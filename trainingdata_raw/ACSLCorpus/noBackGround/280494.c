#include <stddef.h>
#include <stdbool.h>

/*@ requires n >= 1;
    requires 1 <= k <= 500;
    requires \valid(heights + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (heights)[i] <= 500);
    ensures \result <= n;
    ensures \forall integer i; 0 <= i < n ==> (heights[i] >= k ==> \result > 0);
*/
size_t func(size_t n, size_t k, int *heights) {
    size_t count = 0;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant count <= i;
        loop invariant (\forall integer j; 0 <= j < (i) ==> ((heights)[j] >= (k) ==> (count) > 0));
        loop invariant 1 <= n;
        loop invariant 1 <= k <= 500;
        loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (heights)[i] <= 500);
        loop assigns count, i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if (heights[i] >= (int)k) {
            count = count + 1;
        }
        i = i + 1;
    }
    return count;
}
