#include <stddef.h>
#include <stdbool.h>

/*@
    requires \valid_read(A + (0..len-1));
    assigns \nothing;
    ensures 0 <= \result <= len;
*/
size_t count_positives(const int *A, size_t len) {
    size_t count = 0;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= len;
        loop invariant 0 <= count <= i;
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert ((i) <= (len) && (count) <= (i));
        if (A[i] > 0) {
            count += 1;
        }
        i += 1;
    }

    //@ assert 0 <= count <= len;
    return count;
}
