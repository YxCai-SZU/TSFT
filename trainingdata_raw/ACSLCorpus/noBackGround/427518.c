#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid(x + (0..4));
    requires (\exists integer i; 0 <= i < (5) && (x)[i] == 0);
    ensures 1 <= \result <= 5;
    ensures x[\result - 1] == 0;
    assigns \nothing;
*/
long func(long *x)
{
    size_t i = 0;
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant (\exists integer i; 0 <= i < (5) && (x)[i] == 0);
        loop invariant (\forall integer j; (0) <= j < (i) ==> (x)[j] != 0);
        loop assigns i;
        loop variant 5 - i;
    */
    while (i < 5)
    {
        //@ assert 0 <= i < 5;
        if (x[i] == 0)
        {
            //@ assert x[i] == 0;
            return (long)(i + 1);
        }
        //@ assert x[i] != 0;
        i += 1;
    }
    return -1;
}
