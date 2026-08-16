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
    // Variable declarations at scope top
    uint64_t xx;
    uint64_t yy;
    uint64_t ans;

    //@ assert y + 2 * z <= x;
    
    xx = x - z;
    yy = y + z;
    
    //@ assert xx >= 0;
    //@ assert yy >= 0;
    //@ assert yy >= 1;
    
    ans = xx / yy;
    return ans;
}
