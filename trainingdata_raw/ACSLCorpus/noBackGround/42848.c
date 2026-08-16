/*@
    requires 1 <= x <= 10000;
    ensures \result >= 0;
    ensures \result * 2 <= x;
*/
int func(int x)
{
    int quotient = 0;
    int remainder;
    int divisor = 2;
    
    //@ assert 1 <= x <= 10000;
    
    if (x < 0)
    {
        remainder = -x;
    }
    else
    {
        remainder = x;
    }
    
    //@ assert remainder == ((x) < 0 ? -(x) : (x));
    //@ assert remainder >= 0;
    
    /*@
        loop invariant 1 <= x <= 10000;
        loop invariant quotient >= 0;
        loop invariant remainder >= 0;
        loop invariant remainder == x - 2 * quotient;
        loop assigns remainder, quotient;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        //@ assert remainder >= 2;
        remainder -= divisor;
        //@ assert remainder >= 0;
        quotient += 1;
        //@ assert quotient >= 0;
        //@ assert remainder == x - 2 * quotient;
    }
    
    //@ assert remainder == x - 2 * quotient;
    //@ assert remainder >= 0;
    //@ assert remainder < 2;
    
    if (x < 0)
    {
        //@ assert quotient >= 0;
        //@ assert -quotient <= 0;
        //@ assert (-quotient) * 2 <= x;
        return -quotient;
    }
    else
    {
        //@ assert quotient >= 0;
        //@ assert quotient * 2 <= x;
        return quotient;
    }
}
