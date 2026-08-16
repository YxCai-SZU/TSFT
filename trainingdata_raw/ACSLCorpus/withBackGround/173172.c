#include <stddef.h>
#include <stdint.h>

/*@
    predicate valid_params(size_t N, size_t K, size_t *A) =
        2 <= K && K <= N && N <= 100000 &&
        \valid(A+(0..N-1)) &&
        \forall integer i; 0 <= i < N ==> 1 <= A[i] && A[i] <= N;

    logic integer compute_ans(integer N, integer K) =
        N == K ? 1 : (N - K - 1) / (K - 1) + 2;

    lemma ans_bounds: \forall integer N, K;
        2 <= K && K <= N && N <= 100000 ==>
        compute_ans(N, K) >= 0 && compute_ans(N, K) <= N;
*/

/*@
    requires valid_params(N, K, A);
    assigns \nothing;
    ensures 0 <= \result && \result <= N;
    ensures \result == compute_ans(N, K);
*/
size_t func(size_t N, size_t K, const size_t A[])
{
    size_t ans;

    //@ assert 2 <= K && K <= N && N <= 100000;
    
    if (N == K)
    {
        ans = 1;
        //@ assert ans == 1;
    }
    else
    {
        ans = (N - K - 1) / (K - 1) + 2;
        //@ assert ans >= 2;
    }

    //@ assert ans >= 0 && ans <= N;
    //@ assert ans == compute_ans(N, K);
    return ans;
}
