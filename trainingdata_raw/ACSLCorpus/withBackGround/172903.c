#include <stdbool.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 10000;

    logic integer safe_mult(integer a, integer b) = a * b;

    lemma mult_bounds:
        \forall integer s, t;
            valid_range(s) && valid_range(t) ==>
            1 <= safe_mult(s, t) <= 10000 * 10000;
*/

/*@
    requires valid_range(d);
    requires valid_range(t);
    requires valid_range(s);
    ensures \result == (s * t >= d);
    assigns \nothing;
*/
bool func(long d, long t, long s)
{
    // Variable declarations at scope top
    bool res;

    //@ assert valid_range(s);
    //@ assert valid_range(t);
    //@ assert 1 <= safe_mult(s, t) <= 10000 * 10000;
    //@ assert safe_mult(s, t) >= 1;

    res = (s * t >= d);
    return res;
}
