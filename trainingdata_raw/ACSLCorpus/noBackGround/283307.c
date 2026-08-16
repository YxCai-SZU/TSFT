#include <stdint.h>

/*@
    requires (0 <= (h1) <= 23 && 0 <= (m1) <= 59);
    requires (0 <= (h2) <= 23 && 0 <= (m2) <= 59);
    requires 0 <= k <= 1439;
    requires (((h1) < (h2)) || ((h1) == (h2) && (m1) <= (m2)));
    ensures \result == (((h2) - (h1)) * 60 + (m2) - (m1) - (k));
*/
int32_t func(int32_t h1, int32_t m1, int32_t h2, int32_t m2, int32_t k)
{
    int32_t t1;
    int32_t t2;
    int32_t result;

    //@ assert h1 * 60 <= 1380;
    //@ assert h2 * 60 <= 1380;
    //@ assert m1 <= 59;
    //@ assert m2 <= 59;

    t1 = h1 * 60 + m1;
    t2 = h2 * 60 + m2;
    result = t2 - t1 - k;

    return result;
}
