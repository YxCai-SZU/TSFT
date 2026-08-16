#include <stdbool.h>

/*@
    predicate bounds(integer a, integer b, integer c, integer d, integer e, integer k) =
        a >= 0 && b >= 0 && c >= 0 && d >= 0 && e >= 0 &&
        a <= 123 && b <= 123 && c <= 123 && d <= 123 && e <= 123 &&
        k >= 0 && k <= 123 &&
        a < b && b < c && c < d && d < e;

    logic integer distance(integer e, integer a) = e - a;

    lemma dist_definition: \forall integer a, integer e; distance(e, a) == e - a;
*/

/*@
    requires bounds(a, b, c, d, e, k);
    ensures \result == true <==> (e - a <= k);
    assigns \nothing;
*/
bool func(long a, long b, long c, long d, long e, long k)
{
    long dist;

    dist = e - a;
    //@ assert distance(e, a) == e - a;

    return dist <= k;
}
