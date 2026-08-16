/*@
    predicate is_valid_range(integer a, integer b, integer c, integer d, integer e, integer k) =
        0 <= a <= 123 &&
        0 <= b <= 123 &&
        0 <= c <= 123 &&
        0 <= d <= 123 &&
        0 <= e <= 123 &&
        0 <= k <= 123 &&
        a < b &&
        b < c &&
        c < d &&
        d < e;

    logic integer distance(integer e, integer a) = e - a;
*/

#include <stdbool.h>

/*@
    requires is_valid_range(a, b, c, d, e, k);
    ensures \result == (distance(e, a) <= k);
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long c,
          unsigned long long d, unsigned long long e, unsigned long long k)
{
    unsigned long long dist;

    //@ assert a < e;
    dist = e - a;
    //@ assert dist == distance(e, a);
    return dist <= k;
}
