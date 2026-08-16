#include <stdint.h>

/*@
    predicate valid_params(integer n, integer k) =
        1 <= n && n <= 1000000000 &&
        2 <= k && k <= 10;

    lemma mod_range: \forall integer n, k; valid_params(n, k) ==> 0 <= n % k < k;
*/

/*@
    requires valid_params(n, k);
    ensures \result <= n;
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t k)
{
    uint32_t r;
    
    r = n % k;
    
    if (r == 0U)
    {
        return 0U;
    }
    else
    {
        //@ assert 1 <= n;
        //@ assert k <= 10;
        return 1U;
    }
}
