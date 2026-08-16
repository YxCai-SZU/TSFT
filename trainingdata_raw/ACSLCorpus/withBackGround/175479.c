#include <stdint.h>

/*@
    predicate valid_time(integer h, integer m) =
        0 <= h <= 23 && 0 <= m <= 59;

    logic integer to_minutes(integer h, integer m) = h * 60 + m;

    lemma time_order:
        \forall integer h1, m1, h2, m2;
        valid_time(h1, m1) && valid_time(h2, m2) && to_minutes(h1, m1) <= to_minutes(h2, m2) ==>
        to_minutes(h2, m2) - to_minutes(h1, m1) >= 0;
*/

/*@
    requires
        0 <= h1 <= 23 && 0 <= m1 <= 59 &&
        0 <= h2 <= 23 && 0 <= m2 <= 59 &&
        0 <= k <= 23 * 60 + 59 &&
        h1 * 60 + m1 <= h2 * 60 + m2;
    ensures
        \result == (int32_t)(h2 * 60 + m2) - (int32_t)(h1 * 60 + m1) - (int32_t)k;
*/
int32_t func(uint32_t h1, uint32_t m1, uint32_t h2, uint32_t m2, uint32_t k)
{
    uint32_t t1;
    uint32_t t2;
    int32_t buf;

    t1 = h1 * 60 + m1;
    t2 = h2 * 60 + m2;
    //@ assert t1 <= t2;
    //@ assert t2 - t1 >= 0;
    //@ assert k <= 23 * 60 + 59;
    buf = (int32_t)t2 - (int32_t)t1 - (int32_t)k;
    //@ assert buf == (int32_t)(h2 * 60 + m2) - (int32_t)(h1 * 60 + m1) - (int32_t)k;
    return buf;
}
