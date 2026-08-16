#include <stdint.h>

/*@
    predicate is_valid_input(uint32_t x) = x <= 100000;

    logic integer calculate_ans(integer x) =
        (x % 1000 == 0) ? 0 : (1000 - x % 1000);
*/

/*@
    requires is_valid_input(x);
    ensures \result <= 1000;
    ensures \result == calculate_ans(x);
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    uint32_t ans;
    
    //@ assert x <= 100000;
    
    if (x % 1000 == 0) {
        ans = 0;
    } else {
        ans = 1000 - x % 1000;
    }
    
    //@ assert ans <= 1000;
    
    return ans;
}
