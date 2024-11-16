/*
 * File: ZLC_Encoder.h
 * ZLC Electronic Design Competition Group（ZLC电赛小组）
 * Zhijian Li,Haoran Chen,Tianyu Zhou
 * Shandong University    2024-10-7
 * Open Source address:https://github.com/ZhijianLi2003/ZLC_MSPM0_Peripheral_Library
 */

#ifndef __ZLC_Encoder_H
#define __ZLC_Encoder_H

#include "board.h"
#include "ti_msp_dl_config.h"

extern int16_t Encoder_Count_L;
extern int16_t Encoder_Count_R;

void Encoder_Init(void);

int16_t Encoder_Get_L(void);
int16_t Encoder_Get_R(void);

#endif