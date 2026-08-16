#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((n) > 0 && (n) <= 100 &&
        \forall integer i; 0 <= i < (n) ==> ((a)[i] == 1 || (a)[i] == 2 || (a)[i] == 3));
    ensures \result <= n;
    assigns \nothing;
*/
size_t func(size_t n, int *a) {
    size_t count = 0;
    size_t index = 0;
    
    /*@
        loop invariant index <= n;
        loop invariant count <= index;
        loop invariant ((n) > 0 && (n) <= 100 &&
        \forall integer i; 0 <= i < (n) ==> ((a)[i] == 1 || (a)[i] == 2 || (a)[i] == 3));
        loop assigns index, count;
    */
    while (index < n) {
        //@ assert index < n;
        if (index % 2 == 0 && (a[index] & 1) == 1) {
            count += 1;
        }
        index += 1;
    }
    return count;
}
