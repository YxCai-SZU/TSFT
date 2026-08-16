#include <stdbool.h>

/*@
    requires (1 <= (n) <= 10000) && (1 <= (m) <= 10000);
    ensures \result == ( (n * m) % 2 == 0 );
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int m)
{
    unsigned int product;
    bool is_even = false;
    unsigned int temp;

    //@ assert (1 <= (n) <= 10000);
    //@ assert (1 <= (m) <= 10000);
    product = n * m;
    //@ assert (1 <= (product) <= 10000 * 10000);
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
