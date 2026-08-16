#include <stdint.h>

/*@
    requires (0 <= (h1) && (h1) <= 23 && 0 <= (m1) && (m1) <= 59);
    requires (0 <= (h2) && (h2) <= 23 && 0 <= (m2) && (m2) <= 59);
    requires 0 <= k && k <= 60 * (h2 - h1) + m2 - m1;
    ensures \result == 60 * (h2 - h1) + m2 - m1 - k;
*/
int32_t func(int32_t h1, int32_t m1, int32_t h2, int32_t m2, int32_t k)
{
    int32_t hm1;
    int32_t hm2;
    int32_t result;

    //@ assert (0 <= (h1) && (h1) <= 23 && 0 <= (m1) && (m1) <= 59);
    //@ assert (0 <= (h2) && (h2) <= 23 && 0 <= (m2) && (m2) <= 59);
    //@ assert 0 <= k && k <= 60 * (h2 - h1) + m2 - m1;

    hm1 = h1 * 60 + m1;
    hm2 = h2 * 60 + m2;

    //@ assert hm1 == ((h1) * 60 + (m1));
    //@ assert hm2 == ((h2) * 60 + (m2));

    //@ assert hm2 >= hm1;
    //@ assert hm2 - hm1 <= 60 * (h2 - h1) + m2 - m1;

    result = hm2 - hm1 - k;

    //@ assert result == hm2 - hm1 - k;
    //@ assert result == (60 * ((h2) - (h1)) + (m2) - (m1) - (k));

    return result;
}
