#include <limits.h>

/*@
    requires (1 <= (x) <= 10000);
    ensures \result == (x / 3) * 5;
    assigns \nothing;
*/
int func(int x)
{
    int quotient;
    int remainder;
    int divisor;
    int is_negative;
    int res;
    
    quotient = 0;
    remainder = x;
    divisor = 3;
    is_negative = 0;
    
    if (x < 0)
    {
        remainder = -remainder;
        is_negative = 1;
    }
    
    /*@
        loop invariant 1 <= x <= 10000;
        loop invariant quotient >= 0;
        loop invariant remainder >= 0;
        loop invariant remainder == x - divisor * quotient;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        remainder -= divisor;
        quotient += 1;
        //@ assert remainder == x - divisor * quotient;
    }
    
    if (is_negative)
    {
        quotient = -quotient;
    }
    
    res = quotient * 5;
    //@ assert res == (x / 3) * 5;
    return res;
}
