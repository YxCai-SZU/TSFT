#include <stdbool.h>

/*@
    requires (1 <= (d) <= 10000) && (1 <= (t) <= 10000) && (1 <= (s) <= 10000);
    ensures \result == (s * t >= d);
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert (1 <= (s) <= 10000);
    //@ assert (1 <= (t) <= 10000);
    //@ assert s * t <= 10000 * 10000;

    result = (s * t >= d);
    return result;
}
