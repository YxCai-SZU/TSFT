#include <stdbool.h>

/*@
    requires (-40 <= (t) <= 40);
    ensures \result == (t >= 30);
    assigns \nothing;
*/
bool func(int t)
{
    bool ac_on;
    
    //@ assert (-40 <= (t) <= 40);
    ac_on = (t >= 30);
    return ac_on;
}
