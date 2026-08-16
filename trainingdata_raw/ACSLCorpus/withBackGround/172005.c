#include <stdint.h>

/*@
    predicate in_range(integer x) = 1 <= x <= 1000000000;
    
    logic integer base_result(integer x) = 2 * (x / 11);
    
    lemma result_bounds:
        \forall integer x;
        in_range(x) ==>
        base_result(x) <= 2 * (x / 11) + 2 &&
        base_result(x) >= 2 * (x / 11);
*/

/*@
    requires in_range(x);
    ensures \result <= 2 * (x / 11) + 2;
    ensures \result >= 2 * (x / 11);
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    uint32_t ans;
    uint32_t rem;
    
    ans = 2 * (x / 11);
    rem = x % 11;
    
    if (rem > 0 && rem <= 6)
    {
        //@ assert ans + 1 <= 2 * (x / 11) + 2;
        return ans + 1;
    }
    else
    {
        //@ assert ans + 2 <= 2 * (x / 11) + 2;
        return ans + 2;
    }
}
