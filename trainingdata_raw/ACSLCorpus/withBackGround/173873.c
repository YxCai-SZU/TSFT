#include <stdint.h>

/*@
    predicate valid_params(integer n, integer k) =
        1 <= k <= n <= 100;
*/

/*@
    requires valid_params(n, k);
    ensures \result == n - k + 1;
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t k)
{
    // Variable declarations at scope top
    int64_t result;
    
    //@ assert valid_params(n, k);
    
    result = n - k + 1;
    
    //@ assert result == n - k + 1;
    
    return result;
}
