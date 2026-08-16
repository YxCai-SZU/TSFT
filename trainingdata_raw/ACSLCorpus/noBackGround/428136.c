#include <limits.h>

/*@
    requires (1 <= (a) <= 10000);
    ensures \result == a / 3;
    assigns \nothing;
*/
int func(int a)
{
    int quotient = 0;
    int remainder;
    int divisor = 3;
    
    //@ assert (1 <= (a) <= 10000);
    
    if (a < 0)
    {
        remainder = -a;
    }
    else
    {
        remainder = a;
    }
    
    //@ assert remainder == ((a) < 0 ? -(a) : (a));
    //@ assert remainder >= 0;
    
    /*@
        loop invariant 1 <= a <= 10000;
        loop invariant quotient >= 0;
        loop invariant remainder >= 0;
        loop invariant remainder == a - quotient * 3;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        remainder -= divisor;
        quotient += 1;
    }
    
    //@ assert 0 <= remainder < 3;
    
    if (a < 0)
    {
        quotient = -quotient;
    }
    
    //@ assert quotient == a / 3;
    
    return quotient;
}
