#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;
    
    logic integer triple(integer x) = x * 3;
    
    lemma triple_bounds: \forall integer x; valid_range(x) ==> 3 <= triple(x) <= 300;
*/

/*@
    requires valid_range(x);
    ensures \result == triple(x);
    assigns \nothing;
*/
int32_t func(int32_t x)
{
    int32_t ans;
    
    //@ assert valid_range(x);
    //@ assert 3 <= triple(x) <= 300;
    
    ans = x * 3;
    
    //@ assert ans == triple(x);
    return ans;
}
