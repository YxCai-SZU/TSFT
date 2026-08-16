#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    logic integer product(integer x, integer y) = x * y;

    lemma product_bound:
        \forall integer x, y;
            valid_range(x) && valid_range(y) ==> product(x, y) <= 100000000;

    lemma subtraction_bound:
        \forall integer sa, sc;
            sa >= 0 && sc >= 0 && sa <= 100000000 && sc <= 100000000 ==>
            (integer)sa - (integer)sc >= -100000000;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == (int)(a * b) - (int)(c * d);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t sa;
    uint32_t sc;
    int32_t result;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert product(a, b) <= 100000000;
    sa = a * b;

    //@ assert valid_range(c);
    //@ assert valid_range(d);
    //@ assert product(c, d) <= 100000000;
    sc = c * d;

    //@ assert sa >= 0 && sc >= 0;
    //@ assert (int32_t)sa - (int32_t)sc >= -100000000;
    result = (int32_t)sa - (int32_t)sc;

    return result;
}
