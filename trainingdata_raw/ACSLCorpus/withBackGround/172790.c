/*@
    predicate is_even(integer x) = (x / 2) * 2 == x;
    
    lemma division_property: \forall integer x, d; 
        x >= 0 && d > 0 ==> x - d * (x / d) >= 0 && x - d * (x / d) < d;
*/

/*@
    requires 1 <= x <= 100;
    ensures \result == (x % 2 == 0);
    assigns \nothing;
*/
int func(int x)
{
    int quotient;
    int remainder;
    int divisor;
    int result;
    
    quotient = 0;
    remainder = (x < 0) ? -x : x;
    divisor = 2;
    
    /*@
        loop invariant 0 <= remainder <= 100;
        loop invariant quotient >= 0;
        loop invariant remainder == x - divisor * quotient;
        loop invariant 1 <= x <= 100;
        loop assigns remainder, quotient;
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
    
    result = (quotient * 2 == x);
    
    //@ assert result == (x % 2 == 0);
    return result;
}
