#include <stdint.h>

/*@
    predicate valid_n(integer n) = 3 <= n && n <= 100;
    
    logic integer func_spec(integer n) = (n - 2) * 180;
    
    lemma func_range: \forall integer n; valid_n(n) ==> 180 <= func_spec(n) <= 17640;
*/

/*@
    requires valid_n(n);
    ensures \result == func_spec(n);
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    // Variable declarations at top of scope
    int32_t result;
    
    //@ assert 1 <= n - 2 <= 98;
    
    //@ assert 180 <= ((int32_t)n - 2) * 180 <= 17640;
    
    result = ((int32_t)n - 2) * 180;
    
    //@ assert result == func_spec(n);
    
    return result;
}
