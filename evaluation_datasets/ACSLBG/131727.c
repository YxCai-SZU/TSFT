#include <stdint.h>

/*@
    predicate valid_params(integer a, integer b, integer c, integer k) =
        1 <= a <= 100 &&
        1 <= b <= 100 &&
        1 <= c <= 100 &&
        1 <= k <= a + b + c;

    logic integer compute_ans(integer a, integer b, integer c, integer k) =
        (k > a ? a : k) - (k > a + b ? c : (k > a ? k - a - b : 0));
*/


int32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t k)
{
    int32_t ans = 0;
    uint32_t rest = k;

    //@ assert valid_params(a, b, c, k);

    if (rest > a)
    {
        ans += (int32_t)a;
        rest -= a;
    }
    else
    {
        ans += (int32_t)rest;
        rest = 0;
    }

    //@ assert ans >= 0 && ans <= (int32_t)a;

    if (rest > b)
    {
        rest -= b;
    }
    else
    {
        rest = 0;
    }

    //@ assert rest <= b + c;

    if (rest > c)
    {
        ans -= (int32_t)c;
        rest -= c;
    }
    else
    {
        ans -= (int32_t)rest;
        rest = 0;
    }

    //@ assert ans >= -(int32_t)c && ans <= (int32_t)a;
    return ans;
}
