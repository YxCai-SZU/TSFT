#include <limits.h>

/*@
    requires (-1000 <= (x) <= 1000);
    ensures (x >= 0 ==> \result == x) && (x < 0 ==> \result == -x);
    assigns \nothing;
*/
int func(int x)
{
    int result;
    
    //@ assert (-1000 <= (x) <= 1000);
    
    if (x < 0)
    {
        //@ assert x < 0;
        //@ assert -x >= 0;
        //@ assert -x <= 1000;
        result = -x;
    }
    else
    {
        //@ assert x >= 0;
        result = x;
    }
    
    //@ assert (x >= 0 ==> result == x) && (x < 0 ==> result == -x);
    return result;
}
