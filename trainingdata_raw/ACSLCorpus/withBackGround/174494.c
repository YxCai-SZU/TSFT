#include <stdint.h>

/*@
    predicate in_range(integer v) = 1 <= v <= 8;

    logic integer product(integer x, integer y) = x * y * x;

    lemma product_bound:
        \forall integer x, y;
            in_range(x) && in_range(y) ==> product(x, y) <= 512;
*/

/*@
    requires 1 <= x <= 8;
    requires 1 <= y <= 8;
    ensures \result == x * y * x;
    ensures \result <= 512;
*/
uint32_t func(uint32_t x, uint32_t y)
{
    // Variable declarations at scope top
    uint32_t ans;

    //@ assert x <= 8;
    //@ assert y <= 8;
    //@ assert x * y <= 64;
    //@ assert x * y * x <= 512;

    ans = x * y * x;
    return ans;
}
