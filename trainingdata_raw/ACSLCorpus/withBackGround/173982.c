#include <stdint.h>

/*@
    predicate remainder_500_invariant(uint64_t x, uint64_t quotient_500, uint64_t remainder_500) =
        1 <= x <= 100000 &&
        0 <= quotient_500 &&
        0 <= remainder_500 <= x &&
        remainder_500 == x - 500 * quotient_500;

    predicate remainder_5_invariant(uint64_t x, uint64_t remainder_500, uint64_t quotient_5, uint64_t remainder_5) =
        1 <= x <= 100000 &&
        0 <= quotient_5 &&
        0 <= remainder_5 <= remainder_500 &&
        remainder_5 == remainder_500 - 5 * quotient_5;

    logic integer target_result(integer x) = (x / 500) * 1000 + ((x % 500) / 5) * 5;
*/

/*@
    requires 1 <= x <= 100000;
    ensures \result == target_result(x);
    assigns \nothing;
*/
uint64_t func(uint64_t x)
{
    uint64_t quotient_500;
    uint64_t remainder_500;
    uint64_t quotient_5;
    uint64_t remainder_5;
    uint64_t result;

    quotient_500 = 0;
    remainder_500 = x;

    /*@
        loop invariant remainder_500_invariant(x, quotient_500, remainder_500);
        loop assigns quotient_500, remainder_500;
        loop variant remainder_500;
    */
    while (remainder_500 >= 500)
    {
        remainder_500 -= 500;
        quotient_500 += 1;
        //@ assert remainder_500_invariant(x, quotient_500, remainder_500);
    }

    quotient_5 = 0;
    remainder_5 = remainder_500;

    /*@
        loop invariant remainder_5_invariant(x, remainder_500, quotient_5, remainder_5);
        loop assigns quotient_5, remainder_5;
        loop variant remainder_5;
    */
    while (remainder_5 >= 5)
    {
        remainder_5 -= 5;
        quotient_5 += 1;
        //@ assert remainder_5_invariant(x, remainder_500, quotient_5, remainder_5);
    }

    result = quotient_500 * 1000 + quotient_5 * 5;
    //@ assert result == target_result(x);
    return result;
}
