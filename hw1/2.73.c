//
//  main.c
//  2.62
//
//  Created by Elizabeth Han on 10/1/17.
//  Copyright © 2017 Elizabeth Han. All rights reserved.
//

#include <stdio.h>
#include <limits.h>


int saturating_add(int x,int y)
{
    int sum = x+y;
    int check = INT_MIN;
    int shift = (sizeof(int)<<3) -1;
    
    int xNegative = (x&check) >> shift; //if this is negative, should result in all ones
    int yNegative = (y&check) >> shift; //same
    int sumPositive = ~((sum&check) >> shift); //Also same
    
    int negFlow = xNegative & yNegative & sumPositive;
    int posFlow = ~xNegative & ~yNegative & ~sumPositive;
    int rightful = ~(negFlow^posFlow) & sum;
    
    return (negFlow & INT_MIN) + (posFlow & INT_MAX) + rightful;

}


/*

int main(void) {

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
 
