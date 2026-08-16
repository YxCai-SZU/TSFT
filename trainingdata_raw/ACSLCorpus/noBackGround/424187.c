#include <stdint.h>

/*@
    requires 0 <= h1 && h1 <= 23;
    requires 0 <= m1 && m1 <= 59;
    requires 0 <= h2 && h2 <= 23;
    requires 0 <= m2 && m2 <= 59;
    requires 0 <= k && k <= 100000;
    requires h1 * 60 + m1 <= h2 * 60 + m2;
    ensures \result == (h2 * 60 + m2) - (h1 * 60 + m1) - k;
    ensures \result >= -100000;
*/
int32_t func(uint32_t h1, uint32_t m1, uint32_t h2, uint32_t m2, uint32_t k)
{
    uint32_t t1;
    uint32_t t2;
    int32_t ans;

    t1 = h1 * 60 + m1;
    t2 = h2 * 60 + m2;

    //@ assert t1 <= t2;
    //@ assert t2 - t1 >= 0;
    //@ assert (int32_t)t2 - (int32_t)t1 - (int32_t)k >= -100000;

    ans = (int32_t)t2 - (int32_t)t1 - (int32_t)k;
    return ans;
}
