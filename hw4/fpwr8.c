//
//  main.c
//  2.90
//
//  Created by Elizabeth Han on 11/7/17.
//  Copyright © 2017 Elizabeth Han. All rights reserved.
//

#include <stdio.h>
#include <limits.h>


static float u2f(unsigned int u)
{
    union{
        unsigned int u;
        float f;
    }temp;
    
    temp.u = u;
    return temp.f;
    
}


float fpwr8(int x)
{
    unsigned exp, frac;
    unsigned u;
    if (x<-49) //you're still good
    {
        //too small.  Return 0.0
        exp= 0; //this is correct
        frac =0; //this is also correct
    
    }
    else if (x<-42){
        //Denormalized result
        exp=0; //this one is correct
        frac = 1 << (149 +(x*3));
    }
    else if (x<43){ //less than biggest value
        //Normalized result
        exp=127+(x*3);
        frac=0; //yup
    }
    else //you're good
    {
        //too big - return infinity
        exp= 255;
        frac=0;
    }
    u = exp<<23 |frac;
    return u2f(u);
 

}
 


