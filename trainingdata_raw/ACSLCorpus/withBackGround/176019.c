#include <stdint.h>

/*@
    predicate valid_params(integer a, integer b, integer c, integer k) =
        a >= 0 && b >= 0 && c >= 0 &&
        k >= 1 &&
        k <= a + b + c &&
        a + b + c <= 2000000000;

    logic integer max_val(integer ans, integer c) =
        ans > -1 * c ? ans : -1 * c;
*/

/*@
    requires valid_params(a, b, c, k);
    ensures \result >= -1 * c;
    ensures \result <= 1 * a;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t ans;
    int64_t rst;
    int64_t max_val;

    ans = 0;
    rst = k;

    if (a >= rst)
    {
        ans += rst;
        rst -= rst;
    }
    else
    {
        ans += a;
        rst -= a;
    }

    if (b >= rst)
    {
        rst -= rst;
    }
    else
    {
        rst -= b;
    }

    ans -= rst;

    if (ans > -1 * c)
    {
        max_val = ans;
    }
    else
    {
        max_val = -1 * c;
    }

    //@ assert max_val == ans || max_val == -1 * c;
    //@ assert ans >= -1 * c;
    //@ assert ans <= 1 * a;
    //@ assert max_val >= -1 * c;
    //@ assert max_val <= 1 * a;

    return max_val;
}
