#include <stdint.h>

/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == (2 * r * 314) / 100;
*/
int32_t func(uint32_t r)
{
    // Variable declarations
    int32_t pi_approx = 314;
    int32_t circumference = 2 * (int32_t)r * pi_approx;
    int32_t result = 0;
    int32_t temp = circumference;
    int32_t divisor = 100;
    
    //@ assert pi_approx == 314;
    //@ assert divisor == 100;
    //@ assert circumference == 2 * (int32_t)r * pi_approx;
    
    /*@
        loop invariant (1 <= (r) && (r) <= 100);
        loop invariant pi_approx == 314;
        loop invariant divisor == 100;
        loop invariant circumference == 2 * (int32_t)r * pi_approx;
        loop invariant circumference == temp + result * divisor;
        loop invariant result * 100 + temp == 2 * r * 314;
        loop invariant result <= 2 * r * 314 / 100;
        loop assigns temp, result;
        loop variant temp;
    */
    while (temp >= divisor) {
        temp -= divisor;
        result += 1;
    }
    
    //@ assert result * 100 + temp == 2 * r * 314;
    
    return result;
}
