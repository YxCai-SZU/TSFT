#include <stdbool.h>

/*@
    requires (1 <= (x) <= 100);
    ensures \result == ((x) * 50 / 100);
    assigns \nothing;
*/
int func(int x)
{
    int result;
    int quotient = 0;
    int remainder;
    int divisor = 100;

    //@ assert (1 <= (x) <= 100);
    result = x * 50;
    remainder = result;

    //@ assert 0 <= result <= 100 * 50;

    /*@
        loop invariant 1 <= x <= 100;
        loop invariant 0 <= quotient <= ((x) * 50 / 100);
        loop invariant remainder == ((x) * 50) - quotient * 100;
        loop invariant 0 <= remainder < 100 + ((x) * 50);
        loop invariant quotient <= ((x) * 50 / 100);
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        quotient += 1;
        remainder -= divisor;
    }

    //@ assert quotient == ((x) * 50 / 100);
    return quotient;
}
