#include <stdbool.h>

/*@
    requires (-40 <= (X) && (X) <= 40);
    ensures (((X) >= 30 ==> (\result) == true) &&
        ((X) < 30 ==> (\result) == false));
    assigns \nothing;
*/
bool func(int X)
{
    bool result;
    //@ assert X >= -40 && X <= 40;
    
    if (X >= 30)
    {
        //@ assert X >= 30;
        result = true;
    }
    else
    {
        //@ assert X < 30;
        result = false;
    }
    
    return result;
}
