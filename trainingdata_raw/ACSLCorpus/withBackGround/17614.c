#include <stdint.h>

/*@
    predicate time_in_range(integer h, integer m) =
        0 <= h && h <= 23 && 0 <= m && m <= 59;

    predicate valid_input(integer h1, integer m1, integer h2, integer m2, integer k) =
        time_in_range(h1, m1) &&
        time_in_range(h2, m2) &&
        0 <= k && k <= 1439 &&
        h1 * 60 + m1 <= h2 * 60 + m2;

    logic integer total_minutes(integer h, integer m) = h * 60 + m;

    lemma minutes_non_negative:
        \forall integer h, m; time_in_range(h, m) ==> total_minutes(h, m) >= 0;

    lemma start_le_end:
        \forall integer h1, m1, h2, m2;
            valid_input(h1, m1, h2, m2, 0) ==> total_minutes(h1, m1) <= total_minutes(h2, m2);
*/

/*@
    requires valid_input(h1, m1, h2, m2, k);
    ensures \result == total_minutes(h2, m2) - total_minutes(h1, m1) - k;
*/
int32_t func(uint32_t h1, uint32_t m1, uint32_t h2, uint32_t m2, uint32_t k)
{
    int32_t start;
    int32_t end;
    int32_t result;

    //@ assert time_in_range(h1, m1);
    //@ assert time_in_range(h2, m2);
    //@ assert 0 <= k && k <= 1439;
    //@ assert total_minutes(h1, m1) <= total_minutes(h2, m2);

    start = (int32_t)(h1 * 60 + m1);
    end = (int32_t)(h2 * 60 + m2);
    result = end - start - (int32_t)k;

    //@ assert result == total_minutes(h2, m2) - total_minutes(h1, m1) - k;
    return result;
}
