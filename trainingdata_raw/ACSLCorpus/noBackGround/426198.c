#include <stdbool.h>

/*@
    requires 1 <= r <= 100;
    ensures \result == 2 * r * 3142 / 1000;
    assigns \nothing;
*/
int func(int r)
{
    int pi_approx;
    int scaled_value;
    int result;
    int remainder;
    int divisor;
    int count;

    pi_approx = 3142;
    scaled_value = r * 2 * pi_approx;
    result = 0;
    remainder = scaled_value;
    divisor = 1000;
    count = 0;

    //@ assert ((scaled_value) == (r) * 2 * 3142);

    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi_approx == 3142;
        loop invariant scaled_value == r * 2 * pi_approx;
        loop invariant divisor == 1000;
        loop invariant ((count) * 1000 + (remainder) == (scaled_value) &&
        0 <= (remainder) < 1000 + (scaled_value));
        loop assigns remainder, count;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        remainder -= divisor;
        count += 1;
    }

    result = count;

    //@ assert result == (2 * (r) * 3142 / 1000);
    return result;
}
