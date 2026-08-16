#include <stdint.h>

/*@
    predicate valid_inputs(integer x, integer y) =
        1 <= x <= 100 &&
        1 <= y <= 100 &&
        y % 2 == 0;

    logic integer expected_result(integer x, integer y) =
        x + (y / 2);
*/

/*@
    requires valid_inputs(x, y);
    ensures \result == expected_result(x, y);
    assigns \nothing;
*/
uint64_t func(uint64_t x, uint64_t y)
{
    uint64_t half_y;
    uint64_t result;

    half_y = y / 2;
    result = x + half_y;

    //@ assert result == x + (y / 2);

    return result;
}
