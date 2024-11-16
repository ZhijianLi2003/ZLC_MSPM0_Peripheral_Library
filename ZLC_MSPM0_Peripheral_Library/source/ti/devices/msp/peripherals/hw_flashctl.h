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

#ifndef ti_devices_msp_peripherals_hw_flashctl__include
#define ti_devices_msp_peripherals_hw_flashctl__include

/* Filename: hw_flashctl.h */
/* Revised: 2023-05-04 09:46:28 */
/* Revision: 59e844638cbc4054026b3e132f05a3e05d70f5a2 */

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
* FLASHCTL Registers
******************************************************************************/
#define FLASHCTL_GEN_OFS                         ((uint32_t)0x00000000U)


/** @addtogroup FLASHCTL_GEN
  @{
*/

typedef struct {
       uint32_t RESERVED0[1032];
  __I  uint32_t IIDX;                              /* !< (@ 0x00001020) Interrupt Index Register */
       uint32_t RESERVED1;
  __IO uint32_t IMASK;                             /* !< (@ 0x00001028) Interrupt Mask Register */
       uint32_t RESERVED2;
  __I  uint32_t RIS;                               /* !< (@ 0x00001030) Raw Interrupt Status Register */
       uint32_t RESERVED3;
  __I  uint32_t MIS;                               /* !< (@ 0x00001038) Masked Interrupt Status Register */
       uint32_t RESERVED4;
  __O  uint32_t ISET;                              /* !< (@ 0x00001040) Interrupt Set Register */
       uint32_t RESERVED5;
  __O  uint32_t ICLR;                              /* !< (@ 0x00001048) Interrupt Clear Register */
       uint32_t RESERVED6[37];
  __I  uint32_t EVT_MODE;                          /* !< (@ 0x000010E0) Event Mode */
       uint32_t RESERVED7[6];
  __I  uint32_t DESC;                              /* !< (@ 0x000010FC) Hardware Version Description Register */
  __IO uint32_t CMDEXEC;                           /* !< (@ 0x00001100) Command Execute Register */
  __IO uint32_t CMDTYPE;                           /* !< (@ 0x00001104) Command Type Register */
  __IO uint32_t CMDCTL;                            /* !< (@ 0x00001108) Command Control Register */
       uint32_t RESERVED8[5];
  __IO uint32_t CMDADDR;                           /* !< (@ 0x00001120) Command Address Register */
  __IO uint32_t CMDBYTEN;                          /* !< (@ 0x00001124) Command Program Byte Enable Register */
       uint32_t RESERVED9;
  __IO uint32_t CMDDATAINDEX;                      /* !< (@ 0x0000112C) Command Data Index Register */
  __IO uint32_t CMDDATA0;                          /* !< (@ 0x00001130) Command Data Register 0 */
  __IO uint32_t CMDDATA1;                          /* !< (@ 0x00001134) Command Data Register 1 */
  __IO uint32_t CMDDATA2;                          /* !< (@ 0x00001138) Command Data Register 2 */
  __IO uint32_t CMDDATA3;                          /* !< (@ 0x0000113C) Command Data Register Bits 127:96 */
  __IO uint32_t CMDDATA4;                          /* !< (@ 0x00001140) Command Data Register 4 */
  __IO uint32_t CMDDATA5;                          /* !< (@ 0x00001144) Command Data Register 5 */
  __IO uint32_t CMDDATA6;                          /* !< (@ 0x00001148) Command Data Register 6 */
  __IO uint32_t CMDDATA7;                          /* !< (@ 0x0000114C) Command Data Register 7 */
  __IO uint32_t CMDDATA8;                          /* !< (@ 0x00001150) Command Data Register 8 */
  __IO uint32_t CMDDATA9;                          /* !< (@ 0x00001154) Command Data Register 9 */
  __IO uint32_t CMDDATA10;                         /* !< (@ 0x00001158) Command Data Register 10 */
  __IO uint32_t CMDDATA11;                         /* !< (@ 0x0000115C) Command Data Register 11 */
  __IO uint32_t CMDDATA12;                         /* !< (@ 0x00001160) Command Data Register 12 */
  __IO uint32_t CMDDATA13;                         /* !< (@ 0x00001164) Command Data Register 13 */
  __IO uint32_t CMDDATA14;                         /* !< (@ 0x00001168) Command Data Register 14 */
  __IO uint32_t CMDDATA15;                         /* !< (@ 0x0000116C) Command Data Register 15 */
  __IO uint32_t CMDDATA16;                         /* !< (@ 0x00001170) Command Data Register 16 */
  __IO uint32_t CMDDATA17;                         /* !< (@ 0x00001174) Command Data Register 17 */
  __IO uint32_t CMDDATA18;                         /* !< (@ 0x00001178) Command Data Register 18 */
  __IO uint32_t CMDDATA19;                         /* !< (@ 0x0000117C) Command Data Register 19 */
  __IO uint32_t CMDDATA20;                         /* !< (@ 0x00001180) Command Data Register 20 */
  __IO uint32_t CMDDATA21;                         /* !< (@ 0x00001184) Command Data Register 21 */
  __IO uint32_t CMDDATA22;                         /* !< (@ 0x00001188) Command Data Register 22 */
  __IO uint32_t CMDDATA23;                         /* !< (@ 0x0000118C) Command Data Register 23 */
  __IO uint32_t CMDDATA24;                         /* !< (@ 0x00001190) Command Data Register 24 */
  __IO uint32_t CMDDATA25;                         /* !< (@ 0x00001194) Command Data Register 25 */
  __IO uint32_t CMDDATA26;                         /* !< (@ 0x00001198) Command Data Register 26 */
  __IO uint32_t CMDDATA27;                         /* !< (@ 0x0000119C) Command Data Register 27 */
  __IO uint32_t CMDDATA28;                         /* !< (@ 0x000011A0) Command Data Register 28 */
  __IO uint32_t CMDDATA29;                         /* !< (@ 0x000011A4) Command Data Register 29 */
  __IO uint32_t CMDDATA30;                         /* !< (@ 0x000011A8) Command Data Register 30 */
  __IO uint32_t CMDDATA31;                         /* !< (@ 0x000011AC) Command Data Register 31 */
  __IO uint32_t CMDDATAECC0;                       /* !< (@ 0x000011B0) Command Data Register ECC 0 */
  __IO uint32_t CMDDATAECC1;                       /* !< (@ 0x000011B4) Command Data Register ECC 1 */
  __IO uint32_t CMDDATAECC2;                       /* !< (@ 0x000011B8) Command Data Register ECC 2 */
  __IO uint32_t CMDDATAECC3;                       /* !< (@ 0x000011BC) Command Data Register ECC 3 */
  __IO uint32_t CMDDATAECC4;                       /* !< (@ 0x000011C0) Command Data Register ECC 4 */
  __IO uint32_t CMDDATAECC5;                       /* !< (@ 0x000011C4) Command Data Register ECC 5 */
  __IO uint32_t CMDDATAECC6;                       /* !< (@ 0x000011C8) Command Data Register ECC 6 */
  __IO uint32_t CMDDATAECC7;                       /* !< (@ 0x000011CC) Command Data Register ECC 7 */
  __IO uint32_t CMDWEPROTA;                        /* !< (@ 0x000011D0) Command Write Erase Protect A Register */
  __IO uint32_t CMDWEPROTB;                        /* !< (@ 0x000011D4) Command Write Erase Protect B Register */
  __IO uint32_t CMDWEPROTC;                        /* !< (@ 0x000011D8) Command Write Erase Protect C Register */
       uint32_t RESERVED10[13];
  __IO uint32_t CMDWEPROTNM;                       /* !< (@ 0x00001210) Command Write Erase Protect Non-Main Register */
  __IO uint32_t CMDWEPROTTR;                       /* !< (@ 0x00001214) Command Write Erase Protect Trim Register */
  __IO uint32_t CMDWEPROTEN;                       /* !< (@ 0x00001218) Command Write Erase Protect Engr Register */
       uint32_t RESERVED11[101];
  __IO uint32_t CFGCMD;                            /* !< (@ 0x000013B0) Command Configuration Register */
  __IO uint32_t CFGPCNT;                           /* !< (@ 0x000013B4) Pulse Counter Configuration Register */
       uint32_t RESERVED12[6];
  __I  uint32_t STATCMD;                           /* !< (@ 0x000013D0) Command Status Register */
  __I  uint32_t STATADDR;                          /* !< (@ 0x000013D4) Address Status Register */
  __I  uint32_t STATPCNT;                          /* !< (@ 0x000013D8) Pulse Count Status Register */
  __I  uint32_t STATMODE;                          /* !< (@ 0x000013DC) Mode Status Register */
       uint32_t RESERVED13[4];
  __I  uint32_t GBLINFO0;                          /* !< (@ 0x000013F0) Global Information Register 0 */
  __I  uint32_t GBLINFO1;                          /* !< (@ 0x000013F4) Global Information Register 1 */
  __I  uint32_t GBLINFO2;                          /* !< (@ 0x000013F8) Global Information Register 2 */
       uint32_t RESERVED14;
  __I  uint32_t BANK0INFO0;                        /* !< (@ 0x00001400) Bank Information Register 0 for Bank 0 */
  __I  uint32_t BANK0INFO1;                        /* !< (@ 0x00001404) Bank Information Register 1 for Bank 0 */
       uint32_t RESERVED15[2];
  __I  uint32_t BANK1INFO0;                        /* !< (@ 0x00001410) Bank Information Register 0 for Bank 1 */
  __I  uint32_t BANK1INFO1;                        /* !< (@ 0x00001414) Bank Information Register 1 for Bank 1 */
       uint32_t RESERVED16[2];
  __I  uint32_t BANK2INFO0;                        /* !< (@ 0x00001420) Bank Information Register 0 for Bank 2 */
  __I  uint32_t BANK2INFO1;                        /* !< (@ 0x00001424) Bank Information Register 1 for Bank 2 */
       uint32_t RESERVED17[2];
  __I  uint32_t BANK3INFO0;                        /* !< (@ 0x00001430) Bank Information Register 0 for Bank 3 */
  __I  uint32_t BANK3INFO1;                        /* !< (@ 0x00001434) Bank Information Register 1 for Bank 3 */
       uint32_t RESERVED18[2];
  __I  uint32_t BANK4INFO0;                        /* !< (@ 0x00001440) Bank Information Register 0 for Bank 4 */
  __I  uint32_t BANK4INFO1;                        /* !< (@ 0x00001444) Bank Information Register 1 for Bank 4 */
} FLASHCTL_GEN_Regs;

/*@}*/ /* end of group FLASHCTL_GEN */

/** @addtogroup FLASHCTL
  @{
*/

typedef struct {
  FLASHCTL_GEN_Regs  GEN;                               /* !< (@ 0x00000000) */
} FLASHCTL_Regs;

/*@}*/ /* end of group FLASHCTL */



#if defined ( __CC_ARM )
#pragma no_anon_unions
#endif

/******************************************************************************
* FLASHCTL Register Control Bits
******************************************************************************/

/* FLASHCTL_IIDX Bits */
/* FLASHCTL_IIDX[STAT] Bits */
#define FLASHCTL_IIDX_STAT_OFS                   (0)                             /* !< STAT Offset */
#define FLASHCTL_IIDX_STAT_MASK                  ((uint32_t)0x00000001U)         /* !< Indicates which interrupt has
                                                                                    fired. 0x0 means no event pending.
                                                                                    The priority order is fixed. On each
                                                                                    read, only one interrupt is
                                                                                    indicated. On a read, the current
                                                                                    interrupt (highest priority) is
                                                                                    automatically cleared by the hardware
                                                                                    and the corresponding interrupt flags
                                                                                    in the RIS and MIS are cleared as
                                                                                    well. After a read from the CPU (not
                                                                                    from the debug interface), the
                                                                                    register must be updated with the
                                                                                    next highest priority interrupt. */
