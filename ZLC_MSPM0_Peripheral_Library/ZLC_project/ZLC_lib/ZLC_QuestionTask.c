/*
 * File: ZLC_QuestionTask.c
 * ZLC Electronic Design Competition Group��ZLC����С�飩
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
		//��¼Ŀ��Ƕ�
		object_angle = heading_angle_0_360;
		
		//��ʼ����
		encoder_odometry_flag = 1;
		
		//����
		bee_time = 300;
	
		q1_first_flag = 1;
	}
					
	//���㺽��ƫ��
	float Servo_error;
	Servo_error = 3.0*get_minor_arc(object_angle,heading_angle_0_360);
	//���ö��
	Set_Servo(Dir_PID(Servo_error));
	//�����ٶ�
	Object_Speed = 280;
					
	//�������������(ʱ������?�Ҷ�����?��������?������)
	if(odometry_sum > 15500 || (black_or_write_check() == BLACK1 && odometry_sum > 4000))
	{
		bee_time = 400;
		State_Machine.Main_State = STOP_STATE;
		//���\�ٶȸ���
		Set_Servo(0);
		Object_Speed = 0;
		//��һ�εı�������
		q1_first_flag = 0;
		//ֹͣ����,��������
		encoder_odometry_flag = 0;
		odometry_sum = 0;
	}
}



void Question_Task_2(void)
{
	if(q2_first_flag == 0)
	{
		//��¼Ŀ��Ƕ�
		object_angle = heading_angle_0_360;
		//��¼��һ�η����ĽǶ�
		first_angle = heading_angle_0_360;
		//��ʼ����
		encoder_odometry_flag = 1;
		//����
		bee_time = 300;
		//��ʼ����2��С״̬��
		State_Machine.Q2_State = Q2_STATE_1;
		
		q2_first_flag = 1;
	}
	if(State_Machine.Q2_State == Q2_STATE_1)  //����2��״̬1(��ֱ)
	{
		//��ֱ
		float Servo_error;
		Servo_error = 2.5*get_minor_arc(object_angle,heading_angle_0_360);
		//���ö��
		Set_Servo(Dir_PID(Servo_error));
		//�����ٶ�
		Object_Speed = 250;
		//���ó���
		if(odometry_sum > 15500 ||(black_or_write_check() == BLACK1 && odometry_sum > 4000))
		{
			bee_time = 300;
			//ֹͣ����
			encoder_odometry_flag = 0;
			odometry_sum = 0;
			//��������2����һ��״̬
			State_Machine.Q2_State = Q2_STATE_2;
		}
	}
	else if(State_Machine.Q2_State == Q2_STATE_2) // ����2��״̬2(��ת�Ҷ�ѭ��)
	{
		//�����ٶ�
		Object_Speed = 200;
		
		//��ת���ȵĻҶ�ѭ��
		float Servo_error = super_black_tracking(RIGHT_PROI);
		
		//���ö��
		Set_Servo(Servo_error);
		
		//�˳��ж�
		if((heading_angle_0_360 > 170 && heading_angle_0_360 < 250) && black_or_write_check() == WRITE2)
		{
			bee_time = 300;
			//��������2����һ��״̬
			State_Machine.Q2_State = Q2_STATE_3;
		}
	}
	else if(State_Machine.Q2_State == Q2_STATE_3)  //����2��״̬3(��ֱ)
	{
		static int Q2_state3_first_flag = 0;
		if(Q2_state3_first_flag == 0)
		{
			 //��ʼ����
			 encoder_odometry_flag = 1;
			 Q2_state3_first_flag = 1;
		}
	
		//�����ٶ�
		Object_Speed = 250;
		//��ֱ
		float Servo_error;
		//��ȡĿ��Ƕ�
		object_angle = navigetion_0_360_limit(first_angle + 181);
		Servo_error = 2.5*get_minor_arc(object_angle,heading_angle_0_360);
		//���ö��
		Set_Servo(Dir_PID(Servo_error));
		//�˳��ж�
		if(odometry_sum > 18500 || black_or_write_check() == BLACK1)
		{
			bee_time = 300;
			//ֹͣ����,��������
			encoder_odometry_flag = 0;
			odometry_sum = 0;
			//��������2����һ��״̬
			State_Machine.Q2_State = Q2_STATE_4;
		}
	}
	else if(State_Machine.Q2_State == Q2_STATE_4)  //����2��״̬3(��ת�Ҷ�ѭ��)
	{
		//�����ٶ�
		Object_Speed = 200;
		
		//��ת���ȵĻҶ�ѭ��
		float Servo_error = super_black_tracking(RIGHT_PROI);
		
		//���ö��
		Set_Servo(Servo_error);
		
		//�˳��ж�
		if((heading_angle_0_360 > 330 ||  heading_angle_0_360 < 90) &&  black_or_write_check() == WRITE2)
		{
			bee_time = 300;
			//��������2����һ��״̬
			State_Machine.Q2_State = Q2_STATE_5;
		}
	}
	else
	{
		//�˳���ǰ��Ŀ
		State_Machine.Q2_State = STOP_STATE;
		State_Machine.Main_State = STOP_STATE;
		//ר������2�ı�������
		q2_first_flag = 0;
	}
}






void Question_Task_3(void)
{
	if(q3_first_flag == 0)
	{
		//��¼��һ�η����ĽǶ�
		first_angle = heading_angle_0_360;
		//��ʼ����
		encoder_odometry_flag = 1;
		//����
		bee_time = 300;
		//��ʼ����3��С״̬��
		State_Machine.Q3_State = Q3_STATE_1;
		
		q3_first_flag = 1;
	}
	if(State_Machine.Q3_State == Q3_STATE_1)
	{
		//�����ٶ�
		Object_Speed = 300;
		
		//��¼б��Ŀ��Ƕ�
		object_angle = navigetion_0_360_limit(first_angle + 39.66);
		float Servo_error;
		Servo_error = 1.5*get_minor_arc(object_angle,heading_angle_0_360);
		
		//���ö��
		Set_Servo(Dir_PID(Servo_error));
		
		//�������������(ʱ������?�Ҷ�����?��������?)
		if(odometry_sum > 26000 || (black_or_write_check() == BLACK1 && odometry_sum > 4000))   
		{
			bee_time = 300;
			//ֹͣ����
			encoder_odometry_flag = 0;
			odometry_sum = 0;
			//��������3����һ��״̬
			State_Machine.Q3_State = Q3_STATE_2;
		
		 }
	}
	else if(State_Machine.Q3_State == Q3_STATE_2)   //����3��״̬2(��ת�Ҷ�ѭ��)
	{
		static int Q3_state2_first_flag = 0;
		if(Q3_state2_first_flag == 0)
		{
			//���ú����Ӳ�������(50��)
			object_angle = navigetion_0_360_limit(heading_angle_0_360 - 60);
			Q3_state2_first_flag = 1;
		}
		
		if(heading_angle_0_360 > 100 && heading_angle_0_360 < object_angle)     //�����ĻҶ�ѭ��
		{
			float Servo_error = super_black_tracking(LEFT_PROI);
	
			//���ö��
			Set_Servo(Servo_error);
			//�����ٶ�
			Object_Speed = 250;
		}		
		else                                                                    //���ú����Ӳ�������(50��)
		{
			float Servo_error;
			Servo_error = 4.5 * get_minor_arc(object_angle,heading_angle_0_360);
			//���ö��
			Set_Servo(Dir_PID(Servo_error));
			Object_Speed = 200;
			bee_time = 300;
		}												

		//�˳��ж�
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
		//�����ٶ�
		Object_Speed = 280;
	
		float Servo_error;
		Servo_error = 1.5*get_minor_arc(object_angle,heading_angle_0_360);
		//���ö��
		Set_Servo(Dir_PID(Servo_error));
		
		//�˳��ж�
		if(odometry_sum > 25500 || black_or_write_check() == BLACK1)
		{
			bee_time = 300;
			//ֹͣ����
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
	
			//���ö��
			Set_Servo(Servo_error);
		
			//�����ٶ�
			Object_Speed = 250;
		}		
		else 
		{
			float Servo_error;
			Servo_error = 4.0 * get_minor_arc(object_angle,heading_angle_0_360);
			//���ö��
			Set_Servo(Dir_PID(Servo_error));
			Object_Speed = 200;
			bee_time = 300;
		}	
		
		//�˳��ж�
		if((heading_angle_0_360 > 335 ||  heading_angle_0_360 < 90) &&  black_or_write_check() == WRITE2)
		{
			bee_time = 300;
			Q3_state4_first_flag = 0;
			State_Machine.Q3_State = Q3_STATE_5;
		}
	}
	else
	{
		//�˳���ǰ��Ŀ
		State_Machine.Q3_State = STOP_STATE;
		State_Machine.Main_State = STOP_STATE;
		//ר������3�ı�������
		q3_first_flag = 0;
	}
}


void Question_Task_4(void)
{
	if(q4_first_flag == 0)
	{		
		//��¼��һ�η����ĽǶ�
		first_angle = heading_angle_0_360;
		//��ʼ����
		encoder_odometry_flag = 1;
		//����
		bee_time = 300;
		//��ʼ����3��С״̬��
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
		
		//���ö��
		Set_Servo(Dir_PID(Servo_error));
		
		//������̼Ӽ��������ٶ�
		if(odometry_sum < 12300)
		{
			Object_Speed = 390;		
		}
		else
		{
		    Object_Speed = 220;
		}
		
		//�������������(ʱ������?�Ҷ�����?��������?)
		if(odometry_sum > 26000 || (black_or_write_check() == BLACK1 && odometry_sum > 4000))   
		{
			bee_time = 300;
			//ֹͣ����
			encoder_odometry_flag = 0;
			odometry_sum = 0;
			//��������3����һ��״̬
			State_Machine.Q3_State = Q3_STATE_2;
		
		 }
	}
	else if(State_Machine.Q3_State == Q3_STATE_2)   //����3��״̬2(��ת�Ҷ�ѭ��)
	{
		static int Q3_state2_first_flag = 0;
		if(Q3_state2_first_flag == 0)
		{
			//���ú����Ӳ�������(50��)
			object_angle = navigetion_0_360_limit(heading_angle_0_360 - 60);
			Q3_state2_first_flag = 1;
		}
		
		if(heading_angle_0_360 > 100 && heading_angle_0_360 < object_angle)     //�����ĻҶ�ѭ��
		{
			float Servo_error = super_black_tracking(LEFT_PROI);
	
			//���ö��
			Set_Servo(Servo_error);
			//�����ٶ�
			Object_Speed = 300;
		}		
		else                                                                    //���ú����Ӳ�������(50��)
		{
			float Servo_error;
			Servo_error = 4.5 * get_minor_arc(object_angle,heading_angle_0_360);
			//���ö��
			Set_Servo(Dir_PID(Servo_error));
			Object_Speed = 220;
			bee_time = 300;
		}												

		//�˳��ж�
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
		//������̼Ӽ��������ٶ�
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
		//���ö��
		Set_Servo(Dir_PID(Servo_error));
		
		//�˳��ж�
		if(odometry_sum > 25500 || black_or_write_check() == BLACK1)
		{
			bee_time = 300;
			//ֹͣ����
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
	
			//���ö��
			Set_Servo(Servo_error);
		
			//�����ٶ�
			Object_Speed = 300;
		}		
		else 
		{
			float Servo_error;
			Servo_error = 4.5 * get_minor_arc(object_angle,heading_angle_0_360);
			//���ö��
			Set_Servo(Dir_PID(Servo_error));
			Object_Speed = 220;
			bee_time = 300;
		}	
		
		//�˳��ж�
		if((heading_angle_0_360 > 335 ||  heading_angle_0_360 < 90) &&  black_or_write_check() == WRITE2)
		{
			bee_time = 300;
			Q3_state4_first_flag = 0;
			State_Machine.Q3_State = Q3_STATE_5;
		}
	}
	else
	{
		//�˳���ǰ��Ŀ
		q4_circle_num++;
		if(q4_circle_num >= 4)
		{
			State_Machine.Main_State = STOP_STATE;
			//ר������3�ı�������
		    q4_first_flag = 0;
		}
		State_Machine.Q3_State = Q3_STATE_1;
		//��ʼ����
		encoder_odometry_flag = 1;
	}
}
