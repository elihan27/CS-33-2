//
//  main.c
//  hw2test
//
//  Created by Elizabeth Han on 10/17/17.
//  Copyright © 2017 Elizabeth Han. All rights reserved.
//

#include <stdio.h>

long cread(long*xp)
{
    return (xp? *xp : 0);
}

/*int main(void) {
    long x = 3;
    long *y = &x;
    long z = cread(y);
    
    printf("%li \n", z);
    
    
    return 0;
}
*/
