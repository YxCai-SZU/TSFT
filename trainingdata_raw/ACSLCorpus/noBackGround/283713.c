#include <stdint.h>

/*@
    requires ((1 <= ((x)) <= 100000) && (1 <= ((y)) <= 100000) && (1 <= ((z)) <= 100000) &&
        (y) + 2 * (z) <= (x));
    ensures \result == (((x) - (z)) / ((y) + (z)));
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y, uint32_t z)
{
    // Variable declarations at scope top
    uint32_t numerator;
    uint32_t denominator;
    uint32_t quotient;

    //@ assert x >= z;
    //@ assert y + z <= 100000 + z;
    //@ assert (x - z) >= (y + z) && (x - z) <= 100000 * (y + z);

    numerator = x - z;
    denominator = y + z;
    quotient = numerator / denominator;

    return quotient;
}
