#include <stdint.h>

/*@
    requires 0 <= x <= 9;
    requires 0 <= a <= 9;
    ensures ((x) < (a)) ==> \result == 0;
    ensures ((x) >= (a)) ==> \result == 10;
*/
uint64_t func(uint64_t x, uint64_t a)
{
    uint64_t ans;
    
    if (x < a)
    {
        ans = 0;
    }
    else
    {
        ans = 10;
    }
    
    //@ assert (x < a ==> ans == 0) && (x >= a ==> ans == 10);
    
    return ans;
}
