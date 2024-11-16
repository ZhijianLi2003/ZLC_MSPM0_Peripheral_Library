/* --COPYRIGHT--,BSD
 * Copyright (c) 2015, Texas Instruments Incorporated
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
 * --/COPYRIGHT--*/
#ifndef __QMATHLIB_H__
#define __QMATHLIB_H__

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C" {
#endif

//*****************************************************************************
//
// The IQ format to be used when the IQ format is not explicitly specified
// (such as _IQcos instead of _IQ16cos).  This value must be between 1 and 30,
// inclusive.
//
//*****************************************************************************
#ifndef GLOBAL_Q
#define GLOBAL_Q 8
#endif

//*****************************************************************************
//
// Include some standard headers.
//
//*****************************************************************************
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>

//*****************************************************************************
//
// Various Useful Constant Definitions:
//
//*****************************************************************************
#define Q15 15
#define Q14 14
#define Q13 13
#define Q12 12
#define Q11 11
#define Q10 10
#define Q9 9
#define Q8 8
#define Q7 7
#define Q6 6
#define Q5 5
#define Q4 4
#define Q3 3
#define Q2 2
#define Q1 1
#ifndef QG
#define QG GLOBAL_Q
#endif

#define MAX_Q_POS INT16_MAX
#define MAX_Q_NEG INT16_MIN
#define MIN_Q_POS 1
#define MIN_Q_NEG -1

//*****************************************************************************
//
// The types for the various Q formats.
//
//*****************************************************************************
typedef int16_t _q15;
typedef int16_t _q14;
typedef int16_t _q13;
typedef int16_t _q12;
typedef int16_t _q11;
typedef int16_t _q10;
typedef int16_t _q9;
typedef int16_t _q8;
typedef int16_t _q7;
typedef int16_t _q6;
typedef int16_t _q5;
typedef int16_t _q4;
typedef int16_t _q3;
typedef int16_t _q2;
typedef int16_t _q1;
typedef int16_t _q;

//*****************************************************************************
//
// Simple multiplies or divides, which are accomplished with simple shifts.
//
//*****************************************************************************
#define _Qmpy2(A) ((A) << 1)
#define _Qmpy4(A) ((A) << 2)
#define _Qmpy8(A) ((A) << 3)
#define _Qmpy16(A) ((A) << 4)
#define _Qmpy32(A) ((A) << 5)
#define _Qmpy64(A) ((A) << 6)
#define _Qdiv2(A) ((A) >> 1)
#define _Qdiv4(A) ((A) >> 2)
#define _Qdiv8(A) ((A) >> 3)
#define _Qdiv16(A) ((A) >> 4)
#define _Qdiv32(A) ((A) >> 5)
#define _Qdiv64(A) ((A) >> 6)

//*****************************************************************************
//
// Convert a value into an Q number.
//
//*****************************************************************************
#define _Q15(A) ((_q15)((A) * ((int32_t) 1 << 15)))
#define _Q14(A) ((_q14)((A) * ((_q14) 1 << 14)))
#define _Q13(A) ((_q13)((A) * ((_q13) 1 << 13)))
#define _Q12(A) ((_q12)((A) * ((_q12) 1 << 12)))
#define _Q11(A) ((_q11)((A) * ((_q11) 1 << 11)))
#define _Q10(A) ((_q10)((A) * ((_q10) 1 << 10)))
#define _Q9(A) ((_q9)((A) * ((_q9) 1 << 9)))
#define _Q8(A) ((_q8)((A) * ((_q8) 1 << 8)))
#define _Q7(A) ((_q7)((A) * ((_q7) 1 << 7)))
#define _Q6(A) ((_q6)((A) * ((_q6) 1 << 6)))
#define _Q5(A) ((_q5)((A) * ((_q5) 1 << 5)))
#define _Q4(A) ((_q4)((A) * ((_q4) 1 << 4)))
#define _Q3(A) ((_q3)((A) * ((_q3) 1 << 3)))
#define _Q2(A) ((_q2)((A) * ((_q2) 1 << 2)))
#define _Q1(A) ((_q1)((A) * ((_q1) 1 << 1)))

#if GLOBAL_Q == 15
#define _Q(A) _Q15(A)
#endif
#if GLOBAL_Q == 14
#define _Q(A) _Q14(A)
#endif
#if GLOBAL_Q == 13
#define _Q(A) _Q13(A)
#endif
#if GLOBAL_Q == 12
#define _Q(A) _Q12(A)
#endif
#if GLOBAL_Q == 11
#define _Q(A) _Q11(A)
#endif
#if GLOBAL_Q == 10
#define _Q(A) _Q10(A)
#endif
#if GLOBAL_Q == 9
#define _Q(A) _Q9(A)
#endif
#if GLOBAL_Q == 8
#define _Q(A) _Q8(A)
#endif
#if GLOBAL_Q == 7
#define _Q(A) _Q7(A)
#endif
#if GLOBAL_Q == 6
#define _Q(A) _Q6(A)
#endif
#if GLOBAL_Q == 5
#define _Q(A) _Q5(A)
#endif
#if GLOBAL_Q == 4
#define _Q(A) _Q4(A)
#endif
#if GLOBAL_Q == 3
#define _Q(A) _Q3(A)
#endif
#if GLOBAL_Q == 2
#define _Q(A) _Q2(A)
#endif
#if GLOBAL_Q == 1
#define _Q(A) _Q1(A)
#endif

//*****************************************************************************
//
// Convert an Q number to a floating point value.
//
//*****************************************************************************
extern float _Q15toF(_q15 A);
extern float _Q14toF(_q14 A);
extern float _Q13toF(_q13 A);
extern float _Q12toF(_q12 A);
extern float _Q11toF(_q11 A);
extern float _Q10toF(_q10 A);
extern float _Q9toF(_q9 A);
extern float _Q8toF(_q8 A);
extern float _Q7toF(_q7 A);
extern float _Q6toF(_q6 A);
extern float _Q5toF(_q5 A);
extern float _Q4toF(_q4 A);
extern float _Q3toF(_q3 A);
extern float _Q2toF(_q2 A);
extern float _Q1toF(_q1 A);

#if GLOBAL_Q == 15
#define _QtoF(A) _Q15toF(A)
#endif
#if GLOBAL_Q == 14
#define _QtoF(A) _Q14toF(A)
#endif
#if GLOBAL_Q == 13
#define _QtoF(A) _Q13toF(A)
#endif
#if GLOBAL_Q == 12
#define _QtoF(A) _Q12toF(A)
#endif
#if GLOBAL_Q == 11
#define _QtoF(A) _Q11toF(A)
#endif
#if GLOBAL_Q == 10
#define _QtoF(A) _Q10toF(A)
#endif
#if GLOBAL_Q == 9
#define _QtoF(A) _Q9toF(A)
#endif
#if GLOBAL_Q == 8
#define _QtoF(A) _Q8toF(A)
#endif
#if GLOBAL_Q == 7
#define _QtoF(A) _Q7toF(A)
#endif
#if GLOBAL_Q == 6
#define _QtoF(A) _Q6toF(A)
#endif
#if GLOBAL_Q == 5
#define _QtoF(A) _Q5toF(A)
#endif
#if GLOBAL_Q == 4
#define _QtoF(A) _Q4toF(A)
#endif
#if GLOBAL_Q == 3
#define _QtoF(A) _Q3toF(A)
#endif
#if GLOBAL_Q == 2
#define _QtoF(A) _Q2toF(A)
#endif
#if GLOBAL_Q == 1
#define _QtoF(A) _Q1toF(A)
#endif

//*****************************************************************************
//
// Saturates an Q number in a given range.
//
//*****************************************************************************
#define _Qsat(A, Pos, Neg) \
    (((A) > (Pos)) ? (Pos) : (((A) < (Neg)) ? (Neg) : (A)))

//*****************************************************************************
//
// Converts an Q number between the global Q format and a specified Q
// format.
//
//*****************************************************************************

#if (GLOBAL_Q >= 15)
#define _QtoQ15(A) ((_q15)(A) >> (GLOBAL_Q - 15))
#define _Q15toQ(A) ((_q15)(A) << (GLOBAL_Q - 15))
#else
#define _QtoQ15(A) ((_q15)(A) << (15 - GLOBAL_Q))
#define _Q15toQ(A) ((_q15)(A) >> (15 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 14)
#define _QtoQ14(A) ((_q14)(A) >> (GLOBAL_Q - 14))
#define _Q14toQ(A) ((_q14)(A) << (GLOBAL_Q - 14))
#else
#define _QtoQ14(A) ((_q14)(A) << (14 - GLOBAL_Q))
#define _Q14toQ(A) ((_q14)(A) >> (14 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 13)
#define _QtoQ13(A) ((_q13)(A) >> (GLOBAL_Q - 13))
#define _Q13toQ(A) ((_q13)(A) << (GLOBAL_Q - 13))
#else
#define _QtoQ13(A) ((_q13)(A) << (13 - GLOBAL_Q))
#define _Q13toQ(A) ((_q13)(A) >> (13 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 12)
#define _QtoQ12(A) ((_q12)(A) >> (GLOBAL_Q - 12))
#define _Q12toQ(A) ((_q12)(A) << (GLOBAL_Q - 12))
#else
#define _QtoQ12(A) ((_q12)(A) << (12 - GLOBAL_Q))
#define _Q12toQ(A) ((_q12)(A) >> (12 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 11)
#define _QtoQ11(A) ((_q11)(A) >> (GLOBAL_Q - 11))
#define _Q11toQ(A) ((_q11)(A) << (GLOBAL_Q - 11))
#else
#define _QtoQ11(A) ((_q11)(A) << (11 - GLOBAL_Q))
#define _Q11toQ(A) ((_q11)(A) >> (11 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 10)
#define _QtoQ10(A) ((_q10)(A) >> (GLOBAL_Q - 10))
#define _Q10toQ(A) ((_q10)(A) << (GLOBAL_Q - 10))
#else
#define _QtoQ10(A) ((_q10)(A) << (10 - GLOBAL_Q))
#define _Q10toQ(A) ((_q10)(A) >> (10 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 9)
#define _QtoQ9(A) ((_q9)(A) >> (GLOBAL_Q - 9))
#define _Q9toQ(A) ((_q9)(A) << (GLOBAL_Q - 9))
#else
#define _QtoQ9(A) ((_q9)(A) << (9 - GLOBAL_Q))
#define _Q9toQ(A) ((_q9)(A) >> (9 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 8)
#define _QtoQ8(A) ((_q8)(A) >> (GLOBAL_Q - 8))
#define _Q8toQ(A) ((_q8)(A) << (GLOBAL_Q - 8))
#else
#define _QtoQ8(A) ((_q8)(A) << (8 - GLOBAL_Q))
#define _Q8toQ(A) ((_q8)(A) >> (8 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 7)
#define _QtoQ7(A) ((_q7)(A) >> (GLOBAL_Q - 7))
#define _Q7toQ(A) ((_q7)(A) << (GLOBAL_Q - 7))
#else
#define _QtoQ7(A) ((_q7)(A) << (7 - GLOBAL_Q))
#define _Q7toQ(A) ((_q7)(A) >> (7 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 6)
#define _QtoQ6(A) ((_q6)(A) >> (GLOBAL_Q - 6))
#define _Q6toQ(A) ((_q6)(A) << (GLOBAL_Q - 6))
#else
#define _QtoQ6(A) ((_q6)(A) << (6 - GLOBAL_Q))
#define _Q6toQ(A) ((_q6)(A) >> (6 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 5)
#define _QtoQ5(A) ((_q5)(A) >> (GLOBAL_Q - 5))
#define _Q5toQ(A) ((_q5)(A) << (GLOBAL_Q - 5))
#else
#define _QtoQ5(A) ((_q5)(A) << (5 - GLOBAL_Q))
#define _Q5toQ(A) ((_q5)(A) >> (5 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 4)
#define _QtoQ4(A) ((_q4)(A) >> (GLOBAL_Q - 4))
#define _Q4toQ(A) ((_q4)(A) << (GLOBAL_Q - 4))
#else
#define _QtoQ4(A) ((_q4)(A) << (4 - GLOBAL_Q))
#define _Q4toQ(A) ((_q4)(A) >> (4 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 3)
#define _QtoQ3(A) ((_q3)(A) >> (GLOBAL_Q - 3))
#define _Q3toQ(A) ((_q3)(A) << (GLOBAL_Q - 3))
#else
#define _QtoQ3(A) ((_q3)(A) << (3 - GLOBAL_Q))
#define _Q3toQ(A) ((_q3)(A) >> (3 - GLOBAL_Q))
#endif

