#include <limits.h>

/*@
    predicate valid_time(integer h, integer m) =
        h >= 0 && h < 24 && m >= 0 && m < 60;

    logic integer total_minutes(integer h, integer m) = h * 60 + m;

    lemma ans_lower_bound:
        \forall integer h1, m1, h2, m2, k, start, end, ans;
        valid_time(h1, m1) && valid_time(h2, m2) && k >= 0 &&
        start == total_minutes(h1, m1) &&
        end == total_minutes(h2, m2) &&
        ans == end - start - k ==>
        ans >= -k - 1440;

    lemma ans_upper_bound:
        \forall integer h1, m1, h2, m2, k, start, end, ans;
        valid_time(h1, m1) && valid_time(h2, m2) && k >= 0 &&
        start == total_minutes(h1, m1) &&
        end == total_minutes(h2, m2) &&
        ans == end - start - k ==>
        ans <= total_minutes(h2, m2) - total_minutes(h1, m1);
*/

/*@
    requires valid_time(h1, m1);
    requires valid_time(h2, m2);
    requires k >= 0;
    requires h1 < h2 || (h1 == h2 && m1 <= m2);
    ensures \result >= -k - 1440;
    ensures \result <= h2 * 60 + m2 - h1 * 60 - m1;
    assigns \nothing;
*/
int func(int h1, int m1, int h2, int m2, int k)
{
    int start;
    int end;
    int ans;

    //@ assert valid_time(h1, m1);
    //@ assert valid_time(h2, m2);
    //@ assert k >= 0;
    //@ assert h1 < h2 || (h1 == h2 && m1 <= m2);

    start = h1 * 60 + m1;
    end = h2 * 60 + m2;
    ans = end - start - k;

    //@ assert ans >= -k - 1440;
    //@ assert ans <= h2 * 60 + m2 - h1 * 60 - m1;

    return ans;
}
