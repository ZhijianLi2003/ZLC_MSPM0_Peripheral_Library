/*
 * File: ZLC_Navigation.c
 * ZLC Electronic Design Competition Group（ZLC电赛小组）
 * Zhijian Li,Haoran Chen,Tianyu Zhou
 * Shandong University    2024-10-7
 * Open Source address:https://github.com/ZhijianLi2003/ZLC_MSPM0_Peripheral_Library
 */

#include "ZLC_Navigation.h"

/******************************************************IMU Zero_drift Processing******************************************/
imu660ra_measurement_data_struct acc_data, gyro_data;        //IMU_direct_data
imu660ra_physical_data_struct acc_physical,gyro_physical;    //IMU_physical_data

Sensor_GyroCal_t GyroOffset;

void Sensor_GyroOffsetCalc(void)
{
    printf("start calculating the zero drift value\r\n");
	GyroOffset.Xoffset = 0;
    GyroOffset.Yoffset = 0;
    GyroOffset.Zoffset = 0;
    for (int i = 0; i < 1000; i++)
    {
        imu660ra_get_gyro(&gyro_data);	 
        GyroOffset.Xoffset += gyro_data.x;
        GyroOffset.Yoffset += gyro_data.y;
        GyroOffset.Zoffset += gyro_data.z;
        delay_ms(5);
    }
    GyroOffset.Xoffset /= 1000;
    GyroOffset.Yoffset /= 1000;
    GyroOffset.Zoffset /= 1000;
	
	printf("X:%f,Y:%f,Z:%f\r\n",GyroOffset.Xoffset,GyroOffset.Yoffset,GyroOffset.Zoffset);
}


void Sensor_Gyro_Give_Directly(void)
{
	//directly write the zero drift into code(Flash)
	GyroOffset.Xoffset = -0.637000;
	GyroOffset.Yoffset = 4.740000;
	GyroOffset.Zoffset = -2.383000;
}

/********************************************************Inertial Navigation*************************************************/
int encoder_odometry_flag = 0;             //Whether to use encoder integration as odometer(是否使用编码器积分做里程计的标志位)
int odometry_sum = 0;                      //Odometer value(里程计数值)
float heading_angle = 0;                   //The heading angle of pose calculate(-180 to 180)(姿态解算的航向角（-180到180）)
float heading_angle_0_360 = 0;             //The heading angle for navigation.（用于导航的航向角（0-360））
float object_angle = 0;                    //The target heading_Angle of the car movement(车辆运动的目标航向角)
float first_angle = 0;                     //The angle of first run(第一次运行的角度)

/*
 * name:    Limit the heading_angle to 0-360 degrees(to prevent the range of heading_angle over 0-360 degrees beacuse of Addition or subtraction operations )
 * param;   heading_angle before being restricted (angle )     
 * return:  heading_angle after being restricted
 * author:  Zhijian Li
 * date:    2024-07-30
 */
float navigetion_0_360_limit(float angle)
{
		float temp = 0;
		if(angle < 0)
		{
			temp = angle + 360;
		}
		else if(angle > 360)
		{
			temp = angle - 360;
		}
		else
		{
			temp = angle;
		}
		return temp;
}


/*
 * name: Calculate the minor arc deviation in the 0-360 Navigation Coordinate System (Counterclockwise negative arc Angle is Positive, Clockwise is Negative)  
 * param;   azimuth             Object Heading_Angle（0-360）
 *          headingAngle        Current_Heading_Angle（0-360）
 * return: The minor arc Deviation 
 * author: Zhijian Li
 * date:   2024-07-30
 */
float get_minor_arc(float azimuth,float headingAngle)
{
    float angle_err = 0.0;
    //Calculate the minor arc deviation
    if(azimuth >= 180 + headingAngle)
    {
        angle_err = azimuth - headingAngle - 360;
    }
    else if(headingAngle > 180 + azimuth)
    {
        angle_err = azimuth - headingAngle + 360;
    }
    else
    {
        angle_err =  azimuth - headingAngle;
    }

    return -angle_err;
}


