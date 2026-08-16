#include <stdint.h>

/*@
    predicate valid_params(integer N, integer A) =
        1 <= N <= 100 && 0 <= A <= N * N;

    logic integer compute_result(integer N, integer A) =
        N * N - A;

    lemma N_squared_bound:
        \forall integer N; 1 <= N <= 100 ==> N * N <= 10000;
*/

/*@
    requires valid_params(N, A);
    ensures \result == compute_result(N, A);
    assigns \nothing;
*/
uint32_t func(uint32_t N, uint32_t A)
{
    // Variable declarations at top of scope
    uint32_t result;

    //@ assert 1 <= N && N <= 100;
    //@ assert 0 <= A && A <= N * N;
    //@ assert N * N <= 10000;

    result = N * N - A;
    return result;
}
