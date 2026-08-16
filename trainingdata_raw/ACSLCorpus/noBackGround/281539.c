#include <stdint.h>

/*@
    requires
        (0 <= (h1) <= 23 && 0 <= (m1) <= 59) && (0 <= (h2) <= 23 && 0 <= (m2) <= 59) &&
        ((((h1)) * 60 + ((m1))) <= (((h2)) * 60 + ((m2))) &&
        (((h1)) * 60 + ((m1))) <= 1440 &&
        (((h2)) * 60 + ((m2))) <= 1440) && k <= 1440;
    ensures
        \result == (int64_t)(h2 * 60 + m2) - (int64_t)(h1 * 60 + m1) - (int64_t)k;
*/
int64_t func(uint64_t h1, uint64_t m1, uint64_t h2, uint64_t m2, uint64_t k)
{
    uint64_t t1;
    uint64_t t2;
    int64_t result;

    t1 = h1 * 60 + m1;
    t2 = h2 * 60 + m2;

    //@ assert t2 >= t1;
    //@ assert t2 - t1 <= 1440;
    //@ assert (int64_t)t2 - (int64_t)t1 - (int64_t)k <= 1440;

    result = (int64_t)t2 - (int64_t)t1 - (int64_t)k;
    return result;
}
