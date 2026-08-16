#include <stdbool.h>

/*@
    requires -40 <= x <= 40;
    ensures \result ==> x >= 30;
    ensures !\result ==> x < 30;
*/
bool func(int x)
{
    bool result;
    
    //@ assert -40 <= x <= 40;
    
    if (x < 30)
    {
        //@ assert x < 30;
        result = false;
    }
    else
    {
        //@ assert x >= 30;
        result = true;
    }
    
    //@ assert (result ==> x >= 30) && (!result ==> x < 30);
    return result;
}
