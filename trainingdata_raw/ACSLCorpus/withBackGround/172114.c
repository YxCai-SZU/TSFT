#include <stddef.h>
#include <stdbool.h>

/*@ predicate valid_params(integer k, integer n, int *h) =
        1 <= k <= 500 &&
        1 <= n <= 100000 &&
        \valid(h + (0 .. n-1)) &&
        \forall integer i; 0 <= i < n ==> 1 <= h[i] <= 500;
*/

/*@ predicate loop_invariant(integer index, integer ans, integer n, integer k, int *h) =
        0 <= index <= n &&
        0 <= ans <= index &&
        \forall integer i; 0 <= i < n ==> 1 <= h[i] <= 500 &&
        1 <= n <= 100000 &&
        1 <= k <= 500;
*/

/*@ lemma ans_bounds: 
        \forall integer ans, integer n, integer k, int *h; 
        loop_invariant(n, ans, n, k, h) ==> 0 <= ans <= n;
*/

/*@ requires valid_params(k, n, h);
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
int func(int k, size_t n, const int *h) {
    int ans = 0;
    size_t index = 0;
    
    /*@ loop invariant loop_invariant(index, ans, n, k, h);
        loop assigns ans, index;
        loop variant n - index;
    */
    while (index < n) {
        //@ assert 0 <= index < n;
        if (h[index] >= k) {
            ans += 1;
        }
        index += 1;
    }
    return ans;
}
