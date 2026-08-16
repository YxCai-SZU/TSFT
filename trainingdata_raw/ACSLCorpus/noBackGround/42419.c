#include <limits.h>

/*@
    requires a >= INT_MIN && a <= INT_MAX;
    requires b >= INT_MIN && b <= INT_MAX;
    ensures ((\result) == (a) || (\result) == (b));
    ensures ((\result) >= (a));
    ensures ((\result) >= (b));
*/
int max(int a, int b)
{
    int result;
    //@ assert a >= INT_MIN && a <= INT_MAX;
    //@ assert b >= INT_MIN && b <= INT_MAX;
    
    if (a > b)
    {
        //@ assert a >= b;
        result = a;
    }
    else
    {
        //@ assert b >= a;
        result = b;
    }
    
    //@ assert ((result) == (a) || (result) == (b));
    //@ assert ((result) >= (a));
    //@ assert ((result) >= (b));
    return result;
}
