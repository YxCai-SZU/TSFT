#include <stdint.h>

/*@
    requires 1 <= r <= 100;
    ensures \result == (2 * 314 * r) / 100;
*/
int64_t func(int64_t r)
{
    int64_t pi_approx;
    int64_t scaled_r;
    int64_t scaled_circumference;
    int64_t result;
    int64_t temp;

    pi_approx = 314;
    scaled_r = r * 100;
    //@ assert pi_approx == 314;
    //@ assert scaled_r == r * 100;

    //@ assert 0 < 2 * pi_approx * scaled_r <= 2 * 314 * 10000;
    scaled_circumference = 2 * pi_approx * scaled_r;
    //@ assert scaled_circumference == 2 * pi_approx * scaled_r;

    result = 0;
    temp = scaled_circumference;
    //@ assert result * 10000 + temp == scaled_circumference;
    //@ assert 0 <= result;
    //@ assert 0 <= temp;
    //@ assert temp <= scaled_circumference;

    /*@
        loop invariant (1 <= (r) <= 100 &&
        (pi_approx) == 314 &&
        (scaled_r) == (r) * 100 &&
        (scaled_circumference) == 2 * (pi_approx) * (scaled_r) &&
        (result) * 10000 + (temp) == (scaled_circumference) &&
        0 <= (result) &&
        0 <= (temp) &&
        (temp) <= (scaled_circumference));
        loop assigns result, temp;
        loop variant temp;
    */
    while (temp >= 10000)
    {
        //@ assert temp >= 10000;
        result = result + 1;
        temp = temp - 10000;
        //@ assert result * 10000 + temp == scaled_circumference;
        //@ assert 0 <= result;
        //@ assert 0 <= temp;
        //@ assert temp <= scaled_circumference;
    }

    //@ assert result * 10000 + temp == scaled_circumference;
    //@ assert temp < 10000;
    //@ assert result == (2 * 314 * r) / 100;
    return result;
}
