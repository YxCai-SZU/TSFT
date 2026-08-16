#include <stdbool.h>

/*@
    requires (-40 <= (X) <= 40);
    ensures ((\result) == ((X) >= 30));
    assigns \nothing;
*/
bool func(int X)
{
    bool result;
    
    //@ assert (-40 <= (X) <= 40);
    
    if (X < 30) {
        //@ assert X < 30;
        result = false;
    } else {
        //@ assert X >= 30;
        result = true;
    }
    
    //@ assert ((result) == ((X) >= 30));
    return result;
}
