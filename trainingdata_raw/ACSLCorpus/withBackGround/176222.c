#include <stdbool.h>

/*@
    predicate in_range(integer v) =
        -1000000000 <= v && v <= 1000000000;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    ensures \result == true <==> c <= a && b <= d;
    assigns \nothing;
*/
bool func(long a, long b, long c, long d)
{
    bool result;

    //@ assert c <= a && b <= d <==> c <= a && b <= d;

    if (c <= a && b <= d)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}
