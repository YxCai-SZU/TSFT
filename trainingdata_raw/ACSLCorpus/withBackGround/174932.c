#include <stddef.h>

/*@ predicate valid_params(integer N, int *H) =
    N > 0 && N <= 20 &&
    \valid(H+(0..N-1)) &&
    \forall integer i; 0 <= i < N ==> 1 <= H[i] <= 100;
*/

/*@ predicate loop_invariant(integer i, integer N, integer ans, int max, int *H) =
    0 <= i <= N &&
    ans >= 0 &&
    ans <= i &&
    \valid(H+(0..N-1)) &&
    \forall integer j; 0 <= j < N ==> 1 <= H[j] <= 100 &&
    \forall integer k; 0 <= k < i ==> H[k] <= max;
*/

/*@ lemma ans_bounds:
    \forall integer N, ans;
    valid_params(N, (int *)0) && 0 <= ans <= N ==> ans >= 0 && ans <= N;
*/

/*@ requires valid_params(N, H);
    assigns \nothing;
    ensures \result >= 0 && \result <= N;
*/
int func(size_t N, int *H) {
    int max;
    int ans;
    size_t i;
    
    //@ assert valid_params(N, H);
    
    max = H[0];
    ans = 0;
    i = 0;
    
    /*@ loop invariant loop_invariant(i, N, ans, max, H);
        loop assigns i, ans, max;
        loop variant N - i;
    */
    while (i < N) {
        int h;
        
        //@ assert 0 <= i < N;
        h = H[i];
        
        if (max <= h) {
            //@ assert max <= h;
            ans += 1;
            max = h;
        }
        
        i += 1;
    }
    
    //@ assert ans >= 0;
    //@ assert ans <= N;
    return ans;
}
