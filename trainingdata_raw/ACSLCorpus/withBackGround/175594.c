#include <limits.h>

/*@
    predicate valid_time(integer h, integer m) =
        0 <= h <= 23 && 0 <= m <= 59;

    predicate time_order(integer h1, integer m1, integer h2, integer m2) =
        h1 < h2 || (h1 == h2 && m1 <= m2);

    logic integer time_diff(integer h1, integer m1, integer h2, integer m2) =
        (h2 - h1) * 60 + (m2 - m1);
*/

/*@
    requires valid_time(h1, m1);
    requires valid_time(h2, m2);
    requires time_order(h1, m1, h2, m2);
    requires 0 <= k <= 1439;
    ensures \result == time_diff(h1, m1, h2, m2) - k;
*/
int func(int h1, int m1, int h2, int m2, int k)
{
    int result;

    //@ assert time_diff(h1, m1, h2, m2) - k == time_diff(h1, m1, h2, m2) - k;
    result = (h2 - h1) * 60 + (m2 - m1) - k;
    return result;
}
