#include <stdint.h>

/*@
    requires 0 <= x <= 1;
    ensures (((x) == 0) ==> \result == 1);
    ensures (((x) == 1) ==> \result == 0);
*/
int32_t func(uint32_t x)
{
    int32_t ans;
    
    ans = 1 - (int32_t)x;
    
    /*@ assert (x == 0) ==> (ans == 1); */
    /*@ assert (x == 1) ==> (ans == 0); */
    
    return ans;
}

