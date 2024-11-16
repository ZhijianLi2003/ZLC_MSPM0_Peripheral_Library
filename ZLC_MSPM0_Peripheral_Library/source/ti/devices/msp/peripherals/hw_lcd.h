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

#ifndef ti_devices_msp_peripherals_hw_lcd__include
#define ti_devices_msp_peripherals_hw_lcd__include

/* This preliminary header file does not have a version number */
/* MMR repo: https://bitbucket.itg.ti.com/projects/cmcu_msp65ip/repos/f65msplcd */
/* MMR revision: f30da4e0c2d59567e167092fa6005fd6fe36bbf6 */
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
* LCD Registers
******************************************************************************/
#define LCD_INT_EVENT0_OFS                       ((uint32_t)0x00001020U)


/** @addtogroup LCD_INT_EVENT0
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
} LCD_INT_EVENT0_Regs;

/*@}*/ /* end of group LCD_INT_EVENT0 */

/** @addtogroup LCD
  @{
*/

typedef struct {
       uint32_t RESERVED0[512];
  __IO uint32_t PWREN;                             /* !< (@ 0x00000800) Power enable */
  __O  uint32_t RSTCTL;                            /* !< (@ 0x00000804) Reset Control */
       uint32_t RESERVED1[3];
  __I  uint32_t STAT;                              /* !< (@ 0x00000814) Status Register */
       uint32_t RESERVED2[514];
  LCD_INT_EVENT0_Regs  INT_EVENT0;                        /* !< (@ 0x00001020) */
       uint32_t RESERVED3[37];
  __IO uint32_t EVT_MODE;                          /* !< (@ 0x000010E0) Event Mode */
       uint32_t RESERVED4[7];
  __IO uint32_t LCDCTL0;                           /* !< (@ 0x00001100) LCD control register 0 */
       uint32_t RESERVED5;
  __IO uint32_t LCDBLKCTL;                         /* !< (@ 0x00001108) LCD blicking control register */
  __IO uint32_t LCDMEMCTL;                         /* !< (@ 0x0000110C) LCD memory control LCD memory control register */
  __IO uint32_t LCDVCTL;                           /* !< (@ 0x00001110) LCD voltage control register */
  __IO uint32_t LCDPCTL0;                          /* !< (@ 0x00001114) LCD port control register 0 */
  __IO uint32_t LCDPCTL1;                          /* !< (@ 0x00001118) LCD port control register 1 */
  __IO uint32_t LCDPCTL2;                          /* !< (@ 0x0000111C) LCD port control register 2 */
  __IO uint32_t LCDPCTL3;                          /* !< (@ 0x00001120) LCD port control  register 3 */
       uint32_t RESERVED6;
  __IO uint32_t LCDCSSEL0;                         /* !< (@ 0x00001128) LCD common segment select register 0 */
  __IO uint32_t LCDCSSEL1;                         /* !< (@ 0x0000112C) LCD common segment select register 1 */
  __IO uint32_t LCDCSSEL2;                         /* !< (@ 0x00001130) LCD common segment select register 2 */
  __IO uint32_t LCDCSSEL3;                         /* !< (@ 0x00001134) LCD common segment select register 3 */
       uint32_t RESERVED7[2];
  __IO uint8_t LCDM[64];                          /* !< (@ 0x00001140) LCD memory index register */
  __IO uint8_t LCDBM[32];                         /* !< (@ 0x00001180) LCD blinking memory index register */
       uint32_t RESERVED8[791];
  __IO uint32_t LCDVREFCFG;                        /* !< (@ 0x00001DFC) LCD VREF config register */
} LCD_Regs;

/*@}*/ /* end of group LCD */



#if defined ( __CC_ARM )
#pragma no_anon_unions
#endif

/******************************************************************************
* LCD Register Control Bits
******************************************************************************/

/* LCD_IIDX Bits */
/* LCD_IIDX[STAT] Bits */
#define LCD_IIDX_STAT_OFS                        (0)                             /* !< STAT Offset */
#define LCD_IIDX_STAT_MASK                       ((uint32_t)0x000000FFU)         /* !< LCD Module Interrupt Vector Value.
                                                                                    This register provides the highes
                                                                                    priority interrupt index. A read
                                                                                    clears the corresponding interrupt
                                                                                    flag in RIS and MISC. 15h-1Fh =
                                                                                    Reserved */
#define LCD_IIDX_STAT_NO_INTR                    ((uint32_t)0x00000000U)         /* !< No interrupt pending */
#define LCD_IIDX_STAT_FRAME_START                ((uint32_t)0x00000001U)         /* !< Start of new frame interrupt */
#define LCD_IIDX_STAT_BLK_OFF                    ((uint32_t)0x00000002U)         /* !< Blinking segments off interrupt */
#define LCD_IIDX_STAT_BLK_ON                     ((uint32_t)0x00000003U)         /* !< Blinking segments on interrupt */

/* LCD_IMASK Bits */
/* LCD_IMASK[FRMSTART] Bits */
#define LCD_IMASK_FRMSTART_OFS                   (0)                             /* !< FRMSTART Offset */
#define LCD_IMASK_FRMSTART_MASK                  ((uint32_t)0x00000001U)         /* !< Start of new LCD frame. */
#define LCD_IMASK_FRMSTART_CLR                   ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LCD_IMASK_FRMSTART_SET                   ((uint32_t)0x00000001U)         /* !< Set Interrrupt Mask */
/* LCD_IMASK[BLKOFF] Bits */
#define LCD_IMASK_BLKOFF_OFS                     (1)                             /* !< BLKOFF Offset */
#define LCD_IMASK_BLKOFF_MASK                    ((uint32_t)0x00000002U)         /* !< Blinking segments off. */
#define LCD_IMASK_BLKOFF_CLR                     ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LCD_IMASK_BLKOFF_SET                     ((uint32_t)0x00000002U)         /* !< Set Interrrupt Mask */
/* LCD_IMASK[BLKON] Bits */
#define LCD_IMASK_BLKON_OFS                      (2)                             /* !< BLKON Offset */
#define LCD_IMASK_BLKON_MASK                     ((uint32_t)0x00000004U)         /* !< Blinkking segments on. */
#define LCD_IMASK_BLKON_CLR                      ((uint32_t)0x00000000U)         /* !< Clear Interrupt Mask */
#define LCD_IMASK_BLKON_SET                      ((uint32_t)0x00000004U)         /* !< Set Interrrupt Mask */

/* LCD_RIS Bits */
/* LCD_RIS[FRMSTART] Bits */
#define LCD_RIS_FRMSTART_OFS                     (0)                             /* !< FRMSTART Offset */
#define LCD_RIS_FRMSTART_MASK                    ((uint32_t)0x00000001U)         /* !< Set in start of a new frame. */
#define LCD_RIS_FRMSTART_CLR                     ((uint32_t)0x00000000U)         /* !< Interrupt flag cleared */
#define LCD_RIS_FRMSTART_SET                     ((uint32_t)0x00000001U)         /* !< Interrupt flag set */
/* LCD_RIS[BLKOFF] Bits */
#define LCD_RIS_BLKOFF_OFS                       (1)                             /* !< BLKOFF Offset */
#define LCD_RIS_BLKOFF_MASK                      ((uint32_t)0x00000002U)         /* !< Blinking segments turned off
                                                                                    interrupt flag. */
#define LCD_RIS_BLKOFF_CLR                       ((uint32_t)0x00000000U)         /* !< Interrupt flag cleared */
#define LCD_RIS_BLKOFF_SET                       ((uint32_t)0x00000002U)         /* !< Interrupt flag set */
/* LCD_RIS[BLKON] Bits */
#define LCD_RIS_BLKON_OFS                        (2)                             /* !< BLKON Offset */
#define LCD_RIS_BLKON_MASK                       ((uint32_t)0x00000004U)         /* !< Blinking segments turned on. */
#define LCD_RIS_BLKON_CLR                        ((uint32_t)0x00000000U)         /* !< Interrupt flag cleared */
#define LCD_RIS_BLKON_SET                        ((uint32_t)0x00000004U)         /* !< Interrupt flag set */

/* LCD_MIS Bits */
/* LCD_MIS[FRMSTART] Bits */
#define LCD_MIS_FRMSTART_OFS                     (0)                             /* !< FRMSTART Offset */
#define LCD_MIS_FRMSTART_MASK                    ((uint32_t)0x00000001U)         /* !< Master FRMSTART interrupt flag */
#define LCD_MIS_FRMSTART_CLR                     ((uint32_t)0x00000000U)         /* !< Interrupt flag cleared */
#define LCD_MIS_FRMSTART_SET                     ((uint32_t)0x00000001U)         /* !< Interrupt flag set */
/* LCD_MIS[BLKOFF] Bits */
#define LCD_MIS_BLKOFF_OFS                       (1)                             /* !< BLKOFF Offset */
#define LCD_MIS_BLKOFF_MASK                      ((uint32_t)0x00000002U)         /* !< Masked BLKOFF interrupt flag */
#define LCD_MIS_BLKOFF_CLR                       ((uint32_t)0x00000000U)         /* !< Masked interrupt flag cleared */
#define LCD_MIS_BLKOFF_SET                       ((uint32_t)0x00000002U)         /* !< Masked interrupt flag set */
/* LCD_MIS[BLKON] Bits */
#define LCD_MIS_BLKON_OFS                        (2)                             /* !< BLKON Offset */
#define LCD_MIS_BLKON_MASK                       ((uint32_t)0x00000004U)         /* !< Masked BLKON interrupt flag */
#define LCD_MIS_BLKON_CLR                        ((uint32_t)0x00000000U)         /* !< Masked interrupt flag cleared */
#define LCD_MIS_BLKON_SET                        ((uint32_t)0x00000004U)         /* !< Masked interrupt flag set */

/* LCD_ISET Bits */
/* LCD_ISET[FRMSTART] Bits */
#define LCD_ISET_FRMSTART_OFS                    (0)                             /* !< FRMSTART Offset */
#define LCD_ISET_FRMSTART_MASK                   ((uint32_t)0x00000001U)         /* !< Set FRMSTART RIS flag. */
#define LCD_ISET_FRMSTART_NO_EFFECT              ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LCD_ISET_FRMSTART_SET                    ((uint32_t)0x00000001U)         /* !< Set corresponding RIS flag */
/* LCD_ISET[BLKOFF] Bits */
#define LCD_ISET_BLKOFF_OFS                      (1)                             /* !< BLKOFF Offset */
#define LCD_ISET_BLKOFF_MASK                     ((uint32_t)0x00000002U)         /* !< Set BLKOFF RIS flag */
#define LCD_ISET_BLKOFF_NO_EFFECT                ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LCD_ISET_BLKOFF_SET                      ((uint32_t)0x00000002U)         /* !< Set corresponding RIS flag */
/* LCD_ISET[BLKON] Bits */
#define LCD_ISET_BLKON_OFS                       (2)                             /* !< BLKON Offset */
#define LCD_ISET_BLKON_MASK                      ((uint32_t)0x00000004U)         /* !< Set BLKON RIS flag */
#define LCD_ISET_BLKON_NO_EFFECT                 ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LCD_ISET_BLKON_SET                       ((uint32_t)0x00000004U)         /* !< Set corresponding RIS flag */

/* LCD_ICLR Bits */
/* LCD_ICLR[FRMSTART] Bits */
#define LCD_ICLR_FRMSTART_OFS                    (0)                             /* !< FRMSTART Offset */
#define LCD_ICLR_FRMSTART_MASK                   ((uint32_t)0x00000001U)         /* !< Clear FRMSTART RIS flag */
#define LCD_ICLR_FRMSTART_NO_EFFECT              ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LCD_ICLR_FRMSTART_CLR                    ((uint32_t)0x00000001U)         /* !< Clear corresponding RIS flag */
/* LCD_ICLR[BLKOFF] Bits */
#define LCD_ICLR_BLKOFF_OFS                      (1)                             /* !< BLKOFF Offset */
#define LCD_ICLR_BLKOFF_MASK                     ((uint32_t)0x00000002U)         /* !< Clear BLKOFF RIS flag */
#define LCD_ICLR_BLKOFF_NO_EFFECT                ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LCD_ICLR_BLKOFF_CLR                      ((uint32_t)0x00000002U)         /* !< Clear corresponding RIS flag */
/* LCD_ICLR[BLKON] Bits */
#define LCD_ICLR_BLKON_OFS                       (2)                             /* !< BLKON Offset */
#define LCD_ICLR_BLKON_MASK                      ((uint32_t)0x00000004U)         /* !< Clear BLKON RIS flag */
#define LCD_ICLR_BLKON_NO_EFFECT                 ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LCD_ICLR_BLKON_CLR                       ((uint32_t)0x00000004U)         /* !< Clear corresponding RIS flag */

/* LCD_PWREN Bits */
/* LCD_PWREN[ENABLE] Bits */
#define LCD_PWREN_ENABLE_OFS                     (0)                             /* !< ENABLE Offset */
#define LCD_PWREN_ENABLE_MASK                    ((uint32_t)0x00000001U)         /* !< Enable the power */
#define LCD_PWREN_ENABLE_DISABLE                 ((uint32_t)0x00000000U)         /* !< Disable Power */
#define LCD_PWREN_ENABLE_ENABLE                  ((uint32_t)0x00000001U)         /* !< Enable Power */
/* LCD_PWREN[KEY] Bits */
#define LCD_PWREN_KEY_OFS                        (24)                            /* !< KEY Offset */
#define LCD_PWREN_KEY_MASK                       ((uint32_t)0xFF000000U)         /* !< KEY to allow Power State Change */
#define LCD_PWREN_KEY_UNLOCK_W                   ((uint32_t)0x26000000U)         /* !< KEY to allow write access to this
                                                                                    register */

/* LCD_RSTCTL Bits */
/* LCD_RSTCTL[RESETSTKYCLR] Bits */
#define LCD_RSTCTL_RESETSTKYCLR_OFS              (1)                             /* !< RESETSTKYCLR Offset */
#define LCD_RSTCTL_RESETSTKYCLR_MASK             ((uint32_t)0x00000002U)         /* !< Clear the RESETSTKY bit in the STAT
                                                                                    register */
#define LCD_RSTCTL_RESETSTKYCLR_NOP              ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LCD_RSTCTL_RESETSTKYCLR_CLR              ((uint32_t)0x00000002U)         /* !< Clear reset sticky bit */
/* LCD_RSTCTL[RESETASSERT] Bits */
#define LCD_RSTCTL_RESETASSERT_OFS               (0)                             /* !< RESETASSERT Offset */
#define LCD_RSTCTL_RESETASSERT_MASK              ((uint32_t)0x00000001U)         /* !< Assert reset to the peripheral */
#define LCD_RSTCTL_RESETASSERT_NOP               ((uint32_t)0x00000000U)         /* !< Writing 0 has no effect */
#define LCD_RSTCTL_RESETASSERT_ASSERT            ((uint32_t)0x00000001U)         /* !< Assert reset */
/* LCD_RSTCTL[KEY] Bits */
#define LCD_RSTCTL_KEY_OFS                       (24)                            /* !< KEY Offset */
#define LCD_RSTCTL_KEY_MASK                      ((uint32_t)0xFF000000U)         /* !< Unlock key */
#define LCD_RSTCTL_KEY_UNLOCK_W                  ((uint32_t)0xB1000000U)         /* !< KEY to allow write access to this
                                                                                    register */

/* LCD_STAT Bits */
/* LCD_STAT[RESETSTKY] Bits */
#define LCD_STAT_RESETSTKY_OFS                   (16)                            /* !< RESETSTKY Offset */
#define LCD_STAT_RESETSTKY_MASK                  ((uint32_t)0x00010000U)         /* !< This bit indicates, if the
                                                                                    peripheral was reset, since this bit
                                                                                    was cleared by RESETSTKYCLR in the
                                                                                    RSTCTL register */
#define LCD_STAT_RESETSTKY_NORES                 ((uint32_t)0x00000000U)         /* !< The peripheral has not been reset
                                                                                    since this bit was last cleared by
                                                                                    RESETSTKYCLR in the RSTCTL register */
#define LCD_STAT_RESETSTKY_RESET                 ((uint32_t)0x00010000U)         /* !< The peripheral was reset since the
                                                                                    last bit clear */

/* LCD_EVT_MODE Bits */
/* LCD_EVT_MODE[INT0_CFG] Bits */
#define LCD_EVT_MODE_INT0_CFG_OFS                (0)                             /* !< INT0_CFG Offset */
#define LCD_EVT_MODE_INT0_CFG_MASK               ((uint32_t)0x00000003U)         /* !< Event line mode select for event
                                                                                    corresponding to
                                                                                    [IPSTANDARD.INT_EVENT0] */
#define LCD_EVT_MODE_INT0_CFG_DISABLE            ((uint32_t)0x00000000U)         /* !< The interrupt or event line is
                                                                                    disabled. */
