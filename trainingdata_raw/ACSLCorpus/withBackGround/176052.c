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
    assigns \nothing;
*/
bool func(long d, long t, long s)
{
    // Variable declarations at scope top
    bool result;

    //@ assert 1 <= d && d <= 10000;
    //@ assert 1 <= t && t <= 10000;
    //@ assert 1 <= s && s <= 10000;
    //@ assert t * s <= 10000 * 10000;

    result = d <= t * s;
    //@ assert result == true;
    return result;
}
