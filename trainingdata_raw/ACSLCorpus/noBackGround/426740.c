#include <stdbool.h>

/*@
    requires (-40 <= (t) <= 40);
    ensures \result == (t >= 30);
    assigns \nothing;
*/
bool func(int t)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert -40 <= t <= 40;
    result = (t >= 30);
    //@ assert result == (t >= 30);
    return result;
}