#define LCD_EVT_MODE_INT0_CFG_SOFTWARE           ((uint32_t)0x00000001U)         /* !< The interrupt or event line is in
                                                                                    software mode. Software must clear
                                                                                    the RIS. */
#define LCD_EVT_MODE_INT0_CFG_HARDWARE           ((uint32_t)0x00000002U)         /* !< The interrupt or event line is in
                                                                                    hardware mode. The hardware (another
                                                                                    module) clears automatically the
                                                                                    associated RIS flag. */

/* LCD_LCDCTL0 Bits */
/* LCD_LCDCTL0[LCDDIVX] Bits */
#define LCD_LCDCTL0_LCDDIVX_OFS                  (11)                            /* !< LCDDIVX Offset */
#define LCD_LCDCTL0_LCDDIVX_MASK                 ((uint32_t)0x0000F800U)         /* !< LCD frequency divider. Together
                                                                                    with LCDMXx, the LCD frequency fLCD
                                                                                    is calculated as fLCD = fSOURCE /
                                                                                    ((LCDDIVx + 1) * Value[LCDMXx]).
                                                                                    Change only while LCDON = 0.  00000b
                                                                                    = Divide by 1 00001b = Divide by 2 .
                                                                                    11110b = Divide by 31 11111b = Divide
                                                                                    by 32 */
#define LCD_LCDCTL0_LCDDIVX_DIV_BY_1             ((uint32_t)0x00000000U)         /* !< Divide by 1 */
#define LCD_LCDCTL0_LCDDIVX_DIV_BY_2             ((uint32_t)0x00000800U)         /* !< Divide by 2 */
#define LCD_LCDCTL0_LCDDIVX_DIV_BY_3             ((uint32_t)0x00001000U)         /* !< Divide by 3 */
#define LCD_LCDCTL0_LCDDIVX_DIV_BY_4             ((uint32_t)0x00001800U)         /* !< Divide by 4 */
#define LCD_LCDCTL0_LCDDIVX_DIV_BY_5             ((uint32_t)0x00002000U)         /* !< Divide by 5 */
#define LCD_LCDCTL0_LCDDIVX_DIV_BY_6             ((uint32_t)0x00002800U)         /* !< Divide by 6 */
#define LCD_LCDCTL0_LCDDIVX_DIV_BY_7             ((uint32_t)0x00003000U)         /* !< Divide by 7 */
#define LCD_LCDCTL0_LCDDIVX_DIV_BY_8             ((uint32_t)0x00003800U)         /* !< Divide by 8 */
#define LCD_LCDCTL0_LCDDIVX_DIV_BY_9             ((uint32_t)0x00004000U)         /* !< Divide by 9 */
#define LCD_LCDCTL0_LCDDIVX_DIV_BY_10            ((uint32_t)0x00004800U)         /* !< Divide by 10 */
#define LCD_LCDCTL0_LCDDIVX_DIV_BY_11            ((uint32_t)0x00005000U)         /* !< Divide by 11 */
#define LCD_LCDCTL0_LCDDIVX_DIV_BY_12            ((uint32_t)0x00005800U)         /* !< Divide by 12 */
#define LCD_LCDCTL0_LCDDIVX_DIV_BY_13            ((uint32_t)0x00006000U)         /* !< Divide by 13 */
#define LCD_LCDCTL0_LCDDIVX_DIV_BY_14            ((uint32_t)0x00006800U)         /* !< Divide by 14 */
#define LCD_LCDCTL0_LCDDIVX_DIV_BY_15            ((uint32_t)0x00007000U)         /* !< Divide by 15 */
#define LCD_LCDCTL0_LCDDIVX_DIV_BY_16            ((uint32_t)0x00007800U)         /* !< Divide by 16 */
#define LCD_LCDCTL0_LCDDIVX_DIV_BY_17            ((uint32_t)0x00008000U)         /* !< Divide by 17 */
#define LCD_LCDCTL0_LCDDIVX_DIV_BY_18            ((uint32_t)0x00008800U)         /* !< Divide by 18 */
#define LCD_LCDCTL0_LCDDIVX_DIV_BY_19            ((uint32_t)0x00009000U)         /* !< Divide by 19 */
#define LCD_LCDCTL0_LCDDIVX_DIV_BY_20            ((uint32_t)0x00009800U)         /* !< Divide by 20 */
#define LCD_LCDCTL0_LCDDIVX_DIV_BY_21            ((uint32_t)0x0000A000U)         /* !< Divide by 21 */
#define LCD_LCDCTL0_LCDDIVX_DIV_BY_22            ((uint32_t)0x0000A800U)         /* !< Divide by 22 */
#define LCD_LCDCTL0_LCDDIVX_DIV_BY_23            ((uint32_t)0x0000B000U)         /* !< Divide by 23 */
#define LCD_LCDCTL0_LCDDIVX_DIV_BY_24            ((uint32_t)0x0000B800U)         /* !< Divide by 24 */
#define LCD_LCDCTL0_LCDDIVX_DIV_BY_25            ((uint32_t)0x0000C000U)         /* !< Divide by 25 */
#define LCD_LCDCTL0_LCDDIVX_DIV_BY_26            ((uint32_t)0x0000C800U)         /* !< Divide by 26 */
#define LCD_LCDCTL0_LCDDIVX_DIV_BY_27            ((uint32_t)0x0000D000U)         /* !< Divide by 27 */
#define LCD_LCDCTL0_LCDDIVX_DIV_BY_28            ((uint32_t)0x0000D800U)         /* !< Divide by 28 */
#define LCD_LCDCTL0_LCDDIVX_DIV_BY_29            ((uint32_t)0x0000E000U)         /* !< Divide by 29 */
#define LCD_LCDCTL0_LCDDIVX_DIV_BY_30            ((uint32_t)0x0000E800U)         /* !< Divide by 30 */
#define LCD_LCDCTL0_LCDDIVX_DIV_BY_31            ((uint32_t)0x0000F000U)         /* !< Divide by 31 */
#define LCD_LCDCTL0_LCDDIVX_DIV_BY_32            ((uint32_t)0x0000F800U)         /* !< Divide by 32 */
/* LCD_LCDCTL0[LCDLP] Bits */
#define LCD_LCDCTL0_LCDLP_OFS                    (1)                             /* !< LCDLP Offset */
#define LCD_LCDCTL0_LCDLP_MASK                   ((uint32_t)0x00000002U)         /* !< LCD low-power waveform. This bit is
                                                                                    only applicable for 1/3 bias mode,
                                                                                    that is, for LCDBIASSEL = 0.  0b =
                                                                                    Standard LCD waveforms on segment and
                                                                                    common lines selected.  1b =
                                                                                    Low-power LCD waveforms on segment
                                                                                    and common lines selected. */
#define LCD_LCDCTL0_LCDLP_STD_LCD                ((uint32_t)0x00000000U)         /* !< Standard LCD waveforms */
#define LCD_LCDCTL0_LCDLP_LP_LCD                 ((uint32_t)0x00000002U)         /* !< Low power LCD waveforms */
/* LCD_LCDCTL0[LCDMXX] Bits */
#define LCD_LCDCTL0_LCDMXX_OFS                   (3)                             /* !< LCDMXX Offset */
#define LCD_LCDCTL0_LCDMXX_MASK                  ((uint32_t)0x00000038U)         /* !< LCD mux rate. These bits select the
                                                                                    LCD mode. Change only while LCDON =
                                                                                    0.  000b = Static 001b = 2-mux 010b =
                                                                                    3-mux 011b = 4-mux 100b = 5-mux 101b
                                                                                    = 6-mux 110b = 7-mux 111b = 8-mux */
#define LCD_LCDCTL0_LCDMXX_MX_STATIC             ((uint32_t)0x00000000U)         /* !< Static */
#define LCD_LCDCTL0_LCDMXX_MX_2                  ((uint32_t)0x00000008U)         /* !< 2-mux */
#define LCD_LCDCTL0_LCDMXX_MX_3                  ((uint32_t)0x00000010U)         /* !< 3-mux */
#define LCD_LCDCTL0_LCDMXX_MX_4                  ((uint32_t)0x00000018U)         /* !< 4-mux */
#define LCD_LCDCTL0_LCDMXX_MX_5                  ((uint32_t)0x00000020U)         /* !< 5-mux */
#define LCD_LCDCTL0_LCDMXX_MX_6                  ((uint32_t)0x00000028U)         /* !< 6-mux */
#define LCD_LCDCTL0_LCDMXX_MX_7                  ((uint32_t)0x00000030U)         /* !< 7-mux */
#define LCD_LCDCTL0_LCDMXX_MX_8                  ((uint32_t)0x00000038U)         /* !< 8-mux */
/* LCD_LCDCTL0[LCDON] Bits */
#define LCD_LCDCTL0_LCDON_OFS                    (0)                             /* !< LCDON Offset */
#define LCD_LCDCTL0_LCDON_MASK                   ((uint32_t)0x00000001U)         /* !< LCD on. This bit turns the LCD
                                                                                    module on or off.  0b = LCD module
                                                                                    off 1b = LCD module on */
#define LCD_LCDCTL0_LCDON_LCD_MOD_DISABLE        ((uint32_t)0x00000000U)         /* !< LCD module off */
#define LCD_LCDCTL0_LCDON_LCD_MOD_ENABLE         ((uint32_t)0x00000001U)         /* !< LCD module on */
/* LCD_LCDCTL0[LCDSON] Bits */
#define LCD_LCDCTL0_LCDSON_OFS                   (2)                             /* !< LCDSON Offset */
#define LCD_LCDCTL0_LCDSON_MASK                  ((uint32_t)0x00000004U)         /* !< LCD segments on. This bit supports
                                                                                    flashing LCD applications by turning
                                                                                    off all segment lines, while leaving
                                                                                    the LCD timing generator and R33
                                                                                    enabled.  0b = All LCD segments are
                                                                                    off.  1b = All LCD segments are
                                                                                    enabled and on or off according to
                                                                                    their corresponding memory location. */
#define LCD_LCDCTL0_LCDSON_LCD_SEG_OFF           ((uint32_t)0x00000000U)         /* !< All LCD segments are off. */
#define LCD_LCDCTL0_LCDSON_LCD_SEG_ON            ((uint32_t)0x00000004U)         /* !< All LCD segments are enabled and on
                                                                                    or off according to their
                                                                                    corresponding memory location. */
/* LCD_LCDCTL0[LCDSYNCEXT] Bits */
#define LCD_LCDCTL0_LCDSYNCEXT_OFS               (24)                            /* !< LCDSYNCEXT Offset */
#define LCD_LCDCTL0_LCDSYNCEXT_MASK              ((uint32_t)0x01000000U)
#define LCD_LCDCTL0_LCDSYNCEXT_LCD_EXT_SYNC_OFF  ((uint32_t)0x00000000U)         /* !< External eynchronization off. */
#define LCD_LCDCTL0_LCDSYNCEXT_LCD_EXT_SYNC_ON   ((uint32_t)0x01000000U)         /* !< External synchronization on. */

/* LCD_LCDBLKCTL Bits */
/* LCD_LCDBLKCTL[LCDBLKMODX] Bits */
#define LCD_LCDBLKCTL_LCDBLKMODX_OFS             (0)                             /* !< LCDBLKMODX Offset */
#define LCD_LCDBLKCTL_LCDBLKMODX_MASK            ((uint32_t)0x00000003U)         /* !< Blinking mode 00b = Blinking
                                                                                    disabled.  01b = Blinking of
                                                                                    individual segments as enabled in
                                                                                    blinking memory register LCDBMx. In
                                                                                    mux mode >5 blinking is disabled.
                                                                                    10b = Blinking of all segments 11b =
                                                                                    Switching between display contents as
                                                                                    stored in LCDMx and LCDBMx memory
                                                                                    registers. In mux mode >5 blinking is
                                                                                    disabled. */
#define LCD_LCDBLKCTL_LCDBLKMODX_BLINK_DISABLE   ((uint32_t)0x00000000U)         /* !< Blinking disabled. */
#define LCD_LCDBLKCTL_LCDBLKMODX_BLINK_SELECED   ((uint32_t)0x00000001U)         /* !< Blinking of individual segments as
                                                                                    enabled in blinking memory register
                                                                                    LCDBMx. In mux mode >5 blinking is
                                                                                    disabled. */
#define LCD_LCDBLKCTL_LCDBLKMODX_BLINK_ALL       ((uint32_t)0x00000002U)         /* !< Blinking of all segments */
#define LCD_LCDBLKCTL_LCDBLKMODX_BKINK_TOGGLE    ((uint32_t)0x00000003U)         /* !< Switching between display contents
                                                                                    as stored in LCDMx and LCDBMx memory
                                                                                    registers. In mux mode >5 blinking is
                                                                                    disabled. */
/* LCD_LCDBLKCTL[LCDBLKPREX] Bits */
#define LCD_LCDBLKCTL_LCDBLKPREX_OFS             (2)                             /* !< LCDBLKPREX Offset */
#define LCD_LCDBLKCTL_LCDBLKPREX_MASK            ((uint32_t)0x0000001CU)         /* !< Clock prescaler for blinking
                                                                                    frequency. */
#define LCD_LCDBLKCTL_LCDBLKPREX_DIV_BY_2        ((uint32_t)0x00000000U)         /* !< Divide by 2 */
#define LCD_LCDBLKCTL_LCDBLKPREX_DIV_BY_4        ((uint32_t)0x00000004U)         /* !< Divide by 4 */
#define LCD_LCDBLKCTL_LCDBLKPREX_DIV_BY_8        ((uint32_t)0x00000008U)         /* !< Divide by 8 */
#define LCD_LCDBLKCTL_LCDBLKPREX_DIV_BY_16       ((uint32_t)0x0000000CU)         /* !< Divide by 16 */
#define LCD_LCDBLKCTL_LCDBLKPREX_DIV_BY_32       ((uint32_t)0x00000010U)         /* !< Divide by 32 */
#define LCD_LCDBLKCTL_LCDBLKPREX_DIV_BY_64       ((uint32_t)0x00000014U)         /* !< Divide by 64 */
#define LCD_LCDBLKCTL_LCDBLKPREX_DIV_BY_128      ((uint32_t)0x00000018U)         /* !< Divide by 128 */
#define LCD_LCDBLKCTL_LCDBLKPREX_DIV_BY_256      ((uint32_t)0x0000001CU)         /* !< Divide by 256 */

/* LCD_LCDMEMCTL Bits */
/* LCD_LCDMEMCTL[LCDCLRBM] Bits */
#define LCD_LCDMEMCTL_LCDCLRBM_OFS               (2)                             /* !< LCDCLRBM Offset */
#define LCD_LCDMEMCTL_LCDCLRBM_MASK              ((uint32_t)0x00000004U)         /* !< Clear LCD blinking memory Clears
                                                                                    all blinking memory registers LCDBMx.
                                                                                    The bit is automatically reset when
                                                                                    the blinking memory is cleared.
                                                                                    Setting this bit in 5-mux mode and
                                                                                    above has no effect. It is
                                                                                    immediately reset again.  0b =
                                                                                    Contents of blinking memory registers
                                                                                    LCDBMx remain unchanged 1b = Clear
                                                                                    content of all blinking memory
                                                                                    registers LCDBMx */
#define LCD_LCDMEMCTL_LCDCLRBM_NO_CLR_BLNK_MEM_REGS ((uint32_t)0x00000000U)         /* !< Contents of blinking memory
                                                                                    registers LCDBMx remain unchanged */
#define LCD_LCDMEMCTL_LCDCLRBM_CLR_BLNK_MEM_REGS ((uint32_t)0x00000004U)         /* !< Clear content of all blinking
                                                                                    memory registers LCDBMx */
/* LCD_LCDMEMCTL[LCDCLRM] Bits */
#define LCD_LCDMEMCTL_LCDCLRM_OFS                (1)                             /* !< LCDCLRM Offset */
#define LCD_LCDMEMCTL_LCDCLRM_MASK               ((uint32_t)0x00000002U)         /* !< Clear LCD memory Clears all LCD
                                                                                    memory registers LCDMx. The bit is
                                                                                    automatically reset when the LCD
                                                                                    memory is cleared.  0b = Contents of
                                                                                    LCD memory registers LCDMx remain
                                                                                    unchanged 1b = Clear content of all
                                                                                    LCD memory registers LCDMx */
#define LCD_LCDMEMCTL_LCDCLRM_NO_CLR_LCD_MEM_REGS ((uint32_t)0x00000000U)         /* !< Contents of LCD memory registers
                                                                                    LCDMx remain unchanged */
#define LCD_LCDMEMCTL_LCDCLRM_CLR_LCD_MEM_REGS   ((uint32_t)0x00000002U)         /* !< Clear content of all LCD memory
                                                                                    registers LCDMx */
