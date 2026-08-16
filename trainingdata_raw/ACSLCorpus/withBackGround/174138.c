#include <stdbool.h>

/*@
    predicate strict_ordering(long a, long b, long c, long d, long e) =
        0 <= a && a < b && b < c && c < d && d < e && e <= 123;

    predicate valid_k(long k) = 0 <= k && k <= 123;

    logic integer distance(long a, long e) = e - a;

    lemma dist_non_negative:
        \forall long a, b, c, d, e; strict_ordering(a, b, c, d, e) ==> distance(a, e) >= 0;
*/

/*@
    requires strict_ordering(a, b, c, d, e);
    requires valid_k(k);
    ensures \result == (distance(a, e) <= k);
    assigns \nothing;
*/
bool func(long a, long b, long c, long d, long e, long k)
{
    long dist;
    bool result;

    //@ assert strict_ordering(a, b, c, d, e);
    
    dist = e - a;
    //@ assert dist == distance(a, e);
    
    if (dist <= k)
    {
        result = true;
    }
    else
    {
        result = false;
    }
    
    //@ assert result == (distance(a, e) <= k);
    return result;
}
