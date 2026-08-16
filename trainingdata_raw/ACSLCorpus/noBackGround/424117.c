#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == 2 * r * 314 / 100;
    assigns \nothing;
*/
int64_t func(uint64_t r)
{
    int64_t pi_scaled = 314;
    int64_t scale_factor = 100;
    int64_t result = 0;
    int64_t temp = 2 * (int64_t)r * pi_scaled;

    //@ assert ((1 <= ((r)) <= 100) &&         (temp) >= 0 &&         (result) * (100)+ (temp) == (2 * ((r)) * (314)));

    /*@
        loop invariant ((1 <= ((r)) <= 100) &&
        (temp) >= 0 &&
        (result) * (100)+ (temp) == (2 * ((r)) * (314)));
        loop invariant temp >= scale_factor ==> temp >= 0;
        loop assigns result, temp;
        loop variant temp;
    */
    while (temp >= scale_factor)
    {
        //@ assert temp >= scale_factor && temp >= 0;
        result += 1;
        temp -= scale_factor;
        //@ assert ((1 <= ((r)) <= 100) &&         (temp) >= 0 &&         (result) * (100)+ (temp) == (2 * ((r)) * (314)));
    }

    //@ assert temp < scale_factor;
    //@ assert result * scale_factor + temp == 2 * (int64_t)r * pi_scaled;
    return result;
}
