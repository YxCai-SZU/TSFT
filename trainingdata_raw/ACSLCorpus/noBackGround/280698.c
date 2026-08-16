#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((2 * (n) * 3142) / 1000);
    assigns \nothing;
*/
int func(int n)
{
    // Variable declarations at top of scope
    int result;
    int quotient = 0;
    int remainder;
    const int divisor = 1000;

    // Precondition check
    //@ assert (1 <= (n) && (n) <= 100);

    // Overflow safety verification
    //@ assert 2 * n * 3142 <= 2 * 100 * 3142;

    result = 2 * n * 3142;
    remainder = result;

    /*@
        loop invariant (1 <= (n) && (n) <= 100);
        loop invariant result == 2 * n * 3142;
        loop invariant quotient * divisor + remainder == result;
        loop invariant 0 <= remainder < divisor + result;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        remainder -= divisor;
        quotient += 1;
    }

    // Post-verification of division properties
    //@ assert quotient * divisor + remainder == result;
    //@ assert quotient == result / 1000;
    //@ assert remainder == result % 1000;

    return quotient;
}
