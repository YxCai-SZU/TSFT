#include <stddef.h>

/*@
    predicate valid_params(integer a, integer b, integer k) =
        0 <= a <= 100 && 0 <= b <= 100 && 0 <= k <= a + b + 1;
*/

/*@
    requires valid_params(a, b, k);
    ensures \result == k || \result == a;
    assigns \nothing;
*/
size_t func(size_t a, size_t b, size_t k)
{
    size_t ans;
    
    //@ assert valid_params(a, b, k);
    
    if (k <= a)
    {
        ans = k;
    }
    else
    {
        ans = a;
    }
    
    //@ assert ans == k || ans == a;
    
    return ans;
}
