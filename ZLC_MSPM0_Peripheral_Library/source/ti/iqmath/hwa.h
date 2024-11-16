#ifndef __HWA_H
#define __HWA_H

#define DIV_HWA_BASE     0x40410000
#define TRIG_HWA_BASE    DIV_HWA_BASE

#define DIV_CTRL_REG     (DIV_HWA_BASE + 0x1100)
#define DIV_OP1_REG      (DIV_HWA_BASE + 0x1110)
#define DIV_OP2_REG      (DIV_HWA_BASE + 0x1114)
#define DIV_QUOT_REG     (DIV_HWA_BASE + 0x1120)
#define DIV_REM_REG      (DIV_HWA_BASE + 0x1124)

#define TRIG_CTRL_REG    DIV_CTRL_REG
#define TRIG_OP1_REG     DIV_OP1_REG
#define TRIG_OP2_REG     DIV_OP2_REG
#define TRIG_RES1_REG    DIV_QUOT_REG
#define TRIG_RES2_REG    DIV_REM_REG

#endif
