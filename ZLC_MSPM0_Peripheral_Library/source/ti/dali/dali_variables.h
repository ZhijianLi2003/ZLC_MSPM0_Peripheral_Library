/*
 * Copyright (c) 2021, Texas Instruments Incorporated
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
 *  @file       dali_variables.h
 *  @brief      DALI Control Gear Variable Definition
 *  @defgroup   DALI Library (DALI)
 *
 *  @anchor ti_dali_variables_overview
 *  # Overview
 *
 *  The DALI Control Gear Variable Definition
 *
 *  <hr>
 ******************************************************************************/


#ifndef DALI_VARIABLES_H_
#define DALI_VARIABLES_H_
#include <stdint.h>
#include <stdbool.h>


/*  ENUM Definitions              */

/*! @enum DALI_stateType */
typedef enum {
    /*! Device is in initialization*/
    ENABLED,
    /*! Device is not in initialization*/
    DISABLED,
    /*! Device has been initialized*/
    WITHDRAWN,

} DALI_stateType;

/*! @enum DALI_phaseType */
typedef enum {
    /*! Device is in standby phase */
    STANDBY,
    /*! Device is in startup phase*/
    STARTUP,
    /*! Device is in normal operation*/
    NORMAL,
    /*! Device is in failure state*/
    FAILURE,

} DALI_phaseType;

/*  Control Gear Default Definitions              */

/*! Default Level for Power On */
#define POWER_ON_LEVEL_DEFAULT                       (uint8_t)(0xFE)
/*! Default Level for Last Light Level */
#define LAST_LIGHT_LEVEL_DEFAULT                     (uint8_t)(0xFE)
/*! Default Level for System Failure */
#define SYSTEM_FAILURE_LEVEL_DEFAULT                 (uint8_t)(0xFE)
/*! Default Level for Max Level */
#define MAX_LEVEL_DEFAULT                            (uint8_t)(0xFE)
/*! Default Level for Min Level */
#define FADE_RATE_DEFAULT                            (uint8_t)(0x07)
/*! Default Fade Time */
#define FADE_TIME_DEFAULT                            (uint8_t)(0x01)
/*! Default Extended Fade Time Base */
#define EXTENDED_FADE_TIME_BASE_DEFAULT              (uint8_t)(0x00)
/*! Default Extended Fade Time Multiplier */
#define EXTENDED_FADE_TIME_MULTIPLIER_DEFAULT        (uint8_t)(0x00)
/*! Default Short Address */
#define SHORT_ADDRESS_DEFAULT                        (uint8_t)(0xFF)
/*! Default Random Address */
#define RANDOM_ADDRESS_DEFAULT                       (uint32_t)(0x00FFFFFF)
/*! Default Reset State*/
#define RESET_STATE_DEFAULT                          true
/*! Default Group Assignment*/
#define GROUP_DEFAULT                               (uint16_t)(0x0000)
/*! Default Physical Minimum Level*/
#define PHYS_MIN_LEVEL                               (uint8_t)(0x01)
/*! Default Minimum Level*/
#define MIN_LEVEL_DEFAULT                            PHYS_MIN_LEVEL
/*! Default Mask value*/
#define MASK                                         (uint8_t)(0xFF)
/*! Default Scene 0 Level*/
#define SCENE_0_DEFAULT                              MASK
/*! Default Scene 1 Level*/
#define SCENE_1_DEFAULT                              MASK
/*! Default Scene 2 Level*/
#define SCENE_2_DEFAULT                              MASK
/*! Default Scene 3 Level*/
#define SCENE_3_DEFAULT                              MASK
/*! Default Scene 4 Level*/
#define SCENE_4_DEFAULT                              MASK
/*! Default Scene 5 Level*/
#define SCENE_5_DEFAULT                              MASK
/*! Default Scene 6 Level*/
#define SCENE_6_DEFAULT                              MASK
/*! Default Scene 7 Level*/
#define SCENE_7_DEFAULT                              MASK
/*! Default Scene 8 Level*/
#define SCENE_8_DEFAULT                              MASK
/*! Default Scene 9 Level*/
#define SCENE_9_DEFAULT                              MASK
/*! Default Scene 10 Level*/
#define SCENE_10_DEFAULT                             MASK
/*! Default Scene 11 Level*/
#define SCENE_11_DEFAULT                             MASK
/*! Default Scene 12 Level*/
#define SCENE_12_DEFAULT                             MASK
/*! Default Scene 13 Level*/
#define SCENE_13_DEFAULT                             MASK
/*! Default Scene 14 Level*/
#define SCENE_14_DEFAULT                             MASK
/*! Default Scene 15 Level*/
#define SCENE_15_DEFAULT                             MASK
/*! Default Version Number*/
#define VERSION_NUMBER                               (uint8_t)(0x03)

