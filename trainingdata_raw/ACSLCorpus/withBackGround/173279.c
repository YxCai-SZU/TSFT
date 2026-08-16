#include <stdint.h>

/*@
    predicate bounds(integer v) = 1 <= v <= 100;
    predicate product_bounds(integer v) = 1 <= v <= 10000;
*/

/*@
    requires bounds(a) && bounds(b) && bounds(c) && bounds(d);
    ensures \result <= a * b;
    ensures \result <= c * d;
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t c, uint64_t d)
{
    uint64_t x;
    uint64_t y;
    uint64_t ans;

    //@ assert product_bounds(a * b);
    x = a * b;

    //@ assert product_bounds(c * d);
    y = c * d;

    if (x < y) {
        ans = x;
    } else {
        ans = y;
    }

    //@ assert ans <= a * b;
    //@ assert ans <= c * d;
    return ans;
}
