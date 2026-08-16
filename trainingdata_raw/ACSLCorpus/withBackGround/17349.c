#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@
    predicate valid_array(integer n, int64_t *a) =
        n >= 1 && n <= 200000 &&
        \valid(a + (0 .. n-1)) &&
        \forall integer i; 0 <= i < n ==> a[i] >= 1 && a[i] <= 1000000000;

    lemma array_bounds:
        \forall integer n, int64_t *a; valid_array(n, a) ==>
            \forall integer i; 0 <= i < n ==> a[i] >= 1 && a[i] <= 1000000000;
*/

/*@
    requires valid_array(n, a);
    ensures \result >= -1 && \result <= n;
    ensures \result == -1 ==> n == \old(n);
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t *a) {
    int64_t next = 1;
    int64_t count = 0;
    size_t index = 0;
    
    /*@
        loop invariant 0 <= index <= n;
        loop invariant 1 <= next <= index + 1;
        loop invariant 0 <= count <= index;
        loop invariant valid_array(n, a);
        loop assigns next, count, index;
        loop variant n - index;
    */
    while (index < (size_t)n) {
        int64_t i = a[index];
        //@ assert i >= 1 && i <= 1000000000;
        
        if (i == next) {
            next += 1;
        } else {
            count += 1;
        }
        index += 1;
    }
    
    //@ assert count >= 0 && count <= n;
    
    if (n == count) {
        return -1;
    } else {
        return count;
    }
}
