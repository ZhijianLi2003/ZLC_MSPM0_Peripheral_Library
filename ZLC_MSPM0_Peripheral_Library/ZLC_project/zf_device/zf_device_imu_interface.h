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
* 文件名称          zf_device_imu_interface
* 公司名称          成都逐飞科技有限公司
* 版本信息          查看 libraries/doc 文件夹内 version 文件 版本说明
* 开发环境          MDK 5.38a
* 适用平台          MSPM0G3507
* 店铺链接          https://seekfree.taobao.com/
********************************************************************************************************************/

/*********************************************************************************************************************
* 本文件的作用是方便 IMU 的任意平台适配
* 内容为将 IMU 相关的接口进行解耦整合
* 在移植到新的平台时 只需要实现了本文件的接口
* 就可以直接适配 SeekFree 所有的 V4 库 IMU 器件
********************************************************************************************************************/

#ifndef _zf_device_imu_interface_h_
#define _zf_device_imu_interface_h_

// zf_common 层 类型定义 引用
#include "zf_common_typedef.h"

#include "board.h"
#include "ti_msp_dl_config.h"

// 此处定义 IMU 相关的接口资源 这里允许用户修改
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Part Start >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#define IMU_INTERFACE_SPI           ( 0 )                                       // 使用硬件 SPI 方式驱动
#define IMU_INTERFACE_SOFT_IIC      ( 1 )                                       // 使用软件 IIC 方式驱动
#define IMU_INTERFACE_IIC           ( 2 )                                       // 使用硬件 IIC 方式驱动

#define IMU_SPI_INDEX               ( SPI_FOR_IMU_INST )
#define IMU_CS_PORT                 ( SPI_FOR_IMU_CS_PORT )
#define IMU_CS_PIN                  ( SPI_FOR_IMU_CS_PIN_8_PIN )
#define IMU_CS(x)                   ((x) ? (DL_GPIO_setPins(IMU_CS_PORT, IMU_CS_PIN)): (DL_GPIO_clearPins(IMU_CS_PORT, IMU_CS_PIN)))

typedef void    (*imu_delay_ms_func             )   (uint32 parameter);

typedef uint8   (*imu_assert_func               )   (uint8 pass, char *str, char *file, int line);

typedef void    (*imu_write_8bit_register_func  )   (uint8 addr, uint8 reg, uint8 data);
typedef void    (*imu_write_8bit_registers_func )   (uint8 addr, uint8 reg, const uint8 *data, uint32 len);
typedef uint8   (*imu_read_8bit_register_func   )   (uint8 addr, uint8 reg);
typedef void    (*imu_read_8bit_registers_func  )   (uint8 addr, uint8 reg, uint8 *data, uint32 len);

typedef struct                                                                  // IMU660RA 模块化解耦结构
{
    uint8                           interface_type          ;                   // 必须要的接口类型

    imu_delay_ms_func               delay_ms                ;                   // 延时接口 ms 级别延时

    imu_assert_func                 assert                  ;                   // 断言接口

    imu_write_8bit_register_func    write_8bit_register     ;                   // 写寄存器
    imu_write_8bit_registers_func   write_8bit_registers    ;                   // 连续写寄存器
    imu_read_8bit_register_func     read_8bit_register      ;                   // 读寄存器
    imu_read_8bit_registers_func    read_8bit_registers     ;                   // 连续读寄存器
}imu_interface_obj_struct;

extern imu_interface_obj_struct imu_interface_default_obj;
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Part   End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

// 此处列举 本文件的所有函数声明 [ 其中包括宏定义函数 ] 这里不允许用户修改
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Part Start >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//-------------------------------------------------------------------------------------------------------------------
// 函数简介     IMU 延时
// 参数说明     ms              毫秒数
// 返回参数     void
// 使用示例     system_delay_ms(ms);
// 备注信息     
//-------------------------------------------------------------------------------------------------------------------
void imu_delay_ms (uint32 ms);

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     IMU 断言接口定义
// 参数说明     pass            断言判断条件
// 参数说明     *str            断言生效时应该输出的信息
// 参数说明     *file           文件路径信息
// 参数说明     line            报错行数
// 返回参数     uint8           ZF_NO_ERROR - 0 - 正常 /  !ZF_NO_ERROR - !0 - 异常
// 使用示例     imu_assert(pass, str, file, line);
// 备注信息     
//-------------------------------------------------------------------------------------------------------------------
uint8 imu_assert (uint8 pass, char *str, char *file, int line);

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     IMU 写寄存器 8bit
// 参数说明     addr            IIC 器件地址 非 IIC 器件就填 0
// 参数说明     reg             寄存器地址
// 参数说明     data            数据
// 返回参数     void
// 使用示例     imu_write_8bit_register(addr, reg, data);
// 备注信息     
//-------------------------------------------------------------------------------------------------------------------
void imu_write_8bit_register (uint8 addr, uint8 reg, uint8 data);

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     IMU 写寄存器 8bit
// 参数说明     addr            IIC 器件地址 非 IIC 器件就填 0
// 参数说明     reg             寄存器地址
// 参数说明     data            数据缓冲区
// 参数说明     len             数据长度
// 返回参数     void
// 使用示例     imu_write_8bit_registers(addr, reg, data, len);
// 备注信息     
//-------------------------------------------------------------------------------------------------------------------
void imu_write_8bit_registers (uint8 addr, uint8 reg, const uint8 *data, uint32 len);

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     IMU 读寄存器 8bit
// 参数说明     addr            IIC 器件地址 非 IIC 器件就填 0
// 参数说明     reg             寄存器地址
// 返回参数     uint8           数据
// 使用示例     imu_read_8bit_register(addr, reg);
// 备注信息     
//-------------------------------------------------------------------------------------------------------------------
uint8 imu_read_8bit_register (uint8 addr, uint8 reg);

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     IMU 读数据 8bit
// 参数说明     addr            IIC 器件地址 非 IIC 器件就填 0
// 参数说明     reg             寄存器地址
// 参数说明     data            数据缓冲区
// 参数说明     len             数据长度
// 返回参数     void
// 使用示例     imu_read_8bit_registers(addr, reg, data, len);
// 备注信息     
//-------------------------------------------------------------------------------------------------------------------
void imu_read_8bit_registers (uint8 addr, uint8 reg, uint8 *data, uint32 len);

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     IMU 接口注销初始化
// 参数说明     void
// 返回参数     uint8           0-成功 1-失败
// 使用示例     imu_interface_deinit(addr);
// 备注信息     
//-------------------------------------------------------------------------------------------------------------------
uint8 imu_interface_deinit (void);

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     IMU 接口初始化 内部调用
// 参数说明     void
// 返回参数     uint8           0-成功 1-失败
// 使用示例     imu_interface_init();
// 备注信息     
//-------------------------------------------------------------------------------------------------------------------
uint8 imu_interface_init (void);
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Part   End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

#endif
