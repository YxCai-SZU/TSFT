#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (2 * (r) * 314 / 100);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi_approx;
    int64_t two;
    int64_t scale;
    int64_t result;
    int64_t temp;
    
    pi_approx = 314;
    two = 2;
    scale = 100;
    result = 0;
    temp = two * r * pi_approx;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi_approx == 314;
        loop invariant two == 2;
        loop invariant scale == 100;
        loop invariant result * scale + temp == two * r * pi_approx;
        loop invariant 0 <= result <= 2 * r * 314 / 100;
        loop invariant 0 <= temp <= two * r * pi_approx;
        loop assigns result, temp;
        loop variant temp;
    */
    while (temp >= scale)
    {
        //@ assert temp >= scale && result * scale + temp == two * r * pi_approx;
        result += 1;
        temp -= scale;
    }
    
    //@ assert result == (2 * (r) * 314 / 100);
    return result;
}
