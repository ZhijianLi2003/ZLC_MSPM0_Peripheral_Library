/*
 * Copyright (c) 2017-2020, Texas Instruments Incorporated
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
/** ============================================================================
 *  @file       DeviceFamily.h
 *
 *  @brief      Infrastructure to select correct driverlib path and identify devices
 *
 *  This module enables the selection of the correct driverlib path for the current
 *  device. It also facilitates the use of per-device conditional compilation
 *  to enable minor variations in drivers between devices.
 *
 *  In order to use this functionality, DeviceFamily_XYZ must be defined as one of
 *  the supported values. The DeviceFamily_ID and DeviceFamily_DIRECTORY defines
 *  are set based on DeviceFamily_XYZ.
 */

#ifndef ti_devices_DeviceFamily__include
#define ti_devices_DeviceFamily__include

#ifdef __cplusplus
extern "C" {
#endif

/* clang-format off */

/*
 * DeviceFamily_ID_XYZ values.
 *
 * DeviceFamily_ID may be used in the preprocessor for conditional compilation.
 * DeviceFamily_ID is set to one of these values based on the top level
 * DeviceFamily_XYZ define.
 */
#define DeviceFamily_ID_MSPM0L130X      1
#define DeviceFamily_ID_MSPM0L134X      2
#define DeviceFamily_ID_MSPM0L110X      3
#define DeviceFamily_ID_MSPM0G110X      4
#define DeviceFamily_ID_MSPM0G150X      5
#define DeviceFamily_ID_MSPM0G310X      6
#define DeviceFamily_ID_MSPM0G350X      7
#define DeviceFamily_ID_MSPM0C110X      8
#define DeviceFamily_ID_MSPS003FX       9
#define DeviceFamily_ID_MSPM0L122X      10
#define DeviceFamily_ID_MSPM0L222X      11

/*
 * DeviceFamily_PARENT_XYZ values.
 *
 * DeviceFamily_PARENT may be used in the preprocessor for conditional
 * compilation. DeviceFamily_PARENT is set to one of these values based
 * on the top-level DeviceFamily_XYZ define.
 */
#define DeviceFamily_PARENT_MSPM0L11XX_L13XX    1
#define DeviceFamily_PARENT_MSPM0G1X0X_G3X0X    2
#define DeviceFamily_PARENT_MSPM0C110X          3
#define DeviceFamily_PARENT_MSPS003FX           4
#define DeviceFamily_PARENT_MSPM0L122X_L222X    5

/*
 * Lookup table that sets DeviceFamily_ID, DeviceFamily_DIRECTORY, and
 * DeviceFamily_PARENT based on the DeviceFamily_XYZ define.
 * If DeviceFamily_XYZ is undefined, a compiler error is thrown. If
 * multiple DeviceFamily_XYZ are defined, the first one encountered is used.
 */
#if defined(DeviceFamily_MSPM0L130X) || defined(__MSPM0L1306__) \
     || defined(__MSPM0L1305__) || defined(__MSPM0L1304__) \
     || defined(__MSPM0L1303__)
    #define DeviceFamily_ID             DeviceFamily_ID_MSPM0L130X
    #define DeviceFamily_DIRECTORY      msp
    #define DeviceFamily_PARENT         DeviceFamily_PARENT_MSPM0L11XX_L13XX

#elif defined(DeviceFamily_MSPM0L134X) || defined(__MSPM0L1346__) \
    || defined(__MSPM0L1345__) || defined(__MSPM0L1344__) \
    || defined(__MSPM0L1343__)
    #define DeviceFamily_ID             DeviceFamily_ID_MSPM0L134X
    #define DeviceFamily_DIRECTORY      msp
    #define DeviceFamily_PARENT         DeviceFamily_PARENT_MSPM0L11XX_L13XX

#elif defined(DeviceFamily_MSPM0L110X) || defined(__MSPM0L1106__) \
    || defined(__MSPM0L1105__)
    #define DeviceFamily_ID             DeviceFamily_ID_MSPM0L110X
    #define DeviceFamily_DIRECTORY      msp
    #define DeviceFamily_PARENT         DeviceFamily_PARENT_MSPM0L11XX_L13XX

#elif defined(DeviceFamily_MSPM0G110X) || defined(__MSPM0G1107__) \
    || defined(__MSPM0G1106__) || defined(__MSPM0G1105__)
    #define DeviceFamily_ID             DeviceFamily_ID_MSPM0G110X
    #define DeviceFamily_DIRECTORY      msp
    #define DeviceFamily_PARENT         DeviceFamily_PARENT_MSPM0G1X0X_G3X0X

#elif defined(DeviceFamily_MSPM0G150X) || defined(__MSPM0G1507__) \
    || defined(__MSPM0G1506__) || defined(__MSPM0G1505__)
    #define DeviceFamily_ID             DeviceFamily_ID_MSPM0G150X
    #define DeviceFamily_DIRECTORY      msp
    #define DeviceFamily_PARENT         DeviceFamily_PARENT_MSPM0G1X0X_G3X0X

#elif defined(DeviceFamily_MSPM0G310X) || defined(__MSPM0G3107__) \
    || defined(__MSPM0G3106__) || defined(__MSPM0G3105__)
    #define DeviceFamily_ID             DeviceFamily_ID_MSPM0G310X
    #define DeviceFamily_DIRECTORY      msp
    #define DeviceFamily_PARENT         DeviceFamily_PARENT_MSPM0G1X0X_G3X0X

#elif defined(DeviceFamily_MSPM0G350X) || defined(__MSPM0G3507__) \
    || defined(__MSPM0G3506__) || defined(__MSPM0G3505__)
    #define DeviceFamily_ID             DeviceFamily_ID_MSPM0G350X
    #define DeviceFamily_DIRECTORY      msp
    #define DeviceFamily_PARENT         DeviceFamily_PARENT_MSPM0G1X0X_G3X0X
#elif defined(DeviceFamily_MSPM0C110X) || defined(__MSPM0C1104__) \
    || defined(__MSPM0C1103__)
    #define DeviceFamily_ID             DeviceFamily_ID_MSPM0C110X
    #define DeviceFamily_DIRECTORY      msp
    #define DeviceFamily_PARENT         DeviceFamily_PARENT_MSPM0C110X

#elif defined(DeviceFamily_MSPS003FX) || defined(__MSPS003F4__) \
    || defined(__MSPS003F3__)
    #define DeviceFamily_ID             DeviceFamily_ID_MSPS003FX
    #define DeviceFamily_DIRECTORY      msp
    #define DeviceFamily_PARENT         DeviceFamily_PARENT_MSPS003FX

#elif defined(DeviceFamily_MSPM0L122X) || defined(__MSPM0L1228__) \
    || defined(__MSPM0L1227__) || defined(__MSPM0L1226__)
    #define DeviceFamily_ID             DeviceFamily_ID_MSPM0L122X
    #define DeviceFamily_DIRECTORY      msp
    #define DeviceFamily_PARENT         DeviceFamily_PARENT_MSPM0L122X_L222X

#elif defined(DeviceFamily_MSPM0L222X) || defined(__MSPM0L2228__) \
    || defined(__MSPM0L2227__) || defined(__MSPM0L2226__)
    #define DeviceFamily_ID             DeviceFamily_ID_MSPM0L222X
    #define DeviceFamily_DIRECTORY      msp
    #define DeviceFamily_PARENT         DeviceFamily_PARENT_MSPM0L122X_L222X


#else
    #error "DeviceFamily_XYZ undefined. You must define a DeviceFamily_XYZ!"
#endif

/* Ensure that only one DeviceFamily was specified */
#if (defined(DeviceFamily_MSPM0L130X) \
    + defined(DeviceFamily_MSPM0L134X) \
    + defined(DeviceFamily_MSPM0L110X) \
    + defined(DeviceFamily_MSPM0G110X) \
    + defined(DeviceFamily_MSPM0G150X) \
    + defined(DeviceFamily_MSPM0G310X) \
    + defined(DeviceFamily_MSPM0G350X) \
    + defined(DeviceFamily_MSPM0C110X) \
    + defined(DeviceFamily_MSPS003FX) \
    + defined(DeviceFamily_MSPM0L122X) \
    + defined(DeviceFamily_MSPM0L222X) \
    ) > 1
    #error More then one DeviceFamily has been defined!
#endif

/*!
 *  @brief  Macro to include correct driverlib path.
 *
 *  @pre    DeviceFamily_XYZ which sets DeviceFamily_DIRECTORY must be defined
 *          first.
 *
 *  @param  x   A token containing the path of the file to include based on
 *              the root device folder. The preceding forward slash must be
 *              omitted. For example:
 *                  - #include DeviceFamily_constructPath(inc/hw_memmap.h)
 *                  - #include DeviceFamily_constructPath(driverlib/ssi.h)
 *
 *  @return Returns an include path.
 *
 */
#define DeviceFamily_constructPath(x) <ti/devices/DeviceFamily_DIRECTORY/x>

    /* clang-format on */

#ifdef __cplusplus
    }
#endif

#endif /* ti_devices_DeviceFamily__include */
