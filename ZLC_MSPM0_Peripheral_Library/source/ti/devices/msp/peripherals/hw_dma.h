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

#ifndef ti_devices_msp_peripherals_hw_dma__include
#define ti_devices_msp_peripherals_hw_dma__include

/* Filename: hw_dma.h */
/* Revised: 2023-10-18 15:33:13 */
/* Revision: 7d9c399dfeb736b2cd8c73fed58f1ce76b72f726 */

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
* DMA Registers
******************************************************************************/
#define DMA_DMACHAN_OFS                          ((uint32_t)0x00001200U)
#define DMA_DMATRIG_OFS                          ((uint32_t)0x00001110U)
#define DMA_GEN_EVENT_OFS                        ((uint32_t)0x00001050U)
#define DMA_CPU_INT_OFS                          ((uint32_t)0x00001020U)


/** @addtogroup DMA_DMACHAN
  @{
*/

typedef struct {
  __IO uint32_t DMACTL;                            /* !< (@ 0x00001200) DMA Channel Control */
  __IO uint32_t DMASA;                             /* !< (@ 0x00001204) DMA Channel Source Address */
  __IO uint32_t DMADA;                             /* !< (@ 0x00001208) DMA Channel Destination Address */
  __IO uint32_t DMASZ;                             /* !< (@ 0x0000120C) DMA Channel Size */
} DMA_DMACHAN_Regs;

/*@}*/ /* end of group DMA_DMACHAN */

/** @addtogroup DMA_DMATRIG
  @{
*/

typedef struct {
  __IO uint32_t DMATCTL;                           /* !< (@ 0x00001110) DMA Trigger Select */
} DMA_DMATRIG_Regs;

/*@}*/ /* end of group DMA_DMATRIG */

/** @addtogroup DMA_GEN_EVENT
  @{
*/

typedef struct {
  __I  uint32_t IIDX;                              /* !< (@ 0x00001050) Interrupt index */
       uint32_t RESERVED0;
  __IO uint32_t IMASK;                             /* !< (@ 0x00001058) Interrupt mask */
       uint32_t RESERVED1;
  __I  uint32_t RIS;                               /* !< (@ 0x00001060) Raw interrupt status */
       uint32_t RESERVED2;
  __I  uint32_t MIS;                               /* !< (@ 0x00001068) Masked interrupt status */
       uint32_t RESERVED3;
  __O  uint32_t ISET;                              /* !< (@ 0x00001070) Interrupt set */
       uint32_t RESERVED4;
  __O  uint32_t ICLR;                              /* !< (@ 0x00001078) Interrupt clear */
} DMA_GEN_EVENT_Regs;

/*@}*/ /* end of group DMA_GEN_EVENT */

/** @addtogroup DMA_CPU_INT
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
} DMA_CPU_INT_Regs;

/*@}*/ /* end of group DMA_CPU_INT */

/** @addtogroup DMA
  @{
*/

typedef struct {
       uint32_t RESERVED0[256];
  __IO uint32_t FSUB_0;                            /* !< (@ 0x00000400) Subscriber Port 0 */
  __IO uint32_t FSUB_1;                            /* !< (@ 0x00000404) Subscriber Port 1 */
       uint32_t RESERVED1[15];
  __IO uint32_t FPUB_1;                            /* !< (@ 0x00000444) Publisher Port 0 */
       uint32_t RESERVED2[756];
  __IO uint32_t PDBGCTL;                           /* !< (@ 0x00001018) Peripheral Debug Control */
       uint32_t RESERVED3;
  DMA_CPU_INT_Regs  CPU_INT;                           /* !< (@ 0x00001020) */
       uint32_t RESERVED4;
  DMA_GEN_EVENT_Regs  GEN_EVENT;                         /* !< (@ 0x00001050) */
       uint32_t RESERVED5[25];
  __IO uint32_t EVT_MODE;                          /* !< (@ 0x000010E0) Event Mode */
       uint32_t RESERVED6[6];
  __I  uint32_t DESC;                              /* !< (@ 0x000010FC) Module Description */
  __IO uint32_t DMAPRIO;                           /* !< (@ 0x00001100) DMA Channel Priority Control */
       uint32_t RESERVED7[3];
  DMA_DMATRIG_Regs  DMATRIG[16];                       /* !< (@ 0x00001110) */
       uint32_t RESERVED8[44];
  DMA_DMACHAN_Regs  DMACHAN[16];                       /* !< (@ 0x00001200) */
} DMA_Regs;

/*@}*/ /* end of group DMA */



#if defined ( __CC_ARM )
#pragma no_anon_unions
#endif

/******************************************************************************
* DMA Register Control Bits
******************************************************************************/

/* DMA_DMACTL Bits */
/* DMA_DMACTL[DMAREQ] Bits */
#define DMA_DMACTL_DMAREQ_OFS                    (0)                             /* !< DMAREQ Offset */
#define DMA_DMACTL_DMAREQ_MASK                   ((uint32_t)0x00000001U)         /* !< DMA request. Software-controlled
                                                                                    DMA start. DMAREQ is reset
                                                                                    automatically. */
#define DMA_DMACTL_DMAREQ_IDLE                   ((uint32_t)0x00000000U)         /* !< Default read value */
#define DMA_DMACTL_DMAREQ_REQUEST                ((uint32_t)0x00000001U)         /* !< DMA transfer request (start DMA) */
/* DMA_DMACTL[DMAEN] Bits */
#define DMA_DMACTL_DMAEN_OFS                     (1)                             /* !< DMAEN Offset */
#define DMA_DMACTL_DMAEN_MASK                    ((uint32_t)0x00000002U)         /* !< DMA enable */
#define DMA_DMACTL_DMAEN_DISABLE                 ((uint32_t)0x00000000U)         /* !< DMA channel disabled */
#define DMA_DMACTL_DMAEN_ENABLE                  ((uint32_t)0x00000002U)         /* !< DMA channel enabled */
/* DMA_DMACTL[DMASRCWDTH] Bits */
#define DMA_DMACTL_DMASRCWDTH_OFS                (8)                             /* !< DMASRCWDTH Offset */
#define DMA_DMACTL_DMASRCWDTH_MASK               ((uint32_t)0x00000700U)         /* !< DMA source width. This bit selects
                                                                                    the source data width as a byte, half
                                                                                    word, word, long word or long-long
                                                                                    word. */
#define DMA_DMACTL_DMASRCWDTH_BYTE               ((uint32_t)0x00000000U)         /* !< Source data width is BYTE (8-bit) */
#define DMA_DMACTL_DMASRCWDTH_HALF               ((uint32_t)0x00000100U)         /* !< Source data width is HALF-WORD
                                                                                    (16-bit) */
#define DMA_DMACTL_DMASRCWDTH_WORD               ((uint32_t)0x00000200U)         /* !< Source data width is WORD (32-bit) */
#define DMA_DMACTL_DMASRCWDTH_LONG               ((uint32_t)0x00000300U)         /* !< Source data width is LONG-WORD
                                                                                    (64-bit) */
#define DMA_DMACTL_DMASRCWDTH_LONGLONG           ((uint32_t)0x00000400U)         /* !< Source data width is LONG-LONG-WORD
                                                                                    (128-bit) */
/* DMA_DMACTL[DMADSTWDTH] Bits */
#define DMA_DMACTL_DMADSTWDTH_OFS                (12)                            /* !< DMADSTWDTH Offset */
#define DMA_DMACTL_DMADSTWDTH_MASK               ((uint32_t)0x00007000U)         /* !< DMA destination width. This bit
                                                                                    selects the destination as a byte,
                                                                                    half word, word, long word or
                                                                                    long-long word. */
#define DMA_DMACTL_DMADSTWDTH_BYTE               ((uint32_t)0x00000000U)         /* !< Destination data width is BYTE
                                                                                    (8-bit) */
#define DMA_DMACTL_DMADSTWDTH_HALF               ((uint32_t)0x00001000U)         /* !< Destination data width is HALF-WORD
                                                                                    (16-bit) */
#define DMA_DMACTL_DMADSTWDTH_WORD               ((uint32_t)0x00002000U)         /* !< Destination data width is WORD
                                                                                    (32-bit) */
#define DMA_DMACTL_DMADSTWDTH_LONG               ((uint32_t)0x00003000U)         /* !< Destination data width is LONG-WORD
                                                                                    (64-bit) */
#define DMA_DMACTL_DMADSTWDTH_LONGLONG           ((uint32_t)0x00004000U)         /* !< Destination data width is LONG-LONG-WORD
                                                                                    (128-bit) */
/* DMA_DMACTL[DMASRCINCR] Bits */
#define DMA_DMACTL_DMASRCINCR_OFS                (16)                            /* !< DMASRCINCR Offset */
#define DMA_DMACTL_DMASRCINCR_MASK               ((uint32_t)0x000F0000U)         /* !< DMA source increment. This bit
                                                                                    selects automatic incrementing or
                                                                                    decrementing of the source address
                                                                                    DMASA for each transfer. The amount
                                                                                    of change to the DMASA is based on
                                                                                    the definitin in the DMASRCWDTH. For
                                                                                    example an increment of 1 (+1) on a
                                                                                    WORD transfer will increment the
                                                                                    DMASA by 4. */
#define DMA_DMACTL_DMASRCINCR_UNCHANGED          ((uint32_t)0x00000000U)         /* !< Address is unchanged (+0) */
#define DMA_DMACTL_DMASRCINCR_DECREMENT          ((uint32_t)0x00020000U)         /* !< Decremented by 1 (-1 * DMASRCWDTH) */
#define DMA_DMACTL_DMASRCINCR_INCREMENT          ((uint32_t)0x00030000U)         /* !< Incremented by 1 (+1 * DMASRCWDTH) */
#define DMA_DMACTL_DMASRCINCR_STRIDE_2           ((uint32_t)0x00080000U)         /* !< Stride size 2 (+2 * DMASRCWDTH) */
#define DMA_DMACTL_DMASRCINCR_STRIDE_3           ((uint32_t)0x00090000U)         /* !< Stride size 3 (+3 * DMASRCWDTH) */
#define DMA_DMACTL_DMASRCINCR_STRIDE_4           ((uint32_t)0x000A0000U)         /* !< Stride size 4 (+4 * DMASRCWDTH) */
#define DMA_DMACTL_DMASRCINCR_STRIDE_5           ((uint32_t)0x000B0000U)         /* !< Stride size 5 (+5 * DMASRCWDTH) */
#define DMA_DMACTL_DMASRCINCR_STRIDE_6           ((uint32_t)0x000C0000U)         /* !< Stride size 6 (+6 * DMASRCWDTH) */
#define DMA_DMACTL_DMASRCINCR_STRIDE_7           ((uint32_t)0x000D0000U)         /* !< Stride size 7 (+7 * DMASRCWDTH) */
#define DMA_DMACTL_DMASRCINCR_STRIDE_8           ((uint32_t)0x000E0000U)         /* !< Stride size 8 (+8 * DMASRCWDTH) */
#define DMA_DMACTL_DMASRCINCR_STRIDE_9           ((uint32_t)0x000F0000U)         /* !< Stride size 9 (+9 * DMASRCWDTH) */
/* DMA_DMACTL[DMADSTINCR] Bits */
#define DMA_DMACTL_DMADSTINCR_OFS                (20)                            /* !< DMADSTINCR Offset */
#define DMA_DMACTL_DMADSTINCR_MASK               ((uint32_t)0x00F00000U)         /* !< DMA destination increment. This bit
                                                                                    selects automatic incrementing or
                                                                                    decrementing of the destination
                                                                                    address DMADA for each transfer. The
                                                                                    amount of change to the DMADA is
                                                                                    based on the definitin in the
                                                                                    DMADSTWDTH. For example an increment
                                                                                    of 1 (+1) on a WORD transfer will
                                                                                    increment the DMADA by 4. */
#define DMA_DMACTL_DMADSTINCR_UNCHANGED          ((uint32_t)0x00000000U)         /* !< Address is unchanged (+0) */
#define DMA_DMACTL_DMADSTINCR_DECREMENT          ((uint32_t)0x00200000U)         /* !< Decremented by 1 (-1 * DMADSTWDTH) */
#define DMA_DMACTL_DMADSTINCR_INCREMENT          ((uint32_t)0x00300000U)         /* !< Incremented by 1 (+1 * DMADSTWDTH) */
#define DMA_DMACTL_DMADSTINCR_STRIDE_2           ((uint32_t)0x00800000U)         /* !< Stride size 2 (+2 * DMADSTWDTH) */
#define DMA_DMACTL_DMADSTINCR_STRIDE_3           ((uint32_t)0x00900000U)         /* !< Stride size 3 (+3 * DMADSTWDTH) */
#define DMA_DMACTL_DMADSTINCR_STRIDE_4           ((uint32_t)0x00A00000U)         /* !< Stride size 4 (+4 * DMADSTWDTH) */
#define DMA_DMACTL_DMADSTINCR_STRIDE_5           ((uint32_t)0x00B00000U)         /* !< Stride size 5 (+5 * DMADSTWDTH) */
#define DMA_DMACTL_DMADSTINCR_STRIDE_6           ((uint32_t)0x00C00000U)         /* !< Stride size 6 (+6 * DMADSTWDTH) */
#define DMA_DMACTL_DMADSTINCR_STRIDE_7           ((uint32_t)0x00D00000U)         /* !< Stride size 7 (+7 * DMADSTWDTH) */
#define DMA_DMACTL_DMADSTINCR_STRIDE_8           ((uint32_t)0x00E00000U)         /* !< Stride size 8 (+8 * DMADSTWDTH) */
#define DMA_DMACTL_DMADSTINCR_STRIDE_9           ((uint32_t)0x00F00000U)         /* !< Stride size 9 (+9 * DMADSTWDTH) */
/* DMA_DMACTL[DMATM] Bits */
#define DMA_DMACTL_DMATM_OFS                     (28)                            /* !< DMATM Offset */
#define DMA_DMACTL_DMATM_MASK                    ((uint32_t)0x30000000U)         /* !< DMA transfer mode register  Note:
                                                                                    The repeat-single (2h) and
                                                                                    repeat-block (3h) transfer are only
                                                                                    available in a FULL-channel
                                                                                    configuration. Please consult the
                                                                                    datasheet of the specific device to
                                                                                    map which channel number has FULL or
                                                                                    BASIC capability. In a BASIC channel
                                                                                    configuration only the values for
                                                                                    single (0h) and block (1h) transfer
                                                                                    can be set. */
#define DMA_DMACTL_DMATM_SINGLE                  ((uint32_t)0x00000000U)         /* !< Single transfer. Each transfers
                                                                                    requires a new trigger. When the
                                                                                    DMASZ counts down to zero an event
                                                                                    can be generated and the DMAEN is
                                                                                    cleared. */
#define DMA_DMACTL_DMATM_BLOCK                   ((uint32_t)0x10000000U)         /* !< Block transfer. Each trigger
                                                                                    transfers the complete block defined
                                                                                    in DMASZ. After the transfer is
                                                                                    complete an event can be generated
                                                                                    and the DMAEN is cleared. */
#define DMA_DMACTL_DMATM_RPTSNGL                 ((uint32_t)0x20000000U)         /* !< Repeated single transfer. Each
                                                                                    transfers requires a new trigger.
                                                                                    When the DMASZ counts down to zero an
                                                                                    event can be generated. After the
                                                                                    last transfer the DMASA, DMADA, DAMSZ
                                                                                    registers are restored to its initial
                                                                                    value and the DMAEN stays enabled. */
#define DMA_DMACTL_DMATM_RPTBLCK                 ((uint32_t)0x30000000U)         /* !< Repeated block transfer. Each
                                                                                    trigger transfers the complete block
                                                                                    defined in DMASZ. After the last
                                                                                    transfer the DMASA, DMADA, DAMSZ
                                                                                    registers are restored to its initial
                                                                                    value and the DMAEN stays enabled. */
/* DMA_DMACTL[DMAEM] Bits */
#define DMA_DMACTL_DMAEM_OFS                     (24)                            /* !< DMAEM Offset */
#define DMA_DMACTL_DMAEM_MASK                    ((uint32_t)0x03000000U)         /* !< DMA extended mode  Note: The
                                                                                    extended transfer modes are only
                                                                                    available in a FULL-channel
                                                                                    configuration. Please consult the
                                                                                    datasheet of the specific device to
                                                                                    map which channel number has FULL or
                                                                                    BASIC capability. In a BASIC channel
                                                                                    configuration this register is a
                                                                                    read-only register and reads 0x0. */
#define DMA_DMACTL_DMAEM_NORMAL                  ((uint32_t)0x00000000U)         /* !< Normal mode is related to transfers
                                                                                    from SRC to DST */
#define DMA_DMACTL_DMAEM_GATHERMODE              ((uint32_t)0x01000000U)         /* !< Gather mode will read a data from
                                                                                    an address table located at SA, and
                                                                                    the data is transfered to the DA */
#define DMA_DMACTL_DMAEM_FILLMODE                ((uint32_t)0x02000000U)         /* !< Fill mode will copy the SA register
                                                                                    content as data to DA */
#define DMA_DMACTL_DMAEM_TABLEMODE               ((uint32_t)0x03000000U)         /* !< Table mode will read an address and
                                                                                    data value from SA and write the data
                                                                                    to address */
/* DMA_DMACTL[DMAPREIRQ] Bits */
#define DMA_DMACTL_DMAPREIRQ_OFS                 (4)                             /* !< DMAPREIRQ Offset */
#define DMA_DMACTL_DMAPREIRQ_MASK                ((uint32_t)0x00000070U)         /* !< Enable an early IRQ event. This can
                                                                                    help software to react quicker to and
                                                                                    DMA done event or allows some
                                                                                    additional configuration before the
                                                                                    channel is complete.   Note: This
                                                                                    register is only available in a
                                                                                    FULL-channel configuration. Please
                                                                                    consult the datasheet of the specific
                                                                                    device to map which channel number
                                                                                    has FULL or BASIC capability. In a
                                                                                    BASIC configuration this register is
                                                                                    a read only value and always reads as
                                                                                    0x0. */
#define DMA_DMACTL_DMAPREIRQ_PREIRQ_DISABLE      ((uint32_t)0x00000000U)         /* !< Pre-IRQ event disabled. */
#define DMA_DMACTL_DMAPREIRQ_PREIRQ_1            ((uint32_t)0x00000010U)         /* !< Issure Pre-IRQ event when DMASZ=1 */
#define DMA_DMACTL_DMAPREIRQ_PREIRQ_2            ((uint32_t)0x00000020U)         /* !< Issure Pre-IRQ event when DMASZ=2 */
#define DMA_DMACTL_DMAPREIRQ_PREIRQ_4            ((uint32_t)0x00000030U)         /* !< Issure Pre-IRQ event when DMASZ=4 */
#define DMA_DMACTL_DMAPREIRQ_PREIRQ_8            ((uint32_t)0x00000040U)         /* !< Issure Pre-IRQ event when DMASZ=8 */
#define DMA_DMACTL_DMAPREIRQ_PREIRQ_32           ((uint32_t)0x00000050U)         /* !< Issure Pre-IRQ event when DMASZ=32 */
#define DMA_DMACTL_DMAPREIRQ_PREIRQ_64           ((uint32_t)0x00000060U)         /* !< Issure Pre-IRQ event when DMASZ=64 */
#define DMA_DMACTL_DMAPREIRQ_PREIRQ_HALF         ((uint32_t)0x00000070U)         /* !< Issure Pre-IRQ event when DMASZ
                                                                                    reached the half size point of the
                                                                                    original transfer size */
/* DMA_DMACTL[DMAAUTOEN] Bits */
#define DMA_DMACTL_DMAAUTOEN_OFS                 (2)                             /* !< DMAAUTOEN Offset */
#define DMA_DMACTL_DMAAUTOEN_MASK                ((uint32_t)0x0000000CU)         /* !< Automatic DMA channel enable on
                                                                                    DMASA, DMADA, DMASZ register write.
                                                                                    If channel is configured as SW
                                                                                    trigger (DMATCTL=0), the AUTOEN will
                                                                                    set the DMAEN and DMAREQ. If channel
                                                                                    is configured as HW trigger
                                                                                    (DMACTL!=0), the AUTOEN will only set
                                                                                    the DMAEN. */
#define DMA_DMACTL_DMAAUTOEN_DISABLE             ((uint32_t)0x00000000U)         /* !< No automatic DMA enable */
#define DMA_DMACTL_DMAAUTOEN_DMASA               ((uint32_t)0x00000004U)         /* !< Automatic DMA enable on DMASA
                                                                                    register write. */
#define DMA_DMACTL_DMAAUTOEN_DMADA               ((uint32_t)0x00000008U)         /* !< Automatic DMA enable on DMADA
                                                                                    register write. */
#define DMA_DMACTL_DMAAUTOEN_DMASZ               ((uint32_t)0x0000000CU)         /* !< Automatic DMA enable on DMASZ
                                                                                    register write. */

/* DMA_DMASA Bits */
/* DMA_DMASA[ADDR] Bits */
#define DMA_DMASA_ADDR_OFS                       (0)                             /* !< ADDR Offset */
#define DMA_DMASA_ADDR_MASK                      ((uint32_t)0xFFFFFFFFU)         /* !< DMA Channel Source Address */
#define DMA_DMASA_ADDR_MINIMUM                   ((uint32_t)0x00000000U)         /* !< Smallest value */
#define DMA_DMASA_ADDR_MAXIMUM                   ((uint32_t)0xFFFFFFFFU)         /* !< Highest possible value */

/* DMA_DMADA Bits */
/* DMA_DMADA[ADDR] Bits */
#define DMA_DMADA_ADDR_OFS                       (0)                             /* !< ADDR Offset */
#define DMA_DMADA_ADDR_MASK                      ((uint32_t)0xFFFFFFFFU)         /* !< DMA Channel Destination Address */
#define DMA_DMADA_ADDR_MINIMUM                   ((uint32_t)0x00000000U)         /* !< Smallest value */
#define DMA_DMADA_ADDR_MAXIMUM                   ((uint32_t)0xFFFFFFFFU)         /* !< Highest possible value */

