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

// zf_common 层引用
#include "zf_common_debug.h"

// 自身头文件
#include "zf_device_imu_interface.h"

// 此处定义 本文件用使用的变量与对象等 这里不允许用户修改
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Part Start >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
imu_interface_obj_struct imu_interface_default_obj = 
{
    IMU_INTERFACE_SPI,
    imu_delay_ms,
    imu_assert,
    imu_write_8bit_register,
    imu_write_8bit_registers,
    imu_read_8bit_register,
    imu_read_8bit_registers,
};
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Part   End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

// 此处定义 IMU 相关的接口实现 这里不允许用户修改
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Part Start >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//-------------------------------------------------------------------------------------------------------------------
// 函数简介     IMU 延时
// 参数说明     ms              毫秒数
// 返回参数     void
// 使用示例     system_delay_ms(ms);
// 备注信息     
//-------------------------------------------------------------------------------------------------------------------
ZF_WEAK void imu_delay_ms (uint32 ms)
{
    delay_ms(ms);
}

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
ZF_WEAK uint8 imu_assert (uint8 pass, char *str, char *file, int line)
{
    return (pass ? ZF_NO_ERROR : debug_message_handler(ZF_DEBUG_OUTPUT_LEVEL_DEVICE, (pass), (str), file, line));
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     IMU SPI 通信接口
// 参数说明     *data_out       输出数据
// 参数说明     *data_in        输入数据
// 参数说明     data_len        数据量
// 返回参数     void
// 使用示例     spi_transfer_8bit_register(data_out, data_in, data_len);
// 备注信息     
//-------------------------------------------------------------------------------------------------------------------
ZF_WEAK void spi_transfer_8bit_register (const uint8 *data_out, uint8 *data_in, uint32 data_len)
{
    while(data_len --)
    {
        DL_SPI_transmitData8(IMU_SPI_INDEX, *data_out ++);
        while(DL_SPI_isBusy(IMU_SPI_INDEX));
        if(NULL != data_in)
        {
            *data_in ++ = DL_SPI_receiveData8(IMU_SPI_INDEX);
            while(DL_SPI_isBusy(IMU_SPI_INDEX));
        }
    }
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     IMU 写寄存器 8bit
// 参数说明     addr            IIC 器件地址 非 IIC 器件就填 0
// 参数说明     reg             寄存器地址
// 参数说明     data            数据
// 返回参数     void
// 使用示例     imu_write_8bit_register(addr, reg, data);
// 备注信息     
//-------------------------------------------------------------------------------------------------------------------
ZF_WEAK void imu_write_8bit_register (uint8 addr, uint8 reg, uint8 data)
{
#if (IMU_INTERFACE_SPI == IMU_INTERFACE_TYPE)
    IMU_CS(0);
    
    DL_SPI_transmitData8(IMU_SPI_INDEX, reg);
    while(DL_SPI_isBusy(IMU_SPI_INDEX));
    DL_SPI_receiveData8(IMU_SPI_INDEX);
    while(DL_SPI_isBusy(IMU_SPI_INDEX));
    
    DL_SPI_transmitData8(IMU_SPI_INDEX, data);
    while(DL_SPI_isBusy(IMU_SPI_INDEX));
    DL_SPI_receiveData8(IMU_SPI_INDEX);
    while(DL_SPI_isBusy(IMU_SPI_INDEX));
    
    IMU_CS(1);
#elif (IMU_INTERFACE_SOFT_IIC == IMU_INTERFACE_TYPE)
    soft_iic_write_8bit_register(IMU_SOFT_IIC_INDEX, addr, reg, data);
#elif (IMU_INTERFACE_IIC == IMU_INTERFACE_TYPE)
    iic_write_8bit_register(IMU_IIC_INDEX, addr, reg, data);
#endif
}

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
ZF_WEAK void imu_write_8bit_registers (uint8 addr, uint8 reg, const uint8 *data, uint32 len)
{
#if (IMU_INTERFACE_SPI == IMU_INTERFACE_TYPE)
    IMU_CS(0);
    
    DL_SPI_transmitData8(IMU_SPI_INDEX, reg);
    while(DL_SPI_isBusy(IMU_SPI_INDEX));
    DL_SPI_receiveData8(IMU_SPI_INDEX);
    while(DL_SPI_isBusy(IMU_SPI_INDEX));
    
    uint32 send = 0;
    while(len > send)
    {
        DL_SPI_transmitData8(IMU_SPI_INDEX, *(data + send));
        while(DL_SPI_isBusy(IMU_SPI_INDEX));
        DL_SPI_receiveData8(IMU_SPI_INDEX);
        while(DL_SPI_isBusy(IMU_SPI_INDEX));
        send ++;
    }
    IMU_CS(1);
#elif (IMU_INTERFACE_SOFT_IIC == IMU_INTERFACE_TYPE)
    soft_iic_write_8bit_registers(IMU_SOFT_IIC_INDEX, addr, reg, data, len);
#elif (IMU_INTERFACE_IIC == IMU_INTERFACE_TYPE)
    iic_write_8bit_registers(IMU_IIC_INDEX, addr, reg, data, len);
#endif
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     IMU 读寄存器 8bit
// 参数说明     addr            IIC 器件地址 非 IIC 器件就填 0
// 参数说明     reg             寄存器地址
// 返回参数     uint8           数据
// 使用示例     imu_read_8bit_register(addr, reg);
// 备注信息     
//-------------------------------------------------------------------------------------------------------------------
ZF_WEAK uint8 imu_read_8bit_register (uint8 addr, uint8 reg)
{
#if (IMU_INTERFACE_SPI == IMU_INTERFACE_TYPE)
    uint8 data = 0;
    IMU_CS(0);
    
    DL_SPI_transmitData8(IMU_SPI_INDEX, reg);
    while(DL_SPI_isBusy(IMU_SPI_INDEX));
    DL_SPI_receiveData8(IMU_SPI_INDEX);
    while(DL_SPI_isBusy(IMU_SPI_INDEX));
    
    DL_SPI_transmitData8(IMU_SPI_INDEX, 0xFF);
    while(DL_SPI_isBusy(IMU_SPI_INDEX));
    data = DL_SPI_receiveData8(IMU_SPI_INDEX);
    while(DL_SPI_isBusy(IMU_SPI_INDEX));
    
    IMU_CS(1);
    return data;
#elif (IMU_INTERFACE_SOFT_IIC == IMU_INTERFACE_TYPE)
    return soft_iic_read_8bit_register(IMU_SOFT_IIC_INDEX, addr, reg);
#elif (IMU_INTERFACE_IIC == IMU_INTERFACE_TYPE)
    return iic_read_8bit_register(IMU_IIC_INDEX, addr, reg);
#endif
}

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
ZF_WEAK void imu_read_8bit_registers (uint8 addr, uint8 reg, uint8 *data, uint32 len)
{
#if (IMU_INTERFACE_SPI == IMU_INTERFACE_TYPE)
    IMU_CS(0);
    
    DL_SPI_transmitData8(IMU_SPI_INDEX, reg);
    while(DL_SPI_isBusy(IMU_SPI_INDEX));
    DL_SPI_receiveData8(IMU_SPI_INDEX);
    while(DL_SPI_isBusy(IMU_SPI_INDEX));
    
    uint32 read = 0;
    while(len > read)
    {
        DL_SPI_transmitData8(IMU_SPI_INDEX, 0xFF);
        while(DL_SPI_isBusy(IMU_SPI_INDEX));
        *(data + read) = DL_SPI_receiveData8(IMU_SPI_INDEX);
        while(DL_SPI_isBusy(IMU_SPI_INDEX));
        
        read ++;
    }
    IMU_CS(1);
#elif (IMU_INTERFACE_SOFT_IIC == IMU_INTERFACE_TYPE)
    soft_iic_read_8bit_registers(IMU_SOFT_IIC_INDEX, addr, reg, data, len);
#elif (IMU_INTERFACE_IIC == IMU_INTERFACE_TYPE)
    iic_read_8bit_registers(IMU_IIC_INDEX, addr, reg, data, len);
#endif
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     IMU 接口注销初始化
// 参数说明     void
// 返回参数     uint8           0-成功 1-失败
// 使用示例     imu_interface_deinit(addr);
// 备注信息     
//-------------------------------------------------------------------------------------------------------------------
ZF_WEAK uint8 imu_interface_deinit (void)
{
    uint8 return_state = 1;
    do
    {
        return_state = 0;
    }while(0);
    return return_state;
}

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     IMU 接口初始化 内部调用
// 参数说明     void
// 返回参数     uint8           0-成功 1-失败
// 使用示例     imu_interface_init();
// 备注信息     
//-------------------------------------------------------------------------------------------------------------------
ZF_WEAK uint8 imu_interface_init (void)
{
    uint8 return_state = 1;
    do
    {
        return_state = 0;
    }while(0);
    return return_state;
}
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Part   End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
