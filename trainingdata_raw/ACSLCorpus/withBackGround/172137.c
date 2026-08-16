#include <stdbool.h>

/*@
    predicate exists_zero(long long *x, integer len) =
        \exists integer j; 0 <= j < len && x[j] == 0;

    predicate forall_nonzero(long long *x, integer start, integer end) =
        \forall integer k; start <= k < end ==> x[k] != 0;
*/

/*@
    requires \valid(x+(0..4));
    requires exists_zero(x, 5);
    ensures 1 <= \result <= 5;
    ensures x[\result-1] == 0;
    assigns \nothing;
*/
int func(long long *x) {
    int i;
    i = 0;
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant exists_zero(x, 5);
        loop invariant forall_nonzero(x, 0, i);
        loop assigns i;
    */
    while (i < 5) {
        //@ assert 0 <= i < 5;
        if (x[i] == 0) {
            //@ assert x[i] == 0;
            return i + 1;
        }
        //@ assert x[i] != 0;
        i = i + 1;
    }
    //@ assert i == 5;
    //@ assert forall_nonzero(x, 0, 5);
    return -1;
}
