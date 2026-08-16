#include <stddef.h>
#include <stdbool.h>

/*@
    requires ((n) > 0 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> (a)[i] > 0 && (a)[i] <= 100);
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
size_t func(size_t n, int *a) {
    size_t count = 0;
    size_t index = 0;
    
    /*@
        loop invariant 0 <= index <= n;
        loop invariant 0 <= count <= index;
        loop assigns index, count;
        loop variant n - index;
    */
    while (index < n) {
        int i = a[index];
        if ((i % 2 == 1) && (index % 2 == 0)) {
            count += 1;
        }
        index += 1;
    }
    return count;
}
