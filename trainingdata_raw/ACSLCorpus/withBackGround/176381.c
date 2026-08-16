/*@
    predicate valid_params(integer d, integer t, integer s) =
        1 <= d <= 10000 &&
        1 <= t <= 10000 &&
        1 <= s <= 10000;

    logic integer safe_product(integer s, integer t) = s * t;

    lemma product_bounds:
        \forall integer s, integer t;
        valid_params(10000, t, s) ==> 1 <= safe_product(s, t) <= 100000000;
*/

#include <stdbool.h>

/*@
    requires valid_params(d, t, s);
    ensures \result == (s * t >= d);
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    // Variable declarations at scope top
    bool result;
    int product;

    //@ assert 1 <= d <= 10000;
    //@ assert 1 <= t <= 10000;
    //@ assert 1 <= s <= 10000;

    //@ assert t <= 10000;
    //@ assert s <= 10000;
    //@ assert s * t <= 10000 * 10000;
    //@ assert s * t >= 1;

    product = s * t;
    result = (product >= d);
    return result;
}
