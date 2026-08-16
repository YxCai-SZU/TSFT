#include <stdbool.h>

/*@
    requires -40 <= x <= 40;
    ensures \result == true <==> ((x) >= 30);
    assigns \nothing;
*/
bool func(int x)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert x >= -40;
    //@ assert x <= 40;

    if (x >= 30)
    {
        //@ assert ((x) >= 30);
        result = true;
    }
    else
    {
        //@ assert !((x) >= 30);
        result = false;
    }

    return result;
}