#if (GLOBAL_Q >= 2)
#define _QtoQ2(A) ((_q2)(A) >> (GLOBAL_Q - 2))
#define _Q2toQ(A) ((_q2)(A) << (GLOBAL_Q - 2))
#else
#define _QtoQ2(A) ((_q2)(A) << (2 - GLOBAL_Q))
#define _Q2toQ(A) ((_q2)(A) >> (2 - GLOBAL_Q))
#endif

#define _QtoQ1(A) ((_q1)(A) >> (GLOBAL_Q - 1))
#define _Q1toQ(A) ((_q1)(A) << (GLOBAL_Q - 1))

//*****************************************************************************
//
// Multiplies two Q numbers.
//
//*****************************************************************************
extern _q15 _Q15mpy(_q15 A, _q15 B);
extern _q14 _Q14mpy(_q14 A, _q14 B);
extern _q13 _Q13mpy(_q13 A, _q13 B);
extern _q12 _Q12mpy(_q12 A, _q12 B);
extern _q11 _Q11mpy(_q11 A, _q11 B);
extern _q10 _Q10mpy(_q10 A, _q10 B);
extern _q9 _Q9mpy(_q9 A, _q9 B);
extern _q8 _Q8mpy(_q8 A, _q8 B);
extern _q7 _Q7mpy(_q7 A, _q7 B);
extern _q6 _Q6mpy(_q6 A, _q6 B);
extern _q5 _Q5mpy(_q5 A, _q5 B);
extern _q4 _Q4mpy(_q4 A, _q4 B);
extern _q3 _Q3mpy(_q3 A, _q3 B);
extern _q2 _Q2mpy(_q2 A, _q2 B);
extern _q1 _Q1mpy(_q1 A, _q1 B);

#if GLOBAL_Q == 15
#define _Qmpy(A, B) _Q15mpy(A, B)
#endif
#if GLOBAL_Q == 14
#define _Qmpy(A, B) _Q14mpy(A, B)
#endif
#if GLOBAL_Q == 13
#define _Qmpy(A, B) _Q13mpy(A, B)
#endif
#if GLOBAL_Q == 12
#define _Qmpy(A, B) _Q12mpy(A, B)
#endif
#if GLOBAL_Q == 11
#define _Qmpy(A, B) _Q11mpy(A, B)
#endif
#if GLOBAL_Q == 10
#define _Qmpy(A, B) _Q10mpy(A, B)
#endif
#if GLOBAL_Q == 9
#define _Qmpy(A, B) _Q9mpy(A, B)
#endif
#if GLOBAL_Q == 8
#define _Qmpy(A, B) _Q8mpy(A, B)
#endif
#if GLOBAL_Q == 7
#define _Qmpy(A, B) _Q7mpy(A, B)
#endif
#if GLOBAL_Q == 6
#define _Qmpy(A, B) _Q6mpy(A, B)
#endif
#if GLOBAL_Q == 5
#define _Qmpy(A, B) _Q5mpy(A, B)
#endif
#if GLOBAL_Q == 4
#define _Qmpy(A, B) _Q4mpy(A, B)
#endif
#if GLOBAL_Q == 3
#define _Qmpy(A, B) _Q3mpy(A, B)
#endif
#if GLOBAL_Q == 2
#define _Qmpy(A, B) _Q2mpy(A, B)
#endif
#if GLOBAL_Q == 1
#define _Qmpy(A, B) _Q1mpy(A, B)
#endif

//*****************************************************************************
//
// Multiplies two Q numbers, with rounding.
//
//*****************************************************************************
extern _q15 _Q15rmpy(_q15 A, _q15 B);
extern _q14 _Q14rmpy(_q14 A, _q14 B);
extern _q13 _Q13rmpy(_q13 A, _q13 B);
extern _q12 _Q12rmpy(_q12 A, _q12 B);
extern _q11 _Q11rmpy(_q11 A, _q11 B);
extern _q10 _Q10rmpy(_q10 A, _q10 B);
extern _q9 _Q9rmpy(_q9 A, _q9 B);
extern _q8 _Q8rmpy(_q8 A, _q8 B);
extern _q7 _Q7rmpy(_q7 A, _q7 B);
extern _q6 _Q6rmpy(_q6 A, _q6 B);
extern _q5 _Q5rmpy(_q5 A, _q5 B);
extern _q4 _Q4rmpy(_q4 A, _q4 B);
extern _q3 _Q3rmpy(_q3 A, _q3 B);
extern _q2 _Q2rmpy(_q2 A, _q2 B);
extern _q1 _Q1rmpy(_q1 A, _q1 B);

#if GLOBAL_Q == 15
#define _Qrmpy(A, B) _Q15rmpy(A, B)
#endif
#if GLOBAL_Q == 14
#define _Qrmpy(A, B) _Q14rmpy(A, B)
#endif
#if GLOBAL_Q == 13
#define _Qrmpy(A, B) _Q13rmpy(A, B)
#endif
#if GLOBAL_Q == 12
#define _Qrmpy(A, B) _Q12rmpy(A, B)
#endif
#if GLOBAL_Q == 11
#define _Qrmpy(A, B) _Q11rmpy(A, B)
#endif
#if GLOBAL_Q == 10
#define _Qrmpy(A, B) _Q10rmpy(A, B)
#endif
#if GLOBAL_Q == 9
#define _Qrmpy(A, B) _Q9rmpy(A, B)
#endif
#if GLOBAL_Q == 8
#define _Qrmpy(A, B) _Q8rmpy(A, B)
#endif
#if GLOBAL_Q == 7
#define _Qrmpy(A, B) _Q7rmpy(A, B)
#endif
#if GLOBAL_Q == 6
#define _Qrmpy(A, B) _Q6rmpy(A, B)
#endif
#if GLOBAL_Q == 5
#define _Qrmpy(A, B) _Q5rmpy(A, B)
#endif
#if GLOBAL_Q == 4
#define _Qrmpy(A, B) _Q4rmpy(A, B)
#endif
#if GLOBAL_Q == 3
#define _Qrmpy(A, B) _Q3rmpy(A, B)
#endif
#if GLOBAL_Q == 2
#define _Qrmpy(A, B) _Q2rmpy(A, B)
#endif
#if GLOBAL_Q == 1
#define _Qrmpy(A, B) _Q1rmpy(A, B)
#endif

//*****************************************************************************
//
// Multiplies two Q numbers, with rounding and saturation.
//
//*****************************************************************************
extern _q15 _Q15rsmpy(_q15 A, _q15 B);
extern _q14 _Q14rsmpy(_q14 A, _q14 B);
extern _q13 _Q13rsmpy(_q13 A, _q13 B);
extern _q12 _Q12rsmpy(_q12 A, _q12 B);
extern _q11 _Q11rsmpy(_q11 A, _q11 B);
extern _q10 _Q10rsmpy(_q10 A, _q10 B);
extern _q9 _Q9rsmpy(_q9 A, _q9 B);
extern _q8 _Q8rsmpy(_q8 A, _q8 B);
extern _q7 _Q7rsmpy(_q7 A, _q7 B);
extern _q6 _Q6rsmpy(_q6 A, _q6 B);
extern _q5 _Q5rsmpy(_q5 A, _q5 B);
extern _q4 _Q4rsmpy(_q4 A, _q4 B);
extern _q3 _Q3rsmpy(_q3 A, _q3 B);
extern _q2 _Q2rsmpy(_q2 A, _q2 B);
extern _q1 _Q1rsmpy(_q1 A, _q1 B);

