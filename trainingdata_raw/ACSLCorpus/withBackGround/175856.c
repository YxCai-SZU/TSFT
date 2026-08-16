#include <stdint.h>
#include <limits.h>

/*@
    predicate valid_n(integer n) = 3 <= n && n <= 100;
    logic integer func_result(integer n) = (n - 2) * 180;
*/

/*@
    requires valid_n(n);
    ensures \result == func_result(n);
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    // Variable declarations at top of scope
    int32_t result;
    
    //@ assert valid_n(n);
    //@ assert n - 2 >= 1;
    //@ assert (n - 2) * 180 <= INT32_MAX;
    
    result = ((int32_t)n - 2) * 180;
    
    //@ assert result == func_result(n);
    return result;
}
