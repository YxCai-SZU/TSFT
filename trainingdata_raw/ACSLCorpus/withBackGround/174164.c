#include <stdbool.h>

/*@
    predicate valid_inputs(integer d, integer t, integer s) =
        1 <= d <= 10000 &&
        1 <= t <= 10000 &&
        1 <= s <= 10000;

    logic integer safe_product(integer t, integer s) = t * s;
*/

/*@
    requires valid_inputs(d, t, s);
    ensures \result == true <==> d <= t * s;
    assigns \nothing;
*/
bool func(unsigned int d, unsigned int t, unsigned int s)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert t <= 10000;
    //@ assert s <= 10000;
    //@ assert d <= 10000;
    //@ assert (unsigned long long)t * (unsigned long long)s <= 10000ULL * 10000ULL;

    if (d <= t * s) {
        //@ assert d <= t * s;
        result = true;
    } else {
        //@ assert !(d <= t * s);
        result = false;
    }

    return result;
}
