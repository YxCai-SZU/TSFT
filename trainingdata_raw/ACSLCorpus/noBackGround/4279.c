#include <stdbool.h>

/*@
    requires (-40 <= (x) && (x) <= 40);
    ensures \result == (x >= 30);
    assigns \nothing;
*/
bool air_conditioner_turn_on(int x)
{
    // Variable declarations at top of scope
    bool status;

    //@ assert -40 <= x && x <= 40;
    
    status = (x >= 30);
    
    //@ assert status == (x >= 30);
    
    return status;
}

