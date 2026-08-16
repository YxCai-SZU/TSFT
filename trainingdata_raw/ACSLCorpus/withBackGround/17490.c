#include <stdbool.h>

/*@
    predicate intervals_overlap(integer a, integer b, integer c, integer d) =
        a <= b && c <= d && c <= b && a <= d;
 */

/*@
    requires a >= -100 && b <= 100;
    requires c >= -100 && d <= 100;
    requires a <= b;
    requires c <= d;
    ensures \result == (c <= b && a <= d);
    ensures \result <==> intervals_overlap(a, b, c, d);
 */
bool func(long a, long b, long c, long d)
{
    //@ assert a <= b && c <= d;
    return c <= b && a <= d;
}
