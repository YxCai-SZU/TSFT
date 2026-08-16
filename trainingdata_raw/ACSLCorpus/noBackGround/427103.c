#include <stddef.h>
#include <stdbool.h>

/*@ requires \valid_read(A + (0..len-1));
    requires len >= 0;
    requires \forall integer k; 0 <= k < len ==> ((A[k]) > 0 || (A[k]) == 0);
    assigns \nothing;
    ensures \result <= len;
    ensures \result >= 0;
*/
size_t count_positives(const int *A, size_t len) {
    size_t count = 0;
    size_t i = 0;
    
    /*@ loop invariant ((i) <= (len) && (count) <= (i));
        loop invariant i <= len;
        loop invariant count <= i;
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert i < len;
        if (A[i] > 0) {
            count += 1;
        }
        i += 1;
    }
    
    //@ assert count <= len;
    //@ assert count >= 0;
    return count;
}