/* DMA_DMASZ Bits */
/* DMA_DMASZ[SIZE] Bits */
#define DMA_DMASZ_SIZE_OFS                       (0)                             /* !< SIZE Offset */
#define DMA_DMASZ_SIZE_MASK                      ((uint32_t)0x0000FFFFU)         /* !< DMA Channel Size in number of
                                                                                    transfers */
#define DMA_DMASZ_SIZE_MINIMUM                   ((uint32_t)0x00000000U)         /* !< Smallest value */
#define DMA_DMASZ_SIZE_MAXIMUM                   ((uint32_t)0x0000FFFFU)         /* !< Highest possible value */

/* DMA_DMATCTL Bits */
/* DMA_DMATCTL[DMATSEL] Bits */
#define DMA_DMATCTL_DMATSEL_OFS                  (0)                             /* !< DMATSEL Offset */
#define DMA_DMATCTL_DMATSEL_MASK                 ((uint32_t)0x0000003FU)         /* !< DMA Trigger Select   Note:
                                                                                    Reference the datasheet of the device
                                                                                    to see the specific trigger mapping. */
#define DMA_DMATCTL_DMATSEL_MINIMUM              ((uint32_t)0x00000000U)         /* !< Smallest value */
#define DMA_DMATCTL_DMATSEL_DMAREQ               ((uint32_t)0x00000000U)         /* !< Software trigger request */
#define DMA_DMATCTL_DMATSEL_MAXIMUM              ((uint32_t)0x0000003FU)         /* !< Highest possible value */
/* DMA_DMATCTL[DMATINT] Bits */
#define DMA_DMATCTL_DMATINT_OFS                  (7)                             /* !< DMATINT Offset */
#define DMA_DMATCTL_DMATINT_MASK                 ((uint32_t)0x00000080U)         /* !< DMA Trigger by Internal Channel */
#define DMA_DMATCTL_DMATINT_EXTERNAL             ((uint32_t)0x00000000U)         /* !< DMATSEL will define external
                                                                                    trigger select as transfer trigger. */
#define DMA_DMATCTL_DMATINT_INTERNAL             ((uint32_t)0x00000080U)         /* !< DMATSEL will define internal
                                                                                    channel as transfer trigger select.
                                                                                    0-> Channel0-done, 1-> Channel1-done,
                                                                                    ... */

/* DMA_GEN_EVENT_IIDX Bits */
/* DMA_GEN_EVENT_IIDX[STAT] Bits */
#define DMA_GEN_EVENT_IIDX_STAT_OFS              (0)                             /* !< STAT Offset */
#define DMA_GEN_EVENT_IIDX_STAT_MASK             ((uint32_t)0x000000FFU)         /* !< Interrupt index status */
#define DMA_GEN_EVENT_IIDX_STAT_NO_INTR          ((uint32_t)0x00000000U)         /* !< No bit is set means there is no
                                                                                    pending interrupt request */
#define DMA_GEN_EVENT_IIDX_STAT_DMACH0           ((uint32_t)0x00000001U)         /* !< DMA Channel 0 size counter reached
                                                                                    zero (DMASZ=0). */
#define DMA_GEN_EVENT_IIDX_STAT_DMACH1           ((uint32_t)0x00000002U)         /* !< DMA Channel 1 size counter reached
                                                                                    zero (DMASZ=0). */
#define DMA_GEN_EVENT_IIDX_STAT_DMACH2           ((uint32_t)0x00000003U)         /* !< DMA Channel 2 size counter reached
                                                                                    zero (DMASZ=0). */
#define DMA_GEN_EVENT_IIDX_STAT_DMACH3           ((uint32_t)0x00000004U)         /* !< DMA Channel 3 size counter reached
                                                                                    zero (DMASZ=0). */
#define DMA_GEN_EVENT_IIDX_STAT_DMACH4           ((uint32_t)0x00000005U)         /* !< DMA Channel 4 size counter reached
                                                                                    zero (DMASZ=0). */
#define DMA_GEN_EVENT_IIDX_STAT_DMACH5           ((uint32_t)0x00000006U)         /* !< DMA Channel 5 size counter reached
                                                                                    zero (DMASZ=0). */
#define DMA_GEN_EVENT_IIDX_STAT_DMACH6           ((uint32_t)0x00000007U)         /* !< DMA Channel 6 size counter reached
                                                                                    zero (DMASZ=0). */
#define DMA_GEN_EVENT_IIDX_STAT_DMACH7           ((uint32_t)0x00000008U)         /* !< DMA Channel 7 size counter reached
                                                                                    zero (DMASZ=0). */
#define DMA_GEN_EVENT_IIDX_STAT_DMACH8           ((uint32_t)0x00000009U)         /* !< DMA Channel 8 size counter reached
                                                                                    zero (DMASZ=0). */
#define DMA_GEN_EVENT_IIDX_STAT_DMACH9           ((uint32_t)0x0000000AU)         /* !< DMA Channel 9 size counter reached
                                                                                    zero (DMASZ=0). */
#define DMA_GEN_EVENT_IIDX_STAT_DMACH10          ((uint32_t)0x0000000BU)         /* !< DMA Channel 10 size counter reached
                                                                                    zero (DMASZ=0). */
#define DMA_GEN_EVENT_IIDX_STAT_DMACH11          ((uint32_t)0x0000000CU)         /* !< DMA Channel 11 size counter reached
                                                                                    zero (DMASZ=0). */
#define DMA_GEN_EVENT_IIDX_STAT_DMACH12          ((uint32_t)0x0000000DU)         /* !< DMA Channel 12 size counter reached
                                                                                    zero (DMASZ=0). */
#define DMA_GEN_EVENT_IIDX_STAT_DMACH13          ((uint32_t)0x0000000EU)         /* !< DMA Channel 13 size counter reached
                                                                                    zero (DMASZ=0). */
#define DMA_GEN_EVENT_IIDX_STAT_DMACH14          ((uint32_t)0x0000000FU)         /* !< DMA Channel 14 size counter reached
                                                                                    zero (DMASZ=0). */
#define DMA_GEN_EVENT_IIDX_STAT_DMACH15          ((uint32_t)0x00000010U)         /* !< DMA Channel 15 size counter reached
                                                                                    zero (DMASZ=0). */
#define DMA_GEN_EVENT_IIDX_STAT_PREIRQCH0        ((uint32_t)0x00000011U)         /* !< PRE-IRQ event for DMA Channel 0. */
#define DMA_GEN_EVENT_IIDX_STAT_PREIRQCH1        ((uint32_t)0x00000012U)         /* !< PRE-IRQ event for DMA Channel 1. */
#define DMA_GEN_EVENT_IIDX_STAT_PREIRQCH2        ((uint32_t)0x00000013U)         /* !< PRE-IRQ event for DMA Channel 2. */
#define DMA_GEN_EVENT_IIDX_STAT_PREIRQCH3        ((uint32_t)0x00000014U)         /* !< PRE-IRQ event for DMA Channel 3. */
#define DMA_GEN_EVENT_IIDX_STAT_PREIRQCH4        ((uint32_t)0x00000015U)         /* !< PRE-IRQ event for DMA Channel 4. */
#define DMA_GEN_EVENT_IIDX_STAT_PREIRQCH5        ((uint32_t)0x00000016U)         /* !< PRE-IRQ event for DMA Channel 5. */
#define DMA_GEN_EVENT_IIDX_STAT_PREIRQCH6        ((uint32_t)0x00000017U)         /* !< PRE-IRQ event for DMA Channel 6. */
#define DMA_GEN_EVENT_IIDX_STAT_PREIRQCH7        ((uint32_t)0x00000018U)         /* !< PRE-IRQ event for DMA Channel 7. */
#define DMA_GEN_EVENT_IIDX_STAT_ADDRERR          ((uint32_t)0x00000019U)         /* !< DMA address error, SRC address not
                                                                                    reachable. */
#define DMA_GEN_EVENT_IIDX_STAT_DATAERR          ((uint32_t)0x0000001AU)         /* !< DMA data error, SRC data might be
                                                                                    corrupted (PAR or ECC error). */

/* DMA_GEN_EVENT_IMASK Bits */
/* DMA_GEN_EVENT_IMASK[DMACH0] Bits */
#define DMA_GEN_EVENT_IMASK_DMACH0_OFS           (0)                             /* !< DMACH0 Offset */
#define DMA_GEN_EVENT_IMASK_DMACH0_MASK          ((uint32_t)0x00000001U)         /* !< DMA Channel 0 interrupt signal.
                                                                                    Size counter reached zero (DMASZ=0). */
#define DMA_GEN_EVENT_IMASK_DMACH0_CLR           ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_IMASK_DMACH0_SET           ((uint32_t)0x00000001U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_IMASK[DMACH1] Bits */
#define DMA_GEN_EVENT_IMASK_DMACH1_OFS           (1)                             /* !< DMACH1 Offset */
#define DMA_GEN_EVENT_IMASK_DMACH1_MASK          ((uint32_t)0x00000002U)         /* !< DMA Channel 1 interrupt signal.
                                                                                    Size counter reached zero (DMASZ=0). */
#define DMA_GEN_EVENT_IMASK_DMACH1_CLR           ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_IMASK_DMACH1_SET           ((uint32_t)0x00000002U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_IMASK[DMACH2] Bits */
#define DMA_GEN_EVENT_IMASK_DMACH2_OFS           (2)                             /* !< DMACH2 Offset */
#define DMA_GEN_EVENT_IMASK_DMACH2_MASK          ((uint32_t)0x00000004U)         /* !< DMA Channel 2 interrupt signal.
                                                                                    Size counter reached zero (DMASZ=0). */
#define DMA_GEN_EVENT_IMASK_DMACH2_CLR           ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_IMASK_DMACH2_SET           ((uint32_t)0x00000004U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_IMASK[DMACH3] Bits */
#define DMA_GEN_EVENT_IMASK_DMACH3_OFS           (3)                             /* !< DMACH3 Offset */
#define DMA_GEN_EVENT_IMASK_DMACH3_MASK          ((uint32_t)0x00000008U)         /* !< DMA Channel 3 interrupt signal.
                                                                                    Size counter reached zero (DMASZ=0). */
#define DMA_GEN_EVENT_IMASK_DMACH3_CLR           ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_IMASK_DMACH3_SET           ((uint32_t)0x00000008U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_IMASK[DMACH4] Bits */
#define DMA_GEN_EVENT_IMASK_DMACH4_OFS           (4)                             /* !< DMACH4 Offset */
#define DMA_GEN_EVENT_IMASK_DMACH4_MASK          ((uint32_t)0x00000010U)         /* !< DMA Channel 4 interrupt signal.
                                                                                    Size counter reached zero (DMASZ=0). */
#define DMA_GEN_EVENT_IMASK_DMACH4_CLR           ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_IMASK_DMACH4_SET           ((uint32_t)0x00000010U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_IMASK[DMACH5] Bits */
#define DMA_GEN_EVENT_IMASK_DMACH5_OFS           (5)                             /* !< DMACH5 Offset */
#define DMA_GEN_EVENT_IMASK_DMACH5_MASK          ((uint32_t)0x00000020U)         /* !< DMA Channel 5 interrupt signal.
                                                                                    Size counter reached zero (DMASZ=0). */
#define DMA_GEN_EVENT_IMASK_DMACH5_CLR           ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_IMASK_DMACH5_SET           ((uint32_t)0x00000020U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_IMASK[DMACH6] Bits */
#define DMA_GEN_EVENT_IMASK_DMACH6_OFS           (6)                             /* !< DMACH6 Offset */
#define DMA_GEN_EVENT_IMASK_DMACH6_MASK          ((uint32_t)0x00000040U)         /* !< DMA Channel 6 interrupt signal.
                                                                                    Size counter reached zero (DMASZ=0). */
#define DMA_GEN_EVENT_IMASK_DMACH6_CLR           ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_IMASK_DMACH6_SET           ((uint32_t)0x00000040U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_IMASK[DMACH7] Bits */
#define DMA_GEN_EVENT_IMASK_DMACH7_OFS           (7)                             /* !< DMACH7 Offset */
#define DMA_GEN_EVENT_IMASK_DMACH7_MASK          ((uint32_t)0x00000080U)         /* !< DMA Channel 7 interrupt signal.
                                                                                    Size counter reached zero (DMASZ=0). */
#define DMA_GEN_EVENT_IMASK_DMACH7_CLR           ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_IMASK_DMACH7_SET           ((uint32_t)0x00000080U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_IMASK[DMACH8] Bits */
#define DMA_GEN_EVENT_IMASK_DMACH8_OFS           (8)                             /* !< DMACH8 Offset */
#define DMA_GEN_EVENT_IMASK_DMACH8_MASK          ((uint32_t)0x00000100U)         /* !< DMA Channel 8 interrupt signal.
                                                                                    Size counter reached zero (DMASZ=0). */
#define DMA_GEN_EVENT_IMASK_DMACH8_CLR           ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_IMASK_DMACH8_SET           ((uint32_t)0x00000100U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_IMASK[DMACH9] Bits */
#define DMA_GEN_EVENT_IMASK_DMACH9_OFS           (9)                             /* !< DMACH9 Offset */
#define DMA_GEN_EVENT_IMASK_DMACH9_MASK          ((uint32_t)0x00000200U)         /* !< DMA Channel 9 interrupt signal.
                                                                                    Size counter reached zero (DMASZ=0). */
#define DMA_GEN_EVENT_IMASK_DMACH9_CLR           ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_IMASK_DMACH9_SET           ((uint32_t)0x00000200U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_IMASK[DMACH10] Bits */
#define DMA_GEN_EVENT_IMASK_DMACH10_OFS          (10)                            /* !< DMACH10 Offset */
#define DMA_GEN_EVENT_IMASK_DMACH10_MASK         ((uint32_t)0x00000400U)         /* !< DMA Channel 10 interrupt signal.
                                                                                    Size counter reached zero (DMASZ=0). */
#define DMA_GEN_EVENT_IMASK_DMACH10_CLR          ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_IMASK_DMACH10_SET          ((uint32_t)0x00000400U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_IMASK[DMACH11] Bits */
#define DMA_GEN_EVENT_IMASK_DMACH11_OFS          (11)                            /* !< DMACH11 Offset */
#define DMA_GEN_EVENT_IMASK_DMACH11_MASK         ((uint32_t)0x00000800U)         /* !< DMA Channel 11 interrupt signal.
                                                                                    Size counter reached zero (DMASZ=0). */
#define DMA_GEN_EVENT_IMASK_DMACH11_CLR          ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_IMASK_DMACH11_SET          ((uint32_t)0x00000800U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_IMASK[DMACH12] Bits */
#define DMA_GEN_EVENT_IMASK_DMACH12_OFS          (12)                            /* !< DMACH12 Offset */
#define DMA_GEN_EVENT_IMASK_DMACH12_MASK         ((uint32_t)0x00001000U)         /* !< DMA Channel 12 interrupt signal.
                                                                                    Size counter reached zero (DMASZ=0). */
#define DMA_GEN_EVENT_IMASK_DMACH12_CLR          ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_IMASK_DMACH12_SET          ((uint32_t)0x00001000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_IMASK[DMACH13] Bits */
#define DMA_GEN_EVENT_IMASK_DMACH13_OFS          (13)                            /* !< DMACH13 Offset */
#define DMA_GEN_EVENT_IMASK_DMACH13_MASK         ((uint32_t)0x00002000U)         /* !< DMA Channel 13 interrupt signal.
                                                                                    Size counter reached zero (DMASZ=0). */
#define DMA_GEN_EVENT_IMASK_DMACH13_CLR          ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_IMASK_DMACH13_SET          ((uint32_t)0x00002000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_IMASK[DMACH14] Bits */
#define DMA_GEN_EVENT_IMASK_DMACH14_OFS          (14)                            /* !< DMACH14 Offset */
#define DMA_GEN_EVENT_IMASK_DMACH14_MASK         ((uint32_t)0x00004000U)         /* !< DMA Channel 14 interrupt signal.
                                                                                    Size counter reached zero (DMASZ=0). */
#define DMA_GEN_EVENT_IMASK_DMACH14_CLR          ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_IMASK_DMACH14_SET          ((uint32_t)0x00004000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_IMASK[DMACH15] Bits */
#define DMA_GEN_EVENT_IMASK_DMACH15_OFS          (15)                            /* !< DMACH15 Offset */
#define DMA_GEN_EVENT_IMASK_DMACH15_MASK         ((uint32_t)0x00008000U)         /* !< DMA Channel 15 interrupt signal.
                                                                                    Size counter reached zero (DMASZ=0). */
#define DMA_GEN_EVENT_IMASK_DMACH15_CLR          ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_IMASK_DMACH15_SET          ((uint32_t)0x00008000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_IMASK[PREIRQCH0] Bits */
#define DMA_GEN_EVENT_IMASK_PREIRQCH0_OFS        (16)                            /* !< PREIRQCH0 Offset */
#define DMA_GEN_EVENT_IMASK_PREIRQCH0_MASK       ((uint32_t)0x00010000U)         /* !< Pre-IRQ for Channel 0. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_GEN_EVENT_IMASK_PREIRQCH0_CLR        ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_IMASK_PREIRQCH0_SET        ((uint32_t)0x00010000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_IMASK[PREIRQCH1] Bits */
#define DMA_GEN_EVENT_IMASK_PREIRQCH1_OFS        (17)                            /* !< PREIRQCH1 Offset */
#define DMA_GEN_EVENT_IMASK_PREIRQCH1_MASK       ((uint32_t)0x00020000U)         /* !< Pre-IRQ for Channel 1. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_GEN_EVENT_IMASK_PREIRQCH1_CLR        ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_IMASK_PREIRQCH1_SET        ((uint32_t)0x00020000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_IMASK[PREIRQCH2] Bits */
#define DMA_GEN_EVENT_IMASK_PREIRQCH2_OFS        (18)                            /* !< PREIRQCH2 Offset */
#define DMA_GEN_EVENT_IMASK_PREIRQCH2_MASK       ((uint32_t)0x00040000U)         /* !< Pre-IRQ for Channel 2. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_GEN_EVENT_IMASK_PREIRQCH2_CLR        ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_IMASK_PREIRQCH2_SET        ((uint32_t)0x00040000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_IMASK[PREIRQCH3] Bits */
#define DMA_GEN_EVENT_IMASK_PREIRQCH3_OFS        (19)                            /* !< PREIRQCH3 Offset */
#define DMA_GEN_EVENT_IMASK_PREIRQCH3_MASK       ((uint32_t)0x00080000U)         /* !< Pre-IRQ for Channel 3. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_GEN_EVENT_IMASK_PREIRQCH3_CLR        ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_IMASK_PREIRQCH3_SET        ((uint32_t)0x00080000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_IMASK[PREIRQCH4] Bits */
#define DMA_GEN_EVENT_IMASK_PREIRQCH4_OFS        (20)                            /* !< PREIRQCH4 Offset */
#define DMA_GEN_EVENT_IMASK_PREIRQCH4_MASK       ((uint32_t)0x00100000U)         /* !< Pre-IRQ for Channel 4. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_GEN_EVENT_IMASK_PREIRQCH4_CLR        ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_IMASK_PREIRQCH4_SET        ((uint32_t)0x00100000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_IMASK[PREIRQCH5] Bits */
#define DMA_GEN_EVENT_IMASK_PREIRQCH5_OFS        (21)                            /* !< PREIRQCH5 Offset */
#define DMA_GEN_EVENT_IMASK_PREIRQCH5_MASK       ((uint32_t)0x00200000U)         /* !< Pre-IRQ for Channel 5. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_GEN_EVENT_IMASK_PREIRQCH5_CLR        ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_IMASK_PREIRQCH5_SET        ((uint32_t)0x00200000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_IMASK[PREIRQCH6] Bits */
#define DMA_GEN_EVENT_IMASK_PREIRQCH6_OFS        (22)                            /* !< PREIRQCH6 Offset */
#define DMA_GEN_EVENT_IMASK_PREIRQCH6_MASK       ((uint32_t)0x00400000U)         /* !< Pre-IRQ for Channel 6. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_GEN_EVENT_IMASK_PREIRQCH6_CLR        ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_IMASK_PREIRQCH6_SET        ((uint32_t)0x00400000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_IMASK[PREIRQCH7] Bits */
#define DMA_GEN_EVENT_IMASK_PREIRQCH7_OFS        (23)                            /* !< PREIRQCH7 Offset */
#define DMA_GEN_EVENT_IMASK_PREIRQCH7_MASK       ((uint32_t)0x00800000U)         /* !< Pre-IRQ for Channel 7. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_GEN_EVENT_IMASK_PREIRQCH7_CLR        ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_IMASK_PREIRQCH7_SET        ((uint32_t)0x00800000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_IMASK[ADDRERR] Bits */
#define DMA_GEN_EVENT_IMASK_ADDRERR_OFS          (24)                            /* !< ADDRERR Offset */
#define DMA_GEN_EVENT_IMASK_ADDRERR_MASK         ((uint32_t)0x01000000U)         /* !< DMA address error, SRC address not
                                                                                    reachable. */
#define DMA_GEN_EVENT_IMASK_ADDRERR_CLR          ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_IMASK_ADDRERR_SET          ((uint32_t)0x01000000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_IMASK[DATAERR] Bits */
#define DMA_GEN_EVENT_IMASK_DATAERR_OFS          (25)                            /* !< DATAERR Offset */
#define DMA_GEN_EVENT_IMASK_DATAERR_MASK         ((uint32_t)0x02000000U)         /* !< DMA data error, SRC data might be
                                                                                    corrupted (PAR or ECC error). */
#define DMA_GEN_EVENT_IMASK_DATAERR_CLR          ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_IMASK_DATAERR_SET          ((uint32_t)0x02000000U)         /* !< Set interrupt mask bit */

