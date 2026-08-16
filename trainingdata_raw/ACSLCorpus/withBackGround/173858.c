#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    logic integer product(integer a, integer b) = a * b;

    lemma product_bound:
        \forall integer t, s;
        valid_range(t) && valid_range(s) ==> product(t, s) <= 10000 * 10000;
*/

/*@
    requires valid_range(d) && valid_range(t) && valid_range(s);
    ensures \result == (product(t, s) >= d);
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    // Variable declarations at scope top
    bool result;

    //@ assert valid_range(t) && valid_range(s);
    //@ assert product(t, s) <= 10000 * 10000;

    result = (t * s) >= d;
    return result;
}