#if GLOBAL_Q == 15
#define _Qrsmpy(A, B) _Q15rsmpy(A, B)
#endif
#if GLOBAL_Q == 14
#define _Qrsmpy(A, B) _Q14rsmpy(A, B)
#endif
#if GLOBAL_Q == 13
#define _Qrsmpy(A, B) _Q13rsmpy(A, B)
#endif
#if GLOBAL_Q == 12
#define _Qrsmpy(A, B) _Q12rsmpy(A, B)
#endif
#if GLOBAL_Q == 11
#define _Qrsmpy(A, B) _Q11rsmpy(A, B)
#endif
#if GLOBAL_Q == 10
#define _Qrsmpy(A, B) _Q10rsmpy(A, B)
#endif
#if GLOBAL_Q == 9
#define _Qrsmpy(A, B) _Q9rsmpy(A, B)
#endif
#if GLOBAL_Q == 8
#define _Qrsmpy(A, B) _Q8rsmpy(A, B)
#endif
#if GLOBAL_Q == 7
#define _Qrsmpy(A, B) _Q7rsmpy(A, B)
#endif
#if GLOBAL_Q == 6
#define _Qrsmpy(A, B) _Q6rsmpy(A, B)
#endif
#if GLOBAL_Q == 5
#define _Qrsmpy(A, B) _Q5rsmpy(A, B)
#endif
#if GLOBAL_Q == 4
#define _Qrsmpy(A, B) _Q4rsmpy(A, B)
#endif
#if GLOBAL_Q == 3
#define _Qrsmpy(A, B) _Q3rsmpy(A, B)
#endif
#if GLOBAL_Q == 2
#define _Qrsmpy(A, B) _Q2rsmpy(A, B)
#endif
#if GLOBAL_Q == 1
#define _Qrsmpy(A, B) _Q1rsmpy(A, B)
#endif

//*****************************************************************************
//
// Divides two Q numbers.
//
//*****************************************************************************
extern _q15 _Q15div(_q15 A, _q15 B);
extern _q14 _Q14div(_q14 A, _q14 B);
extern _q13 _Q13div(_q13 A, _q13 B);
extern _q12 _Q12div(_q12 A, _q12 B);
extern _q11 _Q11div(_q11 A, _q11 B);
extern _q10 _Q10div(_q10 A, _q10 B);
extern _q9 _Q9div(_q9 A, _q9 B);
extern _q8 _Q8div(_q8 A, _q8 B);
extern _q7 _Q7div(_q7 A, _q7 B);
extern _q6 _Q6div(_q6 A, _q6 B);
extern _q5 _Q5div(_q5 A, _q5 B);
extern _q4 _Q4div(_q4 A, _q4 B);
extern _q3 _Q3div(_q3 A, _q3 B);
extern _q2 _Q2div(_q2 A, _q2 B);
extern _q1 _Q1div(_q1 A, _q1 B);

#if GLOBAL_Q == 15
#define _Qdiv(A, B) _Q15div(A, B)
#endif
#if GLOBAL_Q == 14
#define _Qdiv(A, B) _Q14div(A, B)
#endif
#if GLOBAL_Q == 13
#define _Qdiv(A, B) _Q13div(A, B)
#endif
#if GLOBAL_Q == 12
#define _Qdiv(A, B) _Q12div(A, B)
#endif
#if GLOBAL_Q == 11
#define _Qdiv(A, B) _Q11div(A, B)
#endif
#if GLOBAL_Q == 10
#define _Qdiv(A, B) _Q10div(A, B)
#endif
#if GLOBAL_Q == 9
#define _Qdiv(A, B) _Q9div(A, B)
#endif
#if GLOBAL_Q == 8
#define _Qdiv(A, B) _Q8div(A, B)
#endif
#if GLOBAL_Q == 7
#define _Qdiv(A, B) _Q7div(A, B)
#endif
#if GLOBAL_Q == 6
#define _Qdiv(A, B) _Q6div(A, B)
#endif
#if GLOBAL_Q == 5
#define _Qdiv(A, B) _Q5div(A, B)
#endif
#if GLOBAL_Q == 4
#define _Qdiv(A, B) _Q4div(A, B)
#endif
#if GLOBAL_Q == 3
#define _Qdiv(A, B) _Q3div(A, B)
#endif
#if GLOBAL_Q == 2
#define _Qdiv(A, B) _Q2div(A, B)
#endif
#if GLOBAL_Q == 1
#define _Qdiv(A, B) _Q1div(A, B)
#endif

//*****************************************************************************
//
// Computes the sin of an Q number.
//
//*****************************************************************************
extern _q15 _Q15sin(_q15 A);
extern _q14 _Q14sin(_q14 A);
extern _q13 _Q13sin(_q13 A);
extern _q12 _Q12sin(_q12 A);
extern _q11 _Q11sin(_q11 A);
extern _q10 _Q10sin(_q10 A);
extern _q9 _Q9sin(_q9 A);
extern _q8 _Q8sin(_q8 A);
extern _q7 _Q7sin(_q7 A);
extern _q6 _Q6sin(_q6 A);
extern _q5 _Q5sin(_q5 A);
extern _q4 _Q4sin(_q4 A);
extern _q3 _Q3sin(_q3 A);
extern _q2 _Q2sin(_q2 A);
extern _q1 _Q1sin(_q1 A);

#if GLOBAL_Q == 15
#define _Qsin(A) _Q15sin(A)
#endif
#if GLOBAL_Q == 14
#define _Qsin(A) _Q14sin(A)
#endif
#if GLOBAL_Q == 13
#define _Qsin(A) _Q13sin(A)
#endif
#if GLOBAL_Q == 12
#define _Qsin(A) _Q12sin(A)
#endif
#if GLOBAL_Q == 11
#define _Qsin(A) _Q11sin(A)
#endif
#if GLOBAL_Q == 10
#define _Qsin(A) _Q10sin(A)
#endif
#if GLOBAL_Q == 9
#define _Qsin(A) _Q9sin(A)
#endif
#if GLOBAL_Q == 8
#define _Qsin(A) _Q8sin(A)
#endif
#if GLOBAL_Q == 7
#define _Qsin(A) _Q7sin(A)
#endif
#if GLOBAL_Q == 6
#define _Qsin(A) _Q6sin(A)
#endif
#if GLOBAL_Q == 5
#define _Qsin(A) _Q5sin(A)
#endif
#if GLOBAL_Q == 4
#define _Qsin(A) _Q4sin(A)
#endif
#if GLOBAL_Q == 3
#define _Qsin(A) _Q3sin(A)
#endif
#if GLOBAL_Q == 2
#define _Qsin(A) _Q2sin(A)
#endif
#if GLOBAL_Q == 1
#define _Qsin(A) _Q1sin(A)
#endif

//*****************************************************************************
//
// Computes the sin of an Q number, using cycles per unit instead of radians.
//
//*****************************************************************************
extern _q15 _Q15sinPU(_q15 A);
extern _q14 _Q14sinPU(_q14 A);
extern _q13 _Q13sinPU(_q13 A);
extern _q12 _Q12sinPU(_q12 A);
extern _q11 _Q11sinPU(_q11 A);
extern _q10 _Q10sinPU(_q10 A);
extern _q9 _Q9sinPU(_q9 A);
extern _q8 _Q8sinPU(_q8 A);
extern _q7 _Q7sinPU(_q7 A);
extern _q6 _Q6sinPU(_q6 A);
extern _q5 _Q5sinPU(_q5 A);
extern _q4 _Q4sinPU(_q4 A);
extern _q3 _Q3sinPU(_q3 A);
extern _q2 _Q2sinPU(_q2 A);
extern _q1 _Q1sinPU(_q1 A);

#if GLOBAL_Q == 15
#define _QsinPU(A) _Q15sinPU(A)
#endif
#if GLOBAL_Q == 14
#define _QsinPU(A) _Q14sinPU(A)
#endif
#if GLOBAL_Q == 13
#define _QsinPU(A) _Q13sinPU(A)
#endif
#if GLOBAL_Q == 12
#define _QsinPU(A) _Q12sinPU(A)
#endif
#if GLOBAL_Q == 11
#define _QsinPU(A) _Q11sinPU(A)
#endif
#if GLOBAL_Q == 10
#define _QsinPU(A) _Q10sinPU(A)
#endif
#if GLOBAL_Q == 9
#define _QsinPU(A) _Q9sinPU(A)
#endif
#if GLOBAL_Q == 8
#define _QsinPU(A) _Q8sinPU(A)
#endif
#if GLOBAL_Q == 7
#define _QsinPU(A) _Q7sinPU(A)
#endif
#if GLOBAL_Q == 6
#define _QsinPU(A) _Q6sinPU(A)
#endif
#if GLOBAL_Q == 5
#define _QsinPU(A) _Q5sinPU(A)
#endif
#if GLOBAL_Q == 4
#define _QsinPU(A) _Q4sinPU(A)
#endif
#if GLOBAL_Q == 3
#define _QsinPU(A) _Q3sinPU(A)
#endif
#if GLOBAL_Q == 2
#define _QsinPU(A) _Q2sinPU(A)
#endif
#if GLOBAL_Q == 1
#define _QsinPU(A) _Q1sinPU(A)
#endif

//*****************************************************************************
//
// Computes the arcsin of an Q number.
//
//*****************************************************************************
extern _q14 _Q14asin(_q14 A);
extern _q13 _Q13asin(_q13 A);
extern _q12 _Q12asin(_q12 A);
extern _q11 _Q11asin(_q11 A);
extern _q10 _Q10asin(_q10 A);
extern _q9 _Q9asin(_q9 A);
extern _q8 _Q8asin(_q8 A);
extern _q7 _Q7asin(_q7 A);
extern _q6 _Q6asin(_q6 A);
extern _q5 _Q5asin(_q5 A);
extern _q4 _Q4asin(_q4 A);
extern _q3 _Q3asin(_q3 A);
extern _q2 _Q2asin(_q2 A);
extern _q1 _Q1asin(_q1 A);

#if GLOBAL_Q == 14
#define _Qasin(A) _Q14asin(A)
#endif
#if GLOBAL_Q == 13
#define _Qasin(A) _Q13asin(A)
#endif
#if GLOBAL_Q == 12
#define _Qasin(A) _Q12asin(A)
#endif
#if GLOBAL_Q == 11
#define _Qasin(A) _Q11asin(A)
#endif
#if GLOBAL_Q == 10
#define _Qasin(A) _Q10asin(A)
#endif
#if GLOBAL_Q == 9
#define _Qasin(A) _Q9asin(A)
#endif
#if GLOBAL_Q == 8
#define _Qasin(A) _Q8asin(A)
#endif
#if GLOBAL_Q == 7
#define _Qasin(A) _Q7asin(A)
#endif
#if GLOBAL_Q == 6
#define _Qasin(A) _Q6asin(A)
#endif
#if GLOBAL_Q == 5
#define _Qasin(A) _Q5asin(A)
#endif
#if GLOBAL_Q == 4
#define _Qasin(A) _Q4asin(A)
#endif
#if GLOBAL_Q == 3
#define _Qasin(A) _Q3asin(A)
#endif
#if GLOBAL_Q == 2
#define _Qasin(A) _Q2asin(A)
#endif
#if GLOBAL_Q == 1
#define _Qasin(A) _Q1asin(A)
#endif

