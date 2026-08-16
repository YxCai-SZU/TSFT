#include <stdbool.h>

/*@
    predicate in_range(integer v) = 1 <= v <= 100;
    predicate condition_holds(integer c, integer b, integer d) = c <= b && b <= d;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    ensures \result == true <==> condition_holds(c, b, d);
    assigns \nothing;
*/
bool func(int a, int b, int c, int d)
{
    //@ assert condition_holds(c, b, d) <==> condition_holds(c, b, d);
    return c <= b && b <= d;
}
