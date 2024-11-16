/*
 * File: ZLC_QuestionTask.h
 * ZLC Electronic Design Competition Group（ZLC电赛小组）
 * Zhijian Li,Haoran Chen,Tianyu Zhou
 * Shandong University    2024-10-7
 * Open Source address:https://github.com/ZhijianLi2003/ZLC_MSPM0_Peripheral_Library
 */

#ifndef __ZLC_QUESTION_TASK_H
#define __ZLC_QUESTION_TASK_H

#include "board.h"
#include "ti_msp_dl_config.h"

//question state definition
#define  STOP_STATE   0
#define  QUESTION_1   1
#define  QUESTION_2   2
#define  QUESTION_3   3
#define  QUESTION_4   4

//State_Machine
struct state_machine
{
    int Main_State;
	int Q1_State;
	int Q2_State;
	int Q3_State;
	int Q4_State;
};

extern struct state_machine State_Machine;
void State_Machine_init(void);
void Question_Task_1(void);
void Question_Task_2(void);
void Question_Task_3(void);
void Question_Task_4(void);

#endif