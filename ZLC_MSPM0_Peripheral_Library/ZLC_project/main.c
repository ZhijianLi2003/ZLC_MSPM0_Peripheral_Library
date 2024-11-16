/*
 * File: main.c
 * ZLC Electronic Design Competition Group（ZLC电赛小组）
 * Zhijian Li,Haoran Chen,Tianyu Zhou
 * Shandong University    2024-10-7
 * Open Source address: https://github.com/ZhijianLi2003/ZLC_MSPM0_Peripheral_Library
 * MSPM0G3507 LaunchPad expansion board:http://oshwhub.com/hurricanchen/zlc_-dian-sai-mspm0g3507-launchpad-kuo-zhan-ban
 */
 
#include "ZLC_headfile.h" 
#include "ZLC_QuestionTask.h"

//PIT_IMU_calc_finish_flag
uint8_t pit_imu_flag    = 0;   
//Virtual multi-threaded allocation of main function (use volatitle Keyword to modify variables that change quickly to prevent optimization by the compiler)
volatile int task[4] = {20,0,0,0};         

int main (void)
{
	//Init config of Syscfg
	board_init();
    Set_Servo(0);
	Set_Left_Speed(0);
	Set_Right_Speed(0);
	
	//Enable UART Interrupt
	NVIC_ClearPendingIRQ(UART_0_INST_INT_IRQN); 
	NVIC_EnableIRQ(UART_0_INST_INT_IRQN);       
	
	//Init IMU(waitting for success)
    while(1)
    {
		
        if(imu660ra_init())
        {
			//IMU660ra init failed
            printf("\r\nIMU660RA init error.");                                 
        }
        else
        {
			//IMU660ra init successfully    
            break;
        }
        delay_ms(100);
        DL_GPIO_togglePins(LED1_PORT, LED1_PIN_14_PIN);
    }

	//this function can calculate the zero drift of the gyroscope,but it need 5 seconds. please attention to the serial port output
	//Sensor_GyroOffsetCalc();  
	//After completing the above calculation, you can directly write the output of serial port into the code of the following function.
	Sensor_Gyro_Give_Directly();
    
	//Enable Exit of GPIO_A_GROUP
	NVIC_EnableIRQ(GPIOA_INT_IRQn);
	//Enable Timer PIT_FOR_CUSTOM
	NVIC_EnableIRQ(PIT_FOR_CUSTOM_INST_INT_IRQN);
    DL_TimerG_startCounter(PIT_FOR_CUSTOM_INST);
	//Enable Timer PIT_FOR_CONTROL
	NVIC_EnableIRQ(PIT_FOR_CONTROL_INST_INT_IRQN);
    DL_TimerG_startCounter(PIT_FOR_CONTROL_INST);
	
	//init State_Machine
	State_Machine_init();
	
	//Say Hello
	printf("\r\n Hello,I'm an automatic Car(Question H of Undergraduate Electronic Competition in 2024)");
    printf("\r\n author:SDU-ZLC Electronic Design Competition Group");	
	
	delay_ms(3000);
	State_Machine.Main_State = STOP_STATE;
	
	//main function
    while (1) 
    {
		
		//waiting for button to start
		if(key_1_flag)
		{
			bee_time = 200; 
			State_Machine.Main_State = QUESTION_1;
			key_1_flag = 0;
		}		
		if(key_2_flag)
		{
			bee_time = 200; 
			State_Machine.Main_State = QUESTION_2;
			key_2_flag = 0;
		}
		if(key_3_flag)
		{
			bee_time = 200; 
			State_Machine.Main_State = QUESTION_3;
			key_3_flag = 0;
		}
		if(key_4_flag)
		{
			bee_time = 200; 
			State_Machine.Main_State = QUESTION_4;
			key_4_flag = 0;
		}
		
		
		//stop_protection(Romote_control)
		if(DL_GPIO_readPins(Remote_Switch_PORT,Remote_Switch_PIN_PIN))
		{
			State_Machine.Main_State = STOP_STATE;
		    bee_time = 4000;
		}
		
		//20ms thread 
		if(!task[0])
		{
			task[0] = 20;
			
			//get current pose(heading_angle and angular_velocity)
			if(pit_imu_flag)
			{
				pit_imu_flag = 0;
				//get -180-180 degree
				heading_angle = EulerAngle.yaw;
				
				//change to 0-360 degree
				if(heading_angle < 0)
				{
					heading_angle_0_360 = -heading_angle;
				}
				else if(heading_angle >= 0)
				{
					heading_angle_0_360 = 360 - heading_angle;
				}
			}
			
			//the State_Machine of object question task
			switch(State_Machine.Main_State)
			{
				case STOP_STATE:
					Set_Servo(0);
					Object_Speed = 0;
					break;
				
				case QUESTION_1:
					Question_Task_1();
					break;
				
				case QUESTION_2:
					Question_Task_2();
					break;
				
				case QUESTION_3:
					Question_Task_3();				
					break;
				
				case QUESTION_4:
				    Question_Task_4();	
				break;
					
				default:
					break;
			}	
			
			
			//Parameter debugger section（you can use VOFA or other Serial_assistant to debug）
			//printf("%f\r\n",heading_angle_0_360);
			//printf("%d,%d\r\n",Object_Speed,LC_Speed);
			//printf("%d,%d\r\n",Object_Speed,RC_Speed);
			//printf("%f,%f,%f\r\n",EulerAngle.yaw,EulerAngle.pitch,EulerAngle.roll);
		}				
    }
}