/* DMA_GEN_EVENT_RIS Bits */
/* DMA_GEN_EVENT_RIS[DMACH0] Bits */
#define DMA_GEN_EVENT_RIS_DMACH0_OFS             (0)                             /* !< DMACH0 Offset */
#define DMA_GEN_EVENT_RIS_DMACH0_MASK            ((uint32_t)0x00000001U)         /* !< DMA Channel 0 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_RIS_DMACH0_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define DMA_GEN_EVENT_RIS_DMACH0_SET             ((uint32_t)0x00000001U)         /* !< Interrupt occurred */
/* DMA_GEN_EVENT_RIS[DMACH1] Bits */
#define DMA_GEN_EVENT_RIS_DMACH1_OFS             (1)                             /* !< DMACH1 Offset */
#define DMA_GEN_EVENT_RIS_DMACH1_MASK            ((uint32_t)0x00000002U)         /* !< DMA Channel 1 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_RIS_DMACH1_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define DMA_GEN_EVENT_RIS_DMACH1_SET             ((uint32_t)0x00000002U)         /* !< Interrupt occurred */
/* DMA_GEN_EVENT_RIS[DMACH2] Bits */
#define DMA_GEN_EVENT_RIS_DMACH2_OFS             (2)                             /* !< DMACH2 Offset */
#define DMA_GEN_EVENT_RIS_DMACH2_MASK            ((uint32_t)0x00000004U)         /* !< DMA Channel 2 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_RIS_DMACH2_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define DMA_GEN_EVENT_RIS_DMACH2_SET             ((uint32_t)0x00000004U)         /* !< Interrupt occurred */
/* DMA_GEN_EVENT_RIS[DMACH3] Bits */
#define DMA_GEN_EVENT_RIS_DMACH3_OFS             (3)                             /* !< DMACH3 Offset */
#define DMA_GEN_EVENT_RIS_DMACH3_MASK            ((uint32_t)0x00000008U)         /* !< DMA Channel 3 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_RIS_DMACH3_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define DMA_GEN_EVENT_RIS_DMACH3_SET             ((uint32_t)0x00000008U)         /* !< Interrupt occurred */
/* DMA_GEN_EVENT_RIS[DMACH4] Bits */
#define DMA_GEN_EVENT_RIS_DMACH4_OFS             (4)                             /* !< DMACH4 Offset */
#define DMA_GEN_EVENT_RIS_DMACH4_MASK            ((uint32_t)0x00000010U)         /* !< DMA Channel 4 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_RIS_DMACH4_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define DMA_GEN_EVENT_RIS_DMACH4_SET             ((uint32_t)0x00000010U)         /* !< Interrupt occurred */
/* DMA_GEN_EVENT_RIS[DMACH5] Bits */
#define DMA_GEN_EVENT_RIS_DMACH5_OFS             (5)                             /* !< DMACH5 Offset */
#define DMA_GEN_EVENT_RIS_DMACH5_MASK            ((uint32_t)0x00000020U)         /* !< DMA Channel 5 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_RIS_DMACH5_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define DMA_GEN_EVENT_RIS_DMACH5_SET             ((uint32_t)0x00000020U)         /* !< Interrupt occurred */
/* DMA_GEN_EVENT_RIS[DMACH6] Bits */
#define DMA_GEN_EVENT_RIS_DMACH6_OFS             (6)                             /* !< DMACH6 Offset */
#define DMA_GEN_EVENT_RIS_DMACH6_MASK            ((uint32_t)0x00000040U)         /* !< DMA Channel 6 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_RIS_DMACH6_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define DMA_GEN_EVENT_RIS_DMACH6_SET             ((uint32_t)0x00000040U)         /* !< Interrupt occurred */
/* DMA_GEN_EVENT_RIS[DMACH7] Bits */
#define DMA_GEN_EVENT_RIS_DMACH7_OFS             (7)                             /* !< DMACH7 Offset */
#define DMA_GEN_EVENT_RIS_DMACH7_MASK            ((uint32_t)0x00000080U)         /* !< DMA Channel 7 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_RIS_DMACH7_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define DMA_GEN_EVENT_RIS_DMACH7_SET             ((uint32_t)0x00000080U)         /* !< Interrupt occurred */
/* DMA_GEN_EVENT_RIS[DMACH8] Bits */
#define DMA_GEN_EVENT_RIS_DMACH8_OFS             (8)                             /* !< DMACH8 Offset */
#define DMA_GEN_EVENT_RIS_DMACH8_MASK            ((uint32_t)0x00000100U)         /* !< DMA Channel 8 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_RIS_DMACH8_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define DMA_GEN_EVENT_RIS_DMACH8_SET             ((uint32_t)0x00000100U)         /* !< Interrupt occurred */
/* DMA_GEN_EVENT_RIS[DMACH9] Bits */
#define DMA_GEN_EVENT_RIS_DMACH9_OFS             (9)                             /* !< DMACH9 Offset */
#define DMA_GEN_EVENT_RIS_DMACH9_MASK            ((uint32_t)0x00000200U)         /* !< DMA Channel 9 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_RIS_DMACH9_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define DMA_GEN_EVENT_RIS_DMACH9_SET             ((uint32_t)0x00000200U)         /* !< Interrupt occurred */
/* DMA_GEN_EVENT_RIS[DMACH10] Bits */
#define DMA_GEN_EVENT_RIS_DMACH10_OFS            (10)                            /* !< DMACH10 Offset */
#define DMA_GEN_EVENT_RIS_DMACH10_MASK           ((uint32_t)0x00000400U)         /* !< DMA Channel 10 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_RIS_DMACH10_CLR            ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define DMA_GEN_EVENT_RIS_DMACH10_SET            ((uint32_t)0x00000400U)         /* !< Interrupt occurred */
/* DMA_GEN_EVENT_RIS[DMACH11] Bits */
#define DMA_GEN_EVENT_RIS_DMACH11_OFS            (11)                            /* !< DMACH11 Offset */
#define DMA_GEN_EVENT_RIS_DMACH11_MASK           ((uint32_t)0x00000800U)         /* !< DMA Channel 11 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_RIS_DMACH11_CLR            ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define DMA_GEN_EVENT_RIS_DMACH11_SET            ((uint32_t)0x00000800U)         /* !< Interrupt occurred */
/* DMA_GEN_EVENT_RIS[DMACH12] Bits */
#define DMA_GEN_EVENT_RIS_DMACH12_OFS            (12)                            /* !< DMACH12 Offset */
#define DMA_GEN_EVENT_RIS_DMACH12_MASK           ((uint32_t)0x00001000U)         /* !< DMA Channel 12 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_RIS_DMACH12_CLR            ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define DMA_GEN_EVENT_RIS_DMACH12_SET            ((uint32_t)0x00001000U)         /* !< Interrupt occurred */
/* DMA_GEN_EVENT_RIS[DMACH13] Bits */
#define DMA_GEN_EVENT_RIS_DMACH13_OFS            (13)                            /* !< DMACH13 Offset */
#define DMA_GEN_EVENT_RIS_DMACH13_MASK           ((uint32_t)0x00002000U)         /* !< DMA Channel 13 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_RIS_DMACH13_CLR            ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define DMA_GEN_EVENT_RIS_DMACH13_SET            ((uint32_t)0x00002000U)         /* !< Interrupt occurred */
/* DMA_GEN_EVENT_RIS[DMACH14] Bits */
#define DMA_GEN_EVENT_RIS_DMACH14_OFS            (14)                            /* !< DMACH14 Offset */
#define DMA_GEN_EVENT_RIS_DMACH14_MASK           ((uint32_t)0x00004000U)         /* !< DMA Channel 14 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_RIS_DMACH14_CLR            ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define DMA_GEN_EVENT_RIS_DMACH14_SET            ((uint32_t)0x00004000U)         /* !< Interrupt occurred */
/* DMA_GEN_EVENT_RIS[DMACH15] Bits */
#define DMA_GEN_EVENT_RIS_DMACH15_OFS            (15)                            /* !< DMACH15 Offset */
#define DMA_GEN_EVENT_RIS_DMACH15_MASK           ((uint32_t)0x00008000U)         /* !< DMA Channel 15 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_RIS_DMACH15_CLR            ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define DMA_GEN_EVENT_RIS_DMACH15_SET            ((uint32_t)0x00008000U)         /* !< Interrupt occurred */
/* DMA_GEN_EVENT_RIS[PREIRQCH0] Bits */
#define DMA_GEN_EVENT_RIS_PREIRQCH0_OFS          (16)                            /* !< PREIRQCH0 Offset */
#define DMA_GEN_EVENT_RIS_PREIRQCH0_MASK         ((uint32_t)0x00010000U)         /* !< Pre-IRQ for Channel 0. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_GEN_EVENT_RIS_PREIRQCH0_CLR          ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_RIS_PREIRQCH0_SET          ((uint32_t)0x00010000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_RIS[PREIRQCH1] Bits */
#define DMA_GEN_EVENT_RIS_PREIRQCH1_OFS          (17)                            /* !< PREIRQCH1 Offset */
#define DMA_GEN_EVENT_RIS_PREIRQCH1_MASK         ((uint32_t)0x00020000U)         /* !< Pre-IRQ for Channel 1. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_GEN_EVENT_RIS_PREIRQCH1_CLR          ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_RIS_PREIRQCH1_SET          ((uint32_t)0x00020000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_RIS[PREIRQCH2] Bits */
#define DMA_GEN_EVENT_RIS_PREIRQCH2_OFS          (18)                            /* !< PREIRQCH2 Offset */
#define DMA_GEN_EVENT_RIS_PREIRQCH2_MASK         ((uint32_t)0x00040000U)         /* !< Pre-IRQ for Channel 2. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_GEN_EVENT_RIS_PREIRQCH2_CLR          ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_RIS_PREIRQCH2_SET          ((uint32_t)0x00040000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_RIS[PREIRQCH3] Bits */
#define DMA_GEN_EVENT_RIS_PREIRQCH3_OFS          (19)                            /* !< PREIRQCH3 Offset */
#define DMA_GEN_EVENT_RIS_PREIRQCH3_MASK         ((uint32_t)0x00080000U)         /* !< Pre-IRQ for Channel 3. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_GEN_EVENT_RIS_PREIRQCH3_CLR          ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_RIS_PREIRQCH3_SET          ((uint32_t)0x00080000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_RIS[PREIRQCH4] Bits */
#define DMA_GEN_EVENT_RIS_PREIRQCH4_OFS          (20)                            /* !< PREIRQCH4 Offset */
#define DMA_GEN_EVENT_RIS_PREIRQCH4_MASK         ((uint32_t)0x00100000U)         /* !< Pre-IRQ for Channel 4. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_GEN_EVENT_RIS_PREIRQCH4_CLR          ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_RIS_PREIRQCH4_SET          ((uint32_t)0x00100000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_RIS[PREIRQCH5] Bits */
#define DMA_GEN_EVENT_RIS_PREIRQCH5_OFS          (21)                            /* !< PREIRQCH5 Offset */
#define DMA_GEN_EVENT_RIS_PREIRQCH5_MASK         ((uint32_t)0x00200000U)         /* !< Pre-IRQ for Channel 5. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_GEN_EVENT_RIS_PREIRQCH5_CLR          ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_RIS_PREIRQCH5_SET          ((uint32_t)0x00200000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_RIS[PREIRQCH6] Bits */
#define DMA_GEN_EVENT_RIS_PREIRQCH6_OFS          (22)                            /* !< PREIRQCH6 Offset */
#define DMA_GEN_EVENT_RIS_PREIRQCH6_MASK         ((uint32_t)0x00400000U)         /* !< Pre-IRQ for Channel 6. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_GEN_EVENT_RIS_PREIRQCH6_CLR          ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_RIS_PREIRQCH6_SET          ((uint32_t)0x00400000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_RIS[PREIRQCH7] Bits */
#define DMA_GEN_EVENT_RIS_PREIRQCH7_OFS          (23)                            /* !< PREIRQCH7 Offset */
#define DMA_GEN_EVENT_RIS_PREIRQCH7_MASK         ((uint32_t)0x00800000U)         /* !< Pre-IRQ for Channel 7. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_GEN_EVENT_RIS_PREIRQCH7_CLR          ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_RIS_PREIRQCH7_SET          ((uint32_t)0x00800000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_RIS[ADDRERR] Bits */
#define DMA_GEN_EVENT_RIS_ADDRERR_OFS            (24)                            /* !< ADDRERR Offset */
#define DMA_GEN_EVENT_RIS_ADDRERR_MASK           ((uint32_t)0x01000000U)         /* !< DMA address error, SRC address not
                                                                                    reachable. */
#define DMA_GEN_EVENT_RIS_ADDRERR_CLR            ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_RIS_ADDRERR_SET            ((uint32_t)0x01000000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_RIS[DATAERR] Bits */
#define DMA_GEN_EVENT_RIS_DATAERR_OFS            (25)                            /* !< DATAERR Offset */
#define DMA_GEN_EVENT_RIS_DATAERR_MASK           ((uint32_t)0x02000000U)         /* !< DMA data error, SRC data might be
                                                                                    corrupted (PAR or ECC error). */
#define DMA_GEN_EVENT_RIS_DATAERR_CLR            ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_RIS_DATAERR_SET            ((uint32_t)0x02000000U)         /* !< Set interrupt mask bit */

/* DMA_GEN_EVENT_MIS Bits */
/* DMA_GEN_EVENT_MIS[DMACH0] Bits */
#define DMA_GEN_EVENT_MIS_DMACH0_OFS             (0)                             /* !< DMACH0 Offset */
#define DMA_GEN_EVENT_MIS_DMACH0_MASK            ((uint32_t)0x00000001U)         /* !< DMA Channel 0 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_MIS_DMACH0_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define DMA_GEN_EVENT_MIS_DMACH0_SET             ((uint32_t)0x00000001U)         /* !< Interrupt occurred */
/* DMA_GEN_EVENT_MIS[DMACH1] Bits */
#define DMA_GEN_EVENT_MIS_DMACH1_OFS             (1)                             /* !< DMACH1 Offset */
#define DMA_GEN_EVENT_MIS_DMACH1_MASK            ((uint32_t)0x00000002U)         /* !< DMA Channel 1 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_MIS_DMACH1_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define DMA_GEN_EVENT_MIS_DMACH1_SET             ((uint32_t)0x00000002U)         /* !< Interrupt occurred */
/* DMA_GEN_EVENT_MIS[DMACH2] Bits */
#define DMA_GEN_EVENT_MIS_DMACH2_OFS             (2)                             /* !< DMACH2 Offset */
#define DMA_GEN_EVENT_MIS_DMACH2_MASK            ((uint32_t)0x00000004U)         /* !< DMA Channel 2 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_MIS_DMACH2_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define DMA_GEN_EVENT_MIS_DMACH2_SET             ((uint32_t)0x00000004U)         /* !< Interrupt occurred */
/* DMA_GEN_EVENT_MIS[DMACH3] Bits */
#define DMA_GEN_EVENT_MIS_DMACH3_OFS             (3)                             /* !< DMACH3 Offset */
#define DMA_GEN_EVENT_MIS_DMACH3_MASK            ((uint32_t)0x00000008U)         /* !< DMA Channel 3 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_MIS_DMACH3_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define DMA_GEN_EVENT_MIS_DMACH3_SET             ((uint32_t)0x00000008U)         /* !< Interrupt occurred */
/* DMA_GEN_EVENT_MIS[DMACH4] Bits */
#define DMA_GEN_EVENT_MIS_DMACH4_OFS             (4)                             /* !< DMACH4 Offset */
#define DMA_GEN_EVENT_MIS_DMACH4_MASK            ((uint32_t)0x00000010U)         /* !< DMA Channel 4 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_MIS_DMACH4_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define DMA_GEN_EVENT_MIS_DMACH4_SET             ((uint32_t)0x00000010U)         /* !< Interrupt occurred */
/* DMA_GEN_EVENT_MIS[DMACH5] Bits */
#define DMA_GEN_EVENT_MIS_DMACH5_OFS             (5)                             /* !< DMACH5 Offset */
#define DMA_GEN_EVENT_MIS_DMACH5_MASK            ((uint32_t)0x00000020U)         /* !< DMA Channel 5 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_MIS_DMACH5_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define DMA_GEN_EVENT_MIS_DMACH5_SET             ((uint32_t)0x00000020U)         /* !< Interrupt occurred */
/* DMA_GEN_EVENT_MIS[DMACH6] Bits */
#define DMA_GEN_EVENT_MIS_DMACH6_OFS             (6)                             /* !< DMACH6 Offset */
#define DMA_GEN_EVENT_MIS_DMACH6_MASK            ((uint32_t)0x00000040U)         /* !< DMA Channel 6 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_MIS_DMACH6_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define DMA_GEN_EVENT_MIS_DMACH6_SET             ((uint32_t)0x00000040U)         /* !< Interrupt occurred */
/* DMA_GEN_EVENT_MIS[DMACH7] Bits */
#define DMA_GEN_EVENT_MIS_DMACH7_OFS             (7)                             /* !< DMACH7 Offset */
#define DMA_GEN_EVENT_MIS_DMACH7_MASK            ((uint32_t)0x00000080U)         /* !< DMA Channel 7 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_MIS_DMACH7_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define DMA_GEN_EVENT_MIS_DMACH7_SET             ((uint32_t)0x00000080U)         /* !< Interrupt occurred */
/* DMA_GEN_EVENT_MIS[DMACH8] Bits */
#define DMA_GEN_EVENT_MIS_DMACH8_OFS             (8)                             /* !< DMACH8 Offset */
#define DMA_GEN_EVENT_MIS_DMACH8_MASK            ((uint32_t)0x00000100U)         /* !< DMA Channel 8 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_MIS_DMACH8_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define DMA_GEN_EVENT_MIS_DMACH8_SET             ((uint32_t)0x00000100U)         /* !< Interrupt occurred */
/* DMA_GEN_EVENT_MIS[DMACH9] Bits */
#define DMA_GEN_EVENT_MIS_DMACH9_OFS             (9)                             /* !< DMACH9 Offset */
#define DMA_GEN_EVENT_MIS_DMACH9_MASK            ((uint32_t)0x00000200U)         /* !< DMA Channel 9 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_MIS_DMACH9_CLR             ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define DMA_GEN_EVENT_MIS_DMACH9_SET             ((uint32_t)0x00000200U)         /* !< Interrupt occurred */
/* DMA_GEN_EVENT_MIS[DMACH10] Bits */
#define DMA_GEN_EVENT_MIS_DMACH10_OFS            (10)                            /* !< DMACH10 Offset */
#define DMA_GEN_EVENT_MIS_DMACH10_MASK           ((uint32_t)0x00000400U)         /* !< DMA Channel 10 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_MIS_DMACH10_CLR            ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define DMA_GEN_EVENT_MIS_DMACH10_SET            ((uint32_t)0x00000400U)         /* !< Interrupt occurred */
/* DMA_GEN_EVENT_MIS[DMACH11] Bits */
#define DMA_GEN_EVENT_MIS_DMACH11_OFS            (11)                            /* !< DMACH11 Offset */
#define DMA_GEN_EVENT_MIS_DMACH11_MASK           ((uint32_t)0x00000800U)         /* !< DMA Channel 11 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_MIS_DMACH11_CLR            ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define DMA_GEN_EVENT_MIS_DMACH11_SET            ((uint32_t)0x00000800U)         /* !< Interrupt occurred */
/* DMA_GEN_EVENT_MIS[DMACH12] Bits */
#define DMA_GEN_EVENT_MIS_DMACH12_OFS            (12)                            /* !< DMACH12 Offset */
#define DMA_GEN_EVENT_MIS_DMACH12_MASK           ((uint32_t)0x00001000U)         /* !< DMA Channel 12 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_MIS_DMACH12_CLR            ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define DMA_GEN_EVENT_MIS_DMACH12_SET            ((uint32_t)0x00001000U)         /* !< Interrupt occurred */
/* DMA_GEN_EVENT_MIS[DMACH13] Bits */
#define DMA_GEN_EVENT_MIS_DMACH13_OFS            (13)                            /* !< DMACH13 Offset */
#define DMA_GEN_EVENT_MIS_DMACH13_MASK           ((uint32_t)0x00002000U)         /* !< DMA Channel 13 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_MIS_DMACH13_CLR            ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define DMA_GEN_EVENT_MIS_DMACH13_SET            ((uint32_t)0x00002000U)         /* !< Interrupt occurred */
/* DMA_GEN_EVENT_MIS[DMACH14] Bits */
#define DMA_GEN_EVENT_MIS_DMACH14_OFS            (14)                            /* !< DMACH14 Offset */
#define DMA_GEN_EVENT_MIS_DMACH14_MASK           ((uint32_t)0x00004000U)         /* !< DMA Channel 14 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_MIS_DMACH14_CLR            ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define DMA_GEN_EVENT_MIS_DMACH14_SET            ((uint32_t)0x00004000U)         /* !< Interrupt occurred */
/* DMA_GEN_EVENT_MIS[DMACH15] Bits */
#define DMA_GEN_EVENT_MIS_DMACH15_OFS            (15)                            /* !< DMACH15 Offset */
#define DMA_GEN_EVENT_MIS_DMACH15_MASK           ((uint32_t)0x00008000U)         /* !< DMA Channel 15 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_MIS_DMACH15_CLR            ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define DMA_GEN_EVENT_MIS_DMACH15_SET            ((uint32_t)0x00008000U)         /* !< Interrupt occurred */
/* DMA_GEN_EVENT_MIS[PREIRQCH0] Bits */
#define DMA_GEN_EVENT_MIS_PREIRQCH0_OFS          (16)                            /* !< PREIRQCH0 Offset */
#define DMA_GEN_EVENT_MIS_PREIRQCH0_MASK         ((uint32_t)0x00010000U)         /* !< Pre-IRQ for Channel 0. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_GEN_EVENT_MIS_PREIRQCH0_CLR          ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_MIS_PREIRQCH0_SET          ((uint32_t)0x00010000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_MIS[PREIRQCH1] Bits */
#define DMA_GEN_EVENT_MIS_PREIRQCH1_OFS          (17)                            /* !< PREIRQCH1 Offset */
#define DMA_GEN_EVENT_MIS_PREIRQCH1_MASK         ((uint32_t)0x00020000U)         /* !< Pre-IRQ for Channel 1. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_GEN_EVENT_MIS_PREIRQCH1_CLR          ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_MIS_PREIRQCH1_SET          ((uint32_t)0x00020000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_MIS[PREIRQCH2] Bits */
#define DMA_GEN_EVENT_MIS_PREIRQCH2_OFS          (18)                            /* !< PREIRQCH2 Offset */
#define DMA_GEN_EVENT_MIS_PREIRQCH2_MASK         ((uint32_t)0x00040000U)         /* !< Pre-IRQ for Channel 2. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_GEN_EVENT_MIS_PREIRQCH2_CLR          ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_MIS_PREIRQCH2_SET          ((uint32_t)0x00040000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_MIS[PREIRQCH3] Bits */
#define DMA_GEN_EVENT_MIS_PREIRQCH3_OFS          (19)                            /* !< PREIRQCH3 Offset */
#define DMA_GEN_EVENT_MIS_PREIRQCH3_MASK         ((uint32_t)0x00080000U)         /* !< Pre-IRQ for Channel 3. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_GEN_EVENT_MIS_PREIRQCH3_CLR          ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_MIS_PREIRQCH3_SET          ((uint32_t)0x00080000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_MIS[PREIRQCH4] Bits */
#define DMA_GEN_EVENT_MIS_PREIRQCH4_OFS          (20)                            /* !< PREIRQCH4 Offset */
#define DMA_GEN_EVENT_MIS_PREIRQCH4_MASK         ((uint32_t)0x00100000U)         /* !< Pre-IRQ for Channel 4. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_GEN_EVENT_MIS_PREIRQCH4_CLR          ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_MIS_PREIRQCH4_SET          ((uint32_t)0x00100000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_MIS[PREIRQCH5] Bits */
#define DMA_GEN_EVENT_MIS_PREIRQCH5_OFS          (21)                            /* !< PREIRQCH5 Offset */
#define DMA_GEN_EVENT_MIS_PREIRQCH5_MASK         ((uint32_t)0x00200000U)         /* !< Pre-IRQ for Channel 5. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_GEN_EVENT_MIS_PREIRQCH5_CLR          ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_MIS_PREIRQCH5_SET          ((uint32_t)0x00200000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_MIS[PREIRQCH6] Bits */
#define DMA_GEN_EVENT_MIS_PREIRQCH6_OFS          (22)                            /* !< PREIRQCH6 Offset */
#define DMA_GEN_EVENT_MIS_PREIRQCH6_MASK         ((uint32_t)0x00400000U)         /* !< Pre-IRQ for Channel 6. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_GEN_EVENT_MIS_PREIRQCH6_CLR          ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_MIS_PREIRQCH6_SET          ((uint32_t)0x00400000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_MIS[PREIRQCH7] Bits */
#define DMA_GEN_EVENT_MIS_PREIRQCH7_OFS          (23)                            /* !< PREIRQCH7 Offset */
#define DMA_GEN_EVENT_MIS_PREIRQCH7_MASK         ((uint32_t)0x00800000U)         /* !< Pre-IRQ for Channel 7. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_GEN_EVENT_MIS_PREIRQCH7_CLR          ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_MIS_PREIRQCH7_SET          ((uint32_t)0x00800000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_MIS[ADDRERR] Bits */
#define DMA_GEN_EVENT_MIS_ADDRERR_OFS            (24)                            /* !< ADDRERR Offset */
#define DMA_GEN_EVENT_MIS_ADDRERR_MASK           ((uint32_t)0x01000000U)         /* !< DMA address error, SRC address not
                                                                                    reachable. */
