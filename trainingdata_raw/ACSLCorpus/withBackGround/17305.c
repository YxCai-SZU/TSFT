#include <stdbool.h>

/*@
    predicate bounds(integer a, integer b, integer c, integer d, integer e, integer k) =
        a >= 0 && b >= 0 && c >= 0 && d >= 0 && e >= 0 && k >= 0 &&
        a <= 123 && b <= 123 && c <= 123 && d <= 123 && e <= 123 && k <= 123 &&
        a < b && b < c && c < d && d < e;

    lemma dist_nonnegative: \forall integer a, e; a >= 0 && e >= 0 && a < e ==> e - a >= 0;
    lemma dist_bounded: \forall integer a, e; a >= 0 && e <= 123 && a < e ==> e - a <= 123;
*/

/*@
    requires bounds(a, b, c, d, e, k);
    ensures \result == true <==> (e - a <= k);
    assigns \nothing;
*/
bool func(long a, long b, long c, long d, long e, long k)
{
    long dist;
    //@ assert a >= 0 && e >= 0 && a < b && b < c && c < d && d < e;
    //@ assert e - a >= 0;
    //@ assert e - a <= 123;
    
    dist = e - a;
    
    if (dist <= k)
    {
        return true;
    }
    else
    {
        return false;
    }
}
