#include <stdint.h>

/*@
    predicate valid_n(integer n) = 1 <= n && n <= 1000000000;
    
    logic integer expected_result(integer n) = ((n - 1) * n) / 2;
*/

/*@
    requires valid_n(n);
    ensures \result == expected_result(n);
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    // Variable declarations at top of scope
    uint64_t ans;
    
    //@ assert n > 0 && n <= 1000000000;
    //@ assert n - 1 >= 0;
    //@ assert (n - 1) * n <= 1000000000 * 1000000000;
    
    ans = ((n - 1) * n) / 2;
    return ans;
}
