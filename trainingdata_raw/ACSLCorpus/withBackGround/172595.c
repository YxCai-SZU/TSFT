#include <stdbool.h>

/*@
    predicate valid_params(integer d, integer t, integer s) =
        1 <= d <= 10000 &&
        1 <= t <= 10000 &&
        1 <= s <= 10000;

    logic integer product(integer s, integer t) = s * t;

    lemma product_bound:
        \forall integer d, t, s;
        valid_params(d, t, s) ==> product(s, t) <= 100000000;
*/

/*@
    requires valid_params(d, t, s);
    ensures \result == (s * t >= d);
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    // Variable declarations at scope top
    bool result;

    //@ assert valid_params(d, t, s);
    //@ assert product(s, t) >= d || product(s, t) < d;
    //@ assert product(s, t) <= 100000000;

    result = (s * t >= d);
    return result;
}
