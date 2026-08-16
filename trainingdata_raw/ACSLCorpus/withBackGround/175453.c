#include <stdbool.h>

/*@
    predicate is_ordered(integer a, integer b, integer c, integer d, integer e) =
        a < b && b < c && c < d && d < e;

    predicate within_bounds(integer a, integer b, integer c, integer d, integer e, integer k) =
        a >= 0 && b >= 0 && c >= 0 && d >= 0 && e >= 0 && k >= 0 &&
        a <= 123 && b <= 123 && c <= 123 && d <= 123 && e <= 123 && k <= 123;

    logic integer condition_holds(integer a, integer b, integer c, integer d, integer e, integer k) =
        (b - a <= k) || (c - a <= k) || (d - a <= k) || (e - a <= k) ? 1 : 0;

    lemma ordering_lemma:
        \forall integer a, b, c, d, e, k;
        is_ordered(a, b, c, d, e) && within_bounds(a, b, c, d, e, k) ==>
        a < b && a < c && a < d && a < e;
*/

/*@
    requires is_ordered(a, b, c, d, e);
    requires within_bounds(a, b, c, d, e, k);
    ensures \result == (condition_holds(a, b, c, d, e, k) == 1);
*/
bool func(long a, long b, long c, long d, long e, long k)
{
    //@ assert is_ordered(a, b, c, d, e);
    //@ assert within_bounds(a, b, c, d, e, k);
    
    if (b - a <= k || c - a <= k || d - a <= k || e - a <= k)
    {
        return true;
    }
    else
    {
        return false;
    }
}
