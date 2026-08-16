#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_params(integer N, integer K, int *h) =
        1 <= N <= 100000 &&
        1 <= K <= 500 &&
        \valid(h + (0 .. N-1)) &&
        \forall integer j; 0 <= j < N ==> 1 <= h[j] <= 500;

    predicate loop_invariant(integer i, integer N, integer ans, integer K, int *h) =
        0 <= i <= N &&
        0 <= ans <= i &&
        valid_params(N, K, h);
*/

/*@
    requires valid_params(N, K, h);
    ensures 0 <= \result <= N;
    assigns \nothing;
*/
int func(int N, int K, int *h) {
    int ans = 0;
    int i = 0;
    
    /*@
        loop invariant loop_invariant(i, N, ans, K, h);
        loop assigns i, ans;
        loop variant N - i;
    */
    while (i < N) {
        //@ assert 0 <= i < N;
        if (h[i] >= K) {
            ans += 1;
        }
        i += 1;
    }
    return ans;
}
