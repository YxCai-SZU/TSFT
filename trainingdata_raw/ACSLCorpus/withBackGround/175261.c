#include <stdint.h>

/*@
    predicate valid_params(integer n, integer k) =
        1 <= k <= n <= 50;
    
    logic integer expected_result(integer n, integer k) =
        n - k + 1;
*/

/*@
    requires valid_params(n, k);
    ensures \result == expected_result(n, k);
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t k)
{
    uint64_t ans;
    //@ assert valid_params(n, k);
    ans = n - k + 1;
    //@ assert 1 <= ans <= 50;
    //@ assert ans == expected_result(n, k);
    return ans;
}
