#include <stdint.h>
/*@
    predicate valid_params(integer a, integer b, integer k) =
        1 <= a && 1 <= b && 1 <= k &&
        a <= 1000000000 && b <= 1000000000 && k <= 1000000000 &&
        a + b >= k;

    logic integer compute_result(integer a, integer b, integer k) =
        (a < k ? a : k) - 
        (k - (a < k ? a : k) > 0 ? 
         (b < k - (a < k ? a : k) ? k - (a < k ? a : k) - b : 0) : 0);
*/

/*@
    requires valid_params(a, b, k);
    ensures \result <= k;
    ensures \result >= 0;
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t k)
{
    uint64_t result = 0;
    uint64_t remaining_k = k;

    //@ assert valid_params(a, b, k);
    
    if (a < remaining_k)
    {
        result += a;
        remaining_k -= a;
    }
    else
    {
        result += remaining_k;
        remaining_k = 0;
    }

    //@ assert result <= k;
    
    if (remaining_k > 0)
    {
        if (b < remaining_k)
        {
            remaining_k -= b;
        }
        else
        {
            remaining_k = 0;
        }
    }

    //@ assert result <= k;
    
    if (remaining_k > 0)
    {
        result -= remaining_k;
    }

    //@ assert result <= k;
    //@ assert result >= 0;
    
    return result;
}
