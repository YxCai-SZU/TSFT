#include <stdbool.h>
#include <stddef.h>

/*@ requires (1 <= (n) && (n) <= 100000 &&
       1 <= (k) && (k) <= 500 &&
       \valid((h) + (0 .. (n)-1)) &&
       \forall integer i; 0 <= i < (n) ==> 1 <= (h)[i] && (h)[i] <= 500);
    assigns \nothing;
    ensures 0 <= \result && \result <= n;
*/
long func(long n, long k, long *h) {
    long count = 0;
    size_t index = 0;
    
    /*@ loop invariant (0 <= (index) && (index) <= (size_t)(n) &&
       0 <= (count) && (count) <= (index) &&
       \forall integer i; 0 <= i < (index) ==> 1 <= (h)[i] && (h)[i] <= 500);
        loop assigns count, index;
        loop variant n - (long)index;
    */
    while (index < (size_t)n) {
        //@ assert 0 <= index && index < (size_t)n;
        if (k <= h[index]) {
            count = count + 1;
        }
        
        index = index + 1;
    }
    
    return count;
}
