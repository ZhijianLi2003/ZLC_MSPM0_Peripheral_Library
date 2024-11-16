/*
 * File: ZLC_PID.h
 * ZLC Electronic Design Competition Group（ZLC电赛小组）
 * Zhijian Li,Haoran Chen,Tianyu Zhou
 * Shandong University    2024-10-7
 * Open Source address:https://github.com/ZhijianLi2003/ZLC_MSPM0_Peripheral_Library
 */

#ifndef __ZLC_PID_H
#define __ZLC_PID_H

#include "board.h"
#include "ti_msp_dl_config.h"

//PD control of direction
float Dir_PID(float error);
extern float last_error;

//PI Control of Speed
extern int Object_Speed;
extern int LC_Speed;
extern int RC_Speed;
int Velocity_L(int TargetVelocity, int CurrentVelocity);
int Velocity_R(int TargetVelocity, int CurrentVelocity);


#endif