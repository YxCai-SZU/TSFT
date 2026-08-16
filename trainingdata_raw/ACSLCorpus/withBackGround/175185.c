#include <stdbool.h>

/*@
    predicate valid_range(integer x) = -100 <= x <= 100;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == (c <= b && a <= d);
    assigns \nothing;
*/
bool func(long a, long b, long c, long d)
{
    bool result;
    //@ assert c <= b && a <= d ==> (c <= b && a <= d);
    result = (c <= b && a <= d);
    return result;
}
