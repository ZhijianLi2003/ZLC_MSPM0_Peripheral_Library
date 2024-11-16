/*
 * Copyright (c) 2020, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*!****************************************************************************
 *  @file       dl_sysctl_mspm0l122x_l222x.h
 *  @brief      System Control (SysCtl)
 *  @defgroup   SYSCTL_MSPM0L122X_L222X MSPM0L122X_L222X System Control (SYSCTL)
 *
 *  @anchor ti_dl_m0p_mspm0l122x_l222x_dl_sysctl_Overview
 *  # Overview
 *
 *  The System Control (SysCtl) module enables control over system wide
 *  settings like clocks and power management.
 *
 *  <hr>
 *
 ******************************************************************************
 */
/** @addtogroup SYSCTL_MSPM0L122X_L222X
 * @{
 */
#ifndef ti_dl_m0p_dl_sysctl_sysctl__include
#define ti_dl_m0p_dl_sysctl_sysctl__include

#include <stdbool.h>
#include <stdint.h>

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/dl_common.h>

#ifdef __cplusplus
extern "C" {
#endif

/* clang-format off */

/** @addtogroup DL_SYSCTL_RESET
 *  @{
 */
/*!
 * @brief Perform a SYSRST
 *
 * This issues a SYSRST (CPU plus peripherals only)
 */
 #define DL_SYSCTL_RESET_SYSRST                    (SYSCTL_RESETLEVEL_LEVEL_CPU)

/*!
 * @deprecated This API is deprecated. Please refer to @ref DL_SYSCTL_RESET_SYSRST.
 */
 #define DL_SYSCTL_RESET_CPU                            (DL_SYSCTL_RESET_SYSRST)

/*!
 * @brief Perform a Boot reset
 *
 * This triggers execution of the device boot configuration routine and resets
 * the majority of the core logic while also power cycling the SRAM
 */
 #define DL_SYSCTL_RESET_BOOT                     (SYSCTL_RESETLEVEL_LEVEL_BOOT)

/*!
 * @brief Perform a POR reset
 *
 * This performas a POR reset which is a complete device reset
 */
 #define DL_SYSCTL_RESET_POR                       (SYSCTL_RESETLEVEL_LEVEL_POR)

/*!
 * @brief Perform system reset and exit bootloader to the application
 */
 #define DL_SYSCTL_RESET_BOOTLOADER_EXIT                                       \
                                        (SYSCTL_RESETLEVEL_LEVEL_BOOTLOADEREXIT)

 /*!
 * @brief Perform system reset and run bootloader
 */
 #define DL_SYSCTL_RESET_BOOTLOADER_ENTRY                                      \
                                       (SYSCTL_RESETLEVEL_LEVEL_BOOTLOADERENTRY)

/** @}*/

/** @addtogroup DL_SYSCTL_INTERRUPT
 *  @{
 */
/*! @brief  Low Frequency Oscillator is stabilized and ready to use */
#define DL_SYSCTL_INTERRUPT_LFOSC_GOOD           (SYSCTL_IMASK_LFOSCGOOD_ENABLE)
/*! @brief  Analog clocking consistency error */
#define DL_SYSCTL_INTERRUPT_ANALOG_CLOCK_ERROR   (SYSCTL_IMASK_ANACLKERR_ENABLE)

/** @}*/

/*! @enum DL_SYSCTL_IIDX */
typedef enum {
    /*! @brief  Low Frequency Oscillator is stabilized and ready to use */
    DL_SYSCTL_IIDX_LFOSC_GOOD = SYSCTL_IIDX_STAT_LFOSCGOOD,
    /*! @brief  Analog clocking consistency error */
    DL_SYSCTL_IIDX_ANALOG_CLOCK_ERROR = SYSCTL_IIDX_STAT_ANACLKERR,
} DL_SYSCTL_IIDX;


/** @addtogroup DL_SYSCTL_NMI
 *  @{
 */
/*! @brief  Non-maskable interrupt for Watchdog 0 Fault */
#define DL_SYSCTL_NMI_WWDT0_FAULT                     (SYSCTL_NMIISET_WWDT0_SET)
/*! @brief  Non-maskable interrupt for early BOR */
#define DL_SYSCTL_NMI_BORLVL                         (SYSCTL_NMIISET_BORLVL_SET)
/** @}*/

/** @addtogroup DL_SYSCTL_CLK_STATUS
 *  @{
 */
/*! @brief Writes to HFCLKCLKCFG are blocked */
#define DL_SYSCTL_CLK_STATUS_HFCLK_CONFIG_BLOCKED                              \
                                             (SYSCTL_CLKSTATUS_HFCLKBLKUPD_TRUE)
/*! @brief SYSOSC Frequency Correcting Loop Mode ON */
#define DL_SYSCTL_CLK_STATUS_FCL_ON           (SYSCTL_CLKSTATUS_FCLMODE_ENABLED)
/*! @brief Clock Fail for LFXT or EXLF clock source */
#define DL_SYSCTL_CLK_STATUS_LFCLK_FAIL        (SYSCTL_CLKSTATUS_LFCLKFAIL_TRUE)
/*! @brief High Speed Clock Good */
#define DL_SYSCTL_CLK_STATUS_HSCLK_GOOD        (SYSCTL_CLKSTATUS_HSCLKGOOD_TRUE)
/*! @brief High Speed Clock Stuck Fault */
#define DL_SYSCTL_CLK_STATUS_HSCLK_FAULT       (SYSCTL_CLKSTATUS_HSCLKDEAD_TRUE)
/*! @brief HFCLKs is OFF or DEAD */
#define DL_SYSCTL_CLK_STATUS_HFCLK_OFF          (SYSCTL_CLKSTATUS_HFCLKOFF_TRUE)
/*! @brief All HFCLKs are OFF or DEAD */
#define DL_SYSCTL_CLK_STATUS_HSCLK_OFF         (SYSCTL_CLKSTATUS_HSCLKSOFF_TRUE)
/*! @brief LFOSC is Valid */
#define DL_SYSCTL_CLK_STATUS_LFOSC_GOOD        (SYSCTL_CLKSTATUS_LFOSCGOOD_TRUE)
/*! @brief LFXT is Valid */
#define DL_SYSCTL_CLK_STATUS_LFXT_GOOD          (SYSCTL_CLKSTATUS_LFXTGOOD_TRUE)
/*! @brief High Frequency Clock ON */
#define DL_SYSCTL_CLK_STATUS_HFCLK_GOOD        (SYSCTL_CLKSTATUS_HFCLKGOOD_TRUE)
/*! @brief MCLK now sourced from HSCLK, otherwise SYSOSC */
#define DL_SYSCTL_CLK_STATUS_MCLK_SOURCE_HSCLK (SYSCTL_CLKSTATUS_HSCLKMUX_HSCLK)
/*! @brief MCLK now sourced from LFCLK */
#define DL_SYSCTL_CLK_STATUS_MCLK_SOURCE_LFCLK                                 \
                                             (SYSCTL_CLKSTATUS_CURMCLKSEL_LFCLK)
/*! @brief Analog clocking error */
#define DL_SYSCTL_CLK_STATUS_ANALOG_CLOCK_ERROR                                \
                                               (SYSCTL_CLKSTATUS_ANACLKERR_TRUE)
/*! @brief Frequency Clock Counter (FCC) done */
#define DL_SYSCTL_CLK_STATUS_FCC_DONE            (SYSCTL_CLKSTATUS_FCCDONE_DONE)
/*! @brief = LFCLK sourced from the LFXT (crystal) */
#define DL_SYSCTL_CLK_STATUS_LFCLK_SOURCE_LFXT  (SYSCTL_CLKSTATUS_LFCLKMUX_LFXT)
/*! @brief = LFCLK sourced from LFCLK_IN (external digital clock input) */
#define DL_SYSCTL_CLK_STATUS_LFCLK_SOURCE_EXLF  (SYSCTL_CLKSTATUS_LFCLKMUX_EXLF)
/*! @brief = SYSOSC is at low frequency (4MHz) */
#define DL_SYSCTL_CLK_STATUS_SYSOSC_4MHZ  (SYSCTL_CLKSTATUS_SYSOSCFREQ_SYSOSC4M)
/*! @brief = SYSOSC is at the user-trimmed frequency (16 or 24MHz) */
#define DL_SYSCTL_CLK_STATUS_SYSOSC_USERTRIM_FREQ                              \
                                        (SYSCTL_CLKSTATUS_SYSOSCFREQ_SYSOSCUSER)
/** @}*/

/** @addtogroup DL_SYSCTL_STATUS
 *  @{
 */

/*! @brief IO is locked due to SHUTDOWN */
#define DL_SYSCTL_STATUS_SHUTDOWN_IO_LOCK_TRUE                                 \
                                              (SYSCTL_SYSSTATUS_SHDNIOLOCK_TRUE)
/*! @brief User has disabled external reset pin */
#define DL_SYSCTL_STATUS_EXT_RESET_PIN_DISABLED                                \
                                            (SYSCTL_SYSSTATUS_EXTRSTPINDIS_TRUE)
/*! @brief User has disabled SWD port  */
#define DL_SYSCTL_STATUS_SWD_DISABLED          (SYSCTL_SYSSTATUS_SWDCFGDIS_TRUE)

/*! @brief PMU IFREF good */
#define DL_SYSCTL_STATUS_PMU_IFREF_GOOD      (SYSCTL_SYSSTATUS_PMUIREFGOOD_TRUE)
/*! @brief VBOOST (Analog Charge Pump) started up properly */
#define DL_SYSCTL_STATUS_VBOOST_GOOD        (SYSCTL_SYSSTATUS_ANACPUMPGOOD_TRUE)
/*! @brief Brown Out Reset event status indicator */
#define DL_SYSCTL_STATUS_BOR_EVENT                (SYSCTL_SYSSTATUS_BORLVL_TRUE)
/*! @brief MCAN0 ready */
#define DL_SYSCTL_STATUS_MCAN0_READY          (SYSCTL_SYSSTATUS_MCAN0READY_TRUE)
/*! @brief Double Error Detect on Flash */
#define DL_SYSCTL_STATUS_FLASH_DED              (SYSCTL_SYSSTATUS_FLASHDED_TRUE)
/*! @brief Single Error Correction on Flash */
#define DL_SYSCTL_STATUS_FLASH_SEC              (SYSCTL_SYSSTATUS_FLASHSEC_TRUE)
/*! @brief Current Brown Out Reset minimum level */
#define DL_SYSCTL_STATUS_BOR_LEVEL0                                            \
                                  (SYSCTL_SYSSTATUS_BORCURTHRESHOLD_BORLEVELMIN)
/*! @brief Current Brown Out Reset level 1 */
#define DL_SYSCTL_STATUS_BOR_LEVEL1 (SYSCTL_SYSSTATUS_BORCURTHRESHOLD_BORLEVEL1)
/*! @brief Current Brown Out Reset level 2 */
#define DL_SYSCTL_STATUS_BOR_LEVEL2 (SYSCTL_SYSSTATUS_BORCURTHRESHOLD_BORLEVEL2)
/*! @brief Current Brown Out Reset level 3 */
#define DL_SYSCTL_STATUS_BOR_LEVEL3 (SYSCTL_SYSSTATUS_BORCURTHRESHOLD_BORLEVEL3)
/** @}*/

/* clang-format on */

/*! @enum DL_SYSCTL_NMI_IIDX */
typedef enum {
    /*! @brief  NMI interrupt index for VBAT power on */
    DL_SYSCTL_NMI_IIDX_VBAT_ON = SYSCTL_NMIIIDX_STAT_VBATUP,
    /*! @brief  NMI interrupt index for VBAT power off  */
    DL_SYSCTL_NMI_IIDX_VBAT_OFF = SYSCTL_NMIIIDX_STAT_VBATDN,

    /*! @brief  NMI interrupt index for SRAM Double Error Detect */
    DL_SYSCTL_NMI_IIDX_SRAM_DED = SYSCTL_NMIIIDX_STAT_SRAMDED,
    /*! @brief  NMI interrupt index for Flash Double Error Detect */
    DL_SYSCTL_NMI_IIDX_FLASH_DED = SYSCTL_NMIIIDX_STAT_FLASHDED,
    /*! @brief  NMI interrupt index for LFCLK Monitor Fail */
    DL_SYSCTL_NMI_IIDX_LFCLK_FAIL = SYSCTL_NMIIIDX_STAT_LFCLKFAIL,
    /*! @brief  NMI interrupt index for Watchdog 0 Fault */
    DL_SYSCTL_NMI_IIDX_WWDT0_FAULT = SYSCTL_NMIIIDX_STAT_WWDT0,
    /*! @brief  NMI interrupt index for early BOR */
    DL_SYSCTL_NMI_IIDX_BORLVL = SYSCTL_NMIIIDX_STAT_BORLVL,
    /*! @brief  NMI interrupt index for no interrupt pending */
    DL_SYSCTL_NMI_IIDX_NO_INT = SYSCTL_NMIIIDX_STAT_NO_INTR,
} DL_SYSCTL_NMI_IIDX;

/*! @enum DL_SYSCTL_ERROR_BEHAVIOR */
typedef enum {
    /*! @brief  The error event will trigger a SYSRST */
    DL_SYSCTL_ERROR_BEHAVIOR_RESET = 0x0,
    /*! @brief  The error event will trigger an NMI */
    DL_SYSCTL_ERROR_BEHAVIOR_NMI = 0x1,

} DL_SYSCTL_ERROR_BEHAVIOR;

/*! @enum DL_SYSCTL_SYSOSC_FREQ */
typedef enum {
    /*! Use 4MHz for System Oscillator (SYSOSC) */
    DL_SYSCTL_SYSOSC_FREQ_4M = (SYSCTL_SYSOSCCFG_FREQ_SYSOSC4M),
    /*! Use BASE (32MHz) for System Oscillator (SYSOSC) */
    DL_SYSCTL_SYSOSC_FREQ_BASE = (SYSCTL_SYSOSCCFG_FREQ_SYSOSCBASE),
    /*! User will trim the System Oscillator (SYSOSC) to 16MHz or 24MHz */
    DL_SYSCTL_SYSOSC_FREQ_USERTRIM = (SYSCTL_SYSOSCCFG_FREQ_SYSOSCUSER),
} DL_SYSCTL_SYSOSC_FREQ;

/** @enum DL_SYSCTL_SYSOSC_USERTRIM_FREQ */
typedef enum {
    /*! Set SYSOSC user trim frequency target to 16MHz */
    DL_SYSCTL_SYSOSC_USERTRIM_FREQ_16M =
        (SYSCTL_SYSOSCTRIMUSER_FREQ_SYSOSC16M),
    /*! Set SYSOSC user trim frequency target to 24MHz */
    DL_SYSCTL_SYSOSC_USERTRIM_FREQ_24M =
        (SYSCTL_SYSOSCTRIMUSER_FREQ_SYSOSC24M),
} DL_SYSCTL_SYSOSC_USERTRIM_FREQ;

/*! @brief  Configuration struct for @ref DL_SYSCTL_configSYSOSCUserTrim. */
typedef struct {
    /*! Frequency Correcting Loop resistor divide value [0x0, 0x1FF] */
    uint32_t rDiv;
    /*! Resistor fine trim [0x0, 0xF] */
    uint32_t resistorFine;
    /*! Resistor coarse trim [0x0, 0x3F] */
    uint32_t resistorCoarse;
    /*! Capacitor trim [0x0, 0x7] */
    uint32_t capacitor;
    /*! SYSOSC user trim frequency target */
    DL_SYSCTL_SYSOSC_USERTRIM_FREQ freq;
} DL_SYSCTL_SYSOSCUserTrimConfig;

/** @enum DL_SYSCTL_LFXT_DRIVE_STRENGTH */
typedef enum {
    /*! Lowest Drive and Current */
    DL_SYSCTL_LFXT_DRIVE_STRENGTH_LOWEST =
        (SYSCTL_LFCLKCFG_XT1DRIVE_LOWESTDRV),
    /*! Lower Drive and Current */
    DL_SYSCTL_LFXT_DRIVE_STRENGTH_LOWER = (SYSCTL_LFCLKCFG_XT1DRIVE_LOWERDRV),
    /*! Higher Drive and Current */
    DL_SYSCTL_LFXT_DRIVE_STRENGTH_HIGHER =
        (SYSCTL_LFCLKCFG_XT1DRIVE_HIGHERDRV),
    /*! Highest Drive and Current */
    DL_SYSCTL_LFXT_DRIVE_STRENGTH_HIGHEST =
        (SYSCTL_LFCLKCFG_XT1DRIVE_HIGHESTDRV),
} DL_SYSCTL_LFXT_DRIVE_STRENGTH;

/*! @brief  Configuration struct for @ref DL_SYSCTL_LFCLKConfig. */
typedef struct {
    /*! Enable if CAP is less than 3pF to reduce power consumption */
    bool lowCap;
    /*! Enable to use monitor for LFXT, EXLF failure */
    bool monitor;
    /*! Drive strength and power consumption option */
    DL_SYSCTL_LFXT_DRIVE_STRENGTH xt1Drive;
} DL_SYSCTL_LFCLKConfig;

/** @enum DL_SYSCTL_HFXT_RANGE */
typedef enum {
    /*! HFXT frequency range between 4 and 8 MHz */
    DL_SYSCTL_HFXT_RANGE_4_8_MHZ = SYSCTL_HFCLKCLKCFG_HFXTRSEL_RANGE4TO8,
    /*! HFXT frequency range between 8.01 and 16 MHz */
    DL_SYSCTL_HFXT_RANGE_8_16_MHZ = SYSCTL_HFCLKCLKCFG_HFXTRSEL_RANGE8TO16,
    /*! HFXT frequency range between 16.01 and 32 MHz */
    DL_SYSCTL_HFXT_RANGE_16_32_MHZ = SYSCTL_HFCLKCLKCFG_HFXTRSEL_RANGE16TO32,
    /*! HFXT frequency range between 32.01 and 48 MHz */
    DL_SYSCTL_HFXT_RANGE_32_48_MHZ = SYSCTL_HFCLKCLKCFG_HFXTRSEL_RANGE32TO48,
} DL_SYSCTL_HFXT_RANGE;

/*! @enum DL_SYSCTL_HSCLK_SOURCE */
typedef enum {
    /*! Invalid source for HSCLK */
    DL_SYSCTL_HSCLK_SOURCE_INVALID = 0x0,
    /*! Use HFLK as input source for HSCLK */
    DL_SYSCTL_HSCLK_SOURCE_HFCLK = SYSCTL_HSCLKCFG_HSCLKSEL_HFCLKCLK,
} DL_SYSCTL_HSCLK_SOURCE;

/** @enum DL_SYSCTL_MCLK_SOURCE */
typedef enum {
    /*! Use System Oscillator (SYSOSC) as MCLK source (default after reset) */
    DL_SYSCTL_MCLK_SOURCE_SYSOSC = SYSCTL_MCLKCFG_USEHSCLK_DISABLE,
    /*! Use High Speed Clock (HSCLK) as MCLK source (HFCLK, ...) */
    DL_SYSCTL_MCLK_SOURCE_HSCLK = SYSCTL_MCLKCFG_USEHSCLK_ENABLE,
    /*! Use the Low Frequency Clock (LFCLK) as the clock source */
    DL_SYSCTL_MCLK_SOURCE_LFCLK = SYSCTL_MCLKCFG_USELFCLK_ENABLE,
} DL_SYSCTL_MCLK_SOURCE;

/** @enum DL_SYSCTL_MCLK_DIVIDER */
typedef enum {
    /*! Disable MCLK divider. Change SYSOSC freq only when MDIV is disabled */
    DL_SYSCTL_MCLK_DIVIDER_DISABLE = 0x0,
    /*! Divide MCLK frequency by 2 */
    DL_SYSCTL_MCLK_DIVIDER_2 = 0x1,
    /*! Divide MCLK frequency by 3 */
    DL_SYSCTL_MCLK_DIVIDER_3 = 0x2,
    /*! Divide MCLK frequency by 4 */
    DL_SYSCTL_MCLK_DIVIDER_4 = 0x3,
    /*! Divide MCLK frequency by 5 */
    DL_SYSCTL_MCLK_DIVIDER_5 = 0x4,
    /*! Divide MCLK frequency by 6 */
    DL_SYSCTL_MCLK_DIVIDER_6 = 0x5,
    /*! Divide MCLK frequency by 7 */
    DL_SYSCTL_MCLK_DIVIDER_7 = 0x6,
    /*! Divide MCLK frequency by 8 */
    DL_SYSCTL_MCLK_DIVIDER_8 = 0x7,
    /*! Divide MCLK frequency by 9 */
    DL_SYSCTL_MCLK_DIVIDER_9 = 0x8,
    /*! Divide MCLK frequency by 10 */
    DL_SYSCTL_MCLK_DIVIDER_10 = 0x9,
    /*! Divide MCLK frequency by 11 */
    DL_SYSCTL_MCLK_DIVIDER_11 = 0xA,
    /*! Divide MCLK frequency by 12 */
    DL_SYSCTL_MCLK_DIVIDER_12 = 0xB,
    /*! Divide MCLK frequency by 13 */
    DL_SYSCTL_MCLK_DIVIDER_13 = 0xC,
    /*! Divide MCLK frequency by 14 */
    DL_SYSCTL_MCLK_DIVIDER_14 = 0xD,
    /*! Divide MCLK frequency by 15 */
    DL_SYSCTL_MCLK_DIVIDER_15 = 0xE,
    /*! Divide MCLK frequency by 16 */
    DL_SYSCTL_MCLK_DIVIDER_16 = 0xF,
} DL_SYSCTL_MCLK_DIVIDER;

/** @enum DL_SYSCTL_CLK_OUT_SOURCE */
typedef enum {
    /*! Use System Oscillator (SYSOSC) as CLK_OUT source */
    DL_SYSCTL_CLK_OUT_SOURCE_SYSOSC = SYSCTL_GENCLKCFG_EXCLKSRC_SYSOSC,
    /*! Use Ultra Low Power Clock (ULPCLK) as CLK_OUT source.
      * @ref DL_SYSCTL_CLK_OUT_DIVIDE_DISABLE must not be selected for this
      * configuration. */
    DL_SYSCTL_CLK_OUT_SOURCE_ULPCLK = SYSCTL_GENCLKCFG_EXCLKSRC_ULPCLK,
    /*! Use Low Frequency Clock (LFCLK) as CLK_OUT source */
    DL_SYSCTL_CLK_OUT_SOURCE_LFCLK = SYSCTL_GENCLKCFG_EXCLKSRC_LFCLK,
    /*! Use Middle Frequency Precision Clock (MFPCLK) as CLK_OUT source.
      * @ref DL_SYSCTL_CLK_OUT_DIVIDE_DISABLE must not be selected for this
      * configuration. */
    DL_SYSCTL_CLK_OUT_SOURCE_MFPCLK = SYSCTL_GENCLKCFG_EXCLKSRC_MFPCLK,
    /*! Use High Frequency Clock (HFCLK) as CLK_OUT source */
    DL_SYSCTL_CLK_OUT_SOURCE_HFCLK = SYSCTL_GENCLKCFG_EXCLKSRC_HFCLK,
} DL_SYSCTL_CLK_OUT_SOURCE;

/** @enum DL_SYSCTL_CLK_OUT_DIVIDE */
typedef enum {
    /*! Disable the External Clock (CLK_OUT) output divider */
    DL_SYSCTL_CLK_OUT_DIVIDE_DISABLE = SYSCTL_GENCLKCFG_EXCLKDIVEN_PASSTHRU,
    /*! Divide External Clock (CLK_OUT) output by 2 */
    DL_SYSCTL_CLK_OUT_DIVIDE_2 =
        SYSCTL_GENCLKCFG_EXCLKDIVEN_ENABLE | SYSCTL_GENCLKCFG_EXCLKDIVVAL_DIV2,
    /*! Divide External Clock (CLK_OUT) output by 4 */
    DL_SYSCTL_CLK_OUT_DIVIDE_4 =
        SYSCTL_GENCLKCFG_EXCLKDIVEN_ENABLE | SYSCTL_GENCLKCFG_EXCLKDIVVAL_DIV4,
    /*! Divide External Clock (CLK_OUT) output by 6 */
    DL_SYSCTL_CLK_OUT_DIVIDE_6 =
        SYSCTL_GENCLKCFG_EXCLKDIVEN_ENABLE | SYSCTL_GENCLKCFG_EXCLKDIVVAL_DIV6,
    /*! Divide External Clock (CLK_OUT) output by 8 */
    DL_SYSCTL_CLK_OUT_DIVIDE_8 =
        SYSCTL_GENCLKCFG_EXCLKDIVEN_ENABLE | SYSCTL_GENCLKCFG_EXCLKDIVVAL_DIV8,
    /*! Divide External Clock (CLK_OUT) output by 10 */
    DL_SYSCTL_CLK_OUT_DIVIDE_10 = SYSCTL_GENCLKCFG_EXCLKDIVEN_ENABLE |
                                  SYSCTL_GENCLKCFG_EXCLKDIVVAL_DIV10,
    /*! Divide External Clock (CLK_OUT) output by 12 */
    DL_SYSCTL_CLK_OUT_DIVIDE_12 = SYSCTL_GENCLKCFG_EXCLKDIVEN_ENABLE |
                                  SYSCTL_GENCLKCFG_EXCLKDIVVAL_DIV12,
    /*! Divide External Clock (CLK_OUT) output by 14 */
    DL_SYSCTL_CLK_OUT_DIVIDE_14 = SYSCTL_GENCLKCFG_EXCLKDIVEN_ENABLE |
                                  SYSCTL_GENCLKCFG_EXCLKDIVVAL_DIV14,
    /*! Divide External Clock (CLK_OUT) output by 16 */
    DL_SYSCTL_CLK_OUT_DIVIDE_16 = SYSCTL_GENCLKCFG_EXCLKDIVEN_ENABLE |
                                  SYSCTL_GENCLKCFG_EXCLKDIVVAL_DIV16,
} DL_SYSCTL_CLK_OUT_DIVIDE;

/** @enum DL_SYSCTL_MFPCLK_SOURCE */
typedef enum {
    /*! Use System Oscillator (SYSOSC) as MFPCLK source */
    DL_SYSCTL_MFPCLK_SOURCE_SYSOSC = SYSCTL_GENCLKCFG_MFPCLKSRC_SYSOSC,
    /*! Use High Frequency Clock (HFCLK) as MFPCLK source */
    DL_SYSCTL_MFPCLK_SOURCE_HFCLK = SYSCTL_GENCLKCFG_MFPCLKSRC_HFCLK,
} DL_SYSCTL_MFPCLK_SOURCE;

/** @enum DL_SYSCTL_HFCLK_MFPCLK_DIVIDER */
typedef enum {
    /*! HFCLK is not divided before being used for MFPCLK */
    DL_SYSCTL_HFCLK_MFPCLK_DIVIDER_DISABLE = 0x0,
    /*! Divide HFCLK by 2 before being used for MFPCLK */
    DL_SYSCTL_HFCLK_MFPCLK_DIVIDER_2 = 0x1,
    /*! Divide HFCLK by 3 before being used for MFPCLK */
    DL_SYSCTL_HFCLK_MFPCLK_DIVIDER_3 = 0x2,
    /*! Divide HFCLK by 4 before being used for MFPCLK */
    DL_SYSCTL_HFCLK_MFPCLK_DIVIDER_4 = 0x3,
    /*! Divide HFCLK by 5 before being used for MFPCLK */
    DL_SYSCTL_HFCLK_MFPCLK_DIVIDER_5 = 0x4,
    /*! Divide HFCLK by 6 before being used for MFPCLK */
    DL_SYSCTL_HFCLK_MFPCLK_DIVIDER_6 = 0x5,
    /*! Divide HFCLK by 7 before being used for MFPCLK */
    DL_SYSCTL_HFCLK_MFPCLK_DIVIDER_7 = 0x6,
    /*! Divide HFCLK by 8 before being used for MFPCLK */
    DL_SYSCTL_HFCLK_MFPCLK_DIVIDER_8 = 0x7,
    /*! Divide HFCLK by 9 before being used for MFPCLK */
    DL_SYSCTL_HFCLK_MFPCLK_DIVIDER_9 = 0x8,
    /*! Divide HFCLK by 10 before being used for MFPCLK */
    DL_SYSCTL_HFCLK_MFPCLK_DIVIDER_10 = 0x9,
    /*! Divide HFCLK by 11 before being used for MFPCLK */
    DL_SYSCTL_HFCLK_MFPCLK_DIVIDER_11 = 0xA,
    /*! Divide HFCLK by 12 before being used for MFPCLK */
    DL_SYSCTL_HFCLK_MFPCLK_DIVIDER_12 = 0xB,
    /*! Divide HFCLK by 13 before being used for MFPCLK */
    DL_SYSCTL_HFCLK_MFPCLK_DIVIDER_13 = 0xC,
    /*! Divide HFCLK by 14 before being used for MFPCLK */
    DL_SYSCTL_HFCLK_MFPCLK_DIVIDER_14 = 0xD,
    /*! Divide HFCLK by 15 before being used for MFPCLK */
    DL_SYSCTL_HFCLK_MFPCLK_DIVIDER_15 = 0xE,
    /*! Divide HFCLK by 16 before being used for MFPCLK */
    DL_SYSCTL_HFCLK_MFPCLK_DIVIDER_16 = 0xF,
} DL_SYSCTL_HFCLK_MFPCLK_DIVIDER;

/** @enum DL_SYSCTL_FCC_TRIG_TYPE */
typedef enum {
    /*! FCC trigger is rising-edge to rising-edge pulse */
    DL_SYSCTL_FCC_TRIG_TYPE_RISE_RISE = SYSCTL_GENCLKCFG_FCCLVLTRIG_RISE2RISE,
    /*! FCC trigger is active-high pulse level */
    DL_SYSCTL_FCC_TRIG_TYPE_LEVEL = SYSCTL_GENCLKCFG_FCCLVLTRIG_LEVEL,
} DL_SYSCTL_FCC_TRIG_TYPE;

/** @enum DL_SYSCTL_FCC_TRIG_SOURCE */
typedef enum {
    /*! FCC trigger source is FCC_IN external pin */
    DL_SYSCTL_FCC_TRIG_SOURCE_FCC_IN = SYSCTL_GENCLKCFG_FCCTRIGSRC_EXTPIN,
    /*! FCC trigger source is LFCLK */
    DL_SYSCTL_FCC_TRIG_SOURCE_LFCLK = SYSCTL_GENCLKCFG_FCCTRIGSRC_LFCLK,
} DL_SYSCTL_FCC_TRIG_SOURCE;

/** @enum DL_SYSCTL_FCC_CLOCK_SOURCE */
typedef enum {
    /*! FCC clock source to capture is MCLK */
    DL_SYSCTL_FCC_CLOCK_SOURCE_MCLK = SYSCTL_GENCLKCFG_FCCSELCLK_MCLK,
    /*! FCC clock source to capture is SYSOSC */
    DL_SYSCTL_FCC_CLOCK_SOURCE_SYSOSC = SYSCTL_GENCLKCFG_FCCSELCLK_SYSOSC,
    /*! FCC clock source to capture is HFCLK */
    DL_SYSCTL_FCC_CLOCK_SOURCE_HFCLK = SYSCTL_GENCLKCFG_FCCSELCLK_HFCLK,
    /*! FCC clock source to capture is CLK_OUT */
    DL_SYSCTL_FCC_CLOCK_SOURCE_CLK_OUT = SYSCTL_GENCLKCFG_FCCSELCLK_EXTCLK,
    /*! FCC clock source to capture is FCC_IN */
    DL_SYSCTL_FCC_CLOCK_SOURCE_FCC_IN = SYSCTL_GENCLKCFG_FCCSELCLK_FCCIN,
} DL_SYSCTL_FCC_CLOCK_SOURCE;

/** @enum DL_SYSCTL_FCC_TRIG_CNT */
typedef enum {
    /*! One monitoring period */
    DL_SYSCTL_FCC_TRIG_CNT_01 =
        ((uint32_t) 0 << SYSCTL_GENCLKCFG_FCCTRIGCNT_OFS),
    /*! Two monitoring period */
    DL_SYSCTL_FCC_TRIG_CNT_02 =
        ((uint32_t) 1 << SYSCTL_GENCLKCFG_FCCTRIGCNT_OFS),
    /*! Three monitoring period */
    DL_SYSCTL_FCC_TRIG_CNT_03 =
        ((uint32_t) 2 << SYSCTL_GENCLKCFG_FCCTRIGCNT_OFS),
    /*! Four monitoring period */
    DL_SYSCTL_FCC_TRIG_CNT_04 =
        ((uint32_t) 3 << SYSCTL_GENCLKCFG_FCCTRIGCNT_OFS),
    /*! Five monitoring period */
    DL_SYSCTL_FCC_TRIG_CNT_05 =
        ((uint32_t) 4 << SYSCTL_GENCLKCFG_FCCTRIGCNT_OFS),
    /*! Six monitoring period */
    DL_SYSCTL_FCC_TRIG_CNT_06 =
        ((uint32_t) 5 << SYSCTL_GENCLKCFG_FCCTRIGCNT_OFS),
    /*! Seven monitoring period */
    DL_SYSCTL_FCC_TRIG_CNT_07 =
        ((uint32_t) 6 << SYSCTL_GENCLKCFG_FCCTRIGCNT_OFS),
    /*! Eight monitoring period */
    DL_SYSCTL_FCC_TRIG_CNT_08 =
        ((uint32_t) 7 << SYSCTL_GENCLKCFG_FCCTRIGCNT_OFS),
    /*! Nine monitoring period */
    DL_SYSCTL_FCC_TRIG_CNT_09 =
        ((uint32_t) 8 << SYSCTL_GENCLKCFG_FCCTRIGCNT_OFS),
    /*! Ten monitoring period */
    DL_SYSCTL_FCC_TRIG_CNT_10 =
        ((uint32_t) 9 << SYSCTL_GENCLKCFG_FCCTRIGCNT_OFS),
    /*! Eleven monitoring period */
    DL_SYSCTL_FCC_TRIG_CNT_11 =
        ((uint32_t) 10 << SYSCTL_GENCLKCFG_FCCTRIGCNT_OFS),
    /*! Twelve monitoring period */
    DL_SYSCTL_FCC_TRIG_CNT_12 =
        ((uint32_t) 11 << SYSCTL_GENCLKCFG_FCCTRIGCNT_OFS),
    /*! Thirteen monitoring period */
    DL_SYSCTL_FCC_TRIG_CNT_13 =
        ((uint32_t) 12 << SYSCTL_GENCLKCFG_FCCTRIGCNT_OFS),
    /*! Fourteen monitoring period */
    DL_SYSCTL_FCC_TRIG_CNT_14 =
        ((uint32_t) 13 << SYSCTL_GENCLKCFG_FCCTRIGCNT_OFS),
    /*! Fifteen monitoring period */
    DL_SYSCTL_FCC_TRIG_CNT_15 =
        ((uint32_t) 14 << SYSCTL_GENCLKCFG_FCCTRIGCNT_OFS),
    /*! Sixteen monitoring period */
    DL_SYSCTL_FCC_TRIG_CNT_16 =
        ((uint32_t) 15 << SYSCTL_GENCLKCFG_FCCTRIGCNT_OFS),
    /*! Seventeen monitoring period */
    DL_SYSCTL_FCC_TRIG_CNT_17 =
        ((uint32_t) 16 << SYSCTL_GENCLKCFG_FCCTRIGCNT_OFS),
    /*! Eighteen monitoring period */
    DL_SYSCTL_FCC_TRIG_CNT_18 =
        ((uint32_t) 17 << SYSCTL_GENCLKCFG_FCCTRIGCNT_OFS),
    /*! Nineteen monitoring period */
    DL_SYSCTL_FCC_TRIG_CNT_19 =
        ((uint32_t) 18 << SYSCTL_GENCLKCFG_FCCTRIGCNT_OFS),
    /*! Twenty monitoring period */
    DL_SYSCTL_FCC_TRIG_CNT_20 =
        ((uint32_t) 19 << SYSCTL_GENCLKCFG_FCCTRIGCNT_OFS),
    /*! Twenty-one monitoring period */
    DL_SYSCTL_FCC_TRIG_CNT_21 =
        ((uint32_t) 20 << SYSCTL_GENCLKCFG_FCCTRIGCNT_OFS),
    /*! Twenty-two monitoring period */
    DL_SYSCTL_FCC_TRIG_CNT_22 =
        ((uint32_t) 21 << SYSCTL_GENCLKCFG_FCCTRIGCNT_OFS),
    /*! Twenty-three monitoring period */
    DL_SYSCTL_FCC_TRIG_CNT_23 =
        ((uint32_t) 22 << SYSCTL_GENCLKCFG_FCCTRIGCNT_OFS),
    /*! Twenty-four monitoring period */
    DL_SYSCTL_FCC_TRIG_CNT_24 =
        ((uint32_t) 23 << SYSCTL_GENCLKCFG_FCCTRIGCNT_OFS),
    /*! Twenty-five monitoring period */
    DL_SYSCTL_FCC_TRIG_CNT_25 =
        ((uint32_t) 24 << SYSCTL_GENCLKCFG_FCCTRIGCNT_OFS),
    /*! Twenty-six monitoring period */
    DL_SYSCTL_FCC_TRIG_CNT_26 =
        ((uint32_t) 25 << SYSCTL_GENCLKCFG_FCCTRIGCNT_OFS),
    /*! Twenty-seven monitoring period */
    DL_SYSCTL_FCC_TRIG_CNT_27 =
        ((uint32_t) 26 << SYSCTL_GENCLKCFG_FCCTRIGCNT_OFS),
    /*! Twenty-eight monitoring period */
    DL_SYSCTL_FCC_TRIG_CNT_28 =
        ((uint32_t) 27 << SYSCTL_GENCLKCFG_FCCTRIGCNT_OFS),
    /*! Twenty-nine monitoring period */
    DL_SYSCTL_FCC_TRIG_CNT_29 =
        ((uint32_t) 28 << SYSCTL_GENCLKCFG_FCCTRIGCNT_OFS),
    /*! Thirty monitoring period */
    DL_SYSCTL_FCC_TRIG_CNT_30 =
        ((uint32_t) 29 << SYSCTL_GENCLKCFG_FCCTRIGCNT_OFS),
    /*! Thirty-one monitoring period */
    DL_SYSCTL_FCC_TRIG_CNT_31 =
        ((uint32_t) 30 << SYSCTL_GENCLKCFG_FCCTRIGCNT_OFS),
    /*! Thirty-two monitoring period */
    DL_SYSCTL_FCC_TRIG_CNT_32 =
        ((uint32_t) 31 << SYSCTL_GENCLKCFG_FCCTRIGCNT_OFS),
} DL_SYSCTL_FCC_TRIG_CNT;

/** @enum DL_SYSCTL_VBOOST */
typedef enum {
    /*! VBOOST enabled only when COMP/OPA/GPAMP is enabled */
    DL_SYSCTL_VBOOST_ONDEMAND = SYSCTL_GENCLKCFG_ANACPUMPCFG_ONDEMAND,
    /*! VBOOST enabled in RUN/SLEEP, and in STOP/STANDBY if COMP/OPA/GPAMP is enabled */
    DL_SYSCTL_VBOOST_ONACTIVE = SYSCTL_GENCLKCFG_ANACPUMPCFG_ONACTIVE,
    /*! VBOOST enabled in all power modes except SHUTDOWN for fastest startup */
    DL_SYSCTL_VBOOST_ONALWAYS = SYSCTL_GENCLKCFG_ANACPUMPCFG_ONALWAYS,
} DL_SYSCTL_VBOOST;

/** @enum DL_SYSCTL_FLASH_WAIT_STATE */
typedef enum {
    /*! 0 flash wait states */
    DL_SYSCTL_FLASH_WAIT_STATE_0 = ((uint32_t) 0x00000000U),
    /*! 1 flash wait states */
    DL_SYSCTL_FLASH_WAIT_STATE_1 = ((uint32_t) 0x00000100U),
    /*! 2 flash wait states */
    DL_SYSCTL_FLASH_WAIT_STATE_2 = ((uint32_t) 0x00000200U),
} DL_SYSCTL_FLASH_WAIT_STATE;

/** @enum DL_SYSCTL_POWER_POLICY_RUN_SLEEP */
typedef enum {
    /*! RUN/SLEEP power policy is not enabled */
    DL_SYSCTL_POWER_POLICY_RUN_SLEEP_NOT_ENABLED = 0x0,
    /*! Enable RUN0/SLEEP0 power mode policy. */
    DL_SYSCTL_POWER_POLICY_RUN_SLEEP0 = 0x1,
    /*! Enable the RUN1/SLEEP1 power mode policy */
    DL_SYSCTL_POWER_POLICY_RUN_SLEEP1 = 0x2,
    /*! Enable the RUN2/SLEEP2 power mode policy */
    DL_SYSCTL_POWER_POLICY_RUN_SLEEP2 = 0x3,
} DL_SYSCTL_POWER_POLICY_RUN_SLEEP;

/** @enum DL_SYSCTL_POWER_POLICY_STOP */
typedef enum {
    /*! STOP power policy is not enabled */
    DL_SYSCTL_POWER_POLICY_STOP_NOT_ENABLED = 0x0,
    /*! Enable the STOP0 power mode policy */
    DL_SYSCTL_POWER_POLICY_STOP0 = 0x1,
    /*! Enable the STOP1 power mode policy */
    DL_SYSCTL_POWER_POLICY_STOP1 = 0x2,
    /*! Enable the STOP2 power mode policy */
    DL_SYSCTL_POWER_POLICY_STOP2 = 0x3,
} DL_SYSCTL_POWER_POLICY_STOP;

/** @enum DL_SYSCTL_POWER_POLICY_STANDBY */
typedef enum {
    /*! STANDBY power policy is not enabled */
    DL_SYSCTL_POWER_POLICY_STANDBY_NOT_ENABLED = 0x0,
    /*! Enable the STANDBY0 power mode policy */
    DL_SYSCTL_POWER_POLICY_STANDBY0 = 0x1,
    /*! Enable the STANDBY1 power mode policy */
    DL_SYSCTL_POWER_POLICY_STANDBY1 = 0x2,
} DL_SYSCTL_POWER_POLICY_STANDBY;

/** @enum DL_SYSCTL_BOR_THRESHOLD_LEVEL */
typedef enum {
    /*! BOR0 threshold level. This is the minimum allowed threshold.
     * A BOR0- violation will force a re-boot. */
    DL_SYSCTL_BOR_THRESHOLD_LEVEL_0 = SYSCTL_BORTHRESHOLD_LEVEL_BORMIN,
    /*! BOR1 threshold level. A BOR1- violation generates an interrupt */
    DL_SYSCTL_BOR_THRESHOLD_LEVEL_1 = SYSCTL_BORTHRESHOLD_LEVEL_BORLEVEL1,
    /*! BOR2 threshold level. A BOR2- violation generates an interrupt */
    DL_SYSCTL_BOR_THRESHOLD_LEVEL_2 = SYSCTL_BORTHRESHOLD_LEVEL_BORLEVEL2,
    /*! BOR3 threshold level. A BOR3- violation generates an interrupt */
    DL_SYSCTL_BOR_THRESHOLD_LEVEL_3 = SYSCTL_BORTHRESHOLD_LEVEL_BORLEVEL3,
} DL_SYSCTL_BOR_THRESHOLD_LEVEL;

/** @enum DL_SYSCTL_SHUTDOWN_STORAGE_BYTE */
typedef enum {
    /*! Shutdown Storage Byte 0 */
    DL_SYSCTL_SHUTDOWN_STORAGE_BYTE_0 = 0x0,
    /*! Shutdown Storage Byte 1 */
    DL_SYSCTL_SHUTDOWN_STORAGE_BYTE_1 = 0x1,
    /*! Shutdown Storage Byte 2 */
    DL_SYSCTL_SHUTDOWN_STORAGE_BYTE_2 = 0x2,
    /*! Shutdown Storage Byte 3 */
    DL_SYSCTL_SHUTDOWN_STORAGE_BYTE_3 = 0x3,
} DL_SYSCTL_SHUTDOWN_STORAGE_BYTE;

/** @enum DL_SYSCTL_RESET_CAUSE */
typedef enum {
    /*! No Reset Since Last Read */
    DL_SYSCTL_RESET_CAUSE_NO_RESET = SYSCTL_RSTCAUSE_ID_NORST,
    /*! (VDD < POR- violation) or (PMU trim parity fault) or (SHUTDNSTOREx parity fault) */
    DL_SYSCTL_RESET_CAUSE_POR_HW_FAILURE = SYSCTL_RSTCAUSE_ID_PORHWFAIL,
    /*! NRST pin reset (>1s) */
    DL_SYSCTL_RESET_CAUSE_POR_EXTERNAL_NRST = SYSCTL_RSTCAUSE_ID_POREXNRST,
    /*! Software-triggered POR */
    DL_SYSCTL_RESET_CAUSE_POR_SW_TRIGGERED = SYSCTL_RSTCAUSE_ID_PORSW,
    /*! VDD < BOR- violation */
    DL_SYSCTL_RESET_CAUSE_BOR_SUPPLY_FAILURE = SYSCTL_RSTCAUSE_ID_BORSUPPLY,
    /*! Wake from SHUTDOWN */
    DL_SYSCTL_RESET_CAUSE_BOR_WAKE_FROM_SHUTDOWN =
        SYSCTL_RSTCAUSE_ID_BORWAKESHUTDN,
    /*! Non-PMU trim parity fault */
    DL_SYSCTL_RESET_CAUSE_BOOTRST_NON_PMU_PARITY_FAULT =
        SYSCTL_RSTCAUSE_ID_BOOTNONPMUPARITY,
    /*! Fatal clock fault */
    DL_SYSCTL_RESET_CAUSE_BOOTRST_CLOCK_FAULT = SYSCTL_RSTCAUSE_ID_BOOTCLKFAIL,
    /*! Software-triggered BOOTRST */
    DL_SYSCTL_RESET_CAUSE_BOOTRST_SW_TRIGGERED = SYSCTL_RSTCAUSE_ID_BOOTSW,
    /*! NRST pin reset (<1s) */
    DL_SYSCTL_RESET_CAUSE_BOOTRST_EXTERNAL_NRST =
        SYSCTL_RSTCAUSE_ID_BOOTEXNRST,
    /*! BSL exit */
    DL_SYSCTL_RESET_CAUSE_SYSRST_BSL_EXIT = SYSCTL_RSTCAUSE_ID_SYSBSLEXIT,
    /*! BSL entry */
    DL_SYSCTL_RESET_CAUSE_SYSRST_BSL_ENTRY = SYSCTL_RSTCAUSE_ID_SYSBSLENTRY,
    /*! WWDT0 violation */
    DL_SYSCTL_RESET_CAUSE_SYSRST_WWDT0_VIOLATION = SYSCTL_RSTCAUSE_ID_SYSWWDT0,
    /*! WWDT1 violation */
    DL_SYSCTL_RESET_CAUSE_SYSRST_WWDT1_VIOLATION = SYSCTL_RSTCAUSE_ID_SYSWWDT1,
    /*! Uncorrectable flash ECC error */
    DL_SYSCTL_RESET_CAUSE_SYSRST_FLASH_ECC_ERROR =
        SYSCTL_RSTCAUSE_ID_SYSFLASHECC,
    /*! CPULOCK violation */
    DL_SYSCTL_RESET_CAUSE_SYSRST_CPU_LOCKUP_VIOLATION =
        SYSCTL_RSTCAUSE_ID_SYSCPULOCK,
    /*! Debug-triggered SYSRST */
    DL_SYSCTL_RESET_CAUSE_SYSRST_DEBUG_TRIGGERED = SYSCTL_RSTCAUSE_ID_SYSDBG,
    /*! Software-triggered SYSRST */
    DL_SYSCTL_RESET_CAUSE_SYSRST_SW_TRIGGERED = SYSCTL_RSTCAUSE_ID_SYSSW,
    /*! Debug-triggered CPURST */
    DL_SYSCTL_RESET_CAUSE_CPURST_DEBUG_TRIGGERED = SYSCTL_RSTCAUSE_ID_CPUDBG,
    /*! Software-triggered CPURST */
    DL_SYSCTL_RESET_CAUSE_CPURST_SW_TRIGGERED = SYSCTL_RSTCAUSE_ID_CPUSW,
} DL_SYSCTL_RESET_CAUSE;

/**
 *  @brief  Enable sleep on exit
 *
 *  Enables sleep on exit when the CPU moves from handler mode to thread mode.
 *  By enabling, allows an interrupt driven application to avoid returning to
 *  an empty main application.
 */
__STATIC_INLINE void DL_SYSCTL_enableSleepOnExit(void)
{
    SCB->SCR |= SCB_SCR_SLEEPONEXIT_Msk;
}

/**
 *  @brief  Disable sleep on exit
 *
 *  Disables sleep on exit when the CPU moves from handler mode to thread mode.
 */
__STATIC_INLINE void DL_SYSCTL_disableSleepOnExit(void)
{
    SCB->SCR &= ~(SCB_SCR_SLEEPONEXIT_Msk);
}

/**
 *  @brief  Check if sleep on exit is enabled
 */
__STATIC_INLINE bool DL_SYSCTL_isSleepOnExitEnabled(void)
{
    return ((SCB->SCR & SCB_SCR_SLEEPONEXIT_Msk) == SCB_SCR_SLEEPONEXIT_Msk);
}

/**
 *  @brief  Enable send event on pending bit
 *
 *  When enabled, any enabled event and all interrupts (including disabled
 *  interrupts) can wakeup the processor.
 */
__STATIC_INLINE void DL_SYSCTL_enableEventOnPend(void)
{
    SCB->SCR |= SCB_SCR_SEVONPEND_Msk;
}

/**
 *  @brief  Disable send event on pending bit
 *
 *  When disabled, only enabled interrupts or events can wake up the processor.
 *  Disabled interrupts are excluded.
 */
__STATIC_INLINE void DL_SYSCTL_disableEventOnPend(void)
{
    SCB->SCR &= ~(SCB_SCR_SEVONPEND_Msk);
}

/**
 *  @brief   Check if send event on pending bit is enabled
 *
 *  @return  Returns the enabled status of the send event on pending bit
 *
 *  @retval  true  Send event on pending bit is enabled
 *  @retval  false Send event on pending bit is disabled
 */
__STATIC_INLINE bool DL_SYSCTL_isEventOnPendEnabled(void)
{
    return ((SCB->SCR & SCB_SCR_SEVONPEND_Msk) == SCB_SCR_SEVONPEND_Msk);
}

/*!
 *  @brief  Change MCLK source
 *
 *  To ensure good clocking behavior, these are the recommended steps for transition.
 *  Valid sources and destinations: LFCLK, SYSOSC, HSCLK
 *
 *  Depending on current MCLK source, steps to switch to next MCLK source can vary.
 *  This is a macro that redirects to the different possible transitions.
 *
 *  Only valid for RUN modes. In low power modes, MCLK transitions are handled by hardware.
 *
 *  @note Different transition APIs may require different input parameters
 *  Transitions between LFCLK and HSCLK requires going through SYSOSC.
 *
 *  @sa DL_SYSCTL_switchMCLKfromSYSOSCtoLFCLK
 *  @sa DL_SYSCTL_switchMCLKfromLFCLKtoSYSOSC
 *  @sa DL_SYSCTL_switchMCLKfromSYSOSCtoHSCLK
 *  @sa DL_SYSCTL_switchMCLKfromHSCLKtoSYSOSC
 */
#define DL_SYSCTL_setMCLKSource(current, next, ...) \
    DL_SYSCTL_switchMCLKfrom##current##to##next(__VA_ARGS__);

/**
 *  @brief  Change MCLK source from SYSOSC to LFCLK
 *
 *  @pre    If disabling SYSOSC, high speed oscillators (HFXT,...) must be disabled beforehand.
 *  @post   MCLK source is switched to LFCLK, function will busy-wait until confirmed.
 *
 *  @param[in] disableSYSOSC   Whether to leave SYSOSC running or not
 */
void DL_SYSCTL_switchMCLKfromSYSOSCtoLFCLK(bool disableSYSOSC);

/**
 *  @brief  Change MCLK source from LFCLK to SYSOSC
 *
 *  @post   MCLK source is switched to SYSOSC, function will busy-wait until confirmed.
 */
void DL_SYSCTL_switchMCLKfromLFCLKtoSYSOSC(void);

/**
 *  @brief  Change MCLK source from SYSOSC to HSCLK
 *
 *  @pre    The desired HSCLK source is enabled beforehand (HFXT, HFCLK_IN).
 *  @post   MCLK source is switched to HSCLK, function will busy-wait until confirmed.
 *
 *  @param[in] source   Desired high-speed clock source
 */
void DL_SYSCTL_switchMCLKfromSYSOSCtoHSCLK(DL_SYSCTL_HSCLK_SOURCE source);

/**
 *  @brief  Change MCLK source from HSCLK to SYSOSC
 *
 *  @pre    MCLK is sourced from a valid, running HSCLK source (HFXT, HFCLK_IN)
 *  @post   MCLK source is switched to SYSOSC, function will busy-wait until confirmed.
 *
 *  @note   No HSCLK sources are disabled by this function
 */
void DL_SYSCTL_switchMCLKfromHSCLKtoSYSOSC(void);

/**
 *  @brief     Set the RUN/SLEEP mode power policy to RUN0/SLEEP0
 *
 * In RUN0, the MCLK and the CPUCLK run from a fast clock source (SYSOSC, or
 * HFCLK).
 *
 * Setting the RUN power policy will also set the SLEEP power policy.
 * The SLEEP mode behavior is always identical to RUN mode, just with the
 * CPUCLK disabled. As such, the SLEEP behavior is determined by the
 * configuration of the RUN mode. To actually enter SLEEP mode, you must call
 * `__WFI()` to wait for interrupts or `__WFE()` to wait for ARM events.
 * `__WFI()` is used in interrupt-driven applications, and `__WFE()` is used
 * for interactions between the interrupt handler and main application.
 *
 * There are three RUN/SLEEP mode policy options: RUN0/SLEEP0, RUN1/SLEEP1,
 * and RUN2/SLEEP2. Refer to the device TRM for more information on each policy
 *
 * @sa DL_SYSCTL_setMCLKSource
 */
__STATIC_INLINE void DL_SYSCTL_setPowerPolicyRUN0SLEEP0(void)
{
    DL_SYSCTL_setMCLKSource(LFCLK, SYSOSC);
    SCB->SCR &= ~(SCB_SCR_SLEEPDEEP_Msk);
}

/**
 *  @brief     Set the RUN/SLEEP mode power policy to RUN1/SLEEP1
 *
 * In RUN1, the MCLK and the CPUCLK run from LFCLK (at 32kHz) to reduce active
 * power, but SYSOSC is left enabled to service analog modules such as an ADC,
 * DAC, OPA, or COMP (in HS mode).
 *
 * Setting the RUN power policy will also set the SLEEP power policy.
 * The SLEEP mode behavior is always identical to RUN mode, just with the
 * CPUCLK disabled. As such, the SLEEP behavior is determined by the
 * configuration of the RUN mode. To actually enter SLEEP mode, you must call
 * `__WFI()` to wait for interrupts or `__WFE()` to wait for ARM events.
 * `__WFI()` is used in interrupt-driven applications, and `__WFE()` is used
 * for interactions between the interrupt handler and main application.
 *
 * There are three RUN/SLEEP mode policy options: RUN0/SLEEP0, RUN1/SLEEP1,
 * and RUN2/SLEEP2. Refer to the device TRM for more information on each policy
 *
 * @sa DL_SYSCTL_setMCLKSource
 */
__STATIC_INLINE void DL_SYSCTL_setPowerPolicyRUN1SLEEP1(void)
{
    DL_SYSCTL_setMCLKSource(SYSOSC, LFCLK, (bool) false);
    SCB->SCR &= ~(SCB_SCR_SLEEPDEEP_Msk);
}

/**
 *  @brief     Set the RUN/SLEEP mode power policy to RUN2/SLEEP2
 *
 * In RUN2, the MCLK and the CPUCLK run from LFCLK (at 32kHz), and SYSOSC is
 * completely disabled to save power. This is the lowest power state with
 * the CPU running
 *
 * Setting the RUN power policy will also set the SLEEP power policy.
 * The SLEEP mode behavior is always identical to RUN mode, just with the
 * CPUCLK disabled. As such, the SLEEP behavior is determined by the
 * configuration of the RUN mode. To actually enter SLEEP mode, you must call
 * `__WFI()` to wait for interrupts or `__WFE()` to wait for ARM events.
 * `__WFI()` is used in interrupt-driven applications, and `__WFE()` is used
 * for interactions between the interrupt handler and main application.
 *
 * There are three RUN/SLEEP mode policy options: RUN0/SLEEP0, RUN1/SLEEP1,
 * and RUN2/SLEEP2. Refer to the device TRM for more information on each policy
 *
 * @note Since this turns off SYSOSC, HSCLK sources MUST be disabled before calling
 *
 * @sa DL_SYSCTL_setMCLKSource
 */
__STATIC_INLINE void DL_SYSCTL_setPowerPolicyRUN2SLEEP2(void)
{
    DL_SYSCTL_setMCLKSource(SYSOSC, LFCLK, (bool) true);
    SCB->SCR &= ~(SCB_SCR_SLEEPDEEP_Msk);
}

/**
 *  @brief     Get the RUN/SLEEP mode power policy
 *
 * Get which RUN/SLEEP power policy has been set.
 *
 * The SLEEP mode behavior is always identical to RUN mode, just with the
 * CPUCLK disabled. As such, the SLEEP behavior is determined by the
 * configuration of the RUN mode.
 *
 *  @return  Returns the current RUN/SLEEP mode power policy
 *
 *  @retval  One of @ref DL_SYSCTL_POWER_POLICY_RUN_SLEEP

 */
DL_SYSCTL_POWER_POLICY_RUN_SLEEP DL_SYSCTL_getPowerPolicyRUNSLEEP(void);

/**
 *  @brief     Set the STOP mode power policy to STOP0
 *
 * In STOP0, the SYSOSC is left running at the current frequency when entering
 * STOP mode (either 32MHz, 24MHz, 16MHz, or 4MHz). ULPCLK is always limited
 * to 4MHz automatically by hardware, but SYSOSC is not disturbed to support
 * consistent operation of analog peripherals such as the ADC, OPA, or COMP.
 *
 * There are three STOP mode policy options: STOP0, STOP1, and STOP2.
 * Refer to the device TRM for more information on each policy.
 *
 * @post This API does not actually enter STOP mode. After using this API to
 * set the power policy, to enter STOP mode you must call `__WFI()` to
 * wait for interrupts or `__WFE()` to wait for ARM events. `__WFI()` is used
 * in interrupt-driven applications, and `__WFE()` is used for interactions
 * between the interrupt handler and main application.
 */
__STATIC_INLINE void DL_SYSCTL_setPowerPolicySTOP0(void)
{
    SYSCTL->SOCLOCK.PMODECFG = SYSCTL_PMODECFG_DSLEEP_STOP;
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
    SYSCTL->SOCLOCK.SYSOSCCFG &= ~(
        SYSCTL_SYSOSCCFG_USE4MHZSTOP_MASK | SYSCTL_SYSOSCCFG_DISABLESTOP_MASK);
}

/**
 *  @brief     Set the STOP mode power policy to STOP1
 *
 * In STOP1, the SYSOSC is gear shifted from its current frequency to 4MHz for
 * the lowest power consumption in STOP mode with SYSOSC running. SYSOSC and
 * ULPCLK both run at 4MHz.
 *
 * There are three STOP mode policy options: STOP0, STOP1, and STOP2.
 * Refer to the device TRM for more information on each policy.
 *
 * @post This API does not actually enter STOP mode. After using this API to
 * set the power policy, to enter STOP mode you must call `__WFI()` to
 * wait for interrupts or `__WFE()` to wait for ARM events. `__WFI()` is used
 * in interrupt-driven applications, and `__WFE()` is used for interactions
 * between the interrupt handler and main application.
 */
__STATIC_INLINE void DL_SYSCTL_setPowerPolicySTOP1(void)
{
    SYSCTL->SOCLOCK.PMODECFG = SYSCTL_PMODECFG_DSLEEP_STOP;
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
    SYSCTL->SOCLOCK.SYSOSCCFG |= SYSCTL_SYSOSCCFG_USE4MHZSTOP_MASK;
    SYSCTL->SOCLOCK.SYSOSCCFG &= ~(SYSCTL_SYSOSCCFG_DISABLESTOP_MASK);
}

/**
 *  @brief     Set the STOP mode power policy to STOP2
 *
 * In STOP2, the SYSOSC is disabled and the ULPCLK is sourced from LFCLK at
 * 32kHz. This is the lowest power state in STOP mode.
 *
 * There are three STOP mode policy options: STOP0, STOP1, and STOP2.
 * Refer to the device TRM for more information on each policy.
 *
 * @post This API does not actually enter STOP mode. After using this API to
 * set the power policy, to enter STOP mode you must call `__WFI()` to
 * wait for interrupts or `__WFE()` to wait for ARM events. `__WFI()` is used
 * in interrupt-driven applications, and `__WFE()` is used for interactions
 * between the interrupt handler and main application.
 */
__STATIC_INLINE void DL_SYSCTL_setPowerPolicySTOP2(void)
{
    SYSCTL->SOCLOCK.PMODECFG = SYSCTL_PMODECFG_DSLEEP_STOP;
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
    SYSCTL->SOCLOCK.SYSOSCCFG &= ~(SYSCTL_SYSOSCCFG_USE4MHZSTOP_MASK);
    SYSCTL->SOCLOCK.SYSOSCCFG |= SYSCTL_SYSOSCCFG_DISABLESTOP_MASK;
}

/**
 *  @brief     Get the STOP mode power policy
 *
 * Get which STOP power policy has been set.
 *
 *  @return  Returns the current STOP mode power policy
 *
 *  @retval  One of @ref DL_SYSCTL_POWER_POLICY_STOP if a STOP power policy
 */
DL_SYSCTL_POWER_POLICY_STOP DL_SYSCTL_getPowerPolicySTOP(void);

/**
 *  @brief     Set the STANDBY mode power policy to STANDBY0
 *
 * In STANDBY0, all PD0 peripherals receive the ULPCLK and LFCLK, and the RTC
 * receives RTCCLK.
 *
 * There are two STANDBY mode policy options: STANDBY0 and STANDBY1.
 *
 * @post This API does not actually enter STANDBY mode. After using this API to
 * set the power policy, to enter STANDBY mode you must call `__WFI()` to
 * wait for interrupts or `__WFE()` to wait for ARM events. `__WFI()` is used
 * in interrupt-driven applications, and `__WFE()` is used for interactions
 * between the interrupt handler and main application.
 */
__STATIC_INLINE void DL_SYSCTL_setPowerPolicySTANDBY0(void)
{
    SYSCTL->SOCLOCK.PMODECFG = SYSCTL_PMODECFG_DSLEEP_STANDBY;
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
    SYSCTL->SOCLOCK.MCLKCFG &= ~(SYSCTL_MCLKCFG_STOPCLKSTBY_MASK);
}

/**
 *  @brief     Set the STANDBY mode power policy to STANDBY1
 *
 * In STANDBY1, only TIMG0 and TIMG1 receive ULPCLK/LFCLK. The RTC continues
 * to receive RTCCLK. A TIMG0/1 interrupt, RTC interrupt, or ADC trigger in
 * STANDBY1 always triggers an asynchronous fast clock request to wake the
 * system. Other PD0 peripherals (such as UART, I2C, GPIO, and COMP) can also
 * wake the system upon an external event through an asynchronous fast clock
 * request, but they are not actively clocked in STANDBY1.
 *
 * There are two STANDBY mode policy options: STANDBY0 and STANDBY1.
 *
 * @post This API does not actually enter STANDBY mode. After using this API to
 * set the power policy, to enter STANDBY mode you must call `__WFI()` to
 * wait for interrupts or `__WFE()` to wait for ARM events. `__WFI()` is used
 * in interrupt-driven applications, and `__WFE()` is used for interactions
 * between the interrupt handler and main application.
 */
__STATIC_INLINE void DL_SYSCTL_setPowerPolicySTANDBY1(void)
{
    SYSCTL->SOCLOCK.PMODECFG = SYSCTL_PMODECFG_DSLEEP_STANDBY;
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
    SYSCTL->SOCLOCK.MCLKCFG |= SYSCTL_MCLKCFG_STOPCLKSTBY_MASK;
}

/**
 *  @brief     Get the STANDBY mode power policy
 *
 * Get which STANDBY power policy has been set.
 *
 *  @return  Returns the current STANDBY mode power policy
 *
 *  @retval  One of @ref DL_SYSCTL_POWER_POLICY_STANDBY
 */
DL_SYSCTL_POWER_POLICY_STANDBY DL_SYSCTL_getPowerPolicySTANDBY(void);

/**
 *  @brief     Set power policy to SHUTDOWN mode
 *
 * In SHUTDOWN mode, no clocks are available. The core regulator is completely
 * disabled and all SRAM and register contents are lost, with the exception of
 * the 4 bytes of general purpose memory in SYSCTL which may be used to store
 * state information. The BOR and bandgap circuit are disabled. The device may
 * wake up via a wake-up capable IO, a debug connection, or NRST. SHUTDOWN mode
 * has the lowest current consumption of any operating mode. Exiting SHUTDOWN
 * mode triggers a BOR.
 *
 * There is only one SHUTDOWN mode policy option: SHUTDOWN.
 *
 * @post This API does not actually enter SHUTDOWN mode. After using this API
 * to enable SHUTDOWN mode, to enter SHUTDOWN mode you must call `__WFI()` to
 * wait for interrupts or `__WFE()` to wait for ARM events. `__WFI()` is used
 * in interrupt-driven applications, and `__WFE()` is used for interactions
 * between the interrupt handler and main application.
 */
__STATIC_INLINE void DL_SYSCTL_setPowerPolicySHUTDOWN(void)
{
    SYSCTL->SOCLOCK.PMODECFG = SYSCTL_PMODECFG_DSLEEP_SHUTDOWN;
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
}

/**
 *  @brief     Set the brown-out reset (BOR) threshold level
 *
 *  Note that this API does NOT activate the BOR threshold. After setting the
 *  threshold level with this API, call @ref DL_SYSCTL_activateBORThreshold
 *  to actually activate the new threshold.
 *
 * During startup, the BOR threshold defaults to BOR0 (the lowet value) to
 * ensure the device always starts at the specified VDD minimum. After boot,
 * the BOR threshold level can be configured to a different level. When the
 * BOR threshold is BOR0, a BOR0- violation always generates a BOR- violation
 * signal to SYSCTL, generating a BOR level reset. When the BOR threshold is
 * re-configured to BOR1, BOR2, or BOR3 the BOR circuit will generate a SYSCTL
 * interrupt rather than asserting a BOR- violation. This may be used to give
 * the application an indication that the supply has dropped below a certain
 * level without causing a reset. If the BOR is in interrupt mode (threshold
 * level of BOR1-3), and VDD drops below the respective BORx- level, an
 * interrupt will be generated and the BOR circuit will automatically switch
 * the BOR threshold level to BOR0 to ensure that a BOR- violation is
 * asserted if VDD drops below BOR0-.
 *
 *  @param[in]  thresholdLevel  The BOR threshold level to set.
 *                              One of @ref DL_SYSCTL_BOR_THRESHOLD_LEVEL.
 *
 *  @post       DL_SYSCTL_activateBORThreshold
 */
__STATIC_INLINE void DL_SYSCTL_setBORThreshold(
    DL_SYSCTL_BOR_THRESHOLD_LEVEL thresholdLevel)
{
    SYSCTL->SOCLOCK.BORTHRESHOLD = (uint32_t) thresholdLevel;
}

/**
 *  @brief   Get the brown-out reset (BOR) threshold level
 *
 *  @return  Returns the current BOR threshold level.
 *
 *  @retval  One of @ref DL_SYSCTL_BOR_THRESHOLD_LEVEL
 */
__STATIC_INLINE DL_SYSCTL_BOR_THRESHOLD_LEVEL DL_SYSCTL_getBORThreshold(void)
{
    return (DL_SYSCTL_BOR_THRESHOLD_LEVEL)(SYSCTL->SOCLOCK.BORTHRESHOLD);
}

/**
 *  @brief      Activate the BOR threshold level
 *
 *  Attempts to change the active BOR mode to the BOR threshold that was set
 *  via @ref DL_SYSCTL_setBORThreshold.
 *
 *  Setting this bit also clears any prior BOR violation status indications.
 *
 *  After calling this API, the change can be validated by calling
 *  @ref DL_SYSCTL_getStatus and checking the return value.
 *
 *  @pre        DL_SYSCTL_setBORThreshold
 */
__STATIC_INLINE void DL_SYSCTL_activateBORThreshold(void)
{
    SYSCTL->SOCLOCK.BORCLRCMD =
        SYSCTL_BORCLRCMD_KEY_VALUE | SYSCTL_BORCLRCMD_GO_TRUE;
}

/**
 *  @brief      Resets the device
 *
 *  Resets the device using the type of reset selected. This function does not
 *  return, the reset will happen immediately.
 *
 *  @param[in]  resetType  Type of reset to perform. One of @ref
 *                         DL_SYSCTL_RESET.
 */
__STATIC_INLINE void DL_SYSCTL_resetDevice(uint32_t resetType)
{
    SYSCTL->SOCLOCK.RESETLEVEL = resetType;
    SYSCTL->SOCLOCK.RESETCMD =
        SYSCTL_RESETCMD_KEY_VALUE | SYSCTL_RESETCMD_GO_TRUE;
}

/**
 *  @brief      Enable SYSCTL interrupts
 *
 *  @param[in]  interruptMask  Bit mask of interrupts to enable. Bitwise OR of
 *                             @ref DL_SYSCTL_INTERRUPT.
 */
__STATIC_INLINE void DL_SYSCTL_enableInterrupt(uint32_t interruptMask)
{
    SYSCTL->SOCLOCK.IMASK |= interruptMask;
}

/**
 *  @brief      Disable SYSCTL interrupts
 *
 *  @param[in]  interruptMask  Bit mask of interrupts to enable. Bitwise OR of
 *                             @ref DL_SYSCTL_INTERRUPT.
 */
__STATIC_INLINE void DL_SYSCTL_disableInterrupt(uint32_t interruptMask)
{
    SYSCTL->SOCLOCK.IMASK &= ~(interruptMask);
}

/**
 *  @brief      Check which SYSCTL interrupts are enabled
 *
 *  @param[in]  interruptMask  Bit mask of interrupts to check. Bitwise OR of
 *                             @ref DL_SYSCTL_INTERRUPT.
 *
 *  @return     Which of the requested SYSCTL interrupts are enabled
 *
 *  @retval     Bitwise OR of @ref DL_SYSCTL_INTERRUPT values
 */
__STATIC_INLINE uint32_t DL_SYSCTL_getEnabledInterrupts(uint32_t interruptMask)
{
    return (SYSCTL->SOCLOCK.IMASK & interruptMask);
}

/**
 *  @brief      Check interrupt flag of enabled SYSCTL interrupts
 *
 *  Checks if any of the SYSCTL interrupts that were previously enabled are
 *  pending.
 *
 *  @param[in]  interruptMask  Bit mask of interrupts to check. Bitwise OR of
 *                             @ref DL_SYSCTL_INTERRUPT.
 *
 *  @return     Which of the requested SYSCTL interrupts are pending
 *
 *  @retval     Bitwise OR of @ref DL_SYSCTL_INTERRUPT values
 *
 *  @sa         DL_SYSCTL_enableInterrupt
 */
__STATIC_INLINE uint32_t DL_SYSCTL_getEnabledInterruptStatus(
    uint32_t interruptMask)
{
    return (SYSCTL->SOCLOCK.MIS & interruptMask);
}

/**
 *  @brief      Check interrupt flag of any SYSCTL interrupt
 *
 *  Checks if any of the SYSCTL interrupts are pending. Interrupts do not have to
 *  be previously enabled.
 *
 *  @param[in]  interruptMask  Bit mask of interrupts to check. Bitwise OR of
 *                             @ref DL_SYSCTL_INTERRUPT.
 *
 *  @return     Which of the requested SYSCTL interrupts are pending
 *
 *  @retval     Bitwise OR of @ref DL_SYSCTL_INTERRUPT values
 */
__STATIC_INLINE uint32_t DL_SYSCTL_getRawInterruptStatus(
    uint32_t interruptMask)
{
    return (SYSCTL->SOCLOCK.RIS & interruptMask);
}

/**
 *  @brief      Get highest priority pending SYSCTL interrupt
 *
 *  Checks if any of the SYSCTL interrupts are pending. Interrupts do not have to
 *  be previously enabled.
 *
 *  @return     The highest priority pending SYSCTL interrupt
 *
 *  @retval     One of @ref DL_SYSCTL_IIDX values
 */
__STATIC_INLINE DL_SYSCTL_IIDX DL_SYSCTL_getPendingInterrupt(void)
{
    return (DL_SYSCTL_IIDX)(SYSCTL->SOCLOCK.IIDX);
}

/**
 *  @brief      Clear pending SYSCTL interrupts
 *
 *  @param[in]  interruptMask  Bit mask of interrupts to clear. Bitwise OR of
 *                             @ref DL_SYSCTL_INTERRUPT.
 */
__STATIC_INLINE void DL_SYSCTL_clearInterruptStatus(uint32_t interruptMask)
{
    SYSCTL->SOCLOCK.ICLR = interruptMask;
}

/**
 *  @brief      Check interrupt flag of any SYSCTL non-maskable interrupt
 *
 *  Checks if any of the SYSCTL non-maskable interrupts are pending. Interrupts
 *  do not have to be previously enabled.
 *
 *  @param[in]  interruptMask  Bit mask of interrupts to check. Bitwise OR of
 *                             @ref DL_SYSCTL_NMI.
 *
 *  @return     Which of the requested SYSCTL non-maskable interrupts are pending
 *
 *  @retval     Bitwise OR of @ref DL_SYSCTL_NMI values
 */
__STATIC_INLINE uint32_t DL_SYSCTL_getRawNonMaskableInterruptStatus(
    uint32_t interruptMask)
{
    return (SYSCTL->SOCLOCK.NMIRIS & interruptMask);
}

/**
 *  @brief      Get highest priority pending SYSCTL non-maskable interrupt
 *
 *  Checks if any of the SYSCTL non-maskable interrupts are pending. Interrupts
 *  do not have to be previously enabled.
 *
 *  @return     The highest priority pending SYSCTL non-maskable interrupt
 *
 *  @retval     One of @ref DL_SYSCTL_NMI_IIDX values
 */
__STATIC_INLINE DL_SYSCTL_NMI_IIDX DL_SYSCTL_getPendingNonMaskableInterrupt(
    void)
{
    return (DL_SYSCTL_NMI_IIDX)(SYSCTL->SOCLOCK.NMIIIDX);
}

/**
 *  @brief      Clear pending SYSCTL non-maskable interrupts
 *
 *  @param[in]  interruptMask  Bit mask of interrupts to clear. Bitwise OR of
 *                             @ref DL_SYSCTL_NMI.
 */
__STATIC_INLINE void DL_SYSCTL_clearNonMaskableInterruptStatus(
    uint32_t interruptMask)
{
    SYSCTL->SOCLOCK.NMIICLR = interruptMask;
}

/**
 *  @brief  Set the behavior when a WWDT0 error occurs
 *
 *  Configures whether a WWDT0 error will trigger a BOOTRST or an NMI
 * (non-maskable interrupt). By default, this error will trigger a BOOTRST.
 *
 *  @param[in] behavior The behavior when a Flash ECC DED occurrs
 *
 *  @sa        DL_SYSCTL_enableNonMaskableInterrupt
 */
__STATIC_INLINE void DL_SYSCTL_setWWDT0ErrorBehavior(
    DL_SYSCTL_ERROR_BEHAVIOR behavior)
{
    DL_Common_updateReg(&SYSCTL->SOCLOCK.SYSTEMCFG,
        (((uint32_t) behavior << SYSCTL_SYSTEMCFG_WWDTLP0RSTDIS_OFS)) |
            SYSCTL_SYSTEMCFG_KEY_VALUE,
        (SYSCTL_SYSTEMCFG_WWDTLP0RSTDIS_MASK | SYSCTL_SYSTEMCFG_KEY_MASK));
}

/**
 *  @brief  Get the behavior when a WWDT0 error occurs
 *
 *  By default, this error will trigger a BOOTRST.
 *
 *  @return The behavior when a WWDT0 error occurs
 *
 *  @retval One of @ref DL_SYSCTL_ERROR_BEHAVIOR
 */
__STATIC_INLINE DL_SYSCTL_ERROR_BEHAVIOR DL_SYSCTL_getWWDT0ErrorBehavior(void)
{
    uint32_t behavior =
        (SYSCTL->SOCLOCK.SYSTEMCFG & SYSCTL_SYSTEMCFG_WWDTLP0RSTDIS_MASK) >>
        SYSCTL_SYSTEMCFG_WWDTLP0RSTDIS_OFS;

    return (DL_SYSCTL_ERROR_BEHAVIOR)(behavior);
}

/**
 *  @brief Set the Main Clock (MCLK) divider (MDIV)
 *
 *  Additionally, can use this function to disable MDIV. MDIV must be disabled
 *  before changing SYSOSC frequency.
 *
 *  MDIV is not valid if MCLK source is HSCLK.
 *  MDIV is not used if MCLK source if LFCLK.
 *
 *  @param[in] divider Should be DL_SYSCTL_MCLK_DIVIDER_DISABLE if source is
 *  HSCLK, a don't care if LFCLK, and one of DL_SYSCTL_MCLK_DIVIDER if SYSOSC.
 */
__STATIC_INLINE void DL_SYSCTL_setMCLKDivider(DL_SYSCTL_MCLK_DIVIDER divider)
{
    DL_Common_updateReg(&SYSCTL->SOCLOCK.MCLKCFG, (uint32_t) divider,
        SYSCTL_MCLKCFG_MDIV_MASK);
}
/**
 *  @brief Get the Main Clock (MCLK) divider (MDIV)
 *
 *  @return The value of the Main Clock (MCLK) divider (MDIV)
 *
 *  @retval Should be DL_SYSCTL_MCLK_DIVIDER_DISABLE if source is HSCLK, a
 *  don't care if LFCLK, and one of DL_SYSCTL_MCLK_DIVIDER if SYSOSC.
 */
__STATIC_INLINE DL_SYSCTL_MCLK_DIVIDER DL_SYSCTL_getMCLKDivider(void)
{
    uint32_t divider = SYSCTL->SOCLOCK.MCLKCFG & SYSCTL_MCLKCFG_MDIV_MASK;

    return (DL_SYSCTL_MCLK_DIVIDER)(divider);
}

/**
 *  @brief   Get the source for the Main Clock (MCLK)
 *
 *  @return  The source for the Main Clock (MCLK)
 *
 *  @retval  One of @ref DL_SYSCTL_MCLK_SOURCE
 */
__STATIC_INLINE DL_SYSCTL_MCLK_SOURCE DL_SYSCTL_getMCLKSource(void)
{
    uint32_t source =
        SYSCTL->SOCLOCK.MCLKCFG &
        (SYSCTL_MCLKCFG_USEHSCLK_MASK | SYSCTL_MCLKCFG_USELFCLK_MASK);

    return (DL_SYSCTL_MCLK_SOURCE)(source);
}

/**
 *  @brief     Set the target frequency of the System Oscillator (SYSOSC)
 *
 *  Target/desired SYSOSC frequency may be different than current/actual SYSOSC
 *  frequency during gear shift and other operations.
 *
 *  The System Oscillator (SYSOSC) is an on-chip, accurate, configurable
 *  oscillator with factory trimmed support for 32MHz (base frequency) and 4MHz
 *  (low frequency) operation.
 *  It can also operate at 16MHz or 24MHz by using the
 *  @ref DL_SYSCTL_configSYSOSCUserTrim function instead.
 *
 *  SYSOSC provides a flexible high-speed clock source for the system in cases
 *  where the HFXT is either not present or not used.
 *
 *  MDIV must be disabled before changing SYSOSC freq. See @ref DL_SYSCTL_setMCLKDivider.
 *
 *  @param[in] freq  Target frequency to use for the System Oscillator (SYSOSC).
 *                  @ref DL_SYSCTL_SYSOSC_FREQ_4M or @ref DL_SYSCTL_SYSOSC_FREQ_BASE.
 *
 *  @sa DL_SYSCTL_configSYSOSCUserTrim
 *  @sa DL_SYSCTL_setMCLKDivider
 */
__STATIC_INLINE void DL_SYSCTL_setSYSOSCFreq(DL_SYSCTL_SYSOSC_FREQ freq)
{
    DL_Common_updateReg(&SYSCTL->SOCLOCK.SYSOSCCFG, (uint32_t) freq,
        SYSCTL_SYSOSCCFG_FREQ_MASK);
}

/**
 *  @brief     Trim the System Oscillator (SYSOSC) to 16MHz or 24MHz
 *
 *  The trim values supplied in the config struct must be determined by
 *  experimentation. Please refer to the "SYSOSC User Trim Procedure" section
 *  in the CKM Technical Reference Manual.
 *  Each device must be trimmed individually for accuracy.
 *
 *  MDIV must be disabled before changing SYSOSC freq. See @ref DL_SYSCTL_setMCLKDivider.
 *
 *  @param[in]  config         Pointer to the SYSOSC user trim configuration struct
 *                             @ref DL_SYSCTL_SYSOSCUserTrimConfig.
 *
 *  @sa DL_SYSCTL_setSYSOSCFreq
 *  @sa DL_SYSCTL_setMCLKDivider
 */
__STATIC_INLINE void DL_SYSCTL_configSYSOSCUserTrim(
    DL_SYSCTL_SYSOSCUserTrimConfig *config)
{
    SYSCTL->SOCLOCK.SYSOSCTRIMUSER =
        ((config->rDiv << SYSCTL_SYSOSCTRIMUSER_RDIV_OFS) &
            SYSCTL_SYSOSCTRIMUSER_RDIV_MASK) |
        ((config->resistorFine << SYSCTL_SYSOSCTRIMUSER_RESFINE_OFS) &
            SYSCTL_SYSOSCTRIMUSER_RESFINE_MASK) |
        ((config->resistorCoarse << SYSCTL_SYSOSCTRIMUSER_RESCOARSE_OFS) &
            SYSCTL_SYSOSCTRIMUSER_RESCOARSE_MASK) |
        (config->capacitor << SYSCTL_SYSOSCTRIMUSER_CAP_OFS) |
        ((uint32_t) config->freq);
    DL_Common_updateReg(&SYSCTL->SOCLOCK.SYSOSCCFG,
        SYSCTL_SYSOSCCFG_FREQ_SYSOSCUSER, SYSCTL_SYSOSCCFG_FREQ_MASK);
}

/**
 *  @brief   Get the target frequency of the System Oscillator (SYSOSC)
 *  Target/desired SYSOSC frequency may be different than current/actual SYSOSC
 *  frequency during gear shift and other operations.
 *  This function matches what is input by @ref DL_SYSCTL_setSYSOSCFreq.
 *
 *  @return  The target frequency of System Oscillator (SYSOSC). One of
 *           @ref DL_SYSCTL_SYSOSC_FREQ.
 */
__STATIC_INLINE DL_SYSCTL_SYSOSC_FREQ DL_SYSCTL_getTargetSYSOSCFreq(void)
{
    uint32_t freq = SYSCTL->SOCLOCK.SYSOSCCFG & SYSCTL_SYSOSCCFG_FREQ_MASK;

    return (DL_SYSCTL_SYSOSC_FREQ)(freq);
}

/**
 *  @brief   Get the current frequency of the System Oscillator (SYSOSC)
 *  Current/actual SYSOSC frequency may be different than target/desired SYSOSC
 *  frequency during gear shift and other operations.
 *
 *  @return  The current frequency of System Oscillator (SYSOSC). One of
 *           @ref DL_SYSCTL_SYSOSC_FREQ.
 */
__STATIC_INLINE DL_SYSCTL_SYSOSC_FREQ DL_SYSCTL_getCurrentSYSOSCFreq(void)
{
    uint32_t freq =
        SYSCTL->SOCLOCK.CLKSTATUS & SYSCTL_CLKSTATUS_SYSOSCFREQ_MASK;

    return (DL_SYSCTL_SYSOSC_FREQ)(freq);
}

/**
 *  @brief   Returns status of the different clocks in CKM
 *
 *  @return  Full status of all clock selections
 *
 *  @retval  Bitwise OR of @ref DL_SYSCTL_CLK_STATUS.
 */
__STATIC_INLINE uint32_t DL_SYSCTL_getClockStatus(void)
{
    return (SYSCTL->SOCLOCK.CLKSTATUS);
}

/**
 *  @brief   Returns general status of SYSCTL
 *
 *  @return  Full status of all general conditions in SYSCTL
 *
 *  @retval  Bitwise OR of @ref DL_SYSCTL_STATUS.
 */
__STATIC_INLINE uint32_t DL_SYSCTL_getStatus(void)
{
    return (SYSCTL->SOCLOCK.SYSSTATUS);
}

/**
 *  @brief   Clear the ECC error bits in SYSSTATUS
 *
 *  The ECC error bits in SYSSTATUS are sticky (they remain set when an ECC
 *  error occurs even if future reads do not have errors), and can be
 *  cleared through this API.
 */
__STATIC_INLINE void DL_SYSCTL_clearECCErrorStatus(void)
{
    SYSCTL->SOCLOCK.SYSSTATUSCLR =
        (SYSCTL_SYSSTATUSCLR_ALLECC_CLEAR | SYSCTL_SYSSTATUSCLR_KEY_VALUE);
}

/**
 *  @brief Change LFCLK source to external crystal LFXT
 *
 * LFOSC is the internal 32kHz oscillator and default LFCLK source after a BOR.
 * Once LFCLK source is changed, the change is locked, LFOSC is disabled to
 * save power, and LFCLK source cannot be selected again without BOR.
 *
 * LFXT is an ultra-low power crystal oscillator which supports driving a
 * standard 32.768kHz watch crystal.
 *
 * To use the LFXT, a watch crystal must be populated between LFXIN and LFXOUT
 * pins. Find more info in LFXT section of CKM Technical Reference Manual.
 *
 * GPIO/IOMUX must be configure LFXT functionality for LFXIN and LFXOUT before
 * calling this function.
 *
 * This basic implementation will busy-wait until LFXT oscillator is stabilized.
 * But a more advanced implementation can do other things while the LFXT is
 * stabilizing. You can enable LFXTGOOD interrupt, or check CLKSTATUS.LFXTGOOD
 * when convenient, as long as you do not switch the source via
 * SETUSELFXT until LFXTGOOD is set.
 *
 * LFCLK_IN and LFXT are mutually exclusive.
 * This function assumes LFCLK_IN is disabled (default).
 *
 *  @param[in]  config         Pointer to the LFCLK configuration struct
 *                             @ref DL_SYSCTL_LFCLKConfig.
 */
void DL_SYSCTL_setLFCLKSourceLFXT(DL_SYSCTL_LFCLKConfig *config);

/**
 *  @brief Change LFCLK source to external digital LFCLK_IN
 *
 * LFOSC is the internal 32kHz oscillator and default LFCLK source after a BOR.
 * Once LFCLK source is changed, the change is locked, LFOSC is disabled to
 * save power, and LFCLK source cannot be selected again without BOR.
 *
 * LFCLK_IN is a low frequency digital clock input compatible with 32.768kHz
 * typical frequency digital square wave CMOS clock inputs (typical duty
 * cycle of 50%).
 *
 * Digital clock input must be valid and GPIO/IOMUX must be configured
 * separately on the appropriate pin before calling this function to enable
 * LFCLK_IN.
 *
 * LFCLK_IN and LFXT are mutually exclusive.
 * This function assumes LFXT is disabled (default).
 */
__STATIC_INLINE void DL_SYSCTL_setLFCLKSourceEXLF(void)
{
    SYSCTL->SOCLOCK.EXLFCTL =
        (SYSCTL_EXLFCTL_KEY_VALUE | SYSCTL_EXLFCTL_SETUSEEXLF_TRUE);
}

/**
 *  @brief Change HFCLK source to external crystal HFXT with default parameters
 *
 * HFXT is a high frequency crystal oscillator which supports standard crystals
 * and resonators in the 4-48MHz range to generate a stable high-speed
 * reference clock for the system.
 *
 * To use the HFXT, a crystal or resonator must be populated between HFXIN and HFXOUT
 * pins. Find more info in HFXT section of CKM Technical Reference Manual.
 *
 * GPIO/IOMUX must be configure HFXT functionality for HFXIN and HFXOUT before
 * calling this function.
 *
 * The HFXT startup time is set to ~0.512ms based on the TYP datasheet
 * recommendation. Additionally, the HFCLK startup monitor is enabled.
 *
 * This basic implementation will busy-wait until HFXT oscillator is stabilized.
 * But a more advanced implementation can do other things while the HFXT is
 * stabilizing. You can enable HFCLKGOOD interrupt, or check CLKSTATUS.HFCLKGOOD
 * when convenient, as long as you do not switch the source before HFCLKGOOD is set.
 *
 * To modify the default HFXT startup time or disable the startup monitor, use
 * @ref DL_SYSCTL_setHFCLKSourceHFXTParams instead of this API.
 *
 *  @param[in]  range   HFXT frequency range
 */
void DL_SYSCTL_setHFCLKSourceHFXT(DL_SYSCTL_HFXT_RANGE range);

/**
 *  @brief Change HFCLK source to external crystal HFXT with custom parameters
 *
 * HFXT is a high frequency crystal oscillator which supports standard crystals
 * and resonators in the 4-48MHz range to generate a stable high-speed
 * reference clock for the system.
 *
 * To use the HFXT, a crystal or resonator must be populated between HFXIN and HFXOUT
 * pins. Find more info in HFXT section of CKM Technical Reference Manual.
 *
 * GPIO/IOMUX must be configure HFXT functionality for HFXIN and HFXOUT before
 * calling this function.
 *
 * If the HFCLK startup monitor is enabled, then the HFXT will be checked after
 * the amount of time specified by the startupTime parameter.
 * This basic implementation will busy-wait until HFXT oscillator is stabilized.
 * But a more advanced implementation can do other things while the HFXT is
 * stabilizing. You can enable HFCLKGOOD interrupt, or check CLKSTATUS.HFCLKGOOD
 * when convenient, as long as you do not switch the source before HFCLKGOOD is set.
 *
 * If the HFCLK startup monitor is disabled, then this implementation will not
 * check if the HFXT oscillator is stabilized.
 *
 *  @param[in]  range           HFXT frequency range
 *  @param[in]  startupTime     HFXT startup time
 *  @param[in]  monitorEnable   Whether to enable the HFCLK startup monitor

 */
void DL_SYSCTL_setHFCLKSourceHFXTParams(
    DL_SYSCTL_HFXT_RANGE range, uint32_t startupTime, bool monitorEnable);

/**
 *  @brief Change HFCLK source to external digital HFCLK_IN
 *
 * HFCLK_IN can be used to bypass the HFXT circuit and bring 4-48MHz typical
 * frequency digital clock into the devce as HFCLK source instead of HFXT.
 *
 * HFCLK_IN is a digital clock input compatible with digital square wave CMOS
 * clock inputs and should have typical duty cycle of 50%.
 *
 * Digital clock input must be valid and GPIO/IOMUX must be configured
 * separately on the appropriate pin before calling this function to enable
 * HFCLK_IN.
 */
__STATIC_INLINE void DL_SYSCTL_setHFCLKSourceHFCLKIN(void)
{
    SYSCTL->SOCLOCK.HSCLKEN |= SYSCTL_HSCLKEN_USEEXTHFCLK_ENABLE;
}

/**
 *  @brief      Disable the HFXT
 *
 *  If HFXT is already enabled, application software must verify that either an
 *  HFCLKGOOD indication or an HFCLKOFF (off/dead) indication in the CLKSTATUS
 *  register was asserted by hardware before attempting to disable the HFXT
 *  by clearing HFXTEN. When disabling the HFXT by clearing HFXTEN, the HFXT
 *  must not be re-enabled again until the HFCLKOFF bit in the CLKSTATUS
 *  register is set by hardware.
 *
 *  @sa DL_SYSCTL_getClockStatus
 */
__STATIC_INLINE void DL_SYSCTL_disableHFXT(void)
{
    SYSCTL->SOCLOCK.HSCLKEN &= ~(SYSCTL_HSCLKEN_HFXTEN_MASK);
}

/**
 *  @brief   Get the source of High Speed Clock (HSCLK)
 *
 * HSCLK can be sourced by HFCLK.
 * HSCLK is an optional source for MCLK alongside SYSOSC or LFCLK.
 *
 *  @return  The source of HSCLK. One of @ref DL_SYSCTL_HSCLK_SOURCE.
 */
__STATIC_INLINE DL_SYSCTL_HSCLK_SOURCE DL_SYSCTL_getHSCLKSource(void)
{
    uint32_t source = SYSCTL->SOCLOCK.HSCLKCFG & SYSCTL_HSCLKCFG_HSCLKSEL_MASK;

    return (DL_SYSCTL_HSCLK_SOURCE)(source);
}

/**
 *  @brief   Set the source of High Speed Clock (HSCLK)
 *
 * HSCLK can be sourced by HFCLK.
 * HSCLK is an optional source for MCLK alongside SYSOSC or LFCLK.
 *
 *  @param[in]  source  The source of HSCLK. One of @ref DL_SYSCTL_HSCLK_SOURCE.
 */
__STATIC_INLINE void DL_SYSCTL_setHSCLKSource(DL_SYSCTL_HSCLK_SOURCE source)
{
    SYSCTL->SOCLOCK.HSCLKCFG = (uint32_t) source;
}

/**
 *  @brief   Get the source of Middle Frequency Precision Clock (MFPCLK)
 *
 *  MFPCLK is a continuous 4MHz to DAC module in RUN/SLEEP/STOP mode.
 *  Unlike MFCLK, MFPCLK is async to MCLK/ULPCLK, providing higher DAC precision and performance.
 *  MFPCLK is the only clock source for DAC.
 *
 *  @return  The source of MFPCLK. One of @ref DL_SYSCTL_MFPCLK_SOURCE.
 */
__STATIC_INLINE DL_SYSCTL_MFPCLK_SOURCE DL_SYSCTL_getMFPCLKSource(void)
{
    uint32_t source =
        SYSCTL->SOCLOCK.GENCLKCFG & SYSCTL_GENCLKCFG_MFPCLKSRC_MASK;

    return (DL_SYSCTL_MFPCLK_SOURCE)(source);
}

/**
 *  @brief   Set the source of Middle Frequency Precision Clock (MFPCLK)
 *
 *  MFPCLK is a continuous 4MHz to DAC module in RUN/SLEEP/STOP mode.
 *  Unlike MFCLK, MFPCLK is async to MCLK/ULPCLK, providing higher DAC precision and performance.
 *  MFPCLK is the only clock source for DAC.
 *
 *  @param[in]  source  The source of MFPCLK. One of @ref DL_SYSCTL_MFPCLK_SOURCE.
 */
__STATIC_INLINE void DL_SYSCTL_setMFPCLKSource(DL_SYSCTL_MFPCLK_SOURCE source)
{
    DL_Common_updateReg(&SYSCTL->SOCLOCK.GENCLKCFG, (uint32_t) source,
        SYSCTL_GENCLKCFG_MFPCLKSRC_MASK);
}

/**
 *  @brief  Enable the Medium Frequency Clock (MFCLK)
 *
 *  MFCLK provides a continuous 4MHz clock to drive certain peripherals on the system.
 *  The 4MHz rate is always derived from SYSOSC, and the divider is automatically
 *  applied to maintain the 4MHz rate regardless of SYSOSC frequency.
 *  MCLK is ideal for timers and serial interfaces which require a constant
 *  clock source in RUN/SLEEP/STOP power modes.
 *
 *  MFCLK can only run if 3 conditions are met:
 *
 *  1) Power mode must be RUN, SLEEP, or STOP.
 *  2) USEMFTICK register bit is set, which this function does
 *  3) MDIV must be set to @ref DL_SYSCTL_MCLK_DIVIDER_DISABLE by @ref DL_SYSCTL_setMCLKDivider.
 *
 *  If MCLK source is not SYSOSC, MCLK frequency must be >=32MHz for correct operation of MFCLK.
 *
 *  @sa DL_SYSCTL_setMCLKDivider
 *  @sa DL_SYSCTL_getMCLKSource
 *  @sa DL_SYSCTL_getMCLKFreq
 */
__STATIC_INLINE void DL_SYSCTL_enableMFCLK(void)
{
    SYSCTL->SOCLOCK.MCLKCFG |= SYSCTL_MCLKCFG_USEMFTICK_ENABLE;
}

/**
 *  @brief  Disable the Medium Frequency Clock (MFCLK)
 */
__STATIC_INLINE void DL_SYSCTL_disableMFCLK(void)
{
    SYSCTL->SOCLOCK.MCLKCFG &= ~(SYSCTL_MCLKCFG_USEMFTICK_ENABLE);
}

/**
 *  @brief  Enable the Middle Frequency Precision Clock (MFPCLK)
 *
 *  MFPCLK provides a continuous 4MHz clock to the DAC.
 *
 *  MFPCLK can be sources from either SYSOSC or HFCLK (HFXT or HFCLK_IN).
 *
 *  The DAC does not have a clock selection mux. Its clock source is selected
 *  by configuring MFPCLK.
 *
 *  @sa DL_SYSCTL_disableMFPCLK
 */
__STATIC_INLINE void DL_SYSCTL_enableMFPCLK(void)
{
    SYSCTL->SOCLOCK.GENCLKEN |= SYSCTL_GENCLKEN_MFPCLKEN_ENABLE;
}

/**
 *  @brief  Disable the Middle Frequency Precision Clock (MFPCLK)
 *  @sa DL_SYSCTL_enableMFPCLK
 */
__STATIC_INLINE void DL_SYSCTL_disableMFPCLK(void)
{
    SYSCTL->SOCLOCK.GENCLKEN &= ~(SYSCTL_GENCLKEN_MFPCLKEN_ENABLE);
}

/**
 *  @brief  Set the divider for HFCLK when HFCLK is used as the MFPCLK source
 *
 *  @param[in] divider   The divider of HFCLK for MFPCLK
 *                       One of @ref DL_SYSCTL_HFCLK_MFPCLK_DIVIDER.
 */
__STATIC_INLINE void DL_SYSCTL_setHFCLKDividerForMFPCLK(
    DL_SYSCTL_HFCLK_MFPCLK_DIVIDER divider)
{
    DL_Common_updateReg(&SYSCTL->SOCLOCK.GENCLKCFG,
        ((uint32_t) divider << SYSCTL_GENCLKCFG_HFCLK4MFPCLKDIV_OFS),
        SYSCTL_GENCLKCFG_HFCLK4MFPCLKDIV_MASK);
}

/**
 *  @brief   Get the divider for HFCLK when HFCLK is used as the MFPCLK source
 *
 *  @return  Returns the divider for HFCLK for MFPCLK
 *
 *  @retval  One of @ref DL_SYSCTL_HFCLK_MFPCLK_DIVIDER
 */
__STATIC_INLINE DL_SYSCTL_HFCLK_MFPCLK_DIVIDER
DL_SYSCTL_getHFCLKDividerForMFPCLK(void)
{
    uint32_t divider =
        (SYSCTL->SOCLOCK.GENCLKCFG & SYSCTL_GENCLKCFG_HFCLK4MFPCLKDIV_MASK) >>
        SYSCTL_GENCLKCFG_HFCLK4MFPCLKDIV_OFS;

    return (DL_SYSCTL_HFCLK_MFPCLK_DIVIDER)(divider);
}

/**
 *  @brief  Enable the External Clock (CLK_OUT)
 *
 *  CLK_OUT is provided for pushing out digital clocks to external circuits, such
 *  as an external ADC which does not have its own clock source.
 *
 *  IOMUX setting for CLK_OUT must be configured before using this function.
 *
 *  CLK_OUT has a typical duty cycle of 50% if clock source is HFCLK,
 *  SYSOSC, or LFCLK. If source is MCLK, ULPCLK, or MFCLK, duty cycle is not
 *  guaranteed to be 50%.
 *
 *  This function performs multiple operations:
 *  1) Sets the CLK_OUT source
 *  2) Sets the CLK_OUT divider value
 *  3) Enables the CLK_OUT divider, which can be disabled by @ref DL_SYSCTL_disableExternalClockDivider
 *  4) Enables the CLK_OUT, which can be disabled by @ref DL_SYSCTL_disableExternalClock
 *
 *  @param[in]  source  The source of CLK_OUT. One of @ref DL_SYSCTL_CLK_OUT_SOURCE.
 *  @param[in]  divider The divider of CLK_OUT. One of @ref DL_SYSCTL_CLK_OUT_DIVIDE.
 *
 *  @sa DL_SYSCTL_disableExternalClock
 *  @sa DL_SYSCTL_disableExternalClockDivider
 */
__STATIC_INLINE void DL_SYSCTL_enableExternalClock(
    DL_SYSCTL_CLK_OUT_SOURCE source, DL_SYSCTL_CLK_OUT_DIVIDE divider)
{
    DL_Common_updateReg(&SYSCTL->SOCLOCK.GENCLKCFG,
        (uint32_t) divider | (uint32_t) source,
        SYSCTL_GENCLKCFG_EXCLKDIVEN_MASK | SYSCTL_GENCLKCFG_EXCLKDIVVAL_MASK |
            SYSCTL_GENCLKCFG_EXCLKSRC_MASK);
    SYSCTL->SOCLOCK.GENCLKEN |= SYSCTL_GENCLKEN_EXCLKEN_ENABLE;
}

/**
 *  @brief  Disable the External Clock (CLK_OUT)
 *  @sa DL_SYSCTL_enableExternalClock
 */
__STATIC_INLINE void DL_SYSCTL_disableExternalClock(void)
{
    SYSCTL->SOCLOCK.GENCLKEN &= ~(SYSCTL_GENCLKEN_EXCLKEN_ENABLE);
}

/**
 *  @brief  Disable the External Clock (CLK_OUT) Divider
 *  @sa DL_SYSCTL_enableExternalClock
 */
__STATIC_INLINE void DL_SYSCTL_disableExternalClockDivider(void)
{
    SYSCTL->SOCLOCK.GENCLKCFG &= ~(SYSCTL_GENCLKCFG_EXCLKDIVEN_ENABLE);
}

/**
 *  @brief  Blocks all asynchronous fast clock requests
 *
 *  To block specific async fast clock requests on certain IP, refer to their
 *  individual driverlib. Examples include: RTC, UART, SPI, I2C.
 */
__STATIC_INLINE void DL_SYSCTL_blockAllAsyncFastClockRequests(void)
{
    SYSCTL->SOCLOCK.SYSOSCCFG |= SYSCTL_SYSOSCCFG_BLOCKASYNCALL_ENABLE;
}

/**
 *  @brief  Allows all asynchronous fast clock requests
 *
 *  Although this allows all async fast clock requests, individual IPs may still
 *  be blocking theirs.
 *
 *  To allow specific async fast clock requests on certain IP, refer to their
 *  individual driverlib. Examples include: RTC, UART, SPI, I2C, GPIO.
 */
__STATIC_INLINE void DL_SYSCTL_allowAllAsyncFastClockRequests(void)
{
    SYSCTL->SOCLOCK.SYSOSCCFG &= ~(SYSCTL_SYSOSCCFG_BLOCKASYNCALL_ENABLE);
}

/**
 *  @brief  Generates an asynchronous fast clock request upon any IRQ request to CPU.
 *
 *  Provides lowest latency interrupt handling regardless of system clock speed.
 *  Blockable by @ref DL_SYSCTL_blockAllAsyncFastClockRequests
 *
 *  @sa DL_SYSCTL_blockAllAsyncFastClockRequests
 */
__STATIC_INLINE void DL_SYSCTL_enableFastCPUEventHandling(void)
{
    SYSCTL->SOCLOCK.SYSOSCCFG |= SYSCTL_SYSOSCCFG_FASTCPUEVENT_ENABLE;
}

/**
 *  @brief  Maintains current system clock speed for IRQ request to CPU.
 *
 *  Latency for interrupt handling will be higher at lower system clock speeds.
 */
__STATIC_INLINE void DL_SYSCTL_disableFastCPUEventHandling(void)
{
    SYSCTL->SOCLOCK.SYSOSCCFG &= ~(SYSCTL_SYSOSCCFG_FASTCPUEVENT_ENABLE);
}

/**
 *  @brief  Set the SRAM boundary address to act as partition for read-execute
 *          permission
 *
 *  Specify the SRAM partition address to protect the code region of SRAM from
 *  being written to, and prevent the RW ("data") region of SRAM from being
 *  used for code execution.
 *  The SRAM partition address creates lower and higher partitions:
 *      - Lower partition is Read-Write only, no execute
 *      - Upper partition is Read-Execute only, no write
 *  A partition address of 0x0 is a special case and indicates that all SRAM is
 *  configured with RWX (read-write-execute) permissions. This is the default
 *  value.
 *
 *  The address is set with a 32-byte resolution. The address written is the
 *  system memory map address of the partition (0x200X_XXXX).
 *
 *  @param[in]  address   Address to act as the SRAM partition address. Value is
 *                        a valid 32-bit SRAM address. Only address bits [19:5]
 *                        i.e. bit 5 to bit 19 are used for the boundary address
 */
__STATIC_INLINE void DL_SYSCTL_setSRAMBoundaryAddress(uint32_t address)
{
    SYSCTL->SOCLOCK.SRAMBOUNDARY =
        (((uint32_t) address) & SYSCTL_SRAMBOUNDARY_ADDR_MASK);
}

/**
 *  @brief  Get the SRAM boundary address
 *
 *  Get the SRAM partition address
 *  The SRAM partition address creates lower and higher partitions:
 *      - Lower partition is Read-Write only, no execute
 *      - Upper partition is Read-Execute only, no write
 *  A partition address of 0x0 is a special case and indicates that all SRAM is
 *  configured with RWX (read-write-execute) permissions.
 *
 *  The address is set with a 32-byte granularity. The address written is the
 *  system memory map address of the partition (0x200X_XXXX).
 *
 *  @return     The SRAM partition address offset from the SRAM base address
 *
 *  @retval     Value is range in [0x0, 0x000FFFE0]
 */
__STATIC_INLINE uint32_t DL_SYSCTL_getSRAMBoundaryAddress(void)
{
    return (SYSCTL->SOCLOCK.SRAMBOUNDARY);
}

/**
 *  @brief  Set flash wait state
 *
 *  @note Flash wait states are managed automatically by SYSCTL when MCLK is
 *  running from SYSOSC or LFCLK.
 *  @note This wait state is only applied if MCLK running from HFXT,
 *  or HFCLK_IN.
 *
 *  Consult device specific datasheet for proper values.
 *
 *  @param[in]  waitState  Desired number of flash wait states. One of
 *  @ref DL_SYSCTL_FLASH_WAIT_STATE.
 */
__STATIC_INLINE void DL_SYSCTL_setFlashWaitState(
    DL_SYSCTL_FLASH_WAIT_STATE waitState)
{
    DL_Common_updateReg(&SYSCTL->SOCLOCK.MCLKCFG, (uint32_t) waitState,
        SYSCTL_MCLKCFG_FLASHWAIT_MASK);
}

/**
 *  @brief  Get flash wait state
 *
 *  @note Flash wait states are managed automatically by SYSCTL when MCLK is
 *  running from SYSOSC or LFCLK.
 *  @note This wait state is only applied if MCLK running from HFXT,
 *  or HFCLK_IN.
 *
 *  Consult device specific datasheet for proper values.
 *
 *  @return Number of flash wait states. One of @ref DL_SYSCTL_FLASH_WAIT_STATE.
 */
__STATIC_INLINE DL_SYSCTL_FLASH_WAIT_STATE DL_SYSCTL_getFlashWaitState(void)
{
    uint32_t waitState =
        SYSCTL->SOCLOCK.MCLKCFG & SYSCTL_MCLKCFG_FLASHWAIT_MASK;

    return (DL_SYSCTL_FLASH_WAIT_STATE)(waitState);
}

/**
 *  @brief  Read Frequency Clock Counter (FCC)
 *  @return  22-bit value of Frequency Clock Counter (FCC)
 */
__STATIC_INLINE uint32_t DL_SYSCTL_readFCC(void)
{
    return (SYSCTL->SOCLOCK.FCC);
}

/**
 *  @brief  Start Frequency Clock Counter (FCC)
 *
 *  If FCC_IN is already logic high, counting starts immediately.
 *  When using level trigger, FCC_IN should be low when GO is set, and trigger
 *  pulse should be sent to FCC_IN after starting FCC.
 */
__STATIC_INLINE void DL_SYSCTL_startFCC(void)
{
    SYSCTL->SOCLOCK.FCCCMD = (SYSCTL_FCCCMD_KEY_VALUE | SYSCTL_FCCCMD_GO_TRUE);
}

/**
 *  @brief  Returns whether FCC is done capturing
 *
 *  When capture completes, FCCDONE is set by hardware.
 *  FCCDONE is read-only and is automatically cleared by hardware when a new
 *  capture is started.
 *
 *  @return Whether FCC is done or not
 *  @retval true or false (boolean)
 */
__STATIC_INLINE bool DL_SYSCTL_isFCCDone(void)
{
    return (DL_SYSCTL_getClockStatus() & SYSCTL_CLKSTATUS_FCCDONE_DONE) ==
           SYSCTL_CLKSTATUS_FCCDONE_DONE;
}

/**
 *  @brief     Configure the Frequency Clock Counter (FCC)
 *
 *  FCC enables flexible in-system testing and calibration of a variety of oscillators
 *  and clocks on the device. The FCC counts the number of clock periods seen on the
 *  selected clock source within a known fixed trigger period (derived from a secondary
 *  reference source) to provide an estimation of the frequency of the source clock.
 *
 *  @param[in] trigLvl  Determines if active high level trigger or rising-edge
 *                      to rising-edge. One of @ref DL_SYSCTL_FCC_TRIG_TYPE .
 *  @param[in] trigSrc  Determines which clock source to trigger FCC from. One of
 *                      @ref DL_SYSCTL_FCC_TRIG_SOURCE.
 *  @param[in] clkSrc   Which clock source to capture and measure frequency of. One of
 *                      @ref DL_SYSCTL_FCC_CLOCK_SOURCE.
 */
void DL_SYSCTL_configFCC(DL_SYSCTL_FCC_TRIG_TYPE trigLvl,
    DL_SYSCTL_FCC_TRIG_SOURCE trigSrc, DL_SYSCTL_FCC_CLOCK_SOURCE clkSrc);

/**
 *  @brief     Sets number of rising-edge to rising-edge period for Frequency
 *             Clock Counter (FCC)
 *
 *  Set the number of rising-edge to rising-edge period for Frequency
 *             Clock Counter (FCC)
 *
 *  @param[in] periods  One of @ref DL_SYSCTL_FCC_TRIG_CNT
 */
__STATIC_INLINE void DL_SYSCTL_setFCCPeriods(DL_SYSCTL_FCC_TRIG_CNT periods)
{
    DL_Common_updateReg(&SYSCTL->SOCLOCK.GENCLKCFG, (uint32_t) periods,
        SYSCTL_GENCLKCFG_FCCTRIGCNT_MASK);
}

/**
 *  @brief     Gets number of rising-edge to rising-edge period for Frequency
 *             Clock Counter (FCC)
 *
 *  @return     One of @ref DL_SYSCTL_FCC_TRIG_CNT
 */
__STATIC_INLINE DL_SYSCTL_FCC_TRIG_CNT DL_SYSCTL_getFCCPeriods(void)
{
    uint32_t periods =
        SYSCTL->SOCLOCK.GENCLKCFG & SYSCTL_GENCLKCFG_FCCTRIGCNT_MASK;

    return (DL_SYSCTL_FCC_TRIG_CNT)(periods);
}

/**
 *  @brief  Enable Frequency Correction Loop (FCL) in Internal Resistor Mode
 *
 *  Once FCL is enable, it cannot be disabled by software. A BOOTRST is required.
 */
__STATIC_INLINE void DL_SYSCTL_enableSYSOSCFCL(void)
{
    SYSCTL->SOCLOCK.SYSOSCFCLCTL =
        (SYSCTL_SYSOSCFCLCTL_KEY_VALUE | SYSCTL_SYSOSCFCLCTL_SETUSEFCL_TRUE);
}

/**
 *  @brief  Enable Frequency Correction Loop (FCL) in External Resistor Mode
 *
 *  Used to increase SYSOSC accuracy. An ROSC reference resistor which is suitable
 *  to meet application accuracy reqiurements must be placed between ROSC pin and
 *  device ground (VSS).
 *
 *  Once FCL is enable, it cannot be disabled by software. A BOOTRST is required.
 *
 *  Power consumption of SYSOSC will be marginally higher with FCL enabled due to
 *  reference current which flows through ROSC.
 *  Settling time from startup to specified accuracy may also be longer.
 *  See device-specific datasheet for startup times.
 */
__STATIC_INLINE void DL_SYSCTL_enableSYSOSCFCLExternalResistor(void)
{
    SYSCTL->SOCLOCK.SYSOSCFCLCTL =
        (SYSCTL_SYSOSCFCLCTL_KEY_VALUE | SYSCTL_SYSOSCFCLCTL_SETUSEFCL_TRUE |
            SYSCTL_SYSOSCFCLCTL_SETUSEEXRES_TRUE);
}

/**
 *  @brief  Enable write protection of selected SYSCTL registers
 *
 *  Protecting writes to configuration registers in SYSCTL can add a layer of
 *  robustness against unintended changes during runtime.
 *
 *  @note Does not protect all SYSCTL registers, see TRM for more detail.
 */
__STATIC_INLINE void DL_SYSCTL_enableWriteLock(void)
{
    SYSCTL->SOCLOCK.WRITELOCK = SYSCTL_WRITELOCK_ACTIVE_ENABLE;
}

/**
 *  @brief  Disable write protection of selected SYSCTL registers
 *
 *  Protecting writes to configuration registers in SYSCTL can add a layer of
 *  robustness against unintended changes during runtime.
 *
 *  @note Does not protect all SYSCTL registers, see TRM for more detail.
 */
__STATIC_INLINE void DL_SYSCTL_disableWriteLock(void)
{
    SYSCTL->SOCLOCK.WRITELOCK = SYSCTL_WRITELOCK_ACTIVE_DISABLE;
}

/**
 *  @brief  Sets operating mode of VBOOST (analog charge pump)
 *
 *  Active VBOOST circuitry is needed for COMP/OPA/GPAMP (if present on device).
 *  VBOOST has a startup time, so consider power consumption versus desired startup time.
 *
 *  @note Although VBOOST clock source is automatically managed, it is up to
 *  application software to ensure certain cases, or else ANACLKERR occurs.
 *  See VBOOST section of TRM for more details.
 *  @param[in] setting   One of @ref DL_SYSCTL_VBOOST.
 */
__STATIC_INLINE void DL_SYSCTL_setVBOOSTConfig(DL_SYSCTL_VBOOST setting)
{
    DL_Common_updateReg(&SYSCTL->SOCLOCK.GENCLKCFG, (uint32_t) setting,
        SYSCTL_GENCLKCFG_ANACPUMPCFG_MASK);
}

/**
 *  @brief  Gets operating mode of VBOOST (analog charge pump)
 *
 *  Active VBOOST circuitry is needed for COMP/OPA/GPAMP (if present on device).
 *  VBOOST has a startup time, so consider power consumption versus desired startup time.
 *
 *  @note Although VBOOST clock source is automatically managed, it is up to
 *  application software to ensure certain cases, or else ANACLKERR occurs.
 *  See VBOOST section of TRM for more details.
 *  @return One of @ref DL_SYSCTL_VBOOST.
 */
__STATIC_INLINE DL_SYSCTL_VBOOST DL_SYSCTL_getVBOOSTConfig(void)
{
    uint32_t setting =
        SYSCTL->SOCLOCK.GENCLKCFG & SYSCTL_GENCLKCFG_ANACPUMPCFG_MASK;

    return (DL_SYSCTL_VBOOST)(setting);
}

/**
 *  @brief  Return byte that was saved through SHUTDOWN
 *
 *  Shutdown memory persists beyond BOR, BOOTRST, and SYSRST.
 *
 *  @note Parity bits and parity fault checking is done by hardware.
 *
 *  @param[in] index   One of @ref DL_SYSCTL_SHUTDOWN_STORAGE_BYTE.
 *
 *  @return 8-bit value of Shutdown Storage Byte.
 */
__STATIC_INLINE uint8_t DL_SYSCTL_getShutdownStorageByte(
    DL_SYSCTL_SHUTDOWN_STORAGE_BYTE index)
{
    const volatile uint32_t *pReg = &SYSCTL->SOCLOCK.SHUTDNSTORE0;

    return (uint8_t)(
        *(pReg + (uint32_t) index) & SYSCTL_SHUTDNSTORE0_DATA_MASK);
}

/**
 *  @brief  Save a byte to SHUTDOWN memory
 *
 *  Shutdown memory persists beyond BOR, BOOTRST, and SYSRST.
 *
 *  @note Parity bits and parity fault checking is done by hardware.
 *
 *  @param[in] index   One of @ref DL_SYSCTL_SHUTDOWN_STORAGE_BYTE.
 *  @param[in] data    8-bit data to save in memory
 */
__STATIC_INLINE void DL_SYSCTL_setShutdownStorageByte(
    DL_SYSCTL_SHUTDOWN_STORAGE_BYTE index, uint8_t data)
{
    DL_Common_updateReg(&SYSCTL->SOCLOCK.SHUTDNSTORE0 + (uint32_t) index, data,
        SYSCTL_SHUTDNSTORE0_DATA_MASK);
}

/**
 *  @brief  Enable SHUTDOWN IO Release
 *
 *  After shutdown, IO is locked in previous state.
 *
 *  @note Release IO after re-configuring IO to their proper state.
 */
__STATIC_INLINE void DL_SYSCTL_releaseShutdownIO(void)
{
    SYSCTL->SOCLOCK.SHDNIOREL =
        (SYSCTL_SHDNIOREL_KEY_VALUE | SYSCTL_SHDNIOREL_RELEASE_TRUE);
}

/**
 *  @brief  Disable the reset functionality of the NRST pin
 *
 *  Disabling the NRST pin allows the pin to be configured as a GPIO.
 *  Once disabled, the reset functionality can only be re-enabled by a POR.
 *
 *  @note The register is write-only, so the EXRSTPIN register
 *        will always appear as "Disabled" in the debugger
 */
__STATIC_INLINE void DL_SYSCTL_disableNRSTPin(void)
{
    SYSCTL->SOCLOCK.EXRSTPIN =
        (SYSCTL_EXRSTPIN_KEY_VALUE | SYSCTL_EXRSTPIN_DISABLE_TRUE);
}

/**
 *  @brief  Disable Serial Wire Debug (SWD) functionality
 *
 *  SWD pins are enabled by default after cold start to allow a debug connection.
 *  It is possible to disable SWD on these pins to use for other functionality.
 *
 *  @post SWD is disabled, but pins must be re-configured separately.
 *
 *  @note Cannot debug the device after disabling SWD. Only re-enabled by POR.
 */
__STATIC_INLINE void DL_SYSCTL_disableSWD(void)
{
    SYSCTL->SOCLOCK.SWDCFG =
        (SYSCTL_SWDCFG_KEY_VALUE | SYSCTL_SWDCFG_DISABLE_TRUE);
}

/**
 *  @brief  Return byte that is stored in RSTCAUSE.
 *
 *  @return The cause of reset. One of @ref DL_SYSCTL_RESET_CAUSE
 */
__STATIC_INLINE DL_SYSCTL_RESET_CAUSE DL_SYSCTL_getResetCause(void)
{
    uint32_t resetCause = SYSCTL->SOCLOCK.RSTCAUSE & SYSCTL_RSTCAUSE_ID_MASK;

    return (DL_SYSCTL_RESET_CAUSE)(resetCause);
}

/**
 *  @brief     Set the HFXT startup time
 *
 * Specify the HFXT startup time in 64us resolution. If the HFCLK startup
 * monitor is enabled (HFCLKFLTCHK), HFXT will be checked after this time
 * expires.
 *
 *  @param[in]  startupTime  The HFXT startup time to set in ~64us steps.
 *                           Value between [0x0 (~0s), 0xFF (~16.32ms)].
 */
__STATIC_INLINE void DL_SYSCTL_setHFXTStartupTime(uint32_t startupTime)
{
    DL_Common_updateReg(&SYSCTL->SOCLOCK.HFCLKCLKCFG, startupTime,
        SYSCTL_HFCLKCLKCFG_HFXTTIME_MASK);
}

/**
 *  @brief   Get the HFXT startup time
 *
 *  @return  Returns the HFXT startup time in ~64us steps
 *
 *  @retval  Value between [0x0 (~0s), 0xFF (~16.32ms)]
 */
__STATIC_INLINE uint32_t DL_SYSCTL_getHFXTStartupTime(void)
{
    return (SYSCTL->SOCLOCK.HFCLKCLKCFG & SYSCTL_HFCLKCLKCFG_HFXTTIME_MASK);
}

/**
 *  @brief     Set the HFXT frequency range
 *
 * The high frequency crystal oscillator (HFXT) can be used with standard
 * crystals and resonators in the 4-48MHz range to generate a stable high-speed
 * reference clock for the system.
 *
 *  @param[in]  range  One of @ref DL_SYSCTL_HFXT_RANGE
 */
__STATIC_INLINE void DL_SYSCTL_setHFXTFrequencyRange(
    DL_SYSCTL_HFXT_RANGE range)
{
    DL_Common_updateReg(&SYSCTL->SOCLOCK.HFCLKCLKCFG, ((uint32_t) range),
        SYSCTL_HFCLKCLKCFG_HFXTRSEL_MASK);
}

/**
 *  @brief   Get the HFXT frequency range
 *
 *  @return  Returns the HFXT frequency range
 *
 *  @retval  One of @ref DL_SYSCTL_HFXT_RANGE
 */
__STATIC_INLINE DL_SYSCTL_HFXT_RANGE DL_SYSCTL_getHFXTFrequencyRange(void)
{
    uint32_t range =
        (SYSCTL->SOCLOCK.HFCLKCLKCFG & SYSCTL_HFCLKCLKCFG_HFXTRSEL_MASK) >>
        SYSCTL_HFCLKCLKCFG_HFXTRSEL_OFS;

    return (DL_SYSCTL_HFXT_RANGE)(range);
}

/**
 *  @brief  Enable the HFCLK startup monitor
 *
 * The HFXT takes time to start after being enabled. A startup monitor is
 * provided to indicate to the application software if the HFXT has successfully
 * started, at which point the HFCLK can be selected to source a variety of
 * system functions. The HFCLK startup monitor also supports checking the
 * HFCLK_IN digital clock input for a clock stuck fault.
 *
 */
__STATIC_INLINE void DL_SYSCTL_enableHFCLKStartupMonitor(void)
{
    SYSCTL->SOCLOCK.HFCLKCLKCFG |= SYSCTL_HFCLKCLKCFG_HFCLKFLTCHK_ENABLE;
}

/**
 *  @brief  Disable the HFCLK startup monitor
 */
__STATIC_INLINE void DL_SYSCTL_disableHFCLKStartupMonitor(void)
{
    SYSCTL->SOCLOCK.HFCLKCLKCFG &= ~(SYSCTL_HFCLKCLKCFG_HFCLKFLTCHK_MASK);
}

/**
 *  @brief  Retrieves the calibration constant of the temperature sensor to be
 *          used in temperature calculation.
 *
 *  @retval Temperature sensor calibration data
 */
__STATIC_INLINE uint32_t DL_SYSCTL_getTempCalibrationConstant(void)
{
    return DL_FactoryRegion_getTemperatureVoltage();
}

/**
 *  @brief  Initializes the Read Execute (RX) Protect Firewall
 *
 *  The firewall security configuration can only be configured if INITDONE has
 *  not been issued by the CSC.
 *  This API checks if INITDONE has been issued. If it has not been issued,
 *  then the start and end addresses are set, and then it enables the firewall.
 *  If INITDONE has been issused, then the API immediately returns.
 *
 *  @param[in] startAddr  The start address of the read execute protect firewall
 *  @param[in] endAddr    The end address of the read execute protect firewall
 *
 *  @return  If the Read Execute Protect Firewall was configured
 *
 *  @retval  true  If INITDONE was not issued and the firewall was configured
 *  @retval  false If INITDONE was issued and the firewall was not configured
 */
bool DL_SYSCTL_initReadExecuteProtectFirewall(
    uint32_t startAddr, uint32_t endAddr);

/**
 *  @brief  Initializes the IP Protect Firewall
 *
 *  The firewall security configuration can only be configured if INITDONE has
 *  not been issued by the CSC.
 *  This API checks if INITDONE has been issued. If it has not been issued,
 *  then the start and end addresses are set, and then it enables the firewall.
 *  If INITDONE has been issused, then the API immediately returns.
 *
 *  @param[in] startAddr  The start address of the IP protect firewall
 *  @param[in] endAddr    The end address of the IP protect firewall
 *
 *  @return  If the IP Protect Firewall was configured
 *
 *  @retval  true  If INITDONE was not issued and the firewall was configured
 *  @retval  false If INITDONE was issued and the firewall was not configured
 */
bool DL_SYSCTL_initIPProtectFirewall(uint32_t startAddr, uint32_t endAddr);

/**
 *  @brief  Set the address range of the Write Protect Firewall
 *
 *  Set Write Protection starting at 0x0 of flash, for the first
 *  32KB at 1KB granularity.
 *  Setting a bit to 1 enables write protection, and setting a bit to 0
 *  allows write.
 *
 *  @note This bit can be written only before INITDONE. At INITDONE, this
 *        configuration gets locked and stays locked until the next BOOTRST.
 *
 *  @param[in] addrMask The mask to set the address range for the Write Protect
 *                      Firewall
 */
__STATIC_INLINE void DL_SYSCTL_setWriteProtectFirewallAddrRange(
    uint32_t addrMask)
{
    SYSCTL->SECCFG.FWEPROTMAIN = addrMask;
}

/**
 *  @brief  Get the address range of the Write Protect Firewall
 *
 *  @retval The address range for the Write Protect Firewall
 */
__STATIC_INLINE uint32_t DL_SYSCTL_getWriteProtectFirewallAddrRange(void)
{
    return (SYSCTL->SECCFG.FWEPROTMAIN);
}

/**
 *  @brief  Set the start address of the Read Execute (RX) Protect Firewall
 *
 *  Set the start of the range of Flash MAIN memory that needs to be guarded
 *  from both read and execute accesses. The firewall is configured as an
 *  address range.
 *
 *  The start and end addresses are specified at 64B sector granularity, so
 *  the 6 LSBs are don't cares.
 *  If the start address is equal to the end address, then one sector is RX
 *  protected. If the end address is equal to the start address + 1, then two
 *  sectors are protected, and so on. If the end address is less than the start
 *  address, the no sectors are RX protected. The hardware does not perform any
 *  checks on the addresses.
 *
 *  @note This bit can be written only before INITDONE. At INITDONE, this
 *        configuration gets locked and stays locked until the next BOOTRST.
 *
 *  @param[in] startAddr  The start address of the read execute protect
 *                        firewall. The 6 LSBs are don't cares.
 */
__STATIC_INLINE void DL_SYSCTL_setReadExecuteProtectFirewallAddrStart(
    uint32_t startAddr)
{
    SYSCTL->SECCFG.FRXPROTMAINSTART =
        (startAddr & SYSCTL_FRXPROTMAINSTART_ADDR_MASK);
}

/**
 *  @brief  Get the start address of the Read Execute (RX) Protect Firewall
 *
 *  The start and end addresses are specified at 64B sector granularity, so
 *  the 6 LSBs are don't cares.
 *
 *  @return  The start address of the read execute protect firewall
 */
__STATIC_INLINE uint32_t DL_SYSCTL_getReadExecuteProtectFirewallAddrStart(void)
{
    return (SYSCTL->SECCFG.FRXPROTMAINSTART);
}

/**
 *  @brief  Set the end address of the Read Execute (RX) Protect Firewall
 *
 *  Set the end of the range of Flash MAIN memory that needs to be guarded
 *  from both read and execute accesses. The firewall is configured as an
 *  address range.
 *
 *  The start and end addresses are specified at 64B sector granularity, so
 *  the 6 LSBs are don't cares.
 *  If the start address is equal to the end address, then one sector is RX
 *  protected. If the end address is equal to the start address + 1, then two
 *  sectors are protected, and so on. If the end address is less than the start
 *  address, the no sectors are RX protected. The hardware does not perform any
 *  checks on the addresses.
 *
 *  @note This bit can be written only before INITDONE. At INITDONE, this
 *        configuration gets locked and stays locked until the next BOOTRST.
 *
 *  @param[in] endAddr  The end address of the read execute protect firewall.
 *                      The 6 LSBs are don't cares.
 */
__STATIC_INLINE void DL_SYSCTL_setReadExecuteProtectFirewallAddrEnd(
    uint32_t endAddr)
{
    SYSCTL->SECCFG.FRXPROTMAINEND =
        (endAddr & SYSCTL_FRXPROTMAINEND_ADDR_MASK);
}

/**
 *  @brief  Get the end address of the Read Execute (RX) Protect Firewall
 *
 *  The start and end addresses are specified at 64B sector granularity, so
 *  the 6 LSBs are don't cares.
 *
 *  @return  The end address of the Read Execute Protect Firewall
 */
__STATIC_INLINE uint32_t DL_SYSCTL_getReadExecuteProtectFirewallAddrEnd(void)
{
    return (SYSCTL->SECCFG.FRXPROTMAINEND);
}

/**
 *  @brief  Set the start address of the IP Protect Firewall
 *
 *  Set the end of the range of Flash MAIN memory that needs to be guarded
 *  from read access, allowing only execute accesses. The firewall is configured
 *  as an address range.
 *
 *  The start and end addresses are specified at 64B sector granularity, so
 *  the 6 LSBs are don't cares.
 *  If the start address is equal to the end address, then one sector is IP
 *  protected. If the end address is equal to the start address + 1, then two
 *  sectors are protected, and so on. If the end address is less than the start
 *  address, the no sectors are IP protected. The hardware does not perform any
 *  checks on the addresses.
 *
 *  @note This bit can be written only before INITDONE. At INITDONE, this
 *        configuration gets locked and stays locked until the next BOOTRST.
 *
 *  @param[in] startAddr  The start address of the IP Protect Firewall
 */
__STATIC_INLINE void DL_SYSCTL_setIPProtectFirewallAddrStart(
    uint32_t startAddr)
{
    SYSCTL->SECCFG.FIPPROTMAINSTART =
        (startAddr & SYSCTL_FIPPROTMAINSTART_ADDR_MASK);
}

/**
 *  @brief  Get the start address of the IP Protect Firewall
 *
 *  @return  The start address of the IP Protect Firewall
 */
__STATIC_INLINE uint32_t DL_SYSCTL_getIPProtectFirewallAddrStart(void)
{
    return (SYSCTL->SECCFG.FIPPROTMAINSTART);
}

/**
 *  @brief  Set the end address of the IP Protect firewall
 *
 *  Set the end of the range of Flash MAIN memory that needs to be guarded
 *  from read access, allowing only execute accesses. The firewall is configured
 *  as an address range.
 *
 *  The start and end addresses are specified at 64B sector granularity, so
 *  the 6 LSBs are don't cares.
 *  If the start address is equal to the end address, then one sector is IP
 *  protected. If the end address is equal to the start address + 1, then two
 *  sectors are protected, and so on. If the end address is less than the start
 *  address, the no sectors are IP protected. The hardware does not perform any
 *  checks on the addresses.
 *
 *  @note This bit can be written only before INITDONE. At INITDONE, this
 *        configuration gets locked and stays locked until the next BOOTRST.
 *
 *  @param[in] endAddr  The end address of the IP Protect firewall
 */
__STATIC_INLINE void DL_SYSCTL_setIPProtectFirewallAddrEnd(uint32_t endAddr)
{
    SYSCTL->SECCFG.FIPPROTMAINSTART =
        (endAddr & SYSCTL_FIPPROTMAINEND_ADDR_MASK);
}

/**
 *  @brief  Get the end address of the IP Protect Firewall
 *
 *  @return  The end address of the IP Protect Firewall
 */
__STATIC_INLINE uint32_t DL_SYSCTL_getIPProtectFirewallAddrEnd(void)
{
    return (SYSCTL->SECCFG.FIPPROTMAINSTART);
}

/**
 *  @brief  Enable the policy to allow flash bank swapping
 *
 *  The bank swap policy needs to be configured ahead of any bank swapping or
 *  firewall configurations. In dual/quad-bank devices, this policy can be set
 *  to either
 *      - CSC allows bank swapping
 *      - CSC does not allow bank swapping
 *
 *  By default, bank swapping is enabled to ensure a high security state if the
 *  system boot execution was glitched. Defaulting the system as allowing bank
 *  swapping ensures that firewall protections get mirrored to both flash banks.
 *  Additionally, when bank swapping is enabled, SYSCTL enforces write-excute
 *  mutual exclusion across the two banks (or bank-pairs).
 *
 *  @note This is a write-once bit. This bit can only be written to before
 *        INITDONE. At INITDONE, this bit becomes a read-only bit until next
 *        BOOTRST.
 */
__STATIC_INLINE void DL_SYSCTL_enableFlashBankSwap(void)
{
    SYSCTL->SECCFG.FLBANKSWPPOLICY &= (~(SYSCTL_FLBANKSWPPOLICY_DISABLE_MASK) |
                                       SYSCTL_FLBANKSWPPOLICY_KEY_VALUE);
}

/**
 *  @brief  Disable the policy to allow flash bank swapping
 *
 *  The bank swap policy needs to be configured ahead of any bank swapping or
 *  firewall configurations. In dual/quad-bank devices, this policy can be set
 *  to either
 *      - CSC allows bank swapping
 *      - CSC does not allow bank swapping
 *
 *  By default, bank swapping is enabled to ensure a high security state if the
 *  system boot execution was glitched. Defaulting the system as allowing bank
 *  swapping ensures that firewall protections get mirrored to both flash banks.
 *  Additionally, when bank swapping is enabled, SYSCTL enforces write-excute
 *  mutual exclusion across the two banks (or bank-pairs).
 *
 *  @note This is a write-once bit. This bit can only be written to before
 *        INITDONE. At INITDONE, this bit becomes a read-only bit until next
 *        BOOTRST.
 */
__STATIC_INLINE void DL_SYSCTL_disableFlashBankSwap(void)
{
    SYSCTL->SECCFG.FLBANKSWPPOLICY = (SYSCTL_FLBANKSWPPOLICY_DISABLE_TRUE |
                                      SYSCTL_FLBANKSWPPOLICY_KEY_VALUE);
}

/**
 *  @brief      Perform bank swap and execute from the Upper Flash Bank
 *
 *  The upper physical bank maps to logical 0x0, and gets RX permission.
 *  The lower physical bank gets RW permission.
 *
 *  @note This bit can only be written to before INITDONE. At INITDONE, this bit
 *  becomes a read-only bit until next BOOTRST.
 *
 *  @pre  DL_SYSCTL_enableFlashBankSwap
 */
__STATIC_INLINE void DL_SYSCTL_executeFromUpperFlashBank(void)
{
    SYSCTL->SECCFG.FLBANKSWP |=
        (SYSCTL_FLBANKSWP_USEUPPER_ENABLE | SYSCTL_FLBANKSWP_KEY_VALUE);
}

/**
 *  @brief      Perform bank swap and execute from the Lower Flash Bank
 *
 *  The lower physical bank maps to logical 0x0, and gets RX permission.
 *  The upper physical bank gets RW permission.
 *
 *  @note This bit can only be written to before INITDONE. At INITDONE, this bit
 *  becomes a read-only bit until next BOOTRST.
 *
 *  @pre  DL_SYSCTL_enableFlashBankSwap
 */
__STATIC_INLINE void DL_SYSCTL_executeFromLowerFlashBank(void)
{
    SYSCTL->SECCFG.FLBANKSWP &=
        (~(SYSCTL_FLBANKSWP_USEUPPER_MASK) | SYSCTL_FLBANKSWP_KEY_VALUE);
}

/**
 *  @brief      Enable Read Execute (RX) Protect Firewall
 *
 *  Enables the Read Execute Protect Firewall before INITDONE.
 *
 *  @note This bit can be written only before INITDONE. At INITDONE, this
 *        configuration gets locked and stays locked until the next BOOTRST
 */
__STATIC_INLINE void DL_SYSCTL_enableReadExecuteProtectFirewall(void)
{
    SYSCTL->SECCFG.FWENABLE |=
        (SYSCTL_FWENABLE_FLRXPROT_ENABLE | SYSCTL_FWENABLE_KEY_VALUE);
}

/**
 *  @brief      Enable IP Protect Firewall
 *
 *  Enables the IP Protect Firewall before INITDONE. After INITDONE,
 *  this configuration gets locked until the next BOOTRST.
 *
 *  @note This bit can be written only before INITDONE. At INITDONE, this
 *        configuration gets locked and stays locked until the next BOOTRST
 */
__STATIC_INLINE void DL_SYSCTL_enableIPProtectFirewall(void)
{
    SYSCTL->SECCFG.FWENABLE |=
        (SYSCTL_SECSTATUS_FLIPPROT_ENABLED | SYSCTL_FWENABLE_KEY_VALUE);
}

/**
 *  @brief      Enable SRAM Boundary Lock
 *
 *  When SRAM Boundary Lock is enabled, the SRAMBOUNDARY register is only
 *  writeable only until INITDONE. After INITDONE, the SRAMBOUNDARY register
 *  cannot be written.
 *
 *  When disabled, the SRAMBOUNDARY register is writeable throughout the
 *  application, even after INITDONE.
 *
 *  @note This bit can be written only before INITDONE. At INITDONE, this
 *        configuration gets locked and stays locked until the next BOOTRST
 *
 *  @sa DL_SYSCTL_setSRAMBoundaryAddress
 */
__STATIC_INLINE void DL_SYSCTL_enableSRAMBoundaryLock(void)
{
    SYSCTL->SECCFG.FWENABLE |=
        (SYSCTL_FWENABLE_SRAMBOUNDARYLOCK_ENABLE | SYSCTL_FWENABLE_KEY_VALUE);
}

/**
 *  @brief  Checks if INITDONE has been issued by the CSC
 *
 *  @return Whether INITDONE has been issued or not
 *
 *  @retval  true  If INITDONE has been issued
 *  @retval  false If INITDONE has not been issued
 */
__STATIC_INLINE bool DL_SYSCTL_isINITDONEIssued(void)
{
    return ((SYSCTL->SECCFG.SECSTATUS & SYSCTL_SECSTATUS_INITDONE_YES) ==
            SYSCTL_SECSTATUS_INITDONE_YES);
}

/**
 *  @brief  Checks if Customer Startup Code (CSC) exists in system
 *
 *  @return Whether CSC exists in system
 *
 *  @retval  true  If CSC exists in system
 *  @retval  false If CSC does not exist in system
 */
__STATIC_INLINE bool DL_SYSCTL_ifCSCExists(void)
{
    return ((SYSCTL->SECCFG.SECSTATUS & SYSCTL_SECSTATUS_CSCEXISTS_YES) ==
            SYSCTL_SECSTATUS_CSCEXISTS_YES);
}

/**
 *  @brief  Checks if Read Execute (RX) Protect Firewall is enabled
 *
 *  @return Whether Read Execute Protect Firewall is enabled
 *
 *  @retval  true  If Read Execute Protect Firewall is enabled
 *  @retval  false If Read Execute Protect Firewall is not enabled
 */
__STATIC_INLINE bool DL_SYSCTL_isReadExecuteProtectFirewallEnabled(void)
{
    return ((SYSCTL->SECCFG.SECSTATUS & SYSCTL_SECSTATUS_FLRXPROT_ENABLED) ==
            SYSCTL_SECSTATUS_FLRXPROT_ENABLED);
}

/**
 *  @brief  Checks if IP Protect Firewall is enabled
 *
 *  @return Whether IP Protect Firewall is enabled
 *
 *  @retval  true  If IP Protect Firewall is enabled
 *  @retval  false If IP Protect Firewall is not enabled
 */
__STATIC_INLINE bool DL_SYSCTL_isIPProtectFirewallEnabled(void)
{
    return ((SYSCTL->SECCFG.SECSTATUS & SYSCTL_SECSTATUS_FLIPPROT_ENABLED) ==
            SYSCTL_SECSTATUS_FLIPPROT_ENABLED);
}

/**
 *  @brief  Checks if SRAM Boundary Lock is enabled
 *
 *  @return Whether SRAM Boundary Lock is enabled
 *
 *  @retval  true  If SRAM Boundary Lock is enabled
 *  @retval  false If SRAM Boundary Lock is not enabled
 */
__STATIC_INLINE bool DL_SYSCTL_isSRAMBoundaryLocked(void)
{
    return ((SYSCTL->SECCFG.SECSTATUS &
                SYSCTL_SECSTATUS_SRAMBOUNDARYLOCK_ENABLED) ==
            SYSCTL_SECSTATUS_SRAMBOUNDARYLOCK_ENABLED);
}

/**
 *  @brief  Checks if Flash Bank swapping is enabled
 *
 *  @return Whether Flash Bank swap is enabled
 *
 *  @retval  true  If Flash Bank swap is enabled
 *  @retval  false If Flash Bank swap is not enabled
 */
__STATIC_INLINE bool DL_SYSCTL_isFlashBankSwapEnabled(void)
{
    return ((SYSCTL->SECCFG.SECSTATUS &
                SYSCTL_SECSTATUS_FLBANKSWPPOLICY_ENABLED) ==
            SYSCTL_SECSTATUS_FLBANKSWPPOLICY_ENABLED);
}

/**
 *  @brief  Checks if executing from upper flash bank
 *
 *  @return Whether executing from upper flash bank
 *
 *  @retval  true  If executing from upper flash bank
 *  @retval  false If not executing from upper flash bank
 */
__STATIC_INLINE bool DL_SYSCTL_isExecuteFromUpperFlashBank(void)
{
    return ((SYSCTL->SECCFG.SECSTATUS & SYSCTL_SECSTATUS_FLBANKSWP_MASK) ==
            SYSCTL_SECSTATUS_FLBANKSWP_MASK);
}

/**
 *  @brief  Checks if executing from lower flash bank
 *
 *  @return Whether executing from lower flash bank
 *
 *  @retval  true  If executing from lower flash bank
 *  @retval  false If not executing from lower flash bank
 */
__STATIC_INLINE bool DL_SYSCTL_isExecuteFromLowerFlashBank(void)
{
    return ((SYSCTL->SECCFG.SECSTATUS & SYSCTL_SECSTATUS_FLBANKSWP_MASK) !=
            SYSCTL_SECSTATUS_FLBANKSWP_MASK);
}

/**
 *  @brief  Indicate that INIT is done
 *
 *  After INITDONE is issued, the security configuration is locked and enforced.
 *  A SYSRST will occur, restarting startup code execution, and the main
 *  application is launched.
 *
 *  There is no hardware support to enforce a timeout if INITDONE is not issued
 *  in a reasonable period of time. It is recommended that the CSC use a
 *  watchdog to ensure that INITDONE is issued in a timely manner.
 */
__STATIC_INLINE void DL_SYSCTL_issueINITDONE(void)
{
    SYSCTL->SECCFG.INITDONE |=
        (SYSCTL_INITDONE_PASS_TRUE | SYSCTL_INITDONE_KEY_VALUE);
}

/**
 *  @brief  Enables super capacitor function
 *
 *  Allows battery backup system to be powered by a super capacitor
 */
__STATIC_INLINE void DL_SYSCTL_enableSuperCapacitor(void)
{
    SYSCTL->SOCLOCK.SYSTEMCFG |=
        SYSCTL_SYSTEMCFG_SUPERCAPEN_TRUE | SYSCTL_SYSTEMCFG_KEY_VALUE;
}

/**
 *  @brief  Disables super capacitor function
 *
 *  Prevents battery backup system from being powered by a super capacitor
 */
__STATIC_INLINE void DL_SYSCTL_disableSuperCapacitor(void)
{
    SYSCTL->SOCLOCK.SYSTEMCFG &=
        (~(SYSCTL_SYSTEMCFG_SUPERCAPEN_TRUE) | SYSCTL_SYSTEMCFG_KEY_VALUE);
}

/**
 *  @brief  Checks if super capacitor function is enabled
 *
 *  @return returns the state of the super capacitor bit
 *
 *  @retval  true  The super capacitor function is enabled
 *  @retval  false The super capacitor function is disabled
 */
__STATIC_INLINE bool DL_SYSCTL_isSuperCapacitorEnabled(void)
{
    return ((SYSCTL->SOCLOCK.SYSTEMCFG & SYSCTL_SYSTEMCFG_SUPERCAPEN_MASK) ==
            SYSCTL_SYSTEMCFG_SUPERCAPEN_TRUE);
}

#ifdef __cplusplus
}
#endif

#endif /* ti_dl_m0p_dl_sysctl_sysctl__include */
/** @}*/
