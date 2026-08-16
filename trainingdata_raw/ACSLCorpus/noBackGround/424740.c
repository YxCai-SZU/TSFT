#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (2 * (r) * 3);
    assigns \nothing;
*/
int64_t func(int64_t r) {
    int64_t pi_approx;
    int64_t scale_factor;
    int64_t scaled_r;
    int64_t circumference;
    int64_t temp;
    int64_t divisor;
    
    pi_approx = 3;
    scale_factor = 10;
    scaled_r = r * scale_factor;
    circumference = 0;
    temp = 2 * pi_approx * scaled_r;
    divisor = scale_factor;
    
    /*@
        loop invariant ((1 <= ((r)) <= 100) &&
        (pi_approx) == 3 &&
        (scale_factor) == 10 &&
        (scaled_r) == (r) * (scale_factor) &&
        (temp) >= 0 &&
        (temp) == 2 * (pi_approx) * (scaled_r) - (circumference) * (divisor) &&
        (circumference) * (scale_factor) + (temp) == 2 * (pi_approx) * (scaled_r));
        loop assigns temp, circumference;
        loop variant temp;
    */
    while (temp >= divisor) {
        //@ assert temp >= divisor;
        temp -= divisor;
        circumference += 1;
        //@ assert temp == 2 * pi_approx * scaled_r - circumference * divisor;
    }
    
    //@ assert circumference * scale_factor + temp == 2 * pi_approx * scaled_r;
    //@ assert circumference == (2 * (r) * 3);
    
    return circumference;
}