//Timer interrupt function(1ms)
void PIT_FOR_CUSTOM_INST_IRQHandler(void)
{
	static int count = 0;
    switch( DL_TimerG_getPendingInterrupt(PIT_FOR_CUSTOM_INST) )
    {
        case DL_TIMER_IIDX_LOAD:
		    //the virtual thread manager
		    for (int i = 0; i < 4; i++)
			{
				//if task[i] == 0,the main Loop will excute this thread
				if (task[i])
					task[i] -= 1;
			}
			
			//GPIO time control
			GPIO_Time_Control();
						    
		    //IMU pose calculate task(every 5ms)
			count++;
		    if(count >= 5)
			{
				
				 //get IMU original data
			     imu660ra_get_acc(&acc_data);
                 imu660ra_get_gyro(&gyro_data);
				 //remove the zero-drift of gyro
				 gyro_data.x -= GyroOffset.Xoffset;
				 gyro_data.y -= GyroOffset.Yoffset;
				 gyro_data.z -= GyroOffset.Zoffset;
                 //convert to actual physical dimensions			
				 imu660ra_get_physical_acc(&acc_data,IMU660RA_ACC_RANGE_SGN_8G,&acc_physical);
				 imu660ra_get_physical_gyro(&gyro_data,IMU660RA_GYRO_RANGE_SGN_2000DPS,&gyro_physical);
				 //calculate Quaternion of six-axis data
				 Sensor_Mahony_Six_Axis_IMU(Angle2Radian(gyro_physical.x),Angle2Radian(gyro_physical.y),Angle2Radian(gyro_physical.z),acc_physical.x,acc_physical.y,acc_physical.z);
				 //Convert Quaternion to EularAngle
				 Quaternion2EularAngle();
				 				 
				 count = 0;
				 pit_imu_flag = 1;
			}
            break;
			
        default:
            break;
    }
}


//Timer interrupt function(20ms)
void PIT_FOR_CONTROL_INST_IRQHandler(void)
{
	static int count = 0;
	static int VL_control=0,VR_control = 0;
    switch( DL_TimerG_getPendingInterrupt(PIT_FOR_CONTROL_INST) )
    {
        case DL_TIMER_IIDX_LOAD:
			//key scan detection
		    Key_Edge_Scan();
			//get current speed through cycle encoder count
			LC_Speed = Encoder_Get_L();
	        RC_Speed = -Encoder_Get_R();
		    //mileage calculation
			if(encoder_odometry_flag == 1)
			{
				odometry_sum += ((LC_Speed + RC_Speed) / 2);
			}
            //PI motor closed loop control
            VL_control = Velocity_L(Object_Speed,LC_Speed);
			VR_control = Velocity_R(Object_Speed,RC_Speed);		
			//motor actual PWM control
			Set_Left_Speed(VL_control);
			Set_Right_Speed(VR_control);	
            break;
			
        default:
            break;
    }
}



