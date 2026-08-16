#include <stdint.h>

/*@
    predicate valid_params(integer a, integer b, integer c, integer k) =
        0 <= a && 0 <= b && 0 <= c &&
        1 <= k && k <= a + b + c &&
        a + b + c <= 2000000000;

    logic integer min_a_k(integer a, integer k) = (a < k) ? a : k;

    logic integer min_k_a_b(integer a, integer b, integer k) =
        (k - a - b < 0) ? -(k - a - b) : 0;

    lemma min_a_k_bound: \forall integer a, k; 0 <= a && 1 <= k ==> min_a_k(a, k) <= k;

    lemma min_k_a_b_nonneg: \forall integer a, b, k; 0 <= a && 0 <= b && 1 <= k ==> min_k_a_b(a, b, k) >= 0;

    lemma result_bound_upper: \forall integer a, b, c, k;
        valid_params(a, b, c, k) ==>
        min_a_k(a, k) - min_k_a_b(a, b, k) <= k;

    lemma result_bound_lower: \forall integer a, b, c, k;
        valid_params(a, b, c, k) ==>
        min_a_k(a, k) - min_k_a_b(a, b, k) >= k - (a + b + c);
*/

/*@
    requires valid_params(a, b, c, k);
    ensures \result <= k;
    ensures \result >= k - (a + b + c);
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t min_a_k;
    int64_t min_k_a_b;
    int64_t res;

    //@ assert valid_params(a, b, c, k);

    min_a_k = (a < k) ? a : k;
    //@ assert min_a_k == min_a_k(a, k);

    min_k_a_b = (k - a - b < 0) ? -(k - a - b) : 0;
    //@ assert min_k_a_b == min_k_a_b(a, b, k);

    //@ assert min_a_k <= k;
    //@ assert min_k_a_b >= 0;
    //@ assert min_a_k - min_k_a_b <= k;
    //@ assert min_a_k - min_k_a_b >= k - (a + b + c);

    res = min_a_k - min_k_a_b;
    return res;
}
