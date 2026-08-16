#include <stdint.h>

/*@
    predicate valid_time(integer h, integer m) =
        0 <= h && h <= 23 && 0 <= m && m <= 59;

    predicate time_increasing(integer h1, integer m1, integer h2, integer m2) =
        h2 > h1 || (h1 == h2 && m2 > m1);

    predicate no_overflow(integer h1, integer m1, integer h2, integer m2, integer k) =
        h1 * 60 + m1 + k <= h2 * 60 + m2;

    logic integer total_minutes(integer h, integer m) = h * 60 + m;

    lemma time_order_lemma:
        \forall integer h1, m1, h2, m2;
            valid_time(h1, m1) && valid_time(h2, m2) && time_increasing(h1, m1, h2, m2) ==>
            total_minutes(h1, m1) <= total_minutes(h2, m2);

    lemma result_nonnegative_lemma:
        \forall integer h1, m1, h2, m2, k;
            valid_time(h1, m1) && valid_time(h2, m2) &&
            time_increasing(h1, m1, h2, m2) &&
            no_overflow(h1, m1, h2, m2, k) ==>
            total_minutes(h2, m2) - total_minutes(h1, m1) - k >= 0;
*/

/*@
    requires valid_time(h1, m1);
    requires valid_time(h2, m2);
    requires time_increasing(h1, m1, h2, m2);
    requires no_overflow(h1, m1, h2, m2, k);
    ensures \result == total_minutes(h2, m2) - total_minutes(h1, m1) - k;
*/
int32_t func(uint32_t h1, uint32_t m1, uint32_t h2, uint32_t m2, uint32_t k)
{
    uint32_t t1;
    uint32_t t2;
    int32_t ans;

    //@ assert valid_time(h1, m1);
    //@ assert valid_time(h2, m2);
    //@ assert time_increasing(h1, m1, h2, m2);
    //@ assert no_overflow(h1, m1, h2, m2, k);

    t1 = h1 * 60 + m1;
    t2 = h2 * 60 + m2;

    //@ assert t1 <= t2;
    //@ assert t2 - t1 - k >= 0;

    ans = (int32_t)t2 - (int32_t)t1 - (int32_t)k;

    //@ assert ans == total_minutes(h2, m2) - total_minutes(h1, m1) - k;

    return ans;
}
