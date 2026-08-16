#include <stddef.h>

/*@
    predicate valid_params(integer n, integer r) =
        1 <= n && n <= 100 && 0 <= r && r <= 4111;

    logic integer compute_result(integer n, integer r) =
        n >= 10 ? r : r + 100 * (10 - n);
*/

/*@
    requires valid_params(n, r);
    ensures \result == compute_result(n, r);
    assigns \nothing;
*/
size_t func(size_t n, size_t r)
{
    size_t ans;

    //@ assert valid_params(n, r);

    if (n >= 10)
    {
        ans = r;
        //@ assert ans == compute_result(n, r);
    }
    else
    {
        ans = r + 100 * (10 - n);
        //@ assert ans == compute_result(n, r);
    }

    return ans;
}
