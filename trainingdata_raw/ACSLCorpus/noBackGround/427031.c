#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid(x + (0..2)) && \valid(y + (0..2));
    requires ((3) == 3 &&
        \forall integer i; 0 <= i < (3) ==> ((x)[i] == 0 || (x)[i] == 1));
    requires ((3) == 3 &&
        \forall integer i; 0 <= i < (3) ==> ((y)[i] == 0 || (y)[i] == 1));
    ensures \result >= 0 && \result <= 3;
    assigns \nothing;
*/
int func(int *x, int *y) {
    int ret = 0;
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= 3;
        loop invariant 0 <= ret <= i;
        loop assigns i, ret;
        loop variant 3 - i;
    */
    while (i < 3) {
        //@ assert 0 <= i < 3;
        if (x[i] == y[i]) {
            ret = ret + 1;
        }
        i = i + 1;
    }
    //@ assert i == 3;
    //@ assert 0 <= ret <= 3;
    return ret;
}
