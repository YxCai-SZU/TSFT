#include <stddef.h>
#include <stdbool.h>

/*@
    predicate valid_params(integer n, integer k, int *a) =
        2 <= n <= 200000 &&
        1 <= k <= n - 1 &&
        \valid(a + (0 .. n-1)) &&
        \forall integer j; 0 <= j < n ==> 0 <= a[j] <= 1000000000;

    lemma params_positive: \forall integer n, k, int *a; valid_params(n, k, a) ==> n >= 2 && k >= 1;
*/

/*@
    requires valid_params(n, k, a);
    ensures \result >= 0;
    assigns \nothing;
*/
int func(size_t n, size_t k, const int *a) {
    int min = 1000000001;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= k;
        loop invariant min >= 0;
        loop assigns i, min;
        loop variant k - i;
    */
    while (i < k) {
        size_t l = (n - k + i < n) ? (n - k + i) : (n - 1);
        //@ assert 0 <= l < n;
        
        int diff = (a[0] > a[l]) ? (a[0] - a[l]) : (a[l] - a[0]);
        //@ assert diff >= 0;
        
        if (diff < min) {
            min = diff;
        }
        
        i += 1;
    }
    
    return min;
}
