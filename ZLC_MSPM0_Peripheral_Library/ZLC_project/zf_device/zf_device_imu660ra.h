/*********************************************************************************************************************
* MSPM0G3507 Opensourec Library 即（MSPM0G3507 开源库）是一个基于官方 SDK 接口的第三方开源库
* Copyright (c) 2022 SEEKFREE 逐飞科技
* 
* 本文件是 MSPM0G3507 开源库的一部分
* 
* MSPM0G3507 开源库 是免费软件
* 您可以根据自由软件基金会发布的 GPL（GNU General Public License，即 GNU通用公共许可证）的条款
* 即 GPL 的第3版（即 GPL3.0）或（您选择的）任何后来的版本，重新发布和/或修改它
* 
* 本开源库的发布是希望它能发挥作用，但并未对其作任何的保证
* 甚至没有隐含的适销性或适合特定用途的保证
* 更多细节请参见 GPL
* 
* 您应该在收到本开源库的同时收到一份 GPL 的副本
* 如果没有，请参阅<https://www.gnu.org/licenses/>
* 
* 额外注明：
* 本开源库使用 GPL3.0 开源许可证协议 以上许可申明为译文版本
* 许可申明英文版在 libraries/doc 文件夹下的 GPL3_permission_statement.txt 文件中
* 许可证副本在 libraries 文件夹下 即该文件夹下的 LICENSE 文件
* 欢迎各位使用并传播本程序 但修改内容时必须保留逐飞科技的版权声明（即本声明）
* 
* 文件名称          zf_device_imu660ra
* 公司名称          成都逐飞科技有限公司
* 版本信息          查看 libraries/doc 文件夹内 version 文件 版本说明
* 开发环境          MDK 5.38a
* 适用平台          MSPM0G3507
* 店铺链接          https://seekfree.taobao.com/
********************************************************************************************************************/

/*********************************************************************************************************************
* 接线定义          查看 zf_device_imu_interface.h 中接口资源定义
********************************************************************************************************************/

#ifndef _zf_device_imu660ra_h_
#define _zf_device_imu660ra_h_

// zf_common 层 类型定义 引用
#include "zf_common_typedef.h"

// 此处列举 当前支持的函数列表
// 具体声明在本函数中查看对应注释 具体定义跳转到对应函数定义查看
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Part Start >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// imu660ra_get_physical_acc                                                    // 获取 IMU660RA 加速度计物理量数据
// imu660ra_get_physical_gyro                                                   // 获取 IMU660RA 陀螺仪物理量数据

// imu660ra_get_acc                                                             // 获取 IMU660RA 加速度计数据
// imu660ra_get_gyro                                                            // 获取 IMU660RA 陀螺仪数据

// imu660ra_set_config                                                          // IMU660RA 配置模块工作参数
// imu660ra_init                                                                // 初始化 IMU660RA
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Part   End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

