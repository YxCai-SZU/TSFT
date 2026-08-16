#include <stdint.h>

/*@
    predicate bounds(integer k) = 1 <= k <= 23;
    logic integer compute(integer k) = 48 - k;
*/


int32_t func(int32_t k)
{
    // Variable declarations at top of scope
    int32_t result;
    
    //@ assert bounds(k);
    
    result = 48 - k;
    
    //@ assert result == compute(k);
    return result;
}
