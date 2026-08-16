#include <stdbool.h>

/*@
    requires 1 <= a && a <= 3;
    requires 1 <= b && b <= 3;
    ensures \result == ( (a * b * 2) % 2 != 0 || (a * b * 3) % 2 != 0 );
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    unsigned int product1;
    unsigned int product2;
    bool is_odd;
    unsigned int temp;

    //@ assert 1 <= a && a <= 3;
    //@ assert 1 <= b && b <= 3;
    //@ assert 1 <= a * b && a * b <= 9;

    product1 = a * b * 2;
    product2 = a * b * 3;
    is_odd = false;
    temp = product1;

    /*@
        loop invariant 1 <= a && a <= 3;
        loop invariant 1 <= b && b <= 3;
        loop invariant temp >= 0;
        loop invariant temp <= product1;
        loop invariant product1 <= 18;
        loop invariant (product1 - temp) % 2 == 0;
        loop invariant 1 <= a * b && a * b <= 9;
        loop assigns temp;
        loop variant temp;
    */
    while (temp > 1)
    {
        temp -= 2;
    }

    if (temp == 1)
    {
        is_odd = true;
    }

    if (!is_odd)
    {
        temp = product2;

        /*@
            loop invariant 1 <= a && a <= 3;
            loop invariant 1 <= b && b <= 3;
            loop invariant temp >= 0;
            loop invariant temp <= product2;
            loop invariant product2 <= 27;
            loop invariant (product2 - temp) % 2 == 0;
            loop invariant 1 <= a * b && a * b <= 9;
            loop assigns temp;
            loop variant temp;
        */
        while (temp > 1)
        {
            temp -= 2;
        }

        if (temp == 1)
        {
            is_odd = true;
        }
    }

    //@ assert is_odd == ( (product1 % 2 != 0) || (product2 % 2 != 0) );
    return is_odd;
}
