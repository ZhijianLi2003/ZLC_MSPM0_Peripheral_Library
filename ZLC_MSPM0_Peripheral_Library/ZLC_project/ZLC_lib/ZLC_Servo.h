/*
 * File: ZLC_Servo.h
 * ZLC Electronic Design Competition Group（ZLC电赛小组）
 * Zhijian Li,Haoran Chen,Tianyu Zhou
 * Shandong University    2024-10-7
 * Open Source address:https://github.com/ZhijianLi2003/ZLC_MSPM0_Peripheral_Library
 */

#ifndef __ZLC_Sever_H_
#define __ZLC_Sever_H_

#include "board.h"
#include "ti_msp_dl_config.h"

//For a four-wheel racing car, the median and edge values of the steering gear are very, very important!!!
//For a four-wheel racing car, the median and edge values of the steering gear are very, very important!!!
//For a four-wheel racing car, the median and edge values of the steering gear are very, very important!!!

//Ackermann steering parameters
#define SERVO_MAX_PWM       1872                  //LEFT_EDGE_VALUE(the value when front wheel is on the far left)
#define SERVO_MIN_PWM       1525                  //RIGHT_EDGE_VALUE(the value when front wheel is on the far right)
#define SERVO_MID           1702                  //MID_VALUE(the value when front wheel is in the middle)

void Servo_Angle_Ctrl (float angle);
void Set_Servo(float direct_out);


#endif