#include <stdint.h>

/*@
    predicate is_valid_range(integer x) =
        1 <= x <= 100000000000000;

    logic integer manual_division(integer x, integer divisor) =
        x / divisor;

    lemma division_property:
        \forall integer x, divisor;
        is_valid_range(x) && divisor == 11 ==>
        manual_division(x, divisor) >= 0;

    lemma remainder_property:
        \forall integer x, divisor, quotient, remainder;
        is_valid_range(x) && divisor == 11 &&
        0 <= quotient <= manual_division(x, divisor) &&
        remainder == x - quotient * divisor ==>
        remainder >= 0;
*/

/*@
    requires is_valid_range(x);
    ensures \result >= 0;
    ensures \result <= 2 * (x / 11) + 2;
*/
int64_t func(int64_t x)
{
    int64_t quotient;
    int64_t remainder;
    int64_t divisor;
    int64_t result;

    quotient = 0;
    remainder = x;
    divisor = 11;

    /*@
        loop invariant 1 <= x <= 100000000000000;
        loop invariant 0 <= quotient <= x / divisor;
        loop invariant remainder == x - quotient * divisor;
        loop invariant remainder >= 0;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        remainder -= divisor;
        quotient += 1;
    }

    result = quotient * 2;

    if (remainder > 0)
    {
        //@ assert remainder > 0;
        if (remainder > 6)
        {
            result += 2;
        }
        else
        {
            result += 1;
        }
    }

    //@ assert result >= 0;
    //@ assert result <= 2 * (x / 11) + 2;

    return result;
}

int main()
{
    return 0;
}