#define FLASHCTL_IIDX_STAT_NO_INTR               ((uint32_t)0x00000000U)         /* !< No Interrupt Pending */
#define FLASHCTL_IIDX_STAT_DONE                  ((uint32_t)0x00000001U)         /* !< DONE Interrupt Pending */

/* FLASHCTL_IMASK Bits */
/* FLASHCTL_IMASK[DONE] Bits */
#define FLASHCTL_IMASK_DONE_OFS                  (0)                             /* !< DONE Offset */
#define FLASHCTL_IMASK_DONE_MASK                 ((uint32_t)0x00000001U)         /* !< Interrupt mask for DONE: 0:
                                                                                    Interrupt is disabled in MIS register
                                                                                    1: Interrupt is enabled in MIS
                                                                                    register */
#define FLASHCTL_IMASK_DONE_DISABLED             ((uint32_t)0x00000000U)         /* !< Interrupt is masked out */
#define FLASHCTL_IMASK_DONE_ENABLED              ((uint32_t)0x00000001U)         /* !< Interrupt will request an interrupt
                                                                                    service routine and corresponding bit
                                                                                    in [IPSTANDARD.MIS] will be set */

/* FLASHCTL_RIS Bits */
/* FLASHCTL_RIS[DONE] Bits */
#define FLASHCTL_RIS_DONE_OFS                    (0)                             /* !< DONE Offset */
#define FLASHCTL_RIS_DONE_MASK                   ((uint32_t)0x00000001U)         /* !< Flash wrapper operation completed.
                                                                                    This interrupt bit is set by firmware
                                                                                    or the corresponding bit in the ISET
                                                                                    register. It is cleared by the
                                                                                    corresponding bit in in the ICLR
                                                                                    register or reading the IIDX register
                                                                                    when this interrupt is the highest
                                                                                    priority. */
#define FLASHCTL_RIS_DONE_CLR                    ((uint32_t)0x00000000U)         /* !< Interrupt did not occur */
#define FLASHCTL_RIS_DONE_SET                    ((uint32_t)0x00000001U)         /* !< Interrupt occurred */

/* FLASHCTL_MIS Bits */
/* FLASHCTL_MIS[DONE] Bits */
#define FLASHCTL_MIS_DONE_OFS                    (0)                             /* !< DONE Offset */
#define FLASHCTL_MIS_DONE_MASK                   ((uint32_t)0x00000001U)         /* !< Flash wrapper operation completed.
                                                                                    This masked interrupt bit reflects
                                                                                    the bitwise AND of the corresponding
                                                                                    RIS and IMASK bits. */
#define FLASHCTL_MIS_DONE_CLR                    ((uint32_t)0x00000000U)         /* !< Masked interrupt did not occur */
#define FLASHCTL_MIS_DONE_SET                    ((uint32_t)0x00000001U)         /* !< Masked interrupt occurred */

/* FLASHCTL_ISET Bits */
/* FLASHCTL_ISET[DONE] Bits */
#define FLASHCTL_ISET_DONE_OFS                   (0)                             /* !< DONE Offset */
#define FLASHCTL_ISET_DONE_MASK                  ((uint32_t)0x00000001U)         /* !< 0: No effect 1: Set the DONE
                                                                                    interrupt in the RIS register */
#define FLASHCTL_ISET_DONE_NO_EFFECT             ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define FLASHCTL_ISET_DONE_SET                   ((uint32_t)0x00000001U)         /* !< Set [IPSTANDARD.RIS] bit */

/* FLASHCTL_ICLR Bits */
/* FLASHCTL_ICLR[DONE] Bits */
#define FLASHCTL_ICLR_DONE_OFS                   (0)                             /* !< DONE Offset */
#define FLASHCTL_ICLR_DONE_MASK                  ((uint32_t)0x00000001U)         /* !< 0: No effect 1: Clear the DONE
                                                                                    interrupt in the RIS register */
#define FLASHCTL_ICLR_DONE_NO_EFFECT             ((uint32_t)0x00000000U)         /* !< Writing a 0 has no effect */
#define FLASHCTL_ICLR_DONE_CLR                   ((uint32_t)0x00000001U)         /* !< Clear [IPSTANDARD.RIS] bit */

/* FLASHCTL_EVT_MODE Bits */
/* FLASHCTL_EVT_MODE[INT0_CFG] Bits */
#define FLASHCTL_EVT_MODE_INT0_CFG_OFS           (0)                             /* !< INT0_CFG Offset */
#define FLASHCTL_EVT_MODE_INT0_CFG_MASK          ((uint32_t)0x00000003U)         /* !< Event line mode select for
                                                                                    peripheral event */
#define FLASHCTL_EVT_MODE_INT0_CFG_DISABLE       ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define FLASHCTL_EVT_MODE_INT0_CFG_SOFTWARE      ((uint32_t)0x00000001U)         /* !< The interrupt or event line is in
                                                                                    software mode. Software must clear
                                                                                    the RIS. */
#define FLASHCTL_EVT_MODE_INT0_CFG_HARDWARE      ((uint32_t)0x00000002U)         /* !< The interrupt or event line is in
                                                                                    hardware mode. Hardware must clear
                                                                                    the RIS. */

/* FLASHCTL_DESC Bits */
/* FLASHCTL_DESC[MINREV] Bits */
#define FLASHCTL_DESC_MINREV_OFS                 (0)                             /* !< MINREV Offset */
#define FLASHCTL_DESC_MINREV_MASK                ((uint32_t)0x0000000FU)         /* !< Minor Revision */
#define FLASHCTL_DESC_MINREV_MINIMUM             ((uint32_t)0x00000000U)         /* !< Smallest value */
#define FLASHCTL_DESC_MINREV_MAXIMUM             ((uint32_t)0x0000000FU)         /* !< Highest possible value */
/* FLASHCTL_DESC[MAJREV] Bits */
#define FLASHCTL_DESC_MAJREV_OFS                 (4)                             /* !< MAJREV Offset */
#define FLASHCTL_DESC_MAJREV_MASK                ((uint32_t)0x000000F0U)         /* !< Major Revision */
#define FLASHCTL_DESC_MAJREV_MINIMUM             ((uint32_t)0x00000000U)         /* !< Smallest value */
#define FLASHCTL_DESC_MAJREV_MAXIMUM             ((uint32_t)0x000000F0U)         /* !< Highest possible value */
/* FLASHCTL_DESC[INSTNUM] Bits */
#define FLASHCTL_DESC_INSTNUM_OFS                (8)                             /* !< INSTNUM Offset */
#define FLASHCTL_DESC_INSTNUM_MASK               ((uint32_t)0x00000F00U)         /* !< Instance number */
#define FLASHCTL_DESC_INSTNUM_MINIMUM            ((uint32_t)0x00000000U)         /* !< Smallest value */
#define FLASHCTL_DESC_INSTNUM_MAXIMUM            ((uint32_t)0x00000F00U)         /* !< Highest possible value */
/* FLASHCTL_DESC[FEATUREVER] Bits */
#define FLASHCTL_DESC_FEATUREVER_OFS             (12)                            /* !< FEATUREVER Offset */
#define FLASHCTL_DESC_FEATUREVER_MASK            ((uint32_t)0x0000F000U)         /* !< Feature set */
#define FLASHCTL_DESC_FEATUREVER_MINIMUM         ((uint32_t)0x00000000U)         /* !< Minimum Value */
#define FLASHCTL_DESC_FEATUREVER_MAXIMUM         ((uint32_t)0x0000F000U)         /* !< Maximum Value */
/* FLASHCTL_DESC[MODULEID] Bits */
#define FLASHCTL_DESC_MODULEID_OFS               (16)                            /* !< MODULEID Offset */
#define FLASHCTL_DESC_MODULEID_MASK              ((uint32_t)0xFFFF0000U)         /* !< Module ID */
#define FLASHCTL_DESC_MODULEID_MINIMUM           ((uint32_t)0x00000000U)         /* !< Smallest value */
#define FLASHCTL_DESC_MODULEID_MAXIMUM           ((uint32_t)0xFFFF0000U)         /* !< Highest possible value */

/* FLASHCTL_CMDEXEC Bits */
/* FLASHCTL_CMDEXEC[VAL] Bits */
#define FLASHCTL_CMDEXEC_VAL_OFS                 (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDEXEC_VAL_MASK                ((uint32_t)0x00000001U)         /* !< Command Execute value Initiates
                                                                                    execution of the command specified in
                                                                                    the CMDTYPE register. */
#define FLASHCTL_CMDEXEC_VAL_NOEXECUTE           ((uint32_t)0x00000000U)         /* !< Command will not execute or is not
                                                                                    executing in flash wrapper */
#define FLASHCTL_CMDEXEC_VAL_EXECUTE             ((uint32_t)0x00000001U)         /* !< Command will execute or is
                                                                                    executing in flash wrapper */

/* FLASHCTL_CMDTYPE Bits */
/* FLASHCTL_CMDTYPE[COMMAND] Bits */
#define FLASHCTL_CMDTYPE_COMMAND_OFS             (0)                             /* !< COMMAND Offset */
#define FLASHCTL_CMDTYPE_COMMAND_MASK            ((uint32_t)0x00000007U)         /* !< Command type */
#define FLASHCTL_CMDTYPE_COMMAND_NOOP            ((uint32_t)0x00000000U)         /* !< No Operation */
#define FLASHCTL_CMDTYPE_COMMAND_PROGRAM         ((uint32_t)0x00000001U)         /* !< Program */
#define FLASHCTL_CMDTYPE_COMMAND_ERASE           ((uint32_t)0x00000002U)         /* !< Erase */
#define FLASHCTL_CMDTYPE_COMMAND_READVERIFY      ((uint32_t)0x00000003U)         /* !< ReadVerify - Perform a standalone
                                                                                    ReadVerify operation. */
#define FLASHCTL_CMDTYPE_COMMAND_MODECHANGE      ((uint32_t)0x00000004U)         /* !< Mode Change - Perform a mode change
                                                                                    only, no other operation. */
#define FLASHCTL_CMDTYPE_COMMAND_CLEARSTATUS     ((uint32_t)0x00000005U)         /* !< Clear Status - Clear status bits in
                                                                                    FW_SMSTAT only. */
#define FLASHCTL_CMDTYPE_COMMAND_BLANKVERIFY     ((uint32_t)0x00000006U)         /* !< Blank Verify - Check whether a
                                                                                    flash word is in the erased state.
                                                                                    This command may only be used with
                                                                                    CMDTYPE.SIZE = ONEWORD */
/* FLASHCTL_CMDTYPE[SIZE] Bits */
#define FLASHCTL_CMDTYPE_SIZE_OFS                (4)                             /* !< SIZE Offset */
#define FLASHCTL_CMDTYPE_SIZE_MASK               ((uint32_t)0x00000070U)         /* !< Command size */
#define FLASHCTL_CMDTYPE_SIZE_ONEWORD            ((uint32_t)0x00000000U)         /* !< Operate on 1 flash word */
#define FLASHCTL_CMDTYPE_SIZE_TWOWORD            ((uint32_t)0x00000010U)         /* !< Operate on 2 flash words */
#define FLASHCTL_CMDTYPE_SIZE_FOURWORD           ((uint32_t)0x00000020U)         /* !< Operate on 4 flash words */
#define FLASHCTL_CMDTYPE_SIZE_EIGHTWORD          ((uint32_t)0x00000030U)         /* !< Operate on 8 flash words */
#define FLASHCTL_CMDTYPE_SIZE_SECTOR             ((uint32_t)0x00000040U)         /* !< Operate on a flash sector */
#define FLASHCTL_CMDTYPE_SIZE_BANK               ((uint32_t)0x00000050U)         /* !< Operate on an entire flash bank */

