#include <stddef.h>
#include <stdbool.h>

/*@
    predicate valid_params(integer n, integer k, int *h) =
        n >= 1 && n <= 100000 &&
        k >= 1 && k <= 500 &&
        \valid(h + (0 .. n-1)) &&
        \forall integer j; 0 <= j < n ==> h[j] >= 1 && h[j] <= 500;

    predicate loop_invariant(integer n, integer k, int *h, integer i, integer ans) =
        0 <= i <= n &&
        ans >= 0 &&
        ans <= i &&
        valid_params(n, k, h) &&
        \forall integer j; 0 <= j < i ==> (k <= h[j] ? ans >= 1 : ans >= 0);
*/

/*@
    requires valid_params(n, k, h);
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
int func(size_t n, int k, int *h) {
    int ans = 0;
    size_t i = 0;

    //@ ghost int *ghost_h = h;
    //@ ghost size_t ghost_n = n;
    //@ ghost int ghost_k = k;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant ans >= 0;
        loop invariant ans <= i;
        loop invariant valid_params(ghost_n, ghost_k, ghost_h);
        loop invariant \forall integer j; 0 <= j < i ==> (ghost_k <= ghost_h[j] ? ans >= 1 : ans >= 0);
        loop assigns i, ans;
        loop variant n - i;
    */
    while (i < n) {
        int hi = h[i];
        if (hi >= k) {
            ans += 1;
        }
        i += 1;
        //@ assert ans <= i;
    }
    return ans;
}
