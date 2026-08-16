#include <stdbool.h>

/*@
    requires (-40 <= (k) <= 40);
    ensures ((\result) == ((k) >= 30));
    assigns \nothing;
*/
bool func(int k)
{
    bool result;
    
    //@ assert (-40 <= (k) <= 40);
    
    if (k < -40 || k > 40) {
        //@ assert k < -40 || k > 40;
        result = false;
    } else {
        if (k >= 30) {
            //@ assert k >= 30;
            result = true;
        } else {
            //@ assert k < 30;
            result = false;
        }
    }
    
    //@ assert ((result) == ((k) >= 30));
    return result;
}
