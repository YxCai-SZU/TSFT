#include <stdbool.h>

/*@
    predicate is_valid_range(integer a, integer b, integer c, integer d, integer e, integer k) =
        0 <= a && a < b && b < c && c < d && d < e && e <= 123 &&
        0 <= k && k <= 123;

    logic integer condition_holds(integer a, integer b, integer c, integer d, integer e, integer k) =
        (a + k >= e ? 1 : 0) +
        (b + k >= e ? 1 : 0) +
        (c + k >= e ? 1 : 0) +
        (d + k >= e ? 1 : 0) +
        (e + k >= a ? 1 : 0) +
        (b + k >= a ? 1 : 0) +
        (c + k >= a ? 1 : 0) +
        (d + k >= a ? 1 : 0);

    lemma arithmetic_bounds:
        \forall integer a, b, c, d, e, k;
        is_valid_range(a, b, c, d, e, k) ==>
        a + k >= 0 && a + k <= 246 &&
        b + k >= 0 && b + k <= 246 &&
        c + k >= 0 && c + k <= 246 &&
        d + k >= 0 && d + k <= 246 &&
        e + k >= 0 && e + k <= 246;
*/

/*@
    requires is_valid_range(a, b, c, d, e, k);
    ensures \result == (condition_holds(a, b, c, d, e, k) > 0);
    assigns \nothing;
*/
bool func(long a, long b, long c, long d, long e, long k)
{
    bool ans = false;

    //@ assert a + k >= 0 && a + k <= 246;
    if (a + k >= e)
    {
        ans = true;
    }

    //@ assert b + k >= 0 && b + k <= 246;
    if (b + k >= e)
    {
        ans = true;
    }

    //@ assert c + k >= 0 && c + k <= 246;
    if (c + k >= e)
    {
        ans = true;
    }

    //@ assert d + k >= 0 && d + k <= 246;
    if (d + k >= e)
    {
        ans = true;
    }

    //@ assert e + k >= 0 && e + k <= 246;
    if (e + k >= a)
    {
        ans = true;
    }

    //@ assert b + k >= 0 && b + k <= 246;
    if (b + k >= a)
    {
        ans = true;
    }

    //@ assert c + k >= 0 && c + k <= 246;
    if (c + k >= a)
    {
        ans = true;
    }

    //@ assert d + k >= 0 && d + k <= 246;
    if (d + k >= a)
    {
        ans = true;
    }

    //@ assert ans == (condition_holds(a, b, c, d, e, k) > 0);
    return ans;
}
