#include <stdint.h>

/*@
    predicate valid_input(integer r, integer g) =
        0 <= r <= 4500 && 0 <= g <= 4500;
    
    logic integer compute_result(integer r, integer g) =
        g + (g - r);
*/

/*@
    requires valid_input(r, g);
    ensures \result == compute_result(r, g);
    assigns \nothing;
*/
int64_t func(int64_t r, int64_t g)
{
    int64_t ans;
    
    //@ assert valid_input(r, g);
    
    ans = g + (g - r);
    
    //@ assert ans == compute_result(r, g);
    
    return ans;
}
