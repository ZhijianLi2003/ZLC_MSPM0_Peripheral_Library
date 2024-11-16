/*
 * Copyright (c) 2023, Texas Instruments Incorporated
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
 *  @file       drv8316.h
 *  @brief      DRV8316_MODULE Module
 *
 *  @anchor drv8316_h
 *  # Overview
 *  
 *  API's releated to DRV8316
 * 
 *  <hr>
 ******************************************************************************/
/** @addtogroup DRV8316_MODULE Motor Driver/DRV8316
 * @{
 */

#ifndef _DRV8316_H_
#define _DRV8316_H_

//*****************************************************************************
// the includes
//*****************************************************************************
#include "hal.h"

#ifdef __cplusplus
extern "C" {
#endif

//*****************************************************************************
//defines
//*****************************************************************************
/*! @brief Defines the address mask  */
#define DRV8316_ADDR_MASK                   (0x7E00)

/*! @brief Defines the data mask     */
#define DRV8316_DATA_MASK                   (0x00FF)

/*! @brief Defines the data transmitted while reading a register */
#define DRV8316_DATA_TRANSMIT_TO_READ       (0x00)

/*! @brief Defines the initial parity of command word */
#define DRV8316_INITIAL_PARITY              (0x00)

/*! @brief Defines the parity checking bit           */
#define DRV8316_PARITY_CHECK                (0x01)

/*! @brief Defines the number of bits right shifted  */
#define DRV8316_RIGHT_SHIFT_REGISTER        (1)

/*! @brief Defines the position of the parity in command word    */
#define DRV8316_PARITY_BIT_POSITION         (8)

/*! @brief Defines the position of the parity in command word    */
#define DRV8316_ADDR_BIT_POSITION           (9)

/*! @brief Defines the position of the parity in command word    */
#define DRV8316_SPICMD_BIT_POSITION         (15)

/*! @brief Defines the claer bit mask */
#define DRV8316_CLEAR_BIT_MASK              (0x01)

/*! @brief Defines the time to clear the nSLEEP pin to reset faults */
#define DRV8316_MAXIMUM_RESET_TIME          (40)

/*! @brief Defines the time to wakeup the drv after reset    */
#define DRV8316_MAXIMUM_WAKEUP_TIME         (2000)

/*! @brief Defines voltage conversion constant */
#define DRV8316_VOLTAGE_CONV_CONST          _IQ20(13.417)

/*! @brief Defines CSA reference voltage */
#define DRV8316_CSA_REF_VOLTAGE             (3000)

/*! @brief Defines CSA gains 0.15 in IQ20 */
#define DRV8316_CSAGAIN_0P15VA_IQ           _IQ20(0.15)

/*! @brief Defines CSA gains 0.3 in IQ20 */
#define DRV8316_CSAGAIN_0P3VA_IQ            _IQ20(0.3)

/*! @brief Defines CSA gains 0.6 in IQ20 */
#define DRV8316_CSAGAIN_0P6VA_IQ            _IQ20(0.6)

/*! @brief Defines CSA gains 1.2 in IQ20 */
#define DRV8316_CSAGAIN_1P2VA_IQ            _IQ20(1.2)

//*****************************************************************************
// typedefs
//*****************************************************************************
/*! @enum DRV8316_CTRL01_MASK */
typedef enum
{
    /*! @brief  Defines the mask for clear fault bit            */
    DRV8316_CTRL01_MASK_REG_LOCK = 0x07 << 0
}DRV8316_CTRL01_MASK;

/*! @enum DRV8316_CTRL02_MASK */
typedef enum
{
    /*! @brief  Defines the mask for clear fault bit           */
    DRV8316_CTRL02_MASK_CLR_FLT     = 0x01 << 0,
    /*! @brief  Defines the mask for pwm mode selection bit    */
    DRV8316_CTRL02_MASK_PWM_MODE    = 0x03 << 1,
    /*! @brief  Defines the mask for slew rate selection bit   */
    DRV8316_CTRL02_MASK_SLEW        = 0x03 << 3,
    /*! @brief  Defines the mask for SDO mode selection bit    */
    DRV8316_CTRL02_MASK_SDO_MODE    = 0x01 << 5
}DRV8316_CTRL02_MASK;

/*! @enum DRV8316_CTRL03_MASK */
typedef enum
{
    /*! @brief  Defines the mask for over temp warning bit                        */
    DRV8316_CTRL03_MASK_OTW_REP             = 0x01 << 0,
    /*! @brief  Defines the mask for over voltage protection enable bit           */
    DRV8316_CTRL03_MASK_OVP_EN              = 0x01 << 2,
    /*! @brief  Defines the mask for over voltage protection level setting bit    */
    DRV8316_CTRL03_MASK_OVP_SEL             = 0x01 << 3,
    /*! @brief  Defines the mask for frequency selection bit                      */
    DRV8316_CTRL03_MASK_PWM_100_DUTY_SEL    = 0x01 << 4
}DRV8316_CTRL03_MASK;

/*! @enum DRV8316_CTRL04_MASK */
typedef enum
{
    /*! @brief  Defines the mask for over current protection mode selection bit           */
    DRV8316_CTRL04_MASK_OCP_MODE    = 0x03 << 0,
    /*! @brief  Defines the mask for over current protection level setting bit            */
    DRV8316_CTRL04_MASK_OCP_LVL     = 0x01 << 2,
    /*! @brief  Defines the mask for over current protection retry time setting bit       */
    DRV8316_CTRL04_MASK_OCP_RETRY   = 0x01 << 3,
    /*! @brief  Defines the mask for over current protection deglitch time setting bit    */
    DRV8316_CTRL04_MASK_OCP_DEG     = 0x03 << 4,
    /*! @brief  Defines the mask for over current protection pwm cycle operation bit      */
    DRV8316_CTRL04_MASK_OCP_CBC     = 0x01 << 6,
    /*! @brief  Defines the mask for drvoff bit                                           */
    DRV8316_CTRL04_MASK_DRV_OFF     = 0x01 << 7
}DRV8316_CTRL04_MASK;

/*! @enum DRV8316_CTRL05_MASK */
typedef enum
{
    /*! @brief  Defines the mask for CSA gain setting bit                         */
    DRV8316_CTRL05_MASK_CSA_GAIN        = 0x03 << 0,
    /*! @brief  Defines the mask for Active Synchronous Rectification Enable bit  */
    DRV8316_CTRL05_MASK_EN_ASR          = 0x01 << 2,
    /*! @brief  Defines the mask for Active Asynshronous Rectification Enable bit */
    DRV8316_CTRL05_MASK_EN_AAR          = 0x01 << 3,
    /*! @brief  Defines the mask for Current Limit Recirculation Settings bit     */
    DRV8316_CTRL05_MASK_ILIM_RECIR      = 0x01 << 6
}DRV8316_CTRL05_MASK;

/*! @enum DRV8316_CTRL06_MASK */
typedef enum
{
    /*! @brief  Defines the mask for buck disable bit                 */
    DRV8316_CTRL06_MASK_BUCK_DIS        = 0x01 << 0,
    /*! @brief  Defines the mask for buck voltage selection bit       */
    DRV8316_CTRL06_MASK_BUCK_SEL        = 0x03 << 1,
    /*! @brief  Defines the mask for buck current limit setting bit   */
    DRV8316_CTRL06_MASK_BUCK_CL         = 0x01 << 3,
    /*! @brief  Defines the mask for buck power sequence disable bit  */
    DRV8316_CTRL06_MASK_BUCK_PS_DIS     = 0x01 << 4
}DRV8316_CTRL06_MASK;

/*! @enum DRV8316_CTRL10_MASK */
typedef enum
{
    /*! @brief  Defines the mask for delay target bit                     */
    DRV8316_CTRL10_MASK_DLY_TARGET      = 0x0F << 0,
    /*! @brief  Defines the mask for driver delay compensation enable bit */
    DRV8316_CTRL10_MASK_DLYCMP_EN       = 0x01 << 4,
}DRV8316_CTRL10_MASK;

/*! @enum DRV8316_CTRL01 */
typedef enum
{
    /*! @brief  unlock all registers      */
    DRV8316_CTRL01_REG_UNLOCK   = 0x03 << 0,
    /*! @brief  lock all registers        */
    DRV8316_CTRL01_REG_LOCK     = 0x06 << 0,
}DRV8316_CTRL01;

/*! @enum DRV8316_CTRL02 */
typedef enum
{
    /*! @brief  clear the latched faults                          */
    DRV8316_CTRL02_CLR_FLT              = 0x01 << 0,
    /*! @brief  set 6x pwm mode                                   */
    DRV8316_CTRL02_PWMMODE_6x           = 0x00 << 1,
    /*! @brief  set 6x pwm mode with current limit                */
    DRV8316_CTRL02_PWMMODE_6x_CL        = 0x01 << 1,
    /*! @brief  set 3x pwm mode                                   */
    DRV8316_CTRL02_PWMMODE_3x           = 0x02 << 1,
    /*! @brief  set 3x pwm mode with current limit                */
    DRV8316_CTRL02_PWMMODE_3x_CL        = 0x03 << 1,
    /*! @brief  set slew rate to 25V/us                           */
    DRV8316_CTRL02_SLEWRATE_25          = 0x00 << 3,
    /*! @brief  set slew rate to 50V/us                           */
    DRV8316_CTRL02_SLEWRATE_50          = 0x01 << 3,
    /*! @brief  set slew rate to 125V/us                          */
    DRV8316_CTRL02_SLEWRATE_125         = 0x02 << 3,
    /*! @brief  set slew rate to 200V/us                          */
    DRV8316_CTRL02_SLEWRATE_200         = 0x03 << 3,
    /*! @brief  set SDO in open drain mode                        */
    DRV8316_CTRL02_SDO_OPEN_DRAIN_MODE  = 0x00 << 5,
    /*! @brief  set SDO in push pull mode                         */
    DRV8316_CTRL02_SDO_PUSH_PULL_MODE   = 0x01 << 5
}DRV8316_CTRL02;

/*! @enum DRV8316_CTRL03 */
typedef enum
{
    /*! @brief  Disable over temperature warning              */
    DRV8316_CTRL03_OTW_REP_DISABLE  = 0x00 << 0,
    /*! @brief  Enable over temperature warning               */
    DRV8316_CTRL03_OTW_REP_ENABLE   = 0x01 << 0,
    /*! @brief  Disable over voltage protection               */
    DRV8316_CTRL03_OVP_DISABLE      = 0x00 << 2,
    /*! @brief  Enable over voltage protection                */
    DRV8316_CTRL03_OVP_ENABLE       = 0x01 << 2,
    /*! @brief  over voltage protection limit set to 34V      */
    DRV8316_CTRL03_OVP_SEL_34V      = 0x00 << 3,
    /*! @brief  over voltage protection limit set to 22V      */
    DRV8316_CTRL03_OVP_SEL_22V      = 0x01 << 3,
    /*! @brief  PMW Freq at 100% duty is set to 20KHz         */
    DRV8316_CTRL03_PWM_20KHZ        = 0x00 << 4,
    /*! @brief  PMW Freq at 100% duty is set to 40KHz         */
    DRV8316_CTRL03_PWM_40KHZ        = 0x01 << 4
}DRV8316_CTRL03;

/*! @enum DRV8316_CTRL04 */
typedef enum
{
    /*! @brief  set over current fault to latched                         */
    DRV8316_CTRL04_OCP_LATCHED              = 0x00 << 0,
    /*! @brief  set over current fault to automatic retry                 */
    DRV8316_CTRL04_OCP_AUTO_RETRY           = 0x01 << 0,
    /*! @brief  report over current fault                                 */
    DRV8316_CTRL04_OCP_REPORT               = 0x02 << 0,
    /*! @brief  disable over current fault                                */
    DRV8316_CTRL04_OCP_DISABLE              = 0x03 << 0,
    /*! @brief  set over current protection level to 16A                  */
    DRV8316_CTRL04_OCP_LVL_16A              = 0x00 << 2,
    /*! @brief  set over current protection level to 24A                  */
    DRV8316_CTRL04_OCP_LVL_24A              = 0x01 << 2,
    /*! @brief  set over current protection retry time to 5ms             */
    DRV8316_CTRL04_OCP_RETRY_5MS            = 0x00 << 3,
    /*! @brief  set over current protection retry time to 500ms           */
    DRV8316_CTRL04_OCP_RETRY_500MS          = 0x01 << 3,
    /*! @brief  set over current protection deglitch time to 0.2us        */
    DRV8316_CTRL04_OCP_DEG_0P2US            = 0x00 << 4,
    /*! @brief  set over current protection deglitch time to 0.6us        */
    DRV8316_CTRL04_OCP_DEG_0P6US            = 0x01 << 4,
    /*! @brief  set over current protection deglitch time to 1.25us       */
    DRV8316_CTRL04_OCP_DEG_1P25US           = 0x02 << 4,
    /*! @brief  set over current protection deglitch time to 1.6us        */
    DRV8316_CTRL04_OCP_DEG_1P6US            = 0x03 << 4,
    /*! @brief  set over current protection pwm cycle operation dsiable   */
    DRV8316_CTRL04_OCP_CBC_DISABLE          = 0x00 << 6,
    /*! @brief  set over current protection pwm cycle operation enable    */
    DRV8316_CTRL04_OCP_CBC_ENABLE           = 0x01 << 6,
    /*! @brief  enable DRV                                                */
    DRV8316_CTRL04_DRV_OFF_NO_ACTION        = 0x00 << 7,
    /*! @brief  enter DRV into low power mode                             */
    DRV8316_CTRL04_DRV_OFF_LOW_POWER_MODE   = 0x01 << 7
}DRV8316_CTRL04;

/*! @enum DRV8316_CTRL05 */
typedef enum
{
    /*! @brief  set CSAGAIN to 0.15V/A                        */
    DRV8316_CTRL05_CSA_GAIN_0P15VA          = 0x00 << 0,
    /*! @brief  set CSAGAIN to 0.3V/A                         */
    DRV8316_CTRL05_CSA_GAIN_0P3VA           = 0x01 << 0,
    /*! @brief  set CSAGAIN to 0.6V/A                         */
    DRV8316_CTRL05_CSA_GAIN_0P6VA           = 0x02 << 0,
    /*! @brief  set CSAGAIN to 1.2V/A                         */
    DRV8316_CTRL05_CSA_GAIN_1P2VA           = 0x03 << 0,
    /*! @brief  disable Active synchronous rectification      */
    DRV8316_CTRL05_EN_ASR_DISABLE           = 0x00 << 2,
    /*! @brief  enable Active synchronous rectification       */
    DRV8316_CTRL05_EN_ASR_ENABLE            = 0x01 << 2,
    /*! @brief  disable Active asynchronous rectification     */
    DRV8316_CTRL05_EN_AAR_DISABLE           = 0x00 << 3,
    /*! @brief  enable Active asynchronous rectification      */
    DRV8316_CTRL05_EN_AAR_ENABLE            = 0x01 << 3,
    /*! @brief  set braking type to brake mode                */
    DRV8316_CTRL05_ILIM_RECIR_BRAKE_MODE    = 0x00 << 6,
    /*! @brief  set braking type to coast mode                */
    DRV8316_CTRL05_ILIM_RECIR_COAST_MODE    = 0x01 << 6,
}DRV8316_CTRL05;

/*! @enum DRV8316_CTRL06 */
typedef enum
{
    /*! @brief  enable buck regulator                         */
    DRV8316_CTRL06_BUCK_DIS_ENABLE          = 0x00 << 0,
    /*! @brief  disable buck regulator                        */
    DRV8316_CTRL06_BUCK_DIS_DISABLE         = 0x01 << 0,
    /*! @brief  set buck voltage selection to 3.3V            */
    DRV8316_CTRL06_BUCK_SEL_3P3V            = 0x00 << 1,
    /*! @brief  set buck voltage selection to 5.0V            */
    DRV8316_CTRL06_BUCK_SEL_5P0V            = 0x01 << 1,
    /*! @brief  set buck voltage selection to 4.0V            */
    DRV8316_CTRL06_BUCK_SEL_4P0V            = 0x02 << 1,
    /*! @brief  set buck voltage selection to 5.7V            */
    DRV8316_CTRL06_BUCK_SEL_5P7V            = 0x03 << 1,
    /*! @brief  set buck current limit to 600mA               */
    DRV8316_CTRL06_BUCK_CL_600MA            = 0x00 << 3,
    /*! @brief  set buck current limit to 150mA               */
    DRV8316_CTRL06_BUCK_CL_150MA            = 0x01 << 3,
    /*! @brief  enable buck power sequencing                  */
    DRV8316_CTRL06_BUCK_PS_DIS_ENABLE       = 0x00 << 4,
    /*! @brief  disable buck power sequencing                 */
    DRV8316_CTRL06_BUCK_PS_DIS_DISABLE      = 0x01 << 4,
}DRV8316_CTRL06;

/*! @enum DRV8316_CTRL10 */
typedef enum
{
    /*! @brief Delay Target 0.0us */
    DRV8316_CTRL10_DLY_TARGET_0P0US    = 0x00 << 0,
    /*! @brief Delay Target 0.4us */
    DRV8316_CTRL10_DLY_TARGET_0P4US    = 0x01 << 0,
    /*! @brief Delay Target 0.6us */
    DRV8316_CTRL10_DLY_TARGET_0P6US    = 0x02 << 0,
    /*! @brief Delay Target 0.8us */
    DRV8316_CTRL10_DLY_TARGET_0P8US    = 0x03 << 0,
    /*! @brief Delay Target 1.0us */
    DRV8316_CTRL10_DLY_TARGET_1P0US    = 0x04 << 0,
    /*! @brief Delay Target 1.2us */
    DRV8316_CTRL10_DLY_TARGET_1P2US    = 0x05 << 0,
    /*! @brief Delay Target 1.4us */
    DRV8316_CTRL10_DLY_TARGET_1P4US    = 0x06 << 0,
    /*! @brief Delay Target 1.6us */
    DRV8316_CTRL10_DLY_TARGET_1P6US    = 0x07 << 0,
    /*! @brief Delay Target 1.8us */
    DRV8316_CTRL10_DLY_TARGET_1P8US    = 0x08 << 0,
    /*! @brief Delay Target 2.0us */
    DRV8316_CTRL10_DLY_TARGET_2P0US    = 0x09 << 0,
    /*! @brief Delay Target 2.2us */
    DRV8316_CTRL10_DLY_TARGET_2P2US    = 0x0A << 0,
    /*! @brief Delay Target 2.4us */
    DRV8316_CTRL10_DLY_TARGET_2P4US    = 0x0B << 0,
    /*! @brief Delay Target 2.6us */
    DRV8316_CTRL10_DLY_TARGET_2P6US    = 0x0C << 0,
    /*! @brief Delay Target 2.8us */
    DRV8316_CTRL10_DLY_TARGET_2P8US    = 0x0D << 0,
    /*! @brief Delay Target 3.0us */
    DRV8316_CTRL10_DLY_TARGET_3P0US    = 0x0E << 0,
    /*! @brief Delay Target 3.2us */
    DRV8316_CTRL10_DLY_TARGET_3P2US    = 0x0F << 0,
    /*! @brief  disable driver delay compensation   */
    DRV8316_CTRL10_DLYCMP_EN_DISABLE   = 0x00 << 4,
    /*! @brief  enable driver delay compensation    */
    DRV8316_CTRL10_DLYCMP_EN_ENABLE    = 0x01 << 4
}DRV8316_CTRL10;

/*! @enum DRV8316_SPI */
typedef enum
{
    /*! @brief DRV8316 SPI read command */
    DRV8316_SPI_READ = 1 << 15,     
    /*! @brief DRV8316 SPI write command */
    DRV8316_SPI_WRITE = 0 << 15     
}DRV8316_SPI;

/*! @enum DRV8316_ADDR */
typedef enum
{
    /*! @brief Address of Static Register 0 */
    DRV8316_ADDR_STAT_IC = 0x0,         
    /*! @brief Address of Static Register 1 */
    DRV8316_ADDR_STAT_1 = 0x1,          
    /*! @brief Address of Static Register 2 */
    DRV8316_ADDR_STAT_2 = 0x2,          
    /*! @brief Address of Control Register 1 */
    DRV8316_ADDR_CTRL_1 = 0x3,          
    /*! @brief Address of Control Register 2 */
    DRV8316_ADDR_CTRL_2 = 0x4,          
    /*! @brief Address of Control Register 3 */
    DRV8316_ADDR_CTRL_3 = 0x5,          
    /*! @brief Address of Control Register 4 */
    DRV8316_ADDR_CTRL_4 = 0x6,          
    /*! @brief Address of Control Register 5 */
    DRV8316_ADDR_CTRL_5 = 0x7,          
    /*! @brief Address of Control Register 6 */
    DRV8316_ADDR_CTRL_6 = 0x8,          
    /*! @brief Address of Control Register 10 */
    DRV8316_ADDR_CTRL_10 = 0xC          
} DRV8316_ADDR;

/*! @enum DRV8316_CSAGAIN */
typedef enum
{
    /*! @brief Define DRV8316 CSA GAIN 0.15 Setting */
    DRV8316_CSAGAIN_0P15VA = 0x00 << 0,
    /*! @brief Define DRV8316 CSA GAIN 0.3 Setting */
    DRV8316_CSAGAIN_0P3VA = 0x01 << 0,
    /*! @brief Define DRV8316 CSA GAIN 0.6 Setting */
    DRV8316_CSAGAIN_0P6VA = 0x02 << 0,
    /*! @brief Define DRV8316 CSA GAIN 1.2 Setting */
    DRV8316_CSAGAIN_1P2VA = 0x03 << 0
}DRV8316_CSAGAIN;

/*! @enum DRV8316_DRVOFF_PIN_STAT */
typedef enum
{
    /*! @brief Define DRVOFF PIN LOW */
    DRV8316_DRVOFF_PIN_LOW = HAL_GPIO_PIN_LOW,
    /*! @brief Define DRVOFF PIN HIGH */
    DRV8316_DRVOFF_PIN_HIGH = HAL_GPIO_PIN_HIGH
}DRV8316_DRVOFF_PIN_STAT;

/*! @enum  DRV8316_DRV_NSLEEP_STAT */
typedef enum
{
    /*! @brief Define NSLEEP PIN LOW */
    DRV8316_DRV_NSLEEP_SLEEP = HAL_GPIO_PIN_LOW,
    /*! @brief Define NSLEEP PIN HIGH */
    DRV8316_DRV_NSLEEP_AWAKE = HAL_GPIO_PIN_HIGH
}DRV8316_DRV_NSLEEP_STAT;

/*! @brief Defines DRV8316 instance  */
typedef struct
{
    /*!
     * HAL output pin connected to the motor driver's nsleep pin.
     */
    HAL_GPIO_OUT    nsleep;
    /*!
     * HAL output pin connected to the motor driver's drvoff pin.
     */
    HAL_GPIO_OUT    drvoff;
    /*!
     * HAL input pin connected to the motor driver's nfault pin.
     */
    HAL_GPIO_IN     nfault;
    /*!
     * HAL SPI channel connected to the motor driver's spi pins
     */
    HAL_SPI_CHAN    spiChan;
    /*!
     * HAL SPI CS connected to the motor driver's spi cs pin
     */
    HAL_SPI_CS      spiCs;
    /*!
     * Scale factor used to cache values needed to calculate current
     */
    _iq20           csa_sf;
    /*!
     * Scale factor used to cache values needed to calculate current
     */
    _iq20           csaVRef;
    /*!
     * ADc channels used to measure bus voltage
     */
    HAL_ADC_CHAN    Vsen;
    /*!
     * ADc channels used to measure phase A voltage
     */
    HAL_ADC_CHAN    VsenA;
    /*!
     * ADc channels used to measure phase B voltage
     */
    HAL_ADC_CHAN    VsenB;
    /*!
     * ADc channels used to measure phase C voltage
     */
    HAL_ADC_CHAN    VsenC;
    /*!
     * ADc channels used to measure phase A current
     */
    HAL_ADC_CHAN    IsenA;
    /*!
     * ADc channels used to measure phase B current
     */
    HAL_ADC_CHAN    IsenB;
    /*!
     * ADc channels used to measure phase C current
     */
    HAL_ADC_CHAN    IsenC;
    /*!
     * pwm timer to which fault pin is connected
     */
    HAL_FAULT_INPUT faultIn;

}DRV8316_Instance;

//*****************************************************************************
// the function prototypes
//*****************************************************************************
/**
 * @brief set drvoff
 * @param[in] drvHandle   The drv instance
 * @param[in] value        drvoff value
 */
__STATIC_INLINE void DRV8316_setDrvoff(
        DRV8316_Instance *drvHandle, DRV8316_DRVOFF_PIN_STAT value)
{
  if(value == DRV8316_DRVOFF_PIN_HIGH)
  {
      HAL_writeGPIOPin(drvHandle->drvoff, HAL_GPIO_PIN_HIGH);
  }
  else if(value == DRV8316_DRVOFF_PIN_LOW)
  {
      HAL_writeGPIOPin(drvHandle->drvoff, HAL_GPIO_PIN_LOW);
  }
  else
  {
      /* This is expected to be empty */
  }
}

/**
 * @brief set nSleep
 * @param[in] drvHandle   The drv instance
 * @param[in] value nSleep value
 */
__STATIC_INLINE void DRV8316_setnSleep(
        DRV8316_Instance *drvHandle, DRV8316_DRV_NSLEEP_STAT value)
{
  if(value == DRV8316_DRV_NSLEEP_AWAKE)
  {
      HAL_writeGPIOPin(drvHandle->nsleep, HAL_GPIO_PIN_HIGH);
  }
  else if(value == DRV8316_DRV_NSLEEP_SLEEP)
  {
      HAL_writeGPIOPin(drvHandle->nsleep, HAL_GPIO_PIN_LOW);
  }
  else
  {
      /* This is expected to be empty */
  }
    /* tWake - Turnon time = 1ms
     * tSleep - Turnoff time = 1ms
     * So not matter what you set sleep pin to just wait 1 ms
     */
  HAL_delayMicroSeconds(DRV8316_MAXIMUM_WAKEUP_TIME);
}

/**
 * @brief initialize the drv8316 module
 * @param[in] drvHandle   The drv instance
 */
void DRV8316_init(DRV8316_Instance *drvHandle);

/**
 * @brief write data to spi
 * @param[in] drvHandle  The drv instance
 * @param[in] addr        SPI register address
 * @param[in] data        data transmitted
 * @return     Return 
 */
uint16_t DRV8316_SPIWrite(
        DRV8316_Instance *drvHandle, DRV8316_ADDR addr, uint8_t data);

/**
 * @brief write data to spi
 * @param[in] drvHandle  The drv instance
 * @param[in] addr        SPI register address
 * @return     Return  
 */
uint16_t DRV8316_SPIRead(
        DRV8316_Instance *drvHandle, DRV8316_ADDR addr);

/**
 * @brief     Enable DRV
 * @param[in] drvHandle   The drv instance
 */
void DRV8316_enable(DRV8316_Instance *drvHandle);

/**
 * @brief     update the drv registers
 * @param[in] drvHandle The drv instance
 * @param[in] regAddr    The register to be updated
 * @param[in] value      new value of the bits to be updated
 * @param[in] mask       mask for the bit to be updated
 */
void DRV8316_updateCTRLRegs(
        DRV8316_Instance *drvHandle, DRV8316_ADDR regAddr,
        uint16_t value, uint16_t mask);

/**
 * @brief updates the current gain scale factor
 * @param[in] drvHandle  The drv instance
 * @param[in] csa         DRV8316 CSA gain value
 */
void DRV8316_updateCSAScaleFactor(
        DRV8316_Instance *drvHandle, DRV8316_CSAGAIN csa);

/**
 * @brief Get voltage from adc channel
 * @param[in] chan  The ADC channel name
 * @return     Return  
 */
_iq20 DRV8316_getVoltage(HAL_ADC_CHAN chan);

/**
 * @brief Get current from adc channel
 * @param[in] chan The ADC channel name
 * @param[in] drvHandle The drv instance
 * @param[in] vRef voltage reference for current
 * @return     Return  
 */
_iq20 DRV8316_getCurrent(HAL_ADC_CHAN chan,
        DRV8316_Instance *drvHandle, _iq20 vRef);

/**
 * @brief updates the adc voltage reference
 * @param[in] adcRef  ADC voltage reference
 * @param[in] chan    ADC channel name
 * @param[in] internalVRef  Internal reference voltage
 * @param[in] externalVRef  External reference voltage
 */
void DRV8316_ADCVRefSel(HAL_ADC_VREF adcRef, HAL_ADC_CHAN chan,
                        HAL_ADC_INT_VREF internalVRef, uint16_t externalVRef);


/**
 * @brief Update the SPI CSA gain register
 * @param[in] drvHandle   The drv instance
 * @param[in] csaGain     The CSA gain value
 */
__STATIC_INLINE void DRV8316_updateSPICsagain(
        DRV8316_Instance *drvHandle, DRV8316_CSAGAIN csaGain)
{
    DRV8316_updateCTRLRegs(drvHandle,
                           DRV8316_ADDR_CTRL_5,
                           csaGain,
                           DRV8316_CTRL05_MASK_CSA_GAIN);
}

/**
 * @brief unlock all registers
 * @param[in] drvHandle  The drv instance
 */
__STATIC_INLINE void DRV8316_unlockRegs(DRV8316_Instance *drvHandle)
{
    DRV8316_updateCTRLRegs(drvHandle,
                           DRV8316_ADDR_CTRL_1,
                           DRV8316_CTRL01_REG_UNLOCK,
                           DRV8316_CTRL01_MASK_REG_LOCK);
}

/**
 * @brief clear the status registers
 * @param[in] drvHandle  The drv instance
 */
__STATIC_INLINE void DRV8316_clearfaultBit(DRV8316_Instance *drvHandle)
{
    DRV8316_updateCTRLRegs(drvHandle,
                           DRV8316_ADDR_CTRL_2,
                           DRV8316_CTRL02_CLR_FLT,
                           DRV8316_CTRL02_MASK_CLR_FLT);
}

/**
 * @brief  get Current reference in IQ20
 * @param[in] vRef  CSA reference voltage in milli volts
 * @return    _iq20 CSA reference voltage in _iq20 format
 */
__STATIC_INLINE _iq20 DRV8316_getcsaVref(uint16_t vRef)
{
    _iq13 temp = _IQ13div(_IQ13(vRef),_IQ13(1000));
    return _IQ13toIQ20(temp);
}

#ifdef __cplusplus
}
#endif
#endif /* _DRV8316_H_ */
/** @}*/
