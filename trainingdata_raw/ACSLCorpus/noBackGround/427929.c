#include <stdbool.h>

/*@
    requires (-40 <= (x) <= 40);
    ensures \result == true <==> ((x) >= 30);
    assigns \nothing;
*/
bool func(int x)
{
    bool result;

    //@ assert (-40 <= (x) <= 40);
    
    if (x < 30)
    {
        //@ assert -40 <= x < 30;
        result = false;
    }
    else
    {
        //@ assert 30 <= x <= 40;
        result = true;
    }
    
    return result;
}