//*****************************************************************************
//
// Computes the cos of an Q number.
//
//*****************************************************************************
extern _q15 _Q15cos(_q15 A);
extern _q14 _Q14cos(_q14 A);
extern _q13 _Q13cos(_q13 A);
extern _q12 _Q12cos(_q12 A);
extern _q11 _Q11cos(_q11 A);
extern _q10 _Q10cos(_q10 A);
extern _q9 _Q9cos(_q9 A);
extern _q8 _Q8cos(_q8 A);
extern _q7 _Q7cos(_q7 A);
extern _q6 _Q6cos(_q6 A);
extern _q5 _Q5cos(_q5 A);
extern _q4 _Q4cos(_q4 A);
extern _q3 _Q3cos(_q3 A);
extern _q2 _Q2cos(_q2 A);
extern _q1 _Q1cos(_q1 A);

#if GLOBAL_Q == 15
#define _Qcos(A) _Q15cos(A)
#endif
#if GLOBAL_Q == 14
#define _Qcos(A) _Q14cos(A)
#endif
#if GLOBAL_Q == 13
#define _Qcos(A) _Q13cos(A)
#endif
#if GLOBAL_Q == 12
#define _Qcos(A) _Q12cos(A)
#endif
#if GLOBAL_Q == 11
#define _Qcos(A) _Q11cos(A)
#endif
#if GLOBAL_Q == 10
#define _Qcos(A) _Q10cos(A)
#endif
#if GLOBAL_Q == 9
#define _Qcos(A) _Q9cos(A)
#endif
#if GLOBAL_Q == 8
#define _Qcos(A) _Q8cos(A)
#endif
#if GLOBAL_Q == 7
#define _Qcos(A) _Q7cos(A)
#endif
#if GLOBAL_Q == 6
#define _Qcos(A) _Q6cos(A)
#endif
#if GLOBAL_Q == 5
#define _Qcos(A) _Q5cos(A)
#endif
#if GLOBAL_Q == 4
#define _Qcos(A) _Q4cos(A)
#endif
#if GLOBAL_Q == 3
#define _Qcos(A) _Q3cos(A)
#endif
#if GLOBAL_Q == 2
#define _Qcos(A) _Q2cos(A)
#endif
#if GLOBAL_Q == 1
#define _Qcos(A) _Q1cos(A)
#endif

//*****************************************************************************
//
// Computes the cos of an Q number, using cycles per unit instead of radians.
//
//*****************************************************************************
extern _q15 _Q15cosPU(_q15 A);
extern _q14 _Q14cosPU(_q14 A);
extern _q13 _Q13cosPU(_q13 A);
extern _q12 _Q12cosPU(_q12 A);
extern _q11 _Q11cosPU(_q11 A);
extern _q10 _Q10cosPU(_q10 A);
extern _q9 _Q9cosPU(_q9 A);
extern _q8 _Q8cosPU(_q8 A);
extern _q7 _Q7cosPU(_q7 A);
extern _q6 _Q6cosPU(_q6 A);
extern _q5 _Q5cosPU(_q5 A);
extern _q4 _Q4cosPU(_q4 A);
extern _q3 _Q3cosPU(_q3 A);
extern _q2 _Q2cosPU(_q2 A);
extern _q1 _Q1cosPU(_q1 A);

#if GLOBAL_Q == 15
#define _QcosPU(A) _Q15cosPU(A)
#endif
#if GLOBAL_Q == 14
#define _QcosPU(A) _Q14cosPU(A)
#endif
#if GLOBAL_Q == 13
#define _QcosPU(A) _Q13cosPU(A)
#endif
#if GLOBAL_Q == 12
#define _QcosPU(A) _Q12cosPU(A)
#endif
#if GLOBAL_Q == 11
#define _QcosPU(A) _Q11cosPU(A)
#endif
#if GLOBAL_Q == 10
#define _QcosPU(A) _Q10cosPU(A)
#endif
#if GLOBAL_Q == 9
#define _QcosPU(A) _Q9cosPU(A)
#endif
#if GLOBAL_Q == 8
#define _QcosPU(A) _Q8cosPU(A)
#endif
#if GLOBAL_Q == 7
#define _QcosPU(A) _Q7cosPU(A)
#endif
#if GLOBAL_Q == 6
#define _QcosPU(A) _Q6cosPU(A)
#endif
#if GLOBAL_Q == 5
#define _QcosPU(A) _Q5cosPU(A)
#endif
#if GLOBAL_Q == 4
#define _QcosPU(A) _Q4cosPU(A)
#endif
#if GLOBAL_Q == 3
#define _QcosPU(A) _Q3cosPU(A)
#endif
#if GLOBAL_Q == 2
#define _QcosPU(A) _Q2cosPU(A)
#endif
#if GLOBAL_Q == 1
#define _QcosPU(A) _Q1cosPU(A)
#endif

//*****************************************************************************
//
// Computes the arccos of an Q number.
//
//*****************************************************************************
#define _Q14acos(A) (_Q14(1.570796327) - _Q14asin(A))
#define _Q13acos(A) (_Q13(1.570796327) - _Q13asin(A))
#define _Q12acos(A) (_Q12(1.570796327) - _Q12asin(A))
#define _Q11acos(A) (_Q11(1.570796327) - _Q11asin(A))
#define _Q10acos(A) (_Q10(1.570796327) - _Q10asin(A))
#define _Q9acos(A) (_Q9(1.570796327) - _Q9asin(A))
#define _Q8acos(A) (_Q8(1.570796327) - _Q8asin(A))
#define _Q7acos(A) (_Q7(1.570796327) - _Q7asin(A))
#define _Q6acos(A) (_Q6(1.570796327) - _Q6asin(A))
#define _Q5acos(A) (_Q5(1.570796327) - _Q5asin(A))
#define _Q4acos(A) (_Q4(1.570796327) - _Q4asin(A))
#define _Q3acos(A) (_Q3(1.570796327) - _Q3asin(A))
#define _Q2acos(A) (_Q2(1.570796327) - _Q2asin(A))
#define _Q1acos(A) (_Q1(1.570796327) - _Q1asin(A))

#if GLOBAL_Q == 14
#define _Qacos(A) _Q14acos(A)
#endif
#if GLOBAL_Q == 13
#define _Qacos(A) _Q13acos(A)
#endif
#if GLOBAL_Q == 12
#define _Qacos(A) _Q12acos(A)
#endif
#if GLOBAL_Q == 11
#define _Qacos(A) _Q11acos(A)
#endif
#if GLOBAL_Q == 10
#define _Qacos(A) _Q10acos(A)
#endif
#if GLOBAL_Q == 9
#define _Qacos(A) _Q9acos(A)
#endif
#if GLOBAL_Q == 8
#define _Qacos(A) _Q8acos(A)
#endif
#if GLOBAL_Q == 7
#define _Qacos(A) _Q7acos(A)
#endif
#if GLOBAL_Q == 6
#define _Qacos(A) _Q6acos(A)
#endif
#if GLOBAL_Q == 5
#define _Qacos(A) _Q5acos(A)
#endif
#if GLOBAL_Q == 4
#define _Qacos(A) _Q4acos(A)
#endif
#if GLOBAL_Q == 3
#define _Qacos(A) _Q3acos(A)
#endif
#if GLOBAL_Q == 2
#define _Qacos(A) _Q2acos(A)
#endif
#if GLOBAL_Q == 1
#define _Qacos(A) _Q1acos(A)
#endif

//*****************************************************************************
//
// Computes the arctan of a coordinate specified by two Q numbers.
//
//*****************************************************************************
extern _q15 _Q15atan2(_q15 A, _q15 B);
extern _q14 _Q14atan2(_q14 A, _q14 B);
extern _q13 _Q13atan2(_q13 A, _q13 B);
extern _q12 _Q12atan2(_q12 A, _q12 B);
extern _q11 _Q11atan2(_q11 A, _q11 B);
extern _q10 _Q10atan2(_q10 A, _q10 B);
extern _q9 _Q9atan2(_q9 A, _q9 B);
extern _q8 _Q8atan2(_q8 A, _q8 B);
extern _q7 _Q7atan2(_q7 A, _q7 B);
extern _q6 _Q6atan2(_q6 A, _q6 B);
extern _q5 _Q5atan2(_q5 A, _q5 B);
extern _q4 _Q4atan2(_q4 A, _q4 B);
extern _q3 _Q3atan2(_q3 A, _q3 B);
extern _q2 _Q2atan2(_q2 A, _q2 B);
extern _q1 _Q1atan2(_q1 A, _q1 B);

#if GLOBAL_Q == 15
#define _Qatan2(A, B) _Q15atan2(A, B)
#endif
#if GLOBAL_Q == 14
#define _Qatan2(A, B) _Q14atan2(A, B)
#endif
#if GLOBAL_Q == 13
#define _Qatan2(A, B) _Q13atan2(A, B)
#endif
#if GLOBAL_Q == 12
#define _Qatan2(A, B) _Q12atan2(A, B)
#endif
#if GLOBAL_Q == 11
#define _Qatan2(A, B) _Q11atan2(A, B)
#endif
#if GLOBAL_Q == 10
#define _Qatan2(A, B) _Q10atan2(A, B)
#endif
#if GLOBAL_Q == 9
#define _Qatan2(A, B) _Q9atan2(A, B)
#endif
#if GLOBAL_Q == 8
#define _Qatan2(A, B) _Q8atan2(A, B)
#endif
#if GLOBAL_Q == 7
#define _Qatan2(A, B) _Q7atan2(A, B)
#endif
#if GLOBAL_Q == 6
#define _Qatan2(A, B) _Q6atan2(A, B)
#endif
#if GLOBAL_Q == 5
#define _Qatan2(A, B) _Q5atan2(A, B)
#endif
#if GLOBAL_Q == 4
#define _Qatan2(A, B) _Q4atan2(A, B)
#endif
#if GLOBAL_Q == 3
#define _Qatan2(A, B) _Q3atan2(A, B)
#endif
#if GLOBAL_Q == 2
#define _Qatan2(A, B) _Q2atan2(A, B)
#endif
#if GLOBAL_Q == 1
#define _Qatan2(A, B) _Q1atan2(A, B)
#endif

