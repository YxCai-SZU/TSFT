#include <stdint.h>

/*@
    requires (1 <= (x) && (x) <= 100000 &&
        1 <= (y) && (y) <= 100000 &&
        1 <= (z) && (z) <= 100000 &&
        (y) + 2 * (z) <= (x));
    ensures \result <= (((x) - (z)) / ((y) + (z)));
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y, uint32_t z)
{
    // Variable declarations at scope top
    uint32_t ans;

    //@ assert (1 <= (x) && (x) <= 100000 &&         1 <= (y) && (y) <= 100000 &&         1 <= (z) && (z) <= 100000 &&         (y) + 2 * (z) <= (x));
    
    ans = (x - z) / (y + z);
    
    //@ assert ans <= (((x) - (z)) / ((y) + (z)));
    
    return ans;
}
