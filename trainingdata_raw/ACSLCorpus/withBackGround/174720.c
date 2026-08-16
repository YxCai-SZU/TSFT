#include <limits.h>

/*@
    predicate valid_time(integer h, integer m) =
        0 <= h <= 23 && 0 <= m <= 59;

    logic integer total_minutes(integer h, integer m) = h * 60 + m;

    lemma time_bound_lemma:
        \forall integer h, m; valid_time(h, m) ==> total_minutes(h, m) <= 23 * 60 + 59;

    lemma diff_nonnegative_lemma:
        \forall integer h1, m1, h2, m2, k;
            valid_time(h1, m1) && valid_time(h2, m2) && k >= 0 &&
            total_minutes(h1, m1) <= total_minutes(h2, m2) - k ==>
            total_minutes(h2, m2) - total_minutes(h1, m1) - k >= 0;
*/

/*@
    requires valid_time(h1, m1);
    requires valid_time(h2, m2);
    requires k >= 0;
    requires total_minutes(h1, m1) <= total_minutes(h2, m2) - k;
    ensures \result == total_minutes(h2, m2) - total_minutes(h1, m1) - k;
    ensures \result >= 0;
*/
long func(long h1, long m1, long h2, long m2, long k) {
    long ans;

    //@ assert total_minutes(h2, m2) <= 23 * 60 + 59;
    //@ assert total_minutes(h1, m1) <= 23 * 60 + 59;
    //@ assert total_minutes(h2, m2) - total_minutes(h1, m1) >= 0;
    //@ assert total_minutes(h2, m2) - total_minutes(h1, m1) - k >= 0;

    ans = (h2 * 60 + m2) - (h1 * 60 + m1) - k;
    return ans;
}
