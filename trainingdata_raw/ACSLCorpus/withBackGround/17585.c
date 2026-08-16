#include <stdint.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 10;

    logic integer compute_result(integer x, integer y, integer z) =
        (x * y + z) / 2;

    lemma result_bound:
        \forall integer x, y, z;
            valid_range(x) && valid_range(y) && valid_range(z) ==>
            compute_result(x, y, z) <= (100 + 10) / 2;
*/

/*@
    requires valid_range(x) && valid_range(y) && valid_range(z);
    ensures \result == compute_result(x, y, z);
    ensures \result <= (100 + 10) / 2;
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y, uint32_t z)
{
    // Variable declarations at scope top
    uint32_t ans;

    //@ assert 1 <= x * y + z;
    //@ assert x * y <= 100;
    //@ assert x * y + z <= 110;
    //@ assert (x * y + z) / 2 <= (100 + 10) / 2;

    ans = (x * y + z) / 2;

    //@ assert ans == compute_result(x, y, z);
    //@ assert ans <= (100 + 10) / 2;

    return ans;
}