/* LED Control Gear Default Definitions */

/*! Default Mininum Fast Fade Time */
#define MIN_FAST_FADE_TIME_DEFAULT                   (uint8_t)(0x01)
/*! Default Fast Fade Time */
#define FAST_FADE_TIME_DEFAULT                       (uint8_t)(0x00)
/*! Default Features */
#define FEATURES_DEFAULT                             (uint8_t)(0x00)
/*! Default Control Gear Type */
#define CONTROL_GEAR_TYPE_DEFAULT                    (uint8_t)(0x00)
/*! Default Extended Version Number */
#define EXTENDED_VERSION_NUMBER_DEFAULT              (uint8_t)(0x02)
/*! Default Device Type */
#define DEVICE_TYPE_DEFAULT                          (uint8_t)(0x06)
/*! Default Dimming Curve */
#define DIMMING_CURVE_DEFAULT                        (uint8_t)(0x00)


/*  Reset Definitions              */

/*! Actual Level Reset Value */
#define ACTUAL_LEVEL_RESET          (uint8_t)(0xFE)
/*! Target Level Reset Value*/
#define TARGET_LEVEL_RESET          (uint8_t)(0x00)
/*! Last Active Level Reset Value*/
#define LAST_ACTIVE_LEVEL_RESET     (uint8_t)(0xFE)
/*! Last Light Level Reset Value*/
#define LAST_LIGHT_LEVEL_RESET      (uint8_t)(0xFE)
/*! Power On Reset Value*/
#define POWER_ON_LEVEL_RESET        (uint8_t)(0xFE)
/*! System Failure Level Reset Value*/
#define SYSTEM_FAILURE_LEVEL_RESET  (uint8_t)(0xFE)
/*! Min Level Reset Value*/
#define MIN_LEVEL_RESET             PHYS_MIN_LEVEL
/*! Max Level Reset Value*/
#define MAX_LEVEL_RESET             (uint8_t)(0xFE)
/*! Fade Rate Reset Value*/
#define FADE_RATE_RESET             (uint8_t)(0x07)
/*! Fade Time Reset Value*/
#define FADE_TIME_RESET             (uint8_t)(0x00)
/*! Search Address Reset Value*/
#define SEARCH_ADDRESS_RESET         (uint32_t)0x00FFFFFF
/*! Random Address Reset Value*/
#define RANDOM_ADDRESS_RESET         (uint32_t)0x00FFFFFF
/*! Group Assignment Reset Value*/
#define GROUP_RESET                 (uint16_t)(0x0000)
/*! Scenes[0-15] Reset Value*/
#define SCENE_0_F_RESET             MASK
/*! Limit Error Reset Value*/
#define LIMIT_ERROR_RESET           false
/*! Fade Running Reset Value*/
#define FADE_RUNNING_RESET          false
/*! Reset State Reset Value*/
#define RESET_STATE_RESET           true
/*! Power Cycle Seen Reset Value*/
#define POWER_CYCLE_SEEN_RESET            false

/*  Fade Time and Rate Computation Defines   */

/*! Computation when fade time is even */
#define EVEN_BUFFER_VALUE           (uint32_t)(0x00008000)
/*! Computation when fade time is odd */
#define ODD_BUFFER_VALUE           (uint32_t)(0x0000B505)
/*! Linear Fade Slope value*/
#define LINEAR_FADE_SLOPE           (float)(0.394)
/*! Linear Fade Offset value*/
#define LINEAR_FADE_OFFSET           (float)(0.094)


/* Memory Bank Address Definitions */

/*! Memory Bank 0 Start Address*/
#define MEM_BANK_0_START_ADDRESS                     (uint8_t)(0x00)
/*! Size of Memory Bank 0*/
#define MEM_BANK_SIZE                                (uint8_t)(0xFF)

