#include <stdbool.h>

/*@
    requires (1 <= (d) <= 10000);
    requires (1 <= (t) <= 10000);
    requires (1 <= (s) <= 10000);
    ensures \result == true <==> d <= t * s;
*/
bool func(long d, long t, long s)
{
    // Variable declarations at scope top
    bool result;

    // Precondition verification
    //@ assert t <= 10000;
    //@ assert s <= 10000;
    //@ assert t * s <= 10000 * 10000;

    if (d > t * s)
    {
        result = false;
    }
    else
    {
        result = true;
    }

    // Postcondition verification
    //@ assert result == (d <= t * s);
    return result;
}
