#include <stdint.h>

/*@
    predicate valid_params(integer x, integer y, integer z) =
        1 <= x && 1 <= y && 1 <= z &&
        x <= 100000 && y <= 100000 && z <= 100000 &&
        y + z <= x;

    logic integer compute_result(integer x, integer y, integer z) =
        (x - z) / (y + z);

    lemma result_bounds: \forall integer x, y, z;
        valid_params(x, y, z) ==> compute_result(x, y, z) <= x;
*/

/*@
    requires valid_params(x, y, z);
    ensures \result == compute_result(x, y, z);
    ensures \result <= x;
    assigns \nothing;
*/
uint64_t func(uint64_t x, uint64_t y, uint64_t z)
{
    //@ assert y + z > 0;
    uint64_t result;
    result = (x - z) / (y + z);
    //@ assert result == compute_result(x, y, z);
    return result;
}
