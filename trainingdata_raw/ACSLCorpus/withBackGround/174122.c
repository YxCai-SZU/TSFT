#include <stdint.h>

/*@
    predicate valid_range(integer a) = 1 <= a && a <= 10;

    logic integer max(integer x, integer y) = x > y ? x : y;
    logic integer min(integer x, integer y) = x < y ? x : y;
    logic integer triangle_area(integer a, integer b, integer c) =
        (a + b + c) / 2 * ((a + b + c) / 2 - a) * ((a + b + c) / 2 - b) * ((a + b + c) / 2 - c);
*/

/*@
    requires valid_range(a);
    ensures \result == a + (a * a) + (a * a * a);
    assigns \nothing;
*/
uint32_t func(uint32_t a)
{
    //@ assert valid_range(a);
    //@ assert a + (a * a) + (a * a * a) <= 10 + (10 * 10) + (10 * 10 * 10);
    return a + (a * a) + (a * a * a);
}
