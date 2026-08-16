#include <stdint.h>

/*@
    requires (0 <= (X) <= 1000000000);
    ensures \result == (((X) / 500 * 1000) + (((X) % 500) / 5 * 5));
    assigns \nothing;
*/
int64_t func(int64_t X)
{
    int64_t result = 0;
    int64_t temp = X;
    int64_t quotient_500 = 0;
    int64_t remainder_500 = 0;
    int64_t product_1000 = 0;
    int64_t quotient_5 = 0;
    int64_t remainder_5 = 0;
    int64_t product_5 = 0;

    /*@
        loop invariant 0 <= quotient_500;
        loop invariant 0 <= temp <= X;
        loop invariant temp == X - quotient_500 * 500;
        loop invariant (0 <= (X) <= 1000000000);
        loop assigns quotient_500, temp;
        loop variant temp;
    */
    while (temp >= 500)
    {
        quotient_500 += 1;
        temp -= 500;
    }
    remainder_500 = temp;

    product_1000 = quotient_500 * 1000;

    /*@
        loop invariant 0 <= quotient_5;
        loop invariant 0 <= remainder_500 <= X;
        loop invariant remainder_500 == X - quotient_500 * 500 - quotient_5 * 5;
        loop invariant (0 <= (X) <= 1000000000);
        loop assigns quotient_5, remainder_500;
        loop variant remainder_500;
    */
    while (remainder_500 >= 5)
    {
        quotient_5 += 1;
        remainder_500 -= 5;
    }

    product_5 = quotient_5 * 5;
    result = product_1000 + product_5;

    //@ assert result == (((X) / 500 * 1000) + (((X) % 500) / 5 * 5));
    return result;
}
