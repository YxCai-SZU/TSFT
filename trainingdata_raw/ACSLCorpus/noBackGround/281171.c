#include <stdbool.h>

/*@
    requires (-40 <= (X) && (X) <= 40);
    ensures \result == (X >= 30);
    assigns \nothing;
*/
bool func(int X)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert -40 <= X && X <= 40;
    
    result = (X >= 30);
    
    //@ assert result == (X >= 30);
    
    return result;
}
