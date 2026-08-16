#include <limits.h>

/*@
    requires INT_MIN <= a <= INT_MAX;
    requires INT_MIN <= b <= INT_MAX;
    requires INT_MIN <= c <= INT_MAX;
    ensures \result == a || \result == b || \result == c;
    ensures \result <= a && \result <= b && \result <= c;
    ensures (((\result) == (a) || (\result) == (b) || (\result) == (c)) &&
        ((\result) <= (a) && (\result) <= (b) && (\result) <= (c)));
*/
int min_numbers(int a, int b, int c)
{
    int ret;
    //@ assert INT_MIN <= a <= INT_MAX;
    //@ assert INT_MIN <= b <= INT_MAX;
    //@ assert INT_MIN <= c <= INT_MAX;
    
    if (a <= b && a <= c)
    {
        //@ assert a <= b && a <= c;
        ret = a;
    }
    else if (b <= a && b <= c)
    {
        //@ assert b <= a && b <= c;
        ret = b;
    }
    else
    {
        //@ assert c <= a && c <= b;
        ret = c;
    }
    
    //@ assert (((ret) == (a) || (ret) == (b) || (ret) == (c)) &&         ((ret) <= (a) && (ret) <= (b) && (ret) <= (c)));
    return ret;
}
