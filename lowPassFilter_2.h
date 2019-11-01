/*
 * Filter Coefficients (C Source) generated by the Filter Design and Analysis Tool
 * Generated by MATLAB(R) 9.0 and the DSP System Toolbox 9.2.
 * Generated on: 28-Oct-2019 08:31:01
 */

/*
 * Discrete-Time FIR Filter (real)
 * -------------------------------
 * Filter Structure  : Direct-Form FIR
 * Filter Length     : 64
 * Stable            : Yes
 * Linear Phase      : Yes (Type 2)
 * Arithmetic        : fixed
 * Numerator         : s8,7 -> [-1 1)
 * Input             : s16,15 -> [-1 1)
 * Filter Internals  : Full Precision
 *   Output          : s24,22 -> [-2 2)  (auto determined)
 *   Product         : s20,22 -> [-1.250000e-01 1.250000e-01)  (auto determined)
 *   Accumulator     : s24,22 -> [-2 2)  (auto determined)
 *   Round Mode      : No rounding
 *   Overflow Mode   : No overflow
 */

/* General type conversion for MATLAB generated C-code  */
#include "tmwtypes.h"
/* 
 * Expected path to tmwtypes.h 
 * C:\Program Files\MATLAB\R2016a\extern\include\tmwtypes.h 
 */
const int BL = 64;
const int8_T B[64] = {
     -1,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,
      0,   -1,   -1,   -2,   -2,   -2,   -2,   -2,   -1,    0,    1,    2,
      4,    5,    7,    9,   10,   11,   12,   13,   13,   12,   11,   10,
      9,    7,    5,    4,    2,    1,    0,   -1,   -2,   -2,   -2,   -2,
     -2,   -1,   -1,    0,    0,    0,    1,    1,    1,    1,    0,    0,
      0,    0,    0,   -1
};
