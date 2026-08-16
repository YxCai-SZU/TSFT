#include <stdint.h>

/*@
    requires (1 <= (x) && (x) <= 100000);
    ensures \result == ((x / 500) * 1000 + ((x % 500) / 5) * 5);
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    uint32_t quotient_500;
    uint32_t remainder_500;
    uint32_t quotient_5;
    uint32_t remainder_5;
    uint32_t ans;

    quotient_500 = 0;
    remainder_500 = x;

    /*@
        loop invariant (1 <= (x) && (x) <= 100000);
        loop invariant (0 <= (quotient_500) && 0 <= (remainder_500) && (remainder_500) == (x) - 500 * (quotient_500));
        loop assigns quotient_500, remainder_500;
        loop variant remainder_500;
    */
    while (remainder_500 >= 500)
    {
        //@ assert remainder_500 == x - 500 * quotient_500;
        quotient_500 += 1;
        remainder_500 -= 500;
    }

    quotient_5 = 0;
    remainder_5 = remainder_500;

    /*@
        loop invariant (1 <= (x) && (x) <= 100000);
        loop invariant (0 <= (quotient_5) && 0 <= (remainder_5) && (remainder_5) == (remainder_500) - 5 * (quotient_5));
        loop assigns quotient_5, remainder_5;
        loop variant remainder_5;
    */
    while (remainder_5 >= 5)
    {
        //@ assert remainder_5 == remainder_500 - 5 * quotient_5;
        quotient_5 += 1;
        remainder_5 -= 5;
    }

    ans = quotient_500 * 1000 + quotient_5 * 5;
    //@ assert ans == ((quotient_500) * 1000 + (quotient_5) * 5);
    return ans;
}
