#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result <= ((a) * 3 + (b));
*/
int func(int a, int b)
{
    int result;
    int quotient;
    int remainder;
    int divisor;

    result = a * 3 + b;
    quotient = 0;
    remainder = result;
    divisor = 2;

    /*@
        loop invariant (1 <= (a) <= 100 && 1 <= (b) <= 100);
        loop invariant 0 <= quotient <= ((a) * 3 + (b)) / 2;
        loop invariant remainder == ((a) * 3 + (b)) - 2 * quotient;
        loop invariant result == ((a) * 3 + (b));
        loop assigns quotient, remainder;
    */
    while (remainder >= divisor)
    {
        //@ assert remainder >= 2;
        remainder -= divisor;
        quotient += 1;
        //@ assert remainder == ((a) * 3 + (b)) - 2 * quotient;
    }

    result = quotient;
    //@ assert result >= 0;
    return result;
}
