#include <stdint.h>

/*@
    predicate is_valid_input(integer a, integer b, integer c) =
        0 <= a && a <= 50 &&
        0 <= b && b <= 50 &&
        0 <= c && c <= 50;

    logic integer max_of_three(integer a, integer b, integer c) =
        (a >= b && a >= c) ? a :
        (b >= a && b >= c) ? b : c;

    lemma ans_range:
        \forall integer a, b, c;
        is_valid_input(a, b, c) ==>
        \let max = max_of_three(a, b, c);
        \let condition = (a + b + c - max >= max);
        (condition ==> 1 >= 0 && 1 <= 2) &&
        (!condition ==> 2 >= 0 && 2 <= 2);
*/

/*@
    requires is_valid_input(a, b, c);
    ensures \result >= 0 && \result <= 2;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t ans;
    uint32_t max;

    if (a >= b && a >= c)
    {
        max = a;
    }
    else if (b >= a && b >= c)
    {
        max = b;
    }
    else
    {
        max = c;
    }

    //@ assert max == max_of_three(a, b, c);

    if (a + b + c - max >= max)
    {
        ans = 1;
    }
    else
    {
        ans = 2;
    }

    return ans;
}
