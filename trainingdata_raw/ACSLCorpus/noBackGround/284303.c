#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((2 * 31415 * ((r))) / 10000);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi_approx = 31415;
    int64_t two_pi_r = 2 * pi_approx * r;
    int64_t divisor = 10000;
    int64_t result = 0;
    int64_t remainder = two_pi_r;
    
    //@ assert two_pi_r == 2 * 31415 * r;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi_approx == 31415;
        loop invariant two_pi_r == 2 * pi_approx * r;
        loop invariant divisor == 10000;
        loop invariant 0 <= result <= two_pi_r / divisor;
        loop invariant two_pi_r == result * divisor + remainder;
        loop invariant 0 <= remainder < divisor + two_pi_r;
        loop assigns remainder, result;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        remainder -= divisor;
        result += 1;
    }
    
    //@ assert result * 10000 + remainder == two_pi_r;
    //@ assert result == (2 * 31415 * r) / 10000;
    
    return result;
}
