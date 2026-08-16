#include <stdbool.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 100;

    predicate pre_cond(integer a, integer b, integer c, integer d) =
        valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d) &&
        a < b && c < d;

    predicate post_cond(integer a, integer b, integer c, integer d, bool result) =
        result == (b >= c && a <= d);
*/

/*@
    requires pre_cond(a, b, c, d);
    ensures post_cond(a, b, c, d, \result);
    assigns \nothing;
*/
bool func(long a, long b, long c, long d)
{
    // Variable declarations at the top
    bool result;

    if (b >= c)
    {
        if (a <= d)
        {
            result = true;
        }
        else
        {
            //@ assert b >= c && a > d;
            result = false;
        }
    }
    else
    {
        //@ assert b < c && a <= d;
        result = false;
    }

    //@ assert result == (b >= c && a <= d);
    return result;
}
