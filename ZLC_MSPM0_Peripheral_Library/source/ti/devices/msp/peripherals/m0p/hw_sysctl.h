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

/* This file automatically includes the specific device sysctl header file
   without the need to include a specific device sysctl header.
   The device #define is set automatically through the toolchain on basis
   of the device chosen in the device selection menu (.e.g -D__MICRO1__).      */

#ifndef ti_devices_msp_peripheral_m0p_sysctl__include
#define ti_devices_msp_peripheral_m0p_sysctl__include

/******************************************************************************
* MSP devices
******************************************************************************/

#include <ti/devices/DeviceFamily.h>

#if (DeviceFamily_PARENT == DeviceFamily_PARENT_MSPM0G1X0X_G3X0X)
#include <ti/devices/msp/peripherals/m0p/sysctl/hw_sysctl_mspm0g1x0x_g3x0x.h>
#elif (DeviceFamily_PARENT == DeviceFamily_PARENT_MSPM0L11XX_L13XX)
#include <ti/devices/msp/peripherals/m0p/sysctl/hw_sysctl_mspm0l11xx_l13xx.h>
#elif (DeviceFamily_PARENT == DeviceFamily_PARENT_MSPM0C110X) || (DeviceFamily_PARENT == DeviceFamily_PARENT_MSPS003FX)
#include <ti/devices/msp/peripherals/m0p/sysctl/hw_sysctl_mspm0c110x.h>
#elif (DeviceFamily_PARENT == DeviceFamily_PARENT_MSPM0L122X_L222X)
#include <ti/devices/msp/peripherals/m0p/sysctl/hw_sysctl_mspm0l122x_l222x.h>
/********************************************************************
 *
 ********************************************************************/
#else
#error "Failed to match a default include file"
#endif

#endif /* ti_devices_msp_peripheral_m0p_sysctl__include */