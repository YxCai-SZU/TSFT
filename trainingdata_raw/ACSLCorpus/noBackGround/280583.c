#include <stdint.h>

/*@
    requires (0 <= (h1) && (h1) < 24 && 0 <= (m1) && (m1) < 60);
    requires (0 <= (h2) && (h2) < 24 && 0 <= (m2) && (m2) < 60);
    requires (0 <= (k) && (k) < 24 * 60);
    requires ((h2) * 60 + (m2) >= (h1) * 60 + (m1) + (k));
    ensures \result == h2 * 60 + m2 - h1 * 60 - m1 - k;
*/
int32_t func(int32_t h1, int32_t m1, int32_t h2, int32_t m2, int32_t k) {
    int32_t t1;
    int32_t t2;
    int32_t result;

    //@ assert h1 * 60 + m1 <= 24 * 60 - 1;
    //@ assert h2 * 60 + m2 <= 24 * 60 - 1;
    //@ assert h2 * 60 + m2 >= h1 * 60 + m1 + k;

    t1 = h1 * 60 + m1;
    t2 = h2 * 60 + m2;
    result = t2 - t1 - k;
    return result;
}
