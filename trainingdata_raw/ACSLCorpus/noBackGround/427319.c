#include <stdint.h>

/*@
    requires (1 <= (a) <= 100000);
    ensures \result == (((a) / 500) * 1000 + (((a) % 500) / 5) * 5);
    assigns \nothing;
*/
uint32_t func(uint32_t a)
{
    uint32_t five_hundreds;
    uint32_t temp_a;
    uint32_t remaining;
    uint32_t five_ones;
    uint32_t temp_remaining;
    uint32_t result;
    
    five_hundreds = 0;
    temp_a = a;
    
    /*@
        loop invariant 0 <= five_hundreds <= a / 500;
        loop invariant 0 <= temp_a;
        loop invariant temp_a == a - five_hundreds * 500;
        loop invariant (1 <= (a) <= 100000);
        loop assigns five_hundreds, temp_a;
        loop variant temp_a;
    */
    while (temp_a >= 500)
    {
        //@ assert temp_a >= 500;
        temp_a -= 500;
        five_hundreds += 1;
    }
    
    remaining = temp_a;
    five_ones = 0;
    temp_remaining = remaining;
    
    /*@
        loop invariant 0 <= five_ones <= remaining / 5;
        loop invariant 0 <= temp_remaining;
        loop invariant temp_remaining == remaining - five_ones * 5;
        loop invariant (1 <= (a) <= 100000);
        loop assigns five_ones, temp_remaining;
        loop variant temp_remaining;
    */
    while (temp_remaining >= 5)
    {
        //@ assert temp_remaining >= 5;
        temp_remaining -= 5;
        five_ones += 1;
    }
    
    result = five_hundreds * 1000 + five_ones * 5;
    
    //@ assert result == (((a) / 500) * 1000 + (((a) % 500) / 5) * 5);
    return result;
}
