#include <stdint.h>

/*@
    predicate valid_range(integer v) = 1 <= v && v <= 100;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == ((a & b) | (c & d));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t x;
    uint32_t y;
    uint32_t res;

    x = a & b;
    y = c & d;

    //@ assert x == (a & b);
    //@ assert y == (c & d);
    //@ assert (x & y) == ((a & b) & (c & d));

    res = x | y;
    return res;
}
