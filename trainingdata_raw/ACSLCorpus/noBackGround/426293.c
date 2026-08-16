#include <stdbool.h>

/*@
    requires (1 <= (d) <= 10000 && 1 <= (t) <= 10000 && 1 <= (s) <= 10000);
    ensures \result == true <==> (unsigned)d <= (unsigned)t * (unsigned)s;
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    // Variable declarations at scope top
    bool result;

    //@ assert 1 <= t * s <= 100000000;

    if ((unsigned)d <= (unsigned)t * (unsigned)s)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}
