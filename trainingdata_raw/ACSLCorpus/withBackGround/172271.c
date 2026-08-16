#include <stdint.h>

/*@ predicate valid_time(integer h, integer m) =
    h >= 0 && h < 24 && m >= 0 && m < 60;
*/

/*@ predicate valid_k(integer k) =
    k >= 0 && k < 24 * 60;
*/

/*@ predicate time_leq(integer h1, integer m1, integer h2, integer m2, integer k) =
    h1 * 60 + m1 <= h2 * 60 + m2 - k;
*/

/*@ logic integer total_minutes(integer h, integer m) =
    h * 60 + m;
*/

/*@ lemma subtraction_safe:
    \forall integer h1, m1, h2, m2, k;
    valid_time(h1, m1) && valid_time(h2, m2) && valid_k(k) && time_leq(h1, m1, h2, m2, k) ==>
    total_minutes(h2, m2) >= total_minutes(h1, m1) && 
    total_minutes(h2, m2) - total_minutes(h1, m1) >= k;
*/

/*@
    requires valid_time(h1, m1);
    requires valid_time(h2, m2);
    requires valid_k(k);
    requires time_leq(h1, m1, h2, m2, k);
    ensures \result == total_minutes(h2, m2) - total_minutes(h1, m1) - k;
    assigns \nothing;
*/
int32_t func(int32_t h1, int32_t m1, int32_t h2, int32_t m2, int32_t k) {
    int32_t start;
    int32_t end;
    int32_t ans;
    
    start = h1 * 60 + m1;
    end = h2 * 60 + m2;
    
    //@ assert start == total_minutes(h1, m1);
    //@ assert end == total_minutes(h2, m2);
    //@ assert end >= start;
    //@ assert end - start >= k;
    
    ans = end - start - k;
    
    //@ assert ans == total_minutes(h2, m2) - total_minutes(h1, m1) - k;
    return ans;
}
