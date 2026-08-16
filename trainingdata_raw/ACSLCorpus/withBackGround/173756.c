#include <stddef.h>

/*@
    predicate exists_zero(int *v, integer len) =
        \exists integer j; 0 <= j < len && v[j] == 0;

    predicate forall_nonzero(int *v, integer i) =
        \forall integer k; 0 <= k < i ==> v[k] != 0;
*/

/*@
    requires \valid(v+(0..4));
    requires exists_zero(v, 5);
    ensures 1 <= \result <= 5;
    ensures v[\result-1] == 0;
    assigns \nothing;
*/
int func(int *v) {
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant \valid(v+(0..4));
        loop invariant exists_zero(v, 5);
        loop invariant forall_nonzero(v, i);
        loop assigns i;
        loop variant 5-i;
    */
    while (i < 5) {
        //@ assert 0 <= i < 5;
        if (v[i] == 0) {
            //@ assert v[i] == 0;
            return (int)(i + 1);
        }
        //@ assert v[i] != 0;
        i++;
    }
    return -1;
}
