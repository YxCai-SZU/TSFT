#include <limits.h>

/*@
    predicate in_range(integer v) = -10000 <= v <= 10000;

    logic integer safe_mul(integer x, integer y) = x * y;

    lemma mul_bounds:
        \forall integer x, y;
            in_range(x) && in_range(y) ==> 
            -100000000 <= safe_mul(x, y) <= 100000000;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    ensures \result == safe_mul(a, b) || \result == safe_mul(c, d);
    ensures \result >= safe_mul(a, b);
    ensures \result >= safe_mul(c, d);
    assigns \nothing;
*/
long func(long a, long b, long c, long d)
{
    // Variable declarations at top of scope
    long result;
    long ab_product;
    long cd_product;

    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert in_range(c);
    //@ assert in_range(d);

    // Calculate products
    ab_product = a * b;
    cd_product = c * d;

    //@ assert -100000000 <= ab_product <= 100000000;
    //@ assert -100000000 <= cd_product <= 100000000;

    if (ab_product > cd_product)
    {
        //@ assert ab_product >= cd_product;
        result = ab_product;
    }
    else
    {
        //@ assert cd_product >= ab_product;
        result = cd_product;
    }

    return result;
}
