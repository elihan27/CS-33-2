//
//  main.c
//  2.62
//
//  Created by Elizabeth Han on 10/1/17.
//  Copyright © 2017 Elizabeth Han. All rights reserved.
//

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

int saturating_add(int x, int y)
{
    
    int sum = x+y;
    int shift = (sizeof(int)<<3)-1;
    
    int check = __builtin_add_overflow_p (x, y, (int) 0); //results in one if overflow
    check = check << shift; //shift bool over to most significant bit
    check = check >> shift; //This should result in either all ones or all zeroes.
    
    int xNegative = (x & INT_MIN) >> shift; //if this is negative, should result in all ones
    
    
    return (xNegative & check & INT_MIN) + (~xNegative & check & INT_MAX) + (~check & sum);
    
}





/*int main(void) {

    int x = saturating_add(INT_MAX, 1); //should result in INT_MAX
    int y = saturating_add(INT_MIN, -1); //should result in INT_MIN
    int z = saturating_add(1, 2); //3
    int a = saturating_add(-1, -2);//-3
    int b = saturating_add(1, -2); //-1
    int c = saturating_add(INT_MAX, -2); //2147483645
    int d = saturating_add(INT_MIN, 1); //-2147483647 
    
    printf("%i \n", INT_MIN);
    printf("%i \n", INT_MAX);
    printf("%i \n", x);
    printf("%i \n", y);
    printf("%i \n", z);
    printf("%i \n", a);
    printf("%i \n", b);
    printf("%i \n", c);
    printf("%i \n", d);
 
    return 0;

    
}
 */
