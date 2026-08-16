#include <stdbool.h>

/*@
    predicate is_valid_params(integer d, integer t, integer s) =
        1 <= d <= 10000 &&
        1 <= t <= 10000 &&
        1 <= s <= 10000;

    logic integer safe_product(integer t, integer s) = t * s;

    lemma product_bounds:
        \forall integer t, s;
            is_valid_params(1, t, s) ==> 1 <= safe_product(t, s) <= 100000000;
*/

/*@
    requires is_valid_params(d, t, s);
    ensures \result == (d <= t * s);
    assigns \nothing;
*/
bool func(long d, long t, long s)
{
    // Variable declarations at scope top
    bool result;

    //@ assert 1 <= t <= 10000;
    //@ assert 1 <= s <= 10000;
    //@ assert t * s <= 10000 * 10000;

    if (d <= t * s) {
        //@ assert d <= t * s;
        result = true;
    } else {
        //@ assert d > t * s;
        result = false;
    }

    return result;
}
