#include <stdbool.h>

/*@
    requires (-40 <= (x) && (x) <= 40) && ((x) == (int)(x));
    ensures \result == (x >= 30);
    assigns \nothing;
*/
bool func(int x)
{
    bool result;
    //@ assert (-40 <= (x) && (x) <= 40) && ((x) == (int)(x));
    
    if (x >= 30) {
        //@ assert x >= 30;
        result = true;
    } else {
        //@ assert x < 30;
        result = false;
    }
    
    //@ assert result == (x >= 30);
    return result;
}
