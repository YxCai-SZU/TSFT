#include <stdbool.h>

/*@
    requires (1 <= (d) <= 10000 &&
        1 <= (t) <= 10000 &&
        1 <= (s) <= 10000 &&
        (d) >= 0 &&
        (t) >= 0 &&
        (s) >= 0);
    ensures \result == true <==> d <= t * s;
    assigns \nothing;
*/
bool func(long d, long t, long s)
{
    // Variable declarations at scope top
    bool result;

    //@ assert 1 <= t <= 10000;
    //@ assert 1 <= s <= 10000;
    //@ assert t * s <= 10000 * 10000;

    //@ assert 1 <= d <= 10000;
    //@ assert d <= 10000 * 10000;

    result = (d <= t * s);
    return result;
}
