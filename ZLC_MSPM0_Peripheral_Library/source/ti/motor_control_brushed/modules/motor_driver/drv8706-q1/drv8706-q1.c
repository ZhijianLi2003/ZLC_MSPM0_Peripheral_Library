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

#ifndef drv8706_q1_h
#define drv8706_q1_h

#include "drv8706-q1.h"

#define IGNORE_SPI

#define DRV8706Q1_BRG_FW_OFS    (4)
#define DRV8706Q1_BRG_FW_MASK   (1 << DRV8706Q1_BRG_MODE_OFS)

#define DRV8706Q1_BRG_MODE_OFS  (5)
#define DRV8706Q1_BRG_MODE_MASK (3 << DRV8706Q1_BRG_MODE_OFS)

#define DRV8706Q1_CSA_GAIN_OFS  (0)
#define DRV8706Q1_CSA_GAIN_MASK (3 << DRV8706Q1_CSA_GAIN_OFS)

#define DRV8706Q1_CSA_DIV_OFS  (2)
#define DRV8706Q1_CSA_DIV_MASK (1 << DRV8706Q1_CSA_DIV_OFS)

#define DRV8706_RESET_TIME_MS (100)
typedef enum {
    DRV8706Q1_BRG_MODE_HALF_BRIDGE_MODE = 0,
    DRV8706Q1_BRG_MODE_PHASE_MODE = 1,
    DRV8706Q1_BRG_MODE_H_BRIDGE_MODE = 2,
    DRV8706Q1_BRG_MODE_SOLENOID_MODE = 3,
} DRV8706Q1_BRG_MODE_FIELD;

void DRV8706Q1_powerOnResetVal(DRV8706Q1_INSTANCE* drv) {
    /* Internal module variables that should be set to the motor driver's reset
     * value.
     */
    drv->csaDiv = DRV8706Q1_CSA_DIV_2;
    drv->csaGain = DRV8706Q1_CSA_GAIN_20;
    drv->driveMode = DRV8706Q1_HALF_BRIDGE;
}
void DRV8706Q1_init(DRV8706Q1_INSTANCE* drv) {

    drv->aRef_V = _IQ20(1);
    drv->csaSF = _IQ20(1);
    drv->shuntRes = _IQ20(1);
    DRV8706Q1_powerOnResetVal(drv);
}
void DRV8706Q1_setPWMFreq(DRV8706Q1_INSTANCE drv,
                          DRV8706Q1_PWM_CHANNELS drvChan,
                          uint32_t value) {
    PWM_CHANNELS pwmChan;

    if(drvChan == DRV8706Q1_PWM_CHANNEL_0) {
        pwmChan = drv.in1En;
    } else if(drvChan == DRV8706Q1_PWM_CHANNEL_1) {
        pwmChan = drv.in2Ph;
    } else {
        /* Code shouldn't get here */
    }

    HAL_setPWMFreq(pwmChan,value);
}

void DRV8706Q1_setDutyCycle(DRV8706Q1_INSTANCE drv,
                            DRV8706Q1_PWM_CHANNELS drvChan,
                            uint8_t value) {
    PWM_CHANNELS pwmChan;

    if(drvChan == DRV8706Q1_PWM_CHANNEL_0) {
        pwmChan = drv.in1En;
    } else if(drvChan == DRV8706Q1_PWM_CHANNEL_1) {
        pwmChan = drv.in2Ph;
    } else {
        /* Code shouldn't get here */
    }

    HAL_setDutyCycle(pwmChan,value);
}

