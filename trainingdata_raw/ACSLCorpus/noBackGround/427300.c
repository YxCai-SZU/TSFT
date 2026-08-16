#include <limits.h>

/*@
    requires (INT_MIN <= (a) <= INT_MAX);
    requires (INT_MIN <= (b) <= INT_MAX);
    ensures \result >= a && \result >= b;
    ensures \result <= a || \result <= b;
    assigns \nothing;
*/
int maximum_int(int a, int b)
{
    int ret;

    //@ assert (INT_MIN <= (a) <= INT_MAX);
    //@ assert (INT_MIN <= (b) <= INT_MAX);

    if (a > b)
    {
        //@ assert a >= a && a >= b;
        //@ assert a <= a || a <= b;
        ret = a;
    }
    else
    {
        //@ assert b >= a && b >= b;
        //@ assert b <= a || b <= b;
        ret = b;
    }

    //@ assert ret >= a && ret >= b;
    //@ assert ret <= a || ret <= b;
    return ret;
}
