#include <stdbool.h>

/*@
    requires (1 <= (d) <= 10000);
    requires (1 <= (t) <= 10000);
    requires (1 <= (s) <= 10000);
    ensures \result == (t * s >= d);
*/
bool func(long d, long t, long s)
{
    // Variable declarations at scope top
    bool result;

    //@ assert 1 <= t <= 10000;
    //@ assert 1 <= s <= 10000;
    //@ assert t * s <= 10000 * 10000;
    //@ assert t * s >= 1;

    result = (t * s >= d);
    return result;
}
