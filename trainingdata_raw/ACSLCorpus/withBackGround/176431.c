#include <stdbool.h>

/*@
    predicate strict_order(integer a, integer b, integer c, integer d, integer e) =
        0 <= a && a < b && b < c && c < d && d < e && e <= 123;

    predicate valid_k(integer k) = 0 <= k && k <= 123;

    logic integer distance(integer a, integer e) = e - a;
*/

/*@
    requires strict_order(a, b, c, d, e);
    requires valid_k(k);
    ensures \result == (distance(a, e) <= k);
*/
bool func(long long a, long long b, long long c, long long d, long long e, long long k)
{
    long long dist;
    //@ assert strict_order(a, b, c, d, e);
    //@ assert valid_k(k);
    dist = e - a;
    
    if (dist <= k)
    {
        //@ assert distance(a, e) <= k;
        return true;
    }
    else
    {
        //@ assert distance(a, e) > k;
        return false;
    }
}
