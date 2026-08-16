#include <stdint.h>

/*@
    requires 0 <= h1 <= 23 && 0 <= m1 <= 59;
    requires 0 <= h2 <= 23 && 0 <= m2 <= 59;
    requires 0 <= k <= 23 * 60 + 59;
    requires h1 * 60 + m1 < h2 * 60 + m2;
    ensures \result >= 0;
    ensures \result <= (h2 * 60 + m2) - (h1 * 60 + m1);
    ensures \result == (h2 * 60 + m2) - (h1 * 60 + m1) - k || \result == 0;
*/
int64_t func(int64_t h1, int64_t m1, int64_t h2, int64_t m2, int64_t k)
{
    int64_t t1;
    int64_t t2;
    int64_t ans;

    t1 = h1 * 60 + m1;
    t2 = h2 * 60 + m2;

    //@ assert t1 < t2;
    //@ assert t2 - t1 >= 1;

    if (t2 - t1 - k > 0)
    {
        ans = t2 - t1 - k;
        //@ assert ans == t2 - t1 - k;
    }
    else
    {
        ans = 0;
        //@ assert ans == 0;
    }

    //@ assert ans >= 0;
    //@ assert ans <= t2 - t1;
    //@ assert ans == t2 - t1 - k || ans == 0;

    return ans;
}
