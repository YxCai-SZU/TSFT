#include <stdint.h>

/*@
    requires 1 <= a <= 100;
    requires 2 * 31415 * 1 <= 9223372036854775807 / 100;
    requires 2 * 31415 * 100 <= 9223372036854775807;
    ensures \result == 2 * 31415 * a / 10000;
*/
int64_t func(int64_t a)
{
    int64_t pi = 31415;
    int64_t two = 2;
    int64_t scale = 10000;
    int64_t product;
    int64_t result = 0;
    int64_t remainder;

    //@ assert (1 <= (a) <= 100 &&         2 * 31415 * 1 <= 9223372036854775807 / 100 &&         2 * 31415 * 100 <= 9223372036854775807);
    //@ assert (2 * 31415 * (a)) <= 9223372036854775807;

    product = two * pi * a;

    remainder = product;

    /*@
        loop invariant 1 <= a <= 100;
        loop invariant pi == 31415;
        loop invariant two == 2;
        loop invariant scale == 10000;
        loop invariant product == two * pi * a;
        loop invariant result * scale + remainder == product;
        loop invariant 0 <= remainder < scale + product;
        loop assigns result, remainder;
        loop variant remainder;
    */
    while (remainder >= scale)
    {
        result += 1;
        remainder -= scale;
    }

    //@ assert result * scale + remainder == product;
    //@ assert 0 <= result * scale + remainder <= 2 * 31415 * 100;

    return result;
}

int main()
{
    return 0;
}