#define DMA_GEN_EVENT_MIS_ADDRERR_CLR            ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_MIS_ADDRERR_SET            ((uint32_t)0x01000000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_MIS[DATAERR] Bits */
#define DMA_GEN_EVENT_MIS_DATAERR_OFS            (25)                            /* !< DATAERR Offset */
#define DMA_GEN_EVENT_MIS_DATAERR_MASK           ((uint32_t)0x02000000U)         /* !< DMA data error, SRC data might be
                                                                                    corrupted (PAR or ECC error). */
#define DMA_GEN_EVENT_MIS_DATAERR_CLR            ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_MIS_DATAERR_SET            ((uint32_t)0x02000000U)         /* !< Set interrupt mask bit */

/* DMA_GEN_EVENT_ISET Bits */
/* DMA_GEN_EVENT_ISET[DMACH0] Bits */
#define DMA_GEN_EVENT_ISET_DMACH0_OFS            (0)                             /* !< DMACH0 Offset */
#define DMA_GEN_EVENT_ISET_DMACH0_MASK           ((uint32_t)0x00000001U)         /* !< DMA Channel 0 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_ISET_DMACH0_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_GEN_EVENT_ISET_DMACH0_SET            ((uint32_t)0x00000001U)         /* !< Set interrupt */
/* DMA_GEN_EVENT_ISET[DMACH1] Bits */
#define DMA_GEN_EVENT_ISET_DMACH1_OFS            (1)                             /* !< DMACH1 Offset */
#define DMA_GEN_EVENT_ISET_DMACH1_MASK           ((uint32_t)0x00000002U)         /* !< DMA Channel 1 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_ISET_DMACH1_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_GEN_EVENT_ISET_DMACH1_SET            ((uint32_t)0x00000002U)         /* !< Set interrupt */
/* DMA_GEN_EVENT_ISET[DMACH2] Bits */
#define DMA_GEN_EVENT_ISET_DMACH2_OFS            (2)                             /* !< DMACH2 Offset */
#define DMA_GEN_EVENT_ISET_DMACH2_MASK           ((uint32_t)0x00000004U)         /* !< DMA Channel 2 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_ISET_DMACH2_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_GEN_EVENT_ISET_DMACH2_SET            ((uint32_t)0x00000004U)         /* !< Set interrupt */
/* DMA_GEN_EVENT_ISET[DMACH3] Bits */
#define DMA_GEN_EVENT_ISET_DMACH3_OFS            (3)                             /* !< DMACH3 Offset */
#define DMA_GEN_EVENT_ISET_DMACH3_MASK           ((uint32_t)0x00000008U)         /* !< DMA Channel 3 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_ISET_DMACH3_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_GEN_EVENT_ISET_DMACH3_SET            ((uint32_t)0x00000008U)         /* !< Set interrupt */
/* DMA_GEN_EVENT_ISET[DMACH4] Bits */
#define DMA_GEN_EVENT_ISET_DMACH4_OFS            (4)                             /* !< DMACH4 Offset */
#define DMA_GEN_EVENT_ISET_DMACH4_MASK           ((uint32_t)0x00000010U)         /* !< DMA Channel 4 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_ISET_DMACH4_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_GEN_EVENT_ISET_DMACH4_SET            ((uint32_t)0x00000010U)         /* !< Set interrupt */
/* DMA_GEN_EVENT_ISET[DMACH5] Bits */
#define DMA_GEN_EVENT_ISET_DMACH5_OFS            (5)                             /* !< DMACH5 Offset */
#define DMA_GEN_EVENT_ISET_DMACH5_MASK           ((uint32_t)0x00000020U)         /* !< DMA Channel 5 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_ISET_DMACH5_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_GEN_EVENT_ISET_DMACH5_SET            ((uint32_t)0x00000020U)         /* !< Set interrupt */
/* DMA_GEN_EVENT_ISET[DMACH6] Bits */
#define DMA_GEN_EVENT_ISET_DMACH6_OFS            (6)                             /* !< DMACH6 Offset */
#define DMA_GEN_EVENT_ISET_DMACH6_MASK           ((uint32_t)0x00000040U)         /* !< DMA Channel 6 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_ISET_DMACH6_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_GEN_EVENT_ISET_DMACH6_SET            ((uint32_t)0x00000040U)         /* !< Set interrupt */
/* DMA_GEN_EVENT_ISET[DMACH7] Bits */
#define DMA_GEN_EVENT_ISET_DMACH7_OFS            (7)                             /* !< DMACH7 Offset */
#define DMA_GEN_EVENT_ISET_DMACH7_MASK           ((uint32_t)0x00000080U)         /* !< DMA Channel 7 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_ISET_DMACH7_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_GEN_EVENT_ISET_DMACH7_SET            ((uint32_t)0x00000080U)         /* !< Set interrupt */
/* DMA_GEN_EVENT_ISET[DMACH8] Bits */
#define DMA_GEN_EVENT_ISET_DMACH8_OFS            (8)                             /* !< DMACH8 Offset */
#define DMA_GEN_EVENT_ISET_DMACH8_MASK           ((uint32_t)0x00000100U)         /* !< DMA Channel 8 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_ISET_DMACH8_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_GEN_EVENT_ISET_DMACH8_SET            ((uint32_t)0x00000100U)         /* !< Set interrupt */
/* DMA_GEN_EVENT_ISET[DMACH9] Bits */
#define DMA_GEN_EVENT_ISET_DMACH9_OFS            (9)                             /* !< DMACH9 Offset */
#define DMA_GEN_EVENT_ISET_DMACH9_MASK           ((uint32_t)0x00000200U)         /* !< DMA Channel 9 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_ISET_DMACH9_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_GEN_EVENT_ISET_DMACH9_SET            ((uint32_t)0x00000200U)         /* !< Set interrupt */
/* DMA_GEN_EVENT_ISET[DMACH10] Bits */
#define DMA_GEN_EVENT_ISET_DMACH10_OFS           (10)                            /* !< DMACH10 Offset */
#define DMA_GEN_EVENT_ISET_DMACH10_MASK          ((uint32_t)0x00000400U)         /* !< DMA Channel 0 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_ISET_DMACH10_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_GEN_EVENT_ISET_DMACH10_SET           ((uint32_t)0x00000400U)         /* !< Set interrupt */
/* DMA_GEN_EVENT_ISET[DMACH11] Bits */
#define DMA_GEN_EVENT_ISET_DMACH11_OFS           (11)                            /* !< DMACH11 Offset */
#define DMA_GEN_EVENT_ISET_DMACH11_MASK          ((uint32_t)0x00000800U)         /* !< DMA Channel 11 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_ISET_DMACH11_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_GEN_EVENT_ISET_DMACH11_SET           ((uint32_t)0x00000800U)         /* !< Set interrupt */
/* DMA_GEN_EVENT_ISET[DMACH12] Bits */
#define DMA_GEN_EVENT_ISET_DMACH12_OFS           (12)                            /* !< DMACH12 Offset */
#define DMA_GEN_EVENT_ISET_DMACH12_MASK          ((uint32_t)0x00001000U)         /* !< DMA Channel 12 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_ISET_DMACH12_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_GEN_EVENT_ISET_DMACH12_SET           ((uint32_t)0x00001000U)         /* !< Set interrupt */
/* DMA_GEN_EVENT_ISET[DMACH13] Bits */
#define DMA_GEN_EVENT_ISET_DMACH13_OFS           (13)                            /* !< DMACH13 Offset */
#define DMA_GEN_EVENT_ISET_DMACH13_MASK          ((uint32_t)0x00002000U)         /* !< DMA Channel 13 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_ISET_DMACH13_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_GEN_EVENT_ISET_DMACH13_SET           ((uint32_t)0x00002000U)         /* !< Set interrupt */
/* DMA_GEN_EVENT_ISET[DMACH14] Bits */
#define DMA_GEN_EVENT_ISET_DMACH14_OFS           (14)                            /* !< DMACH14 Offset */
#define DMA_GEN_EVENT_ISET_DMACH14_MASK          ((uint32_t)0x00004000U)         /* !< DMA Channel 14 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_ISET_DMACH14_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_GEN_EVENT_ISET_DMACH14_SET           ((uint32_t)0x00004000U)         /* !< Set interrupt */
/* DMA_GEN_EVENT_ISET[DMACH15] Bits */
#define DMA_GEN_EVENT_ISET_DMACH15_OFS           (15)                            /* !< DMACH15 Offset */
#define DMA_GEN_EVENT_ISET_DMACH15_MASK          ((uint32_t)0x00008000U)         /* !< DMA Channel 0 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_ISET_DMACH15_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_GEN_EVENT_ISET_DMACH15_SET           ((uint32_t)0x00008000U)         /* !< Set interrupt */
/* DMA_GEN_EVENT_ISET[PREIRQCH0] Bits */
#define DMA_GEN_EVENT_ISET_PREIRQCH0_OFS         (16)                            /* !< PREIRQCH0 Offset */
#define DMA_GEN_EVENT_ISET_PREIRQCH0_MASK        ((uint32_t)0x00010000U)         /* !< Pre-IRQ for Channel 0. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_GEN_EVENT_ISET_PREIRQCH0_CLR         ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_ISET_PREIRQCH0_SET         ((uint32_t)0x00010000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_ISET[PREIRQCH1] Bits */
#define DMA_GEN_EVENT_ISET_PREIRQCH1_OFS         (17)                            /* !< PREIRQCH1 Offset */
#define DMA_GEN_EVENT_ISET_PREIRQCH1_MASK        ((uint32_t)0x00020000U)         /* !< Pre-IRQ for Channel 1. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_GEN_EVENT_ISET_PREIRQCH1_CLR         ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_ISET_PREIRQCH1_SET         ((uint32_t)0x00020000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_ISET[PREIRQCH2] Bits */
#define DMA_GEN_EVENT_ISET_PREIRQCH2_OFS         (18)                            /* !< PREIRQCH2 Offset */
#define DMA_GEN_EVENT_ISET_PREIRQCH2_MASK        ((uint32_t)0x00040000U)         /* !< Pre-IRQ for Channel 2. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_GEN_EVENT_ISET_PREIRQCH2_CLR         ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_ISET_PREIRQCH2_SET         ((uint32_t)0x00040000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_ISET[PREIRQCH3] Bits */
#define DMA_GEN_EVENT_ISET_PREIRQCH3_OFS         (19)                            /* !< PREIRQCH3 Offset */
#define DMA_GEN_EVENT_ISET_PREIRQCH3_MASK        ((uint32_t)0x00080000U)         /* !< Pre-IRQ for Channel 3. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_GEN_EVENT_ISET_PREIRQCH3_CLR         ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_ISET_PREIRQCH3_SET         ((uint32_t)0x00080000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_ISET[PREIRQCH4] Bits */
#define DMA_GEN_EVENT_ISET_PREIRQCH4_OFS         (20)                            /* !< PREIRQCH4 Offset */
#define DMA_GEN_EVENT_ISET_PREIRQCH4_MASK        ((uint32_t)0x00100000U)         /* !< Pre-IRQ for Channel 4. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_GEN_EVENT_ISET_PREIRQCH4_CLR         ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_ISET_PREIRQCH4_SET         ((uint32_t)0x00100000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_ISET[PREIRQCH5] Bits */
#define DMA_GEN_EVENT_ISET_PREIRQCH5_OFS         (21)                            /* !< PREIRQCH5 Offset */
#define DMA_GEN_EVENT_ISET_PREIRQCH5_MASK        ((uint32_t)0x00200000U)         /* !< Pre-IRQ for Channel 5. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_GEN_EVENT_ISET_PREIRQCH5_CLR         ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_ISET_PREIRQCH5_SET         ((uint32_t)0x00200000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_ISET[PREIRQCH6] Bits */
#define DMA_GEN_EVENT_ISET_PREIRQCH6_OFS         (22)                            /* !< PREIRQCH6 Offset */
#define DMA_GEN_EVENT_ISET_PREIRQCH6_MASK        ((uint32_t)0x00400000U)         /* !< Pre-IRQ for Channel 6. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_GEN_EVENT_ISET_PREIRQCH6_CLR         ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_ISET_PREIRQCH6_SET         ((uint32_t)0x00400000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_ISET[PREIRQCH7] Bits */
#define DMA_GEN_EVENT_ISET_PREIRQCH7_OFS         (23)                            /* !< PREIRQCH7 Offset */
#define DMA_GEN_EVENT_ISET_PREIRQCH7_MASK        ((uint32_t)0x00800000U)         /* !< Pre-IRQ for Channel 7. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_GEN_EVENT_ISET_PREIRQCH7_CLR         ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_ISET_PREIRQCH7_SET         ((uint32_t)0x00800000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_ISET[ADDRERR] Bits */
#define DMA_GEN_EVENT_ISET_ADDRERR_OFS           (24)                            /* !< ADDRERR Offset */
#define DMA_GEN_EVENT_ISET_ADDRERR_MASK          ((uint32_t)0x01000000U)         /* !< DMA address error, SRC address not
                                                                                    reachable. */
#define DMA_GEN_EVENT_ISET_ADDRERR_CLR           ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_ISET_ADDRERR_SET           ((uint32_t)0x01000000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_ISET[DATAERR] Bits */
#define DMA_GEN_EVENT_ISET_DATAERR_OFS           (25)                            /* !< DATAERR Offset */
#define DMA_GEN_EVENT_ISET_DATAERR_MASK          ((uint32_t)0x02000000U)         /* !< DMA data error, SRC data might be
                                                                                    corrupted (PAR or ECC error). */
#define DMA_GEN_EVENT_ISET_DATAERR_CLR           ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_ISET_DATAERR_SET           ((uint32_t)0x02000000U)         /* !< Set interrupt mask bit */