/* FLASHCTL_CMDCTL Bits */
/* FLASHCTL_CMDCTL[MODESEL] Bits */
#define FLASHCTL_CMDCTL_MODESEL_OFS              (0)                             /* !< MODESEL Offset */
#define FLASHCTL_CMDCTL_MODESEL_MASK             ((uint32_t)0x0000000FU)         /* !< Mode This field is only used for
                                                                                    the Mode Change command type.
                                                                                    Otherwise, bank and pump modes are
                                                                                    set automaticlly through the NW
                                                                                    hardware. */
#define FLASHCTL_CMDCTL_MODESEL_READ             ((uint32_t)0x00000000U)         /* !< Read Mode */
#define FLASHCTL_CMDCTL_MODESEL_RDMARG0          ((uint32_t)0x00000002U)         /* !< Read Margin 0 Mode */
#define FLASHCTL_CMDCTL_MODESEL_RDMARG1          ((uint32_t)0x00000004U)         /* !< Read Margin 1 Mode */
#define FLASHCTL_CMDCTL_MODESEL_RDMARG0B         ((uint32_t)0x00000006U)         /* !< Read Margin 0B Mode */
#define FLASHCTL_CMDCTL_MODESEL_RDMARG1B         ((uint32_t)0x00000007U)         /* !< Read Margin 1B Mode */
#define FLASHCTL_CMDCTL_MODESEL_PGMVER           ((uint32_t)0x00000009U)         /* !< Program Verify Mode */
#define FLASHCTL_CMDCTL_MODESEL_PGMSW            ((uint32_t)0x0000000AU)         /* !< Program Single Word */
#define FLASHCTL_CMDCTL_MODESEL_ERASEVER         ((uint32_t)0x0000000BU)         /* !< Erase Verify Mode */
#define FLASHCTL_CMDCTL_MODESEL_ERASESECT        ((uint32_t)0x0000000CU)         /* !< Erase Sector */
#define FLASHCTL_CMDCTL_MODESEL_PGMMW            ((uint32_t)0x0000000EU)         /* !< Program Multiple Word */
#define FLASHCTL_CMDCTL_MODESEL_ERASEBNK         ((uint32_t)0x0000000FU)         /* !< Erase Bank */
/* FLASHCTL_CMDCTL[BANKSEL] Bits */
#define FLASHCTL_CMDCTL_BANKSEL_OFS              (4)                             /* !< BANKSEL Offset */
#define FLASHCTL_CMDCTL_BANKSEL_MASK             ((uint32_t)0x000001F0U)         /* !< Bank Select A specific Bank ID can
                                                                                    be written to this field to indicate
                                                                                    to which bank an  operation is to be
                                                                                    applied if CMDCTL.ADDRXLATEOVR is
                                                                                    set. */
#define FLASHCTL_CMDCTL_BANKSEL_BANK0            ((uint32_t)0x00000010U)         /* !< Bank 0 */
#define FLASHCTL_CMDCTL_BANKSEL_BANK1            ((uint32_t)0x00000020U)         /* !< Bank 1 */
#define FLASHCTL_CMDCTL_BANKSEL_BANK2            ((uint32_t)0x00000040U)         /* !< Bank 2 */
#define FLASHCTL_CMDCTL_BANKSEL_BANK3            ((uint32_t)0x00000080U)         /* !< Bank 3 */
#define FLASHCTL_CMDCTL_BANKSEL_BANK4            ((uint32_t)0x00000100U)         /* !< Bank 4 */
/* FLASHCTL_CMDCTL[REGIONSEL] Bits */
#define FLASHCTL_CMDCTL_REGIONSEL_OFS            (9)                             /* !< REGIONSEL Offset */
#define FLASHCTL_CMDCTL_REGIONSEL_MASK           ((uint32_t)0x00001E00U)         /* !< Bank Region A specific region ID
                                                                                    can be written to this field to
                                                                                    indicate to which region an
                                                                                    operation is to be applied if
                                                                                    CMDCTL.ADDRXLATEOVR is set. */
#define FLASHCTL_CMDCTL_REGIONSEL_MAIN           ((uint32_t)0x00000200U)         /* !< Main Region */
#define FLASHCTL_CMDCTL_REGIONSEL_NONMAIN        ((uint32_t)0x00000400U)         /* !< Non-Main Region */
#define FLASHCTL_CMDCTL_REGIONSEL_TRIM           ((uint32_t)0x00000800U)         /* !< Trim Region */
#define FLASHCTL_CMDCTL_REGIONSEL_ENGR           ((uint32_t)0x00001000U)         /* !< Engr Region */
/* FLASHCTL_CMDCTL[ECCGENOVR] Bits */
#define FLASHCTL_CMDCTL_ECCGENOVR_OFS            (17)                            /* !< ECCGENOVR Offset */
#define FLASHCTL_CMDCTL_ECCGENOVR_MASK           ((uint32_t)0x00020000U)         /* !< Override hardware generation of ECC
                                                                                    data for program.  Use data written
                                                                                    to  CMDDATAECC*. */
#define FLASHCTL_CMDCTL_ECCGENOVR_NOOVERRIDE     ((uint32_t)0x00000000U)         /* !< Do not override */
#define FLASHCTL_CMDCTL_ECCGENOVR_OVERRIDE       ((uint32_t)0x00020000U)         /* !< Override */
/* FLASHCTL_CMDCTL[ADDRXLATEOVR] Bits */
#define FLASHCTL_CMDCTL_ADDRXLATEOVR_OFS         (16)                            /* !< ADDRXLATEOVR Offset */
#define FLASHCTL_CMDCTL_ADDRXLATEOVR_MASK        ((uint32_t)0x00010000U)         /* !< Override hardware address
                                                                                    translation of address in CMDADDR
                                                                                    from a  system address to a bank
                                                                                    address and bank ID.  Use data
                                                                                    written to  CMDADDR directly as the
                                                                                    bank address.  Use the value written
                                                                                    to  CMDCTL.BANKSEL directly as the
                                                                                    bank ID.  Use the value written to
                                                                                    CMDCTL.REGIONSEL directly as the
                                                                                    region ID. */
#define FLASHCTL_CMDCTL_ADDRXLATEOVR_NOOVERRIDE  ((uint32_t)0x00000000U)         /* !< Do not override */
#define FLASHCTL_CMDCTL_ADDRXLATEOVR_OVERRIDE    ((uint32_t)0x00010000U)         /* !< Override */
/* FLASHCTL_CMDCTL[SSERASEDIS] Bits */
#define FLASHCTL_CMDCTL_SSERASEDIS_OFS           (20)                            /* !< SSERASEDIS Offset */
#define FLASHCTL_CMDCTL_SSERASEDIS_MASK          ((uint32_t)0x00100000U)         /* !< Disable Stair-Step Erase.  If set,
                                                                                    the default VHV trim voltage setting
                                                                                    will be used for all erase pulses. By
                                                                                    default, this bit is reset, meaning
                                                                                    that the VHV voltage will be stepped
                                                                                    during successive erase pulses.  The
                                                                                    step count, step voltage, begin and
                                                                                    end voltages are all hard-wired. */
#define FLASHCTL_CMDCTL_SSERASEDIS_ENABLE        ((uint32_t)0x00000000U)         /* !< Enable */
#define FLASHCTL_CMDCTL_SSERASEDIS_DISABLE       ((uint32_t)0x00100000U)         /* !< Disable */
/* FLASHCTL_CMDCTL[DATAVEREN] Bits */
#define FLASHCTL_CMDCTL_DATAVEREN_OFS            (21)                            /* !< DATAVEREN Offset */
#define FLASHCTL_CMDCTL_DATAVEREN_MASK           ((uint32_t)0x00200000U)         /* !< Enable invalid data verify.   This
                                                                                    checks for 0->1 transitions in the
                                                                                    memory when a program operation is
                                                                                    initiated.  If such a transition is
                                                                                    found, the program will fail with an
                                                                                    error without executing the program. */
#define FLASHCTL_CMDCTL_DATAVEREN_DISABLE        ((uint32_t)0x00000000U)         /* !< Disable */
#define FLASHCTL_CMDCTL_DATAVEREN_ENABLE         ((uint32_t)0x00200000U)         /* !< Enable */

/* FLASHCTL_CMDADDR Bits */
/* FLASHCTL_CMDADDR[VAL] Bits */
#define FLASHCTL_CMDADDR_VAL_OFS                 (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDADDR_VAL_MASK                ((uint32_t)0xFFFFFFFFU)         /* !< Address value */
#define FLASHCTL_CMDADDR_VAL_MINIMUM             ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDADDR_VAL_MAXIMUM             ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDBYTEN Bits */
/* FLASHCTL_CMDBYTEN[VAL] Bits */
#define FLASHCTL_CMDBYTEN_VAL_OFS                (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDBYTEN_VAL_MASK               ((uint32_t)0x0003FFFFU)         /* !< Command Byte Enable value. A 1-bit
                                                                                    per flash word byte value is placed
                                                                                    in this register. */
