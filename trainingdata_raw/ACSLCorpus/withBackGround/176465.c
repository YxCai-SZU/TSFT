#include <stdint.h>

/*@
    predicate valid_params(integer X, integer Y) =
        1 <= X && X <= 100 &&
        1 <= Y && Y <= 100 &&
        Y % 2 == 0;

    logic integer expected_result(integer X, integer Y) =
        X + (Y / 2);
*/

/*@
    requires valid_params(X, Y);
    ensures \result == expected_result(X, Y);
    assigns \nothing;
*/
uint64_t func(uint64_t X, uint64_t Y)
{
    uint64_t result;
    //@ assert valid_params(X, Y);
    result = X + (Y / 2);
    //@ assert result == expected_result(X, Y);
    return result;
}
