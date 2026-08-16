#include <stdint.h>

/*@
    requires (0 <= (x) && (x) <= 10000 &&
        0 <= (y) && (y) <= 10000);
    ensures \result == (x * y) / 100;
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y)
{
    // Variable declarations at scope top
    uint32_t product;
    uint32_t result;

    //@ assert x <= 10000;
    //@ assert y <= 10000;
    //@ assert x * y <= 100000000;

    product = x * y;
    result = product / 100;

    return result;
}
