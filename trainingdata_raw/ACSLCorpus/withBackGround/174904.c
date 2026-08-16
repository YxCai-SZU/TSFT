#include <stddef.h>

/*@
    predicate positive_array(size_t *arr, integer len) =
        \forall integer i; 0 <= i < len ==> arr[i] > 0;
*/

/*@
    requires n > 0;
    requires \valid(h + (0 .. n-1));
    requires positive_array(h, n);
    ensures 0 <= \result < n;
    assigns \nothing;
*/
size_t func(size_t n, const size_t h[]) {
    size_t max = 0;
    size_t cur = 0;
    size_t i = 1;
    
    /*@
        loop invariant 1 <= i <= n;
        loop invariant 0 <= cur <= i - 1;
        loop invariant 0 <= max <= i - 1;
        loop invariant positive_array(h, n);
        loop assigns i, cur, max;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        
        if (h[i] <= h[i - 1]) {
            cur += 1;
        } else {
            cur = 0;
        }
        
        if (cur > max) {
            max = cur;
        }
        
        i += 1;
    }
    
    //@ assert max < n;
    return max;
}