/**********************************************************Gray_Sensor_Navigation*****************************************************/
//GPIO for grayscale sensor
#define GRAY_SENSOR_1   (!DL_GPIO_readPins(HUIDU_PORT,HUIDU_PIN_1_PIN))
#define GRAY_SENSOR_2   (!DL_GPIO_readPins(HUIDU_PORT,HUIDU_PIN_2_PIN))
#define GRAY_SENSOR_3   (!DL_GPIO_readPins(HUIDU_PORT,HUIDU_PIN_3_PIN))
#define GRAY_SENSOR_4   (!DL_GPIO_readPins(HUIDU_PORT,HUIDU_PIN_4_PIN))
#define GRAY_SENSOR_5   (!DL_GPIO_readPins(HUIDU_PORT,HUIDU_PIN_5_PIN))
#define GRAY_SENSOR_6   (!DL_GPIO_readPins(HUIDU_PORT,HUIDU_PIN_6_PIN))
#define GRAY_SENSOR_7   (!DL_GPIO_readPins(HUIDU_PORT,HUIDU_PIN_7_PIN))
#define GRAY_SENSOR_8   (!DL_GPIO_readPins(HUIDU_PORT,HUIDU_PIN_9_PIN))

/*
 * name:    Detecting whether the current car is on the black line (traversing the grayscale sensor)
 * param;   no
 * return:  Car status
 *          BLACK1         Car is on the black line.
 *          WHITE2         Car is on the white track.
 * author:  warrior_Li
 * date:    2024-07-30
 */
int black_or_write_check(void)
{
	int if_have = 0;
	
	//Traversing the grayscale sensor
	if(GRAY_SENSOR_1)
	{
		if_have = 1;
	}
	if(GRAY_SENSOR_2)
	{
		if_have = 1;
	}
	if(GRAY_SENSOR_3)
	{
		if_have = 1;
	}
	if(GRAY_SENSOR_4)
	{
		if_have = 1;
	}
	if(GRAY_SENSOR_5)
	{
		if_have = 1;
	}
	if(GRAY_SENSOR_6)
	{
		if_have = 1;
	}
	if(GRAY_SENSOR_7)
	{
		if_have = 1;
	}
	if(GRAY_SENSOR_8)
	{
		if_have = 1;
	}
		
	//If a black line is detected
	if(if_have >= 1) 
	{
		  return BLACK1;
	}
	else
	{
		  return WRITE2;
	}
}

/*
 * name:    Gray tracking (个人感觉这个循迹方法当时写的不太好，只适用于一侧的转向，大家可以更换其他思路)
 * param;   left_right_proi      tracking priority
 *                               LEFT_PROI            Priority left turn
 *                               RIGHT_PROI           Priority right turn
 * return:  Steering value (four wheels) or turn Angle (three wheels)
 * author:  warrior_Li
 * date:    2024-07-30
 */
float super_black_tracking(int left_right_proi)
{
	float error = 0;

	if(left_right_proi == LEFT_PROI)
	{
		//Traverse the left grayscale sensor
		if(GRAY_SENSOR_1)
		{
			error += 200;
		}
		else if(GRAY_SENSOR_2)
		{
			error += 180;
		}
		else if(GRAY_SENSOR_3)
		{
			error += 140;
		}

		//Traverse the right grayscale sensor
		else if(GRAY_SENSOR_8)
		{
			error += 100;
		}
		else if(GRAY_SENSOR_7)
		{
			error += 100;
		}
		else if(GRAY_SENSOR_6)
		{
			error += 90;
		} 

		else if(GRAY_SENSOR_4)
		{
			error += 150;
		}
		else
		{
			error += 180;
		}
	}
	else 
	{
		//Traverse the right grayscale sensor
		if(GRAY_SENSOR_8)
		{
			error -= 165;
		}
		else if(GRAY_SENSOR_7)
		{
			error -= 155;
		}
		else if(GRAY_SENSOR_6)
		{
			error -= 95;
		}


		//Traverse the left grayscale sensor
		else if(GRAY_SENSOR_1)
		{
			error -= 35;
		}
		else if(GRAY_SENSOR_2)
		{
			error -= 35;
		}
		else if(GRAY_SENSOR_3)
		{
			error -= 35;
		}
		else if(GRAY_SENSOR_5)
		{
			error -= 115;
		}
		else
		{
			error -= 165;
		}
	}
		
	return error;
	
}