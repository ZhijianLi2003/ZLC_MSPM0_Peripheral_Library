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
 *  @file       drv8889-q1.h
 *  @brief      MD_MODULE2 Module
 *
 *
 *  @anchor drv8889q1_h
 *  # Overview
 *
 *  Does stuff
 *
 *  <hr>
 ******************************************************************************/
/** @defgroup MD_MODULE2 Motor_Driver/DRV8889Q1
 * @{
 */
#ifndef DRV8889Q1_H
#define DRV8889Q1_H

#include <stdbool.h>
#include "hal.h"

/* Include the IQmath Library */
#include <ti/iqmath/include/IQmathLib.h>

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * @brief Delay to wait for the SPI to be ready when the DRV is powered on
 */
#define DRV8889Q1_SPI_READY_DELAY_MS                (1)

/*!
 * @brief Step pin Dutycycle in percentage
 */
#define DRV8889Q1_STEP_DUTYCYCLE                    (50)

/*!
 * @brief Max Timer frequency limit
 */
#define DRV8889Q1_MAX_SET_FREQ                      (300000)


/*! @brief Defines the offset for fault bit */
#define DRV8889Q1_REG_FAULT_STATUS_FAULT_OFS        (7)

/*! @brief Defines the offset for spi error bit */
#define DRV8889Q1_REG_FAULT_STATUS_SPI_ERROR_OFS    (6)

/*! @brief Defines the offset for under voltage fault bit */
#define DRV8889Q1_REG_FAULT_STATUS_UVLO_OFS         (5)

/*! @brief Defines the offset for charge pump under voltage fault bit */
#define DRV8889Q1_REG_FAULT_STATUS_CPUV_OFS         (4)

/*! @brief Defines the offset for over current fault bit */
#define DRV8889Q1_REG_FAULT_STATUS_OCP_OFS          (3)

/*! @brief Defines the offset for motor stall fault bit */
#define DRV8889Q1_REG_FAULT_STATUS_STL_OFS          (2)

/*! @brief Defines the offset for over temperature warning or under temperature 
warning or over temperature shutdown fault bit */
#define DRV8889Q1_REG_FAULT_STATUS_TF_OFS           (1)

/*! @brief Defines the offset for open load fault bit */
#define DRV8889Q1_REG_FAULT_STATUS_OL_OFS           (0)

/*! @brief Defines the offset for fault bit */
#define DRV8889Q1_REG_FAULT_STATUS_FAULT_MASK     \
                                (1<<DRV8889Q1_REG_FAULT_STATUS_FAULT_OFS)

/*! @brief Defines the mask for spi error bit */
#define DRV8889Q1_REG_FAULT_STATUS_SPI_ERROR_MASK \
                                (1<<DRV8889Q1_REG_FAULT_STATUS_SPI_ERROR_OFS)

/*! @brief Defines the mask for under voltage fault bit */
#define DRV8889Q1_REG_FAULT_STATUS_UVLO_MASK      \
                                (1<<DRV8889Q1_REG_FAULT_STATUS_UVLO_OFS)

/*! @brief Defines the mask for Charge pump under voltage fault bit */
#define DRV8889Q1_REG_FAULT_STATUS_CPUV_MASK      \
                                (1<<DRV8889Q1_REG_FAULT_STATUS_CPUV_OFS)

/*! @brief Defines the mask for over current fault bit */
#define DRV8889Q1_REG_FAULT_STATUS_OCP_MASK       \
                                (1<<DRV8889Q1_REG_FAULT_STATUS_OCP_OFS)

/*! @brief Defines the mask for motor stall fault bit */
#define DRV8889Q1_REG_FAULT_STATUS_STL_MASK       \
                                (1<<DRV8889Q1_REG_FAULT_STATUS_STL_OFS)

/*! @brief Defines the mask for over temperature warning or under temperature 
warning or over temperature shutdown fault bit */
#define DRV8889Q1_REG_FAULT_STATUS_TF_MASK        \
                                (1<<DRV8889Q1_REG_FAULT_STATUS_TF_OFS)

/*! @brief Defines the mask for open load bit */
#define DRV8889Q1_REG_FAULT_STATUS_OL_MASK        \
                                (1<<DRV8889Q1_REG_FAULT_STATUS_OL_OFS)




/*! @brief Defines the offset for overcurrent fault on the low-side FET of 
half bridge 2 in BOUT */
#define DRV8889Q1_REG_DIAG_STATUS_1_OCP_LS2_B_OFS     (7)

/*! @brief Defines the offset for overcurrent fault on the high-side FET of 
half bridge 2 in BOUT */
#define DRV8889Q1_REG_DIAG_STATUS_1_OCP_HS2_B_OFS     (6)

/*! @brief Defines the offset for overcurrent fault on the low-side FET of 
half bridge 1 in BOUT */
#define DRV8889Q1_REG_DIAG_STATUS_1_OCP_LS1_B_OFS     (5)

/*! @brief Defines the offset for overcurrent fault on the high-side FET of 
half bridge 1 in BOUT */
#define DRV8889Q1_REG_DIAG_STATUS_1_OCP_HS1_B_OFS     (4)

/*! @brief Defines the offset for overcurrent fault on the low-side FET of 
half bridge 2 in AOUT */
#define DRV8889Q1_REG_DIAG_STATUS_1_OCP_LS2_A_OFS     (3)

