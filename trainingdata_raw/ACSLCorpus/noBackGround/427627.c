#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == 2 * r * 314 / 100;
*/
int64_t func(int64_t r)
{
    // Variable declarations at scope top
    int64_t pi;
    int64_t circumference;
    int64_t temp;
    int64_t divisor;
    
    pi = 314;
    circumference = 0;
    temp = 2 * r * pi;
    divisor = 100;
    
    //@ assert ((1 <= ((r)) <= 100) &&         (pi) == 314 &&         0 <= (circumference) &&         0 <= (temp) &&         (temp) + (circumference) * (divisor) == (2 * ((r)) * 314));
    
    /*@
        loop invariant ((1 <= ((r)) <= 100) &&
        (pi) == 314 &&
        0 <= (circumference) &&
        0 <= (temp) &&
        (temp) + (circumference) * (divisor) == (2 * ((r)) * 314));
        loop assigns circumference, temp;
        loop variant temp;
    */
    while (temp >= divisor) {
        temp -= divisor;
        circumference += 1;
    }
    
    //@ assert temp + circumference * divisor == 2 * r * pi;
    
    return circumference;
}