//*****************************************************************************
//
// Computes the arctan of a coordinate specified by two Q numbers, returning
// the value in cycles per unit instead of radians.
//
//*****************************************************************************
extern _q15 _Q15atan2PU(_q15 A, _q15 B);
extern _q14 _Q14atan2PU(_q14 A, _q14 B);
extern _q13 _Q13atan2PU(_q13 A, _q13 B);
extern _q12 _Q12atan2PU(_q12 A, _q12 B);
extern _q11 _Q11atan2PU(_q11 A, _q11 B);
extern _q10 _Q10atan2PU(_q10 A, _q10 B);
extern _q9 _Q9atan2PU(_q9 A, _q9 B);
extern _q8 _Q8atan2PU(_q8 A, _q8 B);
extern _q7 _Q7atan2PU(_q7 A, _q7 B);
extern _q6 _Q6atan2PU(_q6 A, _q6 B);
extern _q5 _Q5atan2PU(_q5 A, _q5 B);
extern _q4 _Q4atan2PU(_q4 A, _q4 B);
extern _q3 _Q3atan2PU(_q3 A, _q3 B);
extern _q2 _Q2atan2PU(_q2 A, _q2 B);
extern _q1 _Q1atan2PU(_q1 A, _q1 B);

#if GLOBAL_Q == 15
#define _Qatan2PU(A, B) _Q15atan2PU(A, B)
#endif
#if GLOBAL_Q == 14
#define _Qatan2PU(A, B) _Q14atan2PU(A, B)
#endif
#if GLOBAL_Q == 13
#define _Qatan2PU(A, B) _Q13atan2PU(A, B)
#endif
#if GLOBAL_Q == 12
#define _Qatan2PU(A, B) _Q12atan2PU(A, B)
#endif
#if GLOBAL_Q == 11
#define _Qatan2PU(A, B) _Q11atan2PU(A, B)
#endif
#if GLOBAL_Q == 10
#define _Qatan2PU(A, B) _Q10atan2PU(A, B)
#endif
#if GLOBAL_Q == 9
#define _Qatan2PU(A, B) _Q9atan2PU(A, B)
#endif
#if GLOBAL_Q == 8
#define _Qatan2PU(A, B) _Q8atan2PU(A, B)
#endif
#if GLOBAL_Q == 7
#define _Qatan2PU(A, B) _Q7atan2PU(A, B)
#endif
#if GLOBAL_Q == 6
#define _Qatan2PU(A, B) _Q6atan2PU(A, B)
#endif
#if GLOBAL_Q == 5
#define _Qatan2PU(A, B) _Q5atan2PU(A, B)
#endif
#if GLOBAL_Q == 4
#define _Qatan2PU(A, B) _Q4atan2PU(A, B)
#endif
#if GLOBAL_Q == 3
#define _Qatan2PU(A, B) _Q3atan2PU(A, B)
#endif
#if GLOBAL_Q == 2
#define _Qatan2PU(A, B) _Q2atan2PU(A, B)
#endif
#if GLOBAL_Q == 1
#define _Qatan2PU(A, B) _Q1atan2PU(A, B)
#endif

//*****************************************************************************
//
// Computes the arctan of an Q number.
//
//*****************************************************************************
#define _Q14atan(A) _Q14atan2(A, _Q14(1.0))
#define _Q13atan(A) _Q13atan2(A, _Q13(1.0))
#define _Q12atan(A) _Q12atan2(A, _Q12(1.0))
#define _Q11atan(A) _Q11atan2(A, _Q11(1.0))
#define _Q10atan(A) _Q10atan2(A, _Q10(1.0))
#define _Q9atan(A) _Q9atan2(A, _Q9(1.0))
#define _Q8atan(A) _Q8atan2(A, _Q8(1.0))
#define _Q7atan(A) _Q7atan2(A, _Q7(1.0))
#define _Q6atan(A) _Q6atan2(A, _Q6(1.0))
#define _Q5atan(A) _Q5atan2(A, _Q5(1.0))
#define _Q4atan(A) _Q4atan2(A, _Q4(1.0))
#define _Q3atan(A) _Q3atan2(A, _Q3(1.0))
#define _Q2atan(A) _Q2atan2(A, _Q2(1.0))
#define _Q1atan(A) _Q1atan2(A, _Q1(1.0))

#if GLOBAL_Q == 15
#define _Qatan(A) _Q15atan2(A, _Q15(1.0))
#endif
#if GLOBAL_Q == 14
#define _Qatan(A) _Q14atan2(A, _Q14(1.0))
#endif
#if GLOBAL_Q == 13
#define _Qatan(A) _Q13atan2(A, _Q13(1.0))
#endif
#if GLOBAL_Q == 12
#define _Qatan(A) _Q12atan2(A, _Q12(1.0))
#endif
#if GLOBAL_Q == 11
#define _Qatan(A) _Q11atan2(A, _Q11(1.0))
#endif
#if GLOBAL_Q == 10
#define _Qatan(A) _Q10atan2(A, _Q10(1.0))
#endif
#if GLOBAL_Q == 9
#define _Qatan(A) _Q9atan2(A, _Q9(1.0))
#endif
#if GLOBAL_Q == 8
#define _Qatan(A) _Q8atan2(A, _Q8(1.0))
#endif
#if GLOBAL_Q == 7
#define _Qatan(A) _Q7atan2(A, _Q7(1.0))
#endif
#if GLOBAL_Q == 6
#define _Qatan(A) _Q6atan2(A, _Q6(1.0))
#endif
#if GLOBAL_Q == 5
#define _Qatan(A) _Q5atan2(A, _Q5(1.0))
#endif
#if GLOBAL_Q == 4
#define _Qatan(A) _Q4atan2(A, _Q4(1.0))
#endif
#if GLOBAL_Q == 3
#define _Qatan(A) _Q3atan2(A, _Q3(1.0))
#endif
#if GLOBAL_Q == 2
#define _Qatan(A) _Q2atan2(A, _Q2(1.0))
#endif
#if GLOBAL_Q == 1
#define _Qatan(A) _Q1atan2(A, _Q1(1.0))
#endif

//*****************************************************************************
//
// Computes the square root of an Q number.
//
//*****************************************************************************
extern _q15 _Q15sqrt(_q15 A);
extern _q14 _Q14sqrt(_q14 A);
extern _q13 _Q13sqrt(_q13 A);
extern _q12 _Q12sqrt(_q12 A);
extern _q11 _Q11sqrt(_q11 A);
extern _q10 _Q10sqrt(_q10 A);
extern _q9 _Q9sqrt(_q9 A);
extern _q8 _Q8sqrt(_q8 A);
extern _q7 _Q7sqrt(_q7 A);
extern _q6 _Q6sqrt(_q6 A);
extern _q5 _Q5sqrt(_q5 A);
extern _q4 _Q4sqrt(_q4 A);
extern _q3 _Q3sqrt(_q3 A);
extern _q2 _Q2sqrt(_q2 A);
extern _q1 _Q1sqrt(_q1 A);

#if GLOBAL_Q == 15
#define _Qsqrt(A) _Q15sqrt(A)
#endif
#if GLOBAL_Q == 14
#define _Qsqrt(A) _Q14sqrt(A)
#endif
#if GLOBAL_Q == 13
#define _Qsqrt(A) _Q13sqrt(A)
#endif
#if GLOBAL_Q == 12
#define _Qsqrt(A) _Q12sqrt(A)
#endif
#if GLOBAL_Q == 11
#define _Qsqrt(A) _Q11sqrt(A)
#endif
#if GLOBAL_Q == 10
#define _Qsqrt(A) _Q10sqrt(A)
#endif
#if GLOBAL_Q == 9
#define _Qsqrt(A) _Q9sqrt(A)
#endif
#if GLOBAL_Q == 8
#define _Qsqrt(A) _Q8sqrt(A)
#endif
#if GLOBAL_Q == 7
#define _Qsqrt(A) _Q7sqrt(A)
#endif
#if GLOBAL_Q == 6
#define _Qsqrt(A) _Q6sqrt(A)
#endif
#if GLOBAL_Q == 5
#define _Qsqrt(A) _Q5sqrt(A)
#endif
#if GLOBAL_Q == 4
#define _Qsqrt(A) _Q4sqrt(A)
#endif
#if GLOBAL_Q == 3
#define _Qsqrt(A) _Q3sqrt(A)
#endif
#if GLOBAL_Q == 2
#define _Qsqrt(A) _Q2sqrt(A)
#endif
#if GLOBAL_Q == 1
#define _Qsqrt(A) _Q1sqrt(A)
#endif

//*****************************************************************************
//
// Computes 1 over the square root of an Q number.
//
//*****************************************************************************
extern _q15 _Q15isqrt(_q15 A);
extern _q14 _Q14isqrt(_q14 A);
extern _q13 _Q13isqrt(_q13 A);
extern _q12 _Q12isqrt(_q12 A);
extern _q11 _Q11isqrt(_q11 A);
extern _q10 _Q10isqrt(_q10 A);
extern _q9 _Q9isqrt(_q9 A);
extern _q8 _Q8isqrt(_q8 A);
extern _q7 _Q7isqrt(_q7 A);
extern _q6 _Q6isqrt(_q6 A);
extern _q5 _Q5isqrt(_q5 A);
extern _q4 _Q4isqrt(_q4 A);
extern _q3 _Q3isqrt(_q3 A);
extern _q2 _Q2isqrt(_q2 A);
extern _q1 _Q1isqrt(_q1 A);

