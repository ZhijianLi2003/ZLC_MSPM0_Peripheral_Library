/*
 * File: ZLC_QuestionTask.c
 * ZLC Electronic Design Competition Group（ZLC电赛小组）
 * Zhijian Li,Haoran Chen,Tianyu Zhou
 * Shandong University    2024-10-7
 * Open Source address:https://github.com/ZhijianLi2003/ZLC_MSPM0_Peripheral_Library
 */

#include "ZLC_QuestionTask.h"
#include "ZLC_Navigation.h"
#include "ZLC_PID.h"
#include "ZLC_Motor.h"
#include "ZLC_GPIO_Peripheral.h"
#include "ZLC_Encoder.h"
#include "ZLC_Servo.h"

//The second level question state definition
#define  Q2_STATE_1   1
#define  Q2_STATE_2   2
#define  Q2_STATE_3   3
#define  Q2_STATE_4   4
#define  Q2_STATE_5   5
#define  Q3_STATE_1   1
#define  Q3_STATE_2   2
#define  Q3_STATE_3   3
#define  Q3_STATE_4   4
#define  Q3_STATE_5   5

struct state_machine State_Machine;

int q1_first_flag = 0;
int q2_first_flag = 0;
int q3_first_flag = 0;
int q4_first_flag = 0;
int q4_circle_num = 0;


void State_Machine_init(void)
{
	State_Machine.Main_State = STOP_STATE;
	State_Machine.Q1_State = STOP_STATE;
	State_Machine.Q2_State = STOP_STATE;
	State_Machine.Q3_State = STOP_STATE;
	State_Machine.Q4_State = STOP_STATE;
}


void Question_Task_1(void)
{
	if(q1_first_flag == 0)
	{
		//记录目标角度
		object_angle = heading_angle_0_360;
		
		//开始积分
		encoder_odometry_flag = 1;
		
		//响铃
		bee_time = 300;
	
		q1_first_flag = 1;
	}
					
	//计算航向偏差
	float Servo_error;
	Servo_error = 3.0*get_minor_arc(object_angle,heading_angle_0_360);
	//设置舵机
	Set_Servo(Dir_PID(Servo_error));
	//设置速度
	Object_Speed = 280;
					
	//任务结束的条件(时间条件?灰度条件?编码条件?都可以)
	if(odometry_sum > 15500 || (black_or_write_check() == BLACK1 && odometry_sum > 4000))
	{
		bee_time = 400;
		State_Machine.Main_State = STOP_STATE;
		//舵机\速度给零
		Set_Servo(0);
		Object_Speed = 0;
		//第一次的变量清零
		q1_first_flag = 0;
		//停止积分,积分清零
		encoder_odometry_flag = 0;
		odometry_sum = 0;
	}
}



