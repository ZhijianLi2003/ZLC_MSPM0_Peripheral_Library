/*
 * File: ZLC_poseCalculate.c
 * ZLC Electronic Design Competition Group（ZLC电赛小组）
 * Zhijian Li,Haoran Chen,Tianyu Zhou
 * Shandong University    2024-10-7
 * Open Source address:https://github.com/ZhijianLi2003/ZLC_MSPM0_Peripheral_Library
 */

#include "ZLC_poseCalculate.h"

//define data
Sensor_imuData_t IMUdata;                     //original sensor data
Sensor_quater_t  Q_info = {1, 0 ,0 , 0};      //Pose Quaternion
Sensor_euler_t EulerAngle ;                   //Pose Eular-Angle

//define parameter
static float delta_T = 0.005f;                //Simpling time(Must be precise!)
static float beta = 0.01f;                    //0.01
float I_ex, I_ey, I_ez;        				  //Error Integral of each axis
float param_Kp = 0.20;         				  //Proportional Gain(The convergence rate of the accelerometer)
float param_Ki = 0.003;       				  //Integral Gain(The convergence rate of the gyroscope)

//change Angle into Radian
float Angle2Radian(float angle)
{
	return angle * PI / 180;
}

//change Radian into Angle
float Radian2Angle(float Radian)
{
	return PI * 180 / PI;
}


/*
 * function: quickly calculate the reciprocal of x square root, hardware independent, easy to port
 * param;    x
 * return:   void
 * author:   Zhijian Li
 * date:     2024-07-30
 */
float Sensor_FastInvSqrt(float x)
{
    float halfx = 0.5f * x;
    float y = x;
    long i = *(long *)&y;
    i = 0x5f3759df - (i >> 1);
    y = *(float *)&i;
    y = y * (1.5f - (halfx * y * y));
    return y;
}

/*
 * function: Mahony pose calculation method(Complementary filter)
 * param;    Six-axis sensor data(three-axi angular velocity and three-axi acceleration) after actual physical unit conversion!!!actual physical unit conversion!!!
             please attention!!! In this function, acceleration is measured in m/s^2 and angular velocity is measured in radians per second.(It's radians, not degrees!)
 * return:   void
 * author:   Zhijian Li
 * date:     2024-07-30
 */
void Sensor_Mahony_Six_Axis_IMU(float gx, float gy, float gz, float ax, float ay, float az)
{
    float q0 = Q_info.q0;
    float q1 = Q_info.q1;
    float q2 = Q_info.q2;
    float q3 = Q_info.q3;

    float sampleFreq = (1 / delta_T);

    float recipNorm;
    float s0, s1, s2, s3;
    float qDot1, qDot2, qDot3, qDot4;
    float _2q0, _2q1, _2q2, _2q3, _4q0, _4q1, _4q2, _8q1, _8q2, q0q0, q1q1, q2q2, q3q3;

    // Rate of change of quaternion from gyroscope
    qDot1 = 0.5f * (-q1 * gx - q2 * gy - q3 * gz);
    qDot2 = 0.5f * (q0 * gx + q2 * gz - q3 * gy);
    qDot3 = 0.5f * (q0 * gy - q1 * gz + q3 * gx);
    qDot4 = 0.5f * (q0 * gz + q1 * gy - q2 * gx);

    // Compute feedback only if accelerometer measurement valid (avoids NaN in accelerometer normalisation)
    if (!((ax == 0.0f) && (ay == 0.0f) && (az == 0.0f)))
    {

        // Normalise accelerometer measurement
        recipNorm = Sensor_FastInvSqrt(ax * ax + ay * ay + az * az);
        ax *= recipNorm;
        ay *= recipNorm;
        az *= recipNorm;

        // Auxiliary variables to avoid repeated arithmetic
        _2q0 = 2.0f * q0;
        _2q1 = 2.0f * q1;
        _2q2 = 2.0f * q2;
        _2q3 = 2.0f * q3;
        _4q0 = 4.0f * q0;
        _4q1 = 4.0f * q1;
        _4q2 = 4.0f * q2;
        _8q1 = 8.0f * q1;
        _8q2 = 8.0f * q2;
        q0q0 = q0 * q0;
        q1q1 = q1 * q1;
        q2q2 = q2 * q2;
        q3q3 = q3 * q3;
        // Gradient decent algorithm corrective step
        s0 = _4q0 * q2q2 + _2q2 * ax + _4q0 * q1q1 - _2q1 * ay;
        s1 = _4q1 * q3q3 - _2q3 * ax + 4.0f * q0q0 * q1 - _2q0 * ay - _4q1 + _8q1 * q1q1 + _8q1 * q2q2 + _4q1 * az;
        s2 = 4.0f * q0q0 * q2 + _2q0 * ax + _4q2 * q3q3 - _2q3 * ay - _4q2 + _8q2 * q1q1 + _8q2 * q2q2 + _4q2 * az;
        s3 = 4.0f * q1q1 * q3 - _2q1 * ax + 4.0f * q2q2 * q3 - _2q2 * ay;
        recipNorm = Sensor_FastInvSqrt(s0 * s0 + s1 * s1 + s2 * s2 + s3 * s3);
        // normalise step magnitude
        s0 *= recipNorm;
        s1 *= recipNorm;
        s2 *= recipNorm;
        s3 *= recipNorm;

        // Apply feedback step
        qDot1 -= beta * s0;
        qDot2 -= beta * s1;
        qDot3 -= beta * s2;
        qDot4 -= beta * s3;
    }
    // Integrate rate of change of quaternion to yield quaternion
    q0 += qDot1 * (1.0f / sampleFreq);
    q1 += qDot2 * (1.0f / sampleFreq);
    q2 += qDot3 * (1.0f / sampleFreq);
    q3 += qDot4 * (1.0f / sampleFreq);
    // Normalise quaternion
    recipNorm = Sensor_FastInvSqrt(q0 * q0 + q1 * q1 + q2 * q2 + q3 * q3);
    q0 *= recipNorm;
    q1 *= recipNorm;
    q2 *= recipNorm;
    q3 *= recipNorm;

    Q_info.q0 = q0;
    Q_info.q1 = q1;
    Q_info.q2 = q2;
    Q_info.q3 = q3;
}

