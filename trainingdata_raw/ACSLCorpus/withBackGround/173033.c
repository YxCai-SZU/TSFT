#include <stdint.h>

/*@
    predicate valid_params(integer n, integer x, integer t) =
        1 <= n <= 1000 && 1 <= x <= 1000 && 1 <= t <= 1000;

    logic integer expected_result(integer n, integer x, integer t) =
        (n / x) * t + (n % x != 0 ? t : 0);
*/

/*@
    requires valid_params(n, x, t);
    ensures \result == expected_result(n, x, t);
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t x, uint64_t t)
{
    // Variable declarations at scope top
    uint64_t ans;
    uint64_t div_result;
    uint64_t mod_result;
    uint64_t temp;

    //@ assert 1 <= n <= 1000;
    //@ assert 1 <= x <= 1000;
    //@ assert 1 <= t <= 1000;

    div_result = n / x;
    //@ assert div_result <= 1000;

    //@ assert div_result * t <= 1000 * 1000;
    temp = div_result * t;

    mod_result = n % x;
    //@ assert mod_result <= 1000;

    if (mod_result != 0)
    {
        ans = temp + t;
    }
    else
    {
        ans = temp;
    }

    //@ assert ans == expected_result(n, x, t);
    return ans;
}
