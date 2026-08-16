/*@
    predicate valid_range(integer v) = 1 <= v <= 10000;

    logic integer product(integer x, integer y) = x * y;

    lemma product_in_range:
        \forall integer a, b;
            valid_range(a) && valid_range(b) ==> 
            1 <= product(a, b) <= 100000000;

    lemma max_property1:
        \forall integer a, b, c, d, m;
            (m == product(a, b) || m == product(c, d)) && m >= product(a, b) && m >= product(c, d) ==>
            m >= product(a, b) && m >= product(c, d);
*/

#include <stdint.h>

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == product(a, b) || \result == product(c, d);
    ensures \result >= product(a, b);
    ensures \result >= product(c, d);
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    // Variable declarations at top of scope
    int64_t x;
    int64_t y;
    int64_t result;

    //@ assert 1 <= product(a, b) <= 100000000;
    //@ assert 1 <= product(c, d) <= 100000000;

    x = a * b;
    y = c * d;

    if (x < y) {
        //@ assert y >= product(a, b);
        result = y;
    } else {
        //@ assert x >= product(c, d);
        result = x;
    }

    return result;
}
