#include <stdint.h>

/*@
    requires (0 <= (h1) < 24 && 0 <= (m1) < 60);
    requires (0 <= (h2) < 24 && 0 <= (m2) < 60);
    requires h1 <= h2;
    requires m1 <= m2;
    requires k <= 24 * 60;
    ensures \result == ((h2) * 60 + (m2)) - ((h1) * 60 + (m1)) - k;
*/
int32_t func(uint32_t h1, uint32_t m1, uint32_t h2, uint32_t m2, uint32_t k)
{
    uint32_t start_minutes;
    uint32_t end_minutes;
    int32_t ans;

    //@ assert h2 * 60 <= 24 * 60;
    //@ assert h1 * 60 <= 24 * 60;
    //@ assert m2 <= 60;
    //@ assert m1 <= 60;
    //@ assert k <= 24 * 60;

    //@ assert ((h2) * 60 + (m2)) >= ((h1) * 60 + (m1));

    start_minutes = h1 * 60 + m1;
    end_minutes = h2 * 60 + m2;
    ans = (int32_t)end_minutes - (int32_t)start_minutes - (int32_t)k;
    return ans;
}
