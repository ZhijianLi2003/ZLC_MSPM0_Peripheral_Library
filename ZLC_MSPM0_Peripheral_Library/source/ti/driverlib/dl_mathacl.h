/*
 * Copyright (c) 2020, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*!****************************************************************************
 *  @file       dl_mathacl.h
 *  @brief      Math Accelerator Driver Library
 *  @defgroup   MATHACL Math Accelerator (MATHACL)
 *
 *  @anchor ti_dl_dl_m0p_mathacl_Overview
 *  # Overview
 *
 *  The Math Accelerator Driver Library provides software to control the
 *  onboard Math Accelerator hardware.
 *
 ******************************************************************************
 */
/** @addtogroup MATHACL
 * @{
 */
#ifndef ti_dl_dl_mathacl__include
#define ti_dl_dl_mathacl__include

#include <stdbool.h>
#include <stdint.h>

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/dl_common.h>

#ifdef __MSPM0_HAS_MATHACL__

#ifdef __cplusplus
extern "C" {
#endif

/* clang-format off */

/** @addtogroup DL_MATHACL_STATUS
 *  @{
 */

/*!
 * @brief MATHACL operation underflow status
 */
#define DL_MATHACL_STATUS_UNDERFLOW               (MATHACL_STATUS_UF_UNDERFLOW)

/*!
 * @brief MATHACL generic underflow bitmask for MATHACL Status register comparison
 */
#define DL_MATHACL_STATUS_UF_MASK                      (MATHACL_STATUS_UF_MASK)

/*!
 * @brief MATHACL operation overflow status
 */
#define DL_MATHACL_STATUS_OVERFLOW                (MATHACL_STATUS_OVF_OVERFLOW)

/*!
 * @brief MATHACL generic overflow bitmask for MATHACL Status register comparison
 */
#define DL_MATHACL_STATUS_OVF_MASK                    (MATHACL_STATUS_OVF_MASK)

/*!
 * @brief MATHACL divide by error status
 */
#define DL_MATHACL_STATUS_ERR_DIVBY0                (MATHACL_STATUS_ERR_DIVBY0)

/*!
 * @brief MATHACL generic error bits mask
 */
#define DL_MATHACL_STATUS_ERR_MASK                    (MATHACL_STATUS_ERR_MASK)

/*!
 * @brief Alias for one-shot sin/cos operation
 */
#define DL_MathACL_startSinCosOperation(MATHACL, config, op)    DL_MathACL_configOperation(MATHACL, config, op, 0)

/*!
 * @brief Alias for one-shot inverse 4-quadrant arctan operation
 */
#define DL_MathACL_startArcTan2Operation(MATHACL, config, x, y)    DL_MathACL_configOperation(MATHACL, config, x, y)

/*!
 * @brief Alias for one-shot arctan operation
 */
#define DL_MathACL_startArcTanOperation(MATHACL, config, x)    DL_MathACL_configOperation(MATHACL, config, x, 0)

/*!
 * @brief Alias for one-shot divide
 */
#define DL_MathACL_startDivOperation(MATHACL, config, num, den)    DL_MathACL_configOperation(MATHACL, config, num, den)

/*!
 * @brief Alias for one-shot square root operation
 */
#define DL_MathACL_startSqrtOperation(MATHACL, config, sqrt)    DL_MathACL_configOperation(MATHACL, config, sqrt, 0)

/*!
 * @brief Alias for one-shot multiply operation
 */
#define DL_MathACL_startMpyOperation(MATHACL, config, multicand, multiplier)    DL_MathACL_configOperation(MATHACL, config, multicand, multiplier)

/** @}*/

/* clang-format on */

/*! @enum DL_MATHACL_OP_TYPE */
typedef enum {
    /*! Sin or cosine operation */
    DL_MATHACL_OP_TYPE_SINCOS = MATHACL_CTL_FUNC_SINCOS,
    /*! Arc tangent 2 operation -- takes in X, Y values */
    DL_MATHACL_OP_TYPE_ARCTAN2 = MATHACL_CTL_FUNC_ATAN2,
    /*! Divide operation -- takes in numerator, denominator, division type */
    DL_MATHACL_OP_TYPE_DIV = MATHACL_CTL_FUNC_DIV,
    /*! Square root operation -- requires that a scaling factor be provided as well  */
    DL_MATHACL_OP_TYPE_SQRT = MATHACL_CTL_FUNC_SQRT,
    /*! Multiply operation returns 32-bit result -- takes in two operands */
    DL_MATHACL_OP_TYPE_MPY_32 = MATHACL_CTL_FUNC_MPY32,
    /*! Square operation returns 32-bit result -- takes in one operand. Supports
     * Q and int data formats. Enable saturation with @ref
     * DL_MathACL_enableSaturation and check @ref DL_MATHACL_STATUS_OVERFLOW
     * for overflow. */
    DL_MATHACL_OP_TYPE_SQUARE_32 = MATHACL_CTL_FUNC_SQUARE32,
    /*! Multiply operation returns 64-bit result -- takes in two operands */
    DL_MATHACL_OP_TYPE_MPY_64 = MATHACL_CTL_FUNC_MPY64,
    /*! Square operation returns 64-bit result -- takes in one operand */
    DL_MATHACL_OP_TYPE_SQUARE_64 = MATHACL_CTL_FUNC_SQUARE64,
    /*! Multiply and Accumulate operation -- takes in two operands. Supports Q
     * and int data formats. Enable saturation with @ref
     * DL_MathACL_enableSaturation and check @ref DL_MATHACL_STATUS_OVERFLOW
     * for overflow. */
    DL_MATHACL_OP_TYPE_MAC = MATHACL_CTL_FUNC_MAC,
    /*! Square and Accumulate operation -- takes in one operand. Supports Q and
     * int data formats. Enable saturation with @ref
     * DL_MathACL_enableSaturation and check @ref DL_MATHACL_STATUS_OVERFLOW
     * for overflow. */
    DL_MATHACL_OP_TYPE_SAC = MATHACL_CTL_FUNC_SAC,
} DL_MATHACL_OP_TYPE;

/*! @enum DL_MATHACL_Q_TYPE */
typedef enum {
    /*! Q0 Operand Type */
    DL_MATHACL_Q_TYPE_Q0 = MATHACL_CTL_QVAL_Q0,
    /*! Q1 Operand Type */
    DL_MATHACL_Q_TYPE_Q1 = MATHACL_CTL_QVAL_Q1,
    /*! Q2 Operand Type */
    DL_MATHACL_Q_TYPE_Q2 = MATHACL_CTL_QVAL_Q2,
    /*! Q3 Operand Type */
    DL_MATHACL_Q_TYPE_Q3 = MATHACL_CTL_QVAL_Q3,
    /*! Q4 Operand Type */
    DL_MATHACL_Q_TYPE_Q4 = MATHACL_CTL_QVAL_Q4,
    /*! Q5 Operand Type */
    DL_MATHACL_Q_TYPE_Q5 = MATHACL_CTL_QVAL_Q5,
    /*! Q6 Operand Type */
    DL_MATHACL_Q_TYPE_Q6 = MATHACL_CTL_QVAL_Q6,
    /*! Q7 Operand Type */
    DL_MATHACL_Q_TYPE_Q7 = MATHACL_CTL_QVAL_Q7,
    /*! Q8 Operand Type */
    DL_MATHACL_Q_TYPE_Q8 = MATHACL_CTL_QVAL_Q8,
    /*! Q9 Operand Type */
    DL_MATHACL_Q_TYPE_Q9 = MATHACL_CTL_QVAL_Q9,
    /*! Q10 Operand Type */
    DL_MATHACL_Q_TYPE_Q10 = MATHACL_CTL_QVAL_Q10,
    /*! Q11 Operand Type */
    DL_MATHACL_Q_TYPE_Q11 = MATHACL_CTL_QVAL_Q11,
    /*! Q12 Operand Type */
    DL_MATHACL_Q_TYPE_Q12 = MATHACL_CTL_QVAL_Q12,
    /*! Q13 Operand Type */
    DL_MATHACL_Q_TYPE_Q13 = MATHACL_CTL_QVAL_Q13,
    /*! Q14 Operand Type */
    DL_MATHACL_Q_TYPE_Q14 = MATHACL_CTL_QVAL_Q14,
    /*! Q15 Operand Type */
    DL_MATHACL_Q_TYPE_Q15 = MATHACL_CTL_QVAL_Q15,
    /*! Q16 Operand Type */
    DL_MATHACL_Q_TYPE_Q16 = MATHACL_CTL_QVAL_Q16,
    /*! Q17 Operand Type */
    DL_MATHACL_Q_TYPE_Q17 = MATHACL_CTL_QVAL_Q17,
    /*! Q18 Operand Type */
    DL_MATHACL_Q_TYPE_Q18 = MATHACL_CTL_QVAL_Q18,
    /*! Q19 Operand Type */
    DL_MATHACL_Q_TYPE_Q19 = MATHACL_CTL_QVAL_Q19,
    /*! Q20 Operand Type */
    DL_MATHACL_Q_TYPE_Q20 = MATHACL_CTL_QVAL_Q20,
    /*! Q21 Operand Type */
    DL_MATHACL_Q_TYPE_Q21 = MATHACL_CTL_QVAL_Q21,
    /*! Q22 Operand Type */
    DL_MATHACL_Q_TYPE_Q22 = MATHACL_CTL_QVAL_Q22,
    /*! Q23 Operand Type */
    DL_MATHACL_Q_TYPE_Q23 = MATHACL_CTL_QVAL_Q23,
    /*! Q24 Operand Type */
    DL_MATHACL_Q_TYPE_Q24 = MATHACL_CTL_QVAL_Q24,
    /*! Q25 Operand Type */
    DL_MATHACL_Q_TYPE_Q25 = MATHACL_CTL_QVAL_Q25,
    /*! Q26 Operand Type */
    DL_MATHACL_Q_TYPE_Q26 = MATHACL_CTL_QVAL_Q26,
    /*! Q27 Operand Type */
    DL_MATHACL_Q_TYPE_Q27 = MATHACL_CTL_QVAL_Q27,
    /*! Q28 Operand Type */
    DL_MATHACL_Q_TYPE_Q28 = MATHACL_CTL_QVAL_Q28,
    /*! Q29 Operand Type */
    DL_MATHACL_Q_TYPE_Q29 = MATHACL_CTL_QVAL_Q29,
    /*! Q30 Operand Type */
    DL_MATHACL_Q_TYPE_Q30 = MATHACL_CTL_QVAL_Q30,
    /*! Q31 Operand Type */
    DL_MATHACL_Q_TYPE_Q31 = MATHACL_CTL_QVAL_Q31,
} DL_MATHACL_Q_TYPE;

/*! @enum DL_MATHACL_OPSIGN */
typedef enum {
    /*! Unsigned operation type */
    DL_MATHACL_OPSIGN_UNSIGNED = MATHACL_CTL_OPTYPE_UNSIGNED,
    /*! Signed operation type */
    DL_MATHACL_OPSIGN_SIGNED = MATHACL_CTL_OPTYPE_SIGNED,
} DL_MATHACL_OPSIGN;

/**
 * @brief Configuration struct for @ref DL_MathACL_configOperation.
 */
typedef struct {
    /*! Operation type. Set to one of @ref DL_MATHACL_OP_TYPE */
    DL_MATHACL_OP_TYPE opType;
    /*! Operation sign type. One of @ref DL_MATHACL_OPSIGN */
    DL_MATHACL_OPSIGN opSign;
    /*! Number of iterations, for applicable operation types. Supported types
        include trigonometric operations and square root. */
    uint32_t iterations;
    /*! Scaling factor on the input in division operations. Leave as 0
        for non-division operations. */
    uint32_t scaleFactor;
    /*! Q value for the operand inputs for the operation */
    DL_MATHACL_Q_TYPE qType;
} DL_MathACL_operationConfig;

/**
 * @brief Enables power on MATHACL module
 *
 * @param mathacl       Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_MathACL_enablePower(MATHACL_Regs *mathacl)
{
    mathacl->GPRCM.PWREN =
        MATHACL_PWREN_KEY_UNLOCK_W | MATHACL_PWREN_ENABLE_ENABLE;
}

/**
 * @brief Disable power on MATHACL module
 *
 * @param mathacl       Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_MathACL_disablePower(MATHACL_Regs *mathacl)
{
    mathacl->GPRCM.PWREN =
        MATHACL_PWREN_KEY_UNLOCK_W | MATHACL_PWREN_ENABLE_DISABLE;
}
/**
 * @brief Resets the MATHACL module
 *
 * @param mathacl       Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_MathACL_reset(MATHACL_Regs *mathacl)
{
    mathacl->GPRCM.RSTCTL =
        MATHACL_RSTCTL_RESETASSERT_ASSERT | MATHACL_RSTCTL_KEY_UNLOCK_W;
}

/**
 * @brief Returns if MATHACL peripheral was reset
 *
 * @param mathacl        Pointer to the register overlay for the MATHACL peripheral
 *
 * @return true if peripheral was reset
 * @return false if peripheral wasn't reset
 *
 */
__STATIC_INLINE bool DL_MathACL_isReset(MATHACL_Regs *mathacl)
{
    return (mathacl->GPRCM.STAT & MATHACL_STAT_RESETSTKY_MASK) ==
           MATHACL_STAT_RESETSTKY_RESET;
}

/**
 * @brief Enable saturation
 *
 * This bit is shared among @ref DL_MATHACL_OP_TYPE_DIV, @ref
 * DL_MATHACL_OP_TYPE_SQUARE_32, @ref DL_MATHACL_OP_TYPE_MPY_32, @ref
 * DL_MATHACL_OP_TYPE_MAC, and @ref DL_MATHACL_OP_TYPE_SAC operations.
 * When saturation is enabled, if there is an overflow event during an
 * operation, then the result will saturate to the maximum value.
 *
 * @param mathacl       Pointer to the register overlay for the peripheral
 *
 * @sa    DL_MATHACL_STATUS_OVERFLOW
 */
__STATIC_INLINE void DL_MathACL_enableSaturation(MATHACL_Regs *mathacl)
{
    mathacl->CTL |= MATHACL_CTL_SATEN_ENABLE;
}

/**
 * @brief Disable saturation
 *
 * When saturation is disabled, if there is an overflow event during an
 * operation, then the result will overflow to an unknown value.
 *
 * @param mathacl       Pointer to the register overlay for the peripheral
 */
__STATIC_INLINE void DL_MathACL_disableSaturation(MATHACL_Regs *mathacl)
{
    mathacl->CTL &= ~(MATHACL_CTL_SATEN_MASK);
}

/**
 * @brief Returns if saturation is enabled
 *
 * @param mathacl     Pointer to the register overlay for the MATHACL peripheral
 *
 * @return true if saturation is enabled
 * @return false if saturation is not enabled
 *
 */
__STATIC_INLINE bool DL_MathACL_isSaturationEnabled(MATHACL_Regs *mathacl)
{
    return (
        (mathacl->CTL & MATHACL_CTL_SATEN_MASK) == MATHACL_CTL_SATEN_ENABLE);
}

/**
 *  @brief      Load Operand one into the math accelerator

 *  @param[in]  mathacl Pointer to the register overlay for the peripheral
 *
 *  @param[in]  op      Operand one to load into the Math Accelerator
 *
 */
__STATIC_INLINE void DL_MathACL_setOperandOne(
    MATHACL_Regs *mathacl, uint32_t op)
{
    mathacl->OP1 = op;
}

/**
 *  @brief      Load Operand two into the math accelerator
 *
 *  @param[in]  mathacl Pointer to the register overlay for the peripheral
 *
 *  @param[in]  op  Operand two to load into the Math Accelerator
 *
 */
__STATIC_INLINE void DL_MathACL_setOperandTwo(
    MATHACL_Regs *mathacl, uint32_t op)
{
    mathacl->OP2 = op;
}

/**
 *  @param[in]  mathacl Pointer to the register overlay for the peripheral
 *
 *  @brief Returns MATHACL result one register
 *
 *  @return Value stored in MATHACUL Result 1 status
 */
__STATIC_INLINE uint32_t DL_MathACL_getResultOne(MATHACL_Regs *mathacl)
{
    return mathacl->RES1;
}

/**
 *  @param[in]  mathacl Pointer to the register overlay for the peripheral
 *
 *  @brief Returns MATHACL result two register
 *
 *  @return Value stored in MATHACUL Result 2 status
 *
 */
__STATIC_INLINE uint32_t DL_MathACL_getResultTwo(MATHACL_Regs *mathacl)
{
    return mathacl->RES2;
}

/**
 *  @param[in]  mathacl Pointer to the register overlay for the peripheral
 *
 *  @brief Returns MATHACL operation status
 *
 *  @return One of @ref DL_MATHACL_STATUS
 *
 */
__STATIC_INLINE uint32_t DL_MathACL_getStatus(MATHACL_Regs *mathacl)
{
    return mathacl->STATUS;
}

/**
 *  @brief      Clear the overflow status bit
 *
 *  Calling this API clears @ref DL_MATHACL_STATUS_OVERFLOW
 *
 *  @param[in]  mathacl Pointer to the register overlay for the peripheral
 *
 *  @sa         DL_MATHACL_STATUS_OVERFLOW
 */
__STATIC_INLINE void DL_MathACL_clearOverflowStatus(MATHACL_Regs *mathacl)
{
    mathacl->STATUSCLR |= MATHACL_STATUSCLR_CLR_OVF_CLR;
}

/**
 *  @brief      Clear the underflow status bit
 *
 *  Calling this API clears @ref DL_MATHACL_STATUS_UNDERFLOW
 *
 *  @param[in]  mathacl Pointer to the register overlay for the peripheral
 *
 *  @sa         DL_MATHACL_STATUS_UNDERFLOW
 */
__STATIC_INLINE void DL_MathACL_clearUnderflowStatus(MATHACL_Regs *mathacl)
{
    mathacl->STATUSCLR |= MATHACL_STATUSCLR_CLR_UF_CLR;
}

/**
 *  @brief      Clear the error status bit
 *
 *  Calling this API clears @ref DL_MATHACL_STATUS_ERR_MASK
 *
 *  @param[in]  mathacl Pointer to the register overlay for the peripheral
 *
 *  @sa         DL_MATHACL_STATUS_ERR_MASK
 */
__STATIC_INLINE void DL_MathACL_clearErrorStatus(MATHACL_Regs *mathacl)
{
    mathacl->STATUSCLR |= MATHACL_STATUSCLR_CLR_ERR_CLR;
}

/**
 *  @brief      Block until MATHACL_STATUS_BUSY_DONE is active in MATHACL
 *
 *  @param[in]  mathacl  Pointer to the register overlay for the peripheral
 *
 */
__STATIC_INLINE void DL_MathACL_waitForOperation(MATHACL_Regs *mathacl)
{
    while ((mathacl->STATUS & MATHACL_STATUS_BUSY_MASK) ==
           MATHACL_STATUS_BUSY_NOTDONE) {
        ;
    }
}

/**
 *  @brief      Configure and execute a Math accelerator operation
 *
 *  @pre        Call @ref DL_MathACL_clearResults when configuring the MATHACL
 *              for performing @ref DL_MATHACL_OP_TYPE_MAC and
 *              @ref DL_MATHACL_OP_TYPE_SAC operations.
 *
 *  @param[in]  mathacl   Pointer to the register overlay for the peripheral
 *
 *  @param[in]  opConfig  Pointer to the configuration structure for the
 *                        operation
 *
 *  @param[in]  op1       Operand one for the operation
 *
 *  @param[in]  op2       Operand two for the operation. May be left as 0
 *                        if unused
 *
 */
void DL_MathACL_configOperation(MATHACL_Regs *mathacl,
    const DL_MathACL_operationConfig *opConfig, uint32_t op1, uint32_t op2);

/**
 *  @brief      Clears the RES1 register
 *
 *  Clears the Result 1 (RES1) register
 *
 *  @param[in]  mathacl Pointer to the register overlay for the peripheral
 *
 */
__STATIC_INLINE void DL_MathACL_clearResultOne(MATHACL_Regs *mathacl)
{
    mathacl->RES1 = 0;
}

/**
 *  @brief      Clears the RES2 register
 *
 *  Clears the Result 2 (RES2) register
 *
 *  @param[in]  mathacl Pointer to the register overlay for the peripheral
 *
 */
__STATIC_INLINE void DL_MathACL_clearResultTwo(MATHACL_Regs *mathacl)
{
    mathacl->RES2 = 0;
}

/**
 *  @brief      Clears the RES1 and RES2 registers
 *
 *  Clears the Result 1 (RES1) and Result 2 (RES2) registers
 *
 *  @param[in]  mathacl Pointer to the register overlay for the peripheral
 *
 */
__STATIC_INLINE void DL_MathACL_clearResults(MATHACL_Regs *mathacl)
{
    mathacl->RES1 = 0;
    mathacl->RES2 = 0;
}

#ifdef __cplusplus
}
#endif

#endif /* __MSPM0_HAS_MATHACL__ */

#endif /* ti_dl_mathacl__include */
/** @}*/
