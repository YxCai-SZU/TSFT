#include <stdbool.h>

/*@
    requires (-40 <= (X) <= 40);
    ensures ((\result) == ((X) >= 30));
    assigns \nothing;
*/
bool func(int X)
{
    bool result;
    //@ assert -40 <= X <= 40;
    
    if (X >= 30) {
        //@ assert X >= 30;
        result = true;
    } else {
        //@ assert X < 30;
        result = false;
    }
    
    return result;
}

/*@
    requires (-40 <= (X) <= 40);
    ensures ((\result) == ((X) >= 30));
    assigns \nothing;
*/
bool func_with_when(int X)
{
    bool result;
    //@ assert -40 <= X <= 40;
    
    if (X >= 30) {
        //@ assert X >= 30;
        result = true;
    } else {
        //@ assert X < 30;
        result = false;
    }
    
    return result;
}

/*@
    requires (-40 <= (X) <= 40);
    ensures ((\result) == ((X) >= 30));
    assigns \nothing;
*/
bool func_with_assertion(int X)
{
    bool result;
    //@ assert -40 <= X <= 40;
    
    if (X >= 30) {
        //@ assert X >= 30;
        result = true;
    } else {
        //@ assert X < 30;
        result = false;
    }
    
    return result;
}
