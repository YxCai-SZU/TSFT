/*@
    requires (1 <= (n) && (n) <= 1000);
    ensures \result == ((n) / 3);
    assigns \nothing;
*/
int func(int n)
{
    int quotient = 0;
    int remainder = n;
    int divisor = 3;
    
    /*@
        loop invariant 0 <= quotient;
        loop invariant quotient <= ((n) / 3);
        loop invariant remainder == n - quotient * divisor;
        loop invariant remainder >= 0;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        //@ assert remainder >= divisor;
        quotient += 1;
        remainder -= divisor;
        //@ assert remainder == n - quotient * divisor;
    }
    
    //@ assert quotient == ((n) / 3);
    return quotient;
}
