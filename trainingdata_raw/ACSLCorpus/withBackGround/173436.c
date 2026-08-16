#include <stddef.h>

/*@
    predicate valid_params(integer n, integer k) =
        1 <= n && n <= 1000000000 &&
        1 <= k && k <= n;

    logic integer compute_ans(integer n, integer k) =
        n - k < k ? n - k : k - 1;

    lemma ans_nonnegative:
        \forall integer n, k;
        valid_params(n, k) ==> compute_ans(n, k) >= 0;

    lemma ans_less_than_n:
        \forall integer n, k;
        valid_params(n, k) ==> compute_ans(n, k) < n;
*/

/*@
    requires valid_params(n, k);
    ensures \result >= 0;
    ensures \result < n;
    assigns \nothing;
*/
size_t func(size_t n, size_t k)
{
    size_t ans;

    //@ assert valid_params(n, k);

    if (n - k < k)
    {
        ans = n - k;
        //@ assert ans == compute_ans(n, k);
    }
    else
    {
        ans = k - 1;
        //@ assert ans == compute_ans(n, k);
    }

    //@ assert ans >= 0;
    //@ assert ans < n;
    return ans;
}
