//
//  main.c
//  hw2test
//
//  Created by Elizabeth Han on 10/17/17.
//  Copyright © 2017 Elizabeth Han. All rights reserved.
//

#include <stdio.h>

/*long cread(long*xp)
{
    return (xp? *xp : 0);
}
*/

/*long cread(long*xp)
{
    long v = 0;
    if (xp!=NULL)
        v = *xp;
    return v;

}*/


/*long cread(long*xp)
{
    
    return (!xp? 0: *xp);
    
}
 */

/*long cread(long *xp)
{
    static const long zero = 0;
    return *(xp ? xp : &zero);
}
*/


/*long cread(long *xp)
{
    //static const int zero = 0;
    long zero = 0;
    return *(xp ? xp : &zero);
}
 */


long cread(long *xp)
{
    long zero = 0;
    long* ZERO = &zero;
    
    return *(xp ? xp : ZERO);
}



int main(void) {
    long x = 3;
    long *y = &x;
    
    long z = cread(y);
     printf("%li \n", z);
    long *a;
    
    z= cread(a);
    
    printf("%li \n", z);
  
    
    return 0;
}
 


