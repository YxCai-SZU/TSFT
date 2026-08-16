#include <stdbool.h>

/*@
    requires \valid(A+(0..len-1));
    requires len > 0;
    assigns \nothing;
    ensures \result == true ==> (A[0] & 1) == 0;
*/
bool all_even(int *A, int len) {
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant len > 0;
        loop invariant (\forall integer j; 0 <= j < (i) ==> ((A)[j] & 1) == 0);
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if ((A[i] & 1) != 0) {
            return false;
        }
        i++;
    }
    
    return true;
}