#if GLOBAL_Q == 15
#define _Qisqrt(A) _Q15isqrt(A)
#endif
#if GLOBAL_Q == 14
#define _Qisqrt(A) _Q14isqrt(A)
#endif
#if GLOBAL_Q == 13
#define _Qisqrt(A) _Q13isqrt(A)
#endif
#if GLOBAL_Q == 12
#define _Qisqrt(A) _Q12isqrt(A)
#endif
#if GLOBAL_Q == 11
#define _Qisqrt(A) _Q11isqrt(A)
#endif
#if GLOBAL_Q == 10
#define _Qisqrt(A) _Q10isqrt(A)
#endif
#if GLOBAL_Q == 9
#define _Qisqrt(A) _Q9isqrt(A)
#endif
#if GLOBAL_Q == 8
#define _Qisqrt(A) _Q8isqrt(A)
#endif
#if GLOBAL_Q == 7
#define _Qisqrt(A) _Q7isqrt(A)
#endif
#if GLOBAL_Q == 6
#define _Qisqrt(A) _Q6isqrt(A)
#endif
#if GLOBAL_Q == 5
#define _Qisqrt(A) _Q5isqrt(A)
#endif
#if GLOBAL_Q == 4
#define _Qisqrt(A) _Q4isqrt(A)
#endif
#if GLOBAL_Q == 3
#define _Qisqrt(A) _Q3isqrt(A)
#endif
#if GLOBAL_Q == 2
#define _Qisqrt(A) _Q2isqrt(A)
#endif
#if GLOBAL_Q == 1
#define _Qisqrt(A) _Q1isqrt(A)
#endif

//*****************************************************************************
//
// Computes e^x of an Q number.
//
//*****************************************************************************
extern _q15 _Q15exp(_q15 A);
extern _q14 _Q14exp(_q14 A);
extern _q13 _Q13exp(_q13 A);
extern _q12 _Q12exp(_q12 A);
extern _q11 _Q11exp(_q11 A);
extern _q10 _Q10exp(_q10 A);
extern _q9 _Q9exp(_q9 A);
extern _q8 _Q8exp(_q8 A);
extern _q7 _Q7exp(_q7 A);
extern _q6 _Q6exp(_q6 A);
extern _q5 _Q5exp(_q5 A);
extern _q4 _Q4exp(_q4 A);
extern _q3 _Q3exp(_q3 A);
extern _q2 _Q2exp(_q2 A);
extern _q1 _Q1exp(_q1 A);

#if GLOBAL_Q == 15
#define _Qexp(A) _Q15exp(A)
#endif
#if GLOBAL_Q == 14
#define _Qexp(A) _Q14exp(A)
#endif
#if GLOBAL_Q == 13
#define _Qexp(A) _Q13exp(A)
#endif
#if GLOBAL_Q == 12
#define _Qexp(A) _Q12exp(A)
#endif
#if GLOBAL_Q == 11
#define _Qexp(A) _Q11exp(A)
#endif
#if GLOBAL_Q == 10
#define _Qexp(A) _Q10exp(A)
#endif
#if GLOBAL_Q == 9
#define _Qexp(A) _Q9exp(A)
#endif
#if GLOBAL_Q == 8
#define _Qexp(A) _Q8exp(A)
#endif
#if GLOBAL_Q == 7
#define _Qexp(A) _Q7exp(A)
#endif
#if GLOBAL_Q == 6
#define _Qexp(A) _Q6exp(A)
#endif
#if GLOBAL_Q == 5
#define _Qexp(A) _Q5exp(A)
#endif
#if GLOBAL_Q == 4
#define _Qexp(A) _Q4exp(A)
#endif
#if GLOBAL_Q == 3
#define _Qexp(A) _Q3exp(A)
#endif
#if GLOBAL_Q == 2
#define _Qexp(A) _Q2exp(A)
#endif
#if GLOBAL_Q == 1
#define _Qexp(A) _Q1exp(A)
#endif

//*****************************************************************************
//
// Computes log(x) of an Q number.
//
//*****************************************************************************
extern _q15 _Q15log(_q15 A);
extern _q14 _Q14log(_q14 A);
extern _q13 _Q13log(_q13 A);
extern _q12 _Q12log(_q12 A);
extern _q11 _Q11log(_q11 A);
extern _q10 _Q10log(_q10 A);
extern _q9 _Q9log(_q9 A);
extern _q8 _Q8log(_q8 A);
extern _q7 _Q7log(_q7 A);
extern _q6 _Q6log(_q6 A);
extern _q5 _Q5log(_q5 A);
extern _q4 _Q4log(_q4 A);
extern _q3 _Q3log(_q3 A);
extern _q2 _Q2log(_q2 A);
extern _q1 _Q1log(_q1 A);

#if GLOBAL_Q == 15
#define _Qlog(A) _Q15log(A)
#endif
#if GLOBAL_Q == 14
#define _Qlog(A) _Q14log(A)
#endif
#if GLOBAL_Q == 13
#define _Qlog(A) _Q13log(A)
#endif
#if GLOBAL_Q == 12
#define _Qlog(A) _Q12log(A)
#endif
#if GLOBAL_Q == 11
#define _Qlog(A) _Q11log(A)
#endif
#if GLOBAL_Q == 10
#define _Qlog(A) _Q10log(A)
#endif
#if GLOBAL_Q == 9
#define _Qlog(A) _Q9log(A)
#endif
#if GLOBAL_Q == 8
#define _Qlog(A) _Q8log(A)
#endif
#if GLOBAL_Q == 7
#define _Qlog(A) _Q7log(A)
#endif
#if GLOBAL_Q == 6
#define _Qlog(A) _Q6log(A)
#endif
#if GLOBAL_Q == 5
#define _Qlog(A) _Q5log(A)
#endif
#if GLOBAL_Q == 4
#define _Qlog(A) _Q4log(A)
#endif
#if GLOBAL_Q == 3
#define _Qlog(A) _Q3log(A)
#endif
#if GLOBAL_Q == 2
#define _Qlog(A) _Q2log(A)
#endif
#if GLOBAL_Q == 1
#define _Qlog(A) _Q1log(A)
#endif

//*****************************************************************************
//
// Returns the integer portion of an Q number.
//
//*****************************************************************************
#define _Q15int(A) ((A) >> 15)
#define _Q14int(A) ((A) >> 14)
#define _Q13int(A) ((A) >> 13)
#define _Q12int(A) ((A) >> 12)
#define _Q11int(A) ((A) >> 11)
#define _Q10int(A) ((A) >> 10)
#define _Q9int(A) ((A) >> 9)
#define _Q8int(A) ((A) >> 8)
#define _Q7int(A) ((A) >> 7)
#define _Q6int(A) ((A) >> 6)
#define _Q5int(A) ((A) >> 5)
#define _Q4int(A) ((A) >> 4)
#define _Q3int(A) ((A) >> 3)
#define _Q2int(A) ((A) >> 2)
#define _Q1int(A) ((A) >> 1)
#define _Qint(A) ((A) >> GLOBAL_Q)

//*****************************************************************************
//
// Computes the fractional portion of an Q number.
//
//*****************************************************************************
extern _q15 _Q15frac(_q15 A);
extern _q14 _Q14frac(_q14 A);
extern _q13 _Q13frac(_q13 A);
extern _q12 _Q12frac(_q12 A);
extern _q11 _Q11frac(_q11 A);
extern _q10 _Q10frac(_q10 A);
extern _q9 _Q9frac(_q9 A);
extern _q8 _Q8frac(_q8 A);
extern _q7 _Q7frac(_q7 A);
extern _q6 _Q6frac(_q6 A);
extern _q5 _Q5frac(_q5 A);
extern _q4 _Q4frac(_q4 A);
extern _q3 _Q3frac(_q3 A);
extern _q2 _Q2frac(_q2 A);
extern _q1 _Q1frac(_q1 A);

#if GLOBAL_Q == 15
#define _Qfrac(A) _Q15frac(A)
#endif
#if GLOBAL_Q == 14
#define _Qfrac(A) _Q14frac(A)
#endif
#if GLOBAL_Q == 13
#define _Qfrac(A) _Q13frac(A)
#endif
#if GLOBAL_Q == 12
#define _Qfrac(A) _Q12frac(A)
#endif
#if GLOBAL_Q == 11
#define _Qfrac(A) _Q11frac(A)
#endif
#if GLOBAL_Q == 10
#define _Qfrac(A) _Q10frac(A)
#endif
#if GLOBAL_Q == 9
#define _Qfrac(A) _Q9frac(A)
#endif
#if GLOBAL_Q == 8
#define _Qfrac(A) _Q8frac(A)
#endif
#if GLOBAL_Q == 7
#define _Qfrac(A) _Q7frac(A)
#endif
#if GLOBAL_Q == 6
#define _Qfrac(A) _Q6frac(A)
#endif
#if GLOBAL_Q == 5
#define _Qfrac(A) _Q5frac(A)
#endif
#if GLOBAL_Q == 4
#define _Qfrac(A) _Q4frac(A)
#endif
#if GLOBAL_Q == 3
#define _Qfrac(A) _Q3frac(A)
#endif
#if GLOBAL_Q == 2
#define _Qfrac(A) _Q2frac(A)
#endif
#if GLOBAL_Q == 1
#define _Qfrac(A) _Q1frac(A)
#endif

//*****************************************************************************
//
// Multiplies two Q numbers in the specified iQ formats, returning the result
// in another Q format.
//
//*****************************************************************************
extern int16_t _Q15mpyQX(int16_t A, int n1, int16_t B, int n2);
extern int16_t _Q14mpyQX(int16_t A, int n1, int16_t B, int n2);
extern int16_t _Q13mpyQX(int16_t A, int n1, int16_t B, int n2);
extern int16_t _Q12mpyQX(int16_t A, int n1, int16_t B, int n2);
extern int16_t _Q11mpyQX(int16_t A, int n1, int16_t B, int n2);
extern int16_t _Q10mpyQX(int16_t A, int n1, int16_t B, int n2);
extern int16_t _Q9mpyQX(int16_t A, int n1, int16_t B, int n2);
extern int16_t _Q8mpyQX(int16_t A, int n1, int16_t B, int n2);
extern int16_t _Q7mpyQX(int16_t A, int n1, int16_t B, int n2);
extern int16_t _Q6mpyQX(int16_t A, int n1, int16_t B, int n2);
extern int16_t _Q5mpyQX(int16_t A, int n1, int16_t B, int n2);
extern int16_t _Q4mpyQX(int16_t A, int n1, int16_t B, int n2);
extern int16_t _Q3mpyQX(int16_t A, int n1, int16_t B, int n2);
extern int16_t _Q2mpyQX(int16_t A, int n1, int16_t B, int n2);
extern int16_t _Q1mpyQX(int16_t A, int n1, int16_t B, int n2);

