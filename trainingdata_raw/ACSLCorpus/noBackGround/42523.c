#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result >= 0 && \result <= a * 100 + b;
*/
int func(int a, int b)
{
    int result;
    int quotient;
    int remainder;

    result = a * 100 + b;
    quotient = 0;
    remainder = result;

    /*@
        loop invariant 0 <= quotient;
        loop invariant 0 <= remainder;
        loop invariant remainder == result - quotient * 108;
        loop invariant result <= a * 100 + b;
        loop assigns quotient, remainder;
    */
    while (remainder >= 108)
    {
        remainder -= 108;
        quotient += 1;
    }

    result = quotient * 108;

    //@ assert result >= 0 && result <= a * 100 + b;

    return result;
}
