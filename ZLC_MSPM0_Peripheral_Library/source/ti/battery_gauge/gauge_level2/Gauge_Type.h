/*
 * Copyright (c) 2024, Texas Instruments Incorporated
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
#ifndef GAUGE_ALGORITHM_GAUGE_TYPE_H_
#define GAUGE_ALGORITHM_GAUGE_TYPE_H_

#include <stdbool.h>
#include <stdint.h>
#include <ti/iqmath/include/IQmathLib.h>

#define COMMUNICATION_DATA_INPUT (1)
#define DETECTION_DATA_INPUT (2)
#define NO_OUTPUT (0)
#define UART_OUTPUT (1)
#define WARN_FILTER (0x3FF)
#define MATRIX_ROW_LENGTH \
    (7)  //Number of temperature bins (rows in the CV matrix)
#define MATRIX_COL_LENGTH (5)  //Number of current bins (cols in the CV matrix)
//*****************************************************************************
// Describe OPA test mode
//*****************************************************************************
typedef enum {
    eNormalMode = 0,
    eOffsetCali = 1,
} tOPACali;

//*****************************************************************************
// Describe the status
//*****************************************************************************
enum {
    eFalse = 0,
    eTrue  = 1,
};
typedef uint8_t tStatus;

//*****************************************************************************
// Describe the status of Battery state
//*****************************************************************************
typedef enum {
    eUnload,
    eDHG,
    eCHG,
} tBattState;

//*****************************************************************************
// Describe the algorithm one running cycle time
//*****************************************************************************
typedef enum {
    eSystemTik_32000MS = 64,
    eSystemTik_16000MS = 32,
    eSystemTik_8000MS  = 16,
    eSystemTik_4000MS  = 8,
    eSystemTik_2000MS  = 4,
    eSystemTik_1000MS  = 2,
    eSystemTik_e500MS  = 1,
} tSystemTikFreq;

//*****************************************************************************
// Describe different Sum Capacity type, used in CurtGauge
//*****************************************************************************
typedef enum {
    eTempQsum,
    eChgQsum,
    eDhgQsum,
    eDeltaQsum,
} tQsumType;

//*****************************************************************************
// Describe different OPA setting
//*****************************************************************************
typedef enum {
    eGAIN16,
    eGAIN32,
} eOpaGain;

//*****************************************************************************
// Warning flags
//*****************************************************************************
typedef struct {
    tStatus VcellHighWarnFlg : 1;
    tStatus VcellLowWarnFlg : 1;
    tStatus IcellHighWarnFlg : 1;
    tStatus IcellLowWarnFlg : 1;
    tStatus TcellChgHighWarnFlg : 1;
    tStatus TcellChgLowWarnFlg : 1;
    tStatus TcellDhgHighWarnFlg : 1;
    tStatus TcellDhgLowWarnFlg : 1;
    tStatus CircuitTableOverRangeFlg : 1;
    tStatus DhgChgEfcyGapFlg : 1;
} tWarningFlags;

//*****************************************************************************
// Elements used in the battery circuit model, which is used characterize the battery
// These parameters need to input ahead.
// We most care is the accurate of discharging parameters, especially iq15DhgNomRcell_R.
// For other parameters we can input by experience.
//*****************************************************************************
typedef struct {
    _iq15 iq15DhgOcv_mV;  //Open circuit voltage, unit is mV
    _iq15 iq15Soc_DEC;    //State of charge, unit is decimal
    _iq15
        iq15CapFactor;  //C = dSoc/dOcv(V)*Qmax(As) = dSoc/dOcv(V)*3.6*Qmax(mAh)
                        //capFactor = dSoc/dOcv*3.6
    _iq15 iq15DhgNomRcell_R;
    _iq20 iq20SlopeRate;
} tBattCircuitParams;

//*****************************************************************************
// Parameters used in IGauge
//When i16mA meet +-256, i16mAs will add. When i16mAs meet 3600, i16mAh will add.
//When i16mA meet +-3600, i16mAs will add
//*****************************************************************************
typedef struct {
    int16_t i16Qsum_mA;
    int16_t i16Qsum_mAs;
    int16_t i16Qsum_mAh;
} tQsum;

typedef struct {
    tQsum tempQsum;   //Used to update u16IF_NomRemCap_mAh, will be calibrated
    tQsum deltaQsum;  //Used to update u16IF_NomRemCap_mAh, will be calibrated
    tQsum chgQsum;
    tQsum dhgQsum;
    int16_t i16IF_NomRemCap_mAh;  //Will be update in every OCV calibration,
        //because it can show the performance of OCV calibration method
    uint16_t u16DhgCycles;
    uint16_t u16ChgCycles;
} tIGaugeCoulometerParams;

//*****************************************************************************
// Parameters inputed by customer
//*****************************************************************************
typedef const struct {
    //******************************Generation configuration parameters********************************//
    tBattCircuitParams *pBattCircuitParams;
    uint16_t
        u16DesignCap_mAh;  //Battery default battery Cell Size, unit is  mAh
    uint16_t
        u16MinBattVoltThd_mV;  //Need to ensure the battery run time voltage all larger that it.
    uint16_t
        u16MaxBattVoltThd_mV;  //Need to ensure the battery run time voltage all lower that it.
    uint16_t
        u16MinFullChgVoltThd_mV;  //The minimum battery constant charge voltage, need to consider to voltage drop caused from line resistance.
    //Should be a little lower than real battery constant charge voltage, like 1000mV
    uint16_t
        u16MaxFullChgVoltThd_mV;  //The maximum battery constant charge voltage
    //Should be a little higher than real battery constant charge voltage, like 100mV
    //Should be lower than the max volt in circuit table
    uint16_t
        u16EmptyDhgVoltThd_mV;  // Empty voltage, treat as the CusSoc = 0%, should be higher than u16MinBattVoltThd_mV
    //Should be higher than the lowest volt in circuit table
    int16_t
        i16FullChgCurtThd_mA;  // Battery charge termination current threshold when it is full, Normally it is 1/20~1/15C
    //Used to tell Gauge the battery is full. Need a little higher than the real charge
    //terminate current. Otherwise the judgment of CHG full will have a problem
    int16_t i16MaxChgCurtThd_mA;  // Battery fast charge current threshold
    int16_t
        i16MinDhgCurtThd_mA;  // Battery fast discharge current threshold, Above will set flag
    int8_t
        i8MaxChgTempThd_C;  // Battery maximum temperature threshold, Above will set flag
    int8_t
        i8MinChgTempThd_C;  // Battery minimum temperature threshold, Above will set flag
    int8_t
        i8MaxDhgTempThd_C;  // Battery maximum temperature threshold, Above will set flag
    int8_t
        i8MinDhgTempThd_C;  // Battery minimum temperature threshold, Above will set flag
    uint8_t
        u8AvgBattParamsUpdateCount;  //Average battery parameters update time:u8AvgBattParamsUpdateCount*sysTikFreq

    //******************************Mix algorithm related parameters************************************//
    uint16_t u16ConvergeStartVolt_mV;
    int8_t
        i8TempThd1_C;  //Used for AmptySoc and FullSoc calculation, lowest temperature threshold
    int8_t i8TempThd2_C;  //Used for AmptySoc and FullSoc calculation
    int8_t i8TempThd3_C;  //Used for AmptySoc and FullSoc calculation
    int8_t i8TempThd4_C;  //Used for AmptySoc and FullSoc calculation
    int8_t i8TempThd5_C;  //Used for AmptySoc and FullSoc calculation
    int8_t
        i8TempThd6_C;  //Used for AmptySoc and FullSoc calculation, highest temperature threshold
    int16_t
        i16CurtThd1_mA;  //Used for AmptySoc calculation, smallest discharge current threshold
    int16_t i16CurtThd2_mA;  //Used for AmptySoc calculation
    int16_t i16CurtThd3_mA;  //Used for AmptySoc calculation
    int16_t
        i16CurtThd4_mA;  //Used for AmptySoc calculation, largest discharge current threshold
    _iq15 iq15AbsEmptySocMatrixInput[MATRIX_ROW_LENGTH * MATRIX_COL_LENGTH];
    _iq15 iq15SmSocIIRFactor;

    //***********************Capacity learn algorithm related parameters********************************//
    int16_t
        i16UnloadCurtLowThd_mA;  //Used to judge the battery unload status, higher than the current detection offset
    int16_t
        i16UnloadCurtHighThd_mA;  //Used to judge the battery unload status, lower than the current detection offset
    _iq15 iq15DefaultSOH_DEC;

    //****************************VoltGuage algorithm related parameters********************************//
    uint8_t u8CircuitTableLength;  //Battery circuit table length
    uint8_t
        u8CircuitTableTestTemp_C;  //Battery circuit table test temperature, used to evaluate runtime Rcell
    // paired with RcellNegTshift and RcellPosTshift
    _iq15
        iq15RcellNegTshift_R;  //Resolution is 0.000030518R or 0.03mR, changed based on u8CircuitTableTestTemp_C
    _iq15
        iq15RcellPosTshift_R;  //Resolution is 0.000030518R or 0.03mR, changed based on u8CircuitTableTestTemp_C

    //****************************CurrentGuage algorithm related parameters********************************//
    int16_t i16AvgLeakageCurt_mA;  //Leakage current
    int16_t i16PassiveDhgCurt_mA;
} tBattParamsConfig;

