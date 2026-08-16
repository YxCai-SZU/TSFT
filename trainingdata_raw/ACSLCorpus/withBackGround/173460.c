#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer safe_div(integer b, integer a) = b / a;

    lemma safe_div_bound: \forall integer a, b; 
        valid_range(a) && valid_range(b) ==> safe_div(b, a) <= 100;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result <= c;
    ensures \result == c || \result == safe_div(b, a);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t result;

    //@ assert valid_range(a) && valid_range(b) && valid_range(c);
    //@ assert safe_div(b, a) <= 100;

    if (c < b / a)
    {
        result = c;
    }
    else
    {
        result = b / a;
    }

    //@ assert result <= c;
    //@ assert result == c || result == safe_div(b, a);
    return result;
}
