#include <stdint.h>

/*@
    predicate valid_time(integer h, integer m) =
        0 <= h && h < 24 && 0 <= m && m < 60;

    logic integer total_minutes(integer h, integer m) = h * 60 + m;

    lemma time_diff_nonnegative:
        \forall integer h1, m1, h2, m2, k;
        valid_time(h1, m1) && valid_time(h2, m2) &&
        total_minutes(h2, m2) >= total_minutes(h1, m1) + k ==>
        total_minutes(h2, m2) - (total_minutes(h1, m1) + k) >= 0;
*/

/*@
    requires valid_time(h1, m1);
    requires valid_time(h2, m2);
    requires total_minutes(h2, m2) >= total_minutes(h1, m1) + k;
    ensures \result == total_minutes(h2, m2) - (total_minutes(h1, m1) + k);
*/
uint64_t func(uint64_t h1, uint64_t m1, uint64_t h2, uint64_t m2, uint64_t k) {
    // Variable declarations at scope top
    uint64_t time;

    //@ assert total_minutes(h2, m2) >= total_minutes(h1, m1) + k;
    
    time = h2 * 60 + m2 - (h1 * 60 + m1 + k);
    return time;
}
