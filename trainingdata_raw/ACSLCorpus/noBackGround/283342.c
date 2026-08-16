#include <stdbool.h>

/*@
    requires \valid(a + (0..3));
    requires \valid(b + (0..3));
    ensures \result == (a[0] == b[0] && a[1] == b[1] && a[2] == b[2] && a[3] == b[3]);
    assigns \nothing;
*/
bool func(int *a, int *b)
{
    bool result;

    if (a[0] != b[0])
    {
        //@ assert !((a)[(0)] == (b)[(0)]);
        return false;
    }
    //@ assert ((a)[(0)] == (b)[(0)]);

    if (a[1] != b[1])
    {
        //@ assert !((a)[(1)] == (b)[(1)]);
        return false;
    }
    //@ assert ((a)[(1)] == (b)[(1)]);

    if (a[2] != b[2])
    {
        //@ assert !((a)[(2)] == (b)[(2)]);
        return false;
    }
    //@ assert ((a)[(2)] == (b)[(2)]);

    if (a[3] != b[3])
    {
        //@ assert !((a)[(3)] == (b)[(3)]);
        return false;
    }
    //@ assert ((a)[(3)] == (b)[(3)]);

    //@ assert (\forall integer i; 0 <= i < (4) ==> (a)[i] == (b)[i]);
    return true;
}
