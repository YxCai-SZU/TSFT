#include <stdint.h>

/*@
    requires 1 <= r <= 100;
    ensures \result == 2 * 314159 * r / 100000;
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi;
    int64_t two;
    int64_t scale;
    int64_t product;
    int64_t circumference;
    int64_t temp;

    pi = 314159;
    two = 2;
    scale = 100000;
    product = two * pi * r;
    circumference = 0;
    temp = product;

    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == 314159;
        loop invariant two == 2;
        loop invariant scale == 100000;
        loop invariant product == two * pi * r;
        loop invariant ((circumference) * (scale) + (temp) == (product));
        loop invariant circumference >= 0;
        loop invariant temp >= 0;
        loop assigns circumference, temp;
        loop variant temp;
    */
    while (temp >= scale)
    {
        //@ assert temp >= scale;
        temp -= scale;
        circumference += 1;
        //@ assert ((circumference) * (scale) + (temp) == (product));
    }

    //@ assert ((circumference) * (scale) + (temp) == (product));
    //@ assert temp < scale;
    //@ assert circumference == product / scale;
    return circumference;
}
