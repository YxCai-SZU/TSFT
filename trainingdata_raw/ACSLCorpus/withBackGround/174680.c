#include <stdint.h>

/*@
    predicate valid_range(integer n, integer m) =
        1 <= n <= 100 && 0 <= m <= n * n;
    
    logic integer compute_result(integer n, integer m) =
        n * n - m;
*/

/*@
    requires valid_range(n, m);
    ensures \result == compute_result(n, m);
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m)
{
    // Variable declarations at top of scope
    uint32_t n_sq;
    int32_t result;
    
    //@ assert 1 <= n <= 100;
    //@ assert 0 <= m <= n * n;
    
    n_sq = n * n;
    //@ assert n_sq <= 10000;
    //@ assert n_sq >= m;
    
    result = (int32_t)(n_sq - m);
    //@ assert result == compute_result(n, m);
    
    return result;
}
