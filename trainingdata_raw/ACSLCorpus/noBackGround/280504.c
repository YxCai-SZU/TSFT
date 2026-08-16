#include <stdbool.h>

/*@
    requires (1 <= (d) <= 10000) && (1 <= (t) <= 10000) && (1 <= (s) <= 10000);
    ensures \result == (d <= t * s);
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert t >= 1 && t <= 10000;
    //@ assert s >= 1 && s <= 10000;
    //@ assert t * s >= 1;
    //@ assert t * s <= 10000 * 10000;
    //@ assert t * s >= 0;

    result = (d <= t * s);
    return result;
}
