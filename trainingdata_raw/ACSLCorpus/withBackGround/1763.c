#include <stdbool.h>

/*@
    predicate is_valid_params(integer d, integer t, integer s) =
        1 <= d <= 10000 &&
        1 <= t <= 10000 &&
        1 <= s <= 10000;

    logic integer safe_mult(integer t, integer s) = t * s;

    lemma mult_bounds:
        \forall integer t, s;
        is_valid_params(1, t, s) ==> safe_mult(t, s) <= 10000 * 10000;
*/

/*@
    requires is_valid_params(d, t, s);
    ensures \result == (d <= t * s);
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    // Variable declarations at scope top
    bool result;

    //@ assert 1 <= t <= 10000;
    //@ assert 1 <= s <= 10000;
    //@ assert t * s <= 10000 * 10000;

    result = d <= t * s;
    return result;
}