/*!
 * @brief variable to store LED control gear information
*/
typedef struct {
    /*! Indicate LED Device is enabled
     *  Required to execute LED specific commands */
    bool enableLEDDevice;
    /*! Indicates shortest fade time for selected dimming curve */
    uint8_t minFastFadeTime;
    /*! Mapped to extendedFadeTime */
    uint8_t fastFadeTime;
    /*! Indicates if load detection and thermal protections are implemented
     *  0 for this implementation, can be modified */
    uint8_t features;
    /*! Indicates failure status of features */
    uint8_t failureStatus;
    /*! Indicates if LED module is integrated into control gear */
    uint8_t controlGearType;
    /*! Hardcoded to 6 for LED*/
    uint8_t deviceType;
    /*! Indicates whether linear or logarithmic dimming curve is used*/
    bool dimmingCurve;
} dali_ledControlGearVar;

/*!
 * @brief variable to store all control gear information
*/
typedef struct {

    /*! Stores the actual level of the light source */
    uint8_t actualLevel;
    /*! Stores the target level of the light source */
    uint8_t targetLevel;
    /*! Stores the last active level of the light source */
    uint8_t lastActiveLevel;
    /*! Stores the last light level of the light source */
    uint8_t lastLightLevel;
    /*! Stores the power on level of the light source */
    uint8_t powerOnLevel;
    /*! Stores the system failure level of the light source */
    uint8_t systemFailureLevel;
    /*! Stores the minimum level of the light source */
    uint8_t minLevel;
    /*! Stores the maximum level of the light source */
    uint8_t maxLevel;
    /*! Stores the fade rate of the light source */
    uint8_t fadeRate;
    /*! Stores the fade time of the light source */
    uint8_t fadeTime;
    /*! Stores the extended fade time base of the light source */
    uint8_t extendedFadeTimeBase;
    /*! Stores the extended fade time multiplier of the light source */
    uint8_t extendedFadeTimeMultiplier;
    /*! Stores the short address of the light source */
    uint32_t shortAddress;
    /*! Stores the search address of the light source */
    uint32_t searchAddress;
    /*! Stores the random address of the light source */
    uint32_t randomAddress;
    /*! Stores the operating mode of the light source */
    uint8_t operatingMode;
    /*! Stores the initialisation state of the light source */
    DALI_stateType initialisationState;
    /*! Stores the write enable state of the light source */
    DALI_stateType writeEnableState;
    /*! Stores the phase state of the light source */
    DALI_phaseType phaseState;
    /*! Indicates if there is a control gear failure */
    bool controlGearFailure;
    /*! Indicates if there is a lamp failure */
    bool lampFailure;
    /*! Indicates if the lamp is on */
    bool lampOn;
    /*! Indicates if there is a limit error */
    bool limitError;
    /*! Indicates if a fade is running */
    bool fadeRunning;
    /*! Indicates if device is in reset */
    bool resetState;
    /*! Indicates if a powercycle was seen */
    bool powerCycleSeen;
    /*! Stores the group that the device is a member of */
    uint16_t gearGroups;
    /*! Stores the target level of 16 scenes */
    uint16_t sceneX[16];
    /*! Stores the contents of Data Transfer Register 0 */
    uint8_t dataTransferRegister0;
    /*! Stores the contents of Data Transfer Register 1 */
    uint8_t dataTransferRegister1;
    /*! Stores the contents of Data Transfer Register 2 */
    uint8_t dataTransferRegister2;
    /*! Stores the PHM of the light source */
    uint8_t PHM;
    /*! Stores the version number of the device */
    uint8_t versionNumber;
    /*! Indicates if a terminate command was sent */
    bool terminate;
    /*! Indicates if an Identify Device command was sent */
    bool identifyState;
    /*! Stores the memory bank information */
    uint8_t memoryBank0[MEM_BANK_SIZE];
    /*! Indicates whether data needs to be copied to flash */
    bool updateFlash;
    /*! Stores response from the device */
    uint8_t transmitData;
    /*! Indicates whether data can be transmitted */
    bool transmitDataFlag;
    /*! Indicates what device should be enabled*/
    uint8_t deviceType;
    /*! Stores control gear information for LED Module*/
    dali_ledControlGearVar ledControlGear;
} dali_controlGearVar;


/*! Definition of global control gear variable*/
extern volatile dali_controlGearVar gControlVar1;


#endif /* DALI_VARIABLES_H_ */
