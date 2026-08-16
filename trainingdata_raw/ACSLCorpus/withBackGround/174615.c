#include <stddef.h>

/*@
    predicate valid_params(integer n, int *h) =
        n >= 1 && n <= 20 &&
        \valid(h + (0 .. n-1)) &&
        \forall integer i; 0 <= i < n ==> h[i] >= 1 && h[i] <= 100;

    predicate loop_invariant(integer n, int *h, integer index, integer ans, integer max_h) =
        index <= n &&
        ans >= 1 &&
        ans <= index &&
        valid_params(n, h) &&
        index > 0;

    lemma ans_bounds: \forall integer n, integer ans; 
        loop_invariant(n, (int *)0, n, ans, 0) ==> ans >= 1 && ans <= n;
*/

/*@
    requires valid_params(n, h);
    ensures \result >= 1 && \result <= n;
    assigns \nothing;
*/
int func(size_t n, int *h) {
    int max_h;
    int ans;
    size_t index;
    
    max_h = h[0];
    ans = 1;
    index = 1;
    
    /*@
        loop invariant loop_invariant(n, h, index, ans, max_h);
        loop invariant index <= n;
        loop assigns max_h, ans, index;
        loop variant n - index;
    */
    while (index < n) {
        //@ assert valid_params(n, h);
        if (max_h <= h[index]) {
            max_h = h[index];
            ans += 1;
        }
        //@ assert ans >= 1 && ans <= index + 1;
        index += 1;
    }
    
    //@ assert ans >= 1 && ans <= n;
    return ans;
}
