/*
 * File: ZLC_Key.c
 * ZLC Electronic Design Competition Group（ZLC电赛小组）
 * Zhijian Li,Haoran Chen,Tianyu Zhou
 * Shandong University    2024-10-7
 * Open Source address:https://github.com/ZhijianLi2003/ZLC_MSPM0_Peripheral_Library
 */


//Because external interrupts are already occupied by the encoder, keys respond by scanning to prevent collisions
#include "ZLC_Key.h"

//if a key is pressed,these flag will be set 1.
uint8_t key_1_flag = 0;
uint8_t key_2_flag = 0;
uint8_t key_3_flag = 0;
uint8_t key_4_flag = 0;

/*
 * function: Scan keys by scanning IO-down the edge.(This function should be placed in the 10ms or 20ms timer interrupt function)
 * param;    no
 * return:   void
 * author:   Zhijian Li
 * date:     2024-07-30
 */
void Key_Edge_Scan(void)
{
	static int last_high_1;
	static int last_high_2;
	static int last_high_3;
	static int last_high_4;  

	//key_1
	if(last_high_1 == 0)
	{
		if(DL_GPIO_readPins(KEY_PORT,KEY_KEY_1_PIN))
		{
			last_high_1 = 1;
		}
	}
	if(last_high_1 == 1 && (!DL_GPIO_readPins(KEY_PORT,KEY_KEY_1_PIN)))
	{
		if(key_1_flag == 0)
		{
			key_1_flag = 1;
			last_high_1 = 0; 
		}
	}
	
	//key_2
	if(last_high_2 == 0)
	{
		if(DL_GPIO_readPins(KEY_PORT,KEY_KEY_3_PIN))
		{
			last_high_2 = 1;
		}
	}
	if(last_high_2 == 1 && (!DL_GPIO_readPins(KEY_PORT,KEY_KEY_3_PIN)))
	{
		if(key_2_flag == 0)
		{
			key_2_flag = 1;
			last_high_2 = 0; 
		}
	}
		
	//key_3
	if(last_high_3 == 0)
	{
		if(DL_GPIO_readPins(KEY_PORT,KEY_KEY_2_PIN))
		{
			last_high_3 = 1;
		}
	}
	if(last_high_3 == 1 && (!DL_GPIO_readPins(KEY_PORT,KEY_KEY_2_PIN)))
	{
		if(key_3_flag == 0)
		{
			key_3_flag = 1;
			last_high_3 = 0; 
		}
	}
	
    //key_4	
	if(last_high_4 == 0)
	{
		if(DL_GPIO_readPins(KEY_PORT,KEY_KEY_4_PIN))
		{
			last_high_4 = 1;
		}
	}
	if(last_high_4 == 1 && (!DL_GPIO_readPins(KEY_PORT,KEY_KEY_4_PIN)))
	{
		if(key_4_flag == 0)
		{
		   key_4_flag = 1;
		   last_high_4 = 0; 
		}
	}
		
}

/*This is a example of using scan to respond key-pressed.
	if(key_1_flag)
	{
		//you response
		key_1_flag = 0;
	}		
*/


