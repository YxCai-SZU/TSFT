#include <stddef.h>
#include <stdbool.h>

/*@
    predicate valid_params(integer n, integer k, size_t *h) =
        1 <= n <= 100000 &&
        1 <= k <= 500 &&
        \valid(h + (0 .. n-1)) &&
        \forall integer j; 0 <= j < n ==> 1 <= h[j] <= 500;
*/

/*@
    requires valid_params(n, k, h);
    ensures \result <= n;
    ensures \forall integer i; 0 <= i < n ==> (h[i] >= k ==> \result >= 1);
    ensures \forall integer i; 0 <= i < n ==> (h[i] < k ==> \result <= n - 1);
*/
size_t func(size_t n, size_t k, const size_t *h) {
    size_t ans = 0;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant ans <= i;
        loop invariant \forall integer j; 0 <= j < i ==> (h[j] >= k ==> ans >= 1);
        loop invariant \forall integer j; 0 <= j < i ==> (h[j] < k ==> ans <= i - 1);
        loop assigns i, ans;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if (h[i] >= k) {
            ans += 1;
        }
        i += 1;
    }
    return ans;
}
