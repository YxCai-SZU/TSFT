#include <stddef.h>

/*@
    predicate valid_params(integer n, integer m, integer k) =
        1 <= n <= 1000 &&
        1 <= m <= 1000 &&
        0 <= k <= n * m;

    logic integer compute_ans(integer n, integer m, integer k) =
        n * m - k;

    logic integer clamp_non_negative(integer x) =
        x < 0 ? 0 : x;

    lemma product_bound:
        \forall integer n, m;
        1 <= n <= 1000 && 1 <= m <= 1000 ==> n * m <= 1000000;
*/

/*@
    requires valid_params(n, m, k);
    ensures \result == clamp_non_negative(compute_ans(n, m, k));
*/
size_t func(size_t n, size_t m, size_t k)
{
    // Variable declarations
    size_t ans;

    //@ assert n * m <= 1000000;
    ans = n * m - k;

    // Manual max function implementation
    if (ans > n * m) {
        ans = 0;
    }

    //@ assert ans == clamp_non_negative(compute_ans(n, m, k));
    return ans;
}
