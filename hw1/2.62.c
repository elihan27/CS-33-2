#include <stdio.h>

int int_shifts_are_arithmetic(void)
{
if ((-1>>1)<0)
  return 1;
 else 
   return 0;

}




/* int main(void) {
    
     int x = int_shifts_are_arithmetic();
     if (x==1)
     printf("arithmetic\n");
     else
     printf("logical\n");
     
     return 0; }
*/
