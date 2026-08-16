#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer div(integer a, integer b) = b / a;

    lemma ans_definition: \forall integer a, b; valid_range(a) && valid_range(b) ==> div(a, b) == b / a;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result <= c;
    ensures \result <= b / a;
    ensures \result == c || \result == b / a;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t ans;
    ans = b / a;

    //@ assert ans == b / a;

    if (c < ans)
    {
        return c;
    }
    else
    {
        //@ assert ans == b / a;
        return ans;
    }
}