/* LCD_LCDMEMCTL[LCDDISP] Bits */
#define LCD_LCDMEMCTL_LCDDISP_OFS                (0)                             /* !< LCDDISP Offset */
#define LCD_LCDMEMCTL_LCDDISP_MASK               ((uint32_t)0x00000001U)         /* !< Select LCD memory registers for
                                                                                    display When LCDBLKMODx = 00, LCDDISP
                                                                                    can be set by software.  The bit is
                                                                                    cleared in LCDBLKMODx = 01 and
                                                                                    LCDBLKMODx = 10 or if a mux mode =5
                                                                                    is selected and cannot be changed by
                                                                                    software.  When LCDBLKMODx = 11, this
                                                                                    bit reflects the currently displayed
                                                                                    memory but cannot be changed by
                                                                                    software. When returning to
                                                                                    LCDBLKMODx = 00 the bit is cleared.
                                                                                    0b = Display content of LCD memory
                                                                                    registers LCDMx 1b = Display content
                                                                                    of LCD blinking memory registers
                                                                                    LCDBMx */
#define LCD_LCDMEMCTL_LCDDISP_SEL_LCD_MEM_REGS   ((uint32_t)0x00000000U)         /* !< Display content of LCD memory
                                                                                    registers LCDMx */
#define LCD_LCDMEMCTL_LCDDISP_SEL_BLNK_MEM_REGS  ((uint32_t)0x00000001U)         /* !< Display content of LCD blinking
                                                                                    memory registers LCDBMx */

/* LCD_LCDVCTL Bits */
/* LCD_LCDVCTL[LCDBIASSEL] Bits */
#define LCD_LCDVCTL_LCDBIASSEL_OFS               (1)                             /* !< LCDBIASSEL Offset */
#define LCD_LCDVCTL_LCDBIASSEL_MASK              ((uint32_t)0x00000002U)         /* !< Bias select.  LCDBIASSEL is ignored
                                                                                    in static mode as well as for 2-mux,
                                                                                    3-mux and 4-mux LCD modes.  For 5-mux
                                                                                    to 8-mux modes: 0b = 1/3 bias 1b =
                                                                                    1/4 bias */
#define LCD_LCDVCTL_LCDBIASSEL_ONE_BY_3_BIAS     ((uint32_t)0x00000000U)         /* !< 1/3 bias */
#define LCD_LCDVCTL_LCDBIASSEL_ONE_BY_4_BIAS     ((uint32_t)0x00000002U)         /* !< 1/4 bias */
/* LCD_LCDVCTL[LCDCPEN] Bits */
#define LCD_LCDVCTL_LCDCPEN_OFS                  (7)                             /* !< LCDCPEN Offset */
#define LCD_LCDVCTL_LCDCPEN_MASK                 ((uint32_t)0x00000080U)         /* !< Charge pump enable 0b = Charge pump
                                                                                    disabled(1) 1b = Charge pump enabled
                                                                                    when VLCD is generated internally
                                                                                    (VLCDEXT = 0) and VLCDx > 0 or
                                                                                    VLCDREFx > 0. */
#define LCD_LCDVCTL_LCDCPEN_CP_DISABLE           ((uint32_t)0x00000000U)         /* !< Charge pump disabled(1) */
#define LCD_LCDVCTL_LCDCPEN_CP_ENABLE            ((uint32_t)0x00000080U)         /* !< Charge pump enabled when VLCD is
                                                                                    generated internally (VLCDEXT = 0)
                                                                                    and VLCDx > 0 or VLCDREFx > 0. */
/* LCD_LCDVCTL[LCDCPFSELX] Bits */
#define LCD_LCDVCTL_LCDCPFSELX_OFS               (12)                            /* !< LCDCPFSELX Offset */
#define LCD_LCDVCTL_LCDCPFSELX_MASK              ((uint32_t)0x0000F000U)         /* !< Charge pump frequency selection.
                                                                                    0000b = 32.768 kHz / 1 / 8 = 4.096
                                                                                    kHz 0001b = 32.768 kHz / 2 / 8 =
                                                                                    2.048 kHz 0010b = 32.768 kHz / 3 / 8
                                                                                    = 1.365 kHz 0011b = 32.768 kHz / 4 /
                                                                                    8 = 1.024 kHz 0100b = 32.768 kHz / 5
                                                                                    / 8 = 819 Hz 0101b = 32.768 kHz / 6 /
                                                                                    8 = 682 Hz 0110b = 32.768 kHz / 7 / 8
                                                                                    = 585 Hz 0111b = 32.768 kHz / 8 / 8 =
                                                                                    512 Hz 1000b = 32.768 kHz / 9 / 8 =
                                                                                    455 Hz 1001b = 32.768 kHz / 10 / 8 =
                                                                                    409 Hz 1010b = 32.768 kHz / 11 / 8 =
                                                                                    372 Hz 1011b = 32.768 kHz / 12 / 8 =
                                                                                    341 Hz 1100b = 32.768 kHz / 13 / 8 =
                                                                                    315 Hz 1101b = 32.768 kHz / 14 / 8 =
                                                                                    292 Hz 1110b = 32.768 kHz / 15 / 8 =
                                                                                    273 Hz 1111b = 32.768 kHz / 16 / 8 =
                                                                                    256 Hz */
#define LCD_LCDVCTL_LCDCPFSELX_DIV_BY_1_BY_8     ((uint32_t)0x00000000U)         /* !< 32.768 kHz / 1 / 8 = 4.096 kHz */
#define LCD_LCDVCTL_LCDCPFSELX_DIV_BY_2_BY_8     ((uint32_t)0x00001000U)         /* !< 32.768 kHz / 2 / 8 = 2.048 kHz */
#define LCD_LCDVCTL_LCDCPFSELX_DIV_BY_3_BY_8     ((uint32_t)0x00002000U)         /* !< 32.768 kHz / 3 / 8 = 1.365 kHz */
#define LCD_LCDVCTL_LCDCPFSELX_DIV_BY_4_BY_8     ((uint32_t)0x00003000U)         /* !< 32.768 kHz / 4 / 8 = 1.024 kHz */
#define LCD_LCDVCTL_LCDCPFSELX_DIV_BY_5_BY_8     ((uint32_t)0x00004000U)         /* !< 32.768 kHz / 5 / 8 = 819 Hz */
#define LCD_LCDVCTL_LCDCPFSELX_DIV_BY_6_BY_8     ((uint32_t)0x00005000U)         /* !< 32.768 kHz / 6 / 8 = 682 Hz */
#define LCD_LCDVCTL_LCDCPFSELX_DIV_BY_7_BY_8     ((uint32_t)0x00006000U)         /* !< 32.768 kHz / 7 / 8 = 585 Hz */
#define LCD_LCDVCTL_LCDCPFSELX_DIV_BY_8_BY_8     ((uint32_t)0x00007000U)         /* !< 32.768 kHz / 8 / 8 = 512 Hz */
#define LCD_LCDVCTL_LCDCPFSELX_DIV_BY_9_BY_8     ((uint32_t)0x00008000U)         /* !< 32.768 kHz / 9 / 8 = 455 Hz */
#define LCD_LCDVCTL_LCDCPFSELX_DIV_BY_10_BY_8    ((uint32_t)0x00009000U)         /* !< 32.768 kHz / 10 / 8 = 409 Hz */
#define LCD_LCDVCTL_LCDCPFSELX_DIV_BY_11_BY_8    ((uint32_t)0x0000A000U)         /* !< 32.768 kHz / 11 / 8 = 372 Hz */
#define LCD_LCDVCTL_LCDCPFSELX_DIV_BY_12_BY_8    ((uint32_t)0x0000B000U)         /* !< 32.768 kHz / 12 / 8 = 341 Hz */
#define LCD_LCDVCTL_LCDCPFSELX_DIV_BY_13_BY_8    ((uint32_t)0x0000C000U)         /* !< 32.768 kHz / 13 / 8 = 315 Hz */
#define LCD_LCDVCTL_LCDCPFSELX_DIV_BY_14_BY_8    ((uint32_t)0x0000D000U)         /* !< 32.768 kHz / 14 / 8 = 292 Hz */
#define LCD_LCDVCTL_LCDCPFSELX_DIV_BY_15_BY_8    ((uint32_t)0x0000E000U)         /* !< 32.768 kHz / 15 / 8 = 273 Hz */
#define LCD_LCDVCTL_LCDCPFSELX_DIV_BY_16_BY_8    ((uint32_t)0x0000F000U)         /* !< 32.768 kHz / 16 / 8 = 256 Hz */
/* LCD_LCDVCTL[LCDINTBIASEN] Bits */
#define LCD_LCDVCTL_LCDINTBIASEN_OFS             (2)                             /* !< LCDINTBIASEN Offset */
#define LCD_LCDVCTL_LCDINTBIASEN_MASK            ((uint32_t)0x00000004U)         /* !< Enables the internal bias voltage
                                                                                    resistor divider.  The actual voltage
                                                                                    source used for the resistor divider
                                                                                    is selected by the VLCDSEL_VDD_R33
                                                                                    bit configuration.  0b = Internal
                                                                                    bias voltage resistor divider is
                                                                                    disabled 1b = Internal bias voltage
                                                                                    resistor divider is enabledDD */
#define LCD_LCDVCTL_LCDINTBIASEN_INT_BIAS_DISABLE ((uint32_t)0x00000000U)         /* !< Internal bias voltage resistor
                                                                                    divider is disabled */
#define LCD_LCDVCTL_LCDINTBIASEN_INT_BIAS_ENABLE ((uint32_t)0x00000004U)         /* !< Internal bias voltage resistor
                                                                                    divider is enabled */
/* LCD_LCDVCTL[LCDREFEN] Bits */
#define LCD_LCDVCTL_LCDREFEN_OFS                 (6)                             /* !< LCDREFEN Offset */
#define LCD_LCDVCTL_LCDREFEN_MASK                ((uint32_t)0x00000040U)         /* !< Internal reference voltage enable
                                                                                    on R13 0b = Internal reference
                                                                                    voltage disabled 1b = Internal
                                                                                    reference voltage enabled */
#define LCD_LCDVCTL_LCDREFEN_INT_REF_DISABLE     ((uint32_t)0x00000000U)         /* !< Internal reference voltage disabled */
#define LCD_LCDVCTL_LCDREFEN_INT_REF_ENABLE      ((uint32_t)0x00000040U)         /* !< Internal reference voltage enabled */
/* LCD_LCDVCTL[LCDREFMODE] Bits */
#define LCD_LCDVCTL_LCDREFMODE_OFS               (0)                             /* !< LCDREFMODE Offset */
#define LCD_LCDVCTL_LCDREFMODE_MASK              ((uint32_t)0x00000001U)         /* !< Selects whether R13 voltage is
                                                                                    switched or in static mode 0b =
                                                                                    Static mode 1b = Switched mode */
#define LCD_LCDVCTL_LCDREFMODE_STATIC_MODE       ((uint32_t)0x00000000U)         /* !< Static mode */
#define LCD_LCDVCTL_LCDREFMODE_SWITCHED_MODE     ((uint32_t)0x00000001U)         /* !< Switched mode */
/* LCD_LCDVCTL[LCDSELVDD] Bits */
#define LCD_LCDVCTL_LCDSELVDD_OFS                (5)                             /* !< LCDSELVDD Offset */
#define LCD_LCDVCTL_LCDSELVDD_MASK               ((uint32_t)0x00000020U)         /* !< Selects if R33 is supplied either
                                                                                    from AVDD internally or from charge
                                                                                    pump 0b = R33 connected to external
                                                                                    supply 1b = R33 internally connected
                                                                                    to AVDD */
#define LCD_LCDVCTL_LCDSELVDD_SEL_EXT_SUPPLY     ((uint32_t)0x00000000U)         /* !< R33 connected to external supply */
#define LCD_LCDVCTL_LCDSELVDD_SEL_AVDD           ((uint32_t)0x00000020U)         /* !< R33 internally connected to AVDD */
/* LCD_LCDVCTL[LCD_HP_LP] Bits */
#define LCD_LCDVCTL_LCD_HP_LP_OFS                (4)                             /* !< LCD_HP_LP Offset */
#define LCD_LCDVCTL_LCD_HP_LP_MASK               ((uint32_t)0x00000010U)         /* !< High-power or Low-power LCD.  This
                                                                                    bit is only effective when the
                                                                                    internal bias voltage resistor
                                                                                    divider is used, that is, when
                                                                                    LCDINTBIASEN = 1. It selects the
                                                                                    resistor ladder that is used to
                                                                                    generate the bias voltages for the
                                                                                    LCD.  0b = Low-power LCD is used 1b =
                                                                                    Higher-power LCD is used */
#define LCD_LCDVCTL_LCD_HP_LP_LP_MODE            ((uint32_t)0x00000000U)         /* !< Low-power LCD is used */
#define LCD_LCDVCTL_LCD_HP_LP_HP_MODE            ((uint32_t)0x00000010U)         /* !< Higher-power LCD is used */
/* LCD_LCDVCTL[VLCDSEL_VDD_R33] Bits */
#define LCD_LCDVCTL_VLCDSEL_VDD_R33_OFS          (3)                             /* !< VLCDSEL_VDD_R33 Offset */
#define LCD_LCDVCTL_VLCDSEL_VDD_R33_MASK         ((uint32_t)0x00000008U)         /* !< Selects if the LCD bias voltage V1
                                                                                    is sourced from the R33 pin or from
                                                                                    the internal supply voltage AVDD This
                                                                                    bit is only effective when the
                                                                                    internal bias voltage resistor
                                                                                    divider is used, that is, when
                                                                                    LCDINTBIASEN = 1 0b = V1 is sourced
                                                                                    from R33 1b = V1 is sourced
                                                                                    internally from AVDD */
#define LCD_LCDVCTL_VLCDSEL_VDD_R33_SEL_R33      ((uint32_t)0x00000000U)         /* !< V1 is sourced from R33 */
#define LCD_LCDVCTL_VLCDSEL_VDD_R33_SEL_AVDD     ((uint32_t)0x00000008U)         /* !< V1 is sourced internally from AVDD */
/* LCD_LCDVCTL[VLCDX] Bits */
#define LCD_LCDVCTL_VLCDX_OFS                    (8)                             /* !< VLCDX Offset */
#define LCD_LCDVCTL_VLCDX_MASK                   ((uint32_t)0x00000F00U)         /* !< Internal reference voltage select
                                                                                    on R13. */
#define LCD_LCDVCTL_VLCDX_SEL_2P60V              ((uint32_t)0x00000000U)         /* !< 2.60 V */
#define LCD_LCDVCTL_VLCDX_SEL_2P66V              ((uint32_t)0x00000100U)         /* !< 2.66 V */
#define LCD_LCDVCTL_VLCDX_SEL_2P72V              ((uint32_t)0x00000200U)         /* !< 2.72 V */
#define LCD_LCDVCTL_VLCDX_SEL_2P78V              ((uint32_t)0x00000300U)         /* !< 2.78 V */
#define LCD_LCDVCTL_VLCDX_SEL_2P84V              ((uint32_t)0x00000400U)         /* !< 2.84 V */
#define LCD_LCDVCTL_VLCDX_SEL_2P90V              ((uint32_t)0x00000500U)         /* !< 2.90 V */
#define LCD_LCDVCTL_VLCDX_SEL_2P96V              ((uint32_t)0x00000600U)         /* !< 2.96 V */
#define LCD_LCDVCTL_VLCDX_SEL_3P02V              ((uint32_t)0x00000700U)         /* !< 3.02 V */
#define LCD_LCDVCTL_VLCDX_SEL_3P08V              ((uint32_t)0x00000800U)         /* !< 3.08 V */
#define LCD_LCDVCTL_VLCDX_SEL_3P14V              ((uint32_t)0x00000900U)         /* !< 3.14 V */
#define LCD_LCDVCTL_VLCDX_SEL_3P20V              ((uint32_t)0x00000A00U)         /* !< 3.20 V */
#define LCD_LCDVCTL_VLCDX_SEL_3P26V              ((uint32_t)0x00000B00U)         /* !< 3.26 V */
#define LCD_LCDVCTL_VLCDX_SEL_3P32V              ((uint32_t)0x00000C00U)         /* !< 3.32 V */
#define LCD_LCDVCTL_VLCDX_SEL_3P38V              ((uint32_t)0x00000D00U)         /* !< 3.38 V */
#define LCD_LCDVCTL_VLCDX_SEL_3P44V              ((uint32_t)0x00000E00U)         /* !< 3.44 V */
#define LCD_LCDVCTL_VLCDX_SEL_3P50V              ((uint32_t)0x00000F00U)         /* !< 3.50 V */
/* LCD_LCDVCTL[LCDVBSTEN] Bits */
#define LCD_LCDVCTL_LCDVBSTEN_OFS                (24)                            /* !< LCDVBSTEN Offset */
#define LCD_LCDVCTL_LCDVBSTEN_MASK               ((uint32_t)0x01000000U)         /* !< Enables the voltage boost circuitry
                                                                                    which provides a boosted VDDA
                                                                                    voltage. This boosted voltage is to
                                                                                    be used in the switch controls, when
                                                                                    the VDDA supply is less than 1.6V. */
