#include <stdbool.h>

/*@
    requires (-40 <= (x) <= 40);
    ensures \result == (x >= 30);
    assigns \nothing;
*/
bool func(int x)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert -40 <= x <= 40;
    //@ assert x >= 30 || x < 30;

    if (x >= 30) {
        result = true;
    } else {
        result = false;
    }

    //@ assert result == (x >= 30);
    return result;
}
