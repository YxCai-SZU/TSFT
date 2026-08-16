#include <stdint.h>

/*@
    predicate valid_params(integer n, integer k) =
        1 <= n <= 200000 &&
        1 <= k <= n;

    logic integer compute_result(integer n, integer k) =
        n - k + 1;

    lemma result_bounds:
        \forall integer n, k;
        valid_params(n, k) ==> 
        1 <= compute_result(n, k) <= 200000;
*/

/*@
    requires valid_params(n, k);
    ensures \result == compute_result(n, k);
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t k)
{
    // Variable declarations at top of scope
    uint32_t res;

    //@ assert valid_params(n, k);
    
    //@ assert compute_result(n, k) <= 200000;
    //@ assert compute_result(n, k) >= 1;
    
    res = n - k + 1;
    
    //@ assert res == compute_result(n, k);
    return res;
}
