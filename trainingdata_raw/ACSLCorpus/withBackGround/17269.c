#include <stdint.h>

/*@
    predicate valid_params(integer A, integer B, integer C, integer K) =
        0 <= A <= 1000000000 &&
        0 <= B <= 1000000000 &&
        0 <= C <= 1000000000 &&
        1 <= K <= 1000000000 &&
        A + B + C >= K;

    logic integer compute_max_sum(integer A, integer B, integer C, integer K) =
        (A >= K ? K : A) - (K - A - B > 0 ? K - A - B : 0);

    lemma max_sum_bounds:
        \forall integer A, B, C, K;
        valid_params(A, B, C, K) ==>
        compute_max_sum(A, B, C, K) >= -C &&
        compute_max_sum(A, B, C, K) <= A;
*/

/*@
    requires valid_params(A, B, C, K);
    ensures \result >= -C && \result <= A;
*/
int64_t func(int64_t A, int64_t B, int64_t C, int64_t K)
{
    int64_t max_sum;
    int64_t remaining;

    max_sum = 0;
    remaining = K;

    if (A >= remaining) {
        max_sum += remaining;
        remaining -= remaining;
    } else {
        max_sum += A;
        remaining -= A;
    }

    if (B >= remaining) {
        remaining -= remaining;
    } else {
        remaining -= B;
    }

    max_sum -= remaining;

    //@ assert max_sum >= -C;
    //@ assert max_sum <= A;

    return max_sum;
}
