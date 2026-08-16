#include <stdbool.h>

/*@
    requires (-40 <= (input) <= 40);
    ensures ((\result) == ((input) >= 30));
    assigns \nothing;
*/
bool func(int input)
{
    bool result;
    
    //@ assert (-40 <= (input) <= 40);
    
    if (input < 30) {
        //@ assert input < 30;
        result = false;
    } else {
        //@ assert input >= 30;
        result = true;
    }
    
    //@ assert ((result) == ((input) >= 30));
    return result;
}
