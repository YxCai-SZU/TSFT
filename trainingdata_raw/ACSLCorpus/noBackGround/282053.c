#include <stdbool.h>

/*@
    requires -40 <= input && input <= 40;
    ensures \result ==> ((input) >= 30);
    ensures !\result ==> ((input) < 30);
*/
bool func(int input)
{
    bool result;
    
    if (input >= 30)
    {
        result = true;
        //@ assert ((input) >= 30);
    }
    else
    {
        //@ assert ((input) < 30);
        result = false;
    }
    
    return result;
}
