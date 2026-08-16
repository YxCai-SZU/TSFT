#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid(x + (0..4));
    requires ((((x))[(0)] == 0) ||
        (((x))[(1)] == 0) ||
        (((x))[(2)] == 0) ||
        (((x))[(3)] == 0) ||
        (((x))[(4)] == 0));
    ensures \result >= 1 && \result <= 5 || \result == -1;
    ensures \result == 1 ==> ((x)[(0)] == 0);
    ensures \result == 2 ==> ((x)[(1)] == 0);
    ensures \result == 3 ==> ((x)[(2)] == 0);
    ensures \result == 4 ==> ((x)[(3)] == 0);
    ensures \result == 5 ==> ((x)[(4)] == 0);
*/
int func(unsigned int *x) {
    size_t index = 0;
    
    /*@
        loop invariant 0 <= index <= 5;
        loop invariant (\forall integer k; 0 <= k < (index) ==> (x)[k] != 0);
        loop assigns index;
    */
    while (index < 5) {
        //@ assert index >= 0 && index < 5;
        if (x[index] == 0) {
            //@ assert ((x)[(index)] == 0);
            return (int)(index + 1);
        }
        //@ assert x[index] != 0;
        index++;
    }
    return -1;
}
