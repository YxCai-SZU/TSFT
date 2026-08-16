#include <stdint.h>

/*@
    requires (0 <= (x) <= 1000000000);
    ensures \result == ((((x)) / 500) * 1000 + (((((x)) % 500)) / 5) * 5);
    assigns \nothing;
*/
int64_t func(int64_t x)
{
    int64_t result = 0;
    int64_t temp_x = x;
    int64_t quotient_500 = 0;
    int64_t remainder_500 = x;
    int64_t quotient_5 = 0;
    int64_t remainder_5 = 0;
    int64_t result_500 = 0;
    int64_t result_5 = 0;

    /*@
        loop invariant 0 <= quotient_500;
        loop invariant quotient_500 <= x / 500;
        loop invariant remainder_500 == x - quotient_500 * 500;
        loop invariant 0 <= remainder_500 < 500 + x;
        loop assigns quotient_500, remainder_500;
        loop variant remainder_500;
    */
    while (remainder_500 >= 500)
    {
        //@ assert remainder_500 >= 500;
        quotient_500 = quotient_500 + 1;
        remainder_500 = remainder_500 - 500;
    }

    remainder_5 = remainder_500;

    /*@
        loop invariant 0 <= quotient_5;
        loop invariant quotient_5 <= remainder_500 / 5;
        loop invariant remainder_5 == remainder_500 - quotient_5 * 5;
        loop invariant 0 <= remainder_5 < 5 + remainder_500;
        loop assigns quotient_5, remainder_5;
        loop variant remainder_5;
    */
    while (remainder_5 >= 5)
    {
        //@ assert remainder_5 >= 5;
        quotient_5 = quotient_5 + 1;
        remainder_5 = remainder_5 - 5;
    }

    result_500 = quotient_500 * 1000;
    result_5 = quotient_5 * 5;

    //@ assert result_500 == ((x) / 500) * 1000;
    //@ assert result_5 == ((((x) % 500)) / 5) * 5;

    if (result_500 >= 0 && result_5 >= 0)
    {
        if (result_500 + result_5 < result_500)
        {
            result = result_500 + result_5;
        }
        else
        {
            result = result_500 + result_5;
        }
    }
    else if (result_500 < 0 && result_5 < 0)
    {
        if (result_500 + result_5 > result_500)
        {
            result = result_500 + result_5;
        }
        else
        {
            result = result_500 + result_5;
        }
    }
    else
    {
        result = result_500 + result_5;
    }

    //@ assert result == ((((x)) / 500) * 1000 + (((((x)) % 500)) / 5) * 5);
    return result;
}
