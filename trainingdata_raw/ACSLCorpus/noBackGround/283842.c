#include <stdint.h>

/*@
    requires (0 <= (h1) && (h1) < 24 && 0 <= (m1) && (m1) < 60);
    requires (0 <= (h2) && (h2) < 24 && 0 <= (m2) && (m2) < 60);
    requires 0 <= k && k < 60 * 24;
    requires ((h1) * 60 + (m1)) < ((h2) * 60 + (m2));
    ensures \result == ((h2) * 60 + (m2)) - ((h1) * 60 + (m1)) - k;
*/
int32_t func(uint32_t h1, uint32_t m1, uint32_t h2, uint32_t m2, uint32_t k)
{
    uint32_t start_min;
    uint32_t end_min;
    int32_t buf;

    start_min = h1 * 60 + m1;
    end_min = h2 * 60 + m2;
    //@ assert end_min >= start_min;
    buf = (int32_t)end_min - (int32_t)start_min - (int32_t)k;
    //@ assert buf == ((h2) * 60 + (m2)) - ((h1) * 60 + (m1)) - k;
    return buf;
}
