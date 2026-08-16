#include <stdbool.h>

/*@
    predicate valid_params(integer d, integer t, integer s) =
        1 <= d <= 10000 &&
        1 <= t <= 10000 &&
        1 <= s <= 10000;
*/

/*@
    requires valid_params(d, t, s);
    ensures \result == (d <= t * s);
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    //@ assert 1 <= t <= 10000 && 1 <= s <= 10000;
    //@ assert t * s <= 10000 * 10000;
    
    if (d <= t * s)
    {
        return true;
    }
    else
    {
        return false;
    }
}
