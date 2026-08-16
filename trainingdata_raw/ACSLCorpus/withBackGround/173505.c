#include <stdint.h>

/*@
    predicate valid_params(integer n, integer r) =
        1 <= n <= 100 && 0 <= r <= 4111;
    
    logic integer compute_result(integer n, integer r) =
        n < 10 ? r + 100 * (10 - n) : r;
*/

/*@
    requires valid_params(n, r);
    ensures \result == compute_result(n, r);
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t r)
{
    int64_t ans = 0;
    
    //@ assert valid_params(n, r);
    
    if (n < 10)
    {
        ans = r + 100 * (10 - n);
        //@ assert ans == compute_result(n, r);
    }
    else
    {
        ans = r;
        //@ assert ans == compute_result(n, r);
    }
    
    return ans;
}
