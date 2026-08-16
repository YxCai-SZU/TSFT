#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    logic integer product(integer x, integer y) = x * y;

    lemma product_bound:
        \forall integer x, y;
            valid_range(x) && valid_range(y) ==> product(x, y) <= 100000000;

    lemma product_positive:
        \forall integer x, y;
            valid_range(x) && valid_range(y) ==> product(x, y) >= 1;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == product(a, b) || \result == product(c, d);
    ensures \result >= 1;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    // Variable declarations at scope top
    int64_t sa;
    int64_t sc;
    int64_t s;

    //@ assert valid_range(a) && valid_range(b);
    //@ assert product(a, b) <= 100000000;
    sa = a * b;

    //@ assert valid_range(c) && valid_range(d);
    //@ assert product(c, d) <= 100000000;
    sc = c * d;

    if (sa > sc) {
        s = sa;
    } else {
        s = sc;
    }

    //@ assert s == product(a, b) || s == product(c, d);
    //@ assert s >= 1;

    return s;
}
