#include <stdbool.h>

/*@
    requires (1 <= (x) <= 100000 &&
        1 <= (y) <= 100000 &&
        1 <= (z) <= 100000 &&
        (y) + 2 * (z) <= (x));
    ensures \result >= 0 && \result <= x;
    assigns \nothing;
*/
int func(int x, int y, int z)
{
    int result = 0;
    int numerator = x - z;
    int denominator = y + z;

    /*@
        loop invariant 0 <= numerator <= x;
        loop invariant 0 <= result <= x;
        loop invariant result <= x - numerator;
        loop invariant (1 <= (x) <= 100000 &&
        1 <= (y) <= 100000 &&
        1 <= (z) <= 100000 &&
        (y) + 2 * (z) <= (x));
        loop assigns numerator, result;
    */
    while (numerator >= denominator)
    {
        //@ assert numerator >= denominator;
        numerator -= denominator;
        result += 1;
    }

    return result;
}
