#include <stdint.h>

/*@
    predicate valid_params(integer n, integer k) =
        1 <= n <= 100000 && 0 <= k <= n - 1;

    logic integer compute_max(integer n, integer k) =
        n - k < k ? n - k : k;

    logic integer compute_min(integer n, integer k) =
        n - k < k ? k : n - k;

    logic integer compute_ans(integer max, integer min) =
        max - min - 1 >= 0 ? max - min - 1 : 0;

    lemma ans_nonnegative:
        \forall integer n, k;
        valid_params(n, k) ==>
        compute_ans(compute_max(n, k), compute_min(n, k)) >= 0;
*/

/*@
    requires valid_params(n, k);
    ensures \result >= 0;
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t k)
{
    int64_t max;
    int64_t min;
    int64_t ans;

    //@ assert valid_params(n, k);

    if (n - k < k)
    {
        max = n - k;
        min = k;
    }
    else
    {
        max = k;
        min = n - k;
    }

    //@ assert max == compute_max(n, k);
    //@ assert min == compute_min(n, k);

    if (max - min - 1 >= 0)
    {
        ans = max - min - 1;
    }
    else
    {
        ans = 0;
    }

    //@ assert ans == compute_ans(max, min);
    //@ assert ans >= 0;

    return ans;
}
