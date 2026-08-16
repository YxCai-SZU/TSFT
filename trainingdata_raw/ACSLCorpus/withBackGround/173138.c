#include <stdbool.h>

/*@
    predicate valid_params(integer n, integer k) =
        1 <= n && n <= 100 &&
        1 <= k && k <= 100;

    logic integer mod(integer n, integer k) = n % k;

    predicate ans_zero_implies_mod_zero(integer n, integer k, integer ans) =
        ans == 0 ==> mod(n, k) == 0;

    predicate ans_one_implies_mod_nonzero(integer n, integer k, integer ans) =
        ans == 1 ==> mod(n, k) != 0;
*/

/*@
    requires valid_params(n, k);
    ensures \result == 0 || \result == 1;
    ensures ans_zero_implies_mod_zero(n, k, \result);
    ensures ans_one_implies_mod_nonzero(n, k, \result);
*/
int func(int n, int k)
{
    int n_mod_k;
    int ans;

    n_mod_k = n % k;
    ans = 1;

    if (n_mod_k == 0)
    {
        ans = 0;
    }

    //@ assert ans == 0 || ans == 1;
    //@ assert ans == 0 ==> n % k == 0;
    //@ assert ans == 1 ==> n % k != 0;

    return ans;
}
