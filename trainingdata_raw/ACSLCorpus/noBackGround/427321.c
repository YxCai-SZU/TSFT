#include <stdint.h>

/*@
    requires (0 <= (x) && (x) <= 1000000000);
    ensures \result == (((x) / 500) * 1000 + ((x) % 500 / 5) * 5);
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    uint32_t result;
    uint32_t temp_x;
    uint32_t five_hundred_yen;
    uint32_t five_yen;
    
    result = 0;
    temp_x = x;
    five_hundred_yen = 0;
    
    /*@
        loop invariant 0 <= five_hundred_yen;
        loop invariant five_hundred_yen <= x / 500;
        loop invariant temp_x == x - five_hundred_yen * 500;
        loop assigns five_hundred_yen, temp_x;
        loop variant temp_x;
    */
    while (temp_x >= 500)
    {
        five_hundred_yen += 1;
        temp_x -= 500;
    }
    
    five_yen = 0;
    
    /*@
        loop invariant 0 <= five_yen;
        loop invariant five_yen <= (x - five_hundred_yen * 500) / 5;
        loop invariant temp_x == x - five_hundred_yen * 500 - five_yen * 5;
        loop assigns five_yen, temp_x;
        loop variant temp_x;
    */
    while (temp_x >= 5)
    {
        five_yen += 1;
        temp_x -= 5;
    }
    
    result = five_hundred_yen * 1000 + five_yen * 5;
    
    //@ assert result == (((x) / 500) * 1000 + ((x) % 500 / 5) * 5);
    
    return result;
}
