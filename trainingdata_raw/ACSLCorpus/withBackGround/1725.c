#include <stdbool.h>

/*@
    predicate in_range(integer a, integer b, integer x) =
        a <= x && x <= b;
*/

/*@
    requires 1 <= a && a <= b && b <= 100;
    requires 1 <= x && x <= b;
    ensures \result <==> in_range(a, b, x);
*/
bool func(long a, long b, long x)
{
    // Variable declarations at top
    bool result;

    //@ assert in_range(a, b, x) <==> in_range(a, b, x);

    result = (a <= x) && (x <= b);
    return result;
}
