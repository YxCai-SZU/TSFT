#include <limits.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result == ((a) * (b)) || \result == ((a) * (b)) - 1;
*/
int func(int a, int b)
{
    int product;
    int result;
    int is_odd;
    int abs_product;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100);
    product = a * b;
    result = product;
    is_odd = 0;
    abs_product = product;

    if (product < 0)
    {
        abs_product = -product;
    }

    /*@
        loop invariant 0 <= abs_product <= ((a) * (b));
        loop invariant abs_product <= 10000;
        loop assigns abs_product;
    */
    while (abs_product >= 2)
    {
        abs_product = abs_product - 2;
    }

    if (abs_product == 1)
    {
        is_odd = 1;
    }

    if (is_odd)
    {
        //@ assert result > 0;
        result = result - 1;
    }

    //@ assert result >= 0;
    return result;
}
