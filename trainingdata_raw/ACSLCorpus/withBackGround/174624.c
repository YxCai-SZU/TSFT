#include <stdbool.h>

/*@
    predicate is_valid_range(integer a, integer b, integer c, integer d, integer e, integer k) =
        0 <= a < 123 &&
        0 <= b < 123 &&
        0 <= c < 123 &&
        0 <= d < 123 &&
        0 <= e < 123 &&
        0 <= k <= 123 &&
        a < b &&
        b < c &&
        c < d &&
        d < e;

    predicate condition_holds(integer a, integer b, integer c, integer d, integer e, integer k) =
        (b - a <= k) || (c - a <= k) || (d - a <= k) || (e - a <= k);
*/

/*@
    requires is_valid_range(a, b, c, d, e, k);
    ensures \result == 1 <==> condition_holds(a, b, c, d, e, k);
*/
bool func(long a, long b, long c, long d, long e, long k)
{
    bool ok = false;

    //@ assert a < b && b < c && c < d && d < e;

    if (b - a <= k)
    {
        ok = true;
    }
    else if (c - a <= k)
    {
        ok = true;
    }
    else if (d - a <= k)
    {
        ok = true;
    }
    else if (e - a <= k)
    {
        ok = true;
    }

    //@ assert ok == 1 <==> condition_holds(a, b, c, d, e, k);
    return ok;
}
