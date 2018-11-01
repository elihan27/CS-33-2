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

int int_shifts_are_arithmetic(void)
{
    if ((-1>>1)<0)
        return 1;
    else
        return 0;
    
}




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


/*bool __builtin_add_overflow (int x, int y, int z);



 
 int the_saturating_add(int x, int y)
 {
 
     int sum = x+y;
     int shift = (sizeof(int)<<3)-1;
    
    int check = __builtin_add_overflow_p (x, y, (int) 0); //results in one if overflow
     check = check << shift;
     check = check >> shift;
     
    int xNegative = (x & INT_MIN) >> shift; //if this is negative, should result in all ones
 
 
     return (xNegative & check & INT_MIN) + (~xNegative & check & INT_MAX) + (~check & sum);
 
 }
 
 */
 
 



int main(void) {

  /*  int x = int_shifts_are_arithmetic();
    if (x==1)
        printf("arithmetic\n");
    else
        printf("logical\n");

    return 0;
   */
    
    //unsigned int x = (unsigned) a;

    
   
    
   
    int x = 0;
    int y = 1;
    
    int z = saturating_add(x,y);
   
    printf("%i \n", INT_MAX);
    printf("%i \n", INT_MIN);
    printf("%i \n", z);
}
