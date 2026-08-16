#include <stddef.h>
#include <stdbool.h>

/*@
    predicate valid_array(int *arr, size_t n) =
        n > 0 && n <= 20 &&
        \valid(arr + (0 .. n-1)) &&
        \forall size_t i; 0 <= i < n ==> 1 <= arr[i] <= 100;

    predicate max_bounds(integer n, integer max_val) =
        max_val >= 0 && max_val <= n - 1;
*/

/*@
    requires valid_array(h, n);
    ensures max_bounds(n, \result);
    assigns \nothing;
*/
int func(size_t n, int *h) {
    int max = 0;
    int step = 0;
    size_t i = 1;
    
    /*@
        loop invariant 1 <= i <= n;
        loop invariant 0 <= step <= i - 1;
        loop invariant 0 <= max <= i - 1;
        loop assigns max, step, i;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert valid_array(h, n);
        
        if (h[i] <= h[i - 1]) {
            step += 1;
            if (i == n - 1) {
                if (max < step) {
                    max = step;
                }
            }
        } else {
            if (max < step) {
                max = step;
            }
            step = 0;
        }
        i += 1;
    }
    
    //@ assert max_bounds(n, max);
    return max;
}

/*@
    lemma max_non_negative:
        \forall size_t n; n > 0 ==> \forall int max; max_bounds(n, max) ==> max >= 0;
*/
