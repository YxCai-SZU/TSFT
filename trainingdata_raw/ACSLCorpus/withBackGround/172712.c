#include <limits.h>

/*@
    predicate is_valid_range(integer x) = 1 <= x <= 10000;

    logic integer product(integer x, integer y) = x * y;

    lemma product_bound:
        \forall integer x, y;
            is_valid_range(x) && is_valid_range(y) ==> 
            product(x, y) <= 10000 * 10000;
*/

/*@
    requires is_valid_range(a);
    requires is_valid_range(b);
    requires is_valid_range(c);
    requires is_valid_range(d);
    ensures \result == product(a, b) || \result == product(c, d);
    ensures \result >= product(a, b);
    ensures \result >= product(c, d);
*/
long func(long a, long b, long c, long d)
{
    long sa;
    long sc;
    long res;

    //@ assert product(a, b) <= 10000 * 10000;
    sa = a * b;

    //@ assert product(c, d) <= 10000 * 10000;
    sc = c * d;

    if (sa > sc)
    {
        res = sa;
    }
    else
    {
        res = sc;
    }

    return res;
}
