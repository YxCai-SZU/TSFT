#include <stdint.h>

/*@
    predicate ans_in_range(integer ans, integer K) =
        ans <= K && ans >= -K;
*/

/*@
    requires 0 <= A <= 1000000000;
    requires 0 <= B <= 1000000000;
    requires 0 <= C <= 1000000000;
    requires 1 <= K <= 1000000000;
    ensures \result <= K;
    ensures \result >= -K;
*/
int64_t func(int64_t A, int64_t B, int64_t C, int64_t K)
{
    int64_t ans;
    int64_t k;

    ans = 0;
    k = K;

    if (A >= k)
    {
        ans += k;
        k = 0;
    }
    else
    {
        ans += A;
        k -= A;
    }

    if (B >= k)
    {
        k = 0;
    }
    else
    {
        k -= B;
    }

    if (C >= k)
    {
        ans -= k;
    }
    else
    {
        ans -= C;
    }

    //@ assert ans <= K;
    //@ assert ans >= -K;

    return ans;
}
