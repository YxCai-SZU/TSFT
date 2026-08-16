#include <stdbool.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (2 * 314159 * (r) / 100000);
    assigns \nothing;
*/
int func(int r)
{
    int pi;
    int ans;
    int quotient;
    int remainder;
    int divisor;

    pi = 314159;
    ans = 2 * pi * r;
    quotient = 0;
    remainder = ans;
    divisor = 100000;

    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == 314159;
        loop invariant ans == 2 * pi * r;
        loop invariant quotient * divisor + remainder == ans;
        loop invariant 0 <= remainder < divisor + ans;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        //@ assert remainder >= divisor;
        quotient += 1;
        remainder -= divisor;
    }

    //@ assert quotient == (2 * 314159 * (r) / 100000);
    return quotient;
}