#define LCD_LCDVCTL_LCDVBSTEN_DISABLE            ((uint32_t)0x00000000U)         /* !< Disable. */
#define LCD_LCDVCTL_LCDVBSTEN_ENABLE             ((uint32_t)0x01000000U)         /* !< Enable. */

/* LCD_LCDPCTL0 Bits */
/* LCD_LCDPCTL0[LCDS0] Bits */
#define LCD_LCDPCTL0_LCDS0_OFS                   (0)                             /* !< LCDS0 Offset */
#define LCD_LCDPCTL0_LCDS0_MASK                  ((uint32_t)0x00000001U)         /* !< LCD pin 0 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL0_LCDS0_SEL_PORT              ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL0_LCDS0_SEL_LCD               ((uint32_t)0x00000001U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL0[LCDS1] Bits */
#define LCD_LCDPCTL0_LCDS1_OFS                   (1)                             /* !< LCDS1 Offset */
#define LCD_LCDPCTL0_LCDS1_MASK                  ((uint32_t)0x00000002U)         /* !< LCD pin 1 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL0_LCDS1_SEL_PORT              ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL0_LCDS1_SEL_LCD               ((uint32_t)0x00000002U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL0[LCDS10] Bits */
#define LCD_LCDPCTL0_LCDS10_OFS                  (10)                            /* !< LCDS10 Offset */
#define LCD_LCDPCTL0_LCDS10_MASK                 ((uint32_t)0x00000400U)         /* !< LCD pin 10 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL0_LCDS10_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL0_LCDS10_SEL_LCD              ((uint32_t)0x00000400U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL0[LCDS11] Bits */
#define LCD_LCDPCTL0_LCDS11_OFS                  (11)                            /* !< LCDS11 Offset */
#define LCD_LCDPCTL0_LCDS11_MASK                 ((uint32_t)0x00000800U)         /* !< LCD pin 11 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL0_LCDS11_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL0_LCDS11_SEL_LCD              ((uint32_t)0x00000800U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL0[LCDS12] Bits */
#define LCD_LCDPCTL0_LCDS12_OFS                  (12)                            /* !< LCDS12 Offset */
#define LCD_LCDPCTL0_LCDS12_MASK                 ((uint32_t)0x00001000U)         /* !< LCD pin 12 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL0_LCDS12_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL0_LCDS12_SEL_LCD              ((uint32_t)0x00001000U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL0[LCDS13] Bits */
#define LCD_LCDPCTL0_LCDS13_OFS                  (13)                            /* !< LCDS13 Offset */
#define LCD_LCDPCTL0_LCDS13_MASK                 ((uint32_t)0x00002000U)         /* !< LCD pin 13 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL0_LCDS13_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL0_LCDS13_SEL_LCD              ((uint32_t)0x00002000U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL0[LCDS14] Bits */
#define LCD_LCDPCTL0_LCDS14_OFS                  (14)                            /* !< LCDS14 Offset */
#define LCD_LCDPCTL0_LCDS14_MASK                 ((uint32_t)0x00004000U)         /* !< LCD pin 14 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL0_LCDS14_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL0_LCDS14_SEL_LCD              ((uint32_t)0x00004000U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL0[LCDS15] Bits */
#define LCD_LCDPCTL0_LCDS15_OFS                  (15)                            /* !< LCDS15 Offset */
#define LCD_LCDPCTL0_LCDS15_MASK                 ((uint32_t)0x00008000U)         /* !< LCD pin 15 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL0_LCDS15_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL0_LCDS15_SEL_LCD              ((uint32_t)0x00008000U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL0[LCDS2] Bits */
#define LCD_LCDPCTL0_LCDS2_OFS                   (2)                             /* !< LCDS2 Offset */
#define LCD_LCDPCTL0_LCDS2_MASK                  ((uint32_t)0x00000004U)         /* !< LCD pin 2 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL0_LCDS2_SEL_PORT              ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL0_LCDS2_SEL_LCD               ((uint32_t)0x00000004U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL0[LCDS3] Bits */
#define LCD_LCDPCTL0_LCDS3_OFS                   (3)                             /* !< LCDS3 Offset */
#define LCD_LCDPCTL0_LCDS3_MASK                  ((uint32_t)0x00000008U)         /* !< LCD pin 3 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL0_LCDS3_SEL_PORT              ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL0_LCDS3_SEL_LCD               ((uint32_t)0x00000008U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL0[LCDS4] Bits */
#define LCD_LCDPCTL0_LCDS4_OFS                   (4)                             /* !< LCDS4 Offset */
#define LCD_LCDPCTL0_LCDS4_MASK                  ((uint32_t)0x00000010U)         /* !< LCD pin 4 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL0_LCDS4_SEL_PORT              ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL0_LCDS4_SEL_LCD               ((uint32_t)0x00000010U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL0[LCDS5] Bits */
#define LCD_LCDPCTL0_LCDS5_OFS                   (5)                             /* !< LCDS5 Offset */
#define LCD_LCDPCTL0_LCDS5_MASK                  ((uint32_t)0x00000020U)         /* !< LCD pin 5 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL0_LCDS5_SEL_PORT              ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL0_LCDS5_SEL_LCD               ((uint32_t)0x00000020U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL0[LCDS6] Bits */
#define LCD_LCDPCTL0_LCDS6_OFS                   (6)                             /* !< LCDS6 Offset */
#define LCD_LCDPCTL0_LCDS6_MASK                  ((uint32_t)0x00000040U)         /* !< LCD pin 6 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL0_LCDS6_SEL_PORT              ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL0_LCDS6_SEL_LCD               ((uint32_t)0x00000040U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL0[LCDS7] Bits */
#define LCD_LCDPCTL0_LCDS7_OFS                   (7)                             /* !< LCDS7 Offset */
#define LCD_LCDPCTL0_LCDS7_MASK                  ((uint32_t)0x00000080U)         /* !< LCD pin 7 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL0_LCDS7_SEL_PORT              ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL0_LCDS7_SEL_LCD               ((uint32_t)0x00000080U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL0[LCDS8] Bits */
#define LCD_LCDPCTL0_LCDS8_OFS                   (8)                             /* !< LCDS8 Offset */
#define LCD_LCDPCTL0_LCDS8_MASK                  ((uint32_t)0x00000100U)         /* !< LCD pin 8 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL0_LCDS8_SEL_PORT              ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL0_LCDS8_SEL_LCD               ((uint32_t)0x00000100U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL0[LCDS9] Bits */
#define LCD_LCDPCTL0_LCDS9_OFS                   (9)                             /* !< LCDS9 Offset */
#define LCD_LCDPCTL0_LCDS9_MASK                  ((uint32_t)0x00000200U)         /* !< LCD pin 9 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL0_LCDS9_SEL_PORT              ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL0_LCDS9_SEL_LCD               ((uint32_t)0x00000200U)         /* !< Pins are LCD functions. */

/* LCD_LCDPCTL1 Bits */
/* LCD_LCDPCTL1[LCDS16] Bits */
#define LCD_LCDPCTL1_LCDS16_OFS                  (0)                             /* !< LCDS16 Offset */
#define LCD_LCDPCTL1_LCDS16_MASK                 ((uint32_t)0x00000001U)         /* !< LCD segment line 16 enable. This
                                                                                    bit affects only pins with
                                                                                    multiplexed functions.  Dedicated LCD
                                                                                    pins are always LCD function.  0b =
                                                                                    Multiplexed pins are port functions.
                                                                                    1b = Pins are LCD functions. */
#define LCD_LCDPCTL1_LCDS16_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL1_LCDS16_SEL_LCD              ((uint32_t)0x00000001U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL1[LCDS17] Bits */
#define LCD_LCDPCTL1_LCDS17_OFS                  (1)                             /* !< LCDS17 Offset */
#define LCD_LCDPCTL1_LCDS17_MASK                 ((uint32_t)0x00000002U)         /* !< LCD segment line 17 enable. This
                                                                                    bit affects only pins with
                                                                                    multiplexed functions.  Dedicated LCD
                                                                                    pins are always LCD function.  0b =
                                                                                    Multiplexed pins are port functions.
                                                                                    1b = Pins are LCD functions. */
#define LCD_LCDPCTL1_LCDS17_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL1_LCDS17_SEL_LCD              ((uint32_t)0x00000002U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL1[LCDS18] Bits */
#define LCD_LCDPCTL1_LCDS18_OFS                  (2)                             /* !< LCDS18 Offset */
#define LCD_LCDPCTL1_LCDS18_MASK                 ((uint32_t)0x00000004U)         /* !< LCD segment line 18 enable. This
                                                                                    bit affects only pins with
                                                                                    multiplexed functions.  Dedicated LCD
                                                                                    pins are always LCD function.  0b =
                                                                                    Multiplexed pins are port functions.
                                                                                    1b = Pins are LCD functions. */
#define LCD_LCDPCTL1_LCDS18_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL1_LCDS18_SEL_LCD              ((uint32_t)0x00000004U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL1[LCDS19] Bits */
#define LCD_LCDPCTL1_LCDS19_OFS                  (3)                             /* !< LCDS19 Offset */
#define LCD_LCDPCTL1_LCDS19_MASK                 ((uint32_t)0x00000008U)         /* !< LCD segment line 19 enable. This
                                                                                    bit affects only pins with
                                                                                    multiplexed functions.  Dedicated LCD
                                                                                    pins are always LCD function.  0b =
                                                                                    Multiplexed pins are port functions.
                                                                                    1b = Pins are LCD functions. */
#define LCD_LCDPCTL1_LCDS19_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL1_LCDS19_SEL_LCD              ((uint32_t)0x00000008U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL1[LCDS20] Bits */
#define LCD_LCDPCTL1_LCDS20_OFS                  (4)                             /* !< LCDS20 Offset */
#define LCD_LCDPCTL1_LCDS20_MASK                 ((uint32_t)0x00000010U)         /* !< LCD segment line 20 enable. This
                                                                                    bit affects only pins with
                                                                                    multiplexed functions.  Dedicated LCD
                                                                                    pins are always LCD function.  0b =
                                                                                    Multiplexed pins are port functions.
                                                                                    1b = Pins are LCD functions. */
#define LCD_LCDPCTL1_LCDS20_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL1_LCDS20_SEL_LCD              ((uint32_t)0x00000010U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL1[LCDS21] Bits */
#define LCD_LCDPCTL1_LCDS21_OFS                  (5)                             /* !< LCDS21 Offset */
#define LCD_LCDPCTL1_LCDS21_MASK                 ((uint32_t)0x00000020U)         /* !< LCD segment line 21 enable. This
                                                                                    bit affects only pins with
                                                                                    multiplexed functions.  Dedicated LCD
                                                                                    pins are always LCD function.  0b =
                                                                                    Multiplexed pins are port functions.
                                                                                    1b = Pins are LCD functions. */
#define LCD_LCDPCTL1_LCDS21_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL1_LCDS21_SEL_LCD              ((uint32_t)0x00000020U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL1[LCDS22] Bits */
#define LCD_LCDPCTL1_LCDS22_OFS                  (6)                             /* !< LCDS22 Offset */
#define LCD_LCDPCTL1_LCDS22_MASK                 ((uint32_t)0x00000040U)         /* !< LCD segment line 22 enable. This
                                                                                    bit affects only pins with
                                                                                    multiplexed functions.  Dedicated LCD
                                                                                    pins are always LCD function.  0b =
                                                                                    Multiplexed pins are port functions.
                                                                                    1b = Pins are LCD functions. */
#define LCD_LCDPCTL1_LCDS22_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL1_LCDS22_SEL_LCD              ((uint32_t)0x00000040U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL1[LCDS23] Bits */
#define LCD_LCDPCTL1_LCDS23_OFS                  (7)                             /* !< LCDS23 Offset */
#define LCD_LCDPCTL1_LCDS23_MASK                 ((uint32_t)0x00000080U)         /* !< LCD segment line 23 enable. This
                                                                                    bit affects only pins with
                                                                                    multiplexed functions.  Dedicated LCD
                                                                                    pins are always LCD function.  0b =
                                                                                    Multiplexed pins are port functions.
                                                                                    1b = Pins are LCD functions. */
#define LCD_LCDPCTL1_LCDS23_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL1_LCDS23_SEL_LCD              ((uint32_t)0x00000080U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL1[LCDS24] Bits */
#define LCD_LCDPCTL1_LCDS24_OFS                  (8)                             /* !< LCDS24 Offset */
#define LCD_LCDPCTL1_LCDS24_MASK                 ((uint32_t)0x00000100U)         /* !< LCD pin 24 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL1_LCDS24_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL1_LCDS24_SEL_LCD              ((uint32_t)0x00000100U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL1[LCDS25] Bits */
#define LCD_LCDPCTL1_LCDS25_OFS                  (9)                             /* !< LCDS25 Offset */
#define LCD_LCDPCTL1_LCDS25_MASK                 ((uint32_t)0x00000200U)         /* !< LCD pin 25 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL1_LCDS25_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL1_LCDS25_SEL_LCD              ((uint32_t)0x00000200U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL1[LCDS26] Bits */
#define LCD_LCDPCTL1_LCDS26_OFS                  (10)                            /* !< LCDS26 Offset */
#define LCD_LCDPCTL1_LCDS26_MASK                 ((uint32_t)0x00000400U)         /* !< LCD pin 26 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL1_LCDS26_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL1_LCDS26_SEL_LCD              ((uint32_t)0x00000400U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL1[LCDS27] Bits */
#define LCD_LCDPCTL1_LCDS27_OFS                  (11)                            /* !< LCDS27 Offset */
#define LCD_LCDPCTL1_LCDS27_MASK                 ((uint32_t)0x00000800U)         /* !< LCD pin 27 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL1_LCDS27_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL1_LCDS27_SEL_LCD              ((uint32_t)0x00000800U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL1[LCDS28] Bits */
#define LCD_LCDPCTL1_LCDS28_OFS                  (12)                            /* !< LCDS28 Offset */
#define LCD_LCDPCTL1_LCDS28_MASK                 ((uint32_t)0x00001000U)         /* !< LCD pin 28 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL1_LCDS28_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL1_LCDS28_SEL_LCD              ((uint32_t)0x00001000U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL1[LCDS29] Bits */
#define LCD_LCDPCTL1_LCDS29_OFS                  (13)                            /* !< LCDS29 Offset */
#define LCD_LCDPCTL1_LCDS29_MASK                 ((uint32_t)0x00002000U)         /* !< LCD pin 29 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL1_LCDS29_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL1_LCDS29_SEL_LCD              ((uint32_t)0x00002000U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL1[LCDS30] Bits */
#define LCD_LCDPCTL1_LCDS30_OFS                  (14)                            /* !< LCDS30 Offset */
#define LCD_LCDPCTL1_LCDS30_MASK                 ((uint32_t)0x00004000U)         /* !< LCD pin 30 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL1_LCDS30_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL1_LCDS30_SEL_LCD              ((uint32_t)0x00004000U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL1[LCDS31] Bits */
#define LCD_LCDPCTL1_LCDS31_OFS                  (15)                            /* !< LCDS31 Offset */
#define LCD_LCDPCTL1_LCDS31_MASK                 ((uint32_t)0x00008000U)         /* !< LCD pin 31 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL1_LCDS31_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL1_LCDS31_SEL_LCD              ((uint32_t)0x00008000U)         /* !< Pins are LCD functions. */

