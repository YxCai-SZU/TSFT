#include <stdint.h>

/*@
    predicate valid_range(integer a, integer b, integer c) =
        1 <= b && b <= a && a <= 20 &&
        1 <= c && c <= 20;

    logic integer calculate_ans(integer min_val) =
        min_val + (min_val - 1) / 2;

    lemma ans_non_negative:
        \forall integer min_val; min_val >= 1 ==> calculate_ans(min_val) >= 0;
*/

/*@
    requires valid_range(a, b, c);
    ensures \result <= c;
    ensures \result >= 0;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t min_val;
    uint32_t ans;

    min_val = a;
    //@ assert min_val == a;

    if (b < min_val)
    {
        min_val = b;
    }
    //@ assert min_val <= a && min_val <= b;

    if (c < min_val)
    {
        min_val = c;
    }
    //@ assert min_val <= a && min_val <= b && min_val <= c;

    ans = min_val + (min_val - 1) / 2;
    //@ assert ans == calculate_ans(min_val);
    //@ assert ans >= 0;

    if (ans < c)
    {
        //@ assert ans < c;
        return ans;
    }
    else
    {
        //@ assert ans >= c;
        return c;
    }
}
