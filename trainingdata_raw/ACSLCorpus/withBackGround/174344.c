#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 20;

    logic integer compute_result(integer a, integer b, integer c, integer d) =
        (a - c) * (b - d);
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == compute_result(a, b, c, d);
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b, int32_t c, int32_t d)
{
    // Variable declarations at scope top
    int32_t result;

    //@ assert a - c >= -19 && a - c <= 19;
    //@ assert b - d >= -19 && b - d <= 19;
    //@ assert (a - c) * (b - d) >= -361 && (a - c) * (b - d) <= 361;

    result = (a - c) * (b - d);
    return result;
}
