#include <stdint.h>

/*@
    predicate safe_mul(uint32_t x, uint32_t y) =
        x <= 0xFFFFFFFF && y <= 0xFFFFFFFF &&
        (unsigned long long)x * (unsigned long long)y <= 0xFFFFFFFF;
*/

/*@
    requires x <= 0xFFFFFFFF && y <= 0xFFFFFFFF;
    requires (unsigned long long)x * (unsigned long long)y <= 0xFFFFFFFF;
    ensures \result == x * y;
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y)
{
    // Variable declarations at top of scope
    uint32_t res;

    //@ assert x <= 0xFFFFFFFF;
    //@ assert y <= 0xFFFFFFFF;
    //@ assert (unsigned long long)x * (unsigned long long)y <= 0xFFFFFFFF;

    res = x * y;
    return res;
}
