#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    logic integer sum_two(integer x, integer y) = x + y;

    lemma sum_bound:
        \forall integer p, q;
        valid_range(p) && valid_range(q) ==> sum_two(p, q) <= 20000;
*/

/*@
    requires valid_range(p);
    requires valid_range(q);
    requires valid_range(r);
    ensures \result <= p + q + r;
    ensures \result == p + q || \result == q + r || \result == p + r;
    assigns \nothing;
*/
uint32_t func(uint32_t p, uint32_t q, uint32_t r)
{
    uint32_t a;
    uint32_t b;
    uint32_t c;
    uint32_t result;

    //@ assert valid_range(p);
    //@ assert valid_range(q);
    //@ assert valid_range(r);

    //@ assert sum_two(p, q) <= 20000;
    a = p + q;

    //@ assert sum_two(q, r) <= 20000;
    b = q + r;

    //@ assert sum_two(p, r) <= 20000;
    c = p + r;

    if (a < b)
    {
        if (a < c)
        {
            result = a;
        }
        else
        {
            result = c;
        }
    }
    else
    {
        if (b < c)
        {
            result = b;
        }
        else
        {
            result = c;
        }
    }

    //@ assert result <= p + q + r;
    //@ assert result == p + q || result == q + r || result == p + r;
    return result;
}
