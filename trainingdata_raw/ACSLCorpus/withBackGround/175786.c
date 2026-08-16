#include <stdint.h>

/*@
    predicate time_in_range(integer h, integer m) =
        0 <= h && h <= 23 && 0 <= m && m <= 59;

    predicate valid_time_pair(integer h1, integer m1, integer h2, integer m2) =
        time_in_range(h1, m1) && time_in_range(h2, m2) &&
        h1 * 60 + m1 <= h2 * 60 + m2;

    predicate k_in_range(integer k) =
        0 <= k && k <= 23 * 60 + 59;

    logic integer time_diff(integer h1, integer m1, integer h2, integer m2) =
        h2 * 60 + m2 - h1 * 60 - m1;

    lemma diff_non_negative:
        \forall integer h1, m1, h2, m2;
        valid_time_pair(h1, m1, h2, m2) ==> time_diff(h1, m1, h2, m2) >= 0;
*/

/*@
    requires time_in_range(h1, m1);
    requires time_in_range(h2, m2);
    requires k_in_range(k);
    requires valid_time_pair(h1, m1, h2, m2);
    ensures \result == time_diff(h1, m1, h2, m2) - k;
*/
int32_t func(uint32_t h1, uint32_t m1, uint32_t h2, uint32_t m2, uint32_t k)
{
    uint32_t x_u32;
    int32_t x_i32;

    //@ assert time_in_range(h1, m1);
    //@ assert time_in_range(h2, m2);
    //@ assert k_in_range(k);
    //@ assert valid_time_pair(h1, m1, h2, m2);
    
    x_u32 = (h2 * 60 + m2) - (h1 * 60 + m1);
    
    //@ assert x_u32 == time_diff(h1, m1, h2, m2);
    
    x_i32 = (int32_t)x_u32 - (int32_t)k;
    
    //@ assert x_i32 == time_diff(h1, m1, h2, m2) - k;
    
    return x_i32;
}
