#include <stdbool.h>

/*@
    predicate in_range(integer x) = -100 <= x && x <= 100;
    predicate within_bounds(integer a, integer b, integer c) =
        a <= b && in_range(a) && in_range(b) && in_range(c);
    predicate result_condition(integer a, integer b, integer c, bool res) =
        res <==> (c >= a && c <= b);
*/

/*@
    requires a <= b;
    requires in_range(a) && in_range(b) && in_range(c);
    ensures \result <==> (c >= a && c <= b);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert a <= b;
    //@ assert in_range(a) && in_range(b) && in_range(c);

    result = (c >= a && c <= b);
    return result;
}
