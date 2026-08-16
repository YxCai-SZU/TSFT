#include <stdbool.h>

/*@
    requires (-40 <= (X) && (X) <= 40);
    ensures \result == (X >= 30);
    assigns \nothing;
*/
bool func(int X)
{
    bool result;
    //@ assert X >= 30 ==> X >= 30;
    result = (X >= 30);
    return result;
}
