#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    logic integer total_sum(integer a, integer b, integer c, integer d) =
        a + b + c + d;

    lemma ans_non_negative:
        \forall integer a, c, ans;
        valid_range(a) && valid_range(c) && ans == a + c ==> ans >= 0;

    lemma ans_upper_bound:
        \forall integer a, c, ans, s;
        valid_range(a) && valid_range(c) && s == total_sum(a, 0, c, 0) &&
        ans == a + c ==> ans <= a + c;
*/

/*@
    requires valid_range(a);
    requires valid_range(b);
    requires valid_range(c);
    requires valid_range(d);
    ensures \result >= 0;
    ensures \result <= a + c;
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b, int32_t c, int32_t d)
{
    int32_t s;
    int32_t ans;

    s = a + b + c + d;
    ans = 0;

    if (s <= a)
    {
        ans += s;
    }
    else if (s <= a + c)
    {
        ans += a + c;
    }
    else
    {
        ans += a + c;
    }

    //@ assert ans >= 0;
    //@ assert ans <= a + c;

    return ans;
}
