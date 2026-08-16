#include <stdbool.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures \result == ( (a * b) % 2 == 0 );
    assigns \nothing;
*/
bool func(int a, int b)
{
    int product;
    bool is_even = false;
    int abs_product;
    int remainder;

    //@ assert (1 <= (a) <= 10000 && 1 <= (b) <= 10000);
    
    product = a * b;

    if (product < 0)
    {
        abs_product = -product;
    }
    else
    {
        abs_product = product;
    }

    remainder = abs_product;

    /*@
        loop invariant 0 <= remainder <= abs_product;
        loop invariant remainder % 2 == abs_product % 2;
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

    //@ assert ((((a)) * ((b))) % 2 == 0) <==> (remainder == 0);
    return is_even;
}