//*****************************************************************************
// Gauge  detection parameters(V, I, T)
//*****************************************************************************
typedef struct {
    tStatus avgBattParamsUpdateFlg : 1;  //The average data is prepared
    tStatus CellBalanceFlg : 1;          //Cell
    int8_t i8Tcell_C;                    //Battery temperature
    _iq15 iq15Vcell_mV;                  //Battery voltage, unit is mV
    int16_t
        i16Icell_mA;  //Battery current, unit is mA, discharge is negative charge is positive
    int16_t i16SumTcell;   //Temp value used to calculate u16AvgTcell_mV
    uint32_t u32SumVcell;  //Temp value used to calculate u16AvgVcell_mV
    int32_t i32SumIcell;   //Temp value used to calculate u16AvgIcell_mV
    uint8_t u8SumCount;    //Used to count the Sum
    _iq15 iq15AvgVcell_mV;
    int16_t i16AvgIcell_mA;
    int8_t i8AvgTcell_C;
} tBattInfoInput;

//*****************************************************************************
// Current calibration factors
//*****************************************************************************
typedef struct {
    uint8_t u8R12toR2FactorCaliValue;
    uint8_t u8R34toR3FactorCaliValue_Gain32;
    uint8_t u8R34toR3FactorCaliValue_Gain16;
    uint8_t u8DefaultValue_Gain32;
    uint8_t u8DefaultValue_Gain16;
} tDacSetValue;