void Question_Task_2(void)
{
	if(q2_first_flag == 0)
	{
		//记录目标角度
		object_angle = heading_angle_0_360;
		//记录第一次发车的角度
		first_angle = heading_angle_0_360;
		//开始积分
		encoder_odometry_flag = 1;
		//响铃
		bee_time = 300;
		//开始问题2的小状态机
		State_Machine.Q2_State = Q2_STATE_1;
		
		q2_first_flag = 1;
	}
	if(State_Machine.Q2_State == Q2_STATE_1)  //问题2的状态1(跑直)
	{
		//跑直
		float Servo_error;
		Servo_error = 2.5*get_minor_arc(object_angle,heading_angle_0_360);
		//设置舵机
		Set_Servo(Dir_PID(Servo_error));
		//设置速度
		Object_Speed = 250;
		//设置出口
		if(odometry_sum > 15500 ||(black_or_write_check() == BLACK1 && odometry_sum > 4000))
		{
			bee_time = 300;
			//停止积分
			encoder_odometry_flag = 0;
			odometry_sum = 0;
			//进入问题2的下一个状态
			State_Machine.Q2_State = Q2_STATE_2;
		}
	}
	else if(State_Machine.Q2_State == Q2_STATE_2) // 问题2的状态2(右转灰度循迹)
	{
		//设置速度
		Object_Speed = 200;
		
		//右转优先的灰度循迹
		float Servo_error = super_black_tracking(RIGHT_PROI);
		
		//设置舵机
		Set_Servo(Servo_error);
		
		//退出判断
		if((heading_angle_0_360 > 170 && heading_angle_0_360 < 250) && black_or_write_check() == WRITE2)
		{
			bee_time = 300;
			//进入问题2的下一个状态
			State_Machine.Q2_State = Q2_STATE_3;
		}
	}
	else if(State_Machine.Q2_State == Q2_STATE_3)  //问题2的状态3(跑直)
	{
		static int Q2_state3_first_flag = 0;
		if(Q2_state3_first_flag == 0)
		{
			 //开始积分
			 encoder_odometry_flag = 1;
			 Q2_state3_first_flag = 1;
		}
	
		//设置速度
		Object_Speed = 250;
		//跑直
		float Servo_error;
		//获取目标角度
		object_angle = navigetion_0_360_limit(first_angle + 181);
		Servo_error = 2.5*get_minor_arc(object_angle,heading_angle_0_360);
		//设置舵机
		Set_Servo(Dir_PID(Servo_error));
		//退出判断
		if(odometry_sum > 18500 || black_or_write_check() == BLACK1)
		{
			bee_time = 300;
			//停止积分,积分清零
			encoder_odometry_flag = 0;
			odometry_sum = 0;
			//进入问题2的下一个状态
			State_Machine.Q2_State = Q2_STATE_4;
		}
	}
	else if(State_Machine.Q2_State == Q2_STATE_4)  //问题2的状态3(右转灰度循迹)
	{
		//设置速度
		Object_Speed = 200;
		
		//右转优先的灰度循迹
		float Servo_error = super_black_tracking(RIGHT_PROI);
		
		//设置舵机
		Set_Servo(Servo_error);
		
		//退出判断
		if((heading_angle_0_360 > 330 ||  heading_angle_0_360 < 90) &&  black_or_write_check() == WRITE2)
		{
			bee_time = 300;
			//进入问题2的下一个状态
			State_Machine.Q2_State = Q2_STATE_5;
		}
	}
	else
	{
		//退出当前题目
		State_Machine.Q2_State = STOP_STATE;
		State_Machine.Main_State = STOP_STATE;
		//专属问题2的变量清零
		q2_first_flag = 0;
	}
}






