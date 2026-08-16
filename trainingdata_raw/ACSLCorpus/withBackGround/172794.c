#include <stdint.h>

/*@
    predicate valid_params(integer n, integer k) =
        1 <= n <= 100 && 1 <= k <= 100;

    logic integer compute_ans(integer n, integer k) =
        k - n < 0 ? n + (k - n) : 0;

    lemma ans_bounds: \forall integer n, k;
        valid_params(n, k) ==> 0 <= compute_ans(n, k) <= n;
*/

/*@
    requires valid_params(n, k);
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
int32_t func(int32_t n, int32_t k)
{
    int32_t ans;
    int32_t rem;

    ans = n;
    rem = k - n;

    if (rem < 0)
    {
        ans = ans + rem;
    }
    else
    {
        ans = 0;
    }

    //@ assert ans >= 0 && ans <= n;
    return ans;
}
