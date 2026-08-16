#include <stdbool.h>

/*@
    requires (1 <= (d) <= 10000 &&
        1 <= (t) <= 10000 &&
        1 <= (s) <= 10000);
    ensures \result == (d <= t * s);
    assigns \nothing;
*/
bool func(long d, long t, long s)
{
    // Variable declarations at scope top
    bool result;

    //@ assert t > 0 && s > 0 && d > 0;
    //@ assert t <= 10000 && s <= 10000 && d <= 10000;
    //@ assert t * s <= 10000 * 10000;

    result = d <= t * s;
    return result;
}
