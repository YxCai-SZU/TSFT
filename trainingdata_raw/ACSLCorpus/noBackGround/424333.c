#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@ requires ((n) >= 2 && (n) <= 200000 &&
    \valid((a) + (0 .. (n)-2)) &&
    \forall integer i; 0 <= i < (n)-1 ==> (a)[i] >= 1 && (a)[i] <= 200000);
    ensures \result >= 0 && \result <= n;
*/
int64_t func(int64_t n, int64_t *a) {
    int64_t count = 0;
    int64_t i = 0;
    
    /*@ loop invariant (0 <= (i) <= (n)-1 &&
    0 <= (count) <= (i) &&
    (((n)) >= 2 && ((n)) <= 200000 &&
    \valid(((a)) + (0 .. ((n))-2)) &&
    \forall integer i; 0 <= i < ((n))-1 ==> ((a))[i] >= 1 && ((a))[i] <= 200000));
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < n - 1) {
        size_t index = (size_t)i;
        //@ assert 0 <= index < n-1;
        
        if (a[index] - 1 == i) {
            count += 1;
        }
        i += 1;
    }
    
    //@ assert count >= 0 && count <= n;
    return count;
}
