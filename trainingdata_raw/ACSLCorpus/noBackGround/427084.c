#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((n) > 0 && (n) <= 100 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 100);
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
int func(size_t n, int *a) {
    int count = 0;
    size_t index = 0;
    
    /*@
        loop invariant 0 <= index <= n;
        loop invariant 0 <= count <= index;
        loop invariant \valid(a + (0 .. n-1));
        loop assigns count, index;
        loop variant n - index;
    */
    while (index < n) {
        if (index + 1 < n && (int)(index + 1) < count) {
            count = (int)(index + 1);
        }
        
        if (a[index] == count) {
            count += 1;
        }
        
        index += 1;
    }
    
    return count;
}
