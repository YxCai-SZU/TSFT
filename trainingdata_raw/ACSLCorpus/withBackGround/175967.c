#include <stdbool.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 10000;

    logic integer safe_mult(integer a, integer b) = a * b;

    lemma mult_bounds:
        \forall integer t, s;
        valid_range(t) && valid_range(s) ==> safe_mult(t, s) <= 10000 * 10000;

    lemma comparison_well_defined:
        \forall integer d, t, s;
        valid_range(d) && valid_range(t) && valid_range(s) ==>
        (d <= safe_mult(t, s) || d > safe_mult(t, s));
*/

/*@
    requires valid_range(d) && valid_range(t) && valid_range(s);
    ensures \result == (d <= t * s);
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    // Declare all variables at the top
    int ds;
    bool result;

    //@ assert valid_range(t) && valid_range(s);
    //@ assert t * s <= 10000 * 10000;

    ds = t * s;

    //@ assert valid_range(d) && ds <= 10000 * 10000;
    //@ assert d <= ds || d > ds;

    result = d <= ds;
    return result;
}
