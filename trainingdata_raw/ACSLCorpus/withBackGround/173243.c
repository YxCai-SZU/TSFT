#include <stdint.h>

/*@
    predicate bounds(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer compute_d(integer a, integer b) = b - a;

    lemma d_mult_bound:
        \forall integer a, b, d;
            bounds(a, b) && d == compute_d(a, b) ==> d * 8 < 1000000;
*/

/*@
    requires bounds(a, b);
    ensures \result >= 0 && \result < 1000000;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t d;
    uint32_t r;
    int32_t result;

    if (a > b)
    {
        return 0;
    }
    else if (a == b)
    {
        return 1;
    }
    else
    {
        d = b - a;
        //@ assert d == compute_d(a, b);
        //@ assert d * 8 < 1000000;
        r = d * 8;
        result = (int32_t)r;
        if (b < 10)
        {
            result += 100 * (int32_t)(10 - b);
        }
        return result;
    }
}
