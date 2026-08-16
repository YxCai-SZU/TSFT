#include <stdbool.h>

/*@ predicate valid_params(integer n, integer k, int *h) =
    n >= 1 && n <= 100000 &&
    k >= 1 && k <= 500 &&
    \valid(h + (0 .. n-1)) &&
    \forall integer i; 0 <= i < n ==> h[i] >= 1 && h[i] <= 500;
*/

/*@ predicate ans_invariant(integer n, integer k, int *h, integer index, integer ans) =
    index >= 0 && index <= n &&
    ans >= 0 && ans <= index &&
    valid_params(n, k, h) &&
    (index > 0 ==> \forall integer i; 0 <= i < index ==> (k <= h[i] ==> ans >= 1)) &&
    (index > 0 ==> \forall integer i; 0 <= i < index ==> (k > h[i] ==> ans == ans));
*/

/*@ lemma ans_bounded: \forall integer n, integer k, int *h, integer index, integer ans;
    ans_invariant(n, k, h, index, ans) ==> ans <= n;
*/

/*@ requires valid_params(n, k, h);
    ensures \result >= 0 && \result <= n;
*/
int func(int n, int k, int *h) {
    int ans = 0;
    int index = 0;
    
    /*@ loop invariant ans_invariant(n, k, h, index, ans);
        loop assigns ans, index;
        loop variant n - index;
    */
    while (index < n) {
        //@ assert ans_invariant(n, k, h, index, ans);
        
        if (k <= h[index]) {
            ans += 1;
        }
        index += 1;
        
        //@ assert ans_invariant(n, k, h, index, ans);
    }
    
    //@ assert ans <= n;
    return ans;
}
