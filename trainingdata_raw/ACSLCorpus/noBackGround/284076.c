#include <stdint.h>
#include <stdbool.h>

/*@
    requires (\valid((input)) &&
        (input)[0] >= 1 && (input)[0] <= 100 &&
        (input)[1] >= 1 && (input)[1] <= 20 &&
        (input)[2] >= 1 && (input)[2] <= 2000);
    ensures \result >= 0;
    ensures \result <= input[2];
    ensures \result == input[0] * input[1] || \result == input[2];
    assigns \nothing;
*/
int64_t func(int64_t *input)
{
    int64_t a;
    int64_t b;
    int64_t x;
    int64_t product;
    int64_t result;

    a = input[0];
    b = input[1];
    x = input[2];

    //@ assert a >= 1 && a <= 100;
    //@ assert b >= 1 && b <= 20;
    //@ assert x >= 1 && x <= 2000;

    //@ assert ((a) * (b)) <= 2000;

    product = a * b;

    if (product < x)
    {
        result = product;
    }
    else
    {
        result = x;
    }

    //@ assert result >= 0;
    //@ assert result <= x;
    //@ assert result == product || result == x;

    return result;
}