/* LCD_LCDPCTL2 Bits */
/* LCD_LCDPCTL2[LCDS32] Bits */
#define LCD_LCDPCTL2_LCDS32_OFS                  (0)                             /* !< LCDS32 Offset */
#define LCD_LCDPCTL2_LCDS32_MASK                 ((uint32_t)0x00000001U)         /* !< LCD pin 32 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL2_LCDS32_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL2_LCDS32_SEL_LCD              ((uint32_t)0x00000001U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL2[LCDS33] Bits */
#define LCD_LCDPCTL2_LCDS33_OFS                  (1)                             /* !< LCDS33 Offset */
#define LCD_LCDPCTL2_LCDS33_MASK                 ((uint32_t)0x00000002U)         /* !< LCD pin 33 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL2_LCDS33_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL2_LCDS33_SEL_LCD              ((uint32_t)0x00000002U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL2[LCDS34] Bits */
#define LCD_LCDPCTL2_LCDS34_OFS                  (2)                             /* !< LCDS34 Offset */
#define LCD_LCDPCTL2_LCDS34_MASK                 ((uint32_t)0x00000004U)         /* !< LCD pin 34 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL2_LCDS34_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL2_LCDS34_SEL_LCD              ((uint32_t)0x00000004U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL2[LCDS35] Bits */
#define LCD_LCDPCTL2_LCDS35_OFS                  (3)                             /* !< LCDS35 Offset */
#define LCD_LCDPCTL2_LCDS35_MASK                 ((uint32_t)0x00000008U)         /* !< LCD pin 35 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL2_LCDS35_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL2_LCDS35_SEL_LCD              ((uint32_t)0x00000008U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL2[LCDS36] Bits */
#define LCD_LCDPCTL2_LCDS36_OFS                  (4)                             /* !< LCDS36 Offset */
#define LCD_LCDPCTL2_LCDS36_MASK                 ((uint32_t)0x00000010U)         /* !< LCD pin 36 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL2_LCDS36_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL2_LCDS36_SEL_LCD              ((uint32_t)0x00000010U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL2[LCDS37] Bits */
#define LCD_LCDPCTL2_LCDS37_OFS                  (5)                             /* !< LCDS37 Offset */
#define LCD_LCDPCTL2_LCDS37_MASK                 ((uint32_t)0x00000020U)         /* !< LCD pin 37 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL2_LCDS37_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL2_LCDS37_SEL_LCD              ((uint32_t)0x00000020U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL2[LCDS38] Bits */
#define LCD_LCDPCTL2_LCDS38_OFS                  (6)                             /* !< LCDS38 Offset */
#define LCD_LCDPCTL2_LCDS38_MASK                 ((uint32_t)0x00000040U)         /* !< LCD pin 38 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL2_LCDS38_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL2_LCDS38_SEL_LCD              ((uint32_t)0x00000040U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL2[LCDS39] Bits */
#define LCD_LCDPCTL2_LCDS39_OFS                  (7)                             /* !< LCDS39 Offset */
#define LCD_LCDPCTL2_LCDS39_MASK                 ((uint32_t)0x00000080U)         /* !< LCD pin 39 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL2_LCDS39_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL2_LCDS39_SEL_LCD              ((uint32_t)0x00000080U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL2[LCDS40] Bits */
#define LCD_LCDPCTL2_LCDS40_OFS                  (8)                             /* !< LCDS40 Offset */
#define LCD_LCDPCTL2_LCDS40_MASK                 ((uint32_t)0x00000100U)         /* !< LCD pin 40 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL2_LCDS40_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL2_LCDS40_SEL_LCD              ((uint32_t)0x00000100U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL2[LCDS41] Bits */
#define LCD_LCDPCTL2_LCDS41_OFS                  (9)                             /* !< LCDS41 Offset */
#define LCD_LCDPCTL2_LCDS41_MASK                 ((uint32_t)0x00000200U)         /* !< LCD pin 41 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL2_LCDS41_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL2_LCDS41_SEL_LCD              ((uint32_t)0x00000200U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL2[LCDS42] Bits */
#define LCD_LCDPCTL2_LCDS42_OFS                  (10)                            /* !< LCDS42 Offset */
#define LCD_LCDPCTL2_LCDS42_MASK                 ((uint32_t)0x00000400U)         /* !< LCD pin 42 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL2_LCDS42_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL2_LCDS42_SEL_LCD              ((uint32_t)0x00000400U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL2[LCDS43] Bits */
#define LCD_LCDPCTL2_LCDS43_OFS                  (11)                            /* !< LCDS43 Offset */
#define LCD_LCDPCTL2_LCDS43_MASK                 ((uint32_t)0x00000800U)         /* !< LCD pin 43 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL2_LCDS43_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL2_LCDS43_SEL_LCD              ((uint32_t)0x00000800U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL2[LCDS44] Bits */
#define LCD_LCDPCTL2_LCDS44_OFS                  (12)                            /* !< LCDS44 Offset */
#define LCD_LCDPCTL2_LCDS44_MASK                 ((uint32_t)0x00001000U)         /* !< LCD pin 44 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL2_LCDS44_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL2_LCDS44_SEL_LCD              ((uint32_t)0x00001000U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL2[LCDS45] Bits */
#define LCD_LCDPCTL2_LCDS45_OFS                  (13)                            /* !< LCDS45 Offset */
#define LCD_LCDPCTL2_LCDS45_MASK                 ((uint32_t)0x00002000U)         /* !< LCD pin 45 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL2_LCDS45_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL2_LCDS45_SEL_LCD              ((uint32_t)0x00002000U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL2[LCDS46] Bits */
#define LCD_LCDPCTL2_LCDS46_OFS                  (14)                            /* !< LCDS46 Offset */
#define LCD_LCDPCTL2_LCDS46_MASK                 ((uint32_t)0x00004000U)         /* !< LCD pin 46 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL2_LCDS46_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL2_LCDS46_SEL_LCD              ((uint32_t)0x00004000U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL2[LCDS47] Bits */
#define LCD_LCDPCTL2_LCDS47_OFS                  (15)                            /* !< LCDS47 Offset */
#define LCD_LCDPCTL2_LCDS47_MASK                 ((uint32_t)0x00008000U)         /* !< LCD pin 47 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL2_LCDS47_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL2_LCDS47_SEL_LCD              ((uint32_t)0x00008000U)         /* !< Pins are LCD functions. */

/* LCD_LCDPCTL3 Bits */
/* LCD_LCDPCTL3[LCDS48] Bits */
#define LCD_LCDPCTL3_LCDS48_OFS                  (0)                             /* !< LCDS48 Offset */
#define LCD_LCDPCTL3_LCDS48_MASK                 ((uint32_t)0x00000001U)         /* !< LCD pin 48 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL3_LCDS48_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL3_LCDS48_SEL_LCD              ((uint32_t)0x00000001U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL3[LCDS49] Bits */
#define LCD_LCDPCTL3_LCDS49_OFS                  (1)                             /* !< LCDS49 Offset */
#define LCD_LCDPCTL3_LCDS49_MASK                 ((uint32_t)0x00000002U)         /* !< LCD pin 49 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL3_LCDS49_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL3_LCDS49_SEL_LCD              ((uint32_t)0x00000002U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL3[LCDS50] Bits */
#define LCD_LCDPCTL3_LCDS50_OFS                  (2)                             /* !< LCDS50 Offset */
#define LCD_LCDPCTL3_LCDS50_MASK                 ((uint32_t)0x00000004U)         /* !< LCD pin 50 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL3_LCDS50_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL3_LCDS50_SEL_LCD              ((uint32_t)0x00000004U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL3[LCDS51] Bits */
#define LCD_LCDPCTL3_LCDS51_OFS                  (3)                             /* !< LCDS51 Offset */
#define LCD_LCDPCTL3_LCDS51_MASK                 ((uint32_t)0x00000008U)         /* !< LCD pin 51 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL3_LCDS51_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL3_LCDS51_SEL_LCD              ((uint32_t)0x00000008U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL3[LCDS52] Bits */
#define LCD_LCDPCTL3_LCDS52_OFS                  (4)                             /* !< LCDS52 Offset */
#define LCD_LCDPCTL3_LCDS52_MASK                 ((uint32_t)0x00000010U)         /* !< LCD pin 52 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL3_LCDS52_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL3_LCDS52_SEL_LCD              ((uint32_t)0x00000010U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL3[LCDS53] Bits */
#define LCD_LCDPCTL3_LCDS53_OFS                  (5)                             /* !< LCDS53 Offset */
#define LCD_LCDPCTL3_LCDS53_MASK                 ((uint32_t)0x00000020U)         /* !< LCD pin 53 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL3_LCDS53_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL3_LCDS53_SEL_LCD              ((uint32_t)0x00000020U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL3[LCDS54] Bits */
#define LCD_LCDPCTL3_LCDS54_OFS                  (6)                             /* !< LCDS54 Offset */
#define LCD_LCDPCTL3_LCDS54_MASK                 ((uint32_t)0x00000040U)         /* !< LCD pin 54 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL3_LCDS54_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL3_LCDS54_SEL_LCD              ((uint32_t)0x00000040U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL3[LCDS55] Bits */
#define LCD_LCDPCTL3_LCDS55_OFS                  (7)                             /* !< LCDS55 Offset */
#define LCD_LCDPCTL3_LCDS55_MASK                 ((uint32_t)0x00000080U)         /* !< LCD pin 55 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL3_LCDS55_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL3_LCDS55_SEL_LCD              ((uint32_t)0x00000080U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL3[LCDS56] Bits */
#define LCD_LCDPCTL3_LCDS56_OFS                  (8)                             /* !< LCDS56 Offset */
#define LCD_LCDPCTL3_LCDS56_MASK                 ((uint32_t)0x00000100U)         /* !< LCD pin 56 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL3_LCDS56_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL3_LCDS56_SEL_LCD              ((uint32_t)0x00000100U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL3[LCDS57] Bits */
#define LCD_LCDPCTL3_LCDS57_OFS                  (9)                             /* !< LCDS57 Offset */
#define LCD_LCDPCTL3_LCDS57_MASK                 ((uint32_t)0x00000200U)         /* !< LCD pin 57 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL3_LCDS57_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL3_LCDS57_SEL_LCD              ((uint32_t)0x00000200U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL3[LCDS58] Bits */
#define LCD_LCDPCTL3_LCDS58_OFS                  (10)                            /* !< LCDS58 Offset */
#define LCD_LCDPCTL3_LCDS58_MASK                 ((uint32_t)0x00000400U)         /* !< LCD pin 58 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL3_LCDS58_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL3_LCDS58_SEL_LCD              ((uint32_t)0x00000400U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL3[LCDS59] Bits */
#define LCD_LCDPCTL3_LCDS59_OFS                  (11)                            /* !< LCDS59 Offset */
#define LCD_LCDPCTL3_LCDS59_MASK                 ((uint32_t)0x00000800U)         /* !< LCD pin 59 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL3_LCDS59_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL3_LCDS59_SEL_LCD              ((uint32_t)0x00000800U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL3[LCDS60] Bits */
#define LCD_LCDPCTL3_LCDS60_OFS                  (12)                            /* !< LCDS60 Offset */
#define LCD_LCDPCTL3_LCDS60_MASK                 ((uint32_t)0x00001000U)         /* !< LCD pin 60 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL3_LCDS60_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL3_LCDS60_SEL_LCD              ((uint32_t)0x00001000U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL3[LCDS61] Bits */
#define LCD_LCDPCTL3_LCDS61_OFS                  (13)                            /* !< LCDS61 Offset */
#define LCD_LCDPCTL3_LCDS61_MASK                 ((uint32_t)0x00002000U)         /* !< LCD pin 61 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL3_LCDS61_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL3_LCDS61_SEL_LCD              ((uint32_t)0x00002000U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL3[LCDS62] Bits */
#define LCD_LCDPCTL3_LCDS62_OFS                  (14)                            /* !< LCDS62 Offset */
#define LCD_LCDPCTL3_LCDS62_MASK                 ((uint32_t)0x00004000U)         /* !< LCD pin 62 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL3_LCDS62_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL3_LCDS62_SEL_LCD              ((uint32_t)0x00004000U)         /* !< Pins are LCD functions. */
/* LCD_LCDPCTL3[LCDS63] Bits */
#define LCD_LCDPCTL3_LCDS63_OFS                  (15)                            /* !< LCDS63 Offset */
#define LCD_LCDPCTL3_LCDS63_MASK                 ((uint32_t)0x00008000U)         /* !< LCD pin 63 enable. This bit affects
                                                                                    only pins with multiplexed functions.
                                                                                    Dedicated LCD pins are always LCD
                                                                                    function.  0b = Multiplexed pins are
                                                                                    port functions.  1b = Pins are LCD
                                                                                    functions. */
#define LCD_LCDPCTL3_LCDS63_SEL_PORT             ((uint32_t)0x00000000U)         /* !< Multiplexed pins are port
                                                                                    functions. */
#define LCD_LCDPCTL3_LCDS63_SEL_LCD              ((uint32_t)0x00008000U)         /* !< Pins are LCD functions. */

/* LCD_LCDCSSEL0 Bits */
/* LCD_LCDCSSEL0[LCDCSS0] Bits */
#define LCD_LCDCSSEL0_LCDCSS0_OFS                (0)                             /* !< LCDCSS0 Offset */
#define LCD_LCDCSSEL0_LCDCSS0_MASK               ((uint32_t)0x00000001U)         /* !< Selects pin L0 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL0_LCDCSS0_SEL_SEG            ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL0_LCDCSS0_SEL_COM            ((uint32_t)0x00000001U)         /* !< Common line */
/* LCD_LCDCSSEL0[LCDCSS1] Bits */
#define LCD_LCDCSSEL0_LCDCSS1_OFS                (1)                             /* !< LCDCSS1 Offset */
#define LCD_LCDCSSEL0_LCDCSS1_MASK               ((uint32_t)0x00000002U)         /* !< Selects pin L1 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL0_LCDCSS1_SEL_SEG            ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL0_LCDCSS1_SEL_COM            ((uint32_t)0x00000002U)         /* !< Common line */
/* LCD_LCDCSSEL0[LCDCSS10] Bits */
#define LCD_LCDCSSEL0_LCDCSS10_OFS               (10)                            /* !< LCDCSS10 Offset */
#define LCD_LCDCSSEL0_LCDCSS10_MASK              ((uint32_t)0x00000400U)         /* !< Selects pin L10 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL0_LCDCSS10_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL0_LCDCSS10_SEL_COM           ((uint32_t)0x00000400U)         /* !< Common line */
/* LCD_LCDCSSEL0[LCDCSS11] Bits */
#define LCD_LCDCSSEL0_LCDCSS11_OFS               (11)                            /* !< LCDCSS11 Offset */
#define LCD_LCDCSSEL0_LCDCSS11_MASK              ((uint32_t)0x00000800U)         /* !< Selects pin L11 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL0_LCDCSS11_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL0_LCDCSS11_SEL_COM           ((uint32_t)0x00000800U)         /* !< Common line */
/* LCD_LCDCSSEL0[LCDCSS12] Bits */
#define LCD_LCDCSSEL0_LCDCSS12_OFS               (12)                            /* !< LCDCSS12 Offset */
#define LCD_LCDCSSEL0_LCDCSS12_MASK              ((uint32_t)0x00001000U)         /* !< Selects pin L12 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL0_LCDCSS12_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL0_LCDCSS12_SEL_COM           ((uint32_t)0x00001000U)         /* !< Common line */
/* LCD_LCDCSSEL0[LCDCSS13] Bits */
#define LCD_LCDCSSEL0_LCDCSS13_OFS               (13)                            /* !< LCDCSS13 Offset */
#define LCD_LCDCSSEL0_LCDCSS13_MASK              ((uint32_t)0x00002000U)         /* !< Selects pin L13 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL0_LCDCSS13_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL0_LCDCSS13_SEL_COM           ((uint32_t)0x00002000U)         /* !< Common line */
/* LCD_LCDCSSEL0[LCDCSS14] Bits */
#define LCD_LCDCSSEL0_LCDCSS14_OFS               (14)                            /* !< LCDCSS14 Offset */
#define LCD_LCDCSSEL0_LCDCSS14_MASK              ((uint32_t)0x00004000U)         /* !< Selects pin L14 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL0_LCDCSS14_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL0_LCDCSS14_SEL_COM           ((uint32_t)0x00004000U)         /* !< Common line */
/* LCD_LCDCSSEL0[LCDCSS15] Bits */
#define LCD_LCDCSSEL0_LCDCSS15_OFS               (15)                            /* !< LCDCSS15 Offset */
#define LCD_LCDCSSEL0_LCDCSS15_MASK              ((uint32_t)0x00008000U)         /* !< Selects pin L15 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL0_LCDCSS15_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL0_LCDCSS15_SEL_COM           ((uint32_t)0x00008000U)         /* !< Common line */
/* LCD_LCDCSSEL0[LCDCSS2] Bits */
#define LCD_LCDCSSEL0_LCDCSS2_OFS                (2)                             /* !< LCDCSS2 Offset */
#define LCD_LCDCSSEL0_LCDCSS2_MASK               ((uint32_t)0x00000004U)         /* !< Selects pin L2 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL0_LCDCSS2_SEL_SEG            ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL0_LCDCSS2_SEL_COM            ((uint32_t)0x00000004U)         /* !< Common line */
/* LCD_LCDCSSEL0[LCDCSS3] Bits */
#define LCD_LCDCSSEL0_LCDCSS3_OFS                (3)                             /* !< LCDCSS3 Offset */
#define LCD_LCDCSSEL0_LCDCSS3_MASK               ((uint32_t)0x00000008U)         /* !< Selects pin L3 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL0_LCDCSS3_SEL_SEG            ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL0_LCDCSS3_SEL_COM            ((uint32_t)0x00000008U)         /* !< Common line */
/* LCD_LCDCSSEL0[LCDCSS4] Bits */
#define LCD_LCDCSSEL0_LCDCSS4_OFS                (4)                             /* !< LCDCSS4 Offset */
#define LCD_LCDCSSEL0_LCDCSS4_MASK               ((uint32_t)0x00000010U)         /* !< Selects pin L4 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL0_LCDCSS4_SEL_SEG            ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL0_LCDCSS4_SEL_COM            ((uint32_t)0x00000010U)         /* !< Common line */
/* LCD_LCDCSSEL0[LCDCSS5] Bits */
#define LCD_LCDCSSEL0_LCDCSS5_OFS                (5)                             /* !< LCDCSS5 Offset */
#define LCD_LCDCSSEL0_LCDCSS5_MASK               ((uint32_t)0x00000020U)         /* !< Selects pin L5 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL0_LCDCSS5_SEL_SEG            ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL0_LCDCSS5_SEL_COM            ((uint32_t)0x00000020U)         /* !< Common line */
/* LCD_LCDCSSEL0[LCDCSS6] Bits */
#define LCD_LCDCSSEL0_LCDCSS6_OFS                (6)                             /* !< LCDCSS6 Offset */
#define LCD_LCDCSSEL0_LCDCSS6_MASK               ((uint32_t)0x00000040U)         /* !< Selects pin L6 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL0_LCDCSS6_SEL_SEG            ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL0_LCDCSS6_SEL_COM            ((uint32_t)0x00000040U)         /* !< Common line */
/* LCD_LCDCSSEL0[LCDCSS7] Bits */
#define LCD_LCDCSSEL0_LCDCSS7_OFS                (7)                             /* !< LCDCSS7 Offset */
#define LCD_LCDCSSEL0_LCDCSS7_MASK               ((uint32_t)0x00000080U)         /* !< Selects pin L7 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL0_LCDCSS7_SEL_SEG            ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL0_LCDCSS7_SEL_COM            ((uint32_t)0x00000080U)         /* !< Common line */
/* LCD_LCDCSSEL0[LCDCSS8] Bits */
#define LCD_LCDCSSEL0_LCDCSS8_OFS                (8)                             /* !< LCDCSS8 Offset */
#define LCD_LCDCSSEL0_LCDCSS8_MASK               ((uint32_t)0x00000100U)         /* !< Selects pin L8 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL0_LCDCSS8_SEL_SEG            ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL0_LCDCSS8_SEL_COM            ((uint32_t)0x00000100U)         /* !< Common line */
/* LCD_LCDCSSEL0[LCDCSS9] Bits */
#define LCD_LCDCSSEL0_LCDCSS9_OFS                (9)                             /* !< LCDCSS9 Offset */
#define LCD_LCDCSSEL0_LCDCSS9_MASK               ((uint32_t)0x00000200U)         /* !< Selects pin L9 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL0_LCDCSS9_SEL_SEG            ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL0_LCDCSS9_SEL_COM            ((uint32_t)0x00000200U)         /* !< Common line */

