#include <limits.h>

/*@ predicate valid_time(integer h, integer m) =
      0 <= h < 24 && 0 <= m < 60;
*/

/*@ predicate time_order(integer h1, integer m1, integer h2, integer m2, integer k) =
      h1 * 60 + m1 <= h2 * 60 + m2 - k;
*/

/*@ lemma ans_bounds:
      \forall integer h1, m1, h2, m2, k;
        valid_time(h1, m1) && valid_time(h2, m2) && k >= 0 &&
        time_order(h1, m1, h2, m2, k) ==>
        0 <= (h2 - h1) * 60 + m2 - m1 - k <= 24 * 60 - 0 * 60 + 60 - 0 - 0;
*/

/*@ requires valid_time(h1, m1);
    @ requires valid_time(h2, m2);
    @ requires k >= 0;
    @ requires time_order(h1, m1, h2, m2, k);
    @ ensures \result == (h2 - h1) * 60 + m2 - m1 - k;
    @ assigns \nothing;
*/
int func(int h1, int m1, int h2, int m2, int k)
{
    int ans;

    //@ assert h1 * 60 + m1 <= h2 * 60 + m2 - k;
    //@ assert 0 <= (h2 - h1) * 60 + m2 - m1 - k <= 24 * 60 - 0 * 60 + 60 - 0 - 0;

    ans = (h2 - h1) * 60 + m2 - m1 - k;
    return ans;
}