// 此处定义 IMU660RA 相关的结构体数据构成细节 这里不允许用户修改
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Part Start >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// IMU660RA_ACC_OUTPUT_RATE_BASE 对应默认的 IMU660RA 的加速度计数据输出频率 实际为 50Hz
// 实际会略有偏差 需要去查看对应的芯片手册 因此对应从低到高可以设置为
// IMU660RA_ACC_OUTPUT_RATE_64_DIV      ->  0.78    Hz
// IMU660RA_ACC_OUTPUT_RATE_32_DIV      ->  1.5     Hz
// IMU660RA_ACC_OUTPUT_RATE_16_DIV      ->  3.1     Hz
// IMU660RA_ACC_OUTPUT_RATE_8_DIV       ->  6.25    Hz
// IMU660RA_ACC_OUTPUT_RATE_4_DIV       ->  12.5    Hz
// IMU660RA_ACC_OUTPUT_RATE_2_DIV       ->  25      Hz
// IMU660RA_ACC_OUTPUT_RATE_BASE        ->  50      Hz
// IMU660RA_ACC_OUTPUT_RATE_2_MUL       ->  100     Hz
// IMU660RA_ACC_OUTPUT_RATE_4_MUL       ->  200     Hz
// IMU660RA_ACC_OUTPUT_RATE_8_MUL       ->  400     Hz
// IMU660RA_ACC_OUTPUT_RATE_16_MUL      ->  800     Hz
// IMU660RA_ACC_OUTPUT_RATE_32_MUL      ->  1600    Hz
typedef enum
{
    IMU660RA_ACC_OUTPUT_RATE_64_DIV = 2 ,                                       // 加速度计输出频率 64 分频 (ACC = Accelerometer 加速度计)
    IMU660RA_ACC_OUTPUT_RATE_32_DIV     ,                                       // 加速度计输出频率 32 分频 (ACC = Accelerometer 加速度计)
    IMU660RA_ACC_OUTPUT_RATE_16_DIV     ,                                       // 加速度计输出频率 16 分频 (ACC = Accelerometer 加速度计)
    IMU660RA_ACC_OUTPUT_RATE_8_DIV      ,                                       // 加速度计输出频率 8  分频 (ACC = Accelerometer 加速度计)
    IMU660RA_ACC_OUTPUT_RATE_4_DIV      ,                                       // 加速度计输出频率 4  分频 (ACC = Accelerometer 加速度计)
    IMU660RA_ACC_OUTPUT_RATE_2_DIV      ,                                       // 加速度计输出频率 2  分频 (ACC = Accelerometer 加速度计)
    IMU660RA_ACC_OUTPUT_RATE_BASE       ,                                       // 加速度计输出频率基础频率 (ACC = Accelerometer 加速度计)
    IMU660RA_ACC_OUTPUT_RATE_2_MUL      ,                                       // 加速度计输出频率 2  倍频 (ACC = Accelerometer 加速度计)
    IMU660RA_ACC_OUTPUT_RATE_4_MUL      ,                                       // 加速度计输出频率 4  倍频 (ACC = Accelerometer 加速度计)
    IMU660RA_ACC_OUTPUT_RATE_8_MUL      ,                                       // 加速度计输出频率 8  倍频 (ACC = Accelerometer 加速度计)
    IMU660RA_ACC_OUTPUT_RATE_16_MUL     ,                                       // 加速度计输出频率 16 倍频 (ACC = Accelerometer 加速度计)
    IMU660RA_ACC_OUTPUT_RATE_32_MUL     ,                                       // 加速度计输出频率 32 倍频 (ACC = Accelerometer 加速度计)
}imu660ra_acc_output_rate_enum;

typedef enum
{
    IMU660RA_ACC_RANGE_SGN_2G       = 2 ,                                       // 加速度计量程 ±2 g (ACC = Accelerometer 加速度计) (SGN = signum 带符号数 表示正负范围) (g 代表重力加速度 物理学名词 一般情况下 g 取 9.8 m/s^2 为标准值)
    IMU660RA_ACC_RANGE_SGN_4G           ,                                       // 加速度计量程 ±4 g (ACC = Accelerometer 加速度计) (SGN = signum 带符号数 表示正负范围) (g 代表重力加速度 物理学名词 一般情况下 g 取 9.8 m/s^2 为标准值)
    IMU660RA_ACC_RANGE_SGN_8G           ,                                       // 加速度计量程 ±8 g (ACC = Accelerometer 加速度计) (SGN = signum 带符号数 表示正负范围) (g 代表重力加速度 物理学名词 一般情况下 g 取 9.8 m/s^2 为标准值)
    IMU660RA_ACC_RANGE_SGN_16G          ,                                       // 加速度计量程 ±16g (ACC = Accelerometer 加速度计) (SGN = signum 带符号数 表示正负范围) (g 代表重力加速度 物理学名词 一般情况下 g 取 9.8 m/s^2 为标准值)
}imu660ra_acc_range_enum;