void Question_Task_3(void)
{
	if(q3_first_flag == 0)
	{
		//记录第一次发车的角度
		first_angle = heading_angle_0_360;
		//开始积分
		encoder_odometry_flag = 1;
		//响铃
		bee_time = 300;
		//开始问题3的小状态机
		State_Machine.Q3_State = Q3_STATE_1;
		
		q3_first_flag = 1;
	}
	if(State_Machine.Q3_State == Q3_STATE_1)
	{
		//设置速度
		Object_Speed = 300;
		
		//记录斜切目标角度
		object_angle = navigetion_0_360_limit(first_angle + 39.66);
		float Servo_error;
		Servo_error = 1.5*get_minor_arc(object_angle,heading_angle_0_360);
		
		//设置舵机
		Set_Servo(Dir_PID(Servo_error));
		
		//任务结束的条件(时间条件?灰度条件?编码条件?)
		if(odometry_sum > 26000 || (black_or_write_check() == BLACK1 && odometry_sum > 4000))   
		{
			bee_time = 300;
			//停止积分
			encoder_odometry_flag = 0;
			odometry_sum = 0;
			//进入问题3的下一个状态
			State_Machine.Q3_State = Q3_STATE_2;
		
		 }
	}
	else if(State_Machine.Q3_State == Q3_STATE_2)   //问题3的状态2(左转灰度循迹)
	{
		static int Q3_state2_first_flag = 0;
		if(Q3_state2_first_flag == 0)
		{
			//利用航向角硬切入黑线(50度)
			object_angle = navigetion_0_360_limit(heading_angle_0_360 - 60);
			Q3_state2_first_flag = 1;
		}
		
		if(heading_angle_0_360 > 100 && heading_angle_0_360 < object_angle)     //正常的灰度循迹
		{
			float Servo_error = super_black_tracking(LEFT_PROI);
	
			//设置舵机
			Set_Servo(Servo_error);
			//设置速度
			Object_Speed = 250;
		}		
		else                                                                    //利用航向角硬切入黑线(50度)
		{
			float Servo_error;
			Servo_error = 4.5 * get_minor_arc(object_angle,heading_angle_0_360);
			//设置舵机
			Set_Servo(Dir_PID(Servo_error));
			Object_Speed = 200;
			bee_time = 300;
		}												

		//退出判断
		if((heading_angle_0_360 < 200 &&  heading_angle_0_360 > 100) &&  black_or_write_check() == WRITE2)
		{
			bee_time = 300;
			Q3_state2_first_flag = 0;
			State_Machine.Q3_State = Q3_STATE_3;
		}			
	}
	else if(State_Machine.Q3_State == Q3_STATE_3)
	{
		static int Q3_state3_first_flag = 0;
		if(Q3_state3_first_flag == 0)
		{
			object_angle =navigetion_0_360_limit(first_angle + 180) - 44.66;
			Q3_state3_first_flag = 1;
		}
		//设置速度
		Object_Speed = 280;
	
		float Servo_error;
		Servo_error = 1.5*get_minor_arc(object_angle,heading_angle_0_360);
		//设置舵机
		Set_Servo(Dir_PID(Servo_error));
		
		//退出判断
		if(odometry_sum > 25500 || black_or_write_check() == BLACK1)
		{
			bee_time = 300;
			//停止积分
			encoder_odometry_flag = 0;
			odometry_sum = 0;
			Q3_state3_first_flag = 0;
			State_Machine.Q3_State = Q3_STATE_4;
		}
	}
	else if(State_Machine.Q3_State == Q3_STATE_4)
	{
		static int Q3_state4_first_flag = 0;
		if(Q3_state4_first_flag == 0)
		{
			object_angle = navigetion_0_360_limit(heading_angle_0_360 + 60);
			Q3_state4_first_flag = 1;
		}
		
		
		if(heading_angle_0_360 > object_angle)
		{
			float Servo_error = super_black_tracking(RIGHT_PROI);
	
			//设置舵机
			Set_Servo(Servo_error);
		
			//设置速度
			Object_Speed = 250;
		}		
		else 
		{
			float Servo_error;
			Servo_error = 4.0 * get_minor_arc(object_angle,heading_angle_0_360);
			//设置舵机
			Set_Servo(Dir_PID(Servo_error));
			Object_Speed = 200;
			bee_time = 300;
		}	
		
		//退出判断
		if((heading_angle_0_360 > 335 ||  heading_angle_0_360 < 90) &&  black_or_write_check() == WRITE2)
		{
			bee_time = 300;
			Q3_state4_first_flag = 0;
			State_Machine.Q3_State = Q3_STATE_5;
		}
	}
	else
	{
		//退出当前题目
		State_Machine.Q3_State = STOP_STATE;
		State_Machine.Main_State = STOP_STATE;
		//专属问题3的变量清零
		q3_first_flag = 0;
	}
}


