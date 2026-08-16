#include <limits.h>

/*@
    predicate valid_time(integer h, integer m) =
        0 <= h <= 23 && 0 <= m <= 59;

    logic integer to_minutes(integer h, integer m) = h * 60 + m;

    lemma time_diff_lemma:
        \forall integer h1, m1, h2, m2, k;
        valid_time(h1, m1) && valid_time(h2, m2) && k >= 0 &&
        to_minutes(h1, m1) + k <= to_minutes(h2, m2) ==>
        to_minutes(h2, m2) - to_minutes(h1, m1) - k ==
        (h2 * 60 + m2) - (h1 * 60 + m1) - k;
*/

/*@
    requires 0 <= h1 <= 23;
    requires 0 <= m1 <= 59;
    requires 0 <= h2 <= 23;
    requires 0 <= m2 <= 59;
    requires k >= 0;
    requires (h1 * 60 + m1) + k <= (h2 * 60 + m2);
    ensures \result == (h2 * 60 + m2) - (h1 * 60 + m1) - k;
    assigns \nothing;
*/
int func(int h1, int m1, int h2, int m2, int k)
{
    int start_min;
    int end_min;
    int result;

    //@ assert valid_time(h1, m1);
    //@ assert valid_time(h2, m2);
    //@ assert to_minutes(h1, m1) + k <= to_minutes(h2, m2);

    start_min = h1 * 60 + m1;
    end_min = h2 * 60 + m2;

    //@ assert end_min - start_min - k == (h2 * 60 + m2) - (h1 * 60 + m1) - k;

    result = end_min - start_min - k;
    return result;
}
