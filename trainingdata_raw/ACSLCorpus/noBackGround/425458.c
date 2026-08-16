#include <stdint.h>

/*@
    requires 1 <= r <= 100;
    ensures \result == 2 * r * 314 / 100;
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi_approx;
    int64_t ans;
    int64_t result;
    int64_t remainder;
    int64_t divisor;
    int64_t count;

    pi_approx = 314;
    ans = 2 * r * pi_approx;
    result = 0;
    remainder = ans;
    divisor = 100;
    count = 0;

    //@ assert (1 <= (r) <= 100 && (ans) == 2 * (r) * 314);

    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi_approx == 314;
        loop invariant ans == 2 * r * pi_approx;
        loop invariant result == 0;
        loop invariant count * divisor + remainder == ans;
        loop invariant 0 <= count <= ans / divisor;
        loop invariant 0 <= remainder < divisor + ans;
        loop assigns remainder, count;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        remainder -= divisor;
        count += 1;
    }

    result = count;

    //@ assert result == ((ans) / 100);
    return result;
}
