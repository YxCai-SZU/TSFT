#include <stdint.h>

/*@
    predicate valid_params(integer n, integer k) =
        1 <= n <= 100000 && 0 <= k <= n;

    logic integer func_result(integer n, integer k) =
        n <= k ? 0 : n - k;

    lemma result_bounds:
        \forall integer n, k;
        valid_params(n, k) ==> 
        (func_result(n, k) == 0 || func_result(n, k) == n - k);
*/

/*@
    requires valid_params(n, k);
    ensures \result == 0 || \result == n - k;
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t k)
{
    uint64_t result;
    
    if (n <= k)
    {
        //@ assert n <= k;
        result = 0;
    }
    else
    {
        //@ assert n > k;
        //@ assert n - k <= 100000;
        result = n - k;
    }
    
    return result;
}
