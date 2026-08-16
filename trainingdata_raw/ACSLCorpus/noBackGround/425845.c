#include <stdint.h>

/*@
    requires (1 <= (x) <= 100000 &&
        1 <= (y) <= 100000 &&
        1 <= (z) <= 100000 &&
        (y) + 2 * (z) <= (x));
    ensures \result == (((x) - (z)) / ((y) + (z)));
    assigns \nothing;
*/
uint64_t func(uint64_t x, uint64_t y, uint64_t z)
{
    uint64_t ans;
    
    //@ assert x - z >= 0;
    //@ assert y + z <= 200000;
    
    ans = (x - z) / (y + z);
    return ans;
}
