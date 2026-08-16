#include <stdbool.h>

/*@
    requires (-40 <= (n) <= 40);
    ensures \result ==> ((n) >= 30);
    ensures !\result ==> ((n) < 30);
*/
bool func(int n)
{
    bool result;
    
    //@ assert (-40 <= (n) <= 40);
    
    if (n >= 30) {
        result = true;
        //@ assert ((n) >= 30);
    } else {
        //@ assert ((n) < 30);
        result = false;
    }
    
    return result;
}
