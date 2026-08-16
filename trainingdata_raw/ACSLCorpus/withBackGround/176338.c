#include <stdint.h>
#include <limits.h>

/*@
    predicate valid_time(integer h, integer m) =
        0 <= h <= 23 && 0 <= m <= 59;

    logic integer total_minutes(integer h, integer m) =
        h * 60 + m;

    lemma time_order:
        \forall integer h1, m1, h2, m2;
        valid_time(h1, m1) && valid_time(h2, m2) &&
        total_minutes(h1, m1) < total_minutes(h2, m2) ==>
        total_minutes(h2, m2) - total_minutes(h1, m1) >= 0;
*/

/*@
    requires valid_time(h1, m1) && valid_time(h2, m2);
    requires total_minutes(h1, m1) < total_minutes(h2, m2);
    requires 0 <= k <= 10000;
    ensures \result == total_minutes(h2, m2) - total_minutes(h1, m1) - k;
    assigns \nothing;
*/
int32_t func(uint32_t h1, uint32_t m1, uint32_t h2, uint32_t m2, uint32_t k)
{
    uint32_t t1;
    uint32_t t2;
    int32_t ans;

    t1 = h1 * 60 + m1;
    t2 = h2 * 60 + m2;

    //@ assert t1 < t2;
    //@ assert t2 - t1 >= 0;
    //@ assert t2 - t1 <= INT32_MAX;

    ans = (int32_t)(t2 - t1) - (int32_t)k;

    //@ assert ans == total_minutes(h2, m2) - total_minutes(h1, m1) - k;

    return ans;
}
