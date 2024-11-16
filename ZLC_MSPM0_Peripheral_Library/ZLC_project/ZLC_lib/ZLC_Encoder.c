/*
 * File: ZLC_Encoder.c
 * ZLC Electronic Design Competition Group（ZLC电赛小组）
 * Zhijian Li,Haoran Chen,Tianyu Zhou
 * Shandong University    2024-10-7
 * Open Source address:https://github.com/ZhijianLi2003/ZLC_MSPM0_Peripheral_Library
 */
 
#include "ZLC_Encoder.h"

int16_t Encoder_Count_L;   //encoder count of left wheel
int16_t Encoder_Count_R;   //encoder count of right wheel

void Encoder_Init(void)
{
	//or Not
    //NVIC_EnableIRQ(GPIOA_INT_IRQn);
}

/*
 * function: get current left encoder number and clear(This function should be placed in the timer interrupt function)
 * param;    void
 * return:   current encoder number 
 * author:   Zhijian Li
 * date:     2024-07-30
 */
int16_t Encoder_Get_L(void)
{
	int16_t Temp;
	Temp = Encoder_Count_L;
	Encoder_Count_L = 0;
	return Temp;
}

/*
 * function: get current right encoder number and clear(This function should be placed in the timer interrupt function)
 * param;    void
 * return:   current encoder number 
 * author:   Zhijian Li
 * date:     2024-07-30
 */
int16_t Encoder_Get_R(void)
{
	int16_t Temp;
	Temp = Encoder_Count_R;
	Encoder_Count_R = 0;
	return Temp;
}

/*
 * function: External interrupt and orthogonal decoding
 * param;    void
 * return:   no
 * author:   Zhijian Li
 * date:     2024-07-30
 */
void GROUP1_IRQHandler(void)
{
    uint8_t Encodeg_flag,A_flag,B_flag,direction_flag;
	uint8_t Encodeg_flag_R,C_flag,D_flag,direction_flag_R;
	
	switch(DL_Interrupt_getPendingGroup(DL_INTERRUPT_GROUP_1)) 
	{
		case DL_INTERRUPT_GROUP1_IIDX_GPIOA:
		if(DL_GPIO_getEnabledInterruptStatus(GPIOA, Encoder_A_PIN))
		{
            Encodeg_flag = 1;//A中断
            if(DL_GPIO_readPins(GPIOA, Encoder_A_PIN)) A_flag = 1;
            else A_flag = 0;
            if(DL_GPIO_readPins(GPIOA, Encoder_B_PIN)) B_flag = 1;
            else B_flag = 0;
            direction_flag = A_flag+B_flag+Encodeg_flag;                    //Sum to determine the direction of rotation, even forward, odd reverse
            if(direction_flag == 0 || direction_flag ==2)Encoder_Count_L++;
            else Encoder_Count_L--;
            
			DL_GPIO_clearInterruptStatus(GPIOA, Encoder_A_PIN);
		}
		
		
		if(DL_GPIO_getEnabledInterruptStatus(GPIOA, Encoder_B_PIN))
		{
            Encodeg_flag = 0;
            if(DL_GPIO_readPins(GPIOA, Encoder_A_PIN)) A_flag = 1;
            else A_flag = 0;
            if(DL_GPIO_readPins(GPIOA, Encoder_B_PIN)) B_flag = 1;
            else B_flag = 0;
            direction_flag = A_flag+B_flag+Encodeg_flag;
            if(direction_flag == 0 || direction_flag ==2)Encoder_Count_L++;
            else Encoder_Count_L--;
            
			DL_GPIO_clearInterruptStatus(GPIOA, Encoder_B_PIN);
		}
 		
		
		if(DL_GPIO_getEnabledInterruptStatus(GPIOA, Encoder_C_PIN))
		{
            Encodeg_flag_R = 1;
            if(DL_GPIO_readPins(GPIOA, Encoder_C_PIN)) C_flag = 1;
            else C_flag = 0;
            if(DL_GPIO_readPins(GPIOA, Encoder_D_PIN)) D_flag = 1;
            else D_flag = 0;
            direction_flag_R = C_flag+D_flag+Encodeg_flag_R;
            if(direction_flag_R == 0 || direction_flag_R ==2)Encoder_Count_R++;
            else Encoder_Count_R--;
            
			DL_GPIO_clearInterruptStatus(GPIOA, Encoder_C_PIN);
		}
		
		if(DL_GPIO_getEnabledInterruptStatus(GPIOA, Encoder_D_PIN))
		{
            Encodeg_flag_R = 0;
            if(DL_GPIO_readPins(GPIOA, Encoder_C_PIN)) C_flag = 1;
            else C_flag = 0;
            if(DL_GPIO_readPins(GPIOA, Encoder_D_PIN)) D_flag = 1;
            else D_flag = 0;
            direction_flag_R = C_flag+D_flag+Encodeg_flag_R;
            if(direction_flag_R == 0 || direction_flag_R ==2)Encoder_Count_R++;
            else Encoder_Count_R--;
            
			DL_GPIO_clearInterruptStatus(GPIOA, Encoder_D_PIN);
		}
 
		break;
	}
}
