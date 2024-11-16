/*
 * File: ZLC_GPIO_Peripheral.h
 * ZLC Electronic Design Competition Group（ZLC电赛小组）
 * Zhijian Li,Haoran Chen,Tianyu Zhou
 * Shandong University    2024-10-7
 * Open Source address:https://github.com/ZhijianLi2003/ZLC_MSPM0_Peripheral_Library
 */

#ifndef __ZLC_GPIO_PERIPHERAL_H
#define __ZLC_GPIO_PERIPHERAL_H

#include "board.h"
#include "ti_msp_dl_config.h"

//This function should be placed in the timer interrupt
void GPIO_Time_Control(void);

//interfaces that is open to the user
extern volatile int bee_time;           //the sound_time of beep(the unit is ms)


#endif