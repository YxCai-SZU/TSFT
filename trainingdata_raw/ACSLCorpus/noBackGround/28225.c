#include <stdbool.h>

/*@
    requires \valid(v + (0..4));
    requires v[0] == 0 || v[1] == 0 || v[2] == 0 || v[3] == 0 || v[4] == 0;
    ensures 1 <= \result <= 5;
    ensures v[\result - 1] == 0;
    assigns \nothing;
*/
long func(long v[5])
{
    int i = 0;
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant (\exists integer j; 0 <= j < (5) && (v)[j] == 0);
        loop invariant (\forall integer k; 0 <= k < (i) ==> (v)[k] != 0);
        loop assigns i;
        loop variant 5 - i;
    */
    while (i < 5)
    {
        //@ assert 0 <= i < 5;
        if (v[i] == 0)
        {
            //@ assert v[i] == 0;
            return (long)(i + 1);
        }
        //@ assert v[i] != 0;
        i++;
    }
    return -1;
}
