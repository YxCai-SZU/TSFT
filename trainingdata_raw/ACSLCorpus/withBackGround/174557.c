#include <stdint.h>

/*@
    predicate valid_params(integer a, integer b, integer c, integer k) =
        0 <= a && a <= 1000000000 &&
        0 <= b && b <= 1000000000 &&
        0 <= c && c <= 1000000000 &&
        1 <= k && k <= 1000000000 &&
        a + b + c >= k;

    logic integer compute_result(integer b, integer c, integer k) =
        2 * b + c - k;
*/

/*@
    requires valid_params(a, b, c, k);
    ensures \result == compute_result(b, c, k);
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t ans;

    //@ assert 2 * b + c >= 0;
    ans = 2 * b + c - k;
    return ans;
}
