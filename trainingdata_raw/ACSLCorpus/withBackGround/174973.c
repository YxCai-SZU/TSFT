#include <limits.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    logic integer product(integer x, integer y) = x * y;

    lemma product_bounds:
        \forall integer x, y;
            valid_range(x) && valid_range(y) ==> 
            1 <= product(x, y) <= 10000 * 10000;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == product(a, b) || \result == product(c, d);
    ensures 1 <= \result <= 10000 * 10000;
    assigns \nothing;
*/
long func(long a, long b, long c, long d)
{
    long sa;
    long sc;
    long result;

    //@ assert valid_range(a) && valid_range(b);
    //@ assert 1 <= product(a, b) <= 10000 * 10000;
    sa = a * b;

    //@ assert valid_range(c) && valid_range(d);
    //@ assert 1 <= product(c, d) <= 10000 * 10000;
    sc = c * d;

    if (sa > sc) {
        result = sa;
    } else {
        result = sc;
    }

    //@ assert result == product(a, b) || result == product(c, d);
    return result;
}
