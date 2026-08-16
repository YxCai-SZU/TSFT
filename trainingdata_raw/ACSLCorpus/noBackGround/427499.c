#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((n) >= 1 && (n) <= 100000 &&
        (k) >= 1 && (k) <= 500 &&
        \valid((h) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> (h)[i] >= 1 && (h)[i] <= 500);
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
int func(int n, int k, int *h) {
    int count = 0;
    size_t index = 0;
    
    /*@
        loop invariant (0 <= (index) <= (n) &&
        (count) >= 0 &&
        (count) <= (index) &&
        (index) <= (n) &&
        (((n)) >= 1 && ((n)) <= 100000 &&
        ((k)) >= 1 && ((k)) <= 500 &&
        \valid(((h)) + (0 .. ((n))-1)) &&
        \forall integer i; 0 <= i < ((n)) ==> ((h))[i] >= 1 && ((h))[i] <= 500) &&
        \forall integer i; 0 <= i < (index) ==> 
            ((k) <= (h)[i] ==> (count) >= 1) &&
            ((k) > (h)[i] ==> (count) >= 0) &&
        (count) <= (n));
        loop assigns count, index;
        loop variant n - index;
    */
    while ((size_t)index < (size_t)n) {
        //@ assert count <= n;
        if (k <= h[index]) {
            count += 1;
        }
        index += 1;
    }
    
    //@ assert count <= n;
    return count;
}
