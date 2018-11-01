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

}

*/

long cread(long*xp)
{
    
    return (!xp? 0: *xp);
    
}
