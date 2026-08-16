#include <stdint.h>

/*@
    predicate is_valid_params(integer n, integer k) =
        0 <= n <= 1000000000000000000 &&
        1 <= k <= 1000000000000000000;

    logic integer compute_result(integer n, integer k) =
        k > n ? n : (k == n ? 0 : k - (n % k));

    lemma result_bound: \forall integer n, k;
        is_valid_params(n, k) ==> compute_result(n, k) <= k;
*/

/*@
    requires is_valid_params(n, k);
    ensures \result <= k;
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t k)
{
    uint64_t ans;

    if (k > n)
    {
        ans = n;
        //@ assert ans == compute_result(n, k);
    }
    else
    {
        if (k == n)
        {
            ans = 0;
            //@ assert ans == compute_result(n, k);
        }
        else
        {
            ans = k - (n % k);
            //@ assert ans == compute_result(n, k);
        }
    }

    //@ assert ans <= k;
    return ans;
}