typedef struct {
    tDacSetValue dacSetValue;
    eOpaGain opaGainSet : 2;
    _iq15 iq15R34toR3Factor_Gain32;   //1/GAIN
    _iq5 iq5VadcinOffsetCode_Gain32;  //ADC in code with current equals to 0mA
    _iq5 iq5OpaOffsetVolt_Gain32;     //OPA output offset with Gain 32x
    _iq15 iq15ResFactor_Gain32;
    _iq15 iq15R34toR3Factor_Gain16;
    _iq5 iq5VadcinOffsetCode_Gain16;
    _iq5 iq5OpaOffsetVolt_Gain16;  //OPA output offset with Gain 16x
    _iq15 iq15ResFactor_Gain16;
    _iq15 iq15R12toR2Factor;
    _iq15 iq15R12toR1Factor;
    int16_t i16McuTemp;  //Use to tell MCU when to do run time calibration
} tCurtCalcFactors;

//*****************************************************************************
// Capacity learn factors
//*****************************************************************************
typedef struct {
    tStatus ocvCaliRecordFlg : 1;
    tStatus ocvCaliFinishFlg : 1;
    tStatus iGaugeDominationFlg : 1;
    uint8_t u8ClStartCnt : 2;
    uint16_t u16BattRestCounter;
    _iq15 iq15CaliSoc_DEC;
    _iq15 iq15CaliOcv_mV;
    tBattState battStateRecord[3];
    _iq15 iq15VcellRecord[2];
    _iq20 iq20Soc1Data[2];
    _iq20 iq20Soc2Data[2];
    _iq20 iq20SocHatData[2][2];
    _iq20 iq20NomQHatData[2][2];
    _iq15 iq15QmaxHat[3];
    uint16_t u16NomFullCap_mAh;
    uint16_t u16MaxNomFullCap_mAh;  //Used to calculate SOH
    _iq15 iq15DeltaQ_mAh;
    _iq15 iq15SOH_DEC;  //Battery state of health
    tBattState battState;
} tBattCapLearnParams;

