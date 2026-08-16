#include <limits.h>

/*@
    requires (1 <= (x) <= 1000);
    ensures \result == ((x) / 3);
    assigns \nothing;
*/
int func(int x)
{
    int quotient = 0;
    int remainder;
    int divisor = 3;
    
    if (x < 0)
    {
        remainder = -x;
    }
    else
    {
        remainder = x;
    }
    
    /*@
        loop invariant 1 <= x <= 1000;
        loop invariant quotient >= 0;
        loop invariant remainder >= 0;
        loop invariant x < 0 ==> x == -(quotient * divisor + remainder);
        loop invariant x >= 0 ==> x == quotient * divisor + remainder;
        loop invariant 0 <= quotient * divisor + remainder <= 1000 * 3;
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
    
    //@ assert quotient * 3 + remainder == x;
    
    return quotient;
}
