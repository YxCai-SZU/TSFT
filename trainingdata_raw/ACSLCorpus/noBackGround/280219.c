#include <stdint.h>

/*@
    requires 1 <= x <= 100000;
    ensures \result == ((((x)) / 500) * 1000 + ((((x)) % 500) / 5) * 5);
    assigns \nothing;
*/
uint64_t func(uint64_t x)
{
    uint64_t result;
    uint64_t temp_x;
    uint64_t div_500;
    uint64_t mod_500_div_5;
    
    result = 0;
    temp_x = x;
    div_500 = 0;
    
    /*@
        loop invariant 1 <= x <= 100000;
        loop invariant 0 <= temp_x <= x;
        loop invariant div_500 <= ((x) / 500);
        loop invariant x == temp_x + 500 * div_500;
        loop assigns temp_x, div_500;
        loop variant temp_x;
    */
    while (temp_x >= 500)
    {
        //@ assert temp_x >= 500;
        temp_x = temp_x - 500;
        div_500 = div_500 + 1;
    }
    
    mod_500_div_5 = 0;
    
    /*@
        loop invariant 1 <= x <= 100000;
        loop invariant 0 <= temp_x <= x;
        loop invariant 0 <= mod_500_div_5 <= (((x) % 500) / 5);
        loop invariant x == temp_x + 5 * mod_500_div_5 + 500 * div_500;
        loop assigns temp_x, mod_500_div_5;
        loop variant temp_x;
    */
    while (temp_x >= 5)
    {
        //@ assert temp_x >= 5;
        temp_x = temp_x - 5;
        mod_500_div_5 = mod_500_div_5 + 1;
    }
    
    result = div_500 * 1000 + mod_500_div_5 * 5;
    
    //@ assert result == ((((x)) / 500) * 1000 + ((((x)) % 500) / 5) * 5);
    return result;
}
