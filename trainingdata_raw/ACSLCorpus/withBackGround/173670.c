#include <stddef.h>
#include <stdbool.h>

/*@ predicate valid_params(size_t k, size_t n, size_t *h) =
        1 <= k && k <= 500 &&
        1 <= n && n <= 100000 &&
        \valid(h + (0 .. n-1)) &&
        \forall integer i; 0 <= i < n ==> 1 <= h[i] && h[i] <= 500;
*/

/*@
    requires valid_params(k, n, h);
    ensures \result <= n;
    ensures \forall integer i; 0 <= i < n ==> (h[i] >= k ==> \result > 0);
    assigns \nothing;
*/
size_t func(size_t k, size_t n, const size_t *h) {
    size_t result = 0;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant result <= i;
        loop invariant \forall integer j; 0 <= j < i ==> (h[j] >= k ==> result > 0);
        loop assigns i, result;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if (h[i] >= k) {
            result += 1;
        }
        i += 1;
    }
    
    //@ assert result <= n;
    return result;
}
