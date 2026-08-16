#include <stdbool.h>

/*@
    requires (-40 <= (x) && (x) <= 40);
    ensures (30 <= (x) && (x) <= 40) ==> \result == true;
    ensures ((x) < 30 || (x) > 40) ==> \result == false;
    assigns \nothing;
*/
bool func(int x)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert (-40 <= (x) && (x) <= 40);
    
    if (x >= 30 && x <= 40)
    {
        //@ assert (30 <= (x) && (x) <= 40);
        result = true;
    }
    else
    {
        //@ assert ((x) < 30 || (x) > 40);
        result = false;
    }
    
    return result;
}