#if GLOBAL_Q == 15
#define _QmpyQX(A, n1, B, n2) _Q15mpyQX(A, n1, B, n2)
#endif
#if GLOBAL_Q == 14
#define _QmpyQX(A, n1, B, n2) _Q14mpyQX(A, n1, B, n2)
#endif
#if GLOBAL_Q == 13
#define _QmpyQX(A, n1, B, n2) _Q13mpyQX(A, n1, B, n2)
#endif
#if GLOBAL_Q == 12
#define _QmpyQX(A, n1, B, n2) _Q12mpyQX(A, n1, B, n2)
#endif
#if GLOBAL_Q == 11
#define _QmpyQX(A, n1, B, n2) _Q11mpyQX(A, n1, B, n2)
#endif
#if GLOBAL_Q == 10
#define _QmpyQX(A, n1, B, n2) _Q10mpyQX(A, n1, B, n2)
#endif
#if GLOBAL_Q == 9
#define _QmpyQX(A, n1, B, n2) _Q9mpyQX(A, n1, B, n2)
#endif
#if GLOBAL_Q == 8
#define _QmpyQX(A, n1, B, n2) _Q8mpyQX(A, n1, B, n2)
#endif
#if GLOBAL_Q == 7
#define _QmpyQX(A, n1, B, n2) _Q7mpyQX(A, n1, B, n2)
#endif
#if GLOBAL_Q == 6
#define _QmpyQX(A, n1, B, n2) _Q6mpyQX(A, n1, B, n2)
#endif
#if GLOBAL_Q == 5
#define _QmpyQX(A, n1, B, n2) _Q5mpyQX(A, n1, B, n2)
#endif
#if GLOBAL_Q == 4
#define _QmpyQX(A, n1, B, n2) _Q4mpyQX(A, n1, B, n2)
#endif
#if GLOBAL_Q == 3
#define _QmpyQX(A, n1, B, n2) _Q3mpyQX(A, n1, B, n2)
#endif
#if GLOBAL_Q == 2
#define _QmpyQX(A, n1, B, n2) _Q2mpyQX(A, n1, B, n2)
#endif
#if GLOBAL_Q == 1
#define _QmpyQX(A, n1, B, n2) _Q1mpyQX(A, n1, B, n2)
#endif

//*****************************************************************************
//
// Multiplies a Q number by an integer.
//
//*****************************************************************************
#define _Q15mpyI16(A, B) ((A) * (B))
#define _Q14mpyI16(A, B) ((A) * (B))
#define _Q13mpyI16(A, B) ((A) * (B))
#define _Q12mpyI16(A, B) ((A) * (B))
#define _Q11mpyI16(A, B) ((A) * (B))
#define _Q10mpyI16(A, B) ((A) * (B))
#define _Q9mpyI16(A, B) ((A) * (B))
#define _Q8mpyI16(A, B) ((A) * (B))
#define _Q7mpyI16(A, B) ((A) * (B))
#define _Q6mpyI16(A, B) ((A) * (B))
#define _Q5mpyI16(A, B) ((A) * (B))
#define _Q4mpyI16(A, B) ((A) * (B))
#define _Q3mpyI16(A, B) ((A) * (B))
#define _Q2mpyI16(A, B) ((A) * (B))
#define _Q1mpyI16(A, B) ((A) * (B))
#define _QmpyI16(A, B) ((A) * (B))

//*****************************************************************************
//
// Multiplies a Q number by an integer, and returns the integer portion.
//
//*****************************************************************************
#define _Q15mpyI16int(A, B) _Q15int(_Q15mpyI16(A, B))
#define _Q14mpyI16int(A, B) _Q14int(_Q14mpyI16(A, B))
#define _Q13mpyI16int(A, B) _Q13int(_Q13mpyI16(A, B))
#define _Q12mpyI16int(A, B) _Q12int(_Q12mpyI16(A, B))
#define _Q11mpyI16int(A, B) _Q11int(_Q11mpyI16(A, B))
#define _Q10mpyI16int(A, B) _Q10int(_Q10mpyI16(A, B))
#define _Q9mpyI16int(A, B) _Q9int(_Q9mpyI16(A, B))
#define _Q8mpyI16int(A, B) _Q8int(_Q8mpyI16(A, B))
#define _Q7mpyI16int(A, B) _Q7int(_Q7mpyI16(A, B))
#define _Q6mpyI16int(A, B) _Q6int(_Q6mpyI16(A, B))
#define _Q5mpyI16int(A, B) _Q5int(_Q5mpyI16(A, B))
#define _Q4mpyI16int(A, B) _Q4int(_Q4mpyI16(A, B))
#define _Q3mpyI16int(A, B) _Q3int(_Q3mpyI16(A, B))
#define _Q2mpyI16int(A, B) _Q2int(_Q2mpyI16(A, B))
#define _Q1mpyI16int(A, B) _Q1int(_Q1mpyI16(A, B))

#if GLOBAL_Q == 15
#define _QmpyI16int(A, B) _Q15mpyI16int(A, B)
#endif
#if GLOBAL_Q == 14
#define _QmpyI16int(A, B) _Q14mpyI16int(A, B)
#endif
#if GLOBAL_Q == 13
#define _QmpyI16int(A, B) _Q13mpyI16int(A, B)
#endif
#if GLOBAL_Q == 12
#define _QmpyI16int(A, B) _Q12mpyI16int(A, B)
#endif
#if GLOBAL_Q == 11
#define _QmpyI16int(A, B) _Q11mpyI16int(A, B)
#endif
#if GLOBAL_Q == 10
#define _QmpyI16int(A, B) _Q10mpyI16int(A, B)
#endif
#if GLOBAL_Q == 9
#define _QmpyI16int(A, B) _Q9mpyI16int(A, B)
#endif
#if GLOBAL_Q == 8
#define _QmpyI16int(A, B) _Q8mpyI16int(A, B)
#endif
#if GLOBAL_Q == 7
#define _QmpyI16int(A, B) _Q7mpyI16int(A, B)
#endif
#if GLOBAL_Q == 6
#define _QmpyI16int(A, B) _Q6mpyI16int(A, B)
#endif
#if GLOBAL_Q == 5
#define _QmpyI16int(A, B) _Q5mpyI16int(A, B)
#endif
#if GLOBAL_Q == 4
#define _QmpyI16int(A, B) _Q4mpyI16int(A, B)
#endif
#if GLOBAL_Q == 3
#define _QmpyI16int(A, B) _Q3mpyI16int(A, B)
#endif
#if GLOBAL_Q == 2
#define _QmpyI16int(A, B) _Q2mpyI16int(A, B)
#endif
#if GLOBAL_Q == 1
#define _QmpyI16int(A, B) _Q1mpyI16int(A, B)
#endif

//*****************************************************************************
//
// Multiplies a Q number by an integer, and returns the fractional portion.
//
//*****************************************************************************
#define _Q15mpyI16frac(A, B) _Q15frac(_Q15mpyI16(A, B))
#define _Q14mpyI16frac(A, B) _Q14frac(_Q14mpyI16(A, B))
#define _Q13mpyI16frac(A, B) _Q13frac(_Q13mpyI16(A, B))
#define _Q12mpyI16frac(A, B) _Q12frac(_Q12mpyI16(A, B))
#define _Q11mpyI16frac(A, B) _Q11frac(_Q11mpyI16(A, B))
#define _Q10mpyI16frac(A, B) _Q10frac(_Q10mpyI16(A, B))
#define _Q9mpyI16frac(A, B) _Q9frac(_Q9mpyI16(A, B))
#define _Q8mpyI16frac(A, B) _Q8frac(_Q8mpyI16(A, B))
#define _Q7mpyI16frac(A, B) _Q7frac(_Q7mpyI16(A, B))
#define _Q6mpyI16frac(A, B) _Q6frac(_Q6mpyI16(A, B))
#define _Q5mpyI16frac(A, B) _Q5frac(_Q5mpyI16(A, B))
#define _Q4mpyI16frac(A, B) _Q4frac(_Q4mpyI16(A, B))
#define _Q3mpyI16frac(A, B) _Q3frac(_Q3mpyI16(A, B))
#define _Q2mpyI16frac(A, B) _Q2frac(_Q2mpyI16(A, B))
#define _Q1mpyI16frac(A, B) _Q1frac(_Q1mpyI16(A, B))

#if GLOBAL_Q == 15
#define _QmpyI16frac(A, B) _Q15mpyI16frac(A, B)
#endif
#if GLOBAL_Q == 14
#define _QmpyI16frac(A, B) _Q14mpyI16frac(A, B)
#endif
#if GLOBAL_Q == 13
#define _QmpyI16frac(A, B) _Q13mpyI16frac(A, B)
#endif
#if GLOBAL_Q == 12
#define _QmpyI16frac(A, B) _Q12mpyI16frac(A, B)
#endif
#if GLOBAL_Q == 11
#define _QmpyI16frac(A, B) _Q11mpyI16frac(A, B)
#endif
#if GLOBAL_Q == 10
#define _QmpyI16frac(A, B) _Q10mpyI16frac(A, B)
#endif
#if GLOBAL_Q == 9
#define _QmpyI16frac(A, B) _Q9mpyI16frac(A, B)
#endif
#if GLOBAL_Q == 8
#define _QmpyI16frac(A, B) _Q8mpyI16frac(A, B)
#endif
#if GLOBAL_Q == 7
#define _QmpyI16frac(A, B) _Q7mpyI16frac(A, B)
#endif
#if GLOBAL_Q == 6
#define _QmpyI16frac(A, B) _Q6mpyI16frac(A, B)
#endif
#if GLOBAL_Q == 5
#define _QmpyI16frac(A, B) _Q5mpyI16frac(A, B)
#endif
#if GLOBAL_Q == 4
#define _QmpyI16frac(A, B) _Q4mpyI16frac(A, B)
#endif
#if GLOBAL_Q == 3
#define _QmpyI16frac(A, B) _Q3mpyI16frac(A, B)
#endif
#if GLOBAL_Q == 2
#define _QmpyI16frac(A, B) _Q2mpyI16frac(A, B)
#endif
#if GLOBAL_Q == 1
#define _QmpyI16frac(A, B) _Q1mpyI16frac(A, B)
#endif

