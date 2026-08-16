#include <stdint.h>

/*@
    predicate valid_params(integer N, integer A) =
        1 <= N && N <= 100 && 0 <= A && A <= N * N;

    logic integer compute_ans(integer N, integer A) = N * N - A;

    lemma N_square_bound: \forall integer N; 1 <= N <= 100 ==> N * N <= 10000;
*/

/*@
    requires valid_params(N, A);
    ensures \result == compute_ans(N, A);
    assigns \nothing;
*/
uint32_t func(uint32_t N, uint32_t A) {
    // Variable declarations at scope top
    uint32_t ans;

    //@ assert N * N <= 10000;
    ans = N * N - A;
    return ans;
}
