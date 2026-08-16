#include <stdbool.h>

/*@
    requires 0 <= x <= 10000 && 0 <= y <= 10000;
    ensures \result == ( (x * y) % 2 == 0 );
    assigns \nothing;
*/
bool func(unsigned int x, unsigned int y)
{
    unsigned int product;
    bool is_even = false;
    unsigned int temp;

    //@ assert 0 <= x <= 10000;
    //@ assert 0 <= y <= 10000;
    //@ assert x * y <= 100000000;

    product = x * y;
    temp = product;

    /*@
        loop invariant 0 <= temp <= product;
        loop invariant temp % 2 == product % 2;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 2)
    {
        temp -= 2;
    }

    if (temp == 0)
    {
        is_even = true;
    }

    return is_even;
}