/* DMA_GEN_EVENT_ICLR Bits */
/* DMA_GEN_EVENT_ICLR[DMACH0] Bits */
#define DMA_GEN_EVENT_ICLR_DMACH0_OFS            (0)                             /* !< DMACH0 Offset */
#define DMA_GEN_EVENT_ICLR_DMACH0_MASK           ((uint32_t)0x00000001U)         /* !< DMA Channel 0 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_ICLR_DMACH0_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_GEN_EVENT_ICLR_DMACH0_CLR            ((uint32_t)0x00000001U)         /* !< Clear interrupt */
/* DMA_GEN_EVENT_ICLR[DMACH1] Bits */
#define DMA_GEN_EVENT_ICLR_DMACH1_OFS            (1)                             /* !< DMACH1 Offset */
#define DMA_GEN_EVENT_ICLR_DMACH1_MASK           ((uint32_t)0x00000002U)         /* !< DMA Channel 1 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_ICLR_DMACH1_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_GEN_EVENT_ICLR_DMACH1_CLR            ((uint32_t)0x00000002U)         /* !< Clear interrupt */
/* DMA_GEN_EVENT_ICLR[DMACH2] Bits */
#define DMA_GEN_EVENT_ICLR_DMACH2_OFS            (2)                             /* !< DMACH2 Offset */
#define DMA_GEN_EVENT_ICLR_DMACH2_MASK           ((uint32_t)0x00000004U)         /* !< DMA Channel 2 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_ICLR_DMACH2_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_GEN_EVENT_ICLR_DMACH2_CLR            ((uint32_t)0x00000004U)         /* !< Clear interrupt */
/* DMA_GEN_EVENT_ICLR[DMACH3] Bits */
#define DMA_GEN_EVENT_ICLR_DMACH3_OFS            (3)                             /* !< DMACH3 Offset */
#define DMA_GEN_EVENT_ICLR_DMACH3_MASK           ((uint32_t)0x00000008U)         /* !< DMA Channel 3 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_ICLR_DMACH3_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_GEN_EVENT_ICLR_DMACH3_CLR            ((uint32_t)0x00000008U)         /* !< Clear interrupt */
/* DMA_GEN_EVENT_ICLR[DMACH4] Bits */
#define DMA_GEN_EVENT_ICLR_DMACH4_OFS            (4)                             /* !< DMACH4 Offset */
#define DMA_GEN_EVENT_ICLR_DMACH4_MASK           ((uint32_t)0x00000010U)         /* !< DMA Channel 4 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_ICLR_DMACH4_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_GEN_EVENT_ICLR_DMACH4_CLR            ((uint32_t)0x00000010U)         /* !< Clear interrupt */
/* DMA_GEN_EVENT_ICLR[DMACH5] Bits */
#define DMA_GEN_EVENT_ICLR_DMACH5_OFS            (5)                             /* !< DMACH5 Offset */
#define DMA_GEN_EVENT_ICLR_DMACH5_MASK           ((uint32_t)0x00000020U)         /* !< DMA Channel 5 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_ICLR_DMACH5_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_GEN_EVENT_ICLR_DMACH5_CLR            ((uint32_t)0x00000020U)         /* !< Clear interrupt */
/* DMA_GEN_EVENT_ICLR[DMACH6] Bits */
#define DMA_GEN_EVENT_ICLR_DMACH6_OFS            (6)                             /* !< DMACH6 Offset */
#define DMA_GEN_EVENT_ICLR_DMACH6_MASK           ((uint32_t)0x00000040U)         /* !< DMA Channel 6 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_ICLR_DMACH6_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_GEN_EVENT_ICLR_DMACH6_CLR            ((uint32_t)0x00000040U)         /* !< Clear interrupt */
/* DMA_GEN_EVENT_ICLR[DMACH7] Bits */
#define DMA_GEN_EVENT_ICLR_DMACH7_OFS            (7)                             /* !< DMACH7 Offset */
#define DMA_GEN_EVENT_ICLR_DMACH7_MASK           ((uint32_t)0x00000080U)         /* !< DMA Channel 7 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_ICLR_DMACH7_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_GEN_EVENT_ICLR_DMACH7_CLR            ((uint32_t)0x00000080U)         /* !< Clear interrupt */
/* DMA_GEN_EVENT_ICLR[DMACH8] Bits */
#define DMA_GEN_EVENT_ICLR_DMACH8_OFS            (8)                             /* !< DMACH8 Offset */
#define DMA_GEN_EVENT_ICLR_DMACH8_MASK           ((uint32_t)0x00000100U)         /* !< DMA Channel 8 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_ICLR_DMACH8_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_GEN_EVENT_ICLR_DMACH8_CLR            ((uint32_t)0x00000100U)         /* !< Clear interrupt */
/* DMA_GEN_EVENT_ICLR[DMACH9] Bits */
#define DMA_GEN_EVENT_ICLR_DMACH9_OFS            (9)                             /* !< DMACH9 Offset */
#define DMA_GEN_EVENT_ICLR_DMACH9_MASK           ((uint32_t)0x00000200U)         /* !< DMA Channel 9 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_ICLR_DMACH9_NO_EFFECT      ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_GEN_EVENT_ICLR_DMACH9_CLR            ((uint32_t)0x00000200U)         /* !< Clear interrupt */
/* DMA_GEN_EVENT_ICLR[DMACH10] Bits */
#define DMA_GEN_EVENT_ICLR_DMACH10_OFS           (10)                            /* !< DMACH10 Offset */
#define DMA_GEN_EVENT_ICLR_DMACH10_MASK          ((uint32_t)0x00000400U)         /* !< DMA Channel 10 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_ICLR_DMACH10_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_GEN_EVENT_ICLR_DMACH10_CLR           ((uint32_t)0x00000400U)         /* !< Clear interrupt */
/* DMA_GEN_EVENT_ICLR[DMACH11] Bits */
#define DMA_GEN_EVENT_ICLR_DMACH11_OFS           (11)                            /* !< DMACH11 Offset */
#define DMA_GEN_EVENT_ICLR_DMACH11_MASK          ((uint32_t)0x00000800U)         /* !< DMA Channel 11 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_ICLR_DMACH11_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_GEN_EVENT_ICLR_DMACH11_CLR           ((uint32_t)0x00000800U)         /* !< Clear interrupt */
/* DMA_GEN_EVENT_ICLR[DMACH12] Bits */
#define DMA_GEN_EVENT_ICLR_DMACH12_OFS           (12)                            /* !< DMACH12 Offset */
#define DMA_GEN_EVENT_ICLR_DMACH12_MASK          ((uint32_t)0x00001000U)         /* !< DMA Channel 12 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_ICLR_DMACH12_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_GEN_EVENT_ICLR_DMACH12_CLR           ((uint32_t)0x00001000U)         /* !< Clear interrupt */
/* DMA_GEN_EVENT_ICLR[DMACH13] Bits */
#define DMA_GEN_EVENT_ICLR_DMACH13_OFS           (13)                            /* !< DMACH13 Offset */
#define DMA_GEN_EVENT_ICLR_DMACH13_MASK          ((uint32_t)0x00002000U)         /* !< DMA Channel 13 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_ICLR_DMACH13_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_GEN_EVENT_ICLR_DMACH13_CLR           ((uint32_t)0x00002000U)         /* !< Clear interrupt */
/* DMA_GEN_EVENT_ICLR[DMACH14] Bits */
#define DMA_GEN_EVENT_ICLR_DMACH14_OFS           (14)                            /* !< DMACH14 Offset */
#define DMA_GEN_EVENT_ICLR_DMACH14_MASK          ((uint32_t)0x00004000U)         /* !< DMA Channel 14 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_ICLR_DMACH14_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_GEN_EVENT_ICLR_DMACH14_CLR           ((uint32_t)0x00004000U)         /* !< Clear interrupt */
/* DMA_GEN_EVENT_ICLR[DMACH15] Bits */
#define DMA_GEN_EVENT_ICLR_DMACH15_OFS           (15)                            /* !< DMACH15 Offset */
#define DMA_GEN_EVENT_ICLR_DMACH15_MASK          ((uint32_t)0x00008000U)         /* !< DMA Channel 15 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_GEN_EVENT_ICLR_DMACH15_NO_EFFECT     ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_GEN_EVENT_ICLR_DMACH15_CLR           ((uint32_t)0x00008000U)         /* !< Clear interrupt */
/* DMA_GEN_EVENT_ICLR[PREIRQCH0] Bits */
#define DMA_GEN_EVENT_ICLR_PREIRQCH0_OFS         (16)                            /* !< PREIRQCH0 Offset */
#define DMA_GEN_EVENT_ICLR_PREIRQCH0_MASK        ((uint32_t)0x00010000U)         /* !< Pre-IRQ for Channel 0. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_GEN_EVENT_ICLR_PREIRQCH0_CLR         ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_ICLR_PREIRQCH0_SET         ((uint32_t)0x00010000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_ICLR[PREIRQCH1] Bits */
#define DMA_GEN_EVENT_ICLR_PREIRQCH1_OFS         (17)                            /* !< PREIRQCH1 Offset */
#define DMA_GEN_EVENT_ICLR_PREIRQCH1_MASK        ((uint32_t)0x00020000U)         /* !< Pre-IRQ for Channel 1. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_GEN_EVENT_ICLR_PREIRQCH1_CLR         ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_ICLR_PREIRQCH1_SET         ((uint32_t)0x00020000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_ICLR[PREIRQCH2] Bits */
#define DMA_GEN_EVENT_ICLR_PREIRQCH2_OFS         (18)                            /* !< PREIRQCH2 Offset */
#define DMA_GEN_EVENT_ICLR_PREIRQCH2_MASK        ((uint32_t)0x00040000U)         /* !< Pre-IRQ for Channel 2. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_GEN_EVENT_ICLR_PREIRQCH2_CLR         ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_ICLR_PREIRQCH2_SET         ((uint32_t)0x00040000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_ICLR[PREIRQCH3] Bits */
#define DMA_GEN_EVENT_ICLR_PREIRQCH3_OFS         (19)                            /* !< PREIRQCH3 Offset */
#define DMA_GEN_EVENT_ICLR_PREIRQCH3_MASK        ((uint32_t)0x00080000U)         /* !< Pre-IRQ for Channel 3. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_GEN_EVENT_ICLR_PREIRQCH3_CLR         ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_ICLR_PREIRQCH3_SET         ((uint32_t)0x00080000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_ICLR[PREIRQCH4] Bits */
#define DMA_GEN_EVENT_ICLR_PREIRQCH4_OFS         (20)                            /* !< PREIRQCH4 Offset */
#define DMA_GEN_EVENT_ICLR_PREIRQCH4_MASK        ((uint32_t)0x00100000U)         /* !< Pre-IRQ for Channel 4. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_GEN_EVENT_ICLR_PREIRQCH4_CLR         ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_ICLR_PREIRQCH4_SET         ((uint32_t)0x00100000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_ICLR[PREIRQCH5] Bits */
#define DMA_GEN_EVENT_ICLR_PREIRQCH5_OFS         (21)                            /* !< PREIRQCH5 Offset */
#define DMA_GEN_EVENT_ICLR_PREIRQCH5_MASK        ((uint32_t)0x00200000U)         /* !< Pre-IRQ for Channel 5. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_GEN_EVENT_ICLR_PREIRQCH5_CLR         ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_ICLR_PREIRQCH5_SET         ((uint32_t)0x00200000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_ICLR[PREIRQCH6] Bits */
#define DMA_GEN_EVENT_ICLR_PREIRQCH6_OFS         (22)                            /* !< PREIRQCH6 Offset */
#define DMA_GEN_EVENT_ICLR_PREIRQCH6_MASK        ((uint32_t)0x00400000U)         /* !< Pre-IRQ for Channel 6. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_GEN_EVENT_ICLR_PREIRQCH6_CLR         ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_ICLR_PREIRQCH6_SET         ((uint32_t)0x00400000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_ICLR[PREIRQCH7] Bits */
#define DMA_GEN_EVENT_ICLR_PREIRQCH7_OFS         (23)                            /* !< PREIRQCH7 Offset */
#define DMA_GEN_EVENT_ICLR_PREIRQCH7_MASK        ((uint32_t)0x00800000U)         /* !< Pre-IRQ for Channel 7. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_GEN_EVENT_ICLR_PREIRQCH7_CLR         ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_ICLR_PREIRQCH7_SET         ((uint32_t)0x00800000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_ICLR[ADDRERR] Bits */
#define DMA_GEN_EVENT_ICLR_ADDRERR_OFS           (24)                            /* !< ADDRERR Offset */
#define DMA_GEN_EVENT_ICLR_ADDRERR_MASK          ((uint32_t)0x01000000U)         /* !< DMA address error, SRC address not
                                                                                    reachable. */
#define DMA_GEN_EVENT_ICLR_ADDRERR_CLR           ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_ICLR_ADDRERR_SET           ((uint32_t)0x01000000U)         /* !< Set interrupt mask bit */
/* DMA_GEN_EVENT_ICLR[DATAERR] Bits */
#define DMA_GEN_EVENT_ICLR_DATAERR_OFS           (25)                            /* !< DATAERR Offset */
#define DMA_GEN_EVENT_ICLR_DATAERR_MASK          ((uint32_t)0x02000000U)         /* !< DMA data error, SRC data might be
                                                                                    corrupted (PAR or ECC error). */
#define DMA_GEN_EVENT_ICLR_DATAERR_CLR           ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_GEN_EVENT_ICLR_DATAERR_SET           ((uint32_t)0x02000000U)         /* !< Set interrupt mask bit */

/* DMA_CPU_INT_IIDX Bits */
/* DMA_CPU_INT_IIDX[STAT] Bits */
#define DMA_CPU_INT_IIDX_STAT_OFS                (0)                             /* !< STAT Offset */
#define DMA_CPU_INT_IIDX_STAT_MASK               ((uint32_t)0x000000FFU)         /* !< Interrupt index status */
#define DMA_CPU_INT_IIDX_STAT_NO_INTR            ((uint32_t)0x00000000U)         /* !< No bit is set means there is no
                                                                                    pending interrupt request */
#define DMA_CPU_INT_IIDX_STAT_DMACH0             ((uint32_t)0x00000001U)         /* !< DMA Channel 0 size counter reached
                                                                                    zero (DMASZ=0). */
#define DMA_CPU_INT_IIDX_STAT_DMACH1             ((uint32_t)0x00000002U)         /* !< DMA Channel 1 size counter reached
                                                                                    zero (DMASZ=0). */
#define DMA_CPU_INT_IIDX_STAT_DMACH2             ((uint32_t)0x00000003U)         /* !< DMA Channel 2 size counter reached
                                                                                    zero (DMASZ=0). */
#define DMA_CPU_INT_IIDX_STAT_DMACH3             ((uint32_t)0x00000004U)         /* !< DMA Channel 3 size counter reached
                                                                                    zero (DMASZ=0). */
#define DMA_CPU_INT_IIDX_STAT_DMACH4             ((uint32_t)0x00000005U)         /* !< DMA Channel 4 size counter reached
                                                                                    zero (DMASZ=0). */
#define DMA_CPU_INT_IIDX_STAT_DMACH5             ((uint32_t)0x00000006U)         /* !< DMA Channel 5 size counter reached
                                                                                    zero (DMASZ=0). */
#define DMA_CPU_INT_IIDX_STAT_DMACH6             ((uint32_t)0x00000007U)         /* !< DMA Channel 6 size counter reached
                                                                                    zero (DMASZ=0). */
#define DMA_CPU_INT_IIDX_STAT_DMACH7             ((uint32_t)0x00000008U)         /* !< DMA Channel 7 size counter reached
                                                                                    zero (DMASZ=0). */
#define DMA_CPU_INT_IIDX_STAT_DMACH8             ((uint32_t)0x00000009U)         /* !< DMA Channel 8 size counter reached
                                                                                    zero (DMASZ=0). */
#define DMA_CPU_INT_IIDX_STAT_DMACH9             ((uint32_t)0x0000000AU)         /* !< DMA Channel 9 size counter reached
                                                                                    zero (DMASZ=0). */
#define DMA_CPU_INT_IIDX_STAT_DMACH10            ((uint32_t)0x0000000BU)         /* !< DMA Channel 10 size counter reached
                                                                                    zero (DMASZ=0). */
#define DMA_CPU_INT_IIDX_STAT_DMACH11            ((uint32_t)0x0000000CU)         /* !< DMA Channel 11 size counter reached
                                                                                    zero (DMASZ=0). */
#define DMA_CPU_INT_IIDX_STAT_DMACH12            ((uint32_t)0x0000000DU)         /* !< DMA Channel 12 size counter reached
                                                                                    zero (DMASZ=0). */
#define DMA_CPU_INT_IIDX_STAT_DMACH13            ((uint32_t)0x0000000EU)         /* !< DMA Channel 13 size counter reached
                                                                                    zero (DMASZ=0). */
#define DMA_CPU_INT_IIDX_STAT_DMACH14            ((uint32_t)0x0000000FU)         /* !< DMA Channel 14 size counter reached
                                                                                    zero (DMASZ=0). */
#define DMA_CPU_INT_IIDX_STAT_DMACH15            ((uint32_t)0x00000010U)         /* !< DMA Channel 15 size counter reached
                                                                                    zero (DMASZ=0). */
#define DMA_CPU_INT_IIDX_STAT_PREIRQCH0          ((uint32_t)0x00000011U)         /* !< PRE-IRQ event for DMA Channel 0. */
#define DMA_CPU_INT_IIDX_STAT_PREIRQCH1          ((uint32_t)0x00000012U)         /* !< PRE-IRQ event for DMA Channel 1. */
#define DMA_CPU_INT_IIDX_STAT_PREIRQCH2          ((uint32_t)0x00000013U)         /* !< PRE-IRQ event for DMA Channel 2. */
#define DMA_CPU_INT_IIDX_STAT_PREIRQCH3          ((uint32_t)0x00000014U)         /* !< PRE-IRQ event for DMA Channel 3. */
#define DMA_CPU_INT_IIDX_STAT_PREIRQCH4          ((uint32_t)0x00000015U)         /* !< PRE-IRQ event for DMA Channel 4. */
#define DMA_CPU_INT_IIDX_STAT_PREIRQCH5          ((uint32_t)0x00000016U)         /* !< PRE-IRQ event for DMA Channel 5. */
#define DMA_CPU_INT_IIDX_STAT_PREIRQCH6          ((uint32_t)0x00000017U)         /* !< PRE-IRQ event for DMA Channel 6. */
#define DMA_CPU_INT_IIDX_STAT_PREIRQCH7          ((uint32_t)0x00000018U)         /* !< PRE-IRQ event for DMA Channel 7. */
#define DMA_CPU_INT_IIDX_STAT_ADDRERR            ((uint32_t)0x00000019U)         /* !< DMA address error, SRC address not
                                                                                    reachable. */
#define DMA_CPU_INT_IIDX_STAT_DATAERR            ((uint32_t)0x0000001AU)         /* !< DMA data error, SRC data might be
                                                                                    corrupted (PAR or ECC error). */

/* DMA_CPU_INT_IMASK Bits */
/* DMA_CPU_INT_IMASK[DMACH0] Bits */
#define DMA_CPU_INT_IMASK_DMACH0_OFS             (0)                             /* !< DMACH0 Offset */
#define DMA_CPU_INT_IMASK_DMACH0_MASK            ((uint32_t)0x00000001U)         /* !< DMA Channel 0 interrupt signal.
                                                                                    Size counter reached zero (DMASZ=0). */
#define DMA_CPU_INT_IMASK_DMACH0_CLR             ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_IMASK_DMACH0_SET             ((uint32_t)0x00000001U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_IMASK[DMACH1] Bits */
#define DMA_CPU_INT_IMASK_DMACH1_OFS             (1)                             /* !< DMACH1 Offset */
#define DMA_CPU_INT_IMASK_DMACH1_MASK            ((uint32_t)0x00000002U)         /* !< DMA Channel 1 interrupt signal.
                                                                                    Size counter reached zero (DMASZ=0). */
#define DMA_CPU_INT_IMASK_DMACH1_CLR             ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_IMASK_DMACH1_SET             ((uint32_t)0x00000002U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_IMASK[DMACH2] Bits */
#define DMA_CPU_INT_IMASK_DMACH2_OFS             (2)                             /* !< DMACH2 Offset */
#define DMA_CPU_INT_IMASK_DMACH2_MASK            ((uint32_t)0x00000004U)         /* !< DMA Channel 2 interrupt signal.
                                                                                    Size counter reached zero (DMASZ=0). */
#define DMA_CPU_INT_IMASK_DMACH2_CLR             ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_IMASK_DMACH2_SET             ((uint32_t)0x00000004U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_IMASK[DMACH3] Bits */
#define DMA_CPU_INT_IMASK_DMACH3_OFS             (3)                             /* !< DMACH3 Offset */
#define DMA_CPU_INT_IMASK_DMACH3_MASK            ((uint32_t)0x00000008U)         /* !< DMA Channel 3 interrupt signal.
                                                                                    Size counter reached zero (DMASZ=0). */
#define DMA_CPU_INT_IMASK_DMACH3_CLR             ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_IMASK_DMACH3_SET             ((uint32_t)0x00000008U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_IMASK[DMACH4] Bits */
#define DMA_CPU_INT_IMASK_DMACH4_OFS             (4)                             /* !< DMACH4 Offset */
#define DMA_CPU_INT_IMASK_DMACH4_MASK            ((uint32_t)0x00000010U)         /* !< DMA Channel 4 interrupt signal.
                                                                                    Size counter reached zero (DMASZ=0). */
#define DMA_CPU_INT_IMASK_DMACH4_CLR             ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_IMASK_DMACH4_SET             ((uint32_t)0x00000010U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_IMASK[DMACH5] Bits */
#define DMA_CPU_INT_IMASK_DMACH5_OFS             (5)                             /* !< DMACH5 Offset */
#define DMA_CPU_INT_IMASK_DMACH5_MASK            ((uint32_t)0x00000020U)         /* !< DMA Channel 5 interrupt signal.
                                                                                    Size counter reached zero (DMASZ=0). */
#define DMA_CPU_INT_IMASK_DMACH5_CLR             ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_IMASK_DMACH5_SET             ((uint32_t)0x00000020U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_IMASK[DMACH6] Bits */
#define DMA_CPU_INT_IMASK_DMACH6_OFS             (6)                             /* !< DMACH6 Offset */
#define DMA_CPU_INT_IMASK_DMACH6_MASK            ((uint32_t)0x00000040U)         /* !< DMA Channel 6 interrupt signal.
                                                                                    Size counter reached zero (DMASZ=0). */
#define DMA_CPU_INT_IMASK_DMACH6_CLR             ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_IMASK_DMACH6_SET             ((uint32_t)0x00000040U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_IMASK[DMACH7] Bits */
#define DMA_CPU_INT_IMASK_DMACH7_OFS             (7)                             /* !< DMACH7 Offset */
#define DMA_CPU_INT_IMASK_DMACH7_MASK            ((uint32_t)0x00000080U)         /* !< DMA Channel 7 interrupt signal.
                                                                                    Size counter reached zero (DMASZ=0). */
#define DMA_CPU_INT_IMASK_DMACH7_CLR             ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_IMASK_DMACH7_SET             ((uint32_t)0x00000080U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_IMASK[DMACH8] Bits */
#define DMA_CPU_INT_IMASK_DMACH8_OFS             (8)                             /* !< DMACH8 Offset */
#define DMA_CPU_INT_IMASK_DMACH8_MASK            ((uint32_t)0x00000100U)         /* !< DMA Channel 8 interrupt signal.
                                                                                    Size counter reached zero (DMASZ=0). */
#define DMA_CPU_INT_IMASK_DMACH8_CLR             ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_IMASK_DMACH8_SET             ((uint32_t)0x00000100U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_IMASK[DMACH9] Bits */
#define DMA_CPU_INT_IMASK_DMACH9_OFS             (9)                             /* !< DMACH9 Offset */
#define DMA_CPU_INT_IMASK_DMACH9_MASK            ((uint32_t)0x00000200U)         /* !< DMA Channel 9 interrupt signal.
                                                                                    Size counter reached zero (DMASZ=0). */
#define DMA_CPU_INT_IMASK_DMACH9_CLR             ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_IMASK_DMACH9_SET             ((uint32_t)0x00000200U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_IMASK[DMACH10] Bits */
#define DMA_CPU_INT_IMASK_DMACH10_OFS            (10)                            /* !< DMACH10 Offset */
#define DMA_CPU_INT_IMASK_DMACH10_MASK           ((uint32_t)0x00000400U)         /* !< DMA Channel 10 interrupt signal.
                                                                                    Size counter reached zero (DMASZ=0). */
#define DMA_CPU_INT_IMASK_DMACH10_CLR            ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_IMASK_DMACH10_SET            ((uint32_t)0x00000400U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_IMASK[DMACH11] Bits */
#define DMA_CPU_INT_IMASK_DMACH11_OFS            (11)                            /* !< DMACH11 Offset */
#define DMA_CPU_INT_IMASK_DMACH11_MASK           ((uint32_t)0x00000800U)         /* !< DMA Channel 11 interrupt signal.
                                                                                    Size counter reached zero (DMASZ=0). */
#define DMA_CPU_INT_IMASK_DMACH11_CLR            ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_IMASK_DMACH11_SET            ((uint32_t)0x00000800U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_IMASK[DMACH12] Bits */
#define DMA_CPU_INT_IMASK_DMACH12_OFS            (12)                            /* !< DMACH12 Offset */
#define DMA_CPU_INT_IMASK_DMACH12_MASK           ((uint32_t)0x00001000U)         /* !< DMA Channel 12 interrupt signal.
                                                                                    Size counter reached zero (DMASZ=0). */
#define DMA_CPU_INT_IMASK_DMACH12_CLR            ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_IMASK_DMACH12_SET            ((uint32_t)0x00001000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_IMASK[DMACH13] Bits */
#define DMA_CPU_INT_IMASK_DMACH13_OFS            (13)                            /* !< DMACH13 Offset */
#define DMA_CPU_INT_IMASK_DMACH13_MASK           ((uint32_t)0x00002000U)         /* !< DMA Channel 13 interrupt signal.
                                                                                    Size counter reached zero (DMASZ=0). */
#define DMA_CPU_INT_IMASK_DMACH13_CLR            ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_IMASK_DMACH13_SET            ((uint32_t)0x00002000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_IMASK[DMACH14] Bits */
#define DMA_CPU_INT_IMASK_DMACH14_OFS            (14)                            /* !< DMACH14 Offset */
#define DMA_CPU_INT_IMASK_DMACH14_MASK           ((uint32_t)0x00004000U)         /* !< DMA Channel 14 interrupt signal.
                                                                                    Size counter reached zero (DMASZ=0). */
#define DMA_CPU_INT_IMASK_DMACH14_CLR            ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_IMASK_DMACH14_SET            ((uint32_t)0x00004000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_IMASK[DMACH15] Bits */
#define DMA_CPU_INT_IMASK_DMACH15_OFS            (15)                            /* !< DMACH15 Offset */
#define DMA_CPU_INT_IMASK_DMACH15_MASK           ((uint32_t)0x00008000U)         /* !< DMA Channel 15 interrupt signal.
                                                                                    Size counter reached zero (DMASZ=0). */
