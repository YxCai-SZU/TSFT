#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid(A+(0..4));
    requires (\exists integer j; 0 <= j < (5) && (A)[j] == 0);
    ensures 1 <= \result <= 5;
    ensures A[\result-1] == 0;
    assigns \nothing;
*/
unsigned long func(unsigned long *A) {
    size_t i = 0;
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant (\forall integer k; 0 <= k < (i) ==> (A)[k] != 0);
        loop assigns i;
        loop variant 5-i;
    */
    while (i < 5) {
        //@ assert 0 <= i < 5;
        if (A[i] == 0) {
            //@ assert A[i] == 0;
            return (unsigned long)(i + 1);
        }
        //@ assert A[i] != 0;
        i += 1;
    }
    //@ assert i == 5;
    return 0;
}
