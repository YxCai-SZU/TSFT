#include <stdint.h>

/*@
    predicate in_range(integer x) = 1 <= x <= 100;
    logic integer compute_ans(integer x) = x * 800 - 200 * (x / 15);
*/

/*@
    requires in_range(x);
    ensures \result == compute_ans(x);
    assigns \nothing;
*/
int32_t func(uint32_t x)
{
    // Variable declarations at top of scope
    int32_t ans;
    
    //@ assert x * 800 <= 100 * 800;
    //@ assert x / 15 <= 6;
    //@ assert 200 * (x / 15) <= 200 * 6;
    
    ans = (int32_t)(x * 800 - 200 * (x / 15));
    return ans;
}
