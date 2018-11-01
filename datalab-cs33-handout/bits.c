/* 
 * CS:APP Data Lab 
 * 
 * <Elizabeth Han 004815046>
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
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

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

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

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
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
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
/*done!  op count: 12
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
   
    int mask = (1<<31) & x; //this should get only the sign bit
    x = x | (mask>>1);
    x=(~x)| mask; //if we negate x, this results in 1 sign bit for everything except negative, and ORing it results a 1 sign bit everywhere
    x= ((~x +~1+1) >>31)&1; //negating x again results in positive numbers( and 0), so subtracting 1 should result in only a negative number for 0...
    //x= ~(x+~1+1);
    
    
    
    //x=(~x)|mask;
    
    
    // int xNegative = (x>>31) & 1; // 0 if negative
    // int ifzero;
    
    return x;
}
/* done! op count: 37
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
    
 
    int count;
    int mask = (0x55 << 8)| (0x55); //0101...
    mask = (mask << 16) | mask;
    count =(x & mask) + ((x>>1) & mask);
    
    mask = (0x33 << 8)| (0x33);//0011...
    mask = (mask << 16) | mask;
    count =(count & mask) + ((count>>2) & mask);
    
    mask = (0xf<<8)| (0xf); //00001111...
    mask = (mask << 16) | mask;
    count =(count & mask) + ((count>>4) & mask);
    
    mask = (0xff<<16) | 0xff; //0000000011111111....
    count =(count & mask) + ((count>>8) & mask);
    
    mask = ~(~0 <<16);
    count = (count & mask) + ((count>>16) & mask);
    
    return count;

}
/* done! op count: 4
 * bitOr - x|y using only ~ and & 
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */ //Done!
int bitOr(int x, int y) {
    return ~((~x)&(~y));
}
/* done! mostly! op count: 39
 * bitRepeat - repeat x's low-order n bits until word is full.
 *   Can assume that 1 <= n <= 32.
 *   Examples: bitRepeat(1, 1) = -1
 *             bitRepeat(7, 4) = 0x77777777
 *             bitRepeat(0x13f, 8) = 0x3f3f3f3f
 *             bitRepeat(0xfffe02, 9) = 0x10080402
 *             bitRepeat(-559038737, 31) = -559038737
 *             bitRepeat(-559038737, 32) = -559038737
 *   Legal ops: int and unsigned ! ~ & ^ | + - * / % << >>
 *             (This is more general than the usual integer coding rules.)
 *   Max ops: 40
 *   Rating: 4
 */
int bitRepeat(int x, int n) {
 
    int if32 = n%32; //Should return 0 if n = 32, else should equal n
    int mask = (~(~0<<if32)+ ((!if32<<31)>>31)) & x;
   
    
    mask = (mask << if32) | mask; //2
    
    n = if32*2;
    if32 = ~((32-n)>>31) & n;
    mask = (mask << if32) | mask; //3
    
    n = if32*2;
    if32 = ~((32-n)>>31) & n;
    mask = (mask << if32) | mask; //4
    
    n = if32*2;
    if32 = ~((32-n)>>31) & n;
    mask = (mask << if32) | mask; //5
    
    n = if32*2;
    if32 = ~((32-n)>>31) & n;
    mask = (mask << (if32)) | mask; //5
    
    return mask;
    

    }
/* done! op count: 8
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
   
  return !(x^(x<<(33+~n)>>(33+~n)));
}
/* done! op count: 6
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
    return (x >>(n<<3)) & (~((~0)<<8));
    
  //return 2; //returns 1 if equal
}
/* done! op count: 22
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
    
    int xPos = !(x>>31); //if positive return 1
    int yPos = !(y>>31); //if positive return 1
    int dif = y + ~x +1;
    int signdif = !(dif>>31); //if difference is negative return 0, else return 1
    int same = ~(xPos ^ yPos) & signdif; //if x and y are the same and the sign is positive, should get 0
    int sign = xPos & yPos & signdif;
    int xMIN = !(x^(1<<31));
    int difsign = (yPos & !xPos);
    
    return same | sign| xMIN|difsign;
    
    
    
   
    /*int signdif = !(dif>>31); //if difference is negative return 0.  This case only works if
    int xMIN = !(x^(1<<31)); //if equal to INTMIN, return 1
    int xMAX = !!(x^~(1<<31));//if equal to INTMAX return 0
    int yMIN = !(y^(1<<31)); //if y equals to INTMAX return 1
    
    return ((!(x&~y))&(yMIN^xMAX)) & (signdif | xMIN);// & (xMAX|yMAX); //this first part returns 0 if not equal
    */
}
/* done! op count: 6
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
    return !((1<<31) & x) & (!!x);//okay wait.  so i get the sign bit (either 1 or 0), then when I not it, I get 0 for negative, 1 and 1 for positive and when I AND it, I get okay yes this makes sense.
    
    //return (!((1 << 31) & x)); //this currently returns 0 if negative, 1 if positive or zero
    
}
/* done! op count: 6
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
    return (x>>n) & ( ~((1<<31)>>(n)<<1));
    
    //~(((1<<31)>>n)<<1)
   
    
    //~(1<< (31+~n+1));
}
/* done! op count: 1
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return (1<<31);
}