/*
 * function: change current pose expressed in quaternion into pose expressed in EularAngle
             because the IMU installation position may not be absolute, you can make some corrections to the values according to the actual situation.
 * param;    void     
 * return:   void
 * author:   Zhijian Li
 * date:     2024-07-30
 */
void Quaternion2EularAngle(void)
{
	float q0 = Q_info.q0;
    float q1 = Q_info.q1;
    float q2 = Q_info.q2;
    float q3 = Q_info.q3;
	//ccalculate EulerAngle
	EulerAngle.pitch = asin(-2 * q1 * q3 + 2 * q0 * q2) * 180 / PI;                                // pitch
    EulerAngle.roll = atan2(2 * q2 * q3 + 2 * q0 * q1, -2 * q1 * q1 - 2 * q2 * q2 + 1) * 180 / PI; // roll
    EulerAngle.yaw = atan2(2 * q1 * q2 + 2 * q0 * q3, -2 * q2 * q2 - 2 * q3 * q3 + 1) * 180 / PI;  // yaw
	//limit value 
    if (EulerAngle.roll > 90 || EulerAngle.roll < -90)
    {
        if (EulerAngle.pitch > 0)
        {
            EulerAngle.pitch = 180 - EulerAngle.pitch;
        }
        if (EulerAngle.pitch < 0)
        {
            EulerAngle.pitch = -(180 + EulerAngle.pitch);
        }
    }
    if (EulerAngle.yaw >= 180)
    {
        EulerAngle.yaw -= 360;
    }
    else if (EulerAngle.yaw < -180)
    {
        EulerAngle.yaw += 360;
    }
	
	//error correct
	EulerAngle.pitch += 1.3;
}


/*
 * function: clear currrent pose and take the current front position as the zero of the EulerAngle.yaw(heading angle)
 * param;    void     
 * return:   void
 * author:   Zhijian Li
 * date:     2024-07-30
 */
void Clear_Current_pose(void)
{
	//Init the quaternion
	Q_info.q0 = 1;
	Q_info.q1 = 0;
	Q_info.q2 = 0;
	Q_info.q3 = 0;
	
	//Init the EularAngle
	EulerAngle.yaw = 0;
	EulerAngle.roll = 0;
	EulerAngle.pitch = 0;
	
}


 
/* Gyro-Zero-Drift often affects accuracy greatly!
 * So,if you want get a relatively accurate results,you should at least calibrate the gyroscope at the system level.
 * This is a example to remove Gyro Zero-drift  

typedef struct
{
	float Xoffset;
	float Yoffset;
	float Zoffset;
} Sensor_GyroCal_t; 
Sensor_GyroCal_t GyroOffset;

void Sensor_GyroOffsetInit(void)
{
	GyroOffset.Xoffset = 0;
	GyroOffset.Yoffset = 0;
	GyroOffset.Zoffset = 0;
	for (int i = 0; i < 1000; i++)
	{
		imu660ra_get_gyro(&gyro_data); //replace it by diver function of your imu
		GyroOffset.Xoffset += gyro_data.x;
		GyroOffset.Yoffset += gyro_data.y;
		GyroOffset.Zoffset += gyro_data.z;
		delay_ms(5);//replace it by your own delay function
	}
	GyroOffset.Xoffset /= 1000;
	GyroOffset.Yoffset /= 1000;
	GyroOffset.Zoffset /= 1000;
}

*/

