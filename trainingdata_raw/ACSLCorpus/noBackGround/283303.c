#include <stddef.h>
#include <stdbool.h>

/*@
    requires n > 0;
    requires \valid(h + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> h[i] > 0;
    ensures \result >= 0 && \result < n;
    assigns \nothing;
*/
size_t func(size_t n, unsigned long *h) {
    size_t max = 0;
    size_t index = 0;
    
    /*@
        loop invariant 0 <= index <= n - 1;
        loop invariant 0 <= max < n;
        loop invariant \valid(h + (0 .. n-1));
        loop invariant \forall integer i; 0 <= i < n ==> h[i] > 0;
        loop assigns index, max;
        loop variant n - index;
    */
    while (index < n - 1) {
        size_t count = 0;
        size_t i = index;
        
        /*@
            loop invariant index <= i <= n - 1;
            loop invariant 0 <= count <= i - index;
            loop invariant \valid(h + (0 .. n-1));
            loop invariant \forall integer j; 0 <= j < n ==> h[j] > 0;
            loop assigns i, count;
            loop variant n - i;
        */
        while (i < n - 1) {
            //@ assert i < n - 1 && i + 1 < n;
            if (h[i] >= h[i + 1]) {
                count += 1;
            } else {
                break;
            }
            i += 1;
        }
        
        if (count > max) {
            max = count;
        }
        index += 1;
    }
    
    //@ assert ((max) >= 0 && (max) < (n));
    return max;
}

