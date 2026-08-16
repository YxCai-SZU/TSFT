#include <stdbool.h>

/*@
    requires -1000 <= a <= 1000;
    ensures \result == (a >= 0);
    assigns \nothing;
*/
bool func(long a)
{
    bool result;
    
    //@ assert -1000 <= a <= 1000;
    
    if (a >= 0)
    {
        //@ assert a >= 0;
        result = true;
    }
    else
    {
        //@ assert a < 0;
        result = false;
    }
    
    return result;
}
