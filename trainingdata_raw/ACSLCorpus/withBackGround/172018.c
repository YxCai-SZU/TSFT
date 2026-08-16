#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    logic integer safe_mult(integer a, integer b) = a * b;

    lemma mult_bounds:
        \forall integer t, s;
        valid_range(t) && valid_range(s) ==> safe_mult(t, s) <= 100000000;
*/

/*@
    requires valid_range(d) && valid_range(t) && valid_range(s);
    requires d >= 0 && t >= 0 && s >= 0;
    ensures \result == (d <= t * s);
    assigns \nothing;
*/
bool func(long d, long t, long s)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert valid_range(t) && valid_range(s);
    //@ assert safe_mult(t, s) <= 100000000;
    //@ assert d <= 100000000;

    result = (d <= t * s);
    return result;
}
