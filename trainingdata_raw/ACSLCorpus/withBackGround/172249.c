#include <limits.h>

/*@
    predicate in_range(integer v) = 1 <= v <= 10000;

    logic integer product(integer x, integer y) = x * y;

    lemma product_bound:
        \forall integer a, b;
            in_range(a) && in_range(b) ==> product(a, b) <= 100000000;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    ensures \result == product(a, b) || \result == product(c, d);
    ensures \result >= product(a, b);
    ensures \result >= product(c, d);
    assigns \nothing;
*/
long func(long a, long b, long c, long d)
{
    // Variable declarations at scope top
    long x;
    long ab_product;
    long cd_product;

    //@ assert in_range(a) && in_range(b);
    //@ assert product(a, b) <= 100000000;
    ab_product = a * b;

    //@ assert in_range(c) && in_range(d);
    //@ assert product(c, d) <= 100000000;
    cd_product = c * d;

    if (ab_product > cd_product)
    {
        x = ab_product;
        //@ assert x == product(a, b);
    }
    else
    {
        x = cd_product;
        //@ assert x == product(c, d);
    }

    //@ assert x >= product(a, b);
    //@ assert x >= product(c, d);
    return x;
}
