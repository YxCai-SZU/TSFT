#include <stdint.h>

/*@
    predicate valid_params(integer n, integer m) =
        1 <= n && n <= 100 &&
        1 <= m && m <= n;

    logic integer compute_result(integer n, integer m) =
        m == 1 ? 1 : (n - m) * 2 + 1;
*/

/*@
    requires valid_params(n, m);
    ensures \result == compute_result(n, m);
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m)
{
    // Variable declarations at scope top
    int32_t result;

    if (m == 1)
    {
        result = 1;
    }
    else
    {
        //@ assert n >= m;
        //@ assert n - m <= 100;
        //@ assert (n - m) * 2 <= 200;
        //@ assert (n - m) * 2 + 1 <= 201;
        result = (int32_t)(n - m) * 2 + 1;
    }

    return result;
}
