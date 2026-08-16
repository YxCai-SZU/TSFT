#include <limits.h>

/*@
    requires INT_MIN <= a <= INT_MAX;
    requires INT_MIN <= b <= INT_MAX;
    ensures \result == a || \result == b;
    ensures \result >= a;
    ensures \result >= b;
    assigns \nothing;
*/
int maximum(int a, int b)
{
    int ret;
    //@ assert INT_MIN <= a <= INT_MAX;
    //@ assert INT_MIN <= b <= INT_MAX;
    
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
    
    //@ assert (((ret) == (a) || (ret) == (b)) &&         (ret) >= (a) &&         (ret) >= (b));
    return ret;
}
