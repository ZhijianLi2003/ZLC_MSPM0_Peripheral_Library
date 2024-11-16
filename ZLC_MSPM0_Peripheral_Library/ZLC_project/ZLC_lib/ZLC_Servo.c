/*
 * File: ZLC_Servo.c
 * ZLC Electronic Design Competition Group（ZLC电赛小组）
 * Zhijian Li,Haoran Chen,Tianyu Zhou
 * Shandong University    2024-10-7
 * Open Source address:https://github.com/ZhijianLi2003/ZLC_MSPM0_Peripheral_Library
 */
#include "ZLC_Servo.h"

//Suitable steering 
//angle supporting:0-180
//Driving frequency/Time cycle:50Hz / 20ms
//supporting high level time:0.5ms-2.5ms

void Sever_Init(void)
{
	//Or not
    //DL_Timer_startCounter(PWM_FOR_SERVO_INST);
}


/* function name: Servo_Angle_Ctrl
 * param: the angle of servo which you want to set（0-180）
 * danger: Many smart cars have a smaller Angle range than 0-180 degrees! 
 * author:   Zhijian Li
 */
void Servo_Angle_Ctrl (float angle)
{
    float duty = 0;
    duty = angle / 180 * 2000.0 + 500;
	DL_TimerG_setCaptureCompareValue(PWM_FOR_SERVO_INST, (uint32_t)duty, GPIO_PWM_FOR_SERVO_C0_IDX);
}


/* function name: Set_Servo
 * param: direct_out(direct_control)
 *        		Turn left  > 0
 *        		Turn right < 0
 * author:   Zhijian Li
 */
void Set_Servo(float direct_out)
{
    uint32_t tmp;
    tmp = (int)(SERVO_MID + direct_out);
    //Output limiting
    if(tmp >= SERVO_MAX_PWM)
        tmp = SERVO_MAX_PWM;
    if(tmp <= SERVO_MIN_PWM)
        tmp = SERVO_MIN_PWM;

    //Set the duty cycle
	DL_TimerG_setCaptureCompareValue(PWM_FOR_SERVO_INST, (uint32_t)tmp, GPIO_PWM_FOR_SERVO_C0_IDX);
}