#define FLASHCTL_CMDBYTEN_VAL_MINIMUM            ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDBYTEN_VAL_MAXIMUM            ((uint32_t)0x0003FFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATAINDEX Bits */
/* FLASHCTL_CMDDATAINDEX[VAL] Bits */
#define FLASHCTL_CMDDATAINDEX_VAL_OFS            (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATAINDEX_VAL_MASK           ((uint32_t)0x00000007U)         /* !< Data register index */
#define FLASHCTL_CMDDATAINDEX_VAL_MINIMUM        ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATAINDEX_VAL_MAXIMUM        ((uint32_t)0x00000007U)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA0 Bits */
/* FLASHCTL_CMDDATA0[VAL] Bits */
#define FLASHCTL_CMDDATA0_VAL_OFS                (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA0_VAL_MASK               ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA0_VAL_MINIMUM            ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA0_VAL_MAXIMUM            ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA1 Bits */
/* FLASHCTL_CMDDATA1[VAL] Bits */
#define FLASHCTL_CMDDATA1_VAL_OFS                (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA1_VAL_MASK               ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA1_VAL_MINIMUM            ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA1_VAL_MAXIMUM            ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA2 Bits */
/* FLASHCTL_CMDDATA2[VAL] Bits */
#define FLASHCTL_CMDDATA2_VAL_OFS                (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA2_VAL_MASK               ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA2_VAL_MINIMUM            ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA2_VAL_MAXIMUM            ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA3 Bits */
/* FLASHCTL_CMDDATA3[VAL] Bits */
#define FLASHCTL_CMDDATA3_VAL_OFS                (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA3_VAL_MASK               ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA3_VAL_MINIMUM            ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA3_VAL_MAXIMUM            ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA4 Bits */
/* FLASHCTL_CMDDATA4[VAL] Bits */
#define FLASHCTL_CMDDATA4_VAL_OFS                (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA4_VAL_MASK               ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. T */
#define FLASHCTL_CMDDATA4_VAL_MINIMUM            ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA4_VAL_MAXIMUM            ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA5 Bits */
/* FLASHCTL_CMDDATA5[VAL] Bits */
#define FLASHCTL_CMDDATA5_VAL_OFS                (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA5_VAL_MASK               ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA5_VAL_MINIMUM            ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA5_VAL_MAXIMUM            ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA6 Bits */
/* FLASHCTL_CMDDATA6[VAL] Bits */
#define FLASHCTL_CMDDATA6_VAL_OFS                (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA6_VAL_MASK               ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA6_VAL_MINIMUM            ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA6_VAL_MAXIMUM            ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA7 Bits */
/* FLASHCTL_CMDDATA7[VAL] Bits */
#define FLASHCTL_CMDDATA7_VAL_OFS                (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA7_VAL_MASK               ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA7_VAL_MINIMUM            ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA7_VAL_MAXIMUM            ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA8 Bits */
/* FLASHCTL_CMDDATA8[VAL] Bits */
#define FLASHCTL_CMDDATA8_VAL_OFS                (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA8_VAL_MASK               ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA8_VAL_MINIMUM            ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA8_VAL_MAXIMUM            ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA9 Bits */
/* FLASHCTL_CMDDATA9[VAL] Bits */
#define FLASHCTL_CMDDATA9_VAL_OFS                (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA9_VAL_MASK               ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA9_VAL_MINIMUM            ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA9_VAL_MAXIMUM            ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA10 Bits */
/* FLASHCTL_CMDDATA10[VAL] Bits */
#define FLASHCTL_CMDDATA10_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA10_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA10_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA10_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA11 Bits */
/* FLASHCTL_CMDDATA11[VAL] Bits */
#define FLASHCTL_CMDDATA11_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA11_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA11_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA11_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA12 Bits */
/* FLASHCTL_CMDDATA12[VAL] Bits */
#define FLASHCTL_CMDDATA12_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA12_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA12_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA12_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA13 Bits */
/* FLASHCTL_CMDDATA13[VAL] Bits */
#define FLASHCTL_CMDDATA13_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA13_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA13_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA13_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA14 Bits */
/* FLASHCTL_CMDDATA14[VAL] Bits */
#define FLASHCTL_CMDDATA14_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA14_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA14_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA14_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA15 Bits */
/* FLASHCTL_CMDDATA15[VAL] Bits */
#define FLASHCTL_CMDDATA15_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA15_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA15_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA15_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA16 Bits */
/* FLASHCTL_CMDDATA16[VAL] Bits */
#define FLASHCTL_CMDDATA16_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA16_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA16_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA16_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA17 Bits */
/* FLASHCTL_CMDDATA17[VAL] Bits */
#define FLASHCTL_CMDDATA17_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA17_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA17_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA17_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA18 Bits */
/* FLASHCTL_CMDDATA18[VAL] Bits */
#define FLASHCTL_CMDDATA18_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA18_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA18_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA18_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA19 Bits */
/* FLASHCTL_CMDDATA19[VAL] Bits */
#define FLASHCTL_CMDDATA19_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA19_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA19_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA19_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA20 Bits */
/* FLASHCTL_CMDDATA20[VAL] Bits */
#define FLASHCTL_CMDDATA20_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA20_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA20_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA20_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA21 Bits */
/* FLASHCTL_CMDDATA21[VAL] Bits */
#define FLASHCTL_CMDDATA21_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA21_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA21_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA21_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA22 Bits */
/* FLASHCTL_CMDDATA22[VAL] Bits */
#define FLASHCTL_CMDDATA22_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA22_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA22_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA22_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA23 Bits */
/* FLASHCTL_CMDDATA23[VAL] Bits */
#define FLASHCTL_CMDDATA23_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA23_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA23_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA23_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA24 Bits */
/* FLASHCTL_CMDDATA24[VAL] Bits */
#define FLASHCTL_CMDDATA24_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA24_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA24_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA24_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA25 Bits */
/* FLASHCTL_CMDDATA25[VAL] Bits */
#define FLASHCTL_CMDDATA25_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA25_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA25_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA25_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA26 Bits */
/* FLASHCTL_CMDDATA26[VAL] Bits */
#define FLASHCTL_CMDDATA26_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA26_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA26_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA26_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA27 Bits */
/* FLASHCTL_CMDDATA27[VAL] Bits */
#define FLASHCTL_CMDDATA27_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA27_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA27_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA27_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA28 Bits */
/* FLASHCTL_CMDDATA28[VAL] Bits */
#define FLASHCTL_CMDDATA28_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA28_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA28_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA28_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA29 Bits */
/* FLASHCTL_CMDDATA29[VAL] Bits */
#define FLASHCTL_CMDDATA29_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA29_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA29_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA29_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA30 Bits */
/* FLASHCTL_CMDDATA30[VAL] Bits */
#define FLASHCTL_CMDDATA30_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA30_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA30_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA30_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATA31 Bits */
/* FLASHCTL_CMDDATA31[VAL] Bits */
#define FLASHCTL_CMDDATA31_VAL_OFS               (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDDATA31_VAL_MASK              ((uint32_t)0xFFFFFFFFU)         /* !< A 32-bit data value is placed in
                                                                                    this field. */
#define FLASHCTL_CMDDATA31_VAL_MINIMUM           ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDDATA31_VAL_MAXIMUM           ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDDATAECC0 Bits */
/* FLASHCTL_CMDDATAECC0[VAL0] Bits */
#define FLASHCTL_CMDDATAECC0_VAL0_OFS            (0)                             /* !< VAL0 Offset */
#define FLASHCTL_CMDDATAECC0_VAL0_MASK           ((uint32_t)0x000000FFU)         /* !< ECC data for bits 63:0 of the data
                                                                                    is placed here. */
#define FLASHCTL_CMDDATAECC0_VAL0_MINIMUM        ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_CMDDATAECC0_VAL0_MAXIMUM        ((uint32_t)0x000000FFU)         /* !< Maximum value */
/* FLASHCTL_CMDDATAECC0[VAL1] Bits */
#define FLASHCTL_CMDDATAECC0_VAL1_OFS            (8)                             /* !< VAL1 Offset */
#define FLASHCTL_CMDDATAECC0_VAL1_MASK           ((uint32_t)0x0000FF00U)         /* !< ECC data for bits 127:64 of the
                                                                                    data is placed here. */
#define FLASHCTL_CMDDATAECC0_VAL1_MINIMUM        ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_CMDDATAECC0_VAL1_MAXIMUM        ((uint32_t)0x0000FF00U)         /* !< Maximum value */

/* FLASHCTL_CMDDATAECC1 Bits */
/* FLASHCTL_CMDDATAECC1[VAL0] Bits */
#define FLASHCTL_CMDDATAECC1_VAL0_OFS            (0)                             /* !< VAL0 Offset */
#define FLASHCTL_CMDDATAECC1_VAL0_MASK           ((uint32_t)0x000000FFU)         /* !< ECC data for bits 63:0 of the data
                                                                                    is placed here. */
#define FLASHCTL_CMDDATAECC1_VAL0_MINIMUM        ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_CMDDATAECC1_VAL0_MAXIMUM        ((uint32_t)0x000000FFU)         /* !< Maximum value */
/* FLASHCTL_CMDDATAECC1[VAL1] Bits */
#define FLASHCTL_CMDDATAECC1_VAL1_OFS            (8)                             /* !< VAL1 Offset */
#define FLASHCTL_CMDDATAECC1_VAL1_MASK           ((uint32_t)0x0000FF00U)         /* !< ECC data for bits 127:64 of the
                                                                                    data is placed here. */
#define FLASHCTL_CMDDATAECC1_VAL1_MINIMUM        ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_CMDDATAECC1_VAL1_MAXIMUM        ((uint32_t)0x0000FF00U)         /* !< Maximum value */

/* FLASHCTL_CMDDATAECC2 Bits */
/* FLASHCTL_CMDDATAECC2[VAL0] Bits */
#define FLASHCTL_CMDDATAECC2_VAL0_OFS            (0)                             /* !< VAL0 Offset */
#define FLASHCTL_CMDDATAECC2_VAL0_MASK           ((uint32_t)0x000000FFU)         /* !< ECC data for bits 63:0 of the data
                                                                                    is placed here. */
#define FLASHCTL_CMDDATAECC2_VAL0_MINIMUM        ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_CMDDATAECC2_VAL0_MAXIMUM        ((uint32_t)0x000000FFU)         /* !< Maximum value */
/* FLASHCTL_CMDDATAECC2[VAL1] Bits */
#define FLASHCTL_CMDDATAECC2_VAL1_OFS            (8)                             /* !< VAL1 Offset */
#define FLASHCTL_CMDDATAECC2_VAL1_MASK           ((uint32_t)0x0000FF00U)         /* !< ECC data for bits 127:64 of the
                                                                                    data is placed here. */
#define FLASHCTL_CMDDATAECC2_VAL1_MINIMUM        ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_CMDDATAECC2_VAL1_MAXIMUM        ((uint32_t)0x0000FF00U)         /* !< Maximum value */

/* FLASHCTL_CMDDATAECC3 Bits */
/* FLASHCTL_CMDDATAECC3[VAL0] Bits */
#define FLASHCTL_CMDDATAECC3_VAL0_OFS            (0)                             /* !< VAL0 Offset */
#define FLASHCTL_CMDDATAECC3_VAL0_MASK           ((uint32_t)0x000000FFU)         /* !< ECC data for bits 63:0 of the data
                                                                                    is placed here. */
#define FLASHCTL_CMDDATAECC3_VAL0_MINIMUM        ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_CMDDATAECC3_VAL0_MAXIMUM        ((uint32_t)0x000000FFU)         /* !< Maximum value */
/* FLASHCTL_CMDDATAECC3[VAL1] Bits */
#define FLASHCTL_CMDDATAECC3_VAL1_OFS            (8)                             /* !< VAL1 Offset */
#define FLASHCTL_CMDDATAECC3_VAL1_MASK           ((uint32_t)0x0000FF00U)         /* !< ECC data for bits 127:64 of the
                                                                                    data is placed here. */
#define FLASHCTL_CMDDATAECC3_VAL1_MINIMUM        ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_CMDDATAECC3_VAL1_MAXIMUM        ((uint32_t)0x0000FF00U)         /* !< Maximum value */

/* FLASHCTL_CMDDATAECC4 Bits */
/* FLASHCTL_CMDDATAECC4[VAL0] Bits */
#define FLASHCTL_CMDDATAECC4_VAL0_OFS            (0)                             /* !< VAL0 Offset */
#define FLASHCTL_CMDDATAECC4_VAL0_MASK           ((uint32_t)0x000000FFU)         /* !< ECC data for bits 63:0 of the data
                                                                                    is placed here. */
#define FLASHCTL_CMDDATAECC4_VAL0_MINIMUM        ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_CMDDATAECC4_VAL0_MAXIMUM        ((uint32_t)0x000000FFU)         /* !< Maximum value */
/* FLASHCTL_CMDDATAECC4[VAL1] Bits */
#define FLASHCTL_CMDDATAECC4_VAL1_OFS            (8)                             /* !< VAL1 Offset */
#define FLASHCTL_CMDDATAECC4_VAL1_MASK           ((uint32_t)0x0000FF00U)         /* !< ECC data for bits 127:64 of the
                                                                                    data is placed here. */
#define FLASHCTL_CMDDATAECC4_VAL1_MINIMUM        ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_CMDDATAECC4_VAL1_MAXIMUM        ((uint32_t)0x0000FF00U)         /* !< Maximum value */

/* FLASHCTL_CMDDATAECC5 Bits */
/* FLASHCTL_CMDDATAECC5[VAL0] Bits */
#define FLASHCTL_CMDDATAECC5_VAL0_OFS            (0)                             /* !< VAL0 Offset */
#define FLASHCTL_CMDDATAECC5_VAL0_MASK           ((uint32_t)0x000000FFU)         /* !< ECC data for bits 63:0 of the data
                                                                                    is placed here. */
