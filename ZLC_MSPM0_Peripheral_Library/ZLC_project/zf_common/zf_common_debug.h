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
* 文件名称          zf_common_debug
* 公司名称          成都逐飞科技有限公司
* 版本信息          查看 libraries/doc 文件夹内 version 文件 版本说明
* 开发环境          MDK 5.38a
* 适用平台          MSPM0G3507
* 店铺链接          https://seekfree.taobao.com/
********************************************************************************************************************/

#ifndef _zf_common_debug_h_
#define _zf_common_debug_h_

// zf_common 层引用
#include "zf_common_typedef.h"

// 此处列举 当前支持的函数列表
// 具体声明在本函数中查看对应注释 具体定义跳转到对应函数定义查看
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Part Start >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// zf_assert                                                                    // 断言函数
// zf_log                                                                       // Log 输出函数

// debug_read_ring_buffer                                                       // 读取 debug 环形缓冲区数据

// debug_message_handler                                                        // debug 调试信息处理函数
// debug_output_struct_init                                                     // debug 输出绑定信息初始化 这个函数一般不由用户调用
// debug_output_init                                                            // debug 输出绑定初始化     这个函数一般不由用户调用
// debug_init                                                                   // debug 串口初始化
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Part   End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//// 此处定义 默认使用的调试输出串口资源 用户可以根据自己的需要进行修改
//// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Part Start >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//#define DEBUG_UART_INDEX                ( UART_1 )                              // 指定 debug uart 所使用的的串口
//#define DEBUG_UART_BAUDRATE             ( 460800 )                              // 指定 debug uart 所使用的的串口波特率
//#define DEBUG_UART_TX_PIN               ( UART1_TX_A9  )                        // 指定 debug uart 所使用的的串口引脚
//#define DEBUG_UART_RX_PIN               ( UART1_RX_A10 )                        // 指定 debug uart 所使用的的串口引脚
//// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Part   End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//// 此处定义 调试输出串口的模式 用户可以根据自己的需要进行修改
//// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Part Start >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//#define DEBUG_UART_USE_INTERRUPT        ( 1 )                                   // 是否启用 debug uart 接收中断
//#if DEBUG_UART_USE_INTERRUPT                                                    // 如果启用 debug uart 接收中断
//#define DEBUG_RING_BUFFER_LEN           ( 64 )                                  // 定义环形缓冲区大小 默认 64byte
//#endif  
//// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Part   End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

// 此处定义 调试输出等级 这里不允许用户修改
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Part Start >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#define DEBUG_OUTPUT_LEVEL_DISABLE      ( 0 )                                   // 禁用调试输出 使用此定义时会跳过调试检查语句
#define DEBUG_OUTPUT_LEVEL_LOG          ( 1 )                                   // Log 调试输出等级 此定义仅仅输出检查报错 不会直接中断程序
#define DEBUG_OUTPUT_LEVEL_ASSERT       ( 2 )                                   // 断言调试输出等级 此定义在检查报错后会输出 Log 并直接中断程序
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Part   End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

// 此处定义 各层级调试输出等级 用户可以根据自己的需要进行修改
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Part Start >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#define ZF_DEBUG_OUTPUT_LEVEL_DRIVER    ( DEBUG_OUTPUT_LEVEL_ASSERT )           // 芯片外设驱动层调试输出等级 默认断言设置
#define ZF_DEBUG_OUTPUT_LEVEL_DEVICE    ( DEBUG_OUTPUT_LEVEL_ASSERT )           // 外接设备驱动层调试输出等级 默认断言设置
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Part   End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

// 此处定义 本文件需要的枚举与对象结构等 这里不允许用户修改
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Part Start >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
typedef enum                                                                    // 枚举 调试输出类型 此定义不允许用户修改
{
    DEBUG_OBJ_TYPE_NULL             = 0,                                        // 未初始化时的默认状态

    DEBUG_OBJ_TYPE_UART             = 1,                                        // 使用串口
    DEBUG_OBJ_TYPE_UART_INTERRUPT   = 2,                                        // 使用串口并且开启接收中断
    DEBUG_OBJ_TYPE_SCREEN           = 3,                                        // 使用屏幕
}debug_obj_type_enum;

typedef struct                                                                  // 结构体 调试输出管理对象 此定义不允许用户修改
{
    debug_obj_type_enum     type_index;                                         // 显示类型

    uint16                  display_x_max;                                      // 屏幕显示范围
    uint16                  display_y_max;                                      // 屏幕显示范围

    uint8                   font_x_size;                                        // 屏幕显示字体大小
    uint8                   font_y_size;                                        // 屏幕显示字体大小

    void                    *device_obj;                                        // 
    union                                                                       // 串口显示函数指针 和 屏幕字符串显示函数指针 共用一个变量地址
    {
        void                (*output_uart)          (const char *str);
        void                (*output_screen)        (void *screen_obj, uint16 x, uint16 y, const char *str);
    };
    void                    (*output_screen_clear)  (void *screen_obj);         // 屏幕清屏函数指针
}debug_obj_struct;
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Part   End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