/*! @brief Defines the offset for overcurrent fault on the high-side FET of 
half bridge 2 in AOUT */
#define DRV8889Q1_REG_DIAG_STATUS_1_OCP_HS2_A_OFS     (2)

/*! @brief Defines the offset for overcurrent fault on the low-side FET of 
half bridge 1 in AOUT */
#define DRV8889Q1_REG_DIAG_STATUS_1_OCP_LS1_A_OFS     (1)

/*! @brief Defines the offset for overcurrent fault on the high-side FET of 
half bridge 1 in AOUT */
#define DRV8889Q1_REG_DIAG_STATUS_1_OCP_HS1_A_OFS     (0)

/*! @brief Defines the mask for overcurrent fault on the low-side FET of 
half bridge 2 in BOUT */
#define DRV8889Q1_REG_DIAG_STATUS_1_OCP_LS2_B_MASK    \
                                (1<<DRV8889Q1_REG_DIAG_STATUS_1_OCP_LS2_B_OFS)
                                
/*! @brief Defines the mask for overcurrent fault on the high-side FET of 
half bridge 2 in BOUT */
#define DRV8889Q1_REG_DIAG_STATUS_1_OCP_HS2_B_MASK    \
                                (1<<DRV8889Q1_REG_DIAG_STATUS_1_OCP_HS2_B_OFS)
                                
/*! @brief Defines the mask for overcurrent fault on the low-side FET of 
half bridge 1 in BOUT */
#define DRV8889Q1_REG_DIAG_STATUS_1_OCP_LS1_B_MASK    \
                                (1<<DRV8889Q1_REG_DIAG_STATUS_1_OCP_LS1_B_OFS)
                                
/*! @brief Defines the mask for overcurrent fault on the high-side FET of 
half bridge 1 in BOUT */
#define DRV8889Q1_REG_DIAG_STATUS_1_OCP_HS1_B_MASK    \
                                (1<<DRV8889Q1_REG_DIAG_STATUS_1_OCP_HS1_B_OFS)
                                
/*! @brief Defines the mask for overcurrent fault on the low-side FET of 
half bridge 2 in AOUT */
#define DRV8889Q1_REG_DIAG_STATUS_1_OCP_LS2_A_MASK    \
                                (1<<DRV8889Q1_REG_DIAG_STATUS_1_OCP_LS2_A_OFS)
                                
/*! @brief Defines the mask for overcurrent fault on the high-side FET of 
half bridge 2 in AOUT */
#define DRV8889Q1_REG_DIAG_STATUS_1_OCP_HS2_A_MASK    \
                                (1<<DRV8889Q1_REG_DIAG_STATUS_1_OCP_HS2_A_OFS)
                                
/*! @brief Defines the mask for overcurrent fault on the low-side FET of 
half bridge 1 in AOUT */
#define DRV8889Q1_REG_DIAG_STATUS_1_OCP_LS1_A_MASK    \
                                (1<<DRV8889Q1_REG_DIAG_STATUS_1_OCP_LS1_A_OFS)
                                
/*! @brief Defines the mask for overcurrent fault on the high-side FET of 
half bridge 1 in AOUT */
#define DRV8889Q1_REG_DIAG_STATUS_1_OCP_HS1_A_MASK    \
                                (1<<DRV8889Q1_REG_DIAG_STATUS_1_OCP_HS1_A_OFS)


/*! @brief Defines the offset for undertemperature warning bit */
#define DRV8889Q1_REG_DIAG_STATUS_2_UTW_OFS             (7)

/*! @brief Defines the offset for overtemperature warning bit */
#define DRV8889Q1_REG_DIAG_STATUS_2_OTW_OFS             (6)

/*! @brief Defines the offset for overtemperature shutdown bit */
#define DRV8889Q1_REG_DIAG_STATUS_2_OTS_OFS             (5)

/*! @brief Defines the offset for stall learning is successful bit */
#define DRV8889Q1_REG_DIAG_STATUS_2_STL_LRN_OK_OFS      (4)

/*! @brief Defines the offset for motor stall condition bit */
#define DRV8889Q1_REG_DIAG_STATUS_2_STALL_OFS           (3)

/*! @brief Defines the offset for open load detection on BOUT */
#define DRV8889Q1_REG_DIAG_STATUS_2_OL_B_OFS            (1)

/*! @brief Defines the offset for open load detection on AOUT */
#define DRV8889Q1_REG_DIAG_STATUS_2_OL_A_OFS            (0)

/*! @brief Defines the mask for undertemperature warning bit */
#define DRV8889Q1_REG_DIAG_STATUS_2_UTW_MASK    \
                                        (1<<DRV8889Q1_REG_DIAG_STATUS_2_UTW_OFS)
                                     
/*! @brief Defines the mask for overtemperature warning bit */   
#define DRV8889Q1_REG_DIAG_STATUS_2_OTW_MASK    \
                                        (1<<DRV8889Q1_REG_DIAG_STATUS_2_OTW_OFS)
                                    
/*! @brief Defines the mask for overtemperature shutdown bit */    
#define DRV8889Q1_REG_DIAG_STATUS_2_OTS_MASK    \
                                        (1<<DRV8889Q1_REG_DIAG_STATUS_2_OTS_OFS)

