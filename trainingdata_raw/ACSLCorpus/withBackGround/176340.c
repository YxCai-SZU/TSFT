#include <stdbool.h>

/*@
    predicate valid_params(integer d, integer t, integer s) =
        1 <= d <= 10000 &&
        1 <= t <= 10000 &&
        1 <= s <= 10000;

    logic integer safe_product(integer t, integer s) = t * s;

    lemma product_bound: \forall integer t, s;
        valid_params(10000, t, s) ==> safe_product(t, s) <= 10000 * 10000;
*/

/*@
    requires valid_params(d, t, s);
    ensures \result == (t * s >= d);
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    // Variable declarations at top of scope
    bool ans;

    //@ assert 1 <= t <= 10000;
    //@ assert 1 <= s <= 10000;
    //@ assert t * s <= 10000 * 10000;

    ans = (t * s >= d);
    return ans;
}
