#include <stdint.h>

/*@
    predicate bounds(integer N, integer M) =
        1 <= N && N <= 20 &&
        1 <= M && M <= 20;

    logic integer result_value(integer N, integer M) =
        N * M - (N + M - 1);

    lemma arithmetic_bounds:
        \forall integer N, M;
        bounds(N, M) ==>
        N * M <= 400 &&
        N + M - 1 <= 39 &&
        N * M >= N + M - 1;
*/

/*@
    requires bounds(N, M);
    ensures \result == result_value(N, M);
    assigns \nothing;
*/
int64_t func(int64_t N, int64_t M)
{
    // Variable declarations at scope top
    int64_t ans;

    //@ assert N * M <= 400;
    //@ assert N + M - 1 <= 39;
    //@ assert N * M >= N + M - 1;

    ans = N * M - (N + M - 1);
    return ans;
}
