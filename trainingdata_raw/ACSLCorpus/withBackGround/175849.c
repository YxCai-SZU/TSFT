#include <stdint.h>

/*@
    predicate valid_time(integer h, integer m) =
        0 <= h < 24 && 0 <= m < 60;

    predicate time_order(integer h1, integer m1, integer h2, integer m2) =
        (h1 < h2) || (h1 == h2 && m1 <= m2);

    predicate sufficient_duration(integer h1, integer m1, integer h2, integer m2, integer k) =
        h2 * 60 + m2 - h1 * 60 - m1 >= k;

    logic integer minutes(integer h, integer m) = h * 60 + m;
*/

/*@
    requires valid_time(h1, m1);
    requires valid_time(h2, m2);
    requires k <= 24 * 60;
    requires time_order(h1, m1, h2, m2);
    requires sufficient_duration(h1, m1, h2, m2, k);
    ensures \result == minutes(h2, m2) - minutes(h1, m1) - k;
*/
int32_t func(uint32_t h1, uint32_t m1, uint32_t h2, uint32_t m2, uint32_t k)
{
    uint32_t start_min;
    uint32_t end_min;
    int32_t r;

    start_min = h1 * 60 + m1;
    end_min = h2 * 60 + m2;
    r = (int32_t)end_min - (int32_t)start_min - (int32_t)k;

    //@ assert start_min == minutes(h1, m1);
    //@ assert end_min == minutes(h2, m2);
    //@ assert r == (int32_t)(minutes(h2, m2) - minutes(h1, m1) - k);

    return r;
}
