#include <stdbool.h>

/*@
    predicate in_range(integer x) = 1 <= x <= 10000;

    logic integer safe_mult(integer t, integer s) = t * s;

    lemma mult_bounds:
        \forall integer t, s;
            in_range(t) && in_range(s) ==> 0 <= safe_mult(t, s) <= 100000000;
*/

/*@
    requires in_range(d);
    requires in_range(t);
    requires in_range(s);
    ensures \result == (d <= t * s);
    assigns \nothing;
*/
bool func(unsigned int d, unsigned int t, unsigned int s)
{
    bool ans;
    //@ assert t <= 10000;
    //@ assert s <= 10000;
    //@ assert t * s <= 10000 * 10000;
    ans = (d <= t * s);
    return ans;
}
