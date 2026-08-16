#include <stdint.h>

/*@
    requires 1 <= n <= 100;
    requires 1 <= k <= 100;
    ensures \result == 0 || \result == 1;
    ensures \result >= 0;
    ensures \result <= 1;
*/
int32_t func(uint32_t n, uint32_t k)
{
    uint32_t diff;
    int32_t ans;

    if (n >= k)
    {
        diff = n - k;
    }
    else
    {
        diff = k - n;
    }

    //@ assert ((diff) == (((n) >= (k)) ? ((n) - (k)) : ((k) - (n))));

    if (diff % 2 == 0)
    {
        ans = 0;
    }
    else
    {
        ans = 1;
    }

    //@ assert (((diff) % 2 == 0) ? 0 : 1) == ans;
    //@ assert ans == 0 || ans == 1;

    return ans;
}