//*****************************************************************************
// Mixing factors
//*****************************************************************************
typedef struct {
    tBattState battRTState;
    _iq15 iq15CusRltSoc
        [2];  //The absolute Soc according to the setting of CusEmptyOcv and CusFullOcv_mV
    _iq15 iq15SmoothRltSoc_DEC;  //The final Soc value send to customer
    _iq15 iq15RawSmoothRltSoc_DEC;
    _iq15
        iq15NomAbsSoc_DEC;  //The absolute Soc related to the circuitParamsTable input range
    int16_t i16CusRemCap_mAh;
    uint16_t u16CusFullCap_mAh;
    int16_t i16NomRemCap_mAh;
    _iq15 iq15AbsEmptySocMatrix[MATRIX_ROW_LENGTH * MATRIX_COL_LENGTH];
    _iq15 iq15AbsFullSocMatrix[MATRIX_ROW_LENGTH];
    _iq15 iq15AbsFullSoc;
    _iq15 iq15AbsEmptySoc;
    uint8_t u8FullSocMatrixCount[2];
    uint8_t u8EmptySocMatrixCount[2];
    uint16_t u16VoltRecord[2];
    int16_t i16CurtRecord[2];
    _iq15 iq15AbsSocRecord[2];
    uint16_t u16AvailableHours;
    uint16_t u16AvailableDays;
} tMixingParams;

//*****************************************************************************
// tBattPackParams
//*****************************************************************************
typedef struct {
    _iq15 iq15PackSmoothRltSoc_DEC;  //The final Soc value send to customer
    uint32_t u32PackCusFullCap_mAh;
    int32_t i32PackRemCap_mAh;
    uint32_t u32PackVolt_mV;
    int32_t i32PackCurt_mA;
    _iq15 iq15PackSOH_DEC;
    uint16_t u16PackCycles;
    tWarningFlags packWarningFlag;
} tBattPackParams;

//*****************************************************************************
// One battery related parameters
//*****************************************************************************
typedef struct {
    tBattParamsConfig *pBattParamsCfg;
    tBattInfoInput battInfoInput;
    tBattCapLearnParams capLearnParams;
    tIGaugeCoulometerParams iGaugeParams;
    tMixingParams mixingParams;
    tWarningFlags warningFlag;
} tBattGlobalParams;

//*****************************************************************************
// Global parameters
//*****************************************************************************
typedef struct {
    tStatus sysTikFlag : 1;
    uint8_t u8SysTikShift;  //Real sysTik time = sysTikFreq/u8SysTikShift
    tSystemTikFreq
        sysTikFreq;  //Used as a clock to run algorithm, can be changed by customer to reduce power consumption
    uint8_t ui8NrOfCell;
    tBattGlobalParams **pBattGlobalParamList;
    tCurtCalcFactors curtCalcFactors;
    tBattPackParams battPackParams;
} tGaugeApplication;

#endif
