#include <stdbool.h>

/*@
    predicate valid_params(integer n, integer k) =
        1 <= n && n <= 100 &&
        1 <= k && k <= 100;

    logic integer func_result(integer n, integer k) =
        (n % k == 0) ? 0 : 1;
*/

/*@
    requires valid_params(n, k);
    assigns \nothing;
    ensures \result >= 0;
    ensures \result == 0 || \result == 1;
    ensures \result == func_result(n, k);
*/
int func(unsigned int n, unsigned int k)
{
    int result;
    //@ assert valid_params(n, k);
    
    if (n % k == 0) {
        result = 0;
        //@ assert result == func_result(n, k);
    } else {
        //@ assert n % k != 0;
        result = 1;
        //@ assert result == func_result(n, k);
    }
    
    return result;
}
