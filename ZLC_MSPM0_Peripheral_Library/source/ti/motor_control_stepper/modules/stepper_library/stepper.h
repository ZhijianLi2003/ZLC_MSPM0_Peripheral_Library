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
 *  @file       stepper.h
 *  @brief      STEPPER_MODULE Module
 *
 *
 *  @anchor stepper_h
 *  # Overview
 *
 *  Does stuff
 *
 *  <hr>
 ******************************************************************************/
/** @defgroup STEPPER_MODULE Stepper_Library
 * @{
 */
#ifndef STEPPER_H
#define STEPPER_H

#include <stdint.h>

#include <ti/devices/msp/msp.h>

/* Include the IQmath Library */
#include <ti/iqmath/include/IQmathLib.h>

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * @brief Maximum count for the indexer
 */
#define STEPPER_INDEXER_MAX_COUNT   (1024)

/*!
 * @brief Value corresponding to 0/8 of indexer max count
 */
#define STEPPER_INDEXER_0_BY_8      (0)

/*!
 * @brief Value corresponding to 1/8 of indexer max count
 */
#define STEPPER_INDEXER_1_BY_8      (STEPPER_INDEXER_MAX_COUNT >> 3)

/*!
 * @brief Value corresponding to 2/8 of indexer max count
 */
#define STEPPER_INDEXER_2_BY_8      (2 * STEPPER_INDEXER_1_BY_8)

/*!
 * @brief Value corresponding to 3/8 of indexer max count
 */
#define STEPPER_INDEXER_3_BY_8      (3 * STEPPER_INDEXER_1_BY_8)

/*!
 * @brief Value corresponding to 4/8 of indexer max count
 */
#define STEPPER_INDEXER_4_BY_8      (4 * STEPPER_INDEXER_1_BY_8)

/*!
 * @brief Value corresponding to 5/8 of indexer max count
 */
#define STEPPER_INDEXER_5_BY_8      (5 * STEPPER_INDEXER_1_BY_8)

/*!
 * @brief Value corresponding to 6/8 of indexer max count
 */
#define STEPPER_INDEXER_6_BY_8      (6 * STEPPER_INDEXER_1_BY_8)

/*!
 * @brief Value corresponding to 7/8 of indexer max count
 */
#define STEPPER_INDEXER_7_BY_8      (7 * STEPPER_INDEXER_1_BY_8)

/*!
 * @brief Value for 2*Pi
 */
#define STEPPER_2PI                 (6.2831853071f)

/*! @enum STEPPER_STEP_INC_DEC */
typedef enum {
    /*! Increment or decrement value associated to full step */
    STEPPER_STEP_INC_DEC_FULL_STEP = 256,
    /*! Increment or decrement value associated to half step */
    STEPPER_STEP_INC_DEC_HALF_STEP = 128,
    /*! Increment or decrement value associated to 1/4 step */
    STEPPER_STEP_INC_DEC_1BY4_STEP = 64,
    /*! Increment or decrement value associated to 1/8 step */
    STEPPER_STEP_INC_DEC_1BY8_STEP = 32,
    /*! Increment or decrement value associated to 1/16 step */
    STEPPER_STEP_INC_DEC_1BY16_STEP = 16,
    /*! Increment or decrement value associated to 1/32 step */
    STEPPER_STEP_INC_DEC_1BY32_STEP = 8,
    /*! Increment or decrement value associated to 1/64 step */
    STEPPER_STEP_INC_DEC_1BY64_STEP = 4,
    /*! Increment or decrement value associated to 1/128 step */
    STEPPER_STEP_INC_DEC_1BY128_STEP = 2,
    /*! Increment or decrement value associated to 1/256 step */
    STEPPER_STEP_INC_DEC_1BY256_STEP = 1,
}STEPPER_STEP_INC_DEC;

/*! @enum STEPPER_DRIVE */
typedef enum {
    /*! Disable the Drive */
    STEPPER_DRIVE_DISABLE = 0,
    /*! Drive in decay state */
    STEPPER_DRIVE_DECAY,
    /*! Drive in forward current state */
    STEPPER_DRIVE_FORWARD,
    /*! Drive in reverse current state */
    STEPPER_DRIVE_REVERSE,
}STEPPER_DRIVE;

/*! @enum STEPPER_STEP_TYPE */
typedef enum {
    /*! Circular step mode */
    STEPPER_STEP_TYPE_CIR = 0,
    /*! Non circular step mode */
    STEPPER_STEP_TYPE_NONCIR,
}STEPPER_STEP_TYPE;

