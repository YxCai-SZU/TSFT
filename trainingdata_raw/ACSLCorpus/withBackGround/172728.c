#include <limits.h>

/*@
    predicate valid_time(integer h, integer m) =
        0 <= h <= 23 && 0 <= m <= 59;

    logic integer time_to_minutes(integer h, integer m) = h * 60 + m;

    lemma time_diff_nonnegative:
        \forall integer h1, m1, h2, m2, k;
        valid_time(h1, m1) && valid_time(h2, m2) &&
        0 <= k <= 60 &&
        time_to_minutes(h1, m1) <= time_to_minutes(h2, m2) - k ==>
        time_to_minutes(h2, m2) - k - time_to_minutes(h1, m1) >= 0;

    lemma time_diff_bound:
        \forall integer h1, m1, h2, m2, k;
        valid_time(h1, m1) && valid_time(h2, m2) &&
        0 <= k <= 60 &&
        time_to_minutes(h1, m1) <= time_to_minutes(h2, m2) - k ==>
        time_to_minutes(h2, m2) - k - time_to_minutes(h1, m1) <= 60 * 24;
*/

/*@
    requires valid_time(h1, m1);
    requires valid_time(h2, m2);
    requires 0 <= k <= 60;
    requires time_to_minutes(h1, m1) <= time_to_minutes(h2, m2) - k;
    ensures \result >= 0;
    ensures \result <= 60 * 24;
    ensures \result == time_to_minutes(h2, m2) - k - time_to_minutes(h1, m1);
*/
int func(int h1, int m1, int h2, int m2, int k)
{
    int t1;
    int t2;
    int result;

    t1 = h1 * 60 + m1;
    t2 = h2 * 60 + m2;

    //@ assert t1 <= t2 - k;

    if (t1 < t2 - k)
    {
        result = t2 - t1 - k;
    }
    else
    {
        result = 0;
    }

    //@ assert result >= 0;
    //@ assert result <= 60 * 24;
    //@ assert result == t2 - k - t1;

    return result;
}