#define FLASHCTL_CMDDATAECC5_VAL0_MINIMUM        ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_CMDDATAECC5_VAL0_MAXIMUM        ((uint32_t)0x000000FFU)         /* !< Maximum value */
/* FLASHCTL_CMDDATAECC5[VAL1] Bits */
#define FLASHCTL_CMDDATAECC5_VAL1_OFS            (8)                             /* !< VAL1 Offset */
#define FLASHCTL_CMDDATAECC5_VAL1_MASK           ((uint32_t)0x0000FF00U)         /* !< ECC data for bits 127:64 of the
                                                                                    data is placed here. */
#define FLASHCTL_CMDDATAECC5_VAL1_MINIMUM        ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_CMDDATAECC5_VAL1_MAXIMUM        ((uint32_t)0x0000FF00U)         /* !< Maximum value */

/* FLASHCTL_CMDDATAECC6 Bits */
/* FLASHCTL_CMDDATAECC6[VAL0] Bits */
#define FLASHCTL_CMDDATAECC6_VAL0_OFS            (0)                             /* !< VAL0 Offset */
#define FLASHCTL_CMDDATAECC6_VAL0_MASK           ((uint32_t)0x000000FFU)         /* !< ECC data for bits 63:0 of the data
                                                                                    is placed here. */
#define FLASHCTL_CMDDATAECC6_VAL0_MINIMUM        ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_CMDDATAECC6_VAL0_MAXIMUM        ((uint32_t)0x000000FFU)         /* !< Maximum value */
/* FLASHCTL_CMDDATAECC6[VAL1] Bits */
#define FLASHCTL_CMDDATAECC6_VAL1_OFS            (8)                             /* !< VAL1 Offset */
#define FLASHCTL_CMDDATAECC6_VAL1_MASK           ((uint32_t)0x0000FF00U)         /* !< ECC data for bits 127:64 of the
                                                                                    data is placed here. */
#define FLASHCTL_CMDDATAECC6_VAL1_MINIMUM        ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_CMDDATAECC6_VAL1_MAXIMUM        ((uint32_t)0x0000FF00U)         /* !< Maximum value */

/* FLASHCTL_CMDDATAECC7 Bits */
/* FLASHCTL_CMDDATAECC7[VAL0] Bits */
#define FLASHCTL_CMDDATAECC7_VAL0_OFS            (0)                             /* !< VAL0 Offset */
#define FLASHCTL_CMDDATAECC7_VAL0_MASK           ((uint32_t)0x000000FFU)         /* !< ECC data for bits 63:0 of the data
                                                                                    is placed here. */
#define FLASHCTL_CMDDATAECC7_VAL0_MINIMUM        ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_CMDDATAECC7_VAL0_MAXIMUM        ((uint32_t)0x000000FFU)         /* !< Maximum value */
/* FLASHCTL_CMDDATAECC7[VAL1] Bits */
#define FLASHCTL_CMDDATAECC7_VAL1_OFS            (8)                             /* !< VAL1 Offset */
#define FLASHCTL_CMDDATAECC7_VAL1_MASK           ((uint32_t)0x0000FF00U)         /* !< ECC data for bits 127:64 of the
                                                                                    data is placed here. */
#define FLASHCTL_CMDDATAECC7_VAL1_MINIMUM        ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_CMDDATAECC7_VAL1_MAXIMUM        ((uint32_t)0x0000FF00U)         /* !< Maximum value */

/* FLASHCTL_CMDWEPROTA Bits */
/* FLASHCTL_CMDWEPROTA[VAL] Bits */
#define FLASHCTL_CMDWEPROTA_VAL_OFS              (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDWEPROTA_VAL_MASK             ((uint32_t)0xFFFFFFFFU)         /* !< Each bit protects 1 sector.  bit
                                                                                    [0]:	When 1, sector 0 of the flash
                                                                                    memory will be protected from program
                                                                                    and erase. bit [1]:	When 1, sector
                                                                                    1 of the flash memory will be
                                                                                    protected from program 		and erase.
                                                                                    : 	: bit [31]:	When 1, sector 31 of
                                                                                    the flash memory will be protected
                                                                                    from program 		and erase. */
#define FLASHCTL_CMDWEPROTA_VAL_MINIMUM          ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDWEPROTA_VAL_MAXIMUM          ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDWEPROTB Bits */
/* FLASHCTL_CMDWEPROTB[VAL] Bits */
#define FLASHCTL_CMDWEPROTB_VAL_OFS              (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDWEPROTB_VAL_MASK             ((uint32_t)0xFFFFFFFFU)         /* !< Each bit protects a group of 8
                                                                                    sectors.  When a bit is 1, the
                                                                                    associated 8 sectors in the flash
                                                                                    will be protected from program and
                                                                                    erase.  A maximum of 256 sectors can
                                                                                    be protected with this register. */
#define FLASHCTL_CMDWEPROTB_VAL_MINIMUM          ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDWEPROTB_VAL_MAXIMUM          ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDWEPROTC Bits */
/* FLASHCTL_CMDWEPROTC[VAL] Bits */
#define FLASHCTL_CMDWEPROTC_VAL_OFS              (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDWEPROTC_VAL_MASK             ((uint32_t)0xFFFFFFFFU)         /* !< Each bit protects a group of 8
                                                                                    sectors.  When a bit is 1, the
                                                                                    associated 8 sectors in the flash
                                                                                    will be protected from program and
                                                                                    erase.  Note that the sectors
                                                                                    protected with this register start at
                                                                                    sector 256 in the flash, where the
                                                                                    sectors protected by the CMDWEPROTB
                                                                                    register end. */
#define FLASHCTL_CMDWEPROTC_VAL_MINIMUM          ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDWEPROTC_VAL_MAXIMUM          ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDWEPROTNM Bits */
/* FLASHCTL_CMDWEPROTNM[VAL] Bits */
#define FLASHCTL_CMDWEPROTNM_VAL_OFS             (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDWEPROTNM_VAL_MASK            ((uint32_t)0xFFFFFFFFU)         /* !< Each bit protects 1 sector.  bit
                                                                                    [0]:	When 1, sector 0 of the non-main
                                                                                    region will be protected from program
                                                                                    and erase. bit [1]:	When 1, sector
                                                                                    1 of the non-main region will be
                                                                                    protected from program 		and erase.
                                                                                    : 	: bit [31]:	When 1, sector 31 of
                                                                                    the non-main will be protected from
                                                                                    program 		and erase. */
#define FLASHCTL_CMDWEPROTNM_VAL_MINIMUM         ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDWEPROTNM_VAL_MAXIMUM         ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDWEPROTTR Bits */
/* FLASHCTL_CMDWEPROTTR[VAL] Bits */
#define FLASHCTL_CMDWEPROTTR_VAL_OFS             (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDWEPROTTR_VAL_MASK            ((uint32_t)0xFFFFFFFFU)         /* !< Each bit protects 1 sector.  bit
                                                                                    [0]:	When 1, sector 0 of the engr
                                                                                    region will be protected from program
                                                                                    and erase. bit [1]:	When 1, sector
                                                                                    1 of the engr region will be
                                                                                    protected from program 		and erase.
                                                                                    : 	: bit [31]:	When 1, sector 31 of
                                                                                    the engr region will be protected
                                                                                    from program 		and erase. */
#define FLASHCTL_CMDWEPROTTR_VAL_MINIMUM         ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDWEPROTTR_VAL_MAXIMUM         ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CMDWEPROTEN Bits */
/* FLASHCTL_CMDWEPROTEN[VAL] Bits */
#define FLASHCTL_CMDWEPROTEN_VAL_OFS             (0)                             /* !< VAL Offset */
#define FLASHCTL_CMDWEPROTEN_VAL_MASK            ((uint32_t)0xFFFFFFFFU)         /* !< Each bit protects 1 sector.  bit
                                                                                    [0]:	When 1, sector 0 of the engr
                                                                                    region will be protected from program
                                                                                    and erase. bit [1]:	When 1, sector
                                                                                    1 of the engr region will be
                                                                                    protected from program 		and erase.
                                                                                    : 	: bit [31]:	When 1, sector 31 of
                                                                                    the engr region will be protected
                                                                                    from program 		and erase. */
#define FLASHCTL_CMDWEPROTEN_VAL_MINIMUM         ((uint32_t)0x00000000U)         /* !< Minimum value of [VAL] */
#define FLASHCTL_CMDWEPROTEN_VAL_MAXIMUM         ((uint32_t)0xFFFFFFFFU)         /* !< Maximum value of [VAL] */

/* FLASHCTL_CFGCMD Bits */
/* FLASHCTL_CFGCMD[WAITSTATE] Bits */
#define FLASHCTL_CFGCMD_WAITSTATE_OFS            (0)                             /* !< WAITSTATE Offset */
#define FLASHCTL_CFGCMD_WAITSTATE_MASK           ((uint32_t)0x0000000FU)         /* !< Wait State setting for verify reads */
#define FLASHCTL_CFGCMD_WAITSTATE_MINIMUM        ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_CFGCMD_WAITSTATE_MAXIMUM        ((uint32_t)0x0000000FU)         /* !< Maximum value */

/* FLASHCTL_CFGPCNT Bits */
/* FLASHCTL_CFGPCNT[MAXPCNTOVR] Bits */
#define FLASHCTL_CFGPCNT_MAXPCNTOVR_OFS          (0)                             /* !< MAXPCNTOVR Offset */
#define FLASHCTL_CFGPCNT_MAXPCNTOVR_MASK         ((uint32_t)0x00000001U)         /* !< Override hard-wired maximum pulse
                                                                                    count.  If MAXERSPCNTOVR is not set,
                                                                                    then setting this value alone will
                                                                                    override the max pulse count for both
                                                                                    program and erase.  If MAXERSPCNTOVR
                                                                                    is set, then this bit will only
                                                                                    control the max pulse count setting
                                                                                    for program. By default, this bit is
                                                                                    0, and a hard-wired max pulse count
                                                                                    is used. */
#define FLASHCTL_CFGPCNT_MAXPCNTOVR_DEFAULT      ((uint32_t)0x00000000U)         /* !< Use hard-wired (default) value for
                                                                                    maximum pulse count */
#define FLASHCTL_CFGPCNT_MAXPCNTOVR_OVERRIDE     ((uint32_t)0x00000001U)         /* !< Use value from MAXPCNTVAL field as
                                                                                    maximum puse count */
