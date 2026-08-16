#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 1000);
    ensures \result == n / 3;
    assigns \nothing;
*/
int func(int n)
{
    int quotient;
    int remainder;
    int divisor;
    bool is_negative;

    quotient = 0;
    remainder = n;
    divisor = 3;
    is_negative = false;

    if (n < 0)
    {
        remainder = -remainder;
        is_negative = true;
    }

    /*@
        loop invariant 1 <= n && n <= 1000;
        loop invariant quotient >= 0;
        loop invariant remainder >= 0;
        loop invariant remainder == n - quotient * divisor;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        remainder -= divisor;
        quotient += 1;
    }

    if (is_negative)
    {
        quotient = -quotient;
    }

    //@ assert quotient == n / 3;
    return quotient;
}
