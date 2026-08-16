#include <stdint.h>

/*@
    predicate valid_range(integer r) = 1 <= r <= 100;
    logic integer pi_approx = 314159;
    logic integer scale = 100000;
    logic integer expected_circumference(integer r) = (2 * pi_approx * r) / scale;
*/

/*@
    requires valid_range(r);
    ensures \result == expected_circumference(r);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi_approx;
    int64_t scale;
    int64_t circumference;
    int64_t temp;
    int64_t count;

    pi_approx = 314159;
    scale = 100000;
    circumference = 0;
    temp = 2 * pi_approx * r;
    count = 0;

    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi_approx == 314159;
        loop invariant scale == 100000;
        loop invariant temp >= 0;
        loop invariant count * scale + temp == 2 * pi_approx * r;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= scale)
    {
        //@ assert temp >= scale;
        temp -= scale;
        count += 1;
    }

    circumference = count;
    //@ assert circumference == expected_circumference(r);
    return circumference;
}
