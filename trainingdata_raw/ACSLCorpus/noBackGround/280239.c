#include <stddef.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);
    assigns \nothing;
*/
size_t func(size_t x)
{
    size_t quotient_500 = 0;
    size_t remainder_500 = x;
    size_t quotient_5 = 0;
    size_t remainder_5 = 0;
    size_t result = 0;

    /*@
        loop invariant 1 <= x <= 100000;
        loop invariant 0 <= quotient_500;
        loop invariant 0 <= remainder_500;
        loop invariant remainder_500 == x - quotient_500 * 500;
        loop invariant quotient_500 <= x / 500;
        loop assigns quotient_500, remainder_500;
        loop variant remainder_500;
    */
    while (remainder_500 >= 500)
    {
        quotient_500 += 1;
        remainder_500 -= 500;
        //@ assert remainder_500 == x - quotient_500 * 500;
    }

    //@ assert quotient_500 == x / 500;
    //@ assert remainder_500 == x % 500;

    remainder_5 = remainder_500;

    /*@
        loop invariant 1 <= x <= 100000;
        loop invariant 0 <= quotient_5;
        loop invariant 0 <= remainder_5;
        loop invariant remainder_5 == remainder_500 - quotient_5 * 5;
        loop invariant quotient_5 <= remainder_500 / 5;
        loop assigns quotient_5, remainder_5;
        loop variant remainder_5;
    */
    while (remainder_5 >= 5)
    {
        quotient_5 += 1;
        remainder_5 -= 5;
        //@ assert remainder_5 == remainder_500 - quotient_5 * 5;
    }

    //@ assert quotient_5 == remainder_500 / 5;
    //@ assert remainder_5 == remainder_500 % 5;

    result = quotient_500 * 1000 + quotient_5 * 5;
    //@ assert result == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);
    return result;
}
