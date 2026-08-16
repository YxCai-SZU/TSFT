#include <stdint.h>

/*@
    predicate valid_range(integer v) = 1 <= v && v <= 100;

    logic integer product(integer a, integer b) = a * b;

    lemma product_bounds:
        \forall integer a, b;
        valid_range(a) && valid_range(b) ==>
        1 <= product(a, b) && product(a, b) <= 10000;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == product(a, b) || \result == product(c, d);
    ensures 1 <= \result && \result <= 10000;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    // Variable declarations at scope top
    uint32_t x;
    uint32_t y;
    uint32_t res;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    //@ assert valid_range(d);

    //@ assert product(a, b) <= 10000;
    //@ assert product(c, d) <= 10000;

    x = a * b;
    y = c * d;

    //@ assert 1 <= product(a, b);
    //@ assert 1 <= product(c, d);

    if (x > y) {
        res = x;
    } else {
        res = y;
    }

    //@ assert res == product(a, b) || res == product(c, d);
    return res;
}
