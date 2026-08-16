#include <stdint.h>

/*@
    predicate is_valid_params(integer a, integer b, integer c, integer k) =
        1 <= a && a <= 1000000000 &&
        1 <= b && b <= 1000000000 &&
        1 <= c && c <= 1000000000 &&
        1 <= k && k <= 1000000000 &&
        a + b + c >= k;

    logic integer compute_result(integer a, integer b, integer c, integer k) =
        \let a_lim = (a < k) ? a : k;
        \let k_rem = k - a_lim;
        \let b_lim = (b < k_rem) ? b : k_rem;
        \let c_rem = k_rem - b_lim;
        \let r = a_lim - c_rem;
        (r > k) ? k : ((r < -k) ? -k : r);

    lemma result_bounds:
        \forall integer a, b, c, k;
        is_valid_params(a, b, c, k) ==>
        -k <= compute_result(a, b, c, k) <= k;
*/

/*@
    requires is_valid_params(a, b, c, k);
    ensures -k <= \result <= k;
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b, int32_t c, int32_t k)
{
    int32_t a_lim;
    int32_t k_remaining;
    int32_t b_lim;
    int32_t c_remaining;
    int32_t result;

    //@ assert a + b + c >= k;

    a_lim = (a < k) ? a : k;
    //@ assert 0 <= a_lim <= k;

    k_remaining = k - a_lim;
    //@ assert 0 <= k_remaining <= k;

    b_lim = (b < k_remaining) ? b : k_remaining;
    //@ assert 0 <= b_lim <= k_remaining;

    c_remaining = k_remaining - b_lim;
    //@ assert 0 <= c_remaining <= k_remaining;

    result = a_lim - c_remaining;
    //@ assert -k <= result <= k;

    if (result > k)
    {
        result = k;
    }
    else if (result < -k)
    {
        result = -k;
    }

    //@ assert -k <= result <= k;
    return result;
}
