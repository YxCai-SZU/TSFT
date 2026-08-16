#include <stdbool.h>
#include <stdint.h>

/*@ predicate valid_params(integer N, integer K, int *H) =
    N >= 1 && N <= 100000 &&
    K >= 1 && K <= 500 &&
    \valid(H + (0 .. N-1)) &&
    \forall integer j; 0 <= j < N ==> H[j] >= 1 && H[j] <= 500;
*/

/*@ predicate ans_invariant(integer i, integer N, integer ans) =
    0 <= i && i <= N && 0 <= ans && ans <= i;
*/

/*@ lemma ans_bounds:
    \forall integer N, integer ans;
    ans_invariant(N, N, ans) ==> ans >= 0 && ans <= N;
*/

/*@
    requires valid_params(N, K, H);
    assigns \nothing;
    ensures \result >= 0 && \result <= N;
*/
uint32_t func(uint32_t N, uint32_t K, int *H) {
    uint32_t ans = 0;
    uint32_t i = 0;
    
    /*@
        loop invariant ans_invariant(i, N, ans);
        loop assigns ans, i;
        loop variant N - i;
    */
    while (i < N) {
        //@ assert 0 <= i && i < N;
        if (H[i] >= K) {
            ans = ans + 1;
        }
        i = i + 1;
    }
    //@ assert ans_invariant(N, N, ans);
    return ans;
}
