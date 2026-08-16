#include <stdbool.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    requires a * b <= 2147483647;
    ensures \result == ((a * b) % 2 != 0);
*/
bool func(int a, int b)
{
    int product;
    bool is_odd;
    int abs_product;

    product = a * b;
    is_odd = false;
    
    if (product < 0)
        abs_product = -product;
    else
        abs_product = product;

    /*@
        loop invariant 0 <= abs_product <= 2147483647;
        loop invariant abs_product <= a * b;
        loop invariant (abs_product % 2 == 0) == (product % 2 == 0);
        loop invariant (product % 2 == 0) ==> !is_odd;
        loop invariant 1 <= a <= 10000;
        loop invariant 1 <= b <= 10000;
        loop invariant a * b <= 2147483647;
        loop assigns abs_product, is_odd;
        loop variant abs_product;
    */
    while (abs_product > 0)
    {
        if (abs_product == 1)
        {
            is_odd = true;
            break;
        }
        abs_product -= 2;
    }

    //@ assert (product % 2 != 0) == is_odd;
    return is_odd;
}
