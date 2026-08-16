#include <stdint.h>

/*@
    predicate bounds(integer a, integer b, integer c) =
        0 <= a <= 1000000000 &&
        0 <= b <= 1000000000 &&
        0 <= c <= 1000000000;

    logic integer max_sum(integer a, integer b) = a + b + 1;

    lemma sum_in_u32_range:
        \forall integer a, b;
        bounds(a, b, 0) ==> max_sum(a, b) <= 4294967295;
*/

/*@
    requires bounds(a, b, c);
    ensures \result >= 0;
    ensures \result <= a + b + 1 + b;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t ans;

    //@ assert bounds(a, b, c);
    //@ assert max_sum(a, b) <= 4294967295;

    if (c <= a + b + 1)
    {
        if (a + b + 1 - c < b)
        {
            ans = b - (a + b + 1 - c);
        }
        else
        {
            ans = 0;
        }
    }
    else
    {
        ans = a + b + 1;
    }

    //@ assert ans >= 0;
    //@ assert ans <= a + b + 1 + b;
    return ans;
}
