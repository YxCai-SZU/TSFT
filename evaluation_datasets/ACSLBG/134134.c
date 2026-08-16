#include <stdbool.h>

/*@
    predicate valid_params(integer n, integer k) =
        1 <= k <= 100 && 1 <= n <= 100;

    predicate post_condition(integer n, integer k, integer ans) =
        ans >= 0 &&
        (ans == 0 ==> n - k >= 0) &&
        (ans > 0 ==> n - k < 0 && ans == k - n);
*/


int func(int n, int k)
{
    int ans;

    if (n >= k)
    {
        ans = 0;
        //@ assert ans == 0;
    }
    else
    {
        ans = k - n;
        //@ assert ans > 0;
    }

    return ans;
}
