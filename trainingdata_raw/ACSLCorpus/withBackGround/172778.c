#include <stdbool.h>

/*@
    predicate in_range(integer x) = 1 <= x <= 10000;
    
    predicate condition(integer a, integer b, integer c, integer d) =
        (c <= b && b <= d) || (c <= a && a <= d);
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    ensures \result == 1 <==> condition(a, b, c, d);
    assigns \nothing;
*/
bool func(long a, long b, long c, long d)
{
    bool result;
    
    //@ assert in_range(a);
    
    if ((c <= b && b <= d) || (c <= a && a <= d)) {
        result = true;
        //@ assert condition(a, b, c, d);
    } else {
        result = false;
        //@ assert !condition(a, b, c, d);
    }
    
    return result;
}
