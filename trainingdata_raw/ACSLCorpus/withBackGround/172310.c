#include <limits.h>

/*@
    predicate valid_time(integer h, integer m) =
        0 <= h && h <= 23 && 0 <= m && m <= 59;

    predicate time_order(integer h1, integer m1, integer h2, integer m2) =
        (h1 < h2) || (h1 == h2 && m1 <= m2);

    logic integer total_minutes(integer h, integer m) = 60 * h + m;

    lemma ans_property:
        \forall integer h1, m1, h2, m2, k, t1, t2, ans;
        valid_time(h1, m1) && valid_time(h2, m2) && k >= 0 &&
        time_order(h1, m1, h2, m2) &&
        t1 == total_minutes(h1, m1) &&
        t2 == total_minutes(h2, m2) &&
        ans == t2 - t1 - k ==>
        (ans == 60 * (h2 - h1) + m2 - m1 - k || ans == 0);
*/

/*@
    requires valid_time(h1, m1);
    requires valid_time(h2, m2);
    requires k >= 0;
    requires time_order(h1, m1, h2, m2);
    ensures \result >= 0;
    ensures \result <= 60 * (h2 - h1) + m2 - m1;
    ensures \result == 60 * (h2 - h1) + m2 - m1 - k || \result == 0;
*/
int func(int h1, int m1, int h2, int m2, int k)
{
    int t1;
    int t2;
    int ans;
    int result;

    t1 = 60 * h1 + m1;
    t2 = 60 * h2 + m2;
    ans = t2 - t1 - k;

    //@ assert ans == 60 * (h2 - h1) + m2 - m1 - k || ans == 0;

    if (ans < 0)
    {
        result = 0;
    }
    else
    {
        result = ans;
    }

    return result;
}