/*! @brief Defines the mask for stall learning is successful bit */                                        
#define DRV8889Q1_REG_DIAG_STATUS_2_STL_LRN_OK_MASK    \
                                (1<<DRV8889Q1_REG_DIAG_STATUS_2_STL_LRN_OK_OFS)

/*! @brief Defines the mask for motor stall condition bit */
#define DRV8889Q1_REG_DIAG_STATUS_2_STALL_MASK    \
                                    (1<<DRV8889Q1_REG_DIAG_STATUS_2_STALL_OFS)
                                    
/*! @brief Defines the mask for open load detection on BOUT */
#define DRV8889Q1_REG_DIAG_STATUS_2_OL_B_MASK    \
                                    (1<<DRV8889Q1_REG_DIAG_STATUS_2_OL_B_OFS)

/*! @brief Defines the mask for open load detection on AOUT */                                    
#define DRV8889Q1_REG_DIAG_STATUS_2_OL_A_MASK    \
                                    (1<<DRV8889Q1_REG_DIAG_STATUS_2_OL_A_OFS)


/*! @brief Defines the offset for TRQ DAC bit */
#define DRV8889Q1_REG_CTRL1_TRQ_DAC_OFS     (4)

/*! @brief Defines the offset for slew rate selection bit */
#define DRV8889Q1_REG_CTRL1_SLEW_RATE_OFS   (0)

/*! @brief Defines the mask for TRQ DAC bit */
#define DRV8889Q1_REG_CTRL1_TRQ_DAC_MASK    \
                                        (15<<DRV8889Q1_REG_CTRL1_TRQ_DAC_OFS)

/*! @brief Defines the mask for slew rate selection bit */                                        
#define DRV8889Q1_REG_CTRL1_SLEW_RATE_MASK  \
                                        (3<<DRV8889Q1_REG_CTRL1_SLEW_RATE_OFS)


/*! @brief Defines the offset output disable bit */
#define DRV8889Q1_REG_CTRL2_DIS_OUT_OFS     (7)

/*! @brief Defines the offset TOFF selection bit */
#define DRV8889Q1_REG_CTRL2_TOFF_OFS        (3)

/*! @brief Defines the offset for decay selection bit */
#define DRV8889Q1_REG_CTRL2_DECAY_OFS       (0)

/*! @brief Defines the mask output disable bit */
#define DRV8889Q1_REG_CTRL2_DIS_OUT_MASK    (1<<DRV8889Q1_REG_CTRL2_DIS_OUT_OFS)

/*! @brief Defines the mask TOFF selection bit */
#define DRV8889Q1_REG_CTRL2_TOFF_MASK       (3<<DRV8889Q1_REG_CTRL2_TOFF_OFS)

/*! @brief Defines the mask for decay selection bit */
#define DRV8889Q1_REG_CTRL2_DECAY_MASK      (7<<DRV8889Q1_REG_CTRL2_DECAY_OFS)


/*! @brief Defines the offset for direction input bit */
#define DRV8889Q1_REG_CTRL3_DIR_OFS               (7)

/*! @brief Defines the offset for step input bit */
#define DRV8889Q1_REG_CTRL3_STEP_OFS              (6)

/*! @brief Defines the offset for direction input selection bit */
#define DRV8889Q1_REG_CTRL3_SPI_DIR_OFS           (5)

/*! @brief Defines the offset for step input selection bit */
#define DRV8889Q1_REG_CTRL3_SPI_STEP_OFS          (4)

/*! @brief Defines the offset for microstep mode selection bit */
#define DRV8889Q1_REG_CTRL3_MICROSTEP_MODE_OFS    (0)

/*! @brief Defines the mask for direction input bit */
#define DRV8889Q1_REG_CTRL3_DIR_MASK       (1<<DRV8889Q1_REG_CTRL3_DIR_OFS)

/*! @brief Defines the mask for step input bit */
#define DRV8889Q1_REG_CTRL3_STEP_MAS       (1<<DRV8889Q1_REG_CTRL3_STEP_OFS)

/*! @brief Defines the mask for direction input selection bit */
#define DRV8889Q1_REG_CTRL3_SPI_DIR_MASK   (1<<DRV8889Q1_REG_CTRL3_SPI_DIR_OFS)

/*! @brief Defines the mask for step input selection bit */
#define DRV8889Q1_REG_CTRL3_SPI_STEP_MASK  (1<<DRV8889Q1_REG_CTRL3_SPI_STEP_OFS)

/*! @brief Defines the mask for microstep mode selection bit */
#define DRV8889Q1_REG_CTRL3_MICROSTEP_MODE_MASK   \
                                    (15<<DRV8889Q1_REG_CTRL3_MICROSTEP_MODE_OFS)

/*! @brief Defines the offset for clear fault bit */
#define DRV8889Q1_REG_CTRL4_CLR_FLT_OFS    (7)

/*! @brief Defines the offset for lock settings bit */
#define DRV8889Q1_REG_CTRL4_LOCK_OFS       (4)

/*! @brief Defines the offset for enable open load bit */
#define DRV8889Q1_REG_CTRL4_EN_OL_OFS      (3)

/*! @brief Defines the offset for overcurrent mode selection bit */
#define DRV8889Q1_REG_CTRL4_OCP_MODE_OFS   (2)

