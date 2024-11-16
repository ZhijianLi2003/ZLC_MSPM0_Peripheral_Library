/*********************************************************************************************************************
* MSPM0G3507 Opensource Library 即（MSPM0G3507 开源库）是一个基于官方 SDK 接口的第三方开源库
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
* 文件名称          zf_common_typedef
* 公司名称          成都逐飞科技有限公司
* 版本信息          查看 libraries/doc 文件夹内 version 文件 版本说明
* 开发环境          MDK 5.38a
* 适用平台          MSPM0G3507
* 店铺链接          https://seekfree.taobao.com/
********************************************************************************************************************/

#ifndef _zf_common_typedef_h_
#define _zf_common_typedef_h_

#include "stdio.h"
#include "stdint.h"
#include "stdbool.h"
#include "stdarg.h"
#include "string.h"
#include "stdlib.h"

                                                                                // 注释的标准缩进 空行的 20 个 Tab 键为基础

//=================================================== 类型定义 ===================================================
#define USE_ZF_TYPEDEF      (1)                                                 // 是否启用类型定义申明

#if USE_ZF_TYPEDEF
// 数据类型声明
// 尽量使用 stdint.h 定义的类型名称 避免冲突 这里可以裁剪
typedef unsigned char       uint8;                                              // 无符号  8 bits
typedef unsigned short int  uint16;                                             // 无符号 16 bits
typedef unsigned int        uint32;                                             // 无符号 32 bits
typedef unsigned long long  uint64;                                             // 无符号 64 bits

typedef signed char         int8;                                               // 有符号  8 bits
typedef signed short int    int16;                                              // 有符号 16 bits
typedef signed int          int32;                                              // 有符号 32 bits
typedef signed long long    int64;                                              // 有符号 64 bits

typedef volatile uint8      vuint8;                                             // 易变性修饰 无符号  8 bits
typedef volatile uint16     vuint16;                                            // 易变性修饰 无符号 16 bits
typedef volatile uint32     vuint32;                                            // 易变性修饰 无符号 32 bits
typedef volatile uint64     vuint64;                                            // 易变性修饰 无符号 64 bits

typedef volatile int8       vint8;                                              // 易变性修饰 有符号  8 bits
typedef volatile int16      vint16;                                             // 易变性修饰 有符号 16 bits
typedef volatile int32      vint32;                                             // 易变性修饰 有符号 32 bits
typedef volatile int64      vint64;                                             // 易变性修饰 有符号 64 bits

typedef enum
{
    COMMON_DATA_SIZE_8BIT   = 1,                                                // 数据位宽 8bit
    COMMON_DATA_SIZE_16BIT  = 2,                                                // 数据位宽 16bit
    COMMON_DATA_SIZE_32BIT  = 4,                                                // 数据位宽 32bit
}common_data_size_enum;

#define ZF_NO_ERROR     ( 0 )                                                   // 通用状态返回检查值 通常情况下返回 0 代表无异常
#define ZF_ERROR        ( 1 )                                                   // 通用状态返回检查值 通常情况下返回 非 0 值代表异常码

#define ZF_ENABLE       ( 1 )                                                   // 使能 定义
#define ZF_DISABLE      ( 0 )                                                   // 禁止 定义

#define ZF_TRUE         ( 1 )                                                   // 布尔值 真 定义
#define ZF_FALSE        ( 0 )                                                   // 布尔值 假 定义

typedef void    (*void_function_void            )   (void);
typedef void    (*void_function_uint32          )   (uint32 parameter);
typedef void    (*void_function_ptr             )   (void *ptr);

typedef uint32  (*uint32_function_void          )   (void);
typedef uint32  (*uint32_function_uint32        )   (uint32 parameter);
typedef uint32  (*uint32_function_ptr           )   (void *ptr);

typedef void*   (*ptr_function_void             )   (void);
typedef void*   (*ptr_function_uint32           )   (uint32 parameter);
typedef void*   (*ptr_function_ptr              )   (void *ptr);

typedef void    (*void_callback_uint32_ptr      )   (uint32 state, void *ptr);

#endif
//=================================================== 类型定义 ===================================================

