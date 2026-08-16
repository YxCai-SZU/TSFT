#include <stdbool.h>

/*@
    requires (\valid((v)) && \valid((v)+1) && \valid((v)+2));
    requires ((((v))[(0)] == 1) || (((v))[(1)] == 1) || (((v))[(2)] == 1));
    ensures \result >= 1 && \result <= 3;
    ensures ((v)[(\result - 1)] == 1);
*/
int func(int *v)
{
    int index;
    index = 0;

    /*@
        loop invariant 0 <= index <= 3;
        loop invariant (\valid((v)) && \valid((v)+1) && \valid((v)+2));
        loop invariant ((((v))[(0)] == 1) || (((v))[(1)] == 1) || (((v))[(2)] == 1));
        loop invariant (\forall integer k; 0 <= k < (index) ==> !(((v))[(k)] == 1));
        loop assigns index;
    */
    while (index < 3)
    {
        //@ assert 0 <= index < 3;
        if (v[index] == 1)
        {
            //@ assert ((v)[(index)] == 1);
            return index + 1;
        }
        //@ assert !((v)[(index)] == 1);
        index = index + 1;
    }
    return -1;
}
