#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100000;

    logic integer compute_result(integer x) =
        (x / 500) * 1000 + ((x % 500) / 5) * 5;
*/

/*@
    requires valid_range(x);
    ensures \result == compute_result(x);
    assigns \nothing;
*/
uint64_t func(uint64_t x)
{
    uint64_t result;
    uint64_t x_remaining;
    uint64_t five_hundreds;
    uint64_t five_ones;

    result = 0;
    x_remaining = x;

    five_hundreds = x / 500;
    result = result + five_hundreds * 1000;
    x_remaining = x_remaining - five_hundreds * 500;

    five_ones = x_remaining / 5;
    result = result + five_ones * 5;
    x_remaining = x_remaining - five_ones * 5;

    //@ assert result == compute_result(x);
    return result;
}
