#include <stdint.h>

/*@
    predicate valid_inputs(integer x, integer y, integer z) =
        1 <= x <= 100000 &&
        1 <= y <= 100000 &&
        1 <= z <= 100000 &&
        y + 2 * z <= x;

    logic integer compute_bound(integer x, integer y, integer z) =
        (x - z) / (y + z);
*/

/*@
    requires valid_inputs(x, y, z);
    ensures \result >= 0;
    ensures \result <= compute_bound(x, y, z);
    assigns \nothing;
*/
int32_t func(uint32_t x, uint32_t y, uint32_t z)
{
    uint32_t ans;
    //@ assert valid_inputs(x, y, z);
    ans = (x - z) / (y + z);
    //@ assert ans >= 0;
    return (int32_t)ans;
}
