/*
 * File: ZLC_Navigation.h
 * ZLC Electronic Design Competition Group（ZLC电赛小组）
 * Zhijian Li,Haoran Chen,Tianyu Zhou
 * Shandong University    2024-10-7
 * Open Source address:https://github.com/ZhijianLi2003/ZLC_MSPM0_Peripheral_Library
 */

#ifndef __ZLC_NAVIGATION_H
#define __ZLC_NAVIGATION_H

#include "board.h"
#include "ti_msp_dl_config.h"
#include "zf_device_imu660ra.h"

/******************************************************IMU Zero_drift Processing******************************************/
extern imu660ra_measurement_data_struct acc_data, gyro_data;        //IMU_direct_data
extern imu660ra_physical_data_struct acc_physical,gyro_physical;    //IMU_physical_data

typedef struct
{
	float Xoffset;
	float Yoffset;
	float Zoffset;
} Sensor_GyroCal_t; 

extern Sensor_GyroCal_t GyroOffset;

void Sensor_GyroOffsetCalc(void);
void Sensor_Gyro_Give_Directly(void);

/********************************************************Inertial Navigation*************************************************/
extern int encoder_odometry_flag;
extern int odometry_sum;
extern float heading_angle;
extern float heading_angle_0_360;
extern float object_angle;
extern float first_angle;
float navigetion_0_360_limit(float angle);
float get_minor_arc(float azimuth,float headingAngle);

/**********************************************************Gray_Sensor_Navigation*****************************************************/

//Grayscale tracking priority
#define LEFT_PROI    0        //Priority left turn
#define RIGHT_PROI   1        //Priority right turn

//Grayscale tracking test 
#define BLACK1       1        //black
#define WRITE2       2        //white

int black_or_write_check(void);
float black_tracking(int left_right_proi);
float super_black_tracking(int left_right_proi);

#endif