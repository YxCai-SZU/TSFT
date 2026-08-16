#include <stdbool.h>

/*@
    predicate valid_params(integer d, integer t, integer s) =
        1 <= d <= 10000 &&
        1 <= t <= 10000 &&
        1 <= s <= 10000 &&
        d <= t * s;
*/

/*@
    requires valid_params(d, t, s);
    ensures \result == true;
*/
bool func(long d, long t, long s)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert d <= t * s;
    
    result = true;
    return result;
}
