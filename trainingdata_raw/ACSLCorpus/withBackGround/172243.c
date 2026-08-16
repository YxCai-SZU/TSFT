#include <stdint.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 100000;

    predicate pre_cond(integer x, integer y, integer z) =
        valid_range(x) && valid_range(y) && valid_range(z) &&
        y + 2 * z <= x;

    predicate post_cond(integer x, integer y, integer z, integer result) =
        result == (x - z) / (y + z);
*/

/*@
    requires pre_cond(x, y, z);
    ensures post_cond(x, y, z, \result);
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y, uint32_t z)
{
    // Declare all variables at the top
    uint32_t result;

    //@ assert x >= y;
    //@ assert x - z >= 0;
    //@ assert y + z <= x;
    //@ assert x - z <= x;
    //@ assert y + z > 0;
    //@ assert (x - z) / (y + z) <= (x - z) / 1;

    result = (x - z) / (y + z);
    return result;
}
