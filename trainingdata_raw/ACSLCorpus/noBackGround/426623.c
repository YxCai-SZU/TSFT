#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((2 * (r) * 314) / 100);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi_approx;
    int64_t two;
    int64_t scale;
    int64_t result;
    int64_t temp_r;
    int64_t count;
    
    pi_approx = 314;
    two = 2;
    scale = 100;
    result = 0;
    temp_r = r * two * pi_approx;
    count = 0;
    
    /*@
        loop invariant ((1 <= ((r)) <= 100) &&
        (pi_approx) == 314 &&
        (two) == 2 &&
        (scale) == 100 &&
        (temp_r) >= 0 &&
        (temp_r) == (r) * (two) * (pi_approx) - (count) * (scale) &&
        (count) >= 0 &&
        (count) <= ((r) * (two) * (pi_approx)) / (scale));
        loop assigns temp_r, count;
        loop variant temp_r;
    */
    while (temp_r >= scale)
    {
        //@ assert temp_r >= scale;
        temp_r = temp_r - scale;
        count = count + 1;
    }
    
    result = count;
    //@ assert result == ((2 * (r) * 314) / 100);
    return result;
}
