#include <stdint.h>

/*@
    predicate valid_params(integer n, integer k) =
        1 <= n <= 200000 && 1 <= k <= 200000;

    logic integer expected_result(integer n, integer k) =
        (n / k) * (k - 1) + (n % k == 0 ? 0 : n % k - 1);

    lemma division_bound: \forall integer n, k; valid_params(n, k) ==> n / k <= 200000;
    lemma multiplication_bound: \forall integer n, k; valid_params(n, k) ==> (n / k) * (k - 1) <= 200000 * 199999;
    lemma modulus_bound: \forall integer n, k; valid_params(n, k) ==> n % k <= 200000;
    lemma subtraction_bound: \forall integer n, k; valid_params(n, k) && n % k != 0 ==> n % k - 1 <= 199999;
*/

/*@
    requires valid_params(n, k);
    ensures \result == expected_result(n, k);
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t k)
{
    // Variable declarations at top of scope
    uint64_t ans;
    uint64_t div_result;
    uint64_t mod_result;
    uint64_t temp;

    //@ assert n / k <= 200000;
    div_result = n / k;

    //@ assert div_result * (k - 1) <= 200000 * 199999;
    temp = div_result * (k - 1);

    //@ assert n % k <= 200000;
    mod_result = n % k;

    if (mod_result == 0)
    {
        ans = temp + 0;
    }
    else
    {
        //@ assert mod_result - 1 <= 199999;
        ans = temp + (mod_result - 1);
    }

    //@ assert ans == expected_result(n, k);
    return ans;
}
