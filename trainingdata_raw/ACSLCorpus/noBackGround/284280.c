#include <limits.h>

/*@
    requires (1 <= (x) <= 1000);
    ensures \result == ((x) / 3);
    assigns \nothing;
*/
int func(int x)
{
    int quotient;
    int remainder;
    int divisor;
    int sign;
    int result;

    quotient = 0;
    remainder = (x < 0) ? -x : x;
    divisor = 3;
    sign = (x < 0) ? -1 : 1;

    /*@
        loop invariant (1 <= (x) <= 1000);
        loop invariant 0 <= remainder <= 1000;
        loop invariant 0 <= quotient <= x / 3;
        loop invariant remainder == x - quotient * divisor;
        loop assigns remainder, quotient;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        //@ assert remainder >= divisor;
        remainder -= divisor;
        quotient += 1;
        //@ assert remainder == x - quotient * divisor;
    }

    result = quotient * sign;
    //@ assert result == x / 3;
    return result;
}