// IMU660RA_GYRO_OUTPUT_RATE_BASE 对应默认的 IMU660RA 的陀螺仪数据输出频率 实际为 50Hz
// 实际会略有偏差 需要去查看对应的芯片手册 因此对应从低到高可以设置为
// IMU660RA_GYRO_OUTPUT_RATE_2_DIV      -> 25       Hz
// IMU660RA_GYRO_OUTPUT_RATE_BASE       -> 50       Hz
// IMU660RA_GYRO_OUTPUT_RATE_2_MUL      -> 100      Hz
// IMU660RA_GYRO_OUTPUT_RATE_4_MUL      -> 200      Hz
// IMU660RA_GYRO_OUTPUT_RATE_8_MUL      -> 400      Hz
// IMU660RA_GYRO_OUTPUT_RATE_16_MUL     -> 800      Hz
// IMU660RA_GYRO_OUTPUT_RATE_32_MUL     -> 1600     Hz
// IMU660RA_GYRO_OUTPUT_RATE_64_MUL     -> 3200     Hz
typedef enum
{
    IMU660RA_GYRO_OUTPUT_RATE_2_DIV = 7 ,                                       // 陀螺仪输出频率 2  分频 (GYRO = Gyroscope 陀螺仪)
    IMU660RA_GYRO_OUTPUT_RATE_BASE      ,                                       // 陀螺仪输出频率基础频率 (GYRO = Gyroscope 陀螺仪)
    IMU660RA_GYRO_OUTPUT_RATE_2_MUL     ,                                       // 陀螺仪输出频率 2  倍频 (GYRO = Gyroscope 陀螺仪)
    IMU660RA_GYRO_OUTPUT_RATE_4_MUL     ,                                       // 陀螺仪输出频率 4  倍频 (GYRO = Gyroscope 陀螺仪)
    IMU660RA_GYRO_OUTPUT_RATE_8_MUL     ,                                       // 陀螺仪输出频率 8  倍频 (GYRO = Gyroscope 陀螺仪)
    IMU660RA_GYRO_OUTPUT_RATE_16_MUL    ,                                       // 陀螺仪输出频率 16 倍频 (GYRO = Gyroscope 陀螺仪)
    IMU660RA_GYRO_OUTPUT_RATE_32_MUL    ,                                       // 陀螺仪输出频率 32 倍频 (GYRO = Gyroscope 陀螺仪)
    IMU660RA_GYRO_OUTPUT_RATE_64_MUL    ,                                       // 陀螺仪输出频率 64 倍频 (GYRO = Gyroscope 陀螺仪)
}imu660ra_gyro_output_rate_enum;

typedef enum
{
    IMU660RA_GYRO_RANGE_SGN_125DPS  = 2 ,                                       // 陀螺仪量程 ±125DPS  (GYRO = Gyroscope 陀螺仪) (SGN = signum 带符号数 表示正负范围) (DPS = Degree Per Second 角速度单位 °/S)
    IMU660RA_GYRO_RANGE_SGN_250DPS      ,                                       // 陀螺仪量程 ±250DPS  (GYRO = Gyroscope 陀螺仪) (SGN = signum 带符号数 表示正负范围) (DPS = Degree Per Second 角速度单位 °/S)
    IMU660RA_GYRO_RANGE_SGN_500DPS      ,                                       // 陀螺仪量程 ±500DPS  (GYRO = Gyroscope 陀螺仪) (SGN = signum 带符号数 表示正负范围) (DPS = Degree Per Second 角速度单位 °/S)
    IMU660RA_GYRO_RANGE_SGN_1000DPS     ,                                       // 陀螺仪量程 ±1000DPS (GYRO = Gyroscope 陀螺仪) (SGN = signum 带符号数 表示正负范围) (DPS = Degree Per Second 角速度单位 °/S)
    IMU660RA_GYRO_RANGE_SGN_2000DPS     ,                                       // 陀螺仪量程 ±2000DPS (GYRO = Gyroscope 陀螺仪) (SGN = signum 带符号数 表示正负范围) (DPS = Degree Per Second 角速度单位 °/S)
}imu660ra_gyro_range_enum;

