#include <stdbool.h>

/*@
    requires 0 <= x <= 10000;
    requires 0 <= y <= 10000;
    ensures \result == ((x * y) % 2 == 0);
    assigns \nothing;
*/
bool func(int x, int y)
{
    int product;
    bool is_even;
    int abs_product;

    //@ assert x * y <= 10000 * 10000;
    product = x * y;

    is_even = true;
    abs_product = product;

    if (product < 0)
    {
        abs_product = -product;
    }

    /*@
        loop invariant 0 <= abs_product <= product;
        loop invariant (product % 2 == 0) ==> is_even;
        loop invariant abs_product % 2 == product % 2;
        loop assigns abs_product, is_even;
        loop variant abs_product;
    */
    while (abs_product > 0)
    {
        if (abs_product == 1 || abs_product == -1)
        {
            is_even = false;
            break;
        }

        abs_product -= 2;
    }

    //@ assert (product % 2 == 0) ==> is_even;
    return is_even;
}

int main()
{
    return 0;
}