/*! @brief Defines the offset for overtemperature mode selection bit */
#define DRV8889Q1_REG_CTRL4_OTSD_MODE_OFS  (1)

/*! @brief Defines the offset for over or under temperature reporting selection 
bit */
#define DRV8889Q1_REG_CTRL4_TW_REP_OFS    (0)

/*! @brief Defines the mask for clear fault bit */
#define DRV8889Q1_REG_CTRL4_CLR_FLT_MASK   (1<<DRV8889Q1_REG_CTRL4_CLR_FLT_OFS)

/*! @brief Defines the mask for lock settings bit */
#define DRV8889Q1_REG_CTRL4_LOCK_MASK      (7<<DRV8889Q1_REG_CTRL4_LOCK_OFS)

/*! @brief Defines the mask for enable open load bit */
#define DRV8889Q1_REG_CTRL4_EN_OL_MASK     (1<<DRV8889Q1_REG_CTRL4_EN_OL_OFS)

/*! @brief Defines the mask for overcurrent mode selection bit */
#define DRV8889Q1_REG_CTRL4_OCP_MODE_MASK  (1<<DRV8889Q1_REG_CTRL4_OCP_MODE_OFS)

/*! @brief Defines the mask for overtemperature mode selection bit */
#define DRV8889Q1_REG_CTRL4_OTSD_MODE_MASK \
                                        (1<<DRV8889Q1_REG_CTRL4_OTSD_MODE_OFS)

/*! @brief Defines the mask for over or under temperature reporting selection 
bit */
#define DRV8889Q1_REG_CTRL4_TW_REP_MASK   (1<<DRV8889Q1_REG_CTRL4_TW_REP_OFS)


/*! @brief Defines the offset for stall learn bit */
#define DRV8889Q1_REG_CTRL5_STL_LRN_OFS     (5)

/*! @brief Defines the offset for enable stall detection bit */
#define DRV8889Q1_REG_CTRL5_EN_STL_OFS      (4)

/*! @brief Defines the offset for stall detection reporting selection bit */
#define DRV8889Q1_REG_CTRL5_STL_REP_OFS     (3)

/*! @brief Defines the mask for stall learn bit */
#define DRV8889Q1_REG_CTRL5_STL_LRN_MASK    (1<<DRV8889Q1_REG_CTRL5_STL_LRN_OFS)

/*! @brief Defines the mask for enable stall detection bit */
#define DRV8889Q1_REG_CTRL5_EN_STL_MASK     (1<<DRV8889Q1_REG_CTRL5_EN_STL_OFS)

/*! @brief Defines the mask for stall detection reporting selection bit */
#define DRV8889Q1_REG_CTRL5_STL_REP_MASK    (1<<DRV8889Q1_REG_CTRL5_STL_REP_OFS)


/*! @brief Defines the offset for stall threshold bit */
#define DRV8889Q1_REG_CTRL6_STALL_TH_OFS    (0)

/*! @brief Defines the mask for stall threshold bit */
#define DRV8889Q1_REG_CTRL6_STALL_TH_MASK   \
                                        (0xFF<<DRV8889Q1_REG_CTRL6_STALL_TH_OFS)


/*! @brief Defines the offset for TRQ COUNT bit */
#define DRV8889Q1_REG_CTRL7_TRQ_COUNT_OFS   (0)

/*! @brief Defines the mask for TRQ COUNT bit */
#define DRV8889Q1_REG_CTRL7_TRQ_COUNT_MASK  \
                                    (0xFF<<DRV8889Q1_REG_CTRL7_TRQ_COUNT_OFS)


/*! @brief Defines the offset for silicon revision identification bit */
#define DRV8889Q1_REG_CTRL8_REV_ID_OFS      (0)

/*! @brief Defines the mask for silicon revision identification bit */
#define DRV8889Q1_REG_CTRL8_REV_ID_MASK     \
                                            (15<<DRV8889Q1_REG_CTRL8_REV_ID_OFS)


/*! @brief Defines the offset for SPI command bit */
#define DRV8889Q1_SPI_CMD_OFS               (14)

/*! @brief Defines the offset for SPI register address */
#define DRV8889Q1_SPI_ADDR_OFS              (9)

/*! @brief Defines the offset for SPI register address */
#define DRV8889Q1_SPI_ADDR_MASK             (0xFF<<DRV8889Q1_SPI_ADDR_OFS)


/*! @brief Number of Electrical cycles for stall auto learning */
#define DRV8889Q1_STALL_LEARN_EL_CYCLES     (16)

/*! @enum DRV8889Q1_REG_ADDR */
typedef enum {
    /* Address of fault status register */
    DRV8889Q1_REG_ADDR_FAULT_STATUS = 0,
    /* Address of diag status 1 register */
    DRV8889Q1_REG_ADDR_DIAG_STATUS_1,
    /* Address of diag status 2 register */
    DRV8889Q1_REG_ADDR_DIAG_STATUS_2,
    /* Address of ctrl1 register */
    DRV8889Q1_REG_ADDR_CTRL1,
    /* Address of ctrl2 register */
    DRV8889Q1_REG_ADDR_CTRL2,
    /* Address of ctrl3 register */
    DRV8889Q1_REG_ADDR_CTRL3,
    /* Address of ctrl4 register */
    DRV8889Q1_REG_ADDR_CTRL4,
    /* Address of ctrl5 register */
    DRV8889Q1_REG_ADDR_CTRL5,
    /* Address of ctrl6 register */
    DRV8889Q1_REG_ADDR_CTRL6,
    /* Address of ctrl7 register */
    DRV8889Q1_REG_ADDR_CTRL7,
    /* Address of ctrl8 register */
    DRV8889Q1_REG_ADDR_CTRL8,
    /* Address of ctrl9 register */
    DRV8889Q1_REG_ADDR_CTRL9,
}DRV8889Q1_REG_ADDR;

