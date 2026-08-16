#include <stdint.h>
#include <stdbool.h>

/*@
    predicate valid_array(uint64_t *a, integer n) =
        n >= 2 && n <= 100 &&
        \valid(a + (0 .. n-1)) &&
        \forall integer i; 0 <= i < n ==> a[i] >= 1 && a[i] <= 100;

    logic integer array_sum(integer n) = n * 100;

    lemma sum_bound: \forall integer n; 2 <= n <= 100 ==> 0 <= array_sum(n);
*/

/*@
    requires valid_array(a, n);
    ensures \result >= 0;
    ensures \result <= array_sum(n);
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t *a) {
    uint64_t res;
    uint64_t i;
    
    res = 0;
    i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant res >= 0;
        loop invariant res <= i * 100;
        loop invariant \forall integer k; 0 <= k < n ==> a[k] >= 1 && a[k] <= 100;
        loop invariant 2 <= n <= 100;
        loop assigns i, res;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert a[i] >= 1 && a[i] <= 100;
        res += a[i] / 2;
        i += 1;
    }
    
    return res;
}
