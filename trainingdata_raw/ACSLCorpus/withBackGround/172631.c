#include <limits.h>

/*@
    predicate valid_time(integer h, integer m) =
        0 <= h <= 23 && 0 <= m <= 59;

    logic integer total_minutes(integer h, integer m) = h * 60 + m;

    lemma time_order_lemma:
        \forall integer h1, m1, h2, m2;
        valid_time(h1, m1) && valid_time(h2, m2) ==>
        total_minutes(h1, m1) <= total_minutes(h2, m2) ==>
        total_minutes(h2, m2) - total_minutes(h1, m1) >= 0;
*/

/*@
    requires valid_time(h1, m1);
    requires valid_time(h2, m2);
    requires k >= 0;
    requires total_minutes(h1, m1) <= total_minutes(h2, m2);
    ensures \result == total_minutes(h2, m2) - total_minutes(h1, m1) - k;
    assigns \nothing;
*/
int func(int h1, int m1, int h2, int m2, int k)
{
    int start;
    int end;
    int ans;

    //@ assert valid_time(h1, m1);
    start = h1 * 60 + m1;
    //@ assert start == total_minutes(h1, m1);
    
    //@ assert valid_time(h2, m2);
    end = h2 * 60 + m2;
    //@ assert end == total_minutes(h2, m2);
    
    //@ assert start <= end;
    ans = end - start - k;
    //@ assert ans == total_minutes(h2, m2) - total_minutes(h1, m1) - k;
    
    return ans;
}