void Question_Task_4(void)
{
	if(q4_first_flag == 0)
	{		
		//记录第一次发车的角度
		first_angle = heading_angle_0_360;
		//开始积分
		encoder_odometry_flag = 1;
		//响铃
		bee_time = 300;
		//开始问题3的小状态机
		State_Machine.Q3_State = Q3_STATE_1;
		
		q4_first_flag = 1;
	}
	if(State_Machine.Q3_State == Q3_STATE_1)
	{
		if(q4_circle_num == 0)
		{
			object_angle = navigetion_0_360_limit(first_angle + 39.66);
		}
		else
		{
			object_angle = navigetion_0_360_limit(first_angle + 41.66);
		}
		
		float Servo_error;
		Servo_error = 1.5*get_minor_arc(object_angle,heading_angle_0_360);
		
		//设置舵机
		Set_Servo(Dir_PID(Servo_error));
		
		//根据里程加减速设置速度
		if(odometry_sum < 12300)
		{
			Object_Speed = 390;		
		}
		else
		{
		    Object_Speed = 220;
		}
		
		//任务结束的条件(时间条件?灰度条件?编码条件?)
		if(odometry_sum > 26000 || (black_or_write_check() == BLACK1 && odometry_sum > 4000))   
		{
			bee_time = 300;
			//停止积分
			encoder_odometry_flag = 0;
			odometry_sum = 0;
			//进入问题3的下一个状态
			State_Machine.Q3_State = Q3_STATE_2;
		
		 }
	}
	else if(State_Machine.Q3_State == Q3_STATE_2)   //问题3的状态2(左转灰度循迹)
	{
		static int Q3_state2_first_flag = 0;
		if(Q3_state2_first_flag == 0)
		{
			//利用航向角硬切入黑线(50度)
			object_angle = navigetion_0_360_limit(heading_angle_0_360 - 60);
			Q3_state2_first_flag = 1;
		}
		
		if(heading_angle_0_360 > 100 && heading_angle_0_360 < object_angle)     //正常的灰度循迹
		{
			float Servo_error = super_black_tracking(LEFT_PROI);
	
			//设置舵机
			Set_Servo(Servo_error);
			//设置速度
			Object_Speed = 300;
		}		
		else                                                                    //利用航向角硬切入黑线(50度)
		{
			float Servo_error;
			Servo_error = 4.5 * get_minor_arc(object_angle,heading_angle_0_360);
			//设置舵机
			Set_Servo(Dir_PID(Servo_error));
			Object_Speed = 220;
			bee_time = 300;
		}												

		//退出判断
		if((heading_angle_0_360 < 200 &&  heading_angle_0_360 > 100) &&  black_or_write_check() == WRITE2)
		{
			bee_time = 300;
			Q3_state2_first_flag = 0;
			State_Machine.Q3_State = Q3_STATE_3;
		}			
	}
	else if(State_Machine.Q3_State == Q3_STATE_3)
	{
		static int Q3_state3_first_flag = 0;
		if(Q3_state3_first_flag == 0)
		{
			if(q4_circle_num == 0)
			{
				object_angle =navigetion_0_360_limit(first_angle + 180) - 42.66;
			}
			else
			{
				object_angle =navigetion_0_360_limit(first_angle + 180) - 42.66;
			}
			
			
			Q3_state3_first_flag = 1;
		}
		//根据里程加减速设置速度
		if(odometry_sum < 11500)
		{
			Object_Speed = 390;		
		}
		else
		{
		    Object_Speed = 220;
		}
	
		float Servo_error;
		Servo_error = 1.5*get_minor_arc(object_angle,heading_angle_0_360);
		//设置舵机
		Set_Servo(Dir_PID(Servo_error));
		
		//退出判断
		if(odometry_sum > 25500 || black_or_write_check() == BLACK1)
		{
			bee_time = 300;
			//停止积分
			encoder_odometry_flag = 0;
			odometry_sum = 0;
			Q3_state3_first_flag = 0;
			State_Machine.Q3_State = Q3_STATE_4;
		}
	}
	else if(State_Machine.Q3_State == Q3_STATE_4)
	{
		static int Q3_state4_first_flag = 0;
		if(Q3_state4_first_flag == 0)
		{
			object_angle = navigetion_0_360_limit(heading_angle_0_360 + 60);
			Q3_state4_first_flag = 1;
		}
		
		
		if(heading_angle_0_360 > object_angle)
		{
			float Servo_error = super_black_tracking(RIGHT_PROI);
	
			//设置舵机
			Set_Servo(Servo_error);
		
			//设置速度
			Object_Speed = 300;
		}		
		else 
		{
			float Servo_error;
			Servo_error = 4.5 * get_minor_arc(object_angle,heading_angle_0_360);
			//设置舵机
			Set_Servo(Dir_PID(Servo_error));
			Object_Speed = 220;
			bee_time = 300;
		}	
		
		//退出判断
		if((heading_angle_0_360 > 335 ||  heading_angle_0_360 < 90) &&  black_or_write_check() == WRITE2)
		{
			bee_time = 300;
			Q3_state4_first_flag = 0;
			State_Machine.Q3_State = Q3_STATE_5;
		}
	}
	else
	{
		//退出当前题目
		q4_circle_num++;
		if(q4_circle_num >= 4)
		{
			State_Machine.Main_State = STOP_STATE;
			//专属问题3的变量清零
		    q4_first_flag = 0;
		}
		State_Machine.Q3_State = Q3_STATE_1;
		//开始积分
		encoder_odometry_flag = 1;
	}
}
