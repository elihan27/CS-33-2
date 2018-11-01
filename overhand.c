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

_Bool
testovf (long n)
{
    return n + 9223372036854775807 < n;
}