// 此处定义 芯片外设驱动层调试输出的具体调用策略 用户可以根据自己的需要进行修改
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Part Start >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// 如果是禁用调试输出 直接输出返回值
// 如果是启用调试输出 会在触发条件时根据输出等级进行处理
#if (DEBUG_OUTPUT_LEVEL_DISABLE == ZF_DEBUG_OUTPUT_LEVEL_DRIVER)
#define debug_message_driver_handler(pass, str) (pass ? ZF_NO_ERROR : !ZF_NO_ERROR)
#else
#define debug_message_driver_handler(pass, str) (pass ? ZF_NO_ERROR : debug_message_handler(ZF_DEBUG_OUTPUT_LEVEL_DRIVER, (pass), (str), ZF_FILE_MESSAGE, ZF_LINE_MESSAGE))
#endif
#if (DEBUG_OUTPUT_LEVEL_DISABLE == ZF_DEBUG_OUTPUT_LEVEL_DEVICE)
#define debug_message_device_handler(pass, str) (pass ? ZF_NO_ERROR : !ZF_NO_ERROR)
#else
#define debug_message_device_handler(pass, str) (pass ? ZF_NO_ERROR : debug_message_handler(ZF_DEBUG_OUTPUT_LEVEL_DEVICE, (pass), (str), ZF_FILE_MESSAGE, ZF_LINE_MESSAGE))
#endif
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Part   End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

// 此处列举 本文件的所有函数声明 [ 其中包括宏定义函数 ] 这里不允许用户修改
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Part Start >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//-------------------------------------------------------------------------------------------------------------------
// 函数简介     调试断言
// 参数说明     pass            判断条件 如果条件为真则返回无错误 如果条件为假就触发断言机制
// 返回参数     uint8           ZF_NO_ERROR - 0 - 正常 /  !ZF_NO_ERROR - !0 - 异常
// 使用示例     zf_assert(pass_flag);
// 备注信息     
//-------------------------------------------------------------------------------------------------------------------
#define zf_assert(pass)     (pass ? ZF_NO_ERROR : debug_message_handler(DEBUG_OUTPUT_LEVEL_ASSERT, (pass), (NULL), ZF_FILE_MESSAGE, ZF_LINE_MESSAGE))

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     调试断言
// 参数说明     pass            判断条件 如果条件为真则返回无错误 如果条件为假就触发调试输出
// 参数说明     str             触发输出时需要输出的信息
// 返回参数     uint8           ZF_NO_ERROR - 0 - 正常 /  !ZF_NO_ERROR - !0 - 异常
// 使用示例     zf_log(pass_flag, "Pass flag set.");
// 备注信息     
//-------------------------------------------------------------------------------------------------------------------
#define zf_log(pass, str)   (pass ? ZF_NO_ERROR : debug_message_handler(DEBUG_OUTPUT_LEVEL_LOG, (pass), (str), ZF_FILE_MESSAGE, ZF_LINE_MESSAGE))

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     读取 debug 环形缓冲区数据
// 参数说明     *data       读出数据存放的数组指针
// 返回参数     uint32      读出数据的实际长度
// 使用示例     uint8 data[64]; uint32 len = debug_read_ring_buffer(data);
// 备注信息     本函数需要开启 DEBUG_UART_USE_INTERRUPT 宏定义 否则直接返回
//-------------------------------------------------------------------------------------------------------------------
uint32 debug_read_ring_buffer (uint8 *data);

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     debug 调试信息处理函数
// 参数说明     output_level    输出等级
// 参数说明     pass            条件判断
// 参数说明     *str            输出的信息
// 参数说明     *file           文件名
// 参数说明     line            目标行数
// 返回参数     uint8           返回 pass 判断值
// 使用示例     debug_message_handler(ZF_DEBUG_FILE, 0, "Error", ZF_DEBUG_FILE, ZF_DEBUG_LINE);
// 备注信息     此部分不允许用户更改
//              推荐使用 zf_commmon_debug.h 中的 zf_log(x, str) 接口
//-------------------------------------------------------------------------------------------------------------------
uint8 debug_message_handler (uint8 output_level, uint8 pass, char *str, char *file, int line);

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     debug 输出绑定信息初始化
// 参数说明     *info       debug 输出的信息结构体
// 返回参数     void
// 使用示例     debug_output_struct_init(info);
// 备注信息     这个函数一般不由用户调用
//-------------------------------------------------------------------------------------------------------------------
void debug_output_struct_init (debug_obj_struct *obj);

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     debug 输出绑定初始化
// 参数说明     *info       debug 输出的信息结构体
// 返回参数     void
// 使用示例     debug_output_init(info);
// 备注信息     这个函数一般不由用户调用
//-------------------------------------------------------------------------------------------------------------------
void debug_output_init (debug_obj_struct *obj);

//-------------------------------------------------------------------------------------------------------------------
// 函数简介     debug 串口初始化
// 参数说明     void
// 返回参数     void
// 使用示例     debug_init();
// 备注信息     开源库示例默认调用 但默认禁用中断接收
//-------------------------------------------------------------------------------------------------------------------
void debug_init (void);
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Part   End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

#endif
