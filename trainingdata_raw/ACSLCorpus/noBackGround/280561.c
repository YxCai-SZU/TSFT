#include <stdint.h>

/*@
    requires (0 <= (h1) && (h1) <= 23 && 0 <= (m1) && (m1) <= 59);
    requires (0 <= (h2) && (h2) <= 23 && 0 <= (m2) && (m2) <= 59);
    requires k >= 0;
    requires (60 * (h1) + (m1) <= 60 * (h2) + (m2));
    requires 60 * h2 + m2 - 60 * h1 - m1 - k >= 0;
    ensures \result == 60 * h2 + m2 - 60 * h1 - m1 - k;
*/
int64_t func(int64_t h1, int64_t m1, int64_t h2, int64_t m2, int64_t k)
{
    int64_t t1;
    int64_t t2;
    int64_t ans;

    t1 = 60 * h1 + m1;
    t2 = 60 * h2 + m2;
    ans = t2 - t1 - k;

    //@ assert t2 - t1 - k == 60 * h2 + m2 - 60 * h1 - m1 - k;

    return ans;
}
