#include <limits.h>

/*@
    requires (1 <= (x) && (x) <= 100);
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
        loop invariant 1 <= x && x <= 100;
        loop invariant 0 <= quotient;
        loop invariant quotient <= x / 3;
        loop invariant 0 <= remainder;
        loop invariant remainder <= x;
        loop invariant remainder + quotient * 3 == x;
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
    
    //@ assert quotient == x / 3;
    
    return quotient;
}
