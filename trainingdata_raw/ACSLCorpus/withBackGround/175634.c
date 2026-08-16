#include <stdbool.h>

/*@
    predicate valid_params(integer d, integer t, integer s) =
        1 <= d <= 10000 &&
        1 <= t <= 10000 &&
        1 <= s <= 10000;

    logic integer safe_product(integer t, integer s) = t * s;

    lemma product_bounds:
        \forall integer t, s;
        valid_params(10000, t, s) ==> safe_product(t, s) <= 100000000;

    lemma product_no_overflow:
        \forall integer t, s;
        valid_params(10000, t, s) ==> safe_product(t, s) <= 9223372036854775807;
*/

/*@
    requires valid_params(d, t, s);
    ensures \result == (t * s >= d);
    assigns \nothing;
*/
bool func(long d, long t, long s)
{
    // Variable declarations at scope top
    bool result;

    //@ assert t > 0 && t <= 10000;
    //@ assert s > 0 && s <= 10000;
    //@ assert t * s <= 100000000;
    //@ assert t * s <= 9223372036854775807;

    result = (t * s >= d);
    return result;
}
