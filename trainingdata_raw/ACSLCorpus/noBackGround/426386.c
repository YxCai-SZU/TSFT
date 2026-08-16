#include <stdint.h>

/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == ((2 * (314159)* (r)) / (100000));
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations at top of scope
    int64_t pi_approx;
    int64_t scale;
    int64_t circumference;
    int64_t temp;

    pi_approx = 314159;
    scale = 100000;
    circumference = 0;
    temp = 2 * pi_approx * r;

    //@ assert (1 <= (r) && (r) <= 100);
    //@ assert temp == 2 * pi_approx * r;

    /*@
        loop invariant 1 <= r && r <= 100;
        loop invariant temp >= 0;
        loop invariant temp == 2 * pi_approx * r - circumference * scale;
        loop invariant circumference * scale + temp == 2 * pi_approx * r;
        loop assigns circumference, temp;
        loop variant temp;
    */
    while (temp >= scale)
    {
        circumference = circumference + 1;
        temp = temp - scale;
    }

    //@ assert circumference == ((2 * (314159)* (r)) / (100000));
    return circumference;
}