/*! @enum DRV8889Q1_SPI_CMD */
typedef enum {
    /* SPI write command */
    DRV8889Q1_SPI_CMD_WRITE = 0,
    /* SPI read command */
    DRV8889Q1_SPI_CMD_READ,
}DRV8889Q1_SPI_CMD;

/*! @enum DRV8889Q1_REG_CTRL4_LOCK */
typedef enum {
    /*! Unlock value */
    DRV8889Q1_REG_CTRL4_LOCK_UNLOCK = 3,
    /*! Lock value */
    DRV8889Q1_REG_CTRL4_LOCK_LOCK = 6
}DRV8889Q1_REG_CTRL4_LOCK;

/*! @enum DRV8889Q1_DIR */
typedef enum
{
    /*! Reverse direction */
    DRV8889Q1_DIR_REVERSE = 0,
    /*! Forward direction */
    DRV8889Q1_DIR_FORWARD ,
}DRV8889Q1_DIR;

/*! @enum DRV8889Q1_STEP */
typedef enum
{
    /*! Full step mode 100% current */
    DRV8889Q1_STEP_FULL_STEP = 0,
    /*! Full step mode 71% current*/
    DRV8889Q1_STEP_FULL_STEP_71,
    /*! Half step mode non circular */
    DRV8889Q1_STEP_NC_HALF_STEP,
    /*! half step mode circular*/
    DRV8889Q1_STEP_HALF_STEP,
    /*! 1 by 4 step mode */
    DRV8889Q1_STEP_1BY4_STEP,
    /*! 1 by 8 step mode */
    DRV8889Q1_STEP_1BY8_STEP,
    /*! 1 by 16 step mode */
    DRV8889Q1_STEP_1BY16_STEP,
    /*! 1 by 32 step mode */
    DRV8889Q1_STEP_1BY32_STEP,
    /*! 1 by 64 step mode */
    DRV8889Q1_STEP_1BY64_STEP,
    /*! 1 by 128 step mode */
    DRV8889Q1_STEP_1BY128_STEP,
    /*! 1 by 256 step mode */
    DRV8889Q1_STEP_1BY256_STEP,
}DRV8889Q1_STEP;

/*! @enum DRV8889Q1_SLEW_RATE */
typedef enum
{
    /*! Set 10V/us slew rate*/ 
    DRV8889Q1_SLEW_RATE_10VUS = 0,
    /*! Set 35V/us slew rate*/ 
    DRV8889Q1_SLEW_RATE_35VUS,
    /*! Set 50V/us slew rate*/ 
    DRV8889Q1_SLEW_RATE_50VUS,
    /*! Set 105V/us slew rate*/ 
    DRV8889Q1_SLEW_RATE_105VUS,
}DRV8889Q1_SLEW_RATE;

/*! @enum DRV8889Q1_DECAY */
typedef enum
{
    /*! Set Slow decay in increasing steps and slow decay in decreasing steps */ 
    DRV8889Q1_DECAY_INC_SLOW_DEC_SLOW = 0,
    /*! Set Slow decay in increasing steps and mixed 30% fast decay 
    in decreasing steps */ 
    DRV8889Q1_DECAY_INC_SLOW_DEC_MIXED_30,
    /*! Set Slow decay in increasing steps and mixed 60% fast decay 
    in decreasing steps */ 
    DRV8889Q1_DECAY_INC_SLOW_DEC_MIXED_60,
    /*! Set Slow decay in increasing steps and fast decay in decreasing steps */ 
    DRV8889Q1_DECAY_INC_SLOW_DEC_FAST,
    /*! Set mixed 30% fast decay in increasing steps and mixed 60% fast decay 
    in decreasing steps */ 
    DRV8889Q1_DECAY_INC_MIXED_30_DEC_MIXED_30,
    /*! Set mixed 60% fast decay in increasing steps and mixed 60% fast decay 
    in decreasing steps */ 
    DRV8889Q1_DECAY_INC_MIXED_60_DEC_MIXED_60,
    /*! Set smart tune dynamic decay */ 
    DRV8889Q1_DECAY_SMART_TUNE_DYNAMIC,
    /*! Set smart tune ripple control decay */ 
    DRV8889Q1_DECAY_SMART_TUNE_RIPPLE_CTRL
}DRV8889Q1_DECAY;

