#include <stdint.h>

/*@
    requires (1 <= (x) && (x) <= 10000);
    ensures \result >= 0;
    ensures \result <= 10000 - x;
    assigns \nothing;
*/
int32_t func(int32_t x)
{
    // Variable declarations at top of scope
    int32_t remaining;
    int32_t result;
    int32_t temp_remaining;
    int32_t hundreds;
    int32_t fives;
    int32_t ones;
    
    // Initialization
    remaining = 10000 - x;
    result = 0;
    temp_remaining = remaining;
    hundreds = 0;
    
    //@ assert (1 <= (x) && (x) <= 10000);
    //@ assert remaining == 10000 - x;
    
    /*@
        loop invariant 1 <= x && x <= 10000;
        loop invariant remaining == 10000 - x;
        loop invariant temp_remaining >= 0;
        loop invariant hundreds >= 0;
        loop invariant temp_remaining == remaining - hundreds * 1000;
        loop assigns temp_remaining, hundreds;
        loop variant temp_remaining;
    */
    while (temp_remaining >= 1000)
    {
        temp_remaining -= 1000;
        hundreds += 1;
    }
    
    result += hundreds * 1000;
    fives = 0;
    
    /*@
        loop invariant 1 <= x && x <= 10000;
        loop invariant remaining == 10000 - x;
        loop invariant temp_remaining >= 0;
        loop invariant hundreds >= 0;
        loop invariant fives >= 0;
        loop invariant temp_remaining == remaining - hundreds * 1000 - fives * 500;
        loop invariant hundreds <= remaining / 1000;
        loop invariant fives <= (remaining - hundreds * 1000) / 500;
        loop assigns temp_remaining, fives;
        loop variant temp_remaining;
    */
    while (temp_remaining >= 500)
    {
        temp_remaining -= 500;
        fives += 1;
    }
    
    result += fives * 500;
    ones = 0;
    
    /*@
        loop invariant 1 <= x && x <= 10000;
        loop invariant remaining == 10000 - x;
        loop invariant temp_remaining >= 0;
        loop invariant hundreds >= 0;
        loop invariant fives >= 0;
        loop invariant ones >= 0;
        loop invariant temp_remaining == remaining - hundreds * 1000 - fives * 500 - ones * 100;
        loop invariant hundreds <= remaining / 1000;
        loop invariant fives <= (remaining - hundreds * 1000) / 500;
        loop invariant ones <= (remaining - hundreds * 1000 - fives * 500) / 100;
        loop assigns temp_remaining, ones;
        loop variant temp_remaining;
    */
    while (temp_remaining >= 100)
    {
        temp_remaining -= 100;
        ones += 1;
    }
    
    result += ones * 100;
    
    //@ assert result >= 0;
    //@ assert result <= 10000 - x;
    
    return result;
}
