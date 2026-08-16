#include <stdint.h>

/*@
    requires ((1 <= ((x)) && ((x)) <= 100000) && (1 <= ((y)) && ((y)) <= 100000) && (1 <= ((z)) && ((z)) <= 100000) &&
        (y) + 2 * (z) <= (x));
    ensures \result == (((x) - (z)) / ((y) + (z)));
    assigns \nothing;
*/
uint64_t func(uint64_t x, uint64_t y, uint64_t z)
{
    // Variable declarations at scope top
    uint64_t ret;

    //@ assert y + z <= 200000;
    //@ assert x - z >= 0;

    ret = (x - z) / (y + z);
    return ret;
}
