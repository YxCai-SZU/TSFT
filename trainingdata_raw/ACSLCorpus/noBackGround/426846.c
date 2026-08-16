#include <stdbool.h>

/*@
    requires \valid(xs + (0 .. 4));
    requires ((5) == 5 &&
        \forall integer i; 0 <= i < (5) ==> (1 <= (xs)[i] && (xs)[i] <= 5) &&
        \exists integer i; 0 <= i < (5) && (xs)[i] == 0);
    ensures 1 <= \result && \result <= 5;
    ensures \exists integer i; 0 <= i < 5 && (xs[i] == \result || xs[i] == 0);
*/
int func(int *xs)
{
    int i;
    i = 0;
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant ((5) == 5 &&
        \forall integer i; 0 <= i < (5) ==> (1 <= (xs)[i] && (xs)[i] <= 5) &&
        \exists integer i; 0 <= i < (5) && (xs)[i] == 0);
        loop assigns i;
    */
    while (i < 5)
    {
        //@ assert 0 <= i < 5;
        if (xs[i] == 0)
        {
            //@ assert xs[i] == 0;
            //@ assert \exists integer j; 0 <= j < 5 && (xs[j] == (i + 1) || xs[j] == 0);
            return i + 1;
        }
        i = i + 1;
    }
    //@ assert i == 5;
    //@ assert \exists integer j; 0 <= j < 5 && xs[j] == 0;
    return 0;
}
