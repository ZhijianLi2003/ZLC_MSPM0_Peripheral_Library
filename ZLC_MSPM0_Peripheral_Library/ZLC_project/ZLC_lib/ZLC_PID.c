/*
 * File: ZLC_PID.c
 * ZLC Electronic Design Competition Group（ZLC电赛小组）
 * Zhijian Li,Haoran Chen,Tianyu Zhou
 * Shandong University    2024-10-7
 * Open Source address:https://github.com/ZhijianLi2003/ZLC_MSPM0_Peripheral_Library
 */

#include "ZLC_PID.h"

/*************************************************PD Control of direction********************************************/

float dir_kp = 4.0,dir_kd = 1.0;
float last_error = 0;

/*
 * function: PD Control of direction
 * param;    the current deviation from the target
 * return:   PWM high level time(0-20000) of steer
 * author:   Zhijian Li
 * date:     2024-07-30
 */
float Dir_PID(float error)
{
	float result = 0;
	result = dir_kp * error + dir_kd * (error - last_error);
	last_error = error;
	return result;
}


/*************************************************PI Control of Speed********************************************/
//Target speed of the closed loop
int Object_Speed = 0;

//the speed currently measured
int LC_Speed = 0;
int RC_Speed = 0;

//Related speed PI parameters 
float Velcity_Klp=2.5, Velcity_Krp=2.5, Velcity_Kli=1.0, Velcity_Kri = 1.0, Velcity_Kd; 

/*
 * function: Left wheel speed loop
 * param;    TargetVelocity and CurrentVelocity(The unit is the unit of the encoder)
 * return:   PWM high level time(0-20000) of motor
 * author:   Zhijian Li
 * date:     2024-07-30
 */
int Velocity_L(int TargetVelocity, int CurrentVelocity)
{
	int Bias;                                                          //define correlation variables
	static int ControlVelocity, Last_bias;                             //A static variable whose value persists after the function call ends
	
	Bias=TargetVelocity-CurrentVelocity;                               //get velocity deviation
	
	ControlVelocity += Velcity_Klp*(Bias-Last_bias)+Velcity_Kli*Bias;  //Incremental PI controller

	Last_bias=Bias;	
	
	//Speed limit
	ControlVelocity=ControlVelocity>1200?1200:(ControlVelocity<-1200?(-1200):ControlVelocity); 
	return ControlVelocity;                                            //returns the speed control value
	
}


/*
 * function: Right wheel speed loop
 * param;    TargetVelocity and CurrentVelocity(The unit is the unit of the encoder)
 * return:   PWM high level time(0-20000) of motor
 * author:   Zhijian Li
 * date:     2024-07-30
 */
int Velocity_R(int TargetVelocity, int CurrentVelocity)
{
	int Bias;                                                           //define correlation variables
	static int ControlVelocity, Last_bias;                              //A static variable whose value persists after the function call ends
	
	Bias=TargetVelocity-CurrentVelocity;                                //get velocity deviation
	
	ControlVelocity+=Velcity_Krp*(Bias-Last_bias)+Velcity_Kri*Bias;     //Incremental PI controller
							  							
	Last_bias=Bias;	
	//Speed limit
	ControlVelocity=ControlVelocity>1200?1200:(ControlVelocity<-1200?(-1200):ControlVelocity); 

	return ControlVelocity;                                             //returns the speed control value
}