#define IMU660RA_TIMEOUT_COUNT              ( 10 )                              // IMU660RA 超时计数

#define IMU660RA_ACC_OUTPUT_RATE_DEFAULT    ( IMU660RA_ACC_OUTPUT_RATE_BASE   ) // 在这设置默认的 加速度计  初始化输出频率
#define IMU660RA_ACC_RANGE_DEFAULT          ( IMU660RA_ACC_RANGE_SGN_8G       ) // 在这设置默认的 加速度计  初始化量程
#define IMU660RA_GYRO_OUTPUT_RATE_DEFAULT   ( IMU660RA_GYRO_OUTPUT_RATE_4_MUL ) // 在这设置默认的 陀螺仪    初始化输出频率
#define IMU660RA_GYRO_RANGE_DEFAULT         ( IMU660RA_GYRO_RANGE_SGN_2000DPS ) // 在这设置默认的 陀螺仪    初始化量程

#define IMU660RA_CONFIG_TYPE_OFFSET         ( 4     )                           // 累计低位的位移后从 16bit 开始
#define IMU660RA_CONFIG_TYPE_MASK           ( 0x0F  )                           // 同样根据需要添加的引脚服用功能掩码 这里也是 4bit 因此掩码为 0xF

#define IMU660RA_CONFIG_VALUE_OFFSET        ( 0     )                           // 累计低位的位移后从 16bit 开始
#define IMU660RA_CONFIG_VALUE_MASK          ( 0x0F  )                           // 同样根据需要添加的引脚服用功能掩码 这里也是 4bit 因此掩码为 0xF

