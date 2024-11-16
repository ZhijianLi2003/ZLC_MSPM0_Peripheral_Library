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


#include "dali_target_led_command.h"

void DALI_LED_referenceSystemPower(void){
    /* TEMPLATE FOR REFERENCE SYSTEM POWER COMMAND(COMMAND NUM:)
     * Part of optional load deviation feature*/
}

void DALI_LED_selectDimmingCurve(void){
    if(gControlVar1.ledControlGear.enableLEDDevice){
        if(gControlVar1.dataTransferRegister0 == 0){
            gControlVar1.ledControlGear.dimmingCurve = 0;
        }
        else if(gControlVar1.dataTransferRegister0 == 1){
            gControlVar1.ledControlGear.dimmingCurve = 1;
        }
        else{
            /* Do nothing */
        }
    }
}

void DALI_LED_setFastFadeTime(void){
    if(gControlVar1.ledControlGear.enableLEDDevice){
        if(gControlVar1.dataTransferRegister0 == 0){
            gControlVar1.ledControlGear.fastFadeTime = 0;
        }
        else if(gControlVar1.dataTransferRegister0 <= gControlVar1.ledControlGear.minFastFadeTime){
            gControlVar1.ledControlGear.fastFadeTime = gControlVar1.ledControlGear.minFastFadeTime;
        }
        else if(gControlVar1.dataTransferRegister0 > 27){
            gControlVar1.ledControlGear.fastFadeTime = 27;
        }
        else{
            gControlVar1.ledControlGear.fastFadeTime = gControlVar1.dataTransferRegister0;
        }
        if(gControlVar1.ledControlGear.fastFadeTime != 0){
            gControlVar1.fadeTime = gControlVar1.ledControlGear.fastFadeTime;
        }
        else{
            /* Do nothing, keep fade time as fade time */
        }
    }
}

void DALI_LED_queryControlGearType(void){
    if(gControlVar1.ledControlGear.enableLEDDevice){
        gControlVar1.transmitData = gControlVar1.ledControlGear.controlGearType;
        gControlVar1.transmitDataFlag = true;
    }
}

void DALI_LED_queryDimmingCurve(void){
    if(gControlVar1.ledControlGear.enableLEDDevice){
        gControlVar1.transmitData = gControlVar1.ledControlGear.controlGearType;
        gControlVar1.transmitDataFlag = true;
    }
}

void DALI_LED_queryFeatures(void){
    if(gControlVar1.ledControlGear.enableLEDDevice){
        gControlVar1.transmitData = gControlVar1.ledControlGear.features;
        gControlVar1.transmitDataFlag = true;
    }
}
void DALI_LED_queryFailureStatus(void){
    if(gControlVar1.ledControlGear.enableLEDDevice){
        gControlVar1.transmitData = gControlVar1.ledControlGear.failureStatus;
        gControlVar1.transmitDataFlag = true;
    }
}
void DALI_LED_queryLoadDecrease(void){
    if(gControlVar1.ledControlGear.enableLEDDevice){
        /** TEMPLATE FOR QUERY LOAD DECREASE COMMAND(COMMAND NUM:)
         * Part of optional load deviation feature*/
    }
}
void DALI_LED_queryLoadIncrease(void){
    if(gControlVar1.ledControlGear.enableLEDDevice){
        /** TEMPLATE FOR QUERY LOAD INCREASE COMMAND(COMMAND NUM:)
         * Part of optional load deviation feature*/
    }
}
void DALI_LED_queryThermalShutdown(void){
    if(gControlVar1.ledControlGear.enableLEDDevice){
        /** TEMPLATE FOR QUERY THERMAL SHUTDOWN COMMAND(COMMAND NUM:)
         * Part of optional thermal protection feature*/
    }
}
void DALI_LED_queryThermalOverload(void){
    if(gControlVar1.ledControlGear.enableLEDDevice){
        /** TEMPLATE FOR QUERY THERMAL OVERLOAD COMMAND(COMMAND NUM:)
         * Part of optional thermal protection feature*/
    }
}
void DALI_LED_queryReferenceRunning(void){
    if(gControlVar1.ledControlGear.enableLEDDevice){
        /** TEMPLATE FOR QUERY REFERENCE RUNNING COMMAND(COMMAND NUM:)
         * Part of optional load deviation feature*/
    }
}
void DALI_LED_queryReferenceMeasurementFailed(void){
    if(gControlVar1.ledControlGear.enableLEDDevice){
        /** TEMPLATE FOR QUERY REFERENCE MEASUREMENT FAILED COMMAND(COMMAND NUM:)
         * Part of optional load deviation feature*/
    }
}
void DALI_LED_queryFastFadeTime(void){
    if(gControlVar1.ledControlGear.enableLEDDevice){
        gControlVar1.transmitData = gControlVar1.ledControlGear.fastFadeTime;
        gControlVar1.transmitDataFlag = true;
    }
}
void DALI_LED_queryMinFastFadeTime(void){
    if(gControlVar1.ledControlGear.enableLEDDevice){
        gControlVar1.transmitData = gControlVar1.ledControlGear.minFastFadeTime;
        gControlVar1.transmitDataFlag = true;
    }
}
void DALI_LED_queryExtendedVersionNumber(void){
    if(gControlVar1.ledControlGear.enableLEDDevice){
        gControlVar1.transmitData = EXTENDED_VERSION_NUMBER_DEFAULT;
        gControlVar1.transmitDataFlag = true;
    }
}

void DALI_LED_enableDeviceType(void){
    if(gControlVar1.deviceType == 6){
        gControlVar1.ledControlGear.enableLEDDevice = true;
    }
    else{
        gControlVar1.ledControlGear.enableLEDDevice = false;
    }
}
