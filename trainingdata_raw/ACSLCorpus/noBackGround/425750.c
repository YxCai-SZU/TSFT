#include <stdbool.h>

/*@
    requires (-40 <= (n) && (n) <= 40);
    ensures \result == (n >= 30);
    assigns \nothing;
*/
bool func(int n)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert (-40 <= (n) && (n) <= 40);
    
    result = (n >= 30);
    
    return result;
}
