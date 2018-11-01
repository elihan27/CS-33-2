//
//  main.c
//  hw2test
// Elizabeth Han 004815046

#include <stdio.h>

//compiled using -O1


long cread(long *xp)
{
    long zero = 0;
    long* ZERO = &zero;
    
    return *(xp ? xp : ZERO);
}


/*int main(void) {
    long x = 3;
    long *y = &x;
    
    long z = cread(y);
     printf("%li \n", z);
    long *a;
    
    z= cread(a);
    
    printf("%li \n", z);
  
    
    return 0;
}
 */

