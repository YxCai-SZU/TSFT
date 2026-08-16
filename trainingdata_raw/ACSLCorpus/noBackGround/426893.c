#include <stddef.h>

/*@
    requires \valid(v + (0 .. 4));
    requires (\exists integer j; (0 <= j < (5)) && ((v)[j] == 0));
    assigns \nothing;
    ensures 1 <= \result <= 5;
    ensures v[\result - 1] == 0;
*/
long func(long *v) {
    size_t i = 0;
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant (\exists integer j; (0 <= j < (5)) && ((v)[j] == 0));
        loop invariant (\forall integer k; (0 <= k < (i)) ==> ((v)[k] != 0));
        loop assigns i;
        loop variant 5 - i;
    */
    while (i < 5) {
        //@ assert i < 5;
        if (v[i] == 0) {
            //@ assert v[i] == 0;
            //@ assert ((0 <= (i) < (5)) && ((v)[(i)] == 0));
            return (long)(i + 1);
        }
        //@ assert v[i] != 0;
        i++;
    }
    //@ assert i == 5;
    //@ assert (\forall integer k; (0 <= k < (5)) ==> ((v)[k] != 0));
    //@ assert !(\exists integer j; (0 <= j < (5)) && ((v)[j] == 0));
    return -1;
}