#define DMA_CPU_INT_IMASK_DMACH15_CLR            ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_IMASK_DMACH15_SET            ((uint32_t)0x00008000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_IMASK[PREIRQCH0] Bits */
#define DMA_CPU_INT_IMASK_PREIRQCH0_OFS          (16)                            /* !< PREIRQCH0 Offset */
#define DMA_CPU_INT_IMASK_PREIRQCH0_MASK         ((uint32_t)0x00010000U)         /* !< Pre-IRQ for Channel 0. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_CPU_INT_IMASK_PREIRQCH0_CLR          ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_IMASK_PREIRQCH0_SET          ((uint32_t)0x00010000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_IMASK[PREIRQCH1] Bits */
#define DMA_CPU_INT_IMASK_PREIRQCH1_OFS          (17)                            /* !< PREIRQCH1 Offset */
#define DMA_CPU_INT_IMASK_PREIRQCH1_MASK         ((uint32_t)0x00020000U)         /* !< Pre-IRQ for Channel 1. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_CPU_INT_IMASK_PREIRQCH1_CLR          ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_IMASK_PREIRQCH1_SET          ((uint32_t)0x00020000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_IMASK[PREIRQCH2] Bits */
#define DMA_CPU_INT_IMASK_PREIRQCH2_OFS          (18)                            /* !< PREIRQCH2 Offset */
#define DMA_CPU_INT_IMASK_PREIRQCH2_MASK         ((uint32_t)0x00040000U)         /* !< Pre-IRQ for Channel 2. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_CPU_INT_IMASK_PREIRQCH2_CLR          ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_IMASK_PREIRQCH2_SET          ((uint32_t)0x00040000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_IMASK[PREIRQCH3] Bits */
#define DMA_CPU_INT_IMASK_PREIRQCH3_OFS          (19)                            /* !< PREIRQCH3 Offset */
#define DMA_CPU_INT_IMASK_PREIRQCH3_MASK         ((uint32_t)0x00080000U)         /* !< Pre-IRQ for Channel 3. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_CPU_INT_IMASK_PREIRQCH3_CLR          ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_IMASK_PREIRQCH3_SET          ((uint32_t)0x00080000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_IMASK[PREIRQCH4] Bits */
#define DMA_CPU_INT_IMASK_PREIRQCH4_OFS          (20)                            /* !< PREIRQCH4 Offset */
#define DMA_CPU_INT_IMASK_PREIRQCH4_MASK         ((uint32_t)0x00100000U)         /* !< Pre-IRQ for Channel 4. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_CPU_INT_IMASK_PREIRQCH4_CLR          ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_IMASK_PREIRQCH4_SET          ((uint32_t)0x00100000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_IMASK[PREIRQCH5] Bits */
#define DMA_CPU_INT_IMASK_PREIRQCH5_OFS          (21)                            /* !< PREIRQCH5 Offset */
#define DMA_CPU_INT_IMASK_PREIRQCH5_MASK         ((uint32_t)0x00200000U)         /* !< Pre-IRQ for Channel 5. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_CPU_INT_IMASK_PREIRQCH5_CLR          ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_IMASK_PREIRQCH5_SET          ((uint32_t)0x00200000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_IMASK[PREIRQCH6] Bits */
#define DMA_CPU_INT_IMASK_PREIRQCH6_OFS          (22)                            /* !< PREIRQCH6 Offset */
#define DMA_CPU_INT_IMASK_PREIRQCH6_MASK         ((uint32_t)0x00400000U)         /* !< Pre-IRQ for Channel 6. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_CPU_INT_IMASK_PREIRQCH6_CLR          ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_IMASK_PREIRQCH6_SET          ((uint32_t)0x00400000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_IMASK[PREIRQCH7] Bits */
#define DMA_CPU_INT_IMASK_PREIRQCH7_OFS          (23)                            /* !< PREIRQCH7 Offset */
#define DMA_CPU_INT_IMASK_PREIRQCH7_MASK         ((uint32_t)0x00800000U)         /* !< Pre-IRQ for Channel 7. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_CPU_INT_IMASK_PREIRQCH7_CLR          ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_IMASK_PREIRQCH7_SET          ((uint32_t)0x00800000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_IMASK[ADDRERR] Bits */
#define DMA_CPU_INT_IMASK_ADDRERR_OFS            (24)                            /* !< ADDRERR Offset */
#define DMA_CPU_INT_IMASK_ADDRERR_MASK           ((uint32_t)0x01000000U)         /* !< DMA address error, SRC address not
                                                                                    reachable. */
#define DMA_CPU_INT_IMASK_ADDRERR_CLR            ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_IMASK_ADDRERR_SET            ((uint32_t)0x01000000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_IMASK[DATAERR] Bits */
#define DMA_CPU_INT_IMASK_DATAERR_OFS            (25)                            /* !< DATAERR Offset */
#define DMA_CPU_INT_IMASK_DATAERR_MASK           ((uint32_t)0x02000000U)         /* !< DMA data error, SRC data might be
                                                                                    corrupted (PAR or ECC error). */
#define DMA_CPU_INT_IMASK_DATAERR_CLR            ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_IMASK_DATAERR_SET            ((uint32_t)0x02000000U)         /* !< Set interrupt mask bit */

/* DMA_CPU_INT_RIS Bits */
/* DMA_CPU_INT_RIS[DMACH0] Bits */
#define DMA_CPU_INT_RIS_DMACH0_OFS               (0)                             /* !< DMACH0 Offset */
#define DMA_CPU_INT_RIS_DMACH0_MASK              ((uint32_t)0x00000001U)         /* !< DMA Channel 0 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_RIS_DMACH0_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define DMA_CPU_INT_RIS_DMACH0_SET               ((uint32_t)0x00000001U)         /* !< Interrupt occurred */
/* DMA_CPU_INT_RIS[DMACH1] Bits */
#define DMA_CPU_INT_RIS_DMACH1_OFS               (1)                             /* !< DMACH1 Offset */
#define DMA_CPU_INT_RIS_DMACH1_MASK              ((uint32_t)0x00000002U)         /* !< DMA Channel 1 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_RIS_DMACH1_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define DMA_CPU_INT_RIS_DMACH1_SET               ((uint32_t)0x00000002U)         /* !< Interrupt occurred */
/* DMA_CPU_INT_RIS[DMACH2] Bits */
#define DMA_CPU_INT_RIS_DMACH2_OFS               (2)                             /* !< DMACH2 Offset */
#define DMA_CPU_INT_RIS_DMACH2_MASK              ((uint32_t)0x00000004U)         /* !< DMA Channel 2 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_RIS_DMACH2_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define DMA_CPU_INT_RIS_DMACH2_SET               ((uint32_t)0x00000004U)         /* !< Interrupt occurred */
/* DMA_CPU_INT_RIS[DMACH3] Bits */
#define DMA_CPU_INT_RIS_DMACH3_OFS               (3)                             /* !< DMACH3 Offset */
#define DMA_CPU_INT_RIS_DMACH3_MASK              ((uint32_t)0x00000008U)         /* !< DMA Channel 3 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_RIS_DMACH3_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define DMA_CPU_INT_RIS_DMACH3_SET               ((uint32_t)0x00000008U)         /* !< Interrupt occurred */
/* DMA_CPU_INT_RIS[DMACH4] Bits */
#define DMA_CPU_INT_RIS_DMACH4_OFS               (4)                             /* !< DMACH4 Offset */
#define DMA_CPU_INT_RIS_DMACH4_MASK              ((uint32_t)0x00000010U)         /* !< DMA Channel 4 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_RIS_DMACH4_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define DMA_CPU_INT_RIS_DMACH4_SET               ((uint32_t)0x00000010U)         /* !< Interrupt occurred */
/* DMA_CPU_INT_RIS[DMACH5] Bits */
#define DMA_CPU_INT_RIS_DMACH5_OFS               (5)                             /* !< DMACH5 Offset */
#define DMA_CPU_INT_RIS_DMACH5_MASK              ((uint32_t)0x00000020U)         /* !< DMA Channel 5 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_RIS_DMACH5_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define DMA_CPU_INT_RIS_DMACH5_SET               ((uint32_t)0x00000020U)         /* !< Interrupt occurred */
/* DMA_CPU_INT_RIS[DMACH6] Bits */
#define DMA_CPU_INT_RIS_DMACH6_OFS               (6)                             /* !< DMACH6 Offset */
#define DMA_CPU_INT_RIS_DMACH6_MASK              ((uint32_t)0x00000040U)         /* !< DMA Channel 6 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_RIS_DMACH6_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define DMA_CPU_INT_RIS_DMACH6_SET               ((uint32_t)0x00000040U)         /* !< Interrupt occurred */
/* DMA_CPU_INT_RIS[DMACH7] Bits */
#define DMA_CPU_INT_RIS_DMACH7_OFS               (7)                             /* !< DMACH7 Offset */
#define DMA_CPU_INT_RIS_DMACH7_MASK              ((uint32_t)0x00000080U)         /* !< DMA Channel 7 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_RIS_DMACH7_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define DMA_CPU_INT_RIS_DMACH7_SET               ((uint32_t)0x00000080U)         /* !< Interrupt occurred */
/* DMA_CPU_INT_RIS[DMACH8] Bits */
#define DMA_CPU_INT_RIS_DMACH8_OFS               (8)                             /* !< DMACH8 Offset */
#define DMA_CPU_INT_RIS_DMACH8_MASK              ((uint32_t)0x00000100U)         /* !< DMA Channel 8 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_RIS_DMACH8_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define DMA_CPU_INT_RIS_DMACH8_SET               ((uint32_t)0x00000100U)         /* !< Interrupt occurred */
/* DMA_CPU_INT_RIS[DMACH9] Bits */
#define DMA_CPU_INT_RIS_DMACH9_OFS               (9)                             /* !< DMACH9 Offset */
#define DMA_CPU_INT_RIS_DMACH9_MASK              ((uint32_t)0x00000200U)         /* !< DMA Channel 9 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_RIS_DMACH9_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define DMA_CPU_INT_RIS_DMACH9_SET               ((uint32_t)0x00000200U)         /* !< Interrupt occurred */
/* DMA_CPU_INT_RIS[DMACH10] Bits */
#define DMA_CPU_INT_RIS_DMACH10_OFS              (10)                            /* !< DMACH10 Offset */
#define DMA_CPU_INT_RIS_DMACH10_MASK             ((uint32_t)0x00000400U)         /* !< DMA Channel 10 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_RIS_DMACH10_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define DMA_CPU_INT_RIS_DMACH10_SET              ((uint32_t)0x00000400U)         /* !< Interrupt occurred */
/* DMA_CPU_INT_RIS[DMACH11] Bits */
#define DMA_CPU_INT_RIS_DMACH11_OFS              (11)                            /* !< DMACH11 Offset */
#define DMA_CPU_INT_RIS_DMACH11_MASK             ((uint32_t)0x00000800U)         /* !< DMA Channel 11 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_RIS_DMACH11_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define DMA_CPU_INT_RIS_DMACH11_SET              ((uint32_t)0x00000800U)         /* !< Interrupt occurred */
/* DMA_CPU_INT_RIS[DMACH12] Bits */
#define DMA_CPU_INT_RIS_DMACH12_OFS              (12)                            /* !< DMACH12 Offset */
#define DMA_CPU_INT_RIS_DMACH12_MASK             ((uint32_t)0x00001000U)         /* !< DMA Channel 12 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_RIS_DMACH12_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define DMA_CPU_INT_RIS_DMACH12_SET              ((uint32_t)0x00001000U)         /* !< Interrupt occurred */
/* DMA_CPU_INT_RIS[DMACH13] Bits */
#define DMA_CPU_INT_RIS_DMACH13_OFS              (13)                            /* !< DMACH13 Offset */
#define DMA_CPU_INT_RIS_DMACH13_MASK             ((uint32_t)0x00002000U)         /* !< DMA Channel 13 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_RIS_DMACH13_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define DMA_CPU_INT_RIS_DMACH13_SET              ((uint32_t)0x00002000U)         /* !< Interrupt occurred */
/* DMA_CPU_INT_RIS[DMACH14] Bits */
#define DMA_CPU_INT_RIS_DMACH14_OFS              (14)                            /* !< DMACH14 Offset */
#define DMA_CPU_INT_RIS_DMACH14_MASK             ((uint32_t)0x00004000U)         /* !< DMA Channel 14 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_RIS_DMACH14_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define DMA_CPU_INT_RIS_DMACH14_SET              ((uint32_t)0x00004000U)         /* !< Interrupt occurred */
/* DMA_CPU_INT_RIS[DMACH15] Bits */
#define DMA_CPU_INT_RIS_DMACH15_OFS              (15)                            /* !< DMACH15 Offset */
#define DMA_CPU_INT_RIS_DMACH15_MASK             ((uint32_t)0x00008000U)         /* !< DMA Channel 15 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_RIS_DMACH15_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define DMA_CPU_INT_RIS_DMACH15_SET              ((uint32_t)0x00008000U)         /* !< Interrupt occurred */
/* DMA_CPU_INT_RIS[PREIRQCH0] Bits */
#define DMA_CPU_INT_RIS_PREIRQCH0_OFS            (16)                            /* !< PREIRQCH0 Offset */
#define DMA_CPU_INT_RIS_PREIRQCH0_MASK           ((uint32_t)0x00010000U)         /* !< Pre-IRQ for Channel 0. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_CPU_INT_RIS_PREIRQCH0_CLR            ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_RIS_PREIRQCH0_SET            ((uint32_t)0x00010000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_RIS[PREIRQCH1] Bits */
#define DMA_CPU_INT_RIS_PREIRQCH1_OFS            (17)                            /* !< PREIRQCH1 Offset */
#define DMA_CPU_INT_RIS_PREIRQCH1_MASK           ((uint32_t)0x00020000U)         /* !< Pre-IRQ for Channel 1. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_CPU_INT_RIS_PREIRQCH1_CLR            ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_RIS_PREIRQCH1_SET            ((uint32_t)0x00020000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_RIS[PREIRQCH2] Bits */
#define DMA_CPU_INT_RIS_PREIRQCH2_OFS            (18)                            /* !< PREIRQCH2 Offset */
#define DMA_CPU_INT_RIS_PREIRQCH2_MASK           ((uint32_t)0x00040000U)         /* !< Pre-IRQ for Channel 2. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_CPU_INT_RIS_PREIRQCH2_CLR            ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_RIS_PREIRQCH2_SET            ((uint32_t)0x00040000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_RIS[PREIRQCH3] Bits */
#define DMA_CPU_INT_RIS_PREIRQCH3_OFS            (19)                            /* !< PREIRQCH3 Offset */
#define DMA_CPU_INT_RIS_PREIRQCH3_MASK           ((uint32_t)0x00080000U)         /* !< Pre-IRQ for Channel 3. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_CPU_INT_RIS_PREIRQCH3_CLR            ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_RIS_PREIRQCH3_SET            ((uint32_t)0x00080000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_RIS[PREIRQCH4] Bits */
#define DMA_CPU_INT_RIS_PREIRQCH4_OFS            (20)                            /* !< PREIRQCH4 Offset */
#define DMA_CPU_INT_RIS_PREIRQCH4_MASK           ((uint32_t)0x00100000U)         /* !< Pre-IRQ for Channel 4. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_CPU_INT_RIS_PREIRQCH4_CLR            ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_RIS_PREIRQCH4_SET            ((uint32_t)0x00100000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_RIS[PREIRQCH5] Bits */
#define DMA_CPU_INT_RIS_PREIRQCH5_OFS            (21)                            /* !< PREIRQCH5 Offset */
#define DMA_CPU_INT_RIS_PREIRQCH5_MASK           ((uint32_t)0x00200000U)         /* !< Pre-IRQ for Channel 5. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_CPU_INT_RIS_PREIRQCH5_CLR            ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_RIS_PREIRQCH5_SET            ((uint32_t)0x00200000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_RIS[PREIRQCH6] Bits */
#define DMA_CPU_INT_RIS_PREIRQCH6_OFS            (22)                            /* !< PREIRQCH6 Offset */
#define DMA_CPU_INT_RIS_PREIRQCH6_MASK           ((uint32_t)0x00400000U)         /* !< Pre-IRQ for Channel 6. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_CPU_INT_RIS_PREIRQCH6_CLR            ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_RIS_PREIRQCH6_SET            ((uint32_t)0x00400000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_RIS[PREIRQCH7] Bits */
#define DMA_CPU_INT_RIS_PREIRQCH7_OFS            (23)                            /* !< PREIRQCH7 Offset */
#define DMA_CPU_INT_RIS_PREIRQCH7_MASK           ((uint32_t)0x00800000U)         /* !< Pre-IRQ for Channel 7. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_CPU_INT_RIS_PREIRQCH7_CLR            ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_RIS_PREIRQCH7_SET            ((uint32_t)0x00800000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_RIS[ADDRERR] Bits */
#define DMA_CPU_INT_RIS_ADDRERR_OFS              (24)                            /* !< ADDRERR Offset */
#define DMA_CPU_INT_RIS_ADDRERR_MASK             ((uint32_t)0x01000000U)         /* !< DMA address error, SRC address not
                                                                                    reachable. */
#define DMA_CPU_INT_RIS_ADDRERR_CLR              ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_RIS_ADDRERR_SET              ((uint32_t)0x01000000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_RIS[DATAERR] Bits */
#define DMA_CPU_INT_RIS_DATAERR_OFS              (25)                            /* !< DATAERR Offset */
#define DMA_CPU_INT_RIS_DATAERR_MASK             ((uint32_t)0x02000000U)         /* !< DMA data error, SRC data might be
                                                                                    corrupted (PAR or ECC error). */
#define DMA_CPU_INT_RIS_DATAERR_CLR              ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_RIS_DATAERR_SET              ((uint32_t)0x02000000U)         /* !< Set interrupt mask bit */

/* DMA_CPU_INT_MIS Bits */
/* DMA_CPU_INT_MIS[DMACH0] Bits */
#define DMA_CPU_INT_MIS_DMACH0_OFS               (0)                             /* !< DMACH0 Offset */
#define DMA_CPU_INT_MIS_DMACH0_MASK              ((uint32_t)0x00000001U)         /* !< DMA Channel 0 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_MIS_DMACH0_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define DMA_CPU_INT_MIS_DMACH0_SET               ((uint32_t)0x00000001U)         /* !< Interrupt occurred */
/* DMA_CPU_INT_MIS[DMACH1] Bits */
#define DMA_CPU_INT_MIS_DMACH1_OFS               (1)                             /* !< DMACH1 Offset */
#define DMA_CPU_INT_MIS_DMACH1_MASK              ((uint32_t)0x00000002U)         /* !< DMA Channel 1 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_MIS_DMACH1_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define DMA_CPU_INT_MIS_DMACH1_SET               ((uint32_t)0x00000002U)         /* !< Interrupt occurred */
/* DMA_CPU_INT_MIS[DMACH2] Bits */
#define DMA_CPU_INT_MIS_DMACH2_OFS               (2)                             /* !< DMACH2 Offset */
#define DMA_CPU_INT_MIS_DMACH2_MASK              ((uint32_t)0x00000004U)         /* !< DMA Channel 2 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_MIS_DMACH2_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define DMA_CPU_INT_MIS_DMACH2_SET               ((uint32_t)0x00000004U)         /* !< Interrupt occurred */
/* DMA_CPU_INT_MIS[DMACH3] Bits */
#define DMA_CPU_INT_MIS_DMACH3_OFS               (3)                             /* !< DMACH3 Offset */
#define DMA_CPU_INT_MIS_DMACH3_MASK              ((uint32_t)0x00000008U)         /* !< DMA Channel 3 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_MIS_DMACH3_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define DMA_CPU_INT_MIS_DMACH3_SET               ((uint32_t)0x00000008U)         /* !< Interrupt occurred */
/* DMA_CPU_INT_MIS[DMACH4] Bits */
#define DMA_CPU_INT_MIS_DMACH4_OFS               (4)                             /* !< DMACH4 Offset */
#define DMA_CPU_INT_MIS_DMACH4_MASK              ((uint32_t)0x00000010U)         /* !< DMA Channel 4 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_MIS_DMACH4_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define DMA_CPU_INT_MIS_DMACH4_SET               ((uint32_t)0x00000010U)         /* !< Interrupt occurred */
/* DMA_CPU_INT_MIS[DMACH5] Bits */
#define DMA_CPU_INT_MIS_DMACH5_OFS               (5)                             /* !< DMACH5 Offset */
#define DMA_CPU_INT_MIS_DMACH5_MASK              ((uint32_t)0x00000020U)         /* !< DMA Channel 5 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_MIS_DMACH5_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define DMA_CPU_INT_MIS_DMACH5_SET               ((uint32_t)0x00000020U)         /* !< Interrupt occurred */
/* DMA_CPU_INT_MIS[DMACH6] Bits */
#define DMA_CPU_INT_MIS_DMACH6_OFS               (6)                             /* !< DMACH6 Offset */
#define DMA_CPU_INT_MIS_DMACH6_MASK              ((uint32_t)0x00000040U)         /* !< DMA Channel 6 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_MIS_DMACH6_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define DMA_CPU_INT_MIS_DMACH6_SET               ((uint32_t)0x00000040U)         /* !< Interrupt occurred */
/* DMA_CPU_INT_MIS[DMACH7] Bits */
#define DMA_CPU_INT_MIS_DMACH7_OFS               (7)                             /* !< DMACH7 Offset */
#define DMA_CPU_INT_MIS_DMACH7_MASK              ((uint32_t)0x00000080U)         /* !< DMA Channel 7 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_MIS_DMACH7_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define DMA_CPU_INT_MIS_DMACH7_SET               ((uint32_t)0x00000080U)         /* !< Interrupt occurred */
/* DMA_CPU_INT_MIS[DMACH8] Bits */
#define DMA_CPU_INT_MIS_DMACH8_OFS               (8)                             /* !< DMACH8 Offset */
#define DMA_CPU_INT_MIS_DMACH8_MASK              ((uint32_t)0x00000100U)         /* !< DMA Channel 8 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_MIS_DMACH8_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define DMA_CPU_INT_MIS_DMACH8_SET               ((uint32_t)0x00000100U)         /* !< Interrupt occurred */
/* DMA_CPU_INT_MIS[DMACH9] Bits */
#define DMA_CPU_INT_MIS_DMACH9_OFS               (9)                             /* !< DMACH9 Offset */
#define DMA_CPU_INT_MIS_DMACH9_MASK              ((uint32_t)0x00000200U)         /* !< DMA Channel 9 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_MIS_DMACH9_CLR               ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define DMA_CPU_INT_MIS_DMACH9_SET               ((uint32_t)0x00000200U)         /* !< Interrupt occurred */
/* DMA_CPU_INT_MIS[DMACH10] Bits */
#define DMA_CPU_INT_MIS_DMACH10_OFS              (10)                            /* !< DMACH10 Offset */
#define DMA_CPU_INT_MIS_DMACH10_MASK             ((uint32_t)0x00000400U)         /* !< DMA Channel 10 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_MIS_DMACH10_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define DMA_CPU_INT_MIS_DMACH10_SET              ((uint32_t)0x00000400U)         /* !< Interrupt occurred */
/* DMA_CPU_INT_MIS[DMACH11] Bits */
#define DMA_CPU_INT_MIS_DMACH11_OFS              (11)                            /* !< DMACH11 Offset */
#define DMA_CPU_INT_MIS_DMACH11_MASK             ((uint32_t)0x00000800U)         /* !< DMA Channel 11 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_MIS_DMACH11_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define DMA_CPU_INT_MIS_DMACH11_SET              ((uint32_t)0x00000800U)         /* !< Interrupt occurred */
/* DMA_CPU_INT_MIS[DMACH12] Bits */
#define DMA_CPU_INT_MIS_DMACH12_OFS              (12)                            /* !< DMACH12 Offset */
#define DMA_CPU_INT_MIS_DMACH12_MASK             ((uint32_t)0x00001000U)         /* !< DMA Channel 12 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_MIS_DMACH12_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define DMA_CPU_INT_MIS_DMACH12_SET              ((uint32_t)0x00001000U)         /* !< Interrupt occurred */
/* DMA_CPU_INT_MIS[DMACH13] Bits */
#define DMA_CPU_INT_MIS_DMACH13_OFS              (13)                            /* !< DMACH13 Offset */
#define DMA_CPU_INT_MIS_DMACH13_MASK             ((uint32_t)0x00002000U)         /* !< DMA Channel 13 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_MIS_DMACH13_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define DMA_CPU_INT_MIS_DMACH13_SET              ((uint32_t)0x00002000U)         /* !< Interrupt occurred */
/* DMA_CPU_INT_MIS[DMACH14] Bits */
#define DMA_CPU_INT_MIS_DMACH14_OFS              (14)                            /* !< DMACH14 Offset */
#define DMA_CPU_INT_MIS_DMACH14_MASK             ((uint32_t)0x00004000U)         /* !< DMA Channel 14 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_MIS_DMACH14_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define DMA_CPU_INT_MIS_DMACH14_SET              ((uint32_t)0x00004000U)         /* !< Interrupt occurred */
/* DMA_CPU_INT_MIS[DMACH15] Bits */
#define DMA_CPU_INT_MIS_DMACH15_OFS              (15)                            /* !< DMACH15 Offset */
#define DMA_CPU_INT_MIS_DMACH15_MASK             ((uint32_t)0x00008000U)         /* !< DMA Channel 15 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_MIS_DMACH15_CLR              ((uint32_t)0x00000000U)         /* !< Interrupt did not occur or is
                                                                                    masked out */
