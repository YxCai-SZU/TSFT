#include <stdbool.h>

/*@
    predicate valid_params(integer n, integer k) =
        1 <= n <= 100 && 1 <= k <= 100;

    predicate result_condition(integer n, integer k, bool result) =
        result == (n <= k * 2);
*/

/*@
    requires valid_params(n, k);
    ensures result_condition(n, k, \result);
    assigns \nothing;
*/
bool func(int n, int k)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert 1 <= n <= 100;
    //@ assert 1 <= k <= 100;

    result = n <= k * 2;
    return result;
}
