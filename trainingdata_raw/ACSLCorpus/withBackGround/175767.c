#include <stdbool.h>

/*@
    predicate in_range(integer v, integer low, integer high) =
        low <= v && v <= high;

    logic integer sum(integer x, integer y) = x + y;
*/

/*@
    requires in_range(n, 1, 100);
    requires in_range(a, 1, 100);
    requires in_range(b, 1, 100);
    ensures \result == (n >= a && n <= a + b);
*/
bool func(int n, int a, int b)
{
    // Variable declarations at the top
    bool result;

    if (n < a)
    {
        result = false;
        //@ assert n < a;
    }
    else if (n >= a && n <= a + b)
    {
        result = true;
        //@ assert n >= a && n <= a + b;
    }
    else
    {
        //@ assert n >= a && n > a + b;
        result = false;
    }

    return result;
}
