#include <stdint.h>

/*@
    predicate valid_input(integer a, integer b, integer c, integer d, integer e) =
        0 <= a && a <= 24 &&
        0 <= b && b <= 59 &&
        0 <= c && c <= 24 &&
        0 <= d && d <= 59 &&
        0 <= e && e <= 59;

    logic integer calculate_result(integer a, integer b, integer c, integer d, integer e) =
        (b + d + e) - (a + c);
*/

/*@
    requires valid_input(a, b, c, d, e);
    ensures \result == calculate_result(a, b, c, d, e);
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b, int32_t c, int32_t d, int32_t e)
{
    int32_t x;
    int32_t y;
    int32_t ans;

    //@ assert b + d <= 118;
    //@ assert b + d + e <= 177;
    //@ assert a + c <= 48;

    x = b + d + e;
    y = a + c;
    ans = x - y;
    return ans;
}
