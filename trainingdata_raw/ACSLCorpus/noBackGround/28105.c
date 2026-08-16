#include <stdint.h>

/*@
    requires ((h1) >= 0 && (h1) <= 23 &&
        (m1) >= 0 && (m1) <= 59);
    requires ((h2) >= 0 && (h2) <= 23 &&
        (m2) >= 0 && (m2) <= 59);
    requires k >= 0;
    requires ((h1) * 60 + (m1)) <= ((h2) * 60 + (m2));
    requires ((h2) * 60 + (m2)) - ((h1) * 60 + (m1)) >= k;
    ensures \result >= 0;
    ensures \result == ((h2) * 60 + (m2)) - ((h1) * 60 + (m1)) - k;
*/
int32_t func(int32_t h1, int32_t m1, int32_t h2, int32_t m2, int32_t k)
{
    int32_t start_min;
    int32_t end_min;
    int32_t ans;

    //@ assert ((h1) >= 0 && (h1) <= 23 &&         (m1) >= 0 && (m1) <= 59);
    //@ assert ((h2) >= 0 && (h2) <= 23 &&         (m2) >= 0 && (m2) <= 59);
    //@ assert ((h1) * 60 + (m1)) <= ((h2) * 60 + (m2));
    //@ assert ((h2) * 60 + (m2)) - ((h1) * 60 + (m1)) >= k;

    start_min = h1 * 60 + m1;
    end_min = h2 * 60 + m2;

    //@ assert end_min >= start_min;
    //@ assert end_min - start_min >= k;

    ans = end_min - start_min - k;
    return ans;
}
