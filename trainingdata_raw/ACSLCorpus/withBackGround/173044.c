#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    logic integer max_product(integer a, integer b, integer c, integer d) =
        (a * b > c * d) ? a * b : c * d;

    lemma product_bound:
        \forall integer a, b;
            valid_range(a) && valid_range(b) ==> a * b <= 10000 * 10000;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == a * b || \result == c * d;
    ensures \result >= a * b;
    ensures \result >= c * d;
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t c, uint64_t d)
{
    //@ assert a * b <= 10000 * 10000;
    //@ assert c * d <= 10000 * 10000;
    
    uint64_t result;
    
    if (a * b > c * d)
    {
        result = a * b;
    }
    else
    {
        result = c * d;
    }
    
    //@ assert result == a * b || result == c * d;
    //@ assert result >= a * b;
    //@ assert result >= c * d;
    
    return result;
}
