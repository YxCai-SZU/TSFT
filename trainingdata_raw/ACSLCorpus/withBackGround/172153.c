#include <stdbool.h>

/*@
    predicate bounds(integer a, integer b, integer c, integer d, integer e, integer k) =
        0 <= a <= 123 &&
        0 <= b <= 123 &&
        0 <= c <= 123 &&
        0 <= d <= 123 &&
        0 <= e <= 123 &&
        0 <= k <= 123 &&
        a < b && b < c && c < d && d < e;

    logic integer distance(integer a, integer e) = e - a;

    lemma dist_identity:
        \forall integer a, e; distance(a, e) == e - a;
*/

/*@
    requires bounds(a, b, c, d, e, k);
    ensures \result == (e - a <= k);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long c,
          unsigned long long d, unsigned long long e, unsigned long long k)
{
    unsigned long long dist;

    //@ assert distance(a, e) == e - a;

    dist = e - a;

    //@ assert dist == distance(a, e);

    return dist <= k;
}
