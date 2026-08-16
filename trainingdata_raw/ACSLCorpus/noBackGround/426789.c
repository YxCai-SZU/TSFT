#include <stdint.h>

/*@
    requires (1 <= (x) && 1 <= (y) && 1 <= (z) &&
        (x) <= 100000 && (y) <= 100000 && (z) <= 100000 &&
        (y) + (z) <= (x));
    ensures \result <= x;
    ensures \result >= 0;
    assigns \nothing;
*/
uint64_t func(uint64_t x, uint64_t y, uint64_t z)
{
    uint64_t ans;
    //@ assert (1 <= (x) && 1 <= (y) && 1 <= (z) &&         (x) <= 100000 && (y) <= 100000 && (z) <= 100000 &&         (y) + (z) <= (x));
    ans = (x - z) / (y + z);
    //@ assert ans == (((x) - (z)) / ((y) + (z)));
    //@ assert ans >= 0;
    //@ assert ans <= x;
    return ans;
}
