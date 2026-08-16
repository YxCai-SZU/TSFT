#include <stdbool.h>

/*@
    requires (-40 <= (x) && (x) <= 40);
    ensures ((\result) == ((x) >= 30));
    assigns \nothing;
*/
bool func(int x)
{
    int r;
    
    //@ assert x >= -40 && x <= 40;
    //@ assert x - 30 >= -70 && x - 30 <= 10;
    
    r = x - 30;
    
    if (r >= 0) {
        return true;
    } else {
        return false;
    }
}
