#include <stdbool.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures \result == (a * b % 2 == 0);
*/
bool func(int a, int b)
{
    unsigned int a_unsigned;
    unsigned int b_unsigned;
    unsigned int product;
    bool is_even = false;
    unsigned int temp;

    //@ assert 1 <= a <= 10000;
    //@ assert 1 <= b <= 10000;

    a_unsigned = (a < 0) ? (unsigned int)(-a) : (unsigned int)a;
    b_unsigned = (b < 0) ? (unsigned int)(-b) : (unsigned int)b;

    //@ assert a_unsigned <= 10000;
    //@ assert b_unsigned <= 10000;
    //@ assert a_unsigned * b_unsigned <= 100000000;

    product = a_unsigned * b_unsigned;

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

    //@ assert is_even == (product % 2 == 0);
    return is_even;
}
