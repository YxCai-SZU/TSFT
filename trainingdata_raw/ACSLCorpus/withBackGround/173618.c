#include <limits.h>

/*@
    predicate is_valid_range(integer x) = 1 <= x <= 1000;
    
    logic integer absolute_value(integer x) = x < 0 ? -x : x;
    
    lemma quotient_bounds:
        \forall integer x, q, r, d;
        is_valid_range(x) && d == 3 && r == absolute_value(x) &&
        0 <= q && q <= x / 3 && r == x - q * d ==>
        0 <= q * 3 <= 1000;
*/

/*@
    requires is_valid_range(x);
    ensures \result >= 0;
    ensures \result * 3 <= x;
    ensures x < (\result + 1) * 3;
    assigns \nothing;
*/
int func(int x)
{
    int quotient;
    int remainder;
    int divisor;
    
    quotient = 0;
    divisor = 3;
    
    //@ assert is_valid_range(x);
    remainder = (x < 0) ? -x : x;
    
    /*@
        loop invariant 0 <= quotient;
        loop invariant quotient <= x / 3;
        loop invariant remainder == x - quotient * divisor;
        loop invariant is_valid_range(x);
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        remainder -= divisor;
        quotient += 1;
    }
    
    if (x < 0)
    {
        quotient = -quotient;
    }
    
    //@ assert 0 <= quotient * 3 <= 1000;
    
    return quotient;
}
