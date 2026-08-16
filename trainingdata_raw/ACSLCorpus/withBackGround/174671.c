#include <stdbool.h>

/*@
    predicate is_valid_range(integer a, integer b, integer c, integer d, integer e, integer k) =
        a >= 0 && b >= 0 && c >= 0 && d >= 0 && e >= 0 &&
        a <= b && b <= c && c <= d && d <= e && e <= 123 &&
        k >= 0 && k <= 123;

    logic integer condition_holds(integer a, integer b, integer c, integer d, integer e, integer k) =
        (b - a <= k) ? 1 : ((c - a <= k) ? 1 : ((d - a <= k) ? 1 : ((e - a <= k) ? 1 : ((a - e <= k) ? 1 : 0))));

    lemma condition_equivalence:
        \forall integer a, b, c, d, e, k;
        is_valid_range(a, b, c, d, e, k) ==>
        (condition_holds(a, b, c, d, e, k) == 1) ==
        ((b - a <= k) || (c - a <= k) || (d - a <= k) || (e - a <= k) || (a - e <= k));
*/

/*@
    requires is_valid_range(a, b, c, d, e, k);
    ensures \result == (condition_holds(a, b, c, d, e, k) == 1);
    assigns \nothing;
*/
bool func(long a, long b, long c, long d, long e, long k)
{
    bool ok = false;

    //@ assert ok == false;

    if (b - a <= k)
    {
        ok = true;
    }
    //@ assert ok == ((b - a <= k) || false);

    if (c - a <= k)
    {
        ok = true;
    }
    //@ assert ok == ((b - a <= k) || (c - a <= k) || false);

    if (d - a <= k)
    {
        ok = true;
    }
    //@ assert ok == ((b - a <= k) || (c - a <= k) || (d - a <= k) || false);

    if (e - a <= k)
    {
        ok = true;
    }
    //@ assert ok == ((b - a <= k) || (c - a <= k) || (d - a <= k) || (e - a <= k) || false);

    if (a - e <= k)
    {
        ok = true;
    }
    //@ assert ok == ((b - a <= k) || (c - a <= k) || (d - a <= k) || (e - a <= k) || (a - e <= k));

    //@ assert ok == (condition_holds(a, b, c, d, e, k) == 1);
    return ok;
}
