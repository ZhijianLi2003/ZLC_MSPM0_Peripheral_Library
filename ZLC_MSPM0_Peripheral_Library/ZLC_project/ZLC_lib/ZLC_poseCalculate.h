/*
 * File: ZLC_poseCalculate.h
 * ZLC Electronic Design Competition Group（ZLC电赛小组）
 * Zhijian Li,Haoran Chen,Tianyu Zhou
 * Shandong University    2024-10-7
 * Open Source address:https://github.com/ZhijianLi2003/ZLC_MSPM0_Peripheral_Library
 */

#ifndef _ZLC_CALCULATE_H
#define _ZLC_CALCULATE_H

#include "math.h"

//some useful value
#define PI 3.14159265359

//declare the structure data
typedef struct
{
    float gyro_x;
    float gyro_y;
    float gyro_z;

    float acc_x;
    float acc_y;
    float acc_z;

    float mag_x;
    float mag_y;
    float mag_z;
} Sensor_imuData_t; //original sensor data

typedef struct
{
    float q0;
    float q1;
    float q2;
    float q3;
} Sensor_quater_t; //Pose Quaternion

typedef struct
{
    float pitch;
    float roll;
    float yaw;
} Sensor_euler_t; //Pose Eular-Angle

extern Sensor_imuData_t  IMUdata;
extern Sensor_quater_t  Q_info;
extern Sensor_euler_t EulerAngle;

//Interconversion of angles and radians
float Angle2Radian(float angle);
float Radian2Angle(float Radian);
//Gyroscope zero drift processing
void Sensor_GyroOffsetInit(void);
//calculate Quaternion of six-axis data
void Sensor_Mahony_Six_Axis_IMU(float gx, float gy, float gz, float ax, float ay, float az);
//Convert Quaternion to EularAngle
void Quaternion2EularAngle(void);

#endif

