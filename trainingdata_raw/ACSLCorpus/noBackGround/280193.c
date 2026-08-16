#include <stdint.h>

/*@
    requires 1 <= k <= 100;
    requires 1 <= n <= 100;
    ensures \result == 0 || \result == 1;
    ensures \result == 0 ==> n - 2 * k < 0;
    ensures \result == 1 ==> n - 2 * k >= 0;
*/
int64_t func(int64_t k, int64_t n)
{
    int64_t ans;
    //@ assert n - 2 * k >= -10000;
    //@ assert n - 2 * k <= 10000;
    ans = 0;
    if (n - 2 * k >= 0)
    {
        ans = 1;
    }
    //@ assert (n - 2 * k >= 0) ==> (ans == 1);
    //@ assert (n - 2 * k < 0) ==> (ans == 0);
    return ans;
}