/*! @enum DRV8889Q1_TRQ_DAC */
typedef enum
{
    /*! 100% Full scale current */ 
    DRV8889Q1_TRQ_DAC_100 = 0,
    /*! 93.75% Full scale current */ 
    DRV8889Q1_TRQ_DAC_93P75,
    /*! 87.5% Full scale current */ 
    DRV8889Q1_TRQ_DAC_87P5,
    /*! 81.25% Full scale current */ 
    DRV8889Q1_TRQ_DAC_81P25,
    /*! 75% Full scale current */ 
    DRV8889Q1_TRQ_DAC_75,
    /*! 68.75% Full scale current */ 
    DRV8889Q1_TRQ_DAC_68P75,
    /*! 62.5% Full scale current */ 
    DRV8889Q1_TRQ_DAC_62P5,
    /*! 56.25% Full scale current */ 
    DRV8889Q1_TRQ_DAC_56P25,
    /*! 50% Full scale current */ 
    DRV8889Q1_TRQ_DAC_50,
    /*! 43.75% Full scale current */ 
    DRV8889Q1_TRQ_DAC_43P75,
    /*! 37.5% Full scale current */ 
    DRV8889Q1_TRQ_DAC_37P5,
    /*! 31.25% Full scale current */ 
    DRV8889Q1_TRQ_DAC_31P25,
    /*! 25% Full scale current */ 
    DRV8889Q1_TRQ_DAC_25,
    /*! 18.75% Full scale current */ 
    DRV8889Q1_TRQ_DAC_18P75,
    /*! 12.5% Full scale current */ 
    DRV8889Q1_TRQ_DAC_12P5,
    /*! 6.25% Full scale current */ 
    DRV8889Q1_TRQ_DAC_6P25,
}DRV8889Q1_TRQ_DAC;

/*! @enum DRV8889Q1_TOFF */
typedef enum
{
    /*! TOFF value 7us */
    DRV8889Q1_TOFF_7US = 0,
    /*! TOFF value 16us */
    DRV8889Q1_TOFF_16US,
    /*! TOFF value 24us */
    DRV8889Q1_TOFF_24US,
    /*! TOFF value 32us */
    DRV8889Q1_TOFF_32US,
}DRV8889Q1_TOFF;

/*! @enum DRV8889Q1_CONTROL_MODE */
typedef enum
{
    /*! Spin mode */
    DRV8889Q1_CONTROL_MODE_SPIN = 0,
    /*! Step mode */
    DRV8889Q1_CONTROL_MODE_STEP,
}DRV8889Q1_CONTROL_MODE;

/*! @enum DRV8889Q1_DRIVE */
typedef enum
{
    /*! Disabled mode */
    DRV8889Q1_DRIVE_DISABLED = 0,
    /*! PWM mode */
    DRV8889Q1_DRIVE_PWM
}DRV8889Q1_DRIVE;

/*! @brief Define drv8889-q1 structure */
typedef struct {
    /*!  Stores the selected step mode. @ref DRV8889Q1_STEP */
    DRV8889Q1_STEP stepMode;
    /*!  Stores the selected decay mode. @ref DRV8889Q1_DECAY */
    DRV8889Q1_DECAY decayMode;
    /*!  Stores the selected control mode. @ref DRV8889Q1_CONTROL_MODE */
    DRV8889Q1_CONTROL_MODE controlMode;
    /*!  Stores the selected drive state. @ref DRV8889Q1_DRIVE */
    DRV8889Q1_DRIVE driveState;
    /*!  Stores the steps to move */
    uint32_t setStep;
    /*!  Stores the step count */
    uint32_t stepCount;
    /*! Stores the indexer timer frequency */
    uint16_t setFreq;
    /*!  GPIO pin set for dir. @ref HAL_GPIO_OUT_PIN */
    HAL_GPIO_OUT_PIN dir;
    /*!  GPIO pin set for drvOff. @ref HAL_GPIO_OUT_PIN */
    HAL_GPIO_OUT_PIN drvOff;
    /*!  GPIO pin set for nsleep. @ref HAL_GPIO_OUT_PIN */
    HAL_GPIO_OUT_PIN nsleep;
    /*!  GPIO pin set for nfault. @ref HAL_GPIO_IN_PIN */
    HAL_GPIO_IN_PIN nfault;
    /*!  DAC channel set for vref. @ref HAL_DAC_CHANNEL */
    HAL_DAC_CHANNEL vref;
    /*!  PWM channel set for step. @ref HAL_PWM_CHANNEL */
    HAL_PWM_CHANNEL step;
    /*!  SPI channel. @ref HAL_SPI_CHANNEL */
    HAL_SPI_CHANNEL spi;
    /*! SPI chip select. @ref HAL_SPI_CS */
    HAL_SPI_CS spiCS;
} DRV8889Q1_Instance;

/**
 * @brief     Enables the necessary interrupts
 * @param[in] handle    A pointer to drv8889-q1 instance
 */
void DRV8889Q1_init(DRV8889Q1_Instance *handle);

/**
 * @brief     Creates a data word to be send through SPI
 * @param[in] wrCmd    SPI read or write command. One of @ref DRV8889Q1_SPI_CMD
 * @param[in] addr     A SPI register address. One of @ref DRV8889Q1_REG_ADDR
 * @param[in] data     Data to be written to the SPI register.
 * @return    Return created SPI word
 */
uint16_t DRV8889Q1_createSPIDataWord(
                DRV8889Q1_SPI_CMD wrCmd, DRV8889Q1_REG_ADDR addr, uint8_t data);

/**
 * @brief     Writes the data to the SPI register
 * @param[in] handle   A pointer to drv8889q1 instance
 * @param[in] addr     A SPI register address. One of @ref DRV8889Q1_REG_ADDR
 * @param[in] data     Data to be written to the SPI register.
 */
