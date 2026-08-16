#include <stdint.h>

/*@
    predicate valid_input(integer a, integer b, integer c, integer k) =
        1 <= a && a <= 7 &&
        1 <= b && b <= 7 &&
        1 <= c && c <= 7 &&
        1 <= k && k <= 7;

    predicate ans_in_range(integer ans) =
        -1000000000 <= ans && ans <= 1000000000;
*/

/*@
    requires valid_input(a, b, c, k);
    ensures ans_in_range(\result);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t k)
{
    int32_t ans = 0;
    uint32_t k_local = k;

    //@ assert valid_input(a, b, c, k_local);

    if (a >= k_local)
    {
        ans += (int32_t)k_local;
        k_local = 0;
    }
    else
    {
        ans += (int32_t)a;
        k_local -= a;
    }

    //@ assert -1000000000 <= ans && ans <= 1000000000;

    if (b >= k_local)
    {
        k_local = 0;
    }
    else
    {
        k_local -= b;
    }

    //@ assert 0 <= k_local && k_local <= 7;
    ans -= (int32_t)k_local;

    //@ assert ans_in_range(ans);
    return ans;
}
