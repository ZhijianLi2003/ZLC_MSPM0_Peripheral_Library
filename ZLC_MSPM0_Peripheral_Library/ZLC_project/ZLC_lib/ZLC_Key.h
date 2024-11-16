/*
 * File: ZLC_Key.h
 * ZLC Electronic Design Competition Group（ZLC电赛小组）
 * Zhijian Li,Haoran Chen,Tianyu Zhou
 * Shandong University    2024-10-7
 * Open Source address:https://github.com/ZhijianLi2003/ZLC_MSPM0_Peripheral_Library
 */


#ifndef __ZLC_KEY_H
#define __ZLC_KEY_H

#include "board.h"
#include "ti_msp_dl_config.h"

extern uint8_t key_1_flag;
extern uint8_t key_2_flag;
extern uint8_t key_3_flag;
extern uint8_t key_4_flag;

void Key_Edge_Scan(void);

#endif