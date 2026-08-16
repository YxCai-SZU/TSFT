#include <limits.h>

/*@
    predicate time_in_range(integer h, integer m) =
        0 <= h <= 23 && 0 <= m <= 59;

    logic integer total_minutes(integer h, integer m) = h * 60 + m;

    lemma minutes_bound: \forall integer h, m;
        time_in_range(h, m) ==> total_minutes(h, m) <= 23 * 60 + 59;
*/

/*@
    requires time_in_range(h1, m1);
    requires time_in_range(h2, m2);
    requires 0 <= k <= 23 * 60 + 59;
    requires total_minutes(h1, m1) <= total_minutes(h2, m2);
    ensures \result == total_minutes(h2, m2) - total_minutes(h1, m1) - k;
    assigns \nothing;
*/
int func(int h1, int m1, int h2, int m2, int k)
{
    int t1;
    int t2;
    int ans;

    //@ assert total_minutes(h1, m1) <= 23 * 60 + 59;
    t1 = h1 * 60 + m1;

    //@ assert total_minutes(h2, m2) <= 23 * 60 + 59;
    t2 = h2 * 60 + m2;

    //@ assert total_minutes(h2, m2) - total_minutes(h1, m1) - k <= 23 * 60 + 59;
    ans = t2 - t1 - k;

    return ans;
}
