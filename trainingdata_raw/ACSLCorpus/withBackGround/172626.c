#include <stdbool.h>

/*@
    predicate is_valid_range(integer x) =
        1 <= x <= 100000;

    logic integer manual_division(integer x, integer divisor) =
        x / divisor;

    logic integer manual_modulus(integer x, integer divisor) =
        x % divisor;

    lemma division_bound:
        \forall integer x, divisor;
            is_valid_range(x) && divisor == 200 ==>
            0 <= manual_division(x, divisor) <= 500;

    lemma modulus_bound:
        \forall integer x, divisor;
            is_valid_range(x) && divisor == 200 ==>
            0 <= manual_modulus(x, divisor) < 200;
*/

/*@
    requires is_valid_range(x);
    ensures \result == (x >= 2000 || x % 200 == 0);
    assigns \nothing;
*/
bool func(int x)
{
    int quotient = 0;
    int remainder = x;
    const int divisor = 200;

    /*@
        loop invariant 1 <= x <= 100000;
        loop invariant 0 <= quotient;
        loop invariant quotient <= x / divisor;
        loop invariant remainder == x - quotient * divisor;
        loop invariant 0 <= quotient * divisor <= 200 * 100000;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        //@ assert 0 <= quotient * divisor <= 200 * 100000;
        remainder -= divisor;
        quotient += 1;
    }

    if (x >= 2000 || remainder == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(void)
{
    return 0;
}
