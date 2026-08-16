#include <stdint.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result >= 0;
    ensures \result <= (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);
*/
int32_t func(uint32_t x)
{
    int32_t ans = 0;
    uint32_t temp_x = x;
    uint32_t five_hundreds = 0;
    
    //@ assert (1 <= (x) <= 100000);
    
    /*@
        loop invariant 0 <= five_hundreds <= x / 500;
        loop invariant temp_x == x - five_hundreds * 500;
        loop invariant ans == 0;
        loop invariant ans >= 0;
        loop invariant ans <= (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);
        loop assigns five_hundreds, temp_x;
    */
    while (temp_x >= 500)
    {
        //@ assert temp_x >= 500;
        five_hundreds += 1;
        temp_x -= 500;
    }
    
    ans += (int32_t)five_hundreds * 1000;
    
    uint32_t five_ones = 0;
    
    /*@
        loop invariant 0 <= five_ones <= (x - five_hundreds * 500) / 5;
        loop invariant temp_x == x - five_hundreds * 500 - five_ones * 5;
        loop invariant ans == (int32_t)five_hundreds * 1000;
        loop invariant ans >= 0;
        loop invariant ans <= (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);
        loop assigns five_ones, temp_x;
    */
    while (temp_x >= 5)
    {
        //@ assert temp_x >= 5;
        five_ones += 1;
        temp_x -= 5;
    }
    
    ans += (int32_t)five_ones * 5;
    
    //@ assert ans >= 0;
    //@ assert ans <= (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);
    
    return ans;
}
