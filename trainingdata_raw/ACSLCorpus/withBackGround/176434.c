#include <limits.h>

/*@
    predicate valid_time(integer h, integer m) =
        0 <= h < 24 && 0 <= m < 60;

    predicate time_ordering(integer h1, integer m1, integer h2, integer m2) =
        h1 < h2 && m1 <= m2;

    logic integer time_difference(integer h1, integer m1, integer h2, integer m2, integer k) =
        (h2 - h1) * 60 + m2 - m1 - k;

    lemma hour_difference_bounds:
        \forall integer h1, h2;
        valid_time(h1, 0) && valid_time(h2, 0) && h1 < h2 ==>
        0 <= h2 - h1 <= 23;

    lemma minute_product_bounds:
        \forall integer h1, h2;
        valid_time(h1, 0) && valid_time(h2, 0) && h1 < h2 ==>
        0 <= (h2 - h1) * 60 <= 23 * 60;

    lemma total_difference_bounds:
        \forall integer h1, m1, h2, m2;
        valid_time(h1, m1) && valid_time(h2, m2) && time_ordering(h1, m1, h2, m2) ==>
        0 <= (h2 - h1) * 60 + m2 - m1 <= 23 * 60 + 60;
*/

/*@
    requires valid_time(h1, m1);
    requires valid_time(h2, m2);
    requires time_ordering(h1, m1, h2, m2);
    requires k >= 0;
    ensures \result == time_difference(h1, m1, h2, m2, k);
    assigns \nothing;
*/
int func(int h1, int m1, int h2, int m2, int k)
{
    // Variable declarations at scope top
    int result;

    //@ assert 0 <= h2 - h1 <= 23;
    //@ assert 0 <= (h2 - h1) * 60 <= 23 * 60;
    //@ assert 0 <= (h2 - h1) * 60 + m2 - m1 <= 23 * 60 + 60;
    
    result = (h2 - h1) * 60 + m2 - m1 - k;
    return result;
}
