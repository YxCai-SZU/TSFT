#include <stdbool.h>

/*@
    predicate in_range(integer a, integer b, integer x) =
        1 <= a && a <= 100 && 1 <= b && b <= 100 && 1 <= x && x <= 200;

    logic integer condition(integer a, integer b, integer x) =
        (a <= x && (x - a) <= b) ? 1 : 0;
*/

/*@
    requires in_range(a, b, x);
    ensures \result == (condition(a, b, x) == 1);
    assigns \nothing;
*/
bool func(long a, long b, long x)
{
    // Variable declarations at top of scope
    long y;
    bool result;
    
    //@ assert in_range(a, b, x);
    
    if (x - a < 0) {
        result = false;
    } else {
        y = x - a;
        //@ assert y == x - a;
        result = (y <= b);
    }
    
    //@ assert result == (condition(a, b, x) == 1);
    return result;
}
