#include <stdint.h>

/*@
    predicate valid_input(integer a, integer b, integer c, integer d) =
        0 <= a && a <= 10000 &&
        0 <= b && b <= 10000 &&
        0 <= c && c <= 10000 &&
        0 <= d && d <= 10000;

    logic integer total_sum(integer a, integer b, integer c, integer d) =
        a + b + c + d;
*/

/*@
    requires valid_input(a, b, c, d);
    ensures \result >= 0;
    ensures \result <= total_sum(a, b, c, d);
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    int64_t x;
    x = 0;

    if (d >= a + b + 1)
    {
        x = a + b + 1 + c;
        //@ assert x <= total_sum(a, b, c, d);
    }
    else if (d >= a)
    {
        x = d + c;
        //@ assert x <= total_sum(a, b, c, d);
    }
    else
    {
        x = d + c;
        //@ assert x <= total_sum(a, b, c, d);
    }

    return x;
}
