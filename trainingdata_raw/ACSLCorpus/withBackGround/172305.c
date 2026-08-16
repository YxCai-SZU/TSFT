#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    logic integer func_result(integer a, integer b, integer c, integer d) =
        a < c ?
            (b < c ? a + b : a + c) :
            (a < d ? c + a : c + d);
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == func_result(a, b, c, d);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t result;

    if (a < c)
    {
        if (b < c)
        {
            //@ assert a < c && b < c;
            result = a + b;
        }
        else
        {
            //@ assert a < c && b >= c;
            result = a + c;
        }
    }
    else
    {
        if (a < d)
        {
            //@ assert a >= c && a < d;
            result = c + a;
        }
        else
        {
            //@ assert a >= c && a >= d;
            result = c + d;
        }
    }

    return result;
}
