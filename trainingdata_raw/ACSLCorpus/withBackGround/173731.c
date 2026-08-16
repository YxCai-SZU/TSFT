#include <stdbool.h>

/*@
    predicate valid_params(integer n, integer k) =
        1 <= n && n <= 100 &&
        1 <= k && k <= 100;

    logic integer condition(integer n, integer k) =
        n >= k * 2 - 1 ? 1 : 0;
*/

/*@
    requires valid_params(n, k);
    ensures \result == (condition(n, k) == 1);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int k)
{
    bool result;
    
    //@ assert valid_params(n, k);
    
    result = (n >= k * 2 - 1);
    
    //@ assert result == (condition(n, k) == 1);
    return result;
}
