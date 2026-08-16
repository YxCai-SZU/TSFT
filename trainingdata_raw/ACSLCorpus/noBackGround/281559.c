#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 10000);
    ensures \result == 1000 * ((n + 999) / 1000) - n;
    assigns \nothing;
*/
int func(int n)
{
    // Variable declarations at scope top
    int quotient = 0;
    int remainder = n + 999;
    const int divisor = 1000;
    int result;

    //@ assert (1 <= (n) && (n) <= 10000);
    //@ assert remainder == n + 999 && divisor == 1000;

    /*@
        loop invariant (0 <= (quotient) && 0 <= (remainder) && (remainder) == (n) + 999 - (quotient) * 1000 && (quotient) <= ((n) + 999) / 1000);
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        //@ assert remainder >= divisor;
        quotient += 1;
        remainder -= divisor;
        //@ assert remainder == n + 999 - quotient * divisor;
    }

    //@ assert quotient == (n + 999) / 1000;
    result = 1000 * quotient - n;
    //@ assert result == (1000 * (quotient) - (n));
    return result;
}
