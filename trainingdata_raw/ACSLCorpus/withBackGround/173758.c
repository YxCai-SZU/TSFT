#include <stdbool.h>

/*@
    predicate valid_params(integer d, integer t, integer s) =
        1 <= d && d <= 10000 &&
        1 <= t && t <= 10000 &&
        1 <= s && s <= 10000 &&
        d <= t * s;

    logic integer safe_product(integer t, integer s) = t * s;

    lemma product_bound:
        \forall integer t, s;
            1 <= t && t <= 10000 && 1 <= s && s <= 10000 ==>
            t * s <= 10000 * 10000;
*/

/*@
    requires valid_params(d, t, s);
    ensures \result == (d <= t * s);
    assigns \nothing;
*/
bool func(long d, long t, long s)
{
    // Variable declarations at scope top
    bool result;

    //@ assert t <= 10000;
    //@ assert s <= 10000;
    //@ assert t * s <= 10000 * 10000;
    //@ assert d <= t * s;

    result = (d <= t * s);
    return result;
}
