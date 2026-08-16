#include <stdint.h>

/*@ predicate valid_time(integer h, integer m) =
        0 <= h && h <= 23 &&
        0 <= m && m <= 59;
*/

/*@ predicate time_order(integer h1, integer m1, integer h2, integer m2) =
        h1 * 60 + m1 <= h2 * 60 + m2;
*/

/*@ logic integer total_minutes(integer h, integer m) = h * 60 + m; */

/*@ lemma ans_nonnegative:
        \forall integer start, end, k, ans;
        start <= end && k >= 0 &&
        ans == (end - start - k > 0 ? end - start - k : 0) ==>
        ans >= 0;
*/

/*@ lemma ans_upper_bound:
        \forall integer start, end, k, ans;
        start <= end && k >= 0 &&
        ans == (end - start - k > 0 ? end - start - k : 0) ==>
        ans <= end - start;
*/

/*@
    requires valid_time(h1, m1) && valid_time(h2, m2);
    requires k >= 0;
    requires time_order(h1, m1, h2, m2);
    ensures \result >= 0;
    ensures \result <= total_minutes(h2, m2) - total_minutes(h1, m1);
*/
int64_t func(int64_t h1, int64_t m1, int64_t h2, int64_t m2, int64_t k)
{
    int64_t start;
    int64_t end;
    int64_t ans;

    //@ assert valid_time(h1, m1);
    //@ assert valid_time(h2, m2);
    //@ assert k >= 0;
    //@ assert time_order(h1, m1, h2, m2);

    start = h1 * 60 + m1;
    end = h2 * 60 + m2;

    //@ assert start == total_minutes(h1, m1);
    //@ assert end == total_minutes(h2, m2);
    //@ assert start <= end;

    if (end - start - k > 0) {
        ans = end - start - k;
    } else {
        ans = 0;
    }

    //@ assert ans >= 0;
    //@ assert ans <= end - start;

    return ans;
}
