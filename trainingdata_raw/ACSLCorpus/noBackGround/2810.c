/*@
    requires (1 <= (x) && (x) <= 1000);
    ensures \result == x / 3;
    assigns \nothing;
*/
int func(int x)
{
    int quotient;
    int remainder;
    int divisor;
    
    quotient = 0;
    remainder = (x < 0) ? -x : x;
    divisor = 3;
    
    /*@
        loop invariant (0 <= (quotient) && (quotient) <= (x) / 3 && (remainder) == (x) - (quotient) * 3);
        loop invariant (1 <= (x) && (x) <= 1000);
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        //@ assert remainder >= 3;
        remainder -= divisor;
        quotient += 1;
        //@ assert remainder == x - quotient * 3;
    }
    
    //@ assert remainder < 3;
    //@ assert quotient == x / 3;
    
    if (x < 0)
    {
        quotient = -quotient;
    }
    
    return quotient;
}
