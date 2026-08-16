#include <stdbool.h>

/*@
    requires (-40 <= (x) <= 40);
    ensures ((\result) == ((x) >= 30));
    assigns \nothing;
 */
bool func(int x)
{
    bool result = false;
    //@ assert (-40 <= (x) <= 40);
    if (x >= 30) {
        result = true;
    }
    //@ assert ((result) == ((x) >= 30));
    return result;
}
