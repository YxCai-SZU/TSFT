#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    logic integer product(integer x, integer y) = x * y;

    lemma product_bounds:
        \forall integer a, b;
        valid_range(a) && valid_range(b) ==> product(a, b) <= 9223372036854775807;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == product(a, b) || \result == product(c, d);
    ensures \result >= product(a, b) && \result >= product(c, d);
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    int64_t sa;
    int64_t sc;
    int64_t max_value;

    //@ assert product(a, b) <= 9223372036854775807;
    sa = a * b;

    //@ assert product(c, d) <= 9223372036854775807;
    sc = c * d;

    if (sa > sc)
    {
        max_value = sa;
        //@ assert max_value == product(a, b);
    }
    else
    {
        max_value = sc;
        //@ assert max_value == product(c, d);
    }

    return max_value;
}