#define DMA_CPU_INT_MIS_DMACH15_SET              ((uint32_t)0x00008000U)         /* !< Interrupt occurred */
/* DMA_CPU_INT_MIS[PREIRQCH0] Bits */
#define DMA_CPU_INT_MIS_PREIRQCH0_OFS            (16)                            /* !< PREIRQCH0 Offset */
#define DMA_CPU_INT_MIS_PREIRQCH0_MASK           ((uint32_t)0x00010000U)         /* !< Pre-IRQ for Channel 0. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_CPU_INT_MIS_PREIRQCH0_CLR            ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_MIS_PREIRQCH0_SET            ((uint32_t)0x00010000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_MIS[PREIRQCH1] Bits */
#define DMA_CPU_INT_MIS_PREIRQCH1_OFS            (17)                            /* !< PREIRQCH1 Offset */
#define DMA_CPU_INT_MIS_PREIRQCH1_MASK           ((uint32_t)0x00020000U)         /* !< Pre-IRQ for Channel 1. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_CPU_INT_MIS_PREIRQCH1_CLR            ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_MIS_PREIRQCH1_SET            ((uint32_t)0x00020000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_MIS[PREIRQCH2] Bits */
#define DMA_CPU_INT_MIS_PREIRQCH2_OFS            (18)                            /* !< PREIRQCH2 Offset */
#define DMA_CPU_INT_MIS_PREIRQCH2_MASK           ((uint32_t)0x00040000U)         /* !< Pre-IRQ for Channel 2. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_CPU_INT_MIS_PREIRQCH2_CLR            ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_MIS_PREIRQCH2_SET            ((uint32_t)0x00040000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_MIS[PREIRQCH3] Bits */
#define DMA_CPU_INT_MIS_PREIRQCH3_OFS            (19)                            /* !< PREIRQCH3 Offset */
#define DMA_CPU_INT_MIS_PREIRQCH3_MASK           ((uint32_t)0x00080000U)         /* !< Pre-IRQ for Channel 3. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_CPU_INT_MIS_PREIRQCH3_CLR            ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_MIS_PREIRQCH3_SET            ((uint32_t)0x00080000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_MIS[PREIRQCH4] Bits */
#define DMA_CPU_INT_MIS_PREIRQCH4_OFS            (20)                            /* !< PREIRQCH4 Offset */
#define DMA_CPU_INT_MIS_PREIRQCH4_MASK           ((uint32_t)0x00100000U)         /* !< Pre-IRQ for Channel 4. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_CPU_INT_MIS_PREIRQCH4_CLR            ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_MIS_PREIRQCH4_SET            ((uint32_t)0x00100000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_MIS[PREIRQCH5] Bits */
#define DMA_CPU_INT_MIS_PREIRQCH5_OFS            (21)                            /* !< PREIRQCH5 Offset */
#define DMA_CPU_INT_MIS_PREIRQCH5_MASK           ((uint32_t)0x00200000U)         /* !< Pre-IRQ for Channel 5. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_CPU_INT_MIS_PREIRQCH5_CLR            ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_MIS_PREIRQCH5_SET            ((uint32_t)0x00200000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_MIS[PREIRQCH6] Bits */
#define DMA_CPU_INT_MIS_PREIRQCH6_OFS            (22)                            /* !< PREIRQCH6 Offset */
#define DMA_CPU_INT_MIS_PREIRQCH6_MASK           ((uint32_t)0x00400000U)         /* !< Pre-IRQ for Channel 6. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_CPU_INT_MIS_PREIRQCH6_CLR            ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_MIS_PREIRQCH6_SET            ((uint32_t)0x00400000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_MIS[PREIRQCH7] Bits */
#define DMA_CPU_INT_MIS_PREIRQCH7_OFS            (23)                            /* !< PREIRQCH7 Offset */
#define DMA_CPU_INT_MIS_PREIRQCH7_MASK           ((uint32_t)0x00800000U)         /* !< Pre-IRQ for Channel 7. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_CPU_INT_MIS_PREIRQCH7_CLR            ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_MIS_PREIRQCH7_SET            ((uint32_t)0x00800000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_MIS[ADDRERR] Bits */
#define DMA_CPU_INT_MIS_ADDRERR_OFS              (24)                            /* !< ADDRERR Offset */
#define DMA_CPU_INT_MIS_ADDRERR_MASK             ((uint32_t)0x01000000U)         /* !< DMA address error, SRC address not
                                                                                    reachable. */
#define DMA_CPU_INT_MIS_ADDRERR_CLR              ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_MIS_ADDRERR_SET              ((uint32_t)0x01000000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_MIS[DATAERR] Bits */
#define DMA_CPU_INT_MIS_DATAERR_OFS              (25)                            /* !< DATAERR Offset */
#define DMA_CPU_INT_MIS_DATAERR_MASK             ((uint32_t)0x02000000U)         /* !< DMA data error, SRC data might be
                                                                                    corrupted (PAR or ECC error). */
#define DMA_CPU_INT_MIS_DATAERR_CLR              ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_MIS_DATAERR_SET              ((uint32_t)0x02000000U)         /* !< Set interrupt mask bit */

/* DMA_CPU_INT_ISET Bits */
/* DMA_CPU_INT_ISET[DMACH0] Bits */
#define DMA_CPU_INT_ISET_DMACH0_OFS              (0)                             /* !< DMACH0 Offset */
#define DMA_CPU_INT_ISET_DMACH0_MASK             ((uint32_t)0x00000001U)         /* !< DMA Channel 0 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_ISET_DMACH0_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_CPU_INT_ISET_DMACH0_SET              ((uint32_t)0x00000001U)         /* !< Set interrupt */
/* DMA_CPU_INT_ISET[DMACH1] Bits */
#define DMA_CPU_INT_ISET_DMACH1_OFS              (1)                             /* !< DMACH1 Offset */
#define DMA_CPU_INT_ISET_DMACH1_MASK             ((uint32_t)0x00000002U)         /* !< DMA Channel 1 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_ISET_DMACH1_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_CPU_INT_ISET_DMACH1_SET              ((uint32_t)0x00000002U)         /* !< Set interrupt */
/* DMA_CPU_INT_ISET[DMACH2] Bits */
#define DMA_CPU_INT_ISET_DMACH2_OFS              (2)                             /* !< DMACH2 Offset */
#define DMA_CPU_INT_ISET_DMACH2_MASK             ((uint32_t)0x00000004U)         /* !< DMA Channel 2 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_ISET_DMACH2_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_CPU_INT_ISET_DMACH2_SET              ((uint32_t)0x00000004U)         /* !< Set interrupt */
/* DMA_CPU_INT_ISET[DMACH3] Bits */
#define DMA_CPU_INT_ISET_DMACH3_OFS              (3)                             /* !< DMACH3 Offset */
#define DMA_CPU_INT_ISET_DMACH3_MASK             ((uint32_t)0x00000008U)         /* !< DMA Channel 3 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_ISET_DMACH3_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_CPU_INT_ISET_DMACH3_SET              ((uint32_t)0x00000008U)         /* !< Set interrupt */
/* DMA_CPU_INT_ISET[DMACH4] Bits */
#define DMA_CPU_INT_ISET_DMACH4_OFS              (4)                             /* !< DMACH4 Offset */
#define DMA_CPU_INT_ISET_DMACH4_MASK             ((uint32_t)0x00000010U)         /* !< DMA Channel 4 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_ISET_DMACH4_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_CPU_INT_ISET_DMACH4_SET              ((uint32_t)0x00000010U)         /* !< Set interrupt */
/* DMA_CPU_INT_ISET[DMACH5] Bits */
#define DMA_CPU_INT_ISET_DMACH5_OFS              (5)                             /* !< DMACH5 Offset */
#define DMA_CPU_INT_ISET_DMACH5_MASK             ((uint32_t)0x00000020U)         /* !< DMA Channel 5 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_ISET_DMACH5_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_CPU_INT_ISET_DMACH5_SET              ((uint32_t)0x00000020U)         /* !< Set interrupt */
/* DMA_CPU_INT_ISET[DMACH6] Bits */
#define DMA_CPU_INT_ISET_DMACH6_OFS              (6)                             /* !< DMACH6 Offset */
#define DMA_CPU_INT_ISET_DMACH6_MASK             ((uint32_t)0x00000040U)         /* !< DMA Channel 6 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_ISET_DMACH6_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_CPU_INT_ISET_DMACH6_SET              ((uint32_t)0x00000040U)         /* !< Set interrupt */
/* DMA_CPU_INT_ISET[DMACH7] Bits */
#define DMA_CPU_INT_ISET_DMACH7_OFS              (7)                             /* !< DMACH7 Offset */
#define DMA_CPU_INT_ISET_DMACH7_MASK             ((uint32_t)0x00000080U)         /* !< DMA Channel 7 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_ISET_DMACH7_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_CPU_INT_ISET_DMACH7_SET              ((uint32_t)0x00000080U)         /* !< Set interrupt */
/* DMA_CPU_INT_ISET[DMACH8] Bits */
#define DMA_CPU_INT_ISET_DMACH8_OFS              (8)                             /* !< DMACH8 Offset */
#define DMA_CPU_INT_ISET_DMACH8_MASK             ((uint32_t)0x00000100U)         /* !< DMA Channel 8 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_ISET_DMACH8_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_CPU_INT_ISET_DMACH8_SET              ((uint32_t)0x00000100U)         /* !< Set interrupt */
/* DMA_CPU_INT_ISET[DMACH9] Bits */
#define DMA_CPU_INT_ISET_DMACH9_OFS              (9)                             /* !< DMACH9 Offset */
#define DMA_CPU_INT_ISET_DMACH9_MASK             ((uint32_t)0x00000200U)         /* !< DMA Channel 9 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_ISET_DMACH9_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_CPU_INT_ISET_DMACH9_SET              ((uint32_t)0x00000200U)         /* !< Set interrupt */
/* DMA_CPU_INT_ISET[DMACH10] Bits */
#define DMA_CPU_INT_ISET_DMACH10_OFS             (10)                            /* !< DMACH10 Offset */
#define DMA_CPU_INT_ISET_DMACH10_MASK            ((uint32_t)0x00000400U)         /* !< DMA Channel 0 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_ISET_DMACH10_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_CPU_INT_ISET_DMACH10_SET             ((uint32_t)0x00000400U)         /* !< Set interrupt */
/* DMA_CPU_INT_ISET[DMACH11] Bits */
#define DMA_CPU_INT_ISET_DMACH11_OFS             (11)                            /* !< DMACH11 Offset */
#define DMA_CPU_INT_ISET_DMACH11_MASK            ((uint32_t)0x00000800U)         /* !< DMA Channel 11 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_ISET_DMACH11_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_CPU_INT_ISET_DMACH11_SET             ((uint32_t)0x00000800U)         /* !< Set interrupt */
/* DMA_CPU_INT_ISET[DMACH12] Bits */
#define DMA_CPU_INT_ISET_DMACH12_OFS             (12)                            /* !< DMACH12 Offset */
#define DMA_CPU_INT_ISET_DMACH12_MASK            ((uint32_t)0x00001000U)         /* !< DMA Channel 12 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_ISET_DMACH12_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_CPU_INT_ISET_DMACH12_SET             ((uint32_t)0x00001000U)         /* !< Set interrupt */
/* DMA_CPU_INT_ISET[DMACH13] Bits */
#define DMA_CPU_INT_ISET_DMACH13_OFS             (13)                            /* !< DMACH13 Offset */
#define DMA_CPU_INT_ISET_DMACH13_MASK            ((uint32_t)0x00002000U)         /* !< DMA Channel 13 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_ISET_DMACH13_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_CPU_INT_ISET_DMACH13_SET             ((uint32_t)0x00002000U)         /* !< Set interrupt */
/* DMA_CPU_INT_ISET[DMACH14] Bits */
#define DMA_CPU_INT_ISET_DMACH14_OFS             (14)                            /* !< DMACH14 Offset */
#define DMA_CPU_INT_ISET_DMACH14_MASK            ((uint32_t)0x00004000U)         /* !< DMA Channel 14 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_ISET_DMACH14_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_CPU_INT_ISET_DMACH14_SET             ((uint32_t)0x00004000U)         /* !< Set interrupt */
/* DMA_CPU_INT_ISET[DMACH15] Bits */
#define DMA_CPU_INT_ISET_DMACH15_OFS             (15)                            /* !< DMACH15 Offset */
#define DMA_CPU_INT_ISET_DMACH15_MASK            ((uint32_t)0x00008000U)         /* !< DMA Channel 0 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_ISET_DMACH15_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_CPU_INT_ISET_DMACH15_SET             ((uint32_t)0x00008000U)         /* !< Set interrupt */
/* DMA_CPU_INT_ISET[PREIRQCH0] Bits */
#define DMA_CPU_INT_ISET_PREIRQCH0_OFS           (16)                            /* !< PREIRQCH0 Offset */
#define DMA_CPU_INT_ISET_PREIRQCH0_MASK          ((uint32_t)0x00010000U)         /* !< Pre-IRQ for Channel 0. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_CPU_INT_ISET_PREIRQCH0_CLR           ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_ISET_PREIRQCH0_SET           ((uint32_t)0x00010000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_ISET[PREIRQCH1] Bits */
#define DMA_CPU_INT_ISET_PREIRQCH1_OFS           (17)                            /* !< PREIRQCH1 Offset */
#define DMA_CPU_INT_ISET_PREIRQCH1_MASK          ((uint32_t)0x00020000U)         /* !< Pre-IRQ for Channel 1. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_CPU_INT_ISET_PREIRQCH1_CLR           ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_ISET_PREIRQCH1_SET           ((uint32_t)0x00020000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_ISET[PREIRQCH2] Bits */
#define DMA_CPU_INT_ISET_PREIRQCH2_OFS           (18)                            /* !< PREIRQCH2 Offset */
#define DMA_CPU_INT_ISET_PREIRQCH2_MASK          ((uint32_t)0x00040000U)         /* !< Pre-IRQ for Channel 2. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_CPU_INT_ISET_PREIRQCH2_CLR           ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_ISET_PREIRQCH2_SET           ((uint32_t)0x00040000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_ISET[PREIRQCH3] Bits */
#define DMA_CPU_INT_ISET_PREIRQCH3_OFS           (19)                            /* !< PREIRQCH3 Offset */
#define DMA_CPU_INT_ISET_PREIRQCH3_MASK          ((uint32_t)0x00080000U)         /* !< Pre-IRQ for Channel 3. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_CPU_INT_ISET_PREIRQCH3_CLR           ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_ISET_PREIRQCH3_SET           ((uint32_t)0x00080000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_ISET[PREIRQCH4] Bits */
#define DMA_CPU_INT_ISET_PREIRQCH4_OFS           (20)                            /* !< PREIRQCH4 Offset */
#define DMA_CPU_INT_ISET_PREIRQCH4_MASK          ((uint32_t)0x00100000U)         /* !< Pre-IRQ for Channel 4. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_CPU_INT_ISET_PREIRQCH4_CLR           ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_ISET_PREIRQCH4_SET           ((uint32_t)0x00100000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_ISET[PREIRQCH5] Bits */
#define DMA_CPU_INT_ISET_PREIRQCH5_OFS           (21)                            /* !< PREIRQCH5 Offset */
#define DMA_CPU_INT_ISET_PREIRQCH5_MASK          ((uint32_t)0x00200000U)         /* !< Pre-IRQ for Channel 5. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_CPU_INT_ISET_PREIRQCH5_CLR           ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_ISET_PREIRQCH5_SET           ((uint32_t)0x00200000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_ISET[PREIRQCH6] Bits */
#define DMA_CPU_INT_ISET_PREIRQCH6_OFS           (22)                            /* !< PREIRQCH6 Offset */
#define DMA_CPU_INT_ISET_PREIRQCH6_MASK          ((uint32_t)0x00400000U)         /* !< Pre-IRQ for Channel 6. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_CPU_INT_ISET_PREIRQCH6_CLR           ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_ISET_PREIRQCH6_SET           ((uint32_t)0x00400000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_ISET[PREIRQCH7] Bits */
#define DMA_CPU_INT_ISET_PREIRQCH7_OFS           (23)                            /* !< PREIRQCH7 Offset */
#define DMA_CPU_INT_ISET_PREIRQCH7_MASK          ((uint32_t)0x00800000U)         /* !< Pre-IRQ for Channel 7. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_CPU_INT_ISET_PREIRQCH7_CLR           ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_ISET_PREIRQCH7_SET           ((uint32_t)0x00800000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_ISET[ADDRERR] Bits */
#define DMA_CPU_INT_ISET_ADDRERR_OFS             (24)                            /* !< ADDRERR Offset */
#define DMA_CPU_INT_ISET_ADDRERR_MASK            ((uint32_t)0x01000000U)         /* !< DMA address error, SRC address not
                                                                                    reachable. */
#define DMA_CPU_INT_ISET_ADDRERR_CLR             ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_ISET_ADDRERR_SET             ((uint32_t)0x01000000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_ISET[DATAERR] Bits */
#define DMA_CPU_INT_ISET_DATAERR_OFS             (25)                            /* !< DATAERR Offset */
#define DMA_CPU_INT_ISET_DATAERR_MASK            ((uint32_t)0x02000000U)         /* !< DMA data error, SRC data might be
                                                                                    corrupted (PAR or ECC error). */
#define DMA_CPU_INT_ISET_DATAERR_CLR             ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_ISET_DATAERR_SET             ((uint32_t)0x02000000U)         /* !< Set interrupt mask bit */

