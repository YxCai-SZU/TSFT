#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100);
    ensures \result == ((a) * 800 - (a / 15) * 200);
    assigns \nothing;
*/
int func(int a)
{
    int quotient = 0;
    int remainder = a;
    int divisor = 15;
    int result;

    //@ ghost int original_a = a;

    /*@
        loop invariant (1 <= (original_a) && (original_a) <= 100);
        loop invariant (0 <= (quotient) && (quotient) <= (original_a) / (divisor) && (remainder) == (original_a) - (quotient) * (divisor) && 0 <= (remainder));
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        //@ assert remainder >= divisor;
        quotient += 1;
        remainder -= divisor;
    }

    //@ assert quotient == original_a / divisor;
    //@ assert remainder == original_a % divisor;

    result = a * 800 - quotient * 200;

    //@ assert 0 <= a * 800 <= 100 * 800;
    //@ assert 0 <= quotient * 200 <= 100 * 200;
    //@ assert a * 800 >= quotient * 200;
    //@ assert a * 800 - quotient * 200 <= 100 * 800;
    //@ assert result == ((a) * 800 - (quotient) * 200);

    return result;
}
