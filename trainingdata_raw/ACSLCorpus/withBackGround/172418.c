#include <stdint.h>

/*@
    predicate valid_params(integer n, integer k) =
        1 <= n && n <= 1000000000000000000 &&
        1 <= k && k <= 1000000000000000000;

    logic integer abs_val(integer x) = x < 0 ? -x : x;

    logic integer min_val(integer a, integer b) = a < b ? a : b;

    lemma ans_bounds:
        \forall integer n, k, ans;
        valid_params(n, k) ==>
        ans == (n < 0 ? -min_val(abs_val(n), abs_val(k)) : min_val(abs_val(n), abs_val(k))) ==>
        ans <= n && ans >= 0 && ans <= k;
*/

/*@
    requires valid_params(n, k);
    ensures \result <= n;
    ensures \result >= 0;
    ensures \result <= k;
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t k)
{
    int64_t abs_n;
    int64_t abs_k;
    int64_t min_val;
    int64_t ans;

    abs_n = n < 0 ? -n : n;
    abs_k = k < 0 ? -k : k;
    min_val = abs_n < abs_k ? abs_n : abs_k;
    ans = n < 0 ? -min_val : min_val;

    //@ assert ans <= n;
    //@ assert ans >= 0;
    //@ assert ans <= k;

    return ans;
}
