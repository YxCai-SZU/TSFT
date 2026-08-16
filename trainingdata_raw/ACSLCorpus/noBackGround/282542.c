#include <stdint.h>

/*@
    requires 0 <= h1 && h1 < 24;
    requires 0 <= m1 && m1 < 60;
    requires 0 <= h2 && h2 < 24;
    requires 0 <= m2 && m2 < 60;
    requires 0 <= k && k < 60;
    requires h1 < h2 || (h1 == h2 && m1 <= m2);
    ensures \result >= 0;
    ensures (uint32_t)\result <= (h2 - h1) * 60 + m2 - m1;
*/
int32_t func(uint32_t h1, uint32_t m1, uint32_t h2, uint32_t m2, uint32_t k) {
    uint32_t start_minutes;
    uint32_t end_minutes;
    int32_t ans;

    start_minutes = h1 * 60 + m1;
    end_minutes = h2 * 60 + m2;

    //@ assert end_minutes >= start_minutes;
    //@ assert end_minutes - start_minutes <= (h2 - h1) * 60 + m2 - m1;

    ans = (int32_t)end_minutes - (int32_t)start_minutes - (int32_t)k;

    if (ans < 0) {
        return 0;
    } else {
        return ans;
    }
}