void DRV8706Q1_setDrivePWMFreq(DRV8706Q1_INSTANCE drv,
                               DRV8706Q1_PWM_CHANNELS drvPwmChan,
                               uint32_t value) {
    DRV8706Q1_MODES curMode = drv.driveMode;
    if(curMode == DRV8706Q1_H_BRIDGE) {
        DRV8706Q1_setPWMFreq(drv,DRV8706Q1_PWM_CHANNEL_0,value);
        DRV8706Q1_setPWMFreq(drv,DRV8706Q1_PWM_CHANNEL_1,value);
    } else if(curMode == DRV8706Q1_PH_EN) {
        DRV8706Q1_setPWMFreq(drv,DRV8706Q1_PWM_CHANNEL_0,value);
    } else if(curMode == DRV8706Q1_SPLIT_SOLENOID) {
        DRV8706Q1_setPWMFreq(drv,DRV8706Q1_PWM_CHANNEL_1,value);
    } else if(curMode == DRV8706Q1_HALF_BRIDGE) {
        DRV8706Q1_setPWMFreq(drv,drvPwmChan,value);
    } else {
        /* Code shouldn't get here */
    }
}


void DRV8706Q1_setDriveDutyCycle(DRV8706Q1_INSTANCE drv,
                                 DRV8706Q1_PWM_CHANNELS drvPwmChan,
                                 uint8_t value) {
    DRV8706Q1_MODES curMode = drv.driveMode;
    if(curMode == DRV8706Q1_H_BRIDGE) {
        DRV8706Q1_setDutyCycle(drv,DRV8706Q1_PWM_CHANNEL_0, value);
        DRV8706Q1_setDutyCycle(drv,DRV8706Q1_PWM_CHANNEL_1, value);
    } else if(curMode == DRV8706Q1_PH_EN) {
        DRV8706Q1_setDutyCycle(drv,DRV8706Q1_PWM_CHANNEL_0, value);
    } else if(curMode == DRV8706Q1_SPLIT_SOLENOID) {
        DRV8706Q1_setDutyCycle(drv,DRV8706Q1_PWM_CHANNEL_1, value);
    } else if(curMode == DRV8706Q1_HALF_BRIDGE) {
        DRV8706Q1_setDutyCycle(drv,drvPwmChan, value);
    } else {
        /* Code shouldn't get here */
    }
}

void DRV8706Q1_changeSolenoidDrive(DRV8706Q1_INSTANCE drv,
                                   DRV8706Q1_SOLENOID_DRIVES drive) {
    if (drive == DRV8706Q1_SOLENOID_DISABLE) {
        HAL_configurePWMPin(drv.in1En,PIN_MODE_OUTPUT_LOW);
        HAL_configurePWMPin(drv.in2Ph,PIN_MODE_PERIPHERAL);
        HAL_setGPIOOutput(drv.nHiz1,PIN_MODE_OUTPUT_LOW);
        HAL_setGPIOOutput(drv.nHiz2,PIN_MODE_OUTPUT_LOW);
    }

    else if (drive == DRV8706Q1_SOLENOID_PWM) {
        HAL_configurePWMPin(drv.in1En,PIN_MODE_OUTPUT_HIGH);
        HAL_configurePWMPin(drv.in2Ph,PIN_MODE_PERIPHERAL);
        HAL_setGPIOOutput(drv.nHiz1,PIN_MODE_OUTPUT_LOW);
        HAL_setGPIOOutput(drv.nHiz2,PIN_MODE_OUTPUT_LOW);
    } else {
        /* Code shouldn't get here */
    }
}

void DRV8706Q1_changeHalfBridgeDrive(DRV8706Q1_INSTANCE drv,
                             DRV8706Q1_PWM_CHANNELS drvChan,
                             DRV8706Q1_HALF_BRIDGE_DRIVES drive) {
    GPIO_OUTPUT_PINS nhizx;
    PWM_CHANNELS inx;

    if(drvChan == DRV8706Q1_PWM_CHANNEL_0) {
        nhizx = drv.nHiz1;
        inx = drv.in1En;
    } else if (drvChan == DRV8706Q1_PWM_CHANNEL_1) {
        nhizx = drv.nHiz2;
        inx = drv.in2Ph;
    } else {
        /* Code shouldn't get here */
    }

    if (drive == DRV8706Q1_HALF_BRIDGE_HI_Z) {
        HAL_setGPIOOutput(nhizx,PIN_MODE_OUTPUT_LOW);
        HAL_configurePWMPin(inx,PIN_MODE_OUTPUT_LOW);
    }
    else if (drive == DRV8706Q1_HALF_BRIDGE_PWM) {
        HAL_setGPIOOutput(nhizx,PIN_MODE_OUTPUT_HIGH);
        HAL_configurePWMPin(inx,PIN_MODE_PERIPHERAL);
    } else {
        /* Code shouldn't get here */
    }

}