//=================================================== IDE 适配定义 ===================================================
#define IDE_MDK         ( 0x01 )
#define IDE_IAR         ( 0x02 )
#define IDE_ADS         ( 0x04 )
#define IDE_MRS         ( 0x08 )

#if defined(__ICCARM__)
#define IDE_TYPE        ( IDE_IAR )
#else
#define IDE_TYPE        ( IDE_MDK )
#endif

#if (IDE_MDK & IDE_TYPE)
// -------------------------- MDK IDE 适配 --------------------------
// MDK 使用 GNUC 工具链
// 内联函数修饰
#define ZF_INLINE           static inline
#define ZF_WEAK             __attribute__((weak))

// 内存对齐与紧凑结构
#define ZF_PACKED           __attribute__((packed))
#define ZF_PACKED_ENABLE    
#define ZF_PACKED_DISABLE   

// 内存屏障指令 用于同步数据与指令 防止工程开优化导致问题
#define ZF_DSB()            __DSB()
#define ZF_ISB()            __ISB()
#define ZF_DMB()            __DMB()

// 文件定位
#define ZF_FILE_MESSAGE     ( __FILE__ )
#define ZF_LINE_MESSAGE     ( __LINE__ )
// -------------------------- MDK IDE 适配 --------------------------
#elif (IDE_IAR & IDE_TYPE)
// -------------------------- IAR IDE 适配 --------------------------
// IAR 使用 ICCARM 工具链
// 内联函数修饰
#define ZF_INLINE           static inline
#define ZF_WEAK             __attribute__((weak))

// 内存对齐与紧凑结构
// IAR 支持 __attribute__((packed)) 因此不需要 _Pragma
#define ZF_PACKED           __attribute__((packed))
#define ZF_PACKED_ENABLE    // _Pragma("pack(push,1)")
#define ZF_PACKED_DISABLE   // _Pragma("pack(pop)")

// 内存屏障指令 用于同步数据与指令 防止工程开优化导致问题
#define ZF_DSB()            __DSB()
#define ZF_ISB()            __ISB()
#define ZF_DMB()            __DMB()

// 文件定位
#define ZF_FILE_MESSAGE     ( __FILE__ )
#define ZF_LINE_MESSAGE     ( __LINE__ )
// -------------------------- IAR IDE 适配 --------------------------
#elif (IDE_ADS & IDE_TYPE)
// -------------------------- ADS IDE 适配 --------------------------
// ADS 使用 ADS* 工具链
// 内联函数修饰
#define ZF_INLINE           static inline
#define ZF_WEAK             __attribute__((weak))

// ADS 仅支持 2/4 字节对齐
#define ZF_PACKED           
#define ZF_PACKED_ENABLE    _Pragma("pack 2")
#define ZF_PACKED_DISABLE   _Pragma("pack 0")

// 内存屏障指令 用于同步数据与指令 防止工程开优化导致问题
#define ZF_DSB()            
#define ZF_ISB()            
#define ZF_DMB()            

// 文件定位
#define ZF_FILE_MESSAGE     ( __FILE__ )
#define ZF_LINE_MESSAGE     ( __LINE__ )
// -------------------------- ADS IDE 适配 --------------------------
#elif (IDE_MRS & IDE_TYPE)
// -------------------------- MRS IDE 适配 --------------------------
// MRS 使用 GNUC 工具链
// 内联函数修饰
#define ZF_INLINE           static inline
#define ZF_WEAK             __attribute__((weak))

// 内存对齐与紧凑结构
#define ZF_PACKED           __attribute__((packed))
#define ZF_PACKED_ENABLE    
#define ZF_PACKED_DISABLE   

// 内存屏障指令 用于同步数据与指令 防止工程开优化导致问题
#define ZF_DSB()            
#define ZF_ISB()            
#define ZF_DMB()            

// 文件定位
#define ZF_FILE_MESSAGE     ( __FILE__ )
#define ZF_LINE_MESSAGE     ( __LINE__ )
// -------------------------- MRS IDE 适配 --------------------------
#else
#error "IDE Type error!"
#endif
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Part   End <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

#endif
