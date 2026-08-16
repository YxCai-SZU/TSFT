#include <stdbool.h>

/*@
    requires (1 <= (x) <= 20) && (1 <= (y) <= 20);
    ensures \result == ((((x) * (y)) % 2) == 0);
    assigns \nothing;
*/
bool func(unsigned int x, unsigned int y)
{
    // Variable declarations at top of scope
    unsigned int product;
    bool is_even;
    unsigned int temp;

    //@ assert x * y <= 400;
    product = x * y;
    is_even = true;
    temp = product;

    /*@
        loop invariant 1 <= x <= 20;
        loop invariant 1 <= y <= 20;
        loop invariant 0 <= temp <= product;
        loop invariant temp % 2 == product % 2;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 2)
    {
        //@ assert temp >= 2;
        temp -= 2;
    }

    if (temp == 1)
    {
        is_even = false;
    }

    //@ assert is_even == (product % 2 == 0);
    return is_even;
}
