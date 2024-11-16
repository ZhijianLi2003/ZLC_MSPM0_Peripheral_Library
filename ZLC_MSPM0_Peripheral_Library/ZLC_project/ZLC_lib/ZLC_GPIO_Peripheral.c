/*
 * File: ZLC_GPIO_Peripheral.c
 * ZLC Electronic Design Competition Group（ZLC电赛小组）
 * Zhijian Li,Haoran Chen,Tianyu Zhou
 * Shandong University    2024-10-7
 * Open Source address:https://github.com/ZhijianLi2003/ZLC_MSPM0_Peripheral_Library
 */

#include "ZLC_GPIO_Peripheral.h"

/*******************************************Setting*****************************************/

//Minimum period for GPIO timing control(the unit is ms)
#define  MINIMUM_PERIOD_GPIO      1  
//you should modify the GPIO interface
#define BEEP(x)    ( (x) ? (DL_GPIO_setPins(BEEP_AND_LED_PORT,BEEP_AND_LED_PIN_0_PIN)) : (DL_GPIO_clearPins(BEEP_AND_LED_PORT,BEEP_AND_LED_PIN_0_PIN)) )


/*******************************************Time Control***********************************/

//the sound_time of beep(the unit is ms)
volatile int bee_time = 0;
//This function should be placed in the timer interrupt (1ms)
void GPIO_Time_Control(void)
{
	/****************************************beep_control**********************************/
	if(bee_time > 0)
    {
        bee_time -= MINIMUM_PERIOD_GPIO;
	    BEEP(1);
    }
    else
    {
		BEEP(0);
    }
	
	/*****************************************other_control*********************************/
		
}


