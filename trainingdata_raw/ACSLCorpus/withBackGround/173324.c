#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    logic integer func_result(integer a, integer b, integer c, integer d) =
        (a > c) ?
            ((b > c) ? a + b : a + c)
        :
            ((a > d) ? a + c : c + d);
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == func_result(a, b, c, d);
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b, int32_t c, int32_t d)
{
    int32_t ans;

    //@ assert a + b <= 20000;
    //@ assert c + d <= 20000;

    if (a > c)
    {
        if (b > c)
        {
            ans = a + b;
        }
        else
        {
            ans = a + c;
        }
    }
    else
    {
        if (a > d)
        {
            ans = a + c;
        }
        else
        {
            ans = c + d;
        }
    }

    //@ assert ans == func_result(a, b, c, d);
    return ans;
}
