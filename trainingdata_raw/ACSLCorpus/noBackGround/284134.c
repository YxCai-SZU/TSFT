#include <stdint.h>

/*@
    requires (0 <= (h1) <= 23 && 0 <= (m1) <= 59);
    requires (0 <= (h2) <= 23 && 0 <= (m2) <= 59);
    requires 0 <= k <= 23 * 60 + 59;
    requires ((h1) * 60 + (m1)) <= ((h2) * 60 + (m2));
    ensures \result == ((h2) * 60 + (m2)) - ((h1) * 60 + (m1)) - k;
*/
int32_t func(uint32_t h1, uint32_t m1, uint32_t h2, uint32_t m2, uint32_t k)
{
    uint32_t start;
    uint32_t end;
    int32_t result;

    start = h1 * 60 + m1;
    end = h2 * 60 + m2;

    //@ assert ((h1) * 60 + (m1)) == start;
    //@ assert ((h2) * 60 + (m2)) == end;
    //@ assert start <= end;

    result = (int32_t)end - (int32_t)start - (int32_t)k;

    //@ assert result == ((h2) * 60 + (m2)) - ((h1) * 60 + (m1)) - k;

    return result;
}
