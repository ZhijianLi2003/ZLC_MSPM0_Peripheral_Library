/*
 * File: ZLC_Motor.h
 * ZLC Electronic Design Competition Group（ZLC电赛小组）
 * Zhijian Li,Haoran Chen,Tianyu Zhou
 * Shandong University    2024-10-7
 * Open Source address:https://github.com/ZhijianLi2003/ZLC_MSPM0_Peripheral_Library
 */
 
#ifndef __ZLC_Motor_H
#define __ZLC_Motor_H

#include "board.h"
#include "ti_msp_dl_config.h"

void Motor_Init(void);
void Set_Left_Speed(int duty);
void Set_Right_Speed(int duty);

#endif
