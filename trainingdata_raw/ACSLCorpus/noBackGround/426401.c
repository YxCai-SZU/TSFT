#include <stdint.h>

/*@
    requires (0 <= (x) <= 1000000000);
    ensures \result == (((((x)) / 500) * 1000) + ((((((x)) % 500)) / 5) * 5));
    assigns \nothing;
*/
uint64_t func(uint64_t x)
{
    uint64_t original_x = x;
    uint64_t div_500 = 0;
    uint64_t temp_x = x;
    
    /*@
        loop invariant 0 <= temp_x <= original_x;
        loop invariant div_500 <= ((original_x) / 500);
        loop invariant temp_x == original_x - div_500 * 500;
        loop assigns temp_x, div_500;
        loop variant temp_x;
    */
    while (temp_x >= 500)
    {
        //@ assert temp_x >= 500;
        temp_x = temp_x - 500;
        div_500 = div_500 + 1;
    }
    
    x = temp_x;
    uint64_t div_5 = 0;
    
    /*@
        loop invariant 0 <= x <= temp_x;
        loop invariant div_5 <= ((temp_x) / 5);
        loop invariant x == temp_x - div_5 * 5;
        loop assigns x, div_5;
        loop variant x;
    */
    while (x >= 5)
    {
        //@ assert x >= 5;
        x = x - 5;
        div_5 = div_5 + 1;
    }
    
    uint64_t ans = div_500 * 1000 + div_5 * 5;
    //@ assert ans == (((((original_x)) / 500) * 1000) + ((((((original_x)) % 500)) / 5) * 5));
    return ans;
}
