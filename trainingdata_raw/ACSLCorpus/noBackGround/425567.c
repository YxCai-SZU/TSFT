#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((2 * ((r)) * 314) / 100);
*/
int32_t func(uint32_t r)
{
    // Variable declarations at scope top
    int32_t pi_approx;
    int32_t circumference;
    int32_t result;
    int32_t temp;
    int32_t divisor;
    int32_t count;
    
    // Initialization
    pi_approx = 314;
    circumference = 2 * (int32_t)r * pi_approx;
    result = 0;
    temp = circumference;
    divisor = 100;
    count = 0;
    
    //@ assert circumference == 2 * (int32_t)r * 314;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi_approx == 314;
        loop invariant circumference == 2 * (int32_t)r * pi_approx;
        loop invariant divisor == 100;
        loop invariant circumference == temp + divisor * count;
        loop invariant count == (circumference - temp) / divisor;
        loop invariant 0 <= count * divisor <= 2 * (int32_t)r * 314;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= divisor) {
        temp -= divisor;
        count += 1;
    }
    
    result = count;
    
    //@ assert circumference == result * divisor + temp;
    
    //@ assert result == circumference / 100;
    
    return result;
}
