#include <stdbool.h>

/*@
    requires 1 <= a && a <= 3;
    requires 1 <= b && b <= 3;
    ensures \result == ((a * b) % 2 != 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    unsigned int product;
    bool is_odd;
    unsigned int temp;

    //@ assert 1 <= a && a <= 3;
    //@ assert 1 <= b && b <= 3;
    //@ assert 1 <= a * b && a * b <= 9;

    product = a * b;
    is_odd = false;
    temp = product;

    /*@
        loop invariant 0 <= temp && temp <= product;
        loop invariant temp % 2 == product % 2;
        loop invariant product == a * b;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 2)
    {
        temp -= 2;
    }

    if (temp == 1)
    {
        is_odd = true;
    }

    return is_odd;
}
