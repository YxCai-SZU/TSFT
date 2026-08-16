#include <stdbool.h>

/*@
    predicate valid_range(integer v) = 1 <= v && v <= 100;
*/

/*@
    requires valid_range(n);
    requires valid_range(m);
    requires valid_range(x);
    requires valid_range(y);
    ensures \result == (n + x < y && y < m + 1 + x);
*/
bool func(unsigned int n, unsigned int m, unsigned int x, unsigned int y)
{
    // Variable declarations at top of scope
    bool result;

    if (n + x < y && y < m + 1 + x)
    {
        //@ assert n + x < y && y < m + 1 + x;
        result = true;
    }
    else
    {
        //@ assert !(n + x < y && y < m + 1 + x);
        result = false;
    }

    return result;
}
