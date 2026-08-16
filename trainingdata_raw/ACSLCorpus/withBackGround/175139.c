#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x && x <= 1;
    logic integer multiply(integer x, integer y) = x * y;
    lemma multiplication_bounds: \forall integer x, y; valid_range(x) && valid_range(y) ==> multiply(x, y) <= 4294967295;
*/

/*@
    requires valid_range(x) && valid_range(y);
    ensures \result == multiply(x, y);
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y)
{
    //@ assert multiply(x, y) <= 4294967295;
    uint32_t ans = x * y;
    return ans;
}

/*@
    requires valid_range(x) && valid_range(y);
    ensures \result == multiply(x, y);
    assigns \nothing;
*/
uint32_t func_no_requires(uint32_t x, uint32_t y)
{
    //@ assert multiply(x, y) <= 4294967295;
    uint32_t ans = x * y;
    return ans;
}
