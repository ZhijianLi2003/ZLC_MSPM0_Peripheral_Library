/*****************************************************************************

  Copyright (C) 2020 Texas Instruments Incorporated - http://www.ti.com/ 

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

/* This file automatically includes the specific device header file
   without the need to include a specific device header.
   The device #define is set automatically through the toolchain on basis
   of the device chosen in the device selection menu (.e.g -D__MICRO1__).      */

#ifndef ti_devices_msp_msp__include
#define ti_devices_msp_msp__include

/* This preliminary header file does not have a version number -  build date: 2020-08-28 14:25:07 */

/******************************************************************************
* MSP devices
******************************************************************************/

#include <ti/devices/DeviceFamily.h>

#if (DeviceFamily_ID == DeviceFamily_ID_MSPM0G110X)
#include <ti/devices/msp/m0p/mspm0g110x.h>
#elif (DeviceFamily_ID == DeviceFamily_ID_MSPM0G150X)
#include <ti/devices/msp/m0p/mspm0g150x.h>
#elif (DeviceFamily_ID == DeviceFamily_ID_MSPM0G310X)
#include <ti/devices/msp/m0p/mspm0g310x.h>
#elif (DeviceFamily_ID == DeviceFamily_ID_MSPM0G350X)
#include <ti/devices/msp/m0p/mspm0g350x.h>
#elif (DeviceFamily_ID == DeviceFamily_ID_MSPM0L110X)
#include <ti/devices/msp/m0p/mspm0l110x.h>
#elif (DeviceFamily_ID == DeviceFamily_ID_MSPM0L130X)
#include <ti/devices/msp/m0p/mspm0l130x.h>
#elif (DeviceFamily_ID == DeviceFamily_ID_MSPM0L134X)
#include <ti/devices/msp/m0p/mspm0l134x.h>
#elif (DeviceFamily_ID == DeviceFamily_ID_MSPM0C110X) || (DeviceFamily_ID == DeviceFamily_ID_MSPS003FX)
#include <ti/devices/msp/m0p/mspm0c110x.h>
#elif (DeviceFamily_ID == DeviceFamily_ID_MSPM0L222X)
#include <ti/devices/msp/m0p/mspm0l222x.h>
#elif (DeviceFamily_ID == DeviceFamily_ID_MSPM0L122X)
#include <ti/devices/msp/m0p/mspm0l122x.h>

/********************************************************************
 *
 ********************************************************************/
#else
#error "Failed to match a default include file"
#endif

#endif /* ti_devices_msp_msp__include */
