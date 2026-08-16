#include <stdint.h>

/*@
    predicate is_valid_params(integer X, integer Y) =
        1 <= X <= 100 &&
        1 <= Y <= 100 &&
        Y % 2 == 0;
*/

/*@
    logic integer expected_result(integer X, integer Y) = X + (Y / 2);
*/

/*@
    requires is_valid_params(X, Y);
    ensures \result == expected_result(X, Y);
    assigns \nothing;
*/
uint64_t func(uint64_t X, uint64_t Y)
{
    uint64_t half_Y;
    uint64_t result;

    half_Y = Y / 2;
    result = X + half_Y;

    //@ assert result == X + (Y / 2);

    return result;
}
