#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((2 * (n) * 314159) / 100000);
    assigns \nothing;
*/
int64_t func(uint64_t n)
{
    uint64_t pi_approx;
    uint64_t two;
    uint64_t scale;
    uint64_t result;
    uint64_t temp;

    pi_approx = 314159;
    two = 2;
    scale = 100000;
    result = 0;
    temp = two * n * pi_approx;

    /*@
        loop invariant 1 <= n && n <= 100;
        loop invariant pi_approx == 314159;
        loop invariant two == 2;
        loop invariant scale == 100000;
        loop invariant temp >= 0;
        loop invariant result * scale + temp == two * n * pi_approx;
        loop assigns temp, result;
        loop variant temp;
    */
    while (temp >= scale)
    {
        //@ assert temp >= scale;
        temp -= scale;
        result += 1;
    }

    //@ assert result * scale + temp == two * n * pi_approx;
    //@ assert result == ((2 * (n) * 314159) / 100000);
    return (int64_t)result;
}
