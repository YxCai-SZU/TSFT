#include <stdint.h>

/*@
    predicate valid_k(integer k) = 1 <= k <= 48;

    logic integer func_result(integer k) = 108 - 2 * k;

    lemma result_bounds: \forall integer k; valid_k(k) ==> 0 <= func_result(k) <= 108;
*/

/*@
    requires valid_k(k);
    ensures \result == func_result(k);
    assigns \nothing;
*/
int32_t func(uint64_t k)
{
    // Variable declarations at top of scope
    int32_t ans;
    
    //@ assert 1 <= k && k <= 48;
    //@ assert 0 <= 108 - 2 * (int32_t)k <= 108;
    
    ans = 108 - 2 * (int32_t)k;
    
    return ans;
}
