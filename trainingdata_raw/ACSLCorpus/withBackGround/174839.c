#include <stdint.h>

/*@
    predicate valid_range(integer v) = 2 <= v <= 100;
    
    logic integer compute_result(integer x, integer y) = x * y - (x + y - 1);
    
    lemma result_nonnegative:
        \forall integer x, y; valid_range(x) && valid_range(y) ==> compute_result(x, y) >= 0;
*/

/*@
    requires 2 <= x <= 100;
    requires 2 <= y <= 100;
    ensures \result >= 0;
    ensures \result == x * y - (x + y - 1);
    assigns \nothing;
*/
int64_t func(int64_t x, int64_t y)
{
    int64_t ans;
    
    //@ assert 2 * 2 <= x * y <= 100 * 100;
    //@ assert x + y - 1 >= 0;
    //@ assert x * y - (x + y - 1) >= 0;
    
    ans = x * y - (x + y - 1);
    
    return ans;
}