/* LCD_LCDCSSEL1 Bits */
/* LCD_LCDCSSEL1[LCDCSS16] Bits */
#define LCD_LCDCSSEL1_LCDCSS16_OFS               (0)                             /* !< LCDCSS16 Offset */
#define LCD_LCDCSSEL1_LCDCSS16_MASK              ((uint32_t)0x00000001U)         /* !< Selects pin L16 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL1_LCDCSS16_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL1_LCDCSS16_SEL_COM           ((uint32_t)0x00000001U)         /* !< Common line */
/* LCD_LCDCSSEL1[LCDCSS17] Bits */
#define LCD_LCDCSSEL1_LCDCSS17_OFS               (1)                             /* !< LCDCSS17 Offset */
#define LCD_LCDCSSEL1_LCDCSS17_MASK              ((uint32_t)0x00000002U)         /* !< Selects pin L17 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL1_LCDCSS17_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL1_LCDCSS17_SEL_COM           ((uint32_t)0x00000002U)         /* !< Common line */
/* LCD_LCDCSSEL1[LCDCSS18] Bits */
#define LCD_LCDCSSEL1_LCDCSS18_OFS               (2)                             /* !< LCDCSS18 Offset */
#define LCD_LCDCSSEL1_LCDCSS18_MASK              ((uint32_t)0x00000004U)         /* !< Selects pin L18 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL1_LCDCSS18_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL1_LCDCSS18_SEL_COM           ((uint32_t)0x00000004U)         /* !< Common line */
/* LCD_LCDCSSEL1[LCDCSS19] Bits */
#define LCD_LCDCSSEL1_LCDCSS19_OFS               (3)                             /* !< LCDCSS19 Offset */
#define LCD_LCDCSSEL1_LCDCSS19_MASK              ((uint32_t)0x00000008U)         /* !< Selects pin L19 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL1_LCDCSS19_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL1_LCDCSS19_SEL_COM           ((uint32_t)0x00000008U)         /* !< Common line */
/* LCD_LCDCSSEL1[LCDCSS20] Bits */
#define LCD_LCDCSSEL1_LCDCSS20_OFS               (4)                             /* !< LCDCSS20 Offset */
#define LCD_LCDCSSEL1_LCDCSS20_MASK              ((uint32_t)0x00000010U)         /* !< Selects pin L20 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL1_LCDCSS20_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL1_LCDCSS20_SEL_COM           ((uint32_t)0x00000010U)         /* !< Common line */
/* LCD_LCDCSSEL1[LCDCSS21] Bits */
#define LCD_LCDCSSEL1_LCDCSS21_OFS               (5)                             /* !< LCDCSS21 Offset */
#define LCD_LCDCSSEL1_LCDCSS21_MASK              ((uint32_t)0x00000020U)         /* !< Selects pin L21 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL1_LCDCSS21_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL1_LCDCSS21_SEL_COM           ((uint32_t)0x00000020U)         /* !< Common line */
/* LCD_LCDCSSEL1[LCDCSS22] Bits */
#define LCD_LCDCSSEL1_LCDCSS22_OFS               (6)                             /* !< LCDCSS22 Offset */
#define LCD_LCDCSSEL1_LCDCSS22_MASK              ((uint32_t)0x00000040U)         /* !< Selects pin L22 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL1_LCDCSS22_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL1_LCDCSS22_SEL_COM           ((uint32_t)0x00000040U)         /* !< Common line */
/* LCD_LCDCSSEL1[LCDCSS23] Bits */
#define LCD_LCDCSSEL1_LCDCSS23_OFS               (7)                             /* !< LCDCSS23 Offset */
#define LCD_LCDCSSEL1_LCDCSS23_MASK              ((uint32_t)0x00000080U)         /* !< Selects pin L23 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL1_LCDCSS23_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL1_LCDCSS23_SEL_COM           ((uint32_t)0x00000080U)         /* !< Common line */
/* LCD_LCDCSSEL1[LCDCSS24] Bits */
#define LCD_LCDCSSEL1_LCDCSS24_OFS               (8)                             /* !< LCDCSS24 Offset */
#define LCD_LCDCSSEL1_LCDCSS24_MASK              ((uint32_t)0x00000100U)         /* !< Selects pin L24 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL1_LCDCSS24_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL1_LCDCSS24_SEL_COM           ((uint32_t)0x00000100U)         /* !< Common line */
/* LCD_LCDCSSEL1[LCDCSS25] Bits */
#define LCD_LCDCSSEL1_LCDCSS25_OFS               (9)                             /* !< LCDCSS25 Offset */
#define LCD_LCDCSSEL1_LCDCSS25_MASK              ((uint32_t)0x00000200U)         /* !< Selects pin L25 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL1_LCDCSS25_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL1_LCDCSS25_SEL_COM           ((uint32_t)0x00000200U)         /* !< Common line */
/* LCD_LCDCSSEL1[LCDCSS26] Bits */
#define LCD_LCDCSSEL1_LCDCSS26_OFS               (10)                            /* !< LCDCSS26 Offset */
#define LCD_LCDCSSEL1_LCDCSS26_MASK              ((uint32_t)0x00000400U)         /* !< Selects pin L26 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL1_LCDCSS26_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL1_LCDCSS26_SEL_COM           ((uint32_t)0x00000400U)         /* !< Common line */
/* LCD_LCDCSSEL1[LCDCSS27] Bits */
#define LCD_LCDCSSEL1_LCDCSS27_OFS               (11)                            /* !< LCDCSS27 Offset */
#define LCD_LCDCSSEL1_LCDCSS27_MASK              ((uint32_t)0x00000800U)         /* !< Selects pin L27 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL1_LCDCSS27_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL1_LCDCSS27_SEL_COM           ((uint32_t)0x00000800U)         /* !< Common line */
/* LCD_LCDCSSEL1[LCDCSS28] Bits */
#define LCD_LCDCSSEL1_LCDCSS28_OFS               (12)                            /* !< LCDCSS28 Offset */
#define LCD_LCDCSSEL1_LCDCSS28_MASK              ((uint32_t)0x00001000U)         /* !< Selects pin L28 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL1_LCDCSS28_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL1_LCDCSS28_SEL_COM           ((uint32_t)0x00001000U)         /* !< Common line */
/* LCD_LCDCSSEL1[LCDCSS29] Bits */
#define LCD_LCDCSSEL1_LCDCSS29_OFS               (13)                            /* !< LCDCSS29 Offset */
#define LCD_LCDCSSEL1_LCDCSS29_MASK              ((uint32_t)0x00002000U)         /* !< Selects pin L29 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL1_LCDCSS29_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL1_LCDCSS29_SEL_COM           ((uint32_t)0x00002000U)         /* !< Common line */
/* LCD_LCDCSSEL1[LCDCSS30] Bits */
#define LCD_LCDCSSEL1_LCDCSS30_OFS               (14)                            /* !< LCDCSS30 Offset */
#define LCD_LCDCSSEL1_LCDCSS30_MASK              ((uint32_t)0x00004000U)         /* !< Selects pin L30 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL1_LCDCSS30_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL1_LCDCSS30_SEL_COM           ((uint32_t)0x00004000U)         /* !< Common line */
/* LCD_LCDCSSEL1[LCDCSS31] Bits */
#define LCD_LCDCSSEL1_LCDCSS31_OFS               (15)                            /* !< LCDCSS31 Offset */
#define LCD_LCDCSSEL1_LCDCSS31_MASK              ((uint32_t)0x00008000U)         /* !< Selects pin L31 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL1_LCDCSS31_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL1_LCDCSS31_SEL_COM           ((uint32_t)0x00008000U)         /* !< Common line */

/* LCD_LCDCSSEL2 Bits */
/* LCD_LCDCSSEL2[LCDCSS32] Bits */
#define LCD_LCDCSSEL2_LCDCSS32_OFS               (0)                             /* !< LCDCSS32 Offset */
#define LCD_LCDCSSEL2_LCDCSS32_MASK              ((uint32_t)0x00000001U)         /* !< Selects pin L32 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL2_LCDCSS32_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL2_LCDCSS32_SEL_COM           ((uint32_t)0x00000001U)         /* !< Common line */
/* LCD_LCDCSSEL2[LCDCSS33] Bits */
#define LCD_LCDCSSEL2_LCDCSS33_OFS               (1)                             /* !< LCDCSS33 Offset */
#define LCD_LCDCSSEL2_LCDCSS33_MASK              ((uint32_t)0x00000002U)         /* !< Selects pin L33 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL2_LCDCSS33_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL2_LCDCSS33_SEL_COM           ((uint32_t)0x00000002U)         /* !< Common line */
/* LCD_LCDCSSEL2[LCDCSS34] Bits */
#define LCD_LCDCSSEL2_LCDCSS34_OFS               (2)                             /* !< LCDCSS34 Offset */
#define LCD_LCDCSSEL2_LCDCSS34_MASK              ((uint32_t)0x00000004U)         /* !< Selects pin L34 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL2_LCDCSS34_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL2_LCDCSS34_SEL_COM           ((uint32_t)0x00000004U)         /* !< Common line */
/* LCD_LCDCSSEL2[LCDCSS35] Bits */
#define LCD_LCDCSSEL2_LCDCSS35_OFS               (3)                             /* !< LCDCSS35 Offset */
#define LCD_LCDCSSEL2_LCDCSS35_MASK              ((uint32_t)0x00000008U)         /* !< Selects pin L35 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL2_LCDCSS35_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL2_LCDCSS35_SEL_COM           ((uint32_t)0x00000008U)         /* !< Common line */
/* LCD_LCDCSSEL2[LCDCSS36] Bits */
#define LCD_LCDCSSEL2_LCDCSS36_OFS               (4)                             /* !< LCDCSS36 Offset */
#define LCD_LCDCSSEL2_LCDCSS36_MASK              ((uint32_t)0x00000010U)         /* !< Selects pin L36 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL2_LCDCSS36_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL2_LCDCSS36_SEL_COM           ((uint32_t)0x00000010U)         /* !< Common line */
/* LCD_LCDCSSEL2[LCDCSS37] Bits */
#define LCD_LCDCSSEL2_LCDCSS37_OFS               (5)                             /* !< LCDCSS37 Offset */
#define LCD_LCDCSSEL2_LCDCSS37_MASK              ((uint32_t)0x00000020U)         /* !< Selects pin L37 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL2_LCDCSS37_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL2_LCDCSS37_SEL_COM           ((uint32_t)0x00000020U)         /* !< Common line */
/* LCD_LCDCSSEL2[LCDCSS38] Bits */
#define LCD_LCDCSSEL2_LCDCSS38_OFS               (6)                             /* !< LCDCSS38 Offset */
#define LCD_LCDCSSEL2_LCDCSS38_MASK              ((uint32_t)0x00000040U)         /* !< Selects pin L38 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL2_LCDCSS38_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL2_LCDCSS38_SEL_COM           ((uint32_t)0x00000040U)         /* !< Common line */
/* LCD_LCDCSSEL2[LCDCSS39] Bits */
#define LCD_LCDCSSEL2_LCDCSS39_OFS               (7)                             /* !< LCDCSS39 Offset */
#define LCD_LCDCSSEL2_LCDCSS39_MASK              ((uint32_t)0x00000080U)         /* !< Selects pin L39 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL2_LCDCSS39_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL2_LCDCSS39_SEL_COM           ((uint32_t)0x00000080U)         /* !< Common line */
/* LCD_LCDCSSEL2[LCDCSS40] Bits */
#define LCD_LCDCSSEL2_LCDCSS40_OFS               (8)                             /* !< LCDCSS40 Offset */
#define LCD_LCDCSSEL2_LCDCSS40_MASK              ((uint32_t)0x00000100U)         /* !< Selects pin L40 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL2_LCDCSS40_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL2_LCDCSS40_SEL_COM           ((uint32_t)0x00000100U)         /* !< Common line */
/* LCD_LCDCSSEL2[LCDCSS41] Bits */
#define LCD_LCDCSSEL2_LCDCSS41_OFS               (9)                             /* !< LCDCSS41 Offset */
#define LCD_LCDCSSEL2_LCDCSS41_MASK              ((uint32_t)0x00000200U)         /* !< Selects pin L41 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL2_LCDCSS41_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL2_LCDCSS41_SEL_COM           ((uint32_t)0x00000200U)         /* !< Common line */
/* LCD_LCDCSSEL2[LCDCSS42] Bits */
#define LCD_LCDCSSEL2_LCDCSS42_OFS               (10)                            /* !< LCDCSS42 Offset */
#define LCD_LCDCSSEL2_LCDCSS42_MASK              ((uint32_t)0x00000400U)         /* !< Selects pin L42 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL2_LCDCSS42_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL2_LCDCSS42_SEL_COM           ((uint32_t)0x00000400U)         /* !< Common line */
/* LCD_LCDCSSEL2[LCDCSS43] Bits */
#define LCD_LCDCSSEL2_LCDCSS43_OFS               (11)                            /* !< LCDCSS43 Offset */
#define LCD_LCDCSSEL2_LCDCSS43_MASK              ((uint32_t)0x00000800U)         /* !< Selects pin L43 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL2_LCDCSS43_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL2_LCDCSS43_SEL_COM           ((uint32_t)0x00000800U)         /* !< Common line */
/* LCD_LCDCSSEL2[LCDCSS44] Bits */
#define LCD_LCDCSSEL2_LCDCSS44_OFS               (12)                            /* !< LCDCSS44 Offset */
#define LCD_LCDCSSEL2_LCDCSS44_MASK              ((uint32_t)0x00001000U)         /* !< Selects pin L44 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL2_LCDCSS44_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL2_LCDCSS44_SEL_COM           ((uint32_t)0x00001000U)         /* !< Common line */
/* LCD_LCDCSSEL2[LCDCSS45] Bits */
#define LCD_LCDCSSEL2_LCDCSS45_OFS               (13)                            /* !< LCDCSS45 Offset */
#define LCD_LCDCSSEL2_LCDCSS45_MASK              ((uint32_t)0x00002000U)         /* !< Selects pin L45 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL2_LCDCSS45_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL2_LCDCSS45_SEL_COM           ((uint32_t)0x00002000U)         /* !< Common line */
/* LCD_LCDCSSEL2[LCDCSS46] Bits */
#define LCD_LCDCSSEL2_LCDCSS46_OFS               (14)                            /* !< LCDCSS46 Offset */
#define LCD_LCDCSSEL2_LCDCSS46_MASK              ((uint32_t)0x00004000U)         /* !< Selects pin L46 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL2_LCDCSS46_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL2_LCDCSS46_SEL_COM           ((uint32_t)0x00004000U)         /* !< Common line */
/* LCD_LCDCSSEL2[LCDCSS47] Bits */
#define LCD_LCDCSSEL2_LCDCSS47_OFS               (15)                            /* !< LCDCSS47 Offset */
#define LCD_LCDCSSEL2_LCDCSS47_MASK              ((uint32_t)0x00008000U)         /* !< Selects pin L47 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL2_LCDCSS47_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL2_LCDCSS47_SEL_COM           ((uint32_t)0x00008000U)         /* !< Common line */