typedef enum                                                                    // 枚举 IMU660RA 配置选项 此枚举定义不允许用户修改
{
    IMU660RA_CONFIG_ACC_OUTPUT_RATE_64_DIV          = ((0x00 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_ACC_OUTPUT_RATE_64_DIV) ,
    IMU660RA_CONFIG_ACC_OUTPUT_RATE_32_DIV          = ((0x00 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_ACC_OUTPUT_RATE_32_DIV) ,
    IMU660RA_CONFIG_ACC_OUTPUT_RATE_16_DIV          = ((0x00 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_ACC_OUTPUT_RATE_16_DIV) ,
    IMU660RA_CONFIG_ACC_OUTPUT_RATE_8_DIV           = ((0x00 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_ACC_OUTPUT_RATE_8_DIV ) ,
    IMU660RA_CONFIG_ACC_OUTPUT_RATE_4_DIV           = ((0x00 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_ACC_OUTPUT_RATE_4_DIV ) ,
    IMU660RA_CONFIG_ACC_OUTPUT_RATE_2_DIV           = ((0x00 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_ACC_OUTPUT_RATE_2_DIV ) ,
    IMU660RA_CONFIG_ACC_OUTPUT_RATE_BASE            = ((0x00 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_ACC_OUTPUT_RATE_BASE  ) ,
    IMU660RA_CONFIG_ACC_OUTPUT_RATE_2_MUL           = ((0x00 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_ACC_OUTPUT_RATE_2_MUL ) ,
    IMU660RA_CONFIG_ACC_OUTPUT_RATE_4_MUL           = ((0x00 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_ACC_OUTPUT_RATE_4_MUL ) ,
    IMU660RA_CONFIG_ACC_OUTPUT_RATE_8_MUL           = ((0x00 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_ACC_OUTPUT_RATE_8_MUL ) ,
    IMU660RA_CONFIG_ACC_OUTPUT_RATE_16_MUL          = ((0x00 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_ACC_OUTPUT_RATE_16_MUL) ,
    IMU660RA_CONFIG_ACC_OUTPUT_RATE_32_MUL          = ((0x00 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_ACC_OUTPUT_RATE_32_MUL) ,

    IMU660RA_CONFIG_ACC_RANGE_SGN_2G                = ((0x01 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_ACC_RANGE_SGN_2G    )   ,
    IMU660RA_CONFIG_ACC_RANGE_SGN_4G                = ((0x01 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_ACC_RANGE_SGN_4G    )   ,
    IMU660RA_CONFIG_ACC_RANGE_SGN_8G                = ((0x01 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_ACC_RANGE_SGN_8G    )   ,
    IMU660RA_CONFIG_ACC_RANGE_SGN_16G               = ((0x01 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_ACC_RANGE_SGN_16G   )   ,

    IMU660RA_CONFIG_GYRO_OUTPUT_RATE_2_DIV          = ((0x02 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_GYRO_OUTPUT_RATE_2_DIV ),
    IMU660RA_CONFIG_GYRO_OUTPUT_RATE_BASE           = ((0x02 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_GYRO_OUTPUT_RATE_BASE  ),
    IMU660RA_CONFIG_GYRO_OUTPUT_RATE_2_MUL          = ((0x02 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_GYRO_OUTPUT_RATE_2_MUL ),
    IMU660RA_CONFIG_GYRO_OUTPUT_RATE_4_MUL          = ((0x02 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_GYRO_OUTPUT_RATE_4_MUL ),
    IMU660RA_CONFIG_GYRO_OUTPUT_RATE_8_MUL          = ((0x02 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_GYRO_OUTPUT_RATE_8_MUL ),
    IMU660RA_CONFIG_GYRO_OUTPUT_RATE_16_MUL         = ((0x02 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_GYRO_OUTPUT_RATE_16_MUL),
    IMU660RA_CONFIG_GYRO_OUTPUT_RATE_32_MUL         = ((0x02 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_GYRO_OUTPUT_RATE_32_MUL),
    IMU660RA_CONFIG_GYRO_OUTPUT_RATE_64_MUL         = ((0x02 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_GYRO_OUTPUT_RATE_64_MUL),

    IMU660RA_CONFIG_GYRO_RANGE_SGN_125DPS           = ((0x03 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_GYRO_RANGE_SGN_125DPS ) ,
    IMU660RA_CONFIG_GYRO_RANGE_SGN_250DPS           = ((0x03 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_GYRO_RANGE_SGN_250DPS ) ,
    IMU660RA_CONFIG_GYRO_RANGE_SGN_500DPS           = ((0x03 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_GYRO_RANGE_SGN_500DPS ) ,
    IMU660RA_CONFIG_GYRO_RANGE_SGN_1000DPS          = ((0x03 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_GYRO_RANGE_SGN_1000DPS) ,
    IMU660RA_CONFIG_GYRO_RANGE_SGN_2000DPS          = ((0x03 << IMU660RA_CONFIG_TYPE_OFFSET) | IMU660RA_GYRO_RANGE_SGN_2000DPS) ,
}imu660ra_config_item_enum;

typedef enum
{
    IMU660RA_INTERFACE_SPI      ,
    IMU660RA_INTERFACE_SOFT_IIC ,
    IMU660RA_INTERFACE_IIC      ,
}imu660ra_interface_type_enum;

typedef enum
{
    IMU660RA_STATE_NO_ERROR                     ,

    IMU660RA_STATE_DATA_BUFFER_ERROR            ,
    IMU660RA_STATE_INTERFACE_INIT_ERROR         ,
    IMU660RA_STATE_ID_CHECK_ERROR               ,
    IMU660RA_STATE_SELF_CHECK_ERROR             ,
    IMU660RA_STATE_SET_CONFIG_ERROR             ,
    IMU660RA_STATE_SET_ACC_OUTPUT_RATE_ERROR    ,
    IMU660RA_STATE_SET_ACC_RANGE_ERROR          ,
    IMU660RA_STATE_SET_GYRO_OUTPUT_RATE_ERROR   ,
    IMU660RA_STATE_SET_GYRO_RANGE_ERROR         ,
}imu660ra_state_enum;

typedef struct                                                                  // IMU660RA 数据格式模板 用于存储 IMU660RA 的数据
{
    int16       x   ;                                                           // X 轴的原始数据
    int16       y   ;                                                           // Y 轴的原始数据
    int16       z   ;                                                           // Z 轴的原始数据
}imu660ra_measurement_data_struct;

typedef struct                                                                  // IMU660RA 数据格式模板 用于存储 IMU660RA 的数据
{
    float       x   ;                                                           // X 轴的物理量数据
    float       y   ;                                                           // Y 轴的物理量数据
    float       z   ;                                                           // Z 轴的物理量数据
}imu660ra_physical_data_struct;
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Part   End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

// 此处定义 IMU660RA 驱动所需的内部定义 这里不允许用户修改
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Part Start >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// 定义 IMU660RA 内部地址
#define IMU660RA_DEV_ADDR           ( 0x69 )                                    // 7bit 地址格式 SA0接地：0x68 SA0上拉：0x69 模块默认上拉
#define IMU660RA_SPI_W              ( 0x00 )
#define IMU660RA_SPI_R              ( 0x80 )

#define IMU660RA_CHIP_ID            ( 0x00 )
#define IMU660RA_PWR_CONF           ( 0x7C )
#define IMU660RA_PWR_CTRL           ( 0x7D )
#define IMU660RA_INIT_CTRL          ( 0x59 )
#define IMU660RA_INIT_DATA          ( 0x5E )
#define IMU660RA_INT_STA            ( 0x21 )
#define IMU660RA_ACC_ADDRESS        ( 0x0C )
#define IMU660RA_GYRO_ADDRESS       ( 0x12 )
#define IMU660RA_ACC_CONF           ( 0x40 )
#define IMU660RA_ACC_RANGE          ( 0x41 )
#define IMU660RA_GYR_CONF           ( 0x42 )
#define IMU660RA_GYR_RANGE          ( 0x43 )
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Part   End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

// 此处列举 本文件的所有函数声明 [ 其中包括宏定义函数 ] 这里不允许用户修改
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Part Start >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//-------------------------------------------------------------------------------------------------------------------
// 函数简介     获取 IMU660RA 加速度计物理量数据
// 参数说明     *measurement_data       IMU660RA 的测量数据缓冲指针
// 返回参数     range                   IMU660RA 加速度量程 详见 zf_device_imu660ra.h 中 imu660ra_acc_range_enum 定义
// 参数说明     *physical_data          IMU660RA 的物理量数据缓冲指针
// 返回参数     imu660ra_state_enum     IMU660RA 状态码 详见 zf_device_imu660ra.h 中 imu660ra_state_enum 定义
// 使用示例     imu660ra_get_physical_acc(imu660_data_buffer, range, physical_data);
// 备注信息     根据量程进行物理量换算
//              加速度计量程 ±2  g   获取到的加速度计数据除以 16384  可以转化为带物理单位的数据 (g 代表重力加速度 物理学名词 一般情况下 g 取 9.8 m/s^2 为标准值)
//              加速度计量程 ±4  g   获取到的加速度计数据除以 8192   可以转化为带物理单位的数据 (g 代表重力加速度 物理学名词 一般情况下 g 取 9.8 m/s^2 为标准值)
//              加速度计量程 ±8  g   获取到的加速度计数据除以 4096   可以转化为带物理单位的数据 (g 代表重力加速度 物理学名词 一般情况下 g 取 9.8 m/s^2 为标准值)
//              加速度计量程 ±16 g   获取到的加速度计数据除以 2048   可以转化为带物理单位的数据 (g 代表重力加速度 物理学名词 一般情况下 g 取 9.8 m/s^2 为标准值)
//-------------------------------------------------------------------------------------------------------------------
imu660ra_state_enum imu660ra_get_physical_acc (imu660ra_measurement_data_struct *measurement_data, imu660ra_acc_range_enum range,imu660ra_physical_data_struct *physical_data);

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     获取 IMU660RA 陀螺仪物理量数据
// 参数说明     *measurement_data       IMU660RA 的测量数据缓冲指针
// 返回参数     range                   IMU660RA 加速度量程 详见 zf_device_imu660ra.h 中 imu660ra_gyro_range_enum 定义
// 参数说明     *physical_data          IMU660RA 的物理量数据缓冲指针
// 返回参数     imu660ra_state_enum     IMU660RA 状态码 详见 zf_device_imu660ra.h 中 imu660ra_state_enum 定义
// 使用示例     imu660ra_get_physical_gyro(imu660_data_buffer, range, physical_data);
// 备注信息     根据量程进行物理量换算
//              陀螺仪量程 ±125  dps    获取到的陀螺仪数据除以 262.4   可以转化为带物理单位的数据 单位为 °/s
//              陀螺仪量程 ±250  dps    获取到的陀螺仪数据除以 131.2   可以转化为带物理单位的数据 单位为 °/s
//              陀螺仪量程 ±500  dps    获取到的陀螺仪数据除以 65.6    可以转化为带物理单位的数据 单位为 °/s
//              陀螺仪量程 ±1000 dps    获取到的陀螺仪数据除以 32.8    可以转化为带物理单位的数据 单位为 °/s
//              陀螺仪量程 ±2000 dps    获取到的陀螺仪数据除以 16.4    可以转化为带物理单位的数据 单位为 °/s
//-------------------------------------------------------------------------------------------------------------------
imu660ra_state_enum imu660ra_get_physical_gyro (imu660ra_measurement_data_struct *measurement_data, imu660ra_gyro_range_enum range,imu660ra_physical_data_struct *physical_data);

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     获取 IMU660RA 加速度计数据
// 参数说明     *measurement_data       IMU660RA 的测量数据缓冲指针
// 返回参数     imu660ra_state_enum     IMU660RA 状态码 详见 zf_device_imu660ra.h 中 imu660ra_state_enum 定义
// 使用示例     imu660ra_get_acc(imu660_data_buffer);
// 备注信息     
//-------------------------------------------------------------------------------------------------------------------
imu660ra_state_enum imu660ra_get_acc (imu660ra_measurement_data_struct *measurement_data);

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     获取 IMU660RA 陀螺仪数据
// 参数说明     *measurement_data       IMU660RA 的测量数据缓冲指针
// 返回参数     imu660ra_state_enum     IMU660RA 状态码 详见 zf_device_imu660ra.h 中 imu660ra_state_enum 定义
// 使用示例     imu660ra_get_gyro(imu660_data_buffer);
// 备注信息     
//-------------------------------------------------------------------------------------------------------------------
imu660ra_state_enum imu660ra_get_gyro (imu660ra_measurement_data_struct *measurement_data);

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     IMU660RA 配置模块工作参数
// 参数说明     item                    IMU660RA 配置参照 zf_device_imu660ra.h 中 imu660ra_config_item_enum 枚举体定义
// 返回参数     imu660ra_state_enum     IMU660RA 状态码 详见 zf_device_imu660ra.h 中 imu660ra_state_enum 定义
// 使用示例     imu660ra_set_config(item);
// 备注信息
//-------------------------------------------------------------------------------------------------------------------
imu660ra_state_enum imu660ra_set_config (imu660ra_config_item_enum item);

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     初始化 IMU660RA
// 参数说明     void
// 返回参数     imu660ra_state_enum     IMU660RA 状态码 详见 zf_device_imu660ra.h 中 imu660ra_state_enum 定义
// 使用示例     imu660ra_init(imu660_data_buffer);
// 备注信息
//-------------------------------------------------------------------------------------------------------------------
imu660ra_state_enum imu660ra_init (void);
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Part   End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

#endif

