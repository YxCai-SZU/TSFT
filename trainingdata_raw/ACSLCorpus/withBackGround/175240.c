#include <stdint.h>

/*@
    predicate bounds(integer x) = 1 <= x <= 100;

    logic integer min_sum_c(integer a, integer b, integer c) =
        a + b < c ? a + b : c;

    lemma min_sum_c_properties:
        \forall integer a, b, c;
            bounds(a) && bounds(b) && bounds(c) ==>
            min_sum_c(a, b, c) <= c &&
            min_sum_c(a, b, c) <= a + b &&
            (min_sum_c(a, b, c) == a + b || min_sum_c(a, b, c) == c);
*/

/*@
    requires bounds(a) && bounds(b) && bounds(c);
    ensures \result <= c;
    ensures \result <= a + b;
    ensures \result == a + b || \result == c;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t result;

    //@ assert bounds(a) && bounds(b) && bounds(c);
    //@ assert 1 <= a + b <= 200;
    //@ assert 1 <= c <= 100;

    if (a + b < c)
    {
        //@ assert a + b <= c;
        //@ assert a + b <= a + b;
        result = a + b;
    }
    else
    {
        //@ assert c <= c;
        //@ assert c <= a + b;
        result = c;
    }

    //@ assert result <= c;
    //@ assert result <= a + b;
    //@ assert result == a + b || result == c;

    return result;
}
