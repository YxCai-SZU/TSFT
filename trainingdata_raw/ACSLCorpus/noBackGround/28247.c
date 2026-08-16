#include <limits.h>

/*@
    requires (1 <= (x) <= 100);
    ensures \result == 3 * (x / 3);
    assigns \nothing;
*/
int func(int x)
{
    int quotient = 0;
    int remainder = x;
    int divisor = 3;

    /*@
        loop invariant 1 <= x <= 100;
        loop invariant 0 <= quotient;
        loop invariant quotient <= x / 3;
        loop invariant remainder == x - quotient * 3;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        //@ assert remainder >= divisor;
        remainder -= divisor;
        quotient += 1;
    }

    int result = quotient + quotient + quotient;
    
    //@ assert result == 3 * quotient;
    //@ assert quotient == x / 3;
    //@ assert result == 3 * (x / 3);
    
    return result;
}
