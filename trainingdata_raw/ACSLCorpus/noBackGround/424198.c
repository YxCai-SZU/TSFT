#include <limits.h>

/*@
    requires (INT_MIN <= (a) <= INT_MAX);
    requires (INT_MIN <= (b) <= INT_MAX);
    ensures \result == ((a) >= (b) ? (a) : (b));
    ensures (INT_MIN <= (\result) <= INT_MAX);
*/
int maximum_int(int a, int b)
{
    int ret;
    //@ assert (INT_MIN <= (a) <= INT_MAX);
    //@ assert (INT_MIN <= (b) <= INT_MAX);
    
    if (a > b)
    {
        //@ assert a >= b;
        ret = a;
    }
    else
    {
        //@ assert b >= a;
        ret = b;
    }
    
    //@ assert ret == ((a) >= (b) ? (a) : (b));
    //@ assert (INT_MIN <= (ret) <= INT_MAX);
    return ret;
}
