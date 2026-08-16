#include <stddef.h>

/*@
    requires (1 <= (x) && (x) <= 100000);
    ensures \result == (1000 * ((x) / 500) + 5 * (((x) % 500) / 5));
    assigns \nothing;
*/
size_t func(size_t x)
{
    size_t quotient_500;
    size_t remainder_500;
    size_t quotient_5;
    size_t remainder_5;
    size_t result;

    //@ assert (1 <= (x) && (x) <= 100000);

    quotient_500 = 0;
    remainder_500 = x;

    /*@
        loop invariant (0 <= (quotient_500) && (remainder_500) >= 0 && (remainder_500) == (x) - 500 * (quotient_500));
        loop invariant (1 <= (x) && (x) <= 100000);
        loop assigns quotient_500, remainder_500;
        loop variant remainder_500;
    */
    while (remainder_500 >= 500)
    {
        //@ assert remainder_500 == x - 500 * quotient_500;
        quotient_500 += 1;
        remainder_500 -= 500;
        //@ assert remainder_500 == x - 500 * quotient_500;
    }

    //@ assert remainder_500 == x - 500 * quotient_500;

    quotient_5 = 0;
    remainder_5 = remainder_500;

    /*@
        loop invariant (0 <= (quotient_5) && (remainder_5) >= 0 && (remainder_5) == (remainder_500) - 5 * (quotient_5));
        loop invariant (1 <= (x) && (x) <= 100000);
        loop assigns quotient_5, remainder_5;
        loop variant remainder_5;
    */
    while (remainder_5 >= 5)
    {
        //@ assert remainder_5 == remainder_500 - 5 * quotient_5;
        quotient_5 += 1;
        remainder_5 -= 5;
        //@ assert remainder_5 == remainder_500 - 5 * quotient_5;
    }

    //@ assert remainder_5 == remainder_500 - 5 * quotient_5;
    result = 1000 * quotient_500 + 5 * quotient_5;
    //@ assert result == (1000 * (quotient_500) + 5 * (quotient_5));
    //@ assert result == (1000 * ((x) / 500) + 5 * (((x) % 500) / 5));

    return result;
}
