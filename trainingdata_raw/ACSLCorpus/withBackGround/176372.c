/*@
    predicate divisor_positive(integer divisor) = divisor > 0;
    predicate remainder_nonnegative(integer remainder) = remainder >= 0;
    predicate x_in_range(integer x) = 1 <= x && x <= 10000;
    predicate quotient_nonnegative(integer quotient) = quotient >= 0;
    predicate quotient_bound(integer quotient, integer x) = quotient <= (x + 1000 - 1) / 1000;
    predicate remainder_relation(integer remainder, integer quotient, integer x) = remainder == x + 1000 - 1 - quotient * 1000;
    
    lemma quotient_mul_nonnegative: \forall integer quotient, divisor; quotient >= 0 && divisor > 0 ==> quotient * divisor >= 0;
*/

/*@
    requires 1 <= x <= 10000;
    ensures \result >= 0;
    ensures \result < 1000;
    ensures (x + \result) % 1000 == 0;
    assigns \nothing;
*/
int func(int x)
{
    int quotient = 0;
    int remainder = x + 1000 - 1;
    int divisor = 1000;
    
    //@ assert divisor_positive(divisor);
    //@ assert remainder_nonnegative(remainder);
    //@ assert x_in_range(x);
    //@ assert quotient_nonnegative(quotient);
    //@ assert quotient_bound(quotient, x);
    //@ assert remainder_relation(remainder, quotient, x);
    
    /*@
        loop invariant x_in_range(x);
        loop invariant quotient_nonnegative(quotient);
        loop invariant quotient_bound(quotient, x);
        loop invariant remainder_relation(remainder, quotient, x);
        loop invariant remainder_nonnegative(remainder);
        loop invariant divisor_positive(divisor);
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        remainder -= divisor;
        quotient += 1;
        
        //@ assert remainder_relation(remainder, quotient, x);
    }
    
    int result = quotient * 1000 - x;
    return result;
}
