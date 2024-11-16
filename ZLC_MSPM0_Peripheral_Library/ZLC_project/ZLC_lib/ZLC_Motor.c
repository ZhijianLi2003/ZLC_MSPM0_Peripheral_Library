/*
 * File: ZLC_Motor.c
 * ZLC Electronic Design Competition Group（ZLC电赛小组）
 * Zhijian Li,Haoran Chen,Tianyu Zhou
 * Shandong University    2024-10-7
 * Open Source address:https://github.com/ZhijianLi2003/ZLC_MSPM0_Peripheral_Library
 */

#include "ZLC_Motor.h"

//The code driver scheme corresponding to this file is DRV8701E scheme
#define PWM_DUTY_MAX        ( 2133 )                                            // The maximum value of PWM

#define DRV8701E_DIR_LEFT(x)    ((x) ? (DL_GPIO_setPins(MOTOR_DIR1_PORT, MOTOR_DIR1_PIN_26_PIN)) : (DL_GPIO_clearPins(MOTOR_DIR1_PORT, MOTOR_DIR1_PIN_26_PIN)) )
#define DRV8701E_DIR_RIGHT(x)    ((x) ? (DL_GPIO_setPins(MOTOR_DIR2_PORT, MOTOR_DIR2_PIN_27_PIN)) : (DL_GPIO_clearPins(MOTOR_DIR2_PORT, MOTOR_DIR2_PIN_27_PIN)) )

#define DRV8701E_PWM_LEFT(x)    (DL_TimerG_setCaptureCompareValue(PWM_FOR_MOTOR_INST, x, GPIO_PWM_FOR_MOTOR_C0_IDX))
#define DRV8701E_PWM_RIGHT(x)    (DL_TimerG_setCaptureCompareValue(PWM_FOR_MOTOR_INST, x, GPIO_PWM_FOR_MOTOR_C1_IDX))

void Motor_Init(void)
{
	//Or not
    //DL_Timer_startCounter(PWM_FOR_MOTOR_INST);
}

/*
 * function: Set PWM high level time(0-2133) of left motor
 * param;    duty value(0-max)
 * return:   void
 * author:   Zhijian Li
 * date:     2024-07-30
 */
void Set_Left_Speed(int duty)
{
	int max =  PWM_DUTY_MAX - 30;
	duty=duty>max?max:(duty<-max?(-max):duty); 
	if(duty >= 0)
	{
		//direction
		DRV8701E_DIR_LEFT(0);
		//speed
		DRV8701E_PWM_LEFT(duty); 
		
	}
	else
	{
		//direction
	    DRV8701E_DIR_LEFT(1);
		//speed
		DRV8701E_PWM_LEFT(-duty);
	}
}

/*
 * function: Set PWM high level time(0-2133) of right motor
 * param;    duty value(0-max)
 * return:   void
 * author:   Zhijian Li
 * date:     2024-07-30
 */
void Set_Right_Speed(int duty)
{
	int max =  PWM_DUTY_MAX - 30;
	duty=duty>max?max:(duty<-max?(-max):duty); 
	if(duty >= 0)
	{
		//direction
		DRV8701E_DIR_RIGHT(0);
		//speed
		DRV8701E_PWM_RIGHT(duty);
		
	}
	else
	{
		//direction
		DRV8701E_DIR_RIGHT(1);
		//speed
		DRV8701E_PWM_RIGHT(-duty);
	}
}


