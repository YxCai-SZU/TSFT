#include <stdint.h>

/*@
    requires
        (0 <= (h1) && (h1) < 24 && 0 <= (m1) && (m1) < 60) && (0 <= (h2) && (h2) < 24 && 0 <= (m2) && (m2) < 60) &&
        ((h1) * 60 + (m1) <= (h2) * 60 + (m2)) &&
        ((h1) * 60 + (m1) + (k) <= (h2) * 60 + (m2));
    ensures
        \result == ((((h2)) * 60 + ((m2))) - (((h1)) * 60 + ((m1))) - (k));
*/
int32_t func(uint32_t h1, uint32_t m1, uint32_t h2, uint32_t m2, uint32_t k)
{
    uint32_t t1;
    uint32_t t2;
    int32_t ans;

    //@ assert ((h1) * 60 + (m1)) <= 24 * 60 - 1;
    //@ assert ((h2) * 60 + (m2)) <= 24 * 60 - 1;
    //@ assert ((h1) * 60 + (m1)) + k <= 24 * 60 - 1;

    t1 = h1 * 60 + m1;
    t2 = h2 * 60 + m2;
    ans = (int32_t)(t2 - t1 - k);
    return ans;
}
