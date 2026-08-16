#include <limits.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((2 * (r) * (31415)) / (10000));
    assigns \nothing;
*/
int func(int r)
{
    int pi_approx;
    int scale;
    int circumference;
    int temp;

    pi_approx = 31415;
    scale = 10000;
    circumference = 0;
    temp = 2 * r * pi_approx;

    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi_approx == 31415;
        loop invariant scale == 10000;
        loop invariant temp >= 0;
        loop invariant circumference * scale + temp == 2 * r * pi_approx;
        loop assigns circumference, temp;
        loop variant temp;
    */
    while (temp >= scale)
    {
        circumference += 1;
        temp -= scale;
    }

    //@ assert circumference * scale + temp == 2 * r * pi_approx;
    //@ assert temp < scale;
    //@ assert circumference * scale + temp == 2 * r * 31415;
    //@ assert circumference == (2 * r * 31415) / 10000;

    return circumference;
}
