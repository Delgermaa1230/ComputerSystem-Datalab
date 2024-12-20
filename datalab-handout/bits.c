/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* We do not support C11 <threads.h>.  */
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
    //De Morgan's хуулийг ашиглан XOR хэрэгжүүлэлтийг хийсэн
    return (~(x & y)) & (~((~x) & (~y)));
}

/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
    // 1-ийг зүүн тийш 31 удаа шилжүүлж, хамгийн 
    // бага утгыг буцаана
    return 1 << 31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
   int a, mask;
   a = x + 1;
   mask = !a;
   /* x нэмэхдээ хоёртын тэмдэгт системийн
    хамгийн бага утга болж байвал шалгана */
   x += a;
   return !(~x | mask);
}

/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */

int allOddBits(int x) {
  // mask үүсгэх : 0xAAAAAAAA
  int mask = (0xAA << 8) + 0xAA;
  mask = (mask << 16) + mask;

  return !((x & mask) ^ mask);
}

/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
    return ~x + 1;  // 1. Урвуу болгох, 2. 1-ийг нэмэх
}


//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
    int lowerBound = x + ~0x30 + 1; 
    // 1. x - 0x30 >= 0
    int upperBound = 0x39 + ~x + 1; 
    // 2. 0x39 - x >= 0
    return !(lowerBound >> 31 | upperBound >> 31); 
    // 3. Шалгалтын үр дүнг нэгтгэж буцаах
}

/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
    int mask = !!x; 
    // 1. x 0 бол mask = 0, бусад тохиолдолд 1
    mask = ~mask + 1; 
    // 2. mask-г 0 эсвэл -1 болгох 
    // (өөрөөр хэлбэл бүх битийг 1 болгох эсвэл бүх битийг 0 болгох)
    return (y & mask) | (z & ~mask); 
    // 3. mask-аар аль нэг утгыг сонгох
}

/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {

    int indicator = !((y + (~x + 1)) >> 31); 
    // y - x үйлдлийн эсрэгцэл, y < x үед 0,  y >= x үед -1
    int xsign = x >> 31; // x < 0 үед -1, x >= 0 үед 0
    int ysign = y >> 31; // y < 0 үед -1, y >= 0 үед 0
    int xbool = !xsign; // x < 0 үед 0, x >= 0 үед 1
    int ybool = !ysign; // y < 0 үед 0, y >= 0 үед 1
    int result = (!(xbool ^ ybool)) & indicator;
    return result | (ybool & !xbool);
}


//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
    return ((x | (~x + 1)) >> 31) + 1;  // 1. Битээр шалгах
}

/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
    int mask, b16, b8, b4, b2, b1, b0;
    mask = x >> 31; // x нь сөрөг бол бүх битийг урвуу болгоно
    x = (x ^ mask); // урвууг олох
    b16 = !!(x >> 16) << 4; // 16 бит зүүн тийш шилжүүлж шалгах
    x >>= b16;
    b8 = !!(x >> 8) << 3; // 8 бит зүүн тийш шилжүүлж шалгах
    x >>= b8;
    b4 = !!(x >> 4) << 2; // 4 бит зүүн тийш шилжүүлж шалгах
    x >>= b4;
    b2 = !!(x >> 2) << 1; // 2 бит зүүн тийш шилжүүлж шалгах
    x >>= b2;
    b1 = !!(x >> 1); // 1 бит зүүн тийш шилжүүлж шалгах
    x >>= b1;
    b0 = x; // эцсийн бит
    return b16 + b8 + b4 + b2 + b1 + b0 + 1; // шаардлагатай битүүдийн тоо
}

//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
    unsigned exp = (uf >> 23) & 0xFF;  // 1. Exponent-г ялгах
    unsigned sign = uf & (1 << 31);  // 2. Тэмдгийг хадгалах
    if (exp == 0xFF) return uf;  // 3. NaN эсвэл Infinity бол өөрчлөхгүй
    if (exp == 0) return uf << 1 | sign;  // 4. Denormal бол үржүүлэх
    exp++;  // 5. Exponent-г 1-ээр нэмэх
    if (exp == 0xFF) return sign | 0x7F800000;  // 6. Хязгаартай бол +INF буцаах
    return (uf & 0x807FFFFF) | (exp << 23);  // 7. Битүүдийг нэгтгэж буцаах
}

/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
    int exp = ((uf >> 23) & 0xFF) - 127;  // 1. Exponent-г салгах
    int sign = uf >> 31;  // 2. Тэмдгийг ялгах
    int frac = (uf & 0x7FFFFF) | 0x800000;  // 3. Mantissa-г ялгах
    if (exp >= 31) return 0x80000000;  // 4. Хязгаарласан утга
    if (exp < 0) return 0;  // 5. 0 эсвэл бага утга бол 0 буцаах
    if (exp > 23) frac <<= (exp - 23);  // 6. Бүхэл тоонд шилжүүлэх
    else frac >>= (23 - exp);
    return sign ? -frac : frac;  // 7. Тэмдэгтийн дагуу буцаах
}

/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
    if (x < -126) return 0;  // 1. Хэтэрхий бага тохиолдолд 0 буцаах
    if (x > 127) return 0x7F800000;  // 2. Хэтэрхий их тохиолдолд +INF буцаах
    return (x + 127) << 23;  // 3. Exponent-г тохируулж буцаах
}