/*! @enum STEPPER_DIR */
typedef enum {
    /*! Forward direction */
    STEPPER_DIR_FORWARD = 0,
    /*! Forward direction */
    STEPPER_DIR_REVERSE,
}STEPPER_DIR;

/*! @brief Define indexer structure */
typedef struct {
    /*!  Stores the count of indexer */
    int16_t counter;
    /*!  Stores the direction. @ref STEPPER_DIR */
    STEPPER_DIR dir;
    /*!  Stores the increment or decrement value. @ref STEPPER_STEP_INC_DEC */
    STEPPER_STEP_INC_DEC indexIncDec;
    /*!  Stores the selected step type. @ref STEPPER_STEP_TYPE */
    STEPPER_STEP_TYPE stepType;
    /*!  Stores IA phase drive state. @ref STEPPER_DRIVE */
    STEPPER_DRIVE IaDrive;
    /*!  Stores IB phase drive state. @ref STEPPER_DRIVE */
    STEPPER_DRIVE IbDrive;
#ifdef __HAS_2_DAC
    /*!  Stores IA current reference */
    _iq15 IaCurrRef;
    /*!  Stores IB current reference */
    _iq15 IbCurrRef;
#endif
}INDEXER_Instance;

/**
 * @brief     Extern angleSf
 */
extern _iq18 angleSf;

/**
 * @brief     Calculates the angle scale factor
 */
void STEPPER_init(void);

/**
 * @brief     Sets the direction for the indexer
 * @param[in] handle    A pointer to indexer instance
 * @param[in] dir       New direction to be set. One of @ref STEPPER_DIR
 */
__STATIC_INLINE void STEPPER_setIndexerDir(
                                    INDEXER_Instance *handle, STEPPER_DIR dir)
{
    handle->dir = dir;
}

/**
 * @brief     Sets the direction for the indexer
 * @param[in] handle    A pointer to indexer instance
 * @param[in] incDecVal    Increment or decrement value to be set. 
 *                      One of @ref STEPPER_STEP_INC_DEC
 */
__STATIC_INLINE void STEPPER_setIndexerIncVal(
                    INDEXER_Instance *handle, STEPPER_STEP_INC_DEC incDecVal)
{
    handle->indexIncDec = incDecVal;
}

/**
 * @brief     Sets the step type
 * @param[in] handle    A pointer to indexer instance
 * @param[in] stepType  Step type value to be set. One of @ref STEPPER_STEP_TYPE
 */
__STATIC_INLINE void STEPPER_setStepType(
                        INDEXER_Instance *handle, STEPPER_STEP_TYPE stepType)
{
    handle->stepType = stepType;
}

/**
 * @brief     Sets the motor drive states
 * @param[in] handle    A pointer to indexer instance
 * @param[in] IaDrive  Drive state for IA phase. One of @ref STEPPER_DRIVE
 * @param[in] IbDrive  Drive state for IB phase. One of @ref STEPPER_DRIVE
 */
__STATIC_INLINE void STEPPER_setMotorDrives(INDEXER_Instance *handle,
                                            STEPPER_DRIVE IaDrive,
                                            STEPPER_DRIVE IbDrive)
{
    handle->IaDrive = IaDrive;
    handle->IbDrive = IbDrive;
}

/**
 * @brief     Updates phase drive state in circular mode
 * @param[in] handle    A pointer to indexer instance
 */
__STATIC_INLINE void STEPPER_cirStepPhaseGen(INDEXER_Instance *handle)
{
    int16_t counter = handle->counter;
    if(counter >= STEPPER_INDEXER_0_BY_8 && counter < STEPPER_INDEXER_2_BY_8)
    {
        STEPPER_setMotorDrives(
                        handle, STEPPER_DRIVE_FORWARD, STEPPER_DRIVE_FORWARD);
    }
    else if(counter >= STEPPER_INDEXER_2_BY_8 && counter < STEPPER_INDEXER_4_BY_8)
    {
        STEPPER_setMotorDrives(
                        handle, STEPPER_DRIVE_FORWARD, STEPPER_DRIVE_REVERSE);
    }
    else if(counter >= STEPPER_INDEXER_4_BY_8 && counter < STEPPER_INDEXER_6_BY_8)
    {
        STEPPER_setMotorDrives(
                        handle, STEPPER_DRIVE_REVERSE, STEPPER_DRIVE_REVERSE);
    }
    else if(counter >= STEPPER_INDEXER_6_BY_8)
    {
        STEPPER_setMotorDrives(
                        handle, STEPPER_DRIVE_REVERSE, STEPPER_DRIVE_FORWARD);
    }
    else
    {
        /* This is expected to be empty*/
    }
}

