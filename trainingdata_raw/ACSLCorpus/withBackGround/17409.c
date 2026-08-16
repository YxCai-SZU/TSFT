#include <stdbool.h>

/*@
    predicate valid_params(integer a, integer b, integer c, integer d, integer e, integer k) =
        0 <= a && a < b && b < c && c < d && d < e && e <= 123 &&
        0 <= k && k <= 123;

    logic integer distance(integer a, integer e) = e - a;
*/

/*@
    requires valid_params(a, b, c, d, e, k);
    ensures \result == (distance(a, e) <= k);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c, 
          unsigned int d, unsigned int e, unsigned int k)
{
    bool ans = true;
    unsigned int dist = e - a;

    //@ assert dist == distance(a, e);

    if (dist > k) {
        ans = false;
    }

    //@ assert ans == (distance(a, e) <= k);
    return ans;
}
