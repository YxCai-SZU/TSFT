#include <stdint.h>

/*@
    predicate valid_time(integer h, integer m) =
        0 <= h <= 23 && 0 <= m <= 59;

    logic integer to_minutes(integer h, integer m) = h * 60 + m;

    lemma minutes_range:
        \forall integer h, m; valid_time(h, m) ==> 0 <= to_minutes(h, m) <= 1439;
*/

/*@
    requires valid_time(h1, m1);
    requires valid_time(h2, m2);
    requires k <= 1439;
    ensures \result == to_minutes(h2, m2) - to_minutes(h1, m1) - k;
*/
int32_t func(uint32_t h1, uint32_t m1, uint32_t h2, uint32_t m2, uint32_t k) {
    uint32_t start_minutes;
    uint32_t end_minutes;
    int32_t result;

    //@ assert valid_time(h1, m1);
    //@ assert valid_time(h2, m2);
    //@ assert k <= 1439;

    start_minutes = h1 * 60 + m1;
    end_minutes = h2 * 60 + m2;

    //@ assert start_minutes == to_minutes(h1, m1);
    //@ assert end_minutes == to_minutes(h2, m2);

    result = (int32_t)end_minutes - (int32_t)start_minutes - (int32_t)k;

    //@ assert result == to_minutes(h2, m2) - to_minutes(h1, m1) - k;
    return result;
}