/* LCD_LCDCSSEL3 Bits */
/* LCD_LCDCSSEL3[LCDCSS48] Bits */
#define LCD_LCDCSSEL3_LCDCSS48_OFS               (0)                             /* !< LCDCSS48 Offset */
#define LCD_LCDCSSEL3_LCDCSS48_MASK              ((uint32_t)0x00000001U)         /* !< Selects pin L48 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL3_LCDCSS48_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL3_LCDCSS48_SEL_COM           ((uint32_t)0x00000001U)         /* !< Common line */
/* LCD_LCDCSSEL3[LCDCSS49] Bits */
#define LCD_LCDCSSEL3_LCDCSS49_OFS               (1)                             /* !< LCDCSS49 Offset */
#define LCD_LCDCSSEL3_LCDCSS49_MASK              ((uint32_t)0x00000002U)         /* !< Selects pin L49 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL3_LCDCSS49_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL3_LCDCSS49_SEL_COM           ((uint32_t)0x00000002U)         /* !< Common line */
/* LCD_LCDCSSEL3[LCDCSS50] Bits */
#define LCD_LCDCSSEL3_LCDCSS50_OFS               (2)                             /* !< LCDCSS50 Offset */
#define LCD_LCDCSSEL3_LCDCSS50_MASK              ((uint32_t)0x00000004U)         /* !< Selects pin L50 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL3_LCDCSS50_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL3_LCDCSS50_SEL_COM           ((uint32_t)0x00000004U)         /* !< Common line */
/* LCD_LCDCSSEL3[LCDCSS51] Bits */
#define LCD_LCDCSSEL3_LCDCSS51_OFS               (3)                             /* !< LCDCSS51 Offset */
#define LCD_LCDCSSEL3_LCDCSS51_MASK              ((uint32_t)0x00000008U)         /* !< Selects pin L51 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL3_LCDCSS51_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL3_LCDCSS51_SEL_COM           ((uint32_t)0x00000008U)         /* !< Common line */
/* LCD_LCDCSSEL3[LCDCSS52] Bits */
#define LCD_LCDCSSEL3_LCDCSS52_OFS               (4)                             /* !< LCDCSS52 Offset */
#define LCD_LCDCSSEL3_LCDCSS52_MASK              ((uint32_t)0x00000010U)         /* !< Selects pin L52 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL3_LCDCSS52_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL3_LCDCSS52_SEL_COM           ((uint32_t)0x00000010U)         /* !< Common line */
/* LCD_LCDCSSEL3[LCDCSS53] Bits */
#define LCD_LCDCSSEL3_LCDCSS53_OFS               (5)                             /* !< LCDCSS53 Offset */
#define LCD_LCDCSSEL3_LCDCSS53_MASK              ((uint32_t)0x00000020U)         /* !< Selects pin L53 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL3_LCDCSS53_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL3_LCDCSS53_SEL_COM           ((uint32_t)0x00000020U)         /* !< Common line */
/* LCD_LCDCSSEL3[LCDCSS54] Bits */
#define LCD_LCDCSSEL3_LCDCSS54_OFS               (6)                             /* !< LCDCSS54 Offset */
#define LCD_LCDCSSEL3_LCDCSS54_MASK              ((uint32_t)0x00000040U)         /* !< Selects pin L54 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL3_LCDCSS54_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL3_LCDCSS54_SEL_COM           ((uint32_t)0x00000040U)         /* !< Common line */
/* LCD_LCDCSSEL3[LCDCSS55] Bits */
#define LCD_LCDCSSEL3_LCDCSS55_OFS               (7)                             /* !< LCDCSS55 Offset */
#define LCD_LCDCSSEL3_LCDCSS55_MASK              ((uint32_t)0x00000080U)         /* !< Selects pin L55 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL3_LCDCSS55_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL3_LCDCSS55_SEL_COM           ((uint32_t)0x00000080U)         /* !< Common line */
/* LCD_LCDCSSEL3[LCDCSS56] Bits */
#define LCD_LCDCSSEL3_LCDCSS56_OFS               (8)                             /* !< LCDCSS56 Offset */
#define LCD_LCDCSSEL3_LCDCSS56_MASK              ((uint32_t)0x00000100U)         /* !< Selects pin L56 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL3_LCDCSS56_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL3_LCDCSS56_SEL_COM           ((uint32_t)0x00000100U)         /* !< Common line */
/* LCD_LCDCSSEL3[LCDCSS57] Bits */
#define LCD_LCDCSSEL3_LCDCSS57_OFS               (9)                             /* !< LCDCSS57 Offset */
#define LCD_LCDCSSEL3_LCDCSS57_MASK              ((uint32_t)0x00000200U)         /* !< Selects pin L57 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL3_LCDCSS57_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL3_LCDCSS57_SEL_COM           ((uint32_t)0x00000200U)         /* !< Common line */
/* LCD_LCDCSSEL3[LCDCSS58] Bits */
#define LCD_LCDCSSEL3_LCDCSS58_OFS               (10)                            /* !< LCDCSS58 Offset */
#define LCD_LCDCSSEL3_LCDCSS58_MASK              ((uint32_t)0x00000400U)         /* !< Selects pin L58 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL3_LCDCSS58_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL3_LCDCSS58_SEL_COM           ((uint32_t)0x00000400U)         /* !< Common line */
/* LCD_LCDCSSEL3[LCDCSS59] Bits */
#define LCD_LCDCSSEL3_LCDCSS59_OFS               (11)                            /* !< LCDCSS59 Offset */
#define LCD_LCDCSSEL3_LCDCSS59_MASK              ((uint32_t)0x00000800U)         /* !< Selects pin L59 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL3_LCDCSS59_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL3_LCDCSS59_SEL_COM           ((uint32_t)0x00000800U)         /* !< Common line */
/* LCD_LCDCSSEL3[LCDCSS60] Bits */
#define LCD_LCDCSSEL3_LCDCSS60_OFS               (12)                            /* !< LCDCSS60 Offset */
#define LCD_LCDCSSEL3_LCDCSS60_MASK              ((uint32_t)0x00001000U)         /* !< Selects pin L60 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL3_LCDCSS60_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL3_LCDCSS60_SEL_COM           ((uint32_t)0x00001000U)         /* !< Common line */
/* LCD_LCDCSSEL3[LCDCSS61] Bits */
#define LCD_LCDCSSEL3_LCDCSS61_OFS               (13)                            /* !< LCDCSS61 Offset */
#define LCD_LCDCSSEL3_LCDCSS61_MASK              ((uint32_t)0x00002000U)         /* !< Selects pin L61 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL3_LCDCSS61_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL3_LCDCSS61_SEL_COM           ((uint32_t)0x00002000U)         /* !< Common line */
/* LCD_LCDCSSEL3[LCDCSS62] Bits */
#define LCD_LCDCSSEL3_LCDCSS62_OFS               (14)                            /* !< LCDCSS62 Offset */
#define LCD_LCDCSSEL3_LCDCSS62_MASK              ((uint32_t)0x00004000U)         /* !< Selects pin L62 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL3_LCDCSS62_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL3_LCDCSS62_SEL_COM           ((uint32_t)0x00004000U)         /* !< Common line */
/* LCD_LCDCSSEL3[LCDCSS63] Bits */
#define LCD_LCDCSSEL3_LCDCSS63_OFS               (15)                            /* !< LCDCSS63 Offset */
#define LCD_LCDCSSEL3_LCDCSS63_MASK              ((uint32_t)0x00008000U)         /* !< Selects pin L63 as either common or
                                                                                    segment line.  0b = Segment line 1b =
                                                                                    Common line */
#define LCD_LCDCSSEL3_LCDCSS63_SEL_SEG           ((uint32_t)0x00000000U)         /* !< Segment line */
#define LCD_LCDCSSEL3_LCDCSS63_SEL_COM           ((uint32_t)0x00008000U)         /* !< Common line */

/* LCD_LCDM Bits */
/* LCD_LCDM[MBIT0] Bits */
#define LCD_LCDM_MBIT0_OFS                       (0)                             /* !< MBIT0 Offset */
#define LCD_LCDM_MBIT0_MASK                      ((uint8_t)0x00000001U)          /* !< If LCD L[2*index] is selected as
                                                                                    segment line (LCDCSS[2*index] = 0b)
                                                                                    and LCD mux rate is static, 2-, 3- or
                                                                                    4-mux (000b <= LCDMXx <= 011b) 0b =
                                                                                    LCD segment off 1b = LCD segment on
                                                                                    If LCD pin L[2*index] is selected as
                                                                                    common line (LCDCSS[2*index] = 1b):
                                                                                    0b = Pin L[2*index] not used as COM0
                                                                                    1b = Pin L[2*index] is used as COM0
                                                                                    If LCD pin L(index) is selected as
                                                                                    segment line (LCDCSS(index) = 0b) and
                                                                                    LCD mux rate is 5-, 6-, 7- or 8-mux
                                                                                    (LCDMXx >= 100b): 0b = LCD segment
                                                                                    off 1b = LCD segment on If LCD pin
                                                                                    L(index) is selected as common line
                                                                                    (LCDCSS(index) = 1b): 0b = Pin
                                                                                    L(index) not used as COM0 1b = Pin
                                                                                    L(index) is used as COM0 */
#define LCD_LCDM_MBIT0_OFF                       ((uint8_t)0x00000000U)          /* !< LCD segment/common off */
#define LCD_LCDM_MBIT0_ON                        ((uint8_t)0x00000001U)          /* !< LCD segment/common on */
/* LCD_LCDM[MBIT1] Bits */
#define LCD_LCDM_MBIT1_OFS                       (1)                             /* !< MBIT1 Offset */
#define LCD_LCDM_MBIT1_MASK                      ((uint8_t)0x00000002U)          /* !< If LCD pin L[2*index] is selected
                                                                                    as segment line (LCDCSS[2*index] =
                                                                                    0b) and LCD mux rate is 2-, 3- or
                                                                                    4-mux (001b <= LCDMXx <= 011b): 0b =
                                                                                    LCD segment off 1b = LCD segment on
                                                                                    If LCD pin L[2*index] is selected as
                                                                                    common line (LCDCSS[2*index] = 1b):
                                                                                    0b = Pin L[2*index] not used as COM1
                                                                                    1b = Pin L[2*index] is used as COM1
                                                                                    If LCD pin L(index) is selected as
                                                                                    segment line (LCDCSS(index) = 0b) and
                                                                                    LCD mux rate is 5-, 6-, 7- or 8-mux
                                                                                    (LCDMXx >= 100b): 0b = LCD segment
                                                                                    off 1b = LCD segment on If LCD pin
                                                                                    L(index) is selected as common line
                                                                                    (LCDCSS(index) = 1b): 0b = Pin
                                                                                    L(index) not used as COM1 1b = Pin
                                                                                    L(index) is used as COM1 */
#define LCD_LCDM_MBIT1_OFF                       ((uint8_t)0x00000000U)          /* !< LCD segment/common off */
#define LCD_LCDM_MBIT1_ON                        ((uint8_t)0x00000002U)          /* !< LCD segment/common on */
/* LCD_LCDM[MBIT2] Bits */
#define LCD_LCDM_MBIT2_OFS                       (2)                             /* !< MBIT2 Offset */
#define LCD_LCDM_MBIT2_MASK                      ((uint8_t)0x00000004U)          /* !< If LCD pin L[2*index] is selected
                                                                                    as segment line (LCDCSS[2*index] =
                                                                                    0b) and LCD mux rate is 3- or 4-mux
                                                                                    (010b <= LCDMXx <= 011b): 0b = LCD
                                                                                    segment off 1b = LCD segment on If
                                                                                    LCD pin L[2*index] is selected as
                                                                                    common line (LCDCSS[2*index] = 1b):
                                                                                    0b = Pin L[2*index] not used as COM2
                                                                                    1b = Pin L[2*index] is used as COM2
                                                                                    If LCD pin L(index) is selected as
                                                                                    segment line (LCDCSS(index) = 0b) and
                                                                                    LCD mux rate is 5-, 6-, 7- or 8-mux
                                                                                    (LCDMXx >= 100b): 0b = LCD segment
                                                                                    off 1b = LCD segment on If LCD pin
                                                                                    L(index) is selected as common line
                                                                                    (LCDCSS(index) = 1b): 0b = Pin
                                                                                    L[index-1] not used as COM2 1b = Pin
                                                                                    L[index-1] is used as COM2 */
#define LCD_LCDM_MBIT2_OFF                       ((uint8_t)0x00000000U)          /* !< LCD segment/common off */
#define LCD_LCDM_MBIT2_ON                        ((uint8_t)0x00000004U)          /* !< LCD segment/common on */
/* LCD_LCDM[MBIT3] Bits */
#define LCD_LCDM_MBIT3_OFS                       (3)                             /* !< MBIT3 Offset */
#define LCD_LCDM_MBIT3_MASK                      ((uint8_t)0x00000008U)          /* !< If LCD pin L(index) is selected as
                                                                                    segment line (LCDCSS(index) = 0b) and
                                                                                    LCD mux rate is 4-mux (LCDMXx=011b):
                                                                                    0b = LCD segment off 1b = LCD segment
                                                                                    on If LCD pin L[2*index] is selected
                                                                                    as common line (LCDCSS[2*index] =
                                                                                    1b): 0b = Pin L[2*index] not used as
                                                                                    COM3 1b = Pin L[2*index] is used as
                                                                                    COM3 If LCD pin L(index) is selected
                                                                                    as segment line (LCDCSS(index) = 0b)
                                                                                    and LCD mux rate is 5-, 6-, 7- or
                                                                                    8-mux (LCDMXx >= 100b): 0b = LCD
                                                                                    segment off 1b = LCD segment on If
                                                                                    LCD pin L(index) is selected as
                                                                                    common line (LCDCSS(index) = 1b): 0b
                                                                                    = Pin L(index) not used as COM3 1b =
                                                                                    Pin L(index) is used as COM3 */
#define LCD_LCDM_MBIT3_OFF                       ((uint8_t)0x00000000U)          /* !< LCD segment/common off */
#define LCD_LCDM_MBIT3_ON                        ((uint8_t)0x00000008U)          /* !< LCD segment/common on */
/* LCD_LCDM[MBIT4] Bits */
#define LCD_LCDM_MBIT4_OFS                       (4)                             /* !< MBIT4 Offset */
#define LCD_LCDM_MBIT4_MASK                      ((uint8_t)0x00000010U)          /* !< If LCD pin L[2*index+1] is selected
                                                                                    as segment line (LCDCSS[2*index+1] =
                                                                                    0b) and LCD mux rate is static, 2-,
                                                                                    3- or 4-mux (000 <= LCDMXx <= 011b)
                                                                                    0b = LCD segment off 1b = LCD segment
                                                                                    on If LCD pin L[2*index+1] is
                                                                                    selected as common line
                                                                                    (LCDCSS[2*index+1] = 1b): 0b = Pin
                                                                                    L[2*ndex+1] not used as COM0 1b = Pin
                                                                                    L[2*ndex+1] is used as COM0 */
#define LCD_LCDM_MBIT4_OFF                       ((uint8_t)0x00000000U)          /* !< LCD segment/common off */
#define LCD_LCDM_MBIT4_ON                        ((uint8_t)0x00000010U)          /* !< LCD segment/common on */
/* LCD_LCDM[MBIT5] Bits */
#define LCD_LCDM_MBIT5_OFS                       (5)                             /* !< MBIT5 Offset */
#define LCD_LCDM_MBIT5_MASK                      ((uint8_t)0x00000020U)          /* !< If LCD pin L[2*index+1] is selected
                                                                                    as segment line (LCDCSS[2*index+1] =
                                                                                    0b) and LCD mux rate is 2-, 3- or
                                                                                    4-mux (001b <= LCDMXx <= 011b): 0b =
                                                                                    LCD segment off 1b = LCD segment on
                                                                                    If LCD pin L[2*index+1] is selected
                                                                                    as common line (LCDCSS[2*index+1] =
                                                                                    1b): 0b = Pin L[2*index+1] not used
                                                                                    as COM1 1b = Pin L[2*index+1] is used
                                                                                    as COM1 If LCD pin L(index) is
                                                                                    selected as segment line
                                                                                    (LCDCSS(index) = 0b) and LCD mux rate
                                                                                    is 6-, 7- or 8-mux (LCDMXx >= 101b):
                                                                                    0b = LCD segment off 1b = LCD segment
                                                                                    on If LCD pin L(index) is selected as
                                                                                    common line (LCDCSS(index) = 1b): 0b
                                                                                    = Pin L(index) not used as COM5 1b =
                                                                                    Pin L(index) is used as COM5 */
