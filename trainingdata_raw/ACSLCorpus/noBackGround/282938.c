#include <stdint.h>

/*@ requires (0 <= (X) && (X) <= 1000000000);
    ensures \result == (X / 500 * 1000) + ((X % 500) / 5 * 5);
*/
int64_t func(int64_t X)
{
    int64_t quotient_500 = 0;
    int64_t remainder_500 = X;
    int64_t quotient_5 = 0;
    int64_t remainder_5 = 0;

    /*@ loop invariant 0 <= quotient_500;
        loop invariant quotient_500 <= X / 500;
        loop invariant 0 <= remainder_500;
        loop invariant remainder_500 <= X;
        loop invariant remainder_500 == ((X) - (quotient_500) * 500);
        loop invariant (0 <= (X) && (X) <= 1000000000);
        loop assigns quotient_500, remainder_500;
        loop variant remainder_500;
    */
    while (remainder_500 >= 500)
    {
        //@ assert remainder_500 >= 500;
        quotient_500 = quotient_500 + 1;
        remainder_500 = remainder_500 - 500;
        //@ assert remainder_500 == ((X) - (quotient_500) * 500);
    }

    remainder_5 = remainder_500;

    /*@ loop invariant 0 <= quotient_5;
        loop invariant quotient_5 <= remainder_500 / 5;
        loop invariant 0 <= remainder_5;
        loop invariant remainder_5 <= remainder_500;
        loop invariant remainder_5 == ((remainder_500) - (quotient_5) * 5);
        loop invariant (0 <= (X) && (X) <= 1000000000);
        loop assigns quotient_5, remainder_5;
        loop variant remainder_5;
    */
    while (remainder_5 >= 5)
    {
        //@ assert remainder_5 >= 5;
        quotient_5 = quotient_5 + 1;
        remainder_5 = remainder_5 - 5;
        //@ assert remainder_5 == ((remainder_500) - (quotient_5) * 5);
    }

    return quotient_500 * 1000 + quotient_5 * 5;
}
