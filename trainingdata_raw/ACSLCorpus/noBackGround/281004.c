#include <stdbool.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures \result == (a * b % 2 != 0);
    assigns \nothing;
*/
bool func(int a, int b)
{
    int product;
    bool is_odd;
    int abs_product;
    int remainder;

    //@ assert a >= 1 && a <= 10000;
    //@ assert b >= 1 && b <= 10000;
    //@ assert a * b <= 10000 * 10000;

    product = a * b;
    is_odd = false;
    abs_product = product;

    if (product < 0)
    {
        abs_product = -product;
    }

    remainder = abs_product;

    /*@
        loop invariant 0 <= remainder <= abs_product;
        loop invariant remainder <= a * b;
        loop invariant 1 <= a <= 10000;
        loop invariant 1 <= b <= 10000;
        loop invariant remainder % 2 == abs_product % 2;
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder >= 2)
    {
        remainder -= 2;
    }

    if (remainder == 1)
    {
        is_odd = true;
    }

    //@ assert is_odd ==> a * b % 2 != 0;
    //@ assert !is_odd ==> a * b % 2 == 0;

    return is_odd;
}
