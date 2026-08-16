#include <stdint.h>

/*@
    predicate bounds(integer n, integer k) =
        2 <= n && n <= 100 &&
        2 <= k && k <= 100;

    logic integer expected_result(integer n, integer k) =
        (n - 1) * (k - 1);

    lemma multiplication_bounds:
        \forall integer n, k;
            bounds(n, k) ==>
            (n - 1) * (k - 1) <= 99 * 99;
*/

/*@
    requires bounds(n, k);
    ensures \result == expected_result(n, k);
    assigns \nothing;
*/
int32_t func(int32_t n, int32_t k)
{
    uint32_t n_unchecked;
    uint32_t k_unchecked;
    uint32_t n_converted;
    uint32_t k_converted;
    uint32_t ans_unchecked;
    int32_t ans;

    n_unchecked = (uint32_t)n;
    k_unchecked = (uint32_t)k;

    //@ assert n_unchecked > 1 && n_unchecked <= 100;
    //@ assert k_unchecked > 1 && k_unchecked <= 100;

    n_converted = n_unchecked - 1;
    k_converted = k_unchecked - 1;

    //@ assert n_converted >= 1 && n_converted <= 99;
    //@ assert k_converted >= 1 && k_converted <= 99;

    //@ assert n_converted * k_converted <= 99 * 99;

    ans_unchecked = n_converted * k_converted;
    ans = (int32_t)ans_unchecked;

    return ans;
}