/* DMA_CPU_INT_ICLR Bits */
/* DMA_CPU_INT_ICLR[DMACH0] Bits */
#define DMA_CPU_INT_ICLR_DMACH0_OFS              (0)                             /* !< DMACH0 Offset */
#define DMA_CPU_INT_ICLR_DMACH0_MASK             ((uint32_t)0x00000001U)         /* !< DMA Channel 0 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_ICLR_DMACH0_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_CPU_INT_ICLR_DMACH0_CLR              ((uint32_t)0x00000001U)         /* !< Clear interrupt */
/* DMA_CPU_INT_ICLR[DMACH1] Bits */
#define DMA_CPU_INT_ICLR_DMACH1_OFS              (1)                             /* !< DMACH1 Offset */
#define DMA_CPU_INT_ICLR_DMACH1_MASK             ((uint32_t)0x00000002U)         /* !< DMA Channel 1 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_ICLR_DMACH1_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_CPU_INT_ICLR_DMACH1_CLR              ((uint32_t)0x00000002U)         /* !< Clear interrupt */
/* DMA_CPU_INT_ICLR[DMACH2] Bits */
#define DMA_CPU_INT_ICLR_DMACH2_OFS              (2)                             /* !< DMACH2 Offset */
#define DMA_CPU_INT_ICLR_DMACH2_MASK             ((uint32_t)0x00000004U)         /* !< DMA Channel 2 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_ICLR_DMACH2_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_CPU_INT_ICLR_DMACH2_CLR              ((uint32_t)0x00000004U)         /* !< Clear interrupt */
/* DMA_CPU_INT_ICLR[DMACH3] Bits */
#define DMA_CPU_INT_ICLR_DMACH3_OFS              (3)                             /* !< DMACH3 Offset */
#define DMA_CPU_INT_ICLR_DMACH3_MASK             ((uint32_t)0x00000008U)         /* !< DMA Channel 3 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_ICLR_DMACH3_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_CPU_INT_ICLR_DMACH3_CLR              ((uint32_t)0x00000008U)         /* !< Clear interrupt */
/* DMA_CPU_INT_ICLR[DMACH4] Bits */
#define DMA_CPU_INT_ICLR_DMACH4_OFS              (4)                             /* !< DMACH4 Offset */
#define DMA_CPU_INT_ICLR_DMACH4_MASK             ((uint32_t)0x00000010U)         /* !< DMA Channel 4 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_ICLR_DMACH4_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_CPU_INT_ICLR_DMACH4_CLR              ((uint32_t)0x00000010U)         /* !< Clear interrupt */
/* DMA_CPU_INT_ICLR[DMACH5] Bits */
#define DMA_CPU_INT_ICLR_DMACH5_OFS              (5)                             /* !< DMACH5 Offset */
#define DMA_CPU_INT_ICLR_DMACH5_MASK             ((uint32_t)0x00000020U)         /* !< DMA Channel 5 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_ICLR_DMACH5_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_CPU_INT_ICLR_DMACH5_CLR              ((uint32_t)0x00000020U)         /* !< Clear interrupt */
/* DMA_CPU_INT_ICLR[DMACH6] Bits */
#define DMA_CPU_INT_ICLR_DMACH6_OFS              (6)                             /* !< DMACH6 Offset */
#define DMA_CPU_INT_ICLR_DMACH6_MASK             ((uint32_t)0x00000040U)         /* !< DMA Channel 6 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_ICLR_DMACH6_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_CPU_INT_ICLR_DMACH6_CLR              ((uint32_t)0x00000040U)         /* !< Clear interrupt */
/* DMA_CPU_INT_ICLR[DMACH7] Bits */
#define DMA_CPU_INT_ICLR_DMACH7_OFS              (7)                             /* !< DMACH7 Offset */
#define DMA_CPU_INT_ICLR_DMACH7_MASK             ((uint32_t)0x00000080U)         /* !< DMA Channel 7 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_ICLR_DMACH7_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_CPU_INT_ICLR_DMACH7_CLR              ((uint32_t)0x00000080U)         /* !< Clear interrupt */
/* DMA_CPU_INT_ICLR[DMACH8] Bits */
#define DMA_CPU_INT_ICLR_DMACH8_OFS              (8)                             /* !< DMACH8 Offset */
#define DMA_CPU_INT_ICLR_DMACH8_MASK             ((uint32_t)0x00000100U)         /* !< DMA Channel 8 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_ICLR_DMACH8_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_CPU_INT_ICLR_DMACH8_CLR              ((uint32_t)0x00000100U)         /* !< Clear interrupt */
/* DMA_CPU_INT_ICLR[DMACH9] Bits */
#define DMA_CPU_INT_ICLR_DMACH9_OFS              (9)                             /* !< DMACH9 Offset */
#define DMA_CPU_INT_ICLR_DMACH9_MASK             ((uint32_t)0x00000200U)         /* !< DMA Channel 9 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_ICLR_DMACH9_NO_EFFECT        ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_CPU_INT_ICLR_DMACH9_CLR              ((uint32_t)0x00000200U)         /* !< Clear interrupt */
/* DMA_CPU_INT_ICLR[DMACH10] Bits */
#define DMA_CPU_INT_ICLR_DMACH10_OFS             (10)                            /* !< DMACH10 Offset */
#define DMA_CPU_INT_ICLR_DMACH10_MASK            ((uint32_t)0x00000400U)         /* !< DMA Channel 10 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_ICLR_DMACH10_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_CPU_INT_ICLR_DMACH10_CLR             ((uint32_t)0x00000400U)         /* !< Clear interrupt */
/* DMA_CPU_INT_ICLR[DMACH11] Bits */
#define DMA_CPU_INT_ICLR_DMACH11_OFS             (11)                            /* !< DMACH11 Offset */
#define DMA_CPU_INT_ICLR_DMACH11_MASK            ((uint32_t)0x00000800U)         /* !< DMA Channel 11 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_ICLR_DMACH11_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_CPU_INT_ICLR_DMACH11_CLR             ((uint32_t)0x00000800U)         /* !< Clear interrupt */
/* DMA_CPU_INT_ICLR[DMACH12] Bits */
#define DMA_CPU_INT_ICLR_DMACH12_OFS             (12)                            /* !< DMACH12 Offset */
#define DMA_CPU_INT_ICLR_DMACH12_MASK            ((uint32_t)0x00001000U)         /* !< DMA Channel 12 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_ICLR_DMACH12_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_CPU_INT_ICLR_DMACH12_CLR             ((uint32_t)0x00001000U)         /* !< Clear interrupt */
/* DMA_CPU_INT_ICLR[DMACH13] Bits */
#define DMA_CPU_INT_ICLR_DMACH13_OFS             (13)                            /* !< DMACH13 Offset */
#define DMA_CPU_INT_ICLR_DMACH13_MASK            ((uint32_t)0x00002000U)         /* !< DMA Channel 13 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_ICLR_DMACH13_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_CPU_INT_ICLR_DMACH13_CLR             ((uint32_t)0x00002000U)         /* !< Clear interrupt */
/* DMA_CPU_INT_ICLR[DMACH14] Bits */
#define DMA_CPU_INT_ICLR_DMACH14_OFS             (14)                            /* !< DMACH14 Offset */
#define DMA_CPU_INT_ICLR_DMACH14_MASK            ((uint32_t)0x00004000U)         /* !< DMA Channel 14 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_ICLR_DMACH14_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_CPU_INT_ICLR_DMACH14_CLR             ((uint32_t)0x00004000U)         /* !< Clear interrupt */
/* DMA_CPU_INT_ICLR[DMACH15] Bits */
#define DMA_CPU_INT_ICLR_DMACH15_OFS             (15)                            /* !< DMACH15 Offset */
#define DMA_CPU_INT_ICLR_DMACH15_MASK            ((uint32_t)0x00008000U)         /* !< DMA Channel 15 interrupt signals
                                                                                    that size counter reached zero
                                                                                    (DMASZ=0). */
#define DMA_CPU_INT_ICLR_DMACH15_NO_EFFECT       ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define DMA_CPU_INT_ICLR_DMACH15_CLR             ((uint32_t)0x00008000U)         /* !< Clear interrupt */
/* DMA_CPU_INT_ICLR[PREIRQCH0] Bits */
#define DMA_CPU_INT_ICLR_PREIRQCH0_OFS           (16)                            /* !< PREIRQCH0 Offset */
#define DMA_CPU_INT_ICLR_PREIRQCH0_MASK          ((uint32_t)0x00010000U)         /* !< Pre-IRQ for Channel 0. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_CPU_INT_ICLR_PREIRQCH0_CLR           ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_ICLR_PREIRQCH0_SET           ((uint32_t)0x00010000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_ICLR[PREIRQCH1] Bits */
#define DMA_CPU_INT_ICLR_PREIRQCH1_OFS           (17)                            /* !< PREIRQCH1 Offset */
#define DMA_CPU_INT_ICLR_PREIRQCH1_MASK          ((uint32_t)0x00020000U)         /* !< Pre-IRQ for Channel 1. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_CPU_INT_ICLR_PREIRQCH1_CLR           ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_ICLR_PREIRQCH1_SET           ((uint32_t)0x00020000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_ICLR[PREIRQCH2] Bits */
#define DMA_CPU_INT_ICLR_PREIRQCH2_OFS           (18)                            /* !< PREIRQCH2 Offset */
#define DMA_CPU_INT_ICLR_PREIRQCH2_MASK          ((uint32_t)0x00040000U)         /* !< Pre-IRQ for Channel 2. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_CPU_INT_ICLR_PREIRQCH2_CLR           ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_ICLR_PREIRQCH2_SET           ((uint32_t)0x00040000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_ICLR[PREIRQCH3] Bits */
#define DMA_CPU_INT_ICLR_PREIRQCH3_OFS           (19)                            /* !< PREIRQCH3 Offset */
#define DMA_CPU_INT_ICLR_PREIRQCH3_MASK          ((uint32_t)0x00080000U)         /* !< Pre-IRQ for Channel 3. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_CPU_INT_ICLR_PREIRQCH3_CLR           ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_ICLR_PREIRQCH3_SET           ((uint32_t)0x00080000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_ICLR[PREIRQCH4] Bits */
#define DMA_CPU_INT_ICLR_PREIRQCH4_OFS           (20)                            /* !< PREIRQCH4 Offset */
#define DMA_CPU_INT_ICLR_PREIRQCH4_MASK          ((uint32_t)0x00100000U)         /* !< Pre-IRQ for Channel 4. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_CPU_INT_ICLR_PREIRQCH4_CLR           ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_ICLR_PREIRQCH4_SET           ((uint32_t)0x00100000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_ICLR[PREIRQCH5] Bits */
#define DMA_CPU_INT_ICLR_PREIRQCH5_OFS           (21)                            /* !< PREIRQCH5 Offset */
#define DMA_CPU_INT_ICLR_PREIRQCH5_MASK          ((uint32_t)0x00200000U)         /* !< Pre-IRQ for Channel 5. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_CPU_INT_ICLR_PREIRQCH5_CLR           ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_ICLR_PREIRQCH5_SET           ((uint32_t)0x00200000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_ICLR[PREIRQCH6] Bits */
#define DMA_CPU_INT_ICLR_PREIRQCH6_OFS           (22)                            /* !< PREIRQCH6 Offset */
#define DMA_CPU_INT_ICLR_PREIRQCH6_MASK          ((uint32_t)0x00400000U)         /* !< Pre-IRQ for Channel 6. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_CPU_INT_ICLR_PREIRQCH6_CLR           ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_ICLR_PREIRQCH6_SET           ((uint32_t)0x00400000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_ICLR[PREIRQCH7] Bits */
#define DMA_CPU_INT_ICLR_PREIRQCH7_OFS           (23)                            /* !< PREIRQCH7 Offset */
#define DMA_CPU_INT_ICLR_PREIRQCH7_MASK          ((uint32_t)0x00800000U)         /* !< Pre-IRQ for Channel 7. Size counter
                                                                                    reached Pre-IRQ threshold. */
#define DMA_CPU_INT_ICLR_PREIRQCH7_CLR           ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_ICLR_PREIRQCH7_SET           ((uint32_t)0x00800000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_ICLR[ADDRERR] Bits */
#define DMA_CPU_INT_ICLR_ADDRERR_OFS             (24)                            /* !< ADDRERR Offset */
#define DMA_CPU_INT_ICLR_ADDRERR_MASK            ((uint32_t)0x01000000U)         /* !< DMA address error, SRC address not
                                                                                    reachable. */
#define DMA_CPU_INT_ICLR_ADDRERR_CLR             ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_ICLR_ADDRERR_SET             ((uint32_t)0x01000000U)         /* !< Set interrupt mask bit */
/* DMA_CPU_INT_ICLR[DATAERR] Bits */
#define DMA_CPU_INT_ICLR_DATAERR_OFS             (25)                            /* !< DATAERR Offset */
#define DMA_CPU_INT_ICLR_DATAERR_MASK            ((uint32_t)0x02000000U)         /* !< DMA data error, SRC data might be
                                                                                    corrupted (PAR or ECC error). */
#define DMA_CPU_INT_ICLR_DATAERR_CLR             ((uint32_t)0x00000000U)         /* !< Clear interrupt mask bit */
#define DMA_CPU_INT_ICLR_DATAERR_SET             ((uint32_t)0x02000000U)         /* !< Set interrupt mask bit */

/* DMA_FSUB_0 Bits */
/* DMA_FSUB_0[CHANID] Bits */
#define DMA_FSUB_0_CHANID_OFS                    (0)                             /* !< CHANID Offset */
#define DMA_FSUB_0_CHANID_MASK                   ((uint32_t)0x000000FFU)         /* !< 0 = disconnected. 1-255 = connected
                                                                                    to channelID = CHANID. */
#define DMA_FSUB_0_CHANID_MNIMUM                 ((uint32_t)0x00000000U)         /* !< 0 is an allowed value, signifying
                                                                                    that the event is unconnected */
#define DMA_FSUB_0_CHANID_UNCONNECTED            ((uint32_t)0x00000000U)         /* !< A value of 0 specifies that the
                                                                                    event is not connected */
#define DMA_FSUB_0_CHANID_MAXIMUM                ((uint32_t)0x000000FFU)         /* !< Consult your device datasheet as
                                                                                    the actual allowed maximum may be
                                                                                    less than 255. */

/* DMA_FSUB_1 Bits */
/* DMA_FSUB_1[CHANID] Bits */
#define DMA_FSUB_1_CHANID_OFS                    (0)                             /* !< CHANID Offset */
#define DMA_FSUB_1_CHANID_MASK                   ((uint32_t)0x000000FFU)         /* !< 0 = disconnected. 1-255 = connected
                                                                                    to channelID = CHANID. */
#define DMA_FSUB_1_CHANID_MNIMUM                 ((uint32_t)0x00000000U)         /* !< 0 is an allowed value, signifying
                                                                                    that the event is unconnected */
#define DMA_FSUB_1_CHANID_UNCONNECTED            ((uint32_t)0x00000000U)         /* !< A value of 0 specifies that the
                                                                                    event is not connected */
#define DMA_FSUB_1_CHANID_MAXIMUM                ((uint32_t)0x000000FFU)         /* !< Consult your device datasheet as
                                                                                    the actual allowed maximum may be
                                                                                    less than 255. */

/* DMA_FPUB_1 Bits */
/* DMA_FPUB_1[CHANID] Bits */
#define DMA_FPUB_1_CHANID_OFS                    (0)                             /* !< CHANID Offset */
#define DMA_FPUB_1_CHANID_MASK                   ((uint32_t)0x000000FFU)         /* !< 0 = disconnected. 1-255 = connected
                                                                                    to channelID = CHANID. */
#define DMA_FPUB_1_CHANID_MNIMUM                 ((uint32_t)0x00000000U)         /* !< 0 is an allowed value, signifying
                                                                                    that the event is unconnected */
#define DMA_FPUB_1_CHANID_UNCONNECTED            ((uint32_t)0x00000000U)         /* !< A value of 0 specifies that the
                                                                                    event is not connected */
#define DMA_FPUB_1_CHANID_MAXIMUM                ((uint32_t)0x000000FFU)         /* !< Consult your device datasheet as
                                                                                    the actual allowed maximum may be
                                                                                    less than 255. */

/* DMA_PDBGCTL Bits */
/* DMA_PDBGCTL[FREE] Bits */
#define DMA_PDBGCTL_FREE_OFS                     (0)                             /* !< FREE Offset */
#define DMA_PDBGCTL_FREE_MASK                    ((uint32_t)0x00000001U)         /* !< Free run control */
#define DMA_PDBGCTL_FREE_STOP                    ((uint32_t)0x00000000U)         /* !< The peripheral freezes
                                                                                    functionality while the Core Halted
                                                                                    input is asserted and resumes when it
                                                                                    is deasserted. */
#define DMA_PDBGCTL_FREE_RUN                     ((uint32_t)0x00000001U)         /* !< The peripheral ignores the state of
                                                                                    the Core Halted input */
/* DMA_PDBGCTL[SOFT] Bits */
#define DMA_PDBGCTL_SOFT_OFS                     (1)                             /* !< SOFT Offset */
#define DMA_PDBGCTL_SOFT_MASK                    ((uint32_t)0x00000002U)         /* !< Soft halt boundary control. This
                                                                                    function is only available, if [FREE]
                                                                                    is set to 'STOP' */
#define DMA_PDBGCTL_SOFT_IMMEDIATE               ((uint32_t)0x00000000U)         /* !< The peripheral will halt
                                                                                    immediately, even if the resultant
                                                                                    state will result in corruption if
                                                                                    the system is restarted */
#define DMA_PDBGCTL_SOFT_DELAYED                 ((uint32_t)0x00000002U)         /* !< The peripheral blocks the debug
                                                                                    freeze until it has reached a
                                                                                    boundary where it can resume without
                                                                                    corruption */

/* DMA_EVT_MODE Bits */
/* DMA_EVT_MODE[INT0_CFG] Bits */
#define DMA_EVT_MODE_INT0_CFG_OFS                (0)                             /* !< INT0_CFG Offset */
#define DMA_EVT_MODE_INT0_CFG_MASK               ((uint32_t)0x00000003U)         /* !< Event line mode select for event
                                                                                    corresponding to interrupt event
                                                                                    CPU_INT */
#define DMA_EVT_MODE_INT0_CFG_DISABLE            ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define DMA_EVT_MODE_INT0_CFG_SOFTWARE           ((uint32_t)0x00000001U)         /* !< The interrupt or event line is in
                                                                                    software mode. Software must clear
                                                                                    the RIS. */
#define DMA_EVT_MODE_INT0_CFG_HARDWARE           ((uint32_t)0x00000002U)         /* !< The interrupt or event line is in
                                                                                    hardware mode. The hardware (another
                                                                                    module) clears automatically the
                                                                                    associated RIS flag. */
/* DMA_EVT_MODE[EVT1_CFG] Bits */
#define DMA_EVT_MODE_EVT1_CFG_OFS                (2)                             /* !< EVT1_CFG Offset */
#define DMA_EVT_MODE_EVT1_CFG_MASK               ((uint32_t)0x0000000CU)         /* !< Event line mode select for event
                                                                                    corresponding to generic event
                                                                                    GEN_EVENT */
#define DMA_EVT_MODE_EVT1_CFG_DISABLE            ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define DMA_EVT_MODE_EVT1_CFG_SOFTWARE           ((uint32_t)0x00000004U)         /* !< The interrupt or event line is in
                                                                                    software mode. Software must clear
                                                                                    the RIS. */
#define DMA_EVT_MODE_EVT1_CFG_HARDWARE           ((uint32_t)0x00000008U)         /* !< The interrupt or event line is in
                                                                                    hardware mode. The hardware (another
                                                                                    module) clears automatically the
                                                                                    associated RIS flag. */

/* DMA_DESC Bits */
/* DMA_DESC[MINREV] Bits */
#define DMA_DESC_MINREV_OFS                      (0)                             /* !< MINREV Offset */
#define DMA_DESC_MINREV_MASK                     ((uint32_t)0x0000000FU)         /* !< Minor rev of the IP */
#define DMA_DESC_MINREV_MINIMUM                  ((uint32_t)0x00000000U)         /* !< Smallest value */
#define DMA_DESC_MINREV_MAXIMUM                  ((uint32_t)0x0000000FU)         /* !< Highest possible value */
/* DMA_DESC[MAJREV] Bits */
#define DMA_DESC_MAJREV_OFS                      (4)                             /* !< MAJREV Offset */
#define DMA_DESC_MAJREV_MASK                     ((uint32_t)0x000000F0U)         /* !< Major rev of the IP */
#define DMA_DESC_MAJREV_MINIMUM                  ((uint32_t)0x00000000U)         /* !< Smallest value */
#define DMA_DESC_MAJREV_MAXIMUM                  ((uint32_t)0x000000F0U)         /* !< Highest possible value */
/* DMA_DESC[FEATUREVER] Bits */
#define DMA_DESC_FEATUREVER_OFS                  (12)                            /* !< FEATUREVER Offset */
#define DMA_DESC_FEATUREVER_MASK                 ((uint32_t)0x0000F000U)         /* !< Feature Set for the DMA: number of
                                                                                    DMA channel minus one  (e.g. 0->1ch,
                                                                                    2->3ch, 15->16ch). */
#define DMA_DESC_FEATUREVER_MINIMUM              ((uint32_t)0x00000000U)         /* !< Smallest value (1 channel) */
#define DMA_DESC_FEATUREVER_MAXIMUM              ((uint32_t)0x0000F000U)         /* !< Highest value (16 channel) */
/* DMA_DESC[MODULEID] Bits */
#define DMA_DESC_MODULEID_OFS                    (16)                            /* !< MODULEID Offset */
#define DMA_DESC_MODULEID_MASK                   ((uint32_t)0xFFFF0000U)         /* !< Module identification contains a
                                                                                    unique peripheral identification
                                                                                    number. The assignments are
                                                                                    maintained in a central database for
                                                                                    all of the platform modules to ensure
                                                                                    uniqueness. */
#define DMA_DESC_MODULEID_MINIMUM                ((uint32_t)0x00000000U)         /* !< Smallest value */
#define DMA_DESC_MODULEID_MAXIMUM                ((uint32_t)0xFFFF0000U)         /* !< Highest possible value */

/* DMA_DMAPRIO Bits */
/* DMA_DMAPRIO[ROUNDROBIN] Bits */
#define DMA_DMAPRIO_ROUNDROBIN_OFS               (0)                             /* !< ROUNDROBIN Offset */
#define DMA_DMAPRIO_ROUNDROBIN_MASK              ((uint32_t)0x00000001U)         /* !< Round robin. This bit enables the
                                                                                    round-robin DMA channel priorities. */
#define DMA_DMAPRIO_ROUNDROBIN_DISABLE           ((uint32_t)0x00000000U)         /* !< Roundrobin priority disabled, DMA
                                                                                    channel priority is fixed:
                                                                                    DMA0-DMA1-DMA2-...-DMA16 */
#define DMA_DMAPRIO_ROUNDROBIN_ENABLE            ((uint32_t)0x00000001U)         /* !< Roundrobin priority enabled, DMA
                                                                                    channel priority changes with each
                                                                                    transfer */
/* DMA_DMAPRIO[BURSTSZ] Bits */
#define DMA_DMAPRIO_BURSTSZ_OFS                  (16)                            /* !< BURSTSZ Offset */
#define DMA_DMAPRIO_BURSTSZ_MASK                 ((uint32_t)0x00030000U)         /* !< Define the burst size of a block
                                                                                    transfer, before the priority is
                                                                                    re-evaluated */
#define DMA_DMAPRIO_BURSTSZ_INFINITI             ((uint32_t)0x00000000U)         /* !< There is no burst size, the whole
                                                                                    block transfer is completed on one
                                                                                    transfer without interruption */
#define DMA_DMAPRIO_BURSTSZ_BURST_8              ((uint32_t)0x00010000U)         /* !< The burst size is 8, after 9
                                                                                    transfers the block transfer is
                                                                                    interrupted and the priority is
                                                                                    reevaluated */
#define DMA_DMAPRIO_BURSTSZ_BUSRT_16             ((uint32_t)0x00020000U)         /* !< The burst size is 16, after 17
                                                                                    transfers the block transfer is
                                                                                    interrupted and the priority is
                                                                                    reevaluated */
#define DMA_DMAPRIO_BURSTSZ_BURST_32             ((uint32_t)0x00030000U)         /* !< The burst size is 32, after 33
                                                                                    transfers the block transfer is
                                                                                    interrupted and the priority is
                                                                                    reevaluated */


#ifdef __cplusplus
}
#endif

#endif /* ti_devices_msp_peripherals_hw_dma__include */