/**
 * @brief     Updates phase drive state in non circular mode
 * @param[in] handle    A pointer to indexer instance
 */
__STATIC_INLINE void STEPPER_nonCirPhaseGen(INDEXER_Instance *handle)
{
    int16_t counter = handle->counter;
    if(counter >= STEPPER_INDEXER_0_BY_8 && counter < STEPPER_INDEXER_1_BY_8)
    {
        STEPPER_setMotorDrives(
                        handle, STEPPER_DRIVE_FORWARD, STEPPER_DRIVE_FORWARD);
    }
    if(counter >= STEPPER_INDEXER_1_BY_8 && counter < STEPPER_INDEXER_2_BY_8)
    {
        STEPPER_setMotorDrives(
                        handle, STEPPER_DRIVE_FORWARD, STEPPER_DRIVE_DECAY);
    }
    else if(counter >= STEPPER_INDEXER_2_BY_8 && counter < STEPPER_INDEXER_3_BY_8)
    {
        STEPPER_setMotorDrives(
                        handle, STEPPER_DRIVE_FORWARD, STEPPER_DRIVE_REVERSE);
    }
    else if(counter >= STEPPER_INDEXER_3_BY_8 && counter < STEPPER_INDEXER_4_BY_8)
    {
        STEPPER_setMotorDrives(
                        handle, STEPPER_DRIVE_DECAY, STEPPER_DRIVE_REVERSE);
    }
    else if(counter >= STEPPER_INDEXER_4_BY_8 && counter < STEPPER_INDEXER_5_BY_8)
    {
        STEPPER_setMotorDrives(
                        handle, STEPPER_DRIVE_REVERSE, STEPPER_DRIVE_REVERSE);
    }
    else if(counter >= STEPPER_INDEXER_5_BY_8 && counter < STEPPER_INDEXER_6_BY_8)
    {
        STEPPER_setMotorDrives(
                        handle, STEPPER_DRIVE_REVERSE, STEPPER_DRIVE_DECAY);
    }
    else if(counter >= STEPPER_INDEXER_6_BY_8 && counter < STEPPER_INDEXER_7_BY_8)
    {
        STEPPER_setMotorDrives(
                        handle, STEPPER_DRIVE_REVERSE, STEPPER_DRIVE_FORWARD);
    }
    else if(counter >= STEPPER_INDEXER_7_BY_8)
    {
        STEPPER_setMotorDrives(
                        handle, STEPPER_DRIVE_DECAY, STEPPER_DRIVE_FORWARD);
    }
    else
    {
        /* This is expected to be empty*/
    }
}

/*
* The current reference is used in case of drivers which has independent vref
* for each motor phase. This is disabled when not using such drivers
*/
#ifdef __HAS_2_DAC
/**
 * @brief     update of current reference value for A and B phases
 * @param[in] handle    A pointer to indexer instance
 */
__STATIC_INLINE void STEPPER_currRefGen(INDEXER_Instance *handle)
{
    uint32_t countValue = handle->counter;
    _iq15 angle = _IQ15mpy(_IQ15(countValue), angleSf);
    handle->IaCurrRef = _IQ15abs(_IQ15cos(angle));
    handle->IbCurrRef = _IQ15abs(_IQ15sin(angle));
}
#endif

/**
 * @brief     Increments the indexer counter and updates the phase 
 *            reference calculation
 * @param[in] handle    A pointer to indexer instance
 */
__STATIC_INLINE void STEPPER_indexer(INDEXER_Instance *handle)
{
    if(handle->dir == STEPPER_DIR_FORWARD)
    {
        handle->counter += handle->indexIncDec;
    }
    else
    {
        handle->counter -= handle->indexIncDec;
    }

    if(handle->counter < 0)
    {
        handle->counter = (STEPPER_INDEXER_MAX_COUNT + handle->counter);
    }

    if(handle->counter >= STEPPER_INDEXER_MAX_COUNT - 1)
    {
        handle->counter = 0;
    }

    if(handle->stepType == STEPPER_STEP_TYPE_CIR)
    {
        STEPPER_cirStepPhaseGen(handle);
    }
    else if(handle->stepType == STEPPER_STEP_TYPE_NONCIR)
    {
        STEPPER_nonCirPhaseGen(handle);
    }
    else
    {
        /* This is expected to be empty*/
    }
}

#ifdef __cplusplus
}
#endif
#endif /* STEPPER_H */
/** @}*/