void DRV8706Q1_changeHBridgeDrive(DRV8706Q1_INSTANCE drv,
                                  DRV8706Q1_H_BRIDGE_DRIVES drive) {
    if(drive == DRV8706Q1_H_BRIDGE_COAST) {
        HAL_configurePWMPin(drv.in1En,PIN_MODE_OUTPUT_LOW);
        HAL_configurePWMPin(drv.in2Ph,PIN_MODE_OUTPUT_LOW);
    }
    else if (drive == DRV8706Q1_H_BRIDGE_REVERSE) {
        HAL_configurePWMPin(drv.in1En,PIN_MODE_OUTPUT_LOW);
        HAL_configurePWMPin(drv.in2Ph,PIN_MODE_PERIPHERAL);
    }
    else if (drive == DRV8706Q1_H_BRIDGE_FORWARD) {
        HAL_configurePWMPin(drv.in1En,PIN_MODE_PERIPHERAL);
        HAL_configurePWMPin(drv.in2Ph,PIN_MODE_OUTPUT_LOW);
    }
    else if (drive == DRV8706Q1_H_BRIDGE_ACTIVE_FREEWHEEL) {
        HAL_configurePWMPin(drv.in1En,PIN_MODE_OUTPUT_HIGH);
        HAL_configurePWMPin(drv.in2Ph,PIN_MODE_OUTPUT_HIGH);
    } else {
        /* Code shouldn't get here */
    }
}

void DRV8706Q1_changePhaseDrive(DRV8706Q1_INSTANCE drv,
                                DRV8706Q1_PHASE_DRIVES drive) {
    if (drive == DRV8706Q1_PHASE_REVERSE) {
        HAL_configurePWMPin(drv.in1En,PIN_MODE_PERIPHERAL);
        HAL_configurePWMPin(drv.in2Ph,PIN_MODE_OUTPUT_LOW);
    }
    else if (drive == DRV8706Q1_PHASE_FORWARD) {
        HAL_configurePWMPin(drv.in1En,PIN_MODE_PERIPHERAL);
        HAL_configurePWMPin(drv.in2Ph,PIN_MODE_OUTPUT_HIGH);
    }
    else if (drive == DRV8706Q1_PHASE_ACTIVE_FREEWHEEL) {
        HAL_configurePWMPin(drv.in1En,PIN_MODE_OUTPUT_LOW);
    } else {
        /* Code shouldn't get here */
    }
}

void DRV8706Q1_reset(DRV8706Q1_INSTANCE* drv) {
    DRV8706Q1_setNSleep(*drv,LOW);
    HAL_delayMilliSeconds(DRV8706_RESET_TIME_MS);
    DRV8706Q1_setNSleep(*drv,HIGH);

    DRV8706Q1_powerOnResetVal(drv);
}

uint16_t DRV8706Q1_spiUpdateRegister(DRV8706Q1_INSTANCE drv,
                                 DRV8706Q1_SPI_ADDR addr,
                                 uint8_t mask,
                                 uint8_t value) {
    uint8_t dataValue;
    dataValue = (uint8_t) DRV8706Q1_spiReadCmd(drv,addr);
    dataValue &= ~(mask);
    dataValue |= value;
    return DRV8706Q1_spiWriteCmd(drv,addr, dataValue);
}

uint16_t DRV8706Q1_switchToHBridgeDrive(DRV8706Q1_INSTANCE *drv,
                                DRV8706Q1_H_BRIDGE_DRIVES drive) {
    uint8_t mask;
    uint8_t value;
    uint16_t spiReadValue;

    mask = (DRV8706Q1_BRG_MODE_MASK);
    value = (DRV8706Q1_BRG_MODE_H_BRIDGE_MODE << DRV8706Q1_BRG_MODE_OFS);

    drv->driveMode = DRV8706Q1_H_BRIDGE;
    spiReadValue = DRV8706Q1_spiUpdateRegister(*drv,
                                               DRV8706Q1_SPI_ADDR_BRG_CTRL,
                                               mask,
                                               value);
    DRV8706Q1_changeHBridgeDrive(*drv, drive);
    return spiReadValue;
}


uint16_t DRV8706Q1_switchToPhaseDrive(DRV8706Q1_INSTANCE* drv,
                                  DRV8706Q1_PHASE_DRIVES drive) {
    uint8_t mask;
    uint8_t value;
    uint16_t spiReadValue;

    mask = (DRV8706Q1_BRG_MODE_MASK);
    value = (DRV8706Q1_BRG_MODE_PHASE_MODE << DRV8706Q1_BRG_MODE_OFS);

    drv->driveMode = DRV8706Q1_PH_EN;
    spiReadValue = DRV8706Q1_spiUpdateRegister(*drv,DRV8706Q1_SPI_ADDR_BRG_CTRL,mask,value);
    DRV8706Q1_changePhaseDrive(*drv,drive);
    return spiReadValue;
}

uint16_t DRV8706Q1_switchToHalfBridgeDrive(DRV8706Q1_INSTANCE* drv,
                               DRV8706Q1_HALF_BRIDGE_DRIVES driveChan0,
                               DRV8706Q1_HALF_BRIDGE_DRIVES driveChan1) {
    uint8_t mask;
    uint8_t value;
    uint16_t spiReadValue;

    mask = (DRV8706Q1_BRG_MODE_MASK);
    value = (DRV8706Q1_BRG_MODE_HALF_BRIDGE_MODE << DRV8706Q1_BRG_MODE_OFS);

    spiReadValue = DRV8706Q1_spiUpdateRegister(*drv,DRV8706Q1_SPI_ADDR_BRG_CTRL,mask,value);

    drv->driveMode = DRV8706Q1_HALF_BRIDGE;
    DRV8706Q1_changeHalfBridgeDrive(*drv, DRV8706Q1_PWM_CHANNEL_0, driveChan0);
    DRV8706Q1_changeHalfBridgeDrive(*drv, DRV8706Q1_PWM_CHANNEL_1, driveChan1);
    return spiReadValue;
}

uint16_t DRV8706Q1_switchToSolenoidDrive(DRV8706Q1_INSTANCE* drv,
                                     DRV8706Q1_SOLENOID_DRIVES drive) {
    uint8_t mask;
    uint8_t value;
    uint16_t spiReadValue;

    mask = (DRV8706Q1_BRG_MODE_MASK);
    value = (DRV8706Q1_BRG_MODE_SOLENOID_MODE << DRV8706Q1_BRG_MODE_OFS);

    drv->driveMode = DRV8706Q1_SPLIT_SOLENOID;
    spiReadValue = DRV8706Q1_spiUpdateRegister(*drv,DRV8706Q1_SPI_ADDR_BRG_CTRL,mask,value);
    DRV8706Q1_changeSolenoidDrive(*drv,drive);

    return spiReadValue;
}

uint16_t DRV8706Q1_spiCmd(SPI_CHANNELS spiChan,
                          SPI_CS spiCS,
                          DRV8706Q1_SPI_W0_BIT wo_bit,
                          DRV8706Q1_SPI_ADDR addr,
                          uint8_t data) {
    uint16_t command = 0;

    /* Bit 14 W0: write = 0 and read = 1 */
    command = ((wo_bit) << 14);

    /* Bit 13-8: address */
    command |= (addr << 8);

    /* Bit 7-0: data */
    command |= data;

    HAL_writeSPI16withTimeout(spiChan,spiCS,command,0);
    return HAL_readSPI16withTimeout(spiChan,spiCS,0);
}

void DRV8706Q1_updateCSAScaleFactor(DRV8706Q1_INSTANCE *drv) {
    /* To speed up current calculations we use a csaSF that can be calculated
     * once and reused repeatedly. Especially since we performing fixed
     * point calculations so avoiding repeated multiplication and division
     * operations will save a lot of CPU cycles.
     *
     *   Bidirectional I = ((Vvref/2)-Vsox)/(Gcsa*Rsense)
     *   Unidirectional I = ((Vvref)-Vsox)/(Gcsa*Rsense)
     *   csaSF = 1/(Gcsa*Rsense)
     */

    drv->csaSF = _IQ20mpy(_IQ20(drv->csaGain),drv->shuntRes);
    drv->csaSF = _IQ20div(_IQ20(1),drv->csaSF);
}

void DRV8706Q1_setAnalogReference(DRV8706Q1_INSTANCE *drv, _iq20 aRef_V) {
    drv->aRef_V = aRef_V;
}

uint16_t DRV8706Q1_setCurrentSenseGain(DRV8706Q1_INSTANCE *drv,
                                       DRV8706Q1_CSA_GAINS gcsa) {
    uint8_t csaGain = 0;
    if (gcsa == DRV8706Q1_CSA_GAIN_10) {
        csaGain = 0;
    } else if (gcsa == DRV8706Q1_CSA_GAIN_20) {
        csaGain = 1;
    } else if (gcsa == DRV8706Q1_CSA_GAIN_40) {
        csaGain = 2;
    } else if (gcsa == DRV8706Q1_CSA_GAIN_80) {
        csaGain = 3;
    } else {
        /* Should never reach here */
    }

    drv->csaGain = gcsa;

    DRV8706Q1_updateCSAScaleFactor(drv);
    return DRV8706Q1_spiUpdateRegister(*drv,
                                       DRV8706Q1_SPI_ADDR_CSA_CTRL,
                                       DRV8706Q1_CSA_GAIN_MASK,csaGain);

}

uint16_t DRV8706Q1_setAnalogReferenceDivider(DRV8706Q1_INSTANCE *drv,
                                            DRV8706Q1_CSA_DIV csaDiv) {
    uint8_t val;
    drv->csaDiv = csaDiv;

    if(csaDiv == DRV8706Q1_CSA_DIV_2) {
        val = 0;
    } else {
        val = 1;
    }

    return DRV8706Q1_spiUpdateRegister(*drv,
                                       DRV8706Q1_SPI_ADDR_CSA_CTRL,
                                       DRV8706Q1_CSA_DIV_MASK,
                                       (val << DRV8706Q1_CSA_DIV_OFS));
}

void DRV8706Q1_setCurrentShuntResistor(DRV8706Q1_INSTANCE *drv,_iq20 rShunt) {
    drv->shuntRes = rShunt;
    DRV8706Q1_updateCSAScaleFactor(drv);
}

_iq20 DRV8706Q1_getCurrent(DRV8706Q1_INSTANCE drv) {
    /*
        I = ((Vvref/csaDiv)-Vsox)/(Gcsa*Rsense)
    */
    _iq20 vSO = HAL_getIQ20VoltageFromADC(drv.adcChan);
    _iq20 vRef = drv.aRef_V;
    if ( drv.csaDiv == DRV8706Q1_CSA_DIV_2) {
        vRef = vRef >> 1;
    } else {
        /* Assuming DRV8706Q1_CSA_DIV_8 */
        vRef = vRef >> 3;
    }
     return _IQ20mpy(vRef-vSO,drv.csaSF);
}


#endif
