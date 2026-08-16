#include <stdbool.h>

/*@
    requires (-40 <= (x) <= 40);
    ensures \result == (x >= 30);
    assigns \nothing;
*/
bool func(int x)
{
    //@ assert (-40 <= (x) <= 40);
    return x >= 30;
}
