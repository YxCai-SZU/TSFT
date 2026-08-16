#include <stdbool.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures \result == (a * b % 2 == 0);
    assigns \nothing;
*/
bool func(int a, int b)
{
    bool is_even = false;
    int product;
    int product_unsigned;
    int remainder;

    //@ assert 1 <= a * b <= 10000 * 10000;
    product = a * b;

    if (product < 0)
    {
        product_unsigned = -product;
    }
    else
    {
        product_unsigned = product;
    }

    remainder = product_unsigned;
    /*@
        loop invariant 0 <= remainder <= product_unsigned;
        loop invariant remainder % 2 == product_unsigned % 2;
        loop invariant product_unsigned == a * b || product_unsigned == -(a * b);
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder >= 2)
    {
        remainder -= 2;
    }

    if (remainder == 0)
    {
        is_even = true;
    }

    //@ assert is_even == (a * b % 2 == 0);
    return is_even;
}