#define LCD_LCDM_MBIT5_OFF                       ((uint8_t)0x00000000U)          /* !< LCD segment/common off */
#define LCD_LCDM_MBIT5_ON                        ((uint8_t)0x00000020U)          /* !< LCD segment/common on */
/* LCD_LCDM[MBIT6] Bits */
#define LCD_LCDM_MBIT6_OFS                       (6)                             /* !< MBIT6 Offset */
#define LCD_LCDM_MBIT6_MASK                      ((uint8_t)0x00000040U)          /* !< If LCD pin L[2*index+1] is selected
                                                                                    as segment line (LCDCSS[2*index+1] =
                                                                                    0b) and LCD mux rate is 3- or 4-mux
                                                                                    (010b <= LCDMXx <= 011b): 0b = LCD
                                                                                    segment off 1b = LCD segment on If
                                                                                    LCD pin L[2*index+1] is selected as
                                                                                    common line (LCDCSS[2*index+1] = 1b):
                                                                                    0b = Pin L[2*index+1] not used as
                                                                                    COM2 1b = Pin L[2*index+1] is used as
                                                                                    COM2 If LCD pin L(index) is selected
                                                                                    as segment line (LCDCSS(index) = 0b)
                                                                                    and LCD mux rate is 7- or 8-mux
                                                                                    (LCDMXx >= 110b): 0b = LCD segment
                                                                                    off 1b = LCD segment on If LCD pin
                                                                                    L(index) is selected as common line
                                                                                    (LCDCSS(index) = 1b): 0b = Pin
                                                                                    L(index) not used as COM6 1b = Pin
                                                                                    L(index) is used as COM6 */
/* LCD_LCDM[MBIT7] Bits */
#define LCD_LCDM_MBIT7_OFS                       (7)                             /* !< MBIT7 Offset */
#define LCD_LCDM_MBIT7_MASK                      ((uint8_t)0x00000080U)          /* !< If LCD pin L[2*index+1] is selected
                                                                                    as segment line (LCDCSS[2*index+1] =
                                                                                    0b) and LCD mux rate is 4-mux
                                                                                    (LCDMXx=011b): 0b = LCD segment off
                                                                                    1b = LCD segment on If LCD pin
                                                                                    L[2*index+1] is selected as common
                                                                                    line (LCDCSS[2*index+1] = 1b): 0b =
                                                                                    Pin L[2*index+1] not used as COM3 1b
                                                                                    = Pin L[2*index+1] is used as COM3 If
                                                                                    LCD pin L(index) is selected as
                                                                                    segment line (LCDCSS(index) = 0b) and
                                                                                    LCD mux rate is 8-mux (LCDMXx =
                                                                                    111b): 0b = LCD segment off 1b = LCD
                                                                                    segment on If LCD pin L(index) is
                                                                                    selected as common line
                                                                                    (LCDCSS(index) = 1b): 0b = Pin
                                                                                    L(index) not used as COM7 1b = Pin
                                                                                    L(index) is used as COM7 */
#define LCD_LCDM_MBIT7_OFF                       ((uint8_t)0x00000000U)          /* !< LCD segment/common off */
#define LCD_LCDM_MBIT7_ON                        ((uint8_t)0x00000080U)          /* !< LCD segment/common on */

/* LCD_LCDBM Bits */
/* LCD_LCDBM[MBIT0] Bits */
#define LCD_LCDBM_MBIT0_OFS                      (0)                             /* !< MBIT0 Offset */
#define LCD_LCDBM_MBIT0_MASK                     ((uint8_t)0x00000001U)          /* !< If LCD L[2*index] is selected as
                                                                                    segment line (LCDCSS[2*index] = 0b)
                                                                                    and LCD mux rate is static, 2-, 3- or
                                                                                    4-mux (000b <= LCDMXx <= 011b) 0b =
                                                                                    LCD segment off 1b = LCD segment on
                                                                                    If LCD pin L[2*index] is selected as
                                                                                    common line (LCDCSS[2*index] = 1b):
                                                                                    0b = Pin L[2*index] not used as COM0
                                                                                    1b = Pin L[2*index] is used as COM0
                                                                                    If LCD pin L(index) is selected as
                                                                                    segment line (LCDCSS(index) = 0b) and
                                                                                    LCD mux rate is 5-, 6-, 7- or 8-mux
                                                                                    (LCDMXx >= 100b): 0b = LCD segment
                                                                                    off 1b = LCD segment on If LCD pin
                                                                                    L(index) is selected as common line
                                                                                    (LCDCSS(index) = 1b): 0b = Pin
                                                                                    L(index) not used as COM0 1b = Pin
                                                                                    L(index) is used as COM0 */
#define LCD_LCDBM_MBIT0_OFF                      ((uint8_t)0x00000000U)          /* !< LCD segment/common off */
#define LCD_LCDBM_MBIT0_ON                       ((uint8_t)0x00000001U)          /* !< LCD segment/common on */
/* LCD_LCDBM[MBIT1] Bits */
#define LCD_LCDBM_MBIT1_OFS                      (1)                             /* !< MBIT1 Offset */
#define LCD_LCDBM_MBIT1_MASK                     ((uint8_t)0x00000002U)          /* !< If LCD pin L[2*index] is selected
                                                                                    as segment line (LCDCSS[2*index] =
                                                                                    0b) and LCD mux rate is 2-, 3- or
                                                                                    4-mux (001b <= LCDMXx <= 011b): 0b =
                                                                                    LCD segment off 1b = LCD segment on
                                                                                    If LCD pin L[2*index] is selected as
                                                                                    common line (LCDCSS[2*index] = 1b):
                                                                                    0b = Pin L[2*index] not used as COM1
                                                                                    1b = Pin L[2*index] is used as COM1
                                                                                    If LCD pin L(index) is selected as
                                                                                    segment line (LCDCSS(index) = 0b) and
                                                                                    LCD mux rate is 5-, 6-, 7- or 8-mux
                                                                                    (LCDMXx >= 100b): 0b = LCD segment
                                                                                    off 1b = LCD segment on If LCD pin
                                                                                    L(index) is selected as common line
                                                                                    (LCDCSS(index) = 1b): 0b = Pin
                                                                                    L(index) not used as COM1 1b = Pin
                                                                                    L(index) is used as COM1 */
#define LCD_LCDBM_MBIT1_OFF                      ((uint8_t)0x00000000U)          /* !< LCD segment/common off */
#define LCD_LCDBM_MBIT1_ON                       ((uint8_t)0x00000002U)          /* !< LCD segment/common on */
/* LCD_LCDBM[MBIT2] Bits */
#define LCD_LCDBM_MBIT2_OFS                      (2)                             /* !< MBIT2 Offset */
#define LCD_LCDBM_MBIT2_MASK                     ((uint8_t)0x00000004U)          /* !< If LCD pin L[2*index] is selected
                                                                                    as segment line (LCDCSS[2*index] =
                                                                                    0b) and LCD mux rate is 3- or 4-mux
                                                                                    (010b <= LCDMXx <= 011b): 0b = LCD
                                                                                    segment off 1b = LCD segment on If
                                                                                    LCD pin L[2*index] is selected as
                                                                                    common line (LCDCSS[2*index] = 1b):
                                                                                    0b = Pin L[2*index] not used as COM2
                                                                                    1b = Pin L[2*index] is used as COM2
                                                                                    If LCD pin L(index) is selected as
                                                                                    segment line (LCDCSS(index) = 0b) and
                                                                                    LCD mux rate is 5-, 6-, 7- or 8-mux
                                                                                    (LCDMXx >= 100b): 0b = LCD segment
                                                                                    off 1b = LCD segment on If LCD pin
                                                                                    L(index) is selected as common line
                                                                                    (LCDCSS(index) = 1b): 0b = Pin
                                                                                    L[index-1] not used as COM2 1b = Pin
                                                                                    L[index-1] is used as COM2 */
#define LCD_LCDBM_MBIT2_OFF                      ((uint8_t)0x00000000U)          /* !< LCD segment/common off */
#define LCD_LCDBM_MBIT2_ON                       ((uint8_t)0x00000004U)          /* !< LCD segment/common on */
/* LCD_LCDBM[MBIT3] Bits */
#define LCD_LCDBM_MBIT3_OFS                      (3)                             /* !< MBIT3 Offset */
#define LCD_LCDBM_MBIT3_MASK                     ((uint8_t)0x00000008U)          /* !< If LCD pin L(index) is selected as
                                                                                    segment line (LCDCSS(index) = 0b) and
                                                                                    LCD mux rate is 4-mux (LCDMXx=011b):
                                                                                    0b = LCD segment off 1b = LCD segment
                                                                                    on If LCD pin L[2*index] is selected
                                                                                    as common line (LCDCSS[2*index] =
                                                                                    1b): 0b = Pin L[2*index] not used as
                                                                                    COM3 1b = Pin L[2*index] is used as
                                                                                    COM3 If LCD pin L(index) is selected
                                                                                    as segment line (LCDCSS(index) = 0b)
                                                                                    and LCD mux rate is 5-, 6-, 7- or
                                                                                    8-mux (LCDMXx >= 100b): 0b = LCD
                                                                                    segment off 1b = LCD segment on If
                                                                                    LCD pin L(index) is selected as
                                                                                    common line (LCDCSS(index) = 1b): 0b
                                                                                    = Pin L(index) not used as COM3 1b =
                                                                                    Pin L(index) is used as COM3 */
#define LCD_LCDBM_MBIT3_OFF                      ((uint8_t)0x00000000U)          /* !< LCD segment/common off */
#define LCD_LCDBM_MBIT3_ON                       ((uint8_t)0x00000008U)          /* !< LCD segment/common on */
/* LCD_LCDBM[MBIT4] Bits */
#define LCD_LCDBM_MBIT4_OFS                      (4)                             /* !< MBIT4 Offset */
#define LCD_LCDBM_MBIT4_MASK                     ((uint8_t)0x00000010U)          /* !< If LCD pin L[2*index+1] is selected
                                                                                    as segment line (LCDCSS[2*index+1] =
                                                                                    0b) and LCD mux rate is static, 2-,
                                                                                    3- or 4-mux (000b <= LCDMXx <= 011b)
                                                                                    0b = LCD segment off 1b = LCD segment
                                                                                    on If LCD pin L[2*index+1] is
                                                                                    selected as common line
                                                                                    (LCDCSS[2*index+1] = 1b): 0b = Pin
                                                                                    L[2*ndex+1] not used as COM0 1b = Pin
                                                                                    L[2*ndex+1] is used as COM0 */
#define LCD_LCDBM_MBIT4_OFF                      ((uint8_t)0x00000000U)          /* !< LCD segment/common off */
#define LCD_LCDBM_MBIT4_ON                       ((uint8_t)0x00000010U)          /* !< LCD segment/common on */
/* LCD_LCDBM[MBIT5] Bits */
#define LCD_LCDBM_MBIT5_OFS                      (5)                             /* !< MBIT5 Offset */
#define LCD_LCDBM_MBIT5_MASK                     ((uint8_t)0x00000020U)          /* !< If LCD pin L[2*index+1] is selected
                                                                                    as segment line (LCDCSS[2*index+1] =
                                                                                    0b) and LCD mux rate is 2-, 3- or
                                                                                    4-mux (001b <= LCDMXx <= 011b): 0b =
                                                                                    LCD segment off 1b = LCD segment on
                                                                                    If LCD pin L[2*index+1] is selected
                                                                                    as common line (LCDCSS[2*index+1] =
                                                                                    1b): 0b = Pin L[2*index+1] not used
                                                                                    as COM1 1b = Pin L[2*index+1] is used
                                                                                    as COM1 If LCD pin L(index) is
                                                                                    selected as segment line
                                                                                    (LCDCSS(index) = 0b) and LCD mux rate
                                                                                    is 6-, 7- or 8-mux (LCDMXx >= 101b):
                                                                                    0b = LCD segment off 1b = LCD segment
                                                                                    on If LCD pin L(index) is selected as
                                                                                    common line (LCDCSS(index) = 1b): 0b
                                                                                    = Pin L(index) not used as COM5 1b =
                                                                                    Pin L(index) is used as COM5 */
#define LCD_LCDBM_MBIT5_OFF                      ((uint8_t)0x00000000U)          /* !< LCD segment/common off */
#define LCD_LCDBM_MBIT5_ON                       ((uint8_t)0x00000020U)          /* !< LCD segment/common on */
/* LCD_LCDBM[MBIT6] Bits */
#define LCD_LCDBM_MBIT6_OFS                      (6)                             /* !< MBIT6 Offset */
#define LCD_LCDBM_MBIT6_MASK                     ((uint8_t)0x00000040U)          /* !< If LCD pin L[2*index+1] is selected
                                                                                    as segment line (LCDCSS[2*index+1] =
                                                                                    0b) and LCD mux rate is 3- or 4-mux
                                                                                    (010b <= LCDMXx <= 011b): 0b = LCD
                                                                                    segment off 1b = LCD segment on If
                                                                                    LCD pin L[2*index+1] is selected as
                                                                                    common line (LCDCSS[2*index+1] = 1b):
                                                                                    0b = Pin L[2*index+1] not used as
                                                                                    COM2 1b = Pin L[2*index+1] is used as
                                                                                    COM2 If LCD pin L(index) is selected
                                                                                    as segment line (LCDCSS(index) = 0b)
                                                                                    and LCD mux rate is 7- or 8-mux
                                                                                    (LCDMXx >= 110b): 0b = LCD segment
                                                                                    off 1b = LCD segment on If LCD pin
                                                                                    L(index) is selected as common line
                                                                                    (LCDCSS(index) = 1b): 0b = Pin
                                                                                    L(index) not used as COM6 1b = Pin
                                                                                    L(index) is used as COM6 */
#define LCD_LCDBM_MBIT6_OFF                      ((uint8_t)0x00000000U)          /* !< LCD segment/common off */
#define LCD_LCDBM_MBIT6_ON                       ((uint8_t)0x00000040U)          /* !< LCD segment/common on */
/* LCD_LCDBM[MBIT7] Bits */
#define LCD_LCDBM_MBIT7_OFS                      (7)                             /* !< MBIT7 Offset */
#define LCD_LCDBM_MBIT7_MASK                     ((uint8_t)0x00000080U)          /* !< If LCD pin L[2*index+1] is selected
                                                                                    as segment line (LCDCSS[2*index+1] =
                                                                                    0b) and LCD mux rate is 4-mux
                                                                                    (LCDMXx=011b): 0b = LCD segment off
                                                                                    1b = LCD segment on If LCD pin
                                                                                    L[2*index+1] is selected as common
                                                                                    line (LCDCSS[2*index+1] = 1b): 0b =
                                                                                    Pin L[2*index+1] not used as COM3 1b
                                                                                    = Pin L[2*index+1] is used as COM3 If
                                                                                    LCD pin L(index) is selected as
                                                                                    segment line (LCDCSS(index) = 0b) and
                                                                                    LCD mux rate is 8-mux (LCDMXx =
                                                                                    111b): 0b = LCD segment off 1b = LCD
                                                                                    segment on If LCD pin L(index) is
                                                                                    selected as common line
                                                                                    (LCDCSS(index) = 1b): 0b = Pin
                                                                                    L(index) not used as COM7 1b = Pin
                                                                                    L(index) is used as COM7 */
#define LCD_LCDBM_MBIT7_OFF                      ((uint8_t)0x00000000U)          /* !< LCD segment/common off */
#define LCD_LCDBM_MBIT7_ON                       ((uint8_t)0x00000080U)          /* !< LCD segment/common on */

/* LCD_LCDVREFCFG Bits */
/* LCD_LCDVREFCFG[ONTIME] Bits */
#define LCD_LCDVREFCFG_ONTIME_OFS                (0)                             /* !< ONTIME Offset */
#define LCD_LCDVREFCFG_ONTIME_MASK               ((uint32_t)0x00000003U)         /* !< Configures the ontime of the VREF. */
#define LCD_LCDVREFCFG_ONTIME_ONTIME16           ((uint32_t)0x00000000U)         /* !< 16 CLKCP cycles of ontime */
#define LCD_LCDVREFCFG_ONTIME_ONTIME32           ((uint32_t)0x00000001U)         /* !< 32 CLKCP cycles of ontime */
#define LCD_LCDVREFCFG_ONTIME_ONTIME128          ((uint32_t)0x00000002U)         /* !< 128 CLKCP cycles of ontime */
#define LCD_LCDVREFCFG_ONTIME_ONTIME256          ((uint32_t)0x00000003U)         /* !< 256 CLKCP cycles of ontime */


#ifdef __cplusplus
}
#endif

#endif /* ti_devices_msp_peripherals_hw_lcd__include */