/* FLASHCTL_CFGPCNT[MAXPCNTVAL] Bits */
#define FLASHCTL_CFGPCNT_MAXPCNTVAL_OFS          (4)                             /* !< MAXPCNTVAL Offset */
#define FLASHCTL_CFGPCNT_MAXPCNTVAL_MASK         ((uint32_t)0x00000FF0U)         /* !< Override maximum pulse counter with
                                                                                    this value.   If MAXPCNTOVR = 0, then
                                                                                    this field is ignored. If MAXPCNTOVR
                                                                                    = 1 and MAXERSPCNTOVR = 0, then this
                                                                                    value will be used  to override the
                                                                                    max pulse count for both program and
                                                                                    erase.  Full max value will be {4'h0,
                                                                                    MAXPCNTVAL} . If MAXPCNTOVR = 1 and
                                                                                    MAXERSPCNTOVR = 1, then this value
                                                                                    will be used to override the max
                                                                                    pulse count for program only.  Full
                                                                                    max value will be {4'h0, MAXPCNTVAL}. */
#define FLASHCTL_CFGPCNT_MAXPCNTVAL_MINIMUM      ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_CFGPCNT_MAXPCNTVAL_MAXIMUM      ((uint32_t)0x00000FF0U)         /* !< Maximum value */

/* FLASHCTL_STATCMD Bits */
/* FLASHCTL_STATCMD[CMDDONE] Bits */
#define FLASHCTL_STATCMD_CMDDONE_OFS             (0)                             /* !< CMDDONE Offset */
#define FLASHCTL_STATCMD_CMDDONE_MASK            ((uint32_t)0x00000001U)         /* !< Command Done */
#define FLASHCTL_STATCMD_CMDDONE_STATNOTDONE     ((uint32_t)0x00000000U)         /* !< Not Done */
#define FLASHCTL_STATCMD_CMDDONE_STATDONE        ((uint32_t)0x00000001U)         /* !< Done */
/* FLASHCTL_STATCMD[CMDPASS] Bits */
#define FLASHCTL_STATCMD_CMDPASS_OFS             (1)                             /* !< CMDPASS Offset */
#define FLASHCTL_STATCMD_CMDPASS_MASK            ((uint32_t)0x00000002U)         /* !< Command Pass - valid when CMD_DONE
                                                                                    field is 1 */
#define FLASHCTL_STATCMD_CMDPASS_STATFAIL        ((uint32_t)0x00000000U)         /* !< Fail */
#define FLASHCTL_STATCMD_CMDPASS_STATPASS        ((uint32_t)0x00000002U)         /* !< Pass */
/* FLASHCTL_STATCMD[CMDINPROGRESS] Bits */
#define FLASHCTL_STATCMD_CMDINPROGRESS_OFS       (2)                             /* !< CMDINPROGRESS Offset */
#define FLASHCTL_STATCMD_CMDINPROGRESS_MASK      ((uint32_t)0x00000004U)         /* !< Command In Progress */
#define FLASHCTL_STATCMD_CMDINPROGRESS_STATCOMPLETE ((uint32_t)0x00000000U)         /* !< Complete */
#define FLASHCTL_STATCMD_CMDINPROGRESS_STATINPROGRESS ((uint32_t)0x00000004U)         /* !< In Progress */
/* FLASHCTL_STATCMD[FAILWEPROT] Bits */
#define FLASHCTL_STATCMD_FAILWEPROT_OFS          (4)                             /* !< FAILWEPROT Offset */
#define FLASHCTL_STATCMD_FAILWEPROT_MASK         ((uint32_t)0x00000010U)         /* !< Command failed due to Write/Erase
                                                                                    Protect Sector Violation */
#define FLASHCTL_STATCMD_FAILWEPROT_STATNOFAIL   ((uint32_t)0x00000000U)         /* !< No Fail */
#define FLASHCTL_STATCMD_FAILWEPROT_STATFAIL     ((uint32_t)0x00000010U)         /* !< Fail */
/* FLASHCTL_STATCMD[FAILVERIFY] Bits */
#define FLASHCTL_STATCMD_FAILVERIFY_OFS          (5)                             /* !< FAILVERIFY Offset */
#define FLASHCTL_STATCMD_FAILVERIFY_MASK         ((uint32_t)0x00000020U)         /* !< Command failed due to verify error */
#define FLASHCTL_STATCMD_FAILVERIFY_STATNOFAIL   ((uint32_t)0x00000000U)         /* !< No Fail */
#define FLASHCTL_STATCMD_FAILVERIFY_STATFAIL     ((uint32_t)0x00000020U)         /* !< Fail */
/* FLASHCTL_STATCMD[FAILMISC] Bits */
#define FLASHCTL_STATCMD_FAILMISC_OFS            (12)                            /* !< FAILMISC Offset */
#define FLASHCTL_STATCMD_FAILMISC_MASK           ((uint32_t)0x00001000U)         /* !< Command failed due to error other
                                                                                    than write/erase protect violation or
                                                                                    verify error.  This is an extra bit
                                                                                    in case a new failure mechanism is
                                                                                    added which requires a status bit. */
#define FLASHCTL_STATCMD_FAILMISC_STATNOFAIL     ((uint32_t)0x00000000U)         /* !< No Fail */
#define FLASHCTL_STATCMD_FAILMISC_STATFAIL       ((uint32_t)0x00001000U)         /* !< Fail */
/* FLASHCTL_STATCMD[FAILILLADDR] Bits */
#define FLASHCTL_STATCMD_FAILILLADDR_OFS         (6)                             /* !< FAILILLADDR Offset */
#define FLASHCTL_STATCMD_FAILILLADDR_MASK        ((uint32_t)0x00000040U)         /* !< Command failed due to the use of an
                                                                                    illegal address */
#define FLASHCTL_STATCMD_FAILILLADDR_STATNOFAIL  ((uint32_t)0x00000000U)         /* !< No Fail */
#define FLASHCTL_STATCMD_FAILILLADDR_STATFAIL    ((uint32_t)0x00000040U)         /* !< Fail */
/* FLASHCTL_STATCMD[FAILMODE] Bits */
#define FLASHCTL_STATCMD_FAILMODE_OFS            (7)                             /* !< FAILMODE Offset */
#define FLASHCTL_STATCMD_FAILMODE_MASK           ((uint32_t)0x00000080U)         /* !< Command failed because a bank has
                                                                                    been set to a mode other than READ.
                                                                                    Program and Erase commands cannot be
                                                                                    initiated unless all banks are in
                                                                                    READ mode. */
#define FLASHCTL_STATCMD_FAILMODE_STATNOFAIL     ((uint32_t)0x00000000U)         /* !< No Fail */
#define FLASHCTL_STATCMD_FAILMODE_STATFAIL       ((uint32_t)0x00000080U)         /* !< Fail */
/* FLASHCTL_STATCMD[FAILINVDATA] Bits */
#define FLASHCTL_STATCMD_FAILINVDATA_OFS         (8)                             /* !< FAILINVDATA Offset */
#define FLASHCTL_STATCMD_FAILINVDATA_MASK        ((uint32_t)0x00000100U)         /* !< Program command failed because an
                                                                                    attempt was made to program a stored
                                                                                    0 value to a 1. */
#define FLASHCTL_STATCMD_FAILINVDATA_STATNOFAIL  ((uint32_t)0x00000000U)         /* !< No Fail */
#define FLASHCTL_STATCMD_FAILINVDATA_STATFAIL    ((uint32_t)0x00000100U)         /* !< Fail */

/* FLASHCTL_STATADDR Bits */
/* FLASHCTL_STATADDR[BANKADDR] Bits */
#define FLASHCTL_STATADDR_BANKADDR_OFS           (0)                             /* !< BANKADDR Offset */
#define FLASHCTL_STATADDR_BANKADDR_MASK          ((uint32_t)0x0000FFFFU)         /* !< Current Bank Address A bank offset
                                                                                    address is stored in this register. */
#define FLASHCTL_STATADDR_BANKADDR_MINIMUM       ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_STATADDR_BANKADDR_MAXIMUM       ((uint32_t)0x0000FFFFU)         /* !< Maximum value */
/* FLASHCTL_STATADDR[BANKID] Bits */
#define FLASHCTL_STATADDR_BANKID_OFS             (21)                            /* !< BANKID Offset */
#define FLASHCTL_STATADDR_BANKID_MASK            ((uint32_t)0x03E00000U)         /* !< Current Bank ID A bank indicator is
                                                                                    stored in this register which
                                                                                    represents the current bank on which
                                                                                    the state  machine is operating.
                                                                                    There is 1 bit per bank. */
#define FLASHCTL_STATADDR_BANKID_BANK0           ((uint32_t)0x00200000U)         /* !< Bank 0 */
#define FLASHCTL_STATADDR_BANKID_BANK1           ((uint32_t)0x00400000U)         /* !< Bank 1 */
#define FLASHCTL_STATADDR_BANKID_BANK2           ((uint32_t)0x00800000U)         /* !< Bank 2 */
#define FLASHCTL_STATADDR_BANKID_BANK3           ((uint32_t)0x01000000U)         /* !< Bank 3 */
#define FLASHCTL_STATADDR_BANKID_BANK4           ((uint32_t)0x02000000U)         /* !< Bank 4 */
/* FLASHCTL_STATADDR[REGIONID] Bits */
#define FLASHCTL_STATADDR_REGIONID_OFS           (16)                            /* !< REGIONID Offset */
#define FLASHCTL_STATADDR_REGIONID_MASK          ((uint32_t)0x001F0000U)         /* !< Current Region ID A region
                                                                                    indicator is stored in this register
                                                                                    which represents the current flash
                                                                                    region on which the state  machine is
                                                                                    operating. */
#define FLASHCTL_STATADDR_REGIONID_MAIN          ((uint32_t)0x00010000U)         /* !< Main Region */
#define FLASHCTL_STATADDR_REGIONID_NONMAIN       ((uint32_t)0x00020000U)         /* !< Non-Main Region */
#define FLASHCTL_STATADDR_REGIONID_TRIM          ((uint32_t)0x00040000U)         /* !< Trim Region */
#define FLASHCTL_STATADDR_REGIONID_ENGR          ((uint32_t)0x00080000U)         /* !< Engr Region */

/* FLASHCTL_STATPCNT Bits */
/* FLASHCTL_STATPCNT[PULSECNT] Bits */
#define FLASHCTL_STATPCNT_PULSECNT_OFS           (0)                             /* !< PULSECNT Offset */
#define FLASHCTL_STATPCNT_PULSECNT_MASK          ((uint32_t)0x00000FFFU)         /* !< Current Pulse Counter Value */
#define FLASHCTL_STATPCNT_PULSECNT_MINIMUM       ((uint32_t)0x00000000U)         /* !< Minimum value */
#define FLASHCTL_STATPCNT_PULSECNT_MAXIMUM       ((uint32_t)0x00000FFFU)         /* !< Maximum value */

/* FLASHCTL_STATMODE Bits */
/* FLASHCTL_STATMODE[BANKNOTINRD] Bits */
#define FLASHCTL_STATMODE_BANKNOTINRD_OFS        (0)                             /* !< BANKNOTINRD Offset */
#define FLASHCTL_STATMODE_BANKNOTINRD_MASK       ((uint32_t)0x0000001FU)         /* !< Bank not in read mode. Indicates
                                                                                    which banks are not in READ mode.
                                                                                    There is 1 bit per bank. */
#define FLASHCTL_STATMODE_BANKNOTINRD_BANK0      ((uint32_t)0x00000001U)         /* !< Bank 0 */
#define FLASHCTL_STATMODE_BANKNOTINRD_BANK1      ((uint32_t)0x00000002U)         /* !< Bank 1 */
#define FLASHCTL_STATMODE_BANKNOTINRD_BANK2      ((uint32_t)0x00000004U)         /* !< Bank 2 */
#define FLASHCTL_STATMODE_BANKNOTINRD_BANK3      ((uint32_t)0x00000008U)         /* !< Bank 3 */
#define FLASHCTL_STATMODE_BANKNOTINRD_BANK4      ((uint32_t)0x00000010U)         /* !< Bank 4 */
/* FLASHCTL_STATMODE[BANKMODE] Bits */
#define FLASHCTL_STATMODE_BANKMODE_OFS           (8)                             /* !< BANKMODE Offset */
#define FLASHCTL_STATMODE_BANKMODE_MASK          ((uint32_t)0x00000F00U)         /* !< Indicates mode of bank(s) that are
                                                                                    not in READ mode */
#define FLASHCTL_STATMODE_BANKMODE_READ          ((uint32_t)0x00000000U)         /* !< Read Mode */
#define FLASHCTL_STATMODE_BANKMODE_RDMARG0       ((uint32_t)0x00000200U)         /* !< Read Margin 0 Mode */
#define FLASHCTL_STATMODE_BANKMODE_RDMARG1       ((uint32_t)0x00000400U)         /* !< Read Margin 1 Mode */
#define FLASHCTL_STATMODE_BANKMODE_RDMARG0B      ((uint32_t)0x00000600U)         /* !< Read Margin 0B Mode */
#define FLASHCTL_STATMODE_BANKMODE_RDMARG1B      ((uint32_t)0x00000700U)         /* !< Read Margin 1B Mode */
#define FLASHCTL_STATMODE_BANKMODE_PGMVER        ((uint32_t)0x00000900U)         /* !< Program Verify Mode */
#define FLASHCTL_STATMODE_BANKMODE_PGMSW         ((uint32_t)0x00000A00U)         /* !< Program Single Word */
#define FLASHCTL_STATMODE_BANKMODE_ERASEVER      ((uint32_t)0x00000B00U)         /* !< Erase Verify Mode */
#define FLASHCTL_STATMODE_BANKMODE_ERASESECT     ((uint32_t)0x00000C00U)         /* !< Erase Sector */
#define FLASHCTL_STATMODE_BANKMODE_PGMMW         ((uint32_t)0x00000E00U)         /* !< Program Multiple Word */
#define FLASHCTL_STATMODE_BANKMODE_ERASEBNK      ((uint32_t)0x00000F00U)         /* !< Erase Bank */
/* FLASHCTL_STATMODE[BANK2TRDY] Bits */
#define FLASHCTL_STATMODE_BANK2TRDY_OFS          (16)                            /* !< BANK2TRDY Offset */
#define FLASHCTL_STATMODE_BANK2TRDY_MASK         ((uint32_t)0x00010000U)         /* !< Bank 2T Ready. Bank(s) are ready
                                                                                    for 2T access.  This is accomplished
                                                                                    when the pump has fully driven power
                                                                                    rails to the bank(s). */
#define FLASHCTL_STATMODE_BANK2TRDY_FALSE        ((uint32_t)0x00000000U)         /* !< Not ready */
#define FLASHCTL_STATMODE_BANK2TRDY_TRUE         ((uint32_t)0x00010000U)         /* !< Ready */
/* FLASHCTL_STATMODE[BANK1TRDY] Bits */
#define FLASHCTL_STATMODE_BANK1TRDY_OFS          (17)                            /* !< BANK1TRDY Offset */
#define FLASHCTL_STATMODE_BANK1TRDY_MASK         ((uint32_t)0x00020000U)         /* !< Bank 1T Ready. Bank(s) are ready
                                                                                    for 1T access.  This is accomplished
                                                                                    when the bank and pump have been
                                                                                    trimmed. */
#define FLASHCTL_STATMODE_BANK1TRDY_FALSE        ((uint32_t)0x00000000U)         /* !< Not ready */
#define FLASHCTL_STATMODE_BANK1TRDY_TRUE         ((uint32_t)0x00020000U)         /* !< Ready */

/* FLASHCTL_GBLINFO0 Bits */
/* FLASHCTL_GBLINFO0[SECTORSIZE] Bits */
#define FLASHCTL_GBLINFO0_SECTORSIZE_OFS         (0)                             /* !< SECTORSIZE Offset */
#define FLASHCTL_GBLINFO0_SECTORSIZE_MASK        ((uint32_t)0x0000FFFFU)         /* !< Sector size in bytes */
#define FLASHCTL_GBLINFO0_SECTORSIZE_ONEKB       ((uint32_t)0x00000400U)         /* !< Sector size is ONEKB */
#define FLASHCTL_GBLINFO0_SECTORSIZE_TWOKB       ((uint32_t)0x00000800U)         /* !< Sector size is TWOKB */
/* FLASHCTL_GBLINFO0[NUMBANKS] Bits */
#define FLASHCTL_GBLINFO0_NUMBANKS_OFS           (16)                            /* !< NUMBANKS Offset */
#define FLASHCTL_GBLINFO0_NUMBANKS_MASK          ((uint32_t)0x00070000U)         /* !< Number of banks instantiated
                                                                                    Minimum:	1 Maximum:	5 */
#define FLASHCTL_GBLINFO0_NUMBANKS_MINIMUM       ((uint32_t)0x00010000U)         /* !< Minimum value */
#define FLASHCTL_GBLINFO0_NUMBANKS_MAXIMUM       ((uint32_t)0x00050000U)         /* !< Maximum value */

/* FLASHCTL_GBLINFO1 Bits */
/* FLASHCTL_GBLINFO1[DATAWIDTH] Bits */
#define FLASHCTL_GBLINFO1_DATAWIDTH_OFS          (0)                             /* !< DATAWIDTH Offset */
#define FLASHCTL_GBLINFO1_DATAWIDTH_MASK         ((uint32_t)0x000000FFU)         /* !< Data width in bits */
#define FLASHCTL_GBLINFO1_DATAWIDTH_W64BIT       ((uint32_t)0x00000040U)         /* !< Data width is 64 bits */
#define FLASHCTL_GBLINFO1_DATAWIDTH_W128BIT      ((uint32_t)0x00000080U)         /* !< Data width is 128 bits */
/* FLASHCTL_GBLINFO1[ECCWIDTH] Bits */
#define FLASHCTL_GBLINFO1_ECCWIDTH_OFS           (8)                             /* !< ECCWIDTH Offset */
#define FLASHCTL_GBLINFO1_ECCWIDTH_MASK          ((uint32_t)0x00001F00U)         /* !< ECC data width in bits */
#define FLASHCTL_GBLINFO1_ECCWIDTH_W0BIT         ((uint32_t)0x00000000U)         /* !< ECC data width is 0.  ECC not used. */
#define FLASHCTL_GBLINFO1_ECCWIDTH_W8BIT         ((uint32_t)0x00000800U)         /* !< ECC data width is 8 bits */
#define FLASHCTL_GBLINFO1_ECCWIDTH_W16BIT        ((uint32_t)0x00001000U)         /* !< ECC data width is 16 bits */
/* FLASHCTL_GBLINFO1[REDWIDTH] Bits */
#define FLASHCTL_GBLINFO1_REDWIDTH_OFS           (16)                            /* !< REDWIDTH Offset */
#define FLASHCTL_GBLINFO1_REDWIDTH_MASK          ((uint32_t)0x00070000U)         /* !< Redundant data width in bits */
#define FLASHCTL_GBLINFO1_REDWIDTH_W0BIT         ((uint32_t)0x00000000U)         /* !< Redundant data width is 0.
                                                                                    Redundancy/Repair not present. */
#define FLASHCTL_GBLINFO1_REDWIDTH_W2BIT         ((uint32_t)0x00020000U)         /* !< Redundant data width is 2 bits */
#define FLASHCTL_GBLINFO1_REDWIDTH_W4BIT         ((uint32_t)0x00040000U)         /* !< Redundant data width is 4 bits */

/* FLASHCTL_GBLINFO2 Bits */
/* FLASHCTL_GBLINFO2[DATAREGISTERS] Bits */
#define FLASHCTL_GBLINFO2_DATAREGISTERS_OFS      (0)                             /* !< DATAREGISTERS Offset */
#define FLASHCTL_GBLINFO2_DATAREGISTERS_MASK     ((uint32_t)0x0000000FU)         /* !< Number of data registers present. */
#define FLASHCTL_GBLINFO2_DATAREGISTERS_MINIMUM  ((uint32_t)0x00000001U)         /* !< Minimum value of [DATAREGISTERS] */
#define FLASHCTL_GBLINFO2_DATAREGISTERS_MAXIMUM  ((uint32_t)0x00000008U)         /* !< Maximum value of [DATAREGISTERS] */

/* FLASHCTL_BANK0INFO0 Bits */
/* FLASHCTL_BANK0INFO0[MAINSIZE] Bits */
#define FLASHCTL_BANK0INFO0_MAINSIZE_OFS         (0)                             /* !< MAINSIZE Offset */
#define FLASHCTL_BANK0INFO0_MAINSIZE_MASK        ((uint32_t)0x00000FFFU)         /* !< Main region size in sectors
                                                                                    Minimum:	0x8 (8) Maximum:	0x200 (512) */
#define FLASHCTL_BANK0INFO0_MAINSIZE_MINSECTORS  ((uint32_t)0x00000008U)         /* !< Minimum value of [MAINSIZE] */
#define FLASHCTL_BANK0INFO0_MAINSIZE_MAXSECTORS  ((uint32_t)0x00000200U)         /* !< Maximum value of [MAINSIZE] */

/* FLASHCTL_BANK0INFO1 Bits */
/* FLASHCTL_BANK0INFO1[NONMAINSIZE] Bits */
#define FLASHCTL_BANK0INFO1_NONMAINSIZE_OFS      (0)                             /* !< NONMAINSIZE Offset */
#define FLASHCTL_BANK0INFO1_NONMAINSIZE_MASK     ((uint32_t)0x000000FFU)         /* !< Non-main region size in sectors
                                                                                    Minimum:	0x0 (0) Maximum:	0x10 (16) */
#define FLASHCTL_BANK0INFO1_NONMAINSIZE_MINSECTORS ((uint32_t)0x00000000U)         /* !< Minimum value of [NONMAINSIZE] */
#define FLASHCTL_BANK0INFO1_NONMAINSIZE_MAXSECTORS ((uint32_t)0x00000020U)         /* !< Maximum value of [NONMAINSIZE] */
/* FLASHCTL_BANK0INFO1[TRIMSIZE] Bits */
#define FLASHCTL_BANK0INFO1_TRIMSIZE_OFS         (8)                             /* !< TRIMSIZE Offset */
#define FLASHCTL_BANK0INFO1_TRIMSIZE_MASK        ((uint32_t)0x0000FF00U)         /* !< Trim region size in sectors
                                                                                    Minimum:	0x0 (0) Maximum:	0x10 (16) */
#define FLASHCTL_BANK0INFO1_TRIMSIZE_MINSECTORS  ((uint32_t)0x00000000U)         /* !< Minimum value of [TRIMSIZE] */
#define FLASHCTL_BANK0INFO1_TRIMSIZE_MAXSECTORS  ((uint32_t)0x00002000U)         /* !< Maximum value of [TRIMSIZE] */
/* FLASHCTL_BANK0INFO1[ENGRSIZE] Bits */
#define FLASHCTL_BANK0INFO1_ENGRSIZE_OFS         (16)                            /* !< ENGRSIZE Offset */
#define FLASHCTL_BANK0INFO1_ENGRSIZE_MASK        ((uint32_t)0x00FF0000U)         /* !< Engr region size in sectors
                                                                                    Minimum:	0x0 (0) Maximum:	0x10 (16) */
#define FLASHCTL_BANK0INFO1_ENGRSIZE_MINSECTORS  ((uint32_t)0x00000000U)         /* !< Minimum value of [ENGRSIZE] */
#define FLASHCTL_BANK0INFO1_ENGRSIZE_MAXSECTORS  ((uint32_t)0x00200000U)         /* !< Maximum value of [ENGRSIZE] */

/* FLASHCTL_BANK1INFO0 Bits */
/* FLASHCTL_BANK1INFO0[MAINSIZE] Bits */
#define FLASHCTL_BANK1INFO0_MAINSIZE_OFS         (0)                             /* !< MAINSIZE Offset */
#define FLASHCTL_BANK1INFO0_MAINSIZE_MASK        ((uint32_t)0x00000FFFU)         /* !< Main region size in sectors
                                                                                    Minimum:	0x8 (8) Maximum:	0x200 (512) */
#define FLASHCTL_BANK1INFO0_MAINSIZE_MINSECTORS  ((uint32_t)0x00000008U)         /* !< Minimum value of [MAINSIZE] */
#define FLASHCTL_BANK1INFO0_MAINSIZE_MAXSECTORS  ((uint32_t)0x00000200U)         /* !< Maximum value of [MAINSIZE] */

/* FLASHCTL_BANK1INFO1 Bits */
/* FLASHCTL_BANK1INFO1[NONMAINSIZE] Bits */
#define FLASHCTL_BANK1INFO1_NONMAINSIZE_OFS      (0)                             /* !< NONMAINSIZE Offset */
#define FLASHCTL_BANK1INFO1_NONMAINSIZE_MASK     ((uint32_t)0x000000FFU)         /* !< Non-main region size in sectors */
#define FLASHCTL_BANK1INFO1_NONMAINSIZE_MINSECTORS ((uint32_t)0x00000000U)         /* !< Minimum value of [NONMAINSIZE] */
#define FLASHCTL_BANK1INFO1_NONMAINSIZE_MAXSECTORS ((uint32_t)0x00000020U)         /* !< Maximum value of [NONMAINSIZE] */
/* FLASHCTL_BANK1INFO1[TRIMSIZE] Bits */
#define FLASHCTL_BANK1INFO1_TRIMSIZE_OFS         (8)                             /* !< TRIMSIZE Offset */
#define FLASHCTL_BANK1INFO1_TRIMSIZE_MASK        ((uint32_t)0x0000FF00U)         /* !< Trim region size in sectors */
#define FLASHCTL_BANK1INFO1_TRIMSIZE_MINSECTORS  ((uint32_t)0x00000000U)         /* !< Minimum value of [TRIMSIZE] */
#define FLASHCTL_BANK1INFO1_TRIMSIZE_MAXSECTORS  ((uint32_t)0x00002000U)         /* !< Maximum value of [TRIMSIZE] */
/* FLASHCTL_BANK1INFO1[ENGRSIZE] Bits */
#define FLASHCTL_BANK1INFO1_ENGRSIZE_OFS         (16)                            /* !< ENGRSIZE Offset */
#define FLASHCTL_BANK1INFO1_ENGRSIZE_MASK        ((uint32_t)0x00FF0000U)         /* !< Engr region size in sectors
                                                                                    Minimum:	0x0 (0) Maximum:	0x10 (16) */
#define FLASHCTL_BANK1INFO1_ENGRSIZE_MINSECTORS  ((uint32_t)0x00000000U)         /* !< Minimum value of [ENGRSIZE] */
#define FLASHCTL_BANK1INFO1_ENGRSIZE_MAXSECTORS  ((uint32_t)0x00200000U)         /* !< Maximum value of [ENGRSIZE] */

/* FLASHCTL_BANK2INFO0 Bits */
/* FLASHCTL_BANK2INFO0[MAINSIZE] Bits */
#define FLASHCTL_BANK2INFO0_MAINSIZE_OFS         (0)                             /* !< MAINSIZE Offset */
#define FLASHCTL_BANK2INFO0_MAINSIZE_MASK        ((uint32_t)0x00000FFFU)         /* !< Main region size in sectors
                                                                                    Minimum:	0x8 (8) Maximum:	0x200 (512) */
#define FLASHCTL_BANK2INFO0_MAINSIZE_MINSECTORS  ((uint32_t)0x00000008U)         /* !< Minimum value of [MAINSIZE] */
#define FLASHCTL_BANK2INFO0_MAINSIZE_MAXSECTORS  ((uint32_t)0x00000200U)         /* !< Maximum value of [MAINSIZE] */

/* FLASHCTL_BANK2INFO1 Bits */
/* FLASHCTL_BANK2INFO1[NONMAINSIZE] Bits */
#define FLASHCTL_BANK2INFO1_NONMAINSIZE_OFS      (0)                             /* !< NONMAINSIZE Offset */
#define FLASHCTL_BANK2INFO1_NONMAINSIZE_MASK     ((uint32_t)0x000000FFU)         /* !< Non-main region size in sectors */
#define FLASHCTL_BANK2INFO1_NONMAINSIZE_MINSECTORS ((uint32_t)0x00000000U)         /* !< Minimum value of [NONMAINSIZE] */
#define FLASHCTL_BANK2INFO1_NONMAINSIZE_MAXSECTORS ((uint32_t)0x00000020U)         /* !< Maximum value of [NONMAINSIZE] */
/* FLASHCTL_BANK2INFO1[TRIMSIZE] Bits */
#define FLASHCTL_BANK2INFO1_TRIMSIZE_OFS         (8)                             /* !< TRIMSIZE Offset */
#define FLASHCTL_BANK2INFO1_TRIMSIZE_MASK        ((uint32_t)0x0000FF00U)         /* !< Trim region size in sectors */
#define FLASHCTL_BANK2INFO1_TRIMSIZE_MINSECTORS  ((uint32_t)0x00000000U)         /* !< Minimum value of [TRIMSIZE] */
#define FLASHCTL_BANK2INFO1_TRIMSIZE_MAXSECTORS  ((uint32_t)0x00002000U)         /* !< Maximum value of [TRIMSIZE] */
/* FLASHCTL_BANK2INFO1[ENGRSIZE] Bits */
#define FLASHCTL_BANK2INFO1_ENGRSIZE_OFS         (16)                            /* !< ENGRSIZE Offset */
#define FLASHCTL_BANK2INFO1_ENGRSIZE_MASK        ((uint32_t)0x00FF0000U)         /* !< Engr region size in sectors */
#define FLASHCTL_BANK2INFO1_ENGRSIZE_MINSECTORS  ((uint32_t)0x00000000U)         /* !< Minimum value of [ENGRSIZE] */
#define FLASHCTL_BANK2INFO1_ENGRSIZE_MAXSECTORS  ((uint32_t)0x00200000U)         /* !< Maximum value of [ENGRSIZE] */

/* FLASHCTL_BANK3INFO0 Bits */
/* FLASHCTL_BANK3INFO0[MAINSIZE] Bits */
#define FLASHCTL_BANK3INFO0_MAINSIZE_OFS         (0)                             /* !< MAINSIZE Offset */
#define FLASHCTL_BANK3INFO0_MAINSIZE_MASK        ((uint32_t)0x00000FFFU)         /* !< Main region size in sectors */
#define FLASHCTL_BANK3INFO0_MAINSIZE_MINSECTORS  ((uint32_t)0x00000008U)         /* !< Minimum value of [MAINSIZE] */
#define FLASHCTL_BANK3INFO0_MAINSIZE_MAXSECTORS  ((uint32_t)0x00000200U)         /* !< Maximum value of [MAINSIZE] */

/* FLASHCTL_BANK3INFO1 Bits */
/* FLASHCTL_BANK3INFO1[NONMAINSIZE] Bits */
#define FLASHCTL_BANK3INFO1_NONMAINSIZE_OFS      (0)                             /* !< NONMAINSIZE Offset */
#define FLASHCTL_BANK3INFO1_NONMAINSIZE_MASK     ((uint32_t)0x000000FFU)         /* !< Non-main region size in sectors */
#define FLASHCTL_BANK3INFO1_NONMAINSIZE_MINSECTORS ((uint32_t)0x00000000U)         /* !< Minimum value of [NONMAINSIZE] */
#define FLASHCTL_BANK3INFO1_NONMAINSIZE_MAXSECTORS ((uint32_t)0x00000020U)         /* !< Maximum value of [NONMAINSIZE] */
/* FLASHCTL_BANK3INFO1[TRIMSIZE] Bits */
#define FLASHCTL_BANK3INFO1_TRIMSIZE_OFS         (8)                             /* !< TRIMSIZE Offset */
#define FLASHCTL_BANK3INFO1_TRIMSIZE_MASK        ((uint32_t)0x0000FF00U)         /* !< Trim region size in sectors */
#define FLASHCTL_BANK3INFO1_TRIMSIZE_MINSECTORS  ((uint32_t)0x00000000U)         /* !< Minimum value of [TRIMSIZE] */
#define FLASHCTL_BANK3INFO1_TRIMSIZE_MAXSECTORS  ((uint32_t)0x00002000U)         /* !< Maximum value of [TRIMSIZE] */
/* FLASHCTL_BANK3INFO1[ENGRSIZE] Bits */
#define FLASHCTL_BANK3INFO1_ENGRSIZE_OFS         (16)                            /* !< ENGRSIZE Offset */
#define FLASHCTL_BANK3INFO1_ENGRSIZE_MASK        ((uint32_t)0x00FF0000U)         /* !< Engr region size in sectors */
#define FLASHCTL_BANK3INFO1_ENGRSIZE_MINSECTORS  ((uint32_t)0x00000000U)         /* !< Minimum value of [ENGRSIZE] */
#define FLASHCTL_BANK3INFO1_ENGRSIZE_MAXSECTORS  ((uint32_t)0x00200000U)         /* !< Maximum value of [ENGRSIZE] */

/* FLASHCTL_BANK4INFO0 Bits */
/* FLASHCTL_BANK4INFO0[MAINSIZE] Bits */
#define FLASHCTL_BANK4INFO0_MAINSIZE_OFS         (0)                             /* !< MAINSIZE Offset */
#define FLASHCTL_BANK4INFO0_MAINSIZE_MASK        ((uint32_t)0x00000FFFU)         /* !< Main region size in sectors */
#define FLASHCTL_BANK4INFO0_MAINSIZE_MINSECTORS  ((uint32_t)0x00000008U)         /* !< Minimum value of [MAINSIZE] */
#define FLASHCTL_BANK4INFO0_MAINSIZE_MAXSECTORS  ((uint32_t)0x00000200U)         /* !< Maximum value of [MAINSIZE] */

/* FLASHCTL_BANK4INFO1 Bits */
/* FLASHCTL_BANK4INFO1[NONMAINSIZE] Bits */
#define FLASHCTL_BANK4INFO1_NONMAINSIZE_OFS      (0)                             /* !< NONMAINSIZE Offset */
#define FLASHCTL_BANK4INFO1_NONMAINSIZE_MASK     ((uint32_t)0x000000FFU)         /* !< Non-main region size in sectors */
#define FLASHCTL_BANK4INFO1_NONMAINSIZE_MINSECTORS ((uint32_t)0x00000000U)         /* !< Minimum value of [NONMAINSIZE] */
#define FLASHCTL_BANK4INFO1_NONMAINSIZE_MAXSECTORS ((uint32_t)0x00000020U)         /* !< Maximum value of [NONMAINSIZE] */
/* FLASHCTL_BANK4INFO1[TRIMSIZE] Bits */
#define FLASHCTL_BANK4INFO1_TRIMSIZE_OFS         (8)                             /* !< TRIMSIZE Offset */
#define FLASHCTL_BANK4INFO1_TRIMSIZE_MASK        ((uint32_t)0x0000FF00U)         /* !< Trim region size in sectors */
#define FLASHCTL_BANK4INFO1_TRIMSIZE_MINSECTORS  ((uint32_t)0x00000000U)         /* !< Minimum value of [TRIMSIZE] */
#define FLASHCTL_BANK4INFO1_TRIMSIZE_MAXSECTORS  ((uint32_t)0x00002000U)         /* !< Maximum value of [TRIMSIZE] */
/* FLASHCTL_BANK4INFO1[ENGRSIZE] Bits */
#define FLASHCTL_BANK4INFO1_ENGRSIZE_OFS         (16)                            /* !< ENGRSIZE Offset */
#define FLASHCTL_BANK4INFO1_ENGRSIZE_MASK        ((uint32_t)0x00FF0000U)         /* !< Engr region size in sectors */
#define FLASHCTL_BANK4INFO1_ENGRSIZE_MINSECTORS  ((uint32_t)0x00000000U)         /* !< Minimum value of [ENGRSIZE] */
#define FLASHCTL_BANK4INFO1_ENGRSIZE_MAXSECTORS  ((uint32_t)0x00200000U)         /* !< Maximum value of [ENGRSIZE] */


#ifdef __cplusplus
}
#endif

#endif /* ti_devices_msp_peripherals_hw_flashctl__include */