void DRV8889Q1_spiWrite(
            DRV8889Q1_Instance *handle, DRV8889Q1_REG_ADDR addr, uint8_t data);

/**
 * @brief     Reads the data in the SPI register
 * @param[in] handle   A pointer to drv8889q1 instance
 * @param[in] addr     A SPI register address. One of @ref DRV8889Q1_REG_ADDR
 * @return    Returns the data in spi register
 */
uint8_t DRV8889Q1_spiRead(DRV8889Q1_Instance *handle, DRV8889Q1_REG_ADDR addr);

/**
 * @brief     Update only some bits in the SPI register
 * @param[in] handle   A pointer to drv8889q1 instance
 * @param[in] addr     A SPI register address. One of @ref DRV8889Q1_REG_ADDR
 * @param[in] mask     Mask for the bits to change
 * @param[in] data     Data to be written to the SPI register
 */
void DRV8889Q1_spiUpdateRegister(DRV8889Q1_Instance *handle, 
                        DRV8889Q1_REG_ADDR addr, uint32_t mask, uint8_t data);
                        
/**
 * @brief     Unlock or lock settings of the DRV
 * @param[in] handle  A pointer to drv8889q1 instance
 * @param[in] lock    Lock or Unlock value. One of @ref DRV8889Q1_REG_CTRL4_LOCK
 */
void DRV8889Q1_setSPIRegisterLock(
                    DRV8889Q1_Instance *handle, DRV8889Q1_REG_CTRL4_LOCK lock);

/**
 * @brief     Sets the direction of motor
 * @param[in] handle  A pointer to drv8889q1 instance
 * @param[in] dir     New direction to be set. One of @ref DRV8889Q1_DIR
 */
void DRV8889Q1_setDirection(DRV8889Q1_Instance *handle, DRV8889Q1_DIR dir);

/**
 * @brief     Sets the step mode
 * @param[in] handle   A pointer to drv8889q1 instance
 * @param[in] stepMode Step mode to be set.
 *                     One of @ref DRV8889Q1_STEP
 */
void DRV8889Q1_setStepMode(DRV8889Q1_Instance *handle, DRV8889Q1_STEP stepMode);

/**
 * @brief     Sets the decay mode
 * @param[in] handle    A pointer to drv8889q1 instance
 * @param[in] decayMode Decay mode to be set. One of @ref DRV8889Q1_DECAY
 */
void DRV8889Q1_setDecayMode(
                        DRV8889Q1_Instance *handle, DRV8889Q1_DECAY decayMode);

/**
 * @brief     Sets the motor speed by setting the timer frequency
 * @param[in] handle    A pointer to drv8889q1 instance
 * @param[in] timFreq   Timer frequency to be set
 */
void DRV8889Q1_setSpeed(DRV8889Q1_Instance *handle, uint32_t timFreq);

/**
 * @brief     Sets full scale current
 * @param[in] handle    A pointer to drv8889q1 instance
 * @param[in] fsCurr    Full scale current value to be set in IQ
 */
void DRV8889Q1_setFSCurr(DRV8889Q1_Instance *handle, _iq15 fsCurr);

/**
 * @brief     Sets Slew rate
 * @param[in] handle    A pointer to drv8889q1 instance
 * @param[in] slewRate  New slew rate to be set. One of @ref DRV8889Q1_SLEW_RATE
 */
void DRV8889Q1_setSlewRate(
                    DRV8889Q1_Instance *handle, DRV8889Q1_SLEW_RATE slewRate);

/**
 * @brief     Sets DRV to awake
 * @param[in] handle    A pointer to drv8889q1 instance
 */
void DRV8889Q1_setNSleep(DRV8889Q1_Instance *handle);

/**
 * @brief     Sets DRV to sleep
 * @param[in] handle    A pointer to drv8889q1 instance
 */
void DRV8889Q1_clearNSleep(DRV8889Q1_Instance *handle);

/**
 * @brief     Enables the drv driver output
 * @param[in] handle    A pointer to drv8889q1 instance
 */
void DRV8889Q1_enableOutput(DRV8889Q1_Instance *handle);

/**
 * @brief     Disables the drv driver output
 * @param[in] handle    A pointer to drv8889q1 instance
 */
void DRV8889Q1_disableOutput(DRV8889Q1_Instance *handle);

/**
 * @brief     Starts the motor
 * @param[in] handle    A pointer to drv8889q1 instance
 */
void DRV8889Q1_startMotor(DRV8889Q1_Instance *handle);

/**
 * @brief     Stops the motor
 * @param[in] handle    A pointer to drv8889q1 instance
 */
void DRV8889Q1_stopMotor(DRV8889Q1_Instance *handle);

/**
 * @brief     Checks if the motor is currently running 
 * @param[in] handle    A pointer to drv8889q1 instance
 * @return    Returns the running status of motor
 * 
 * @retval    true  Motor is currently running
 * @retval    false Motor is not currently running
 */
bool DRV8889Q1_isMotorRunning(DRV8889Q1_Instance *handle);

/**
 * @brief     Gets if any fault occurred at the instant 
 * @param[in] handle    A pointer to drv8889q1 instance
 * @return    Returns if fault occurred 
 * 
 * @retval    true  Fault currently present
 * @retval    false No fault is currently present
 */