//*****************************************************************************
//
// Computes the square root of A^2 + B^2 using Q numbers.
//
//*****************************************************************************
extern int16_t _Qmag(int16_t A, int16_t B);
#define _Q15mag(A, B) _Qmag(A, B)
#define _Q14mag(A, B) _Qmag(A, B)
#define _Q13mag(A, B) _Qmag(A, B)
#define _Q12mag(A, B) _Qmag(A, B)
#define _Q11mag(A, B) _Qmag(A, B)
#define _Q10mag(A, B) _Qmag(A, B)
#define _Q9mag(A, B) _Qmag(A, B)
#define _Q8mag(A, B) _Qmag(A, B)
#define _Q7mag(A, B) _Qmag(A, B)
#define _Q6mag(A, B) _Qmag(A, B)
#define _Q5mag(A, B) _Qmag(A, B)
#define _Q4mag(A, B) _Qmag(A, B)
#define _Q3mag(A, B) _Qmag(A, B)
#define _Q2mag(A, B) _Qmag(A, B)
#define _Q1mag(A, B) _Qmag(A, B)

//*****************************************************************************
//
// Computes the inverse square root of A^2 + B^2 using Q numbers.
//
//*****************************************************************************
extern _q15 _Q15imag(_q15 A, _q15 B);
extern _q14 _Q14imag(_q14 A, _q14 B);
extern _q13 _Q13imag(_q13 A, _q13 B);
extern _q12 _Q12imag(_q12 A, _q12 B);
extern _q11 _Q11imag(_q11 A, _q11 B);
extern _q10 _Q10imag(_q10 A, _q10 B);
extern _q9 _Q9imag(_q9 A, _q9 B);
extern _q8 _Q8imag(_q8 A, _q8 B);
extern _q7 _Q7imag(_q7 A, _q7 B);
extern _q6 _Q6imag(_q6 A, _q6 B);
extern _q5 _Q5imag(_q5 A, _q5 B);
extern _q4 _Q4imag(_q4 A, _q4 B);
extern _q3 _Q3imag(_q3 A, _q3 B);
extern _q2 _Q2imag(_q2 A, _q2 B);
extern _q1 _Q1imag(_q1 A, _q1 B);

#if GLOBAL_Q == 15
#define _Qimag(A, B) _Q15imag(A, B)
#endif
#if GLOBAL_Q == 14
#define _Qimag(A, B) _Q14imag(A, B)
#endif
#if GLOBAL_Q == 13
#define _Qimag(A, B) _Q13imag(A, B)
#endif
#if GLOBAL_Q == 12
#define _Qimag(A, B) _Q12imag(A, B)
#endif
#if GLOBAL_Q == 11
#define _Qimag(A, B) _Q11imag(A, B)
#endif
#if GLOBAL_Q == 10
#define _Qimag(A, B) _Q10imag(A, B)
#endif
#if GLOBAL_Q == 9
#define _Qimag(A, B) _Q9imag(A, B)
#endif
#if GLOBAL_Q == 8
#define _Qimag(A, B) _Q8imag(A, B)
#endif
#if GLOBAL_Q == 7
#define _Qimag(A, B) _Q7imag(A, B)
#endif
#if GLOBAL_Q == 6
#define _Qimag(A, B) _Q6imag(A, B)
#endif
#if GLOBAL_Q == 5
#define _Qimag(A, B) _Q5imag(A, B)
#endif
#if GLOBAL_Q == 4
#define _Qimag(A, B) _Q4imag(A, B)
#endif
#if GLOBAL_Q == 3
#define _Qimag(A, B) _Q3imag(A, B)
#endif
#if GLOBAL_Q == 2
#define _Qimag(A, B) _Q2imag(A, B)
#endif
#if GLOBAL_Q == 1
#define _Qimag(A, B) _Q1imag(A, B)
#endif

//*****************************************************************************
//
// Converts a string into an Q number.
//
//*****************************************************************************
extern _q15 _atoQ15(const char *A);
extern _q14 _atoQ14(const char *A);
extern _q13 _atoQ13(const char *A);
extern _q12 _atoQ12(const char *A);
extern _q11 _atoQ11(const char *A);
extern _q10 _atoQ10(const char *A);
extern _q9 _atoQ9(const char *A);
extern _q8 _atoQ8(const char *A);
extern _q7 _atoQ7(const char *A);
extern _q6 _atoQ6(const char *A);
extern _q5 _atoQ5(const char *A);
extern _q4 _atoQ4(const char *A);
extern _q3 _atoQ3(const char *A);
extern _q2 _atoQ2(const char *A);
extern _q1 _atoQ1(const char *A);

#if GLOBAL_Q == 15
#define _atoQ(A) _atoQ15(A)
#endif
#if GLOBAL_Q == 14
#define _atoQ(A) _atoQ14(A)
#endif
#if GLOBAL_Q == 13
#define _atoQ(A) _atoQ13(A)
#endif
#if GLOBAL_Q == 12
#define _atoQ(A) _atoQ12(A)
#endif
#if GLOBAL_Q == 11
#define _atoQ(A) _atoQ11(A)
#endif
#if GLOBAL_Q == 10
#define _atoQ(A) _atoQ10(A)
#endif
#if GLOBAL_Q == 9
#define _atoQ(A) _atoQ9(A)
#endif
#if GLOBAL_Q == 8
#define _atoQ(A) _atoQ8(A)
#endif
#if GLOBAL_Q == 7
#define _atoQ(A) _atoQ7(A)
#endif
#if GLOBAL_Q == 6
#define _atoQ(A) _atoQ6(A)
#endif
#if GLOBAL_Q == 5
#define _atoQ(A) _atoQ5(A)
#endif
#if GLOBAL_Q == 4
#define _atoQ(A) _atoQ4(A)
#endif
#if GLOBAL_Q == 3
#define _atoQ(A) _atoQ3(A)
#endif
#if GLOBAL_Q == 2
#define _atoQ(A) _atoQ2(A)
#endif
#if GLOBAL_Q == 1
#define _atoQ(A) _atoQ1(A)
#endif

//*****************************************************************************
//
// Converts an Q number into a string.
//
//*****************************************************************************
extern int16_t _Q15toa(char *string, const char *format, _q15 input);
extern int16_t _Q14toa(char *string, const char *format, _q14 input);
extern int16_t _Q13toa(char *string, const char *format, _q13 input);
extern int16_t _Q12toa(char *string, const char *format, _q12 input);
extern int16_t _Q11toa(char *string, const char *format, _q11 input);
extern int16_t _Q10toa(char *string, const char *format, _q10 input);
extern int16_t _Q9toa(char *string, const char *format, _q9 input);
extern int16_t _Q8toa(char *string, const char *format, _q8 input);
extern int16_t _Q7toa(char *string, const char *format, _q7 input);
extern int16_t _Q6toa(char *string, const char *format, _q6 input);
extern int16_t _Q5toa(char *string, const char *format, _q5 input);
extern int16_t _Q4toa(char *string, const char *format, _q4 input);
extern int16_t _Q3toa(char *string, const char *format, _q3 input);
extern int16_t _Q2toa(char *string, const char *format, _q2 input);
extern int16_t _Q1toa(char *string, const char *format, _q1 input);

#if GLOBAL_Q == 15
#define _Qtoa(A, B, C) _Q15toa(A, B, C)
#endif
#if GLOBAL_Q == 14
#define _Qtoa(A, B, C) _Q14toa(A, B, C)
#endif
#if GLOBAL_Q == 13
#define _Qtoa(A, B, C) _Q13toa(A, B, C)
#endif
#if GLOBAL_Q == 12
#define _Qtoa(A, B, C) _Q12toa(A, B, C)
#endif
#if GLOBAL_Q == 11
#define _Qtoa(A, B, C) _Q11toa(A, B, C)
#endif
#if GLOBAL_Q == 10
#define _Qtoa(A, B, C) _Q10toa(A, B, C)
#endif
#if GLOBAL_Q == 9
#define _Qtoa(A, B, C) _Q9toa(A, B, C)
#endif
#if GLOBAL_Q == 8
#define _Qtoa(A, B, C) _Q8toa(A, B, C)
#endif
#if GLOBAL_Q == 7
#define _Qtoa(A, B, C) _Q7toa(A, B, C)
#endif
#if GLOBAL_Q == 6
#define _Qtoa(A, B, C) _Q6toa(A, B, C)
#endif
#if GLOBAL_Q == 5
#define _Qtoa(A, B, C) _Q5toa(A, B, C)
#endif
#if GLOBAL_Q == 4
#define _Qtoa(A, B, C) _Q4toa(A, B, C)
#endif
#if GLOBAL_Q == 3
#define _Qtoa(A, B, C) _Q3toa(A, B, C)
#endif
#if GLOBAL_Q == 2
#define _Qtoa(A, B, C) _Q2toa(A, B, C)
#endif
#if GLOBAL_Q == 1
#define _Qtoa(A, B, C) _Q1toa(A, B, C)
#endif

//*****************************************************************************
//
// Computes the absolute value of an Q number.
//
//*****************************************************************************
#define _Q15abs(A) (((A) < 0) ? -(A) : (A))
#define _Q14abs(A) (((A) < 0) ? -(A) : (A))
#define _Q13abs(A) (((A) < 0) ? -(A) : (A))
#define _Q12abs(A) (((A) < 0) ? -(A) : (A))
#define _Q11abs(A) (((A) < 0) ? -(A) : (A))
#define _Q10abs(A) (((A) < 0) ? -(A) : (A))
#define _Q9abs(A) (((A) < 0) ? -(A) : (A))
#define _Q8abs(A) (((A) < 0) ? -(A) : (A))
#define _Q7abs(A) (((A) < 0) ? -(A) : (A))
#define _Q6abs(A) (((A) < 0) ? -(A) : (A))
#define _Q5abs(A) (((A) < 0) ? -(A) : (A))
#define _Q4abs(A) (((A) < 0) ? -(A) : (A))
#define _Q3abs(A) (((A) < 0) ? -(A) : (A))
#define _Q2abs(A) (((A) < 0) ? -(A) : (A))
#define _Q1abs(A) (((A) < 0) ? -(A) : (A))
#define _Qabs(A) (((A) < 0) ? -(A) : (A))

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif  // __QMATHLIB_H__
