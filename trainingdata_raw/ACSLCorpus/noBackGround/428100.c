#include <stdbool.h>

/*@
    requires (-40 <= (x) <= 40);
    ensures ((\result) == ((x) >= 30));
    assigns \nothing;
*/
bool func(int x)
{
    bool result;
    
    //@ assert -40 <= x <= 40;
    result = (x >= 30);
    
    //@ assert result == (x >= 30);
    return result;
}