bool DRV8889Q1_isFaultOccurred(DRV8889Q1_Instance *handle);


/**
 * @brief     Sets the control mode
 * @param[in] handle     A pointer to drv8889q1 instance
 * @param[in] ctrl_mode  Control mode to be set.
 *                       One of @ref DRV8889Q1_CONTROL_MODE
 */
void DRV8889Q1_setControlMode(
                DRV8889Q1_Instance *handle, DRV8889Q1_CONTROL_MODE ctrl_mode);

/**
 * @brief     Checks if motor has moved the required steps in step mode
 * @param[in] handle    A pointer to drv8889q1 instance
 */
void DRV8889Q1_checkStep(DRV8889Q1_Instance *handle);

/**
 * @brief     Sets the step duty cycle specified in DRV8889Q1_STEP_DUTYCYCLE
 * @param[in] handle    A pointer to drv8889q1 instance
 */
void DRV8889Q1_setStepDuty(DRV8889Q1_Instance *handle);

/**
 * @brief     Sets the step drive state
 * @param[in] handle    A pointer to drv8889q1 instance
 * @param[in] drive         New drive state to be set.
 *                          One of @ref DRV8889Q1_DRIVE
 */
void DRV8889Q1_setStepDrive(DRV8889Q1_Instance *handle, DRV8889Q1_DRIVE drive);

/**
 * @brief     Sets the steps to move in step mode
 * @param[in] handle    A pointer to drv8889q1 instance
 * @param[in] setSteps  Steps to move in step mode
 */
void DRV8889Q1_setStep(DRV8889Q1_Instance *handle, uint16_t setSteps);

/**
 * @brief     Sets TRQ DAC value. Used to scale the full scale current
 * @param[in] handle    A pointer to drv8889q1 instance
 * @param[in] trqDac    New TRQ DAC value to be set.
 *                      One of @ref DRV8889Q1_TRQ_DAC
 */
void DRV8889Q1_setTrqDac(DRV8889Q1_Instance *handle, DRV8889Q1_TRQ_DAC trqDac);

/**
 * @brief     Sets toff value.
 * @param[in] handle    A pointer to drv8889q1 instance
 * @param[in] toff    New toff value to be set.
 *                      One of @ref DRV8889Q1_TOFF
 */
void DRV8889Q1_setToff(DRV8889Q1_Instance *handle, DRV8889Q1_TOFF toff);

/**
 * @brief     Clears the SPI fault status registers
 * @param[in] handle    A pointer to drv8889q1 instance
 */
void DRV8889Q1_clearFaults(DRV8889Q1_Instance *handle);

/**
 * @brief     Gets the stall threshold value from spi register
 * @param[in] handle    A pointer to drv8889q1 instance
 * @return    Returns the stall threshold
 */
uint8_t DRV8889Q1_getStallThres(DRV8889Q1_Instance *handle);

/**
 * @brief     Set the stall threshold value in spi register
 * @param[in] handle       A pointer to drv8889q1 instance
 * @param[in] stallThres   new stall threshold to be set
 */
void DRV8889Q1_setStallThres(DRV8889Q1_Instance *handle, uint8_t stallThres);

/**
 * @brief     Gets the trq count
 * @param[in] handle    A pointer to drv8889q1 instance
 * @return    Returns the trq couht
 */
uint8_t DRV8889Q1_getTrqCount(DRV8889Q1_Instance *handle);

/**
 * @brief     Enables the stall detection
 * @param[in] handle    A pointer to drv8889q1 instance
 */
void DRV8889Q1_enableStallDet(DRV8889Q1_Instance *handle);

/**
 * @brief     Disables the stall detection
 * @param[in] handle    A pointer to drv8889q1 instance
 */
void DRV8889Q1_disableStallDet(DRV8889Q1_Instance *handle);

/**
 * @brief     Enables the open load detection
 * @param[in] handle    A pointer to drv8889q1 instance
 */
void DRV8889Q1_enableOlDet(DRV8889Q1_Instance *handle);

/**
 * @brief     Disables the open load detection
 * @param[in] handle    A pointer to drv8889q1 instance
 */
void DRV8889Q1_disableOlDet(DRV8889Q1_Instance *handle);

/**
 * @brief     Starts auto stall learning
 * @param[in] handle    A pointer to drv8889q1 instance
 */
void DRV8889Q1_setLearnStall(DRV8889Q1_Instance *handle);

/**
 * @brief     Checks if auto stall learning is completed successfully
 * @param[in] handle    A pointer to drv8889q1 instance
 * @return    Returns if stall learning is completed successfully
 * 
 * @retval    true  Stall learning is not complete
 * @retval    false Stall learning is completed successfully
 */
bool DRV8889Q1_isStallLearnSuccess(DRV8889Q1_Instance *handle);

/**
 * @brief     Sets the reference voltage for the vref output
 * @param[in] handle     A pointer to drv8889q1 instance
 * @param[in] refVoltage Reference voltage to be set in IQ
 */
void DRV8889Q1_setVrefRefVoltage(DRV8889Q1_Instance *handle, _iq15 refVoltage);

#ifdef __cplusplus
}
#endif
#endif /* DRV8889Q1_H */
/** @}*/