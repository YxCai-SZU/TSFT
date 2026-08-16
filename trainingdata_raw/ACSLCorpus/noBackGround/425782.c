#include <stdbool.h>

/*@
    requires 0 <= a <= 10000;
    requires 0 <= b <= 10000;
    ensures \result == ((a * b) % 2 == 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    unsigned int product;
    bool is_even;
    unsigned int temp;

    //@ assert a <= 10000 && b <= 10000;
    //@ assert a * b <= 10000 * 10000;

    product = a * b;
    is_even = false;
    temp = product;

    /*@
        loop invariant 0 <= a <= 10000;
        loop invariant 0 <= b <= 10000;
        loop invariant temp >= 0;
        loop invariant temp <= product;
        loop invariant temp % 2 == product % 2;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 2)
    {
        temp = temp - 2;
    }

    if (temp == 0)
    {
        is_even = true;
    }

    //@ assert is_even == ((a * b) % 2 == 0);
    return is_even;
}
