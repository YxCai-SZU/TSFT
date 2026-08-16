#include <stdint.h>

/*@
    requires 1 <= x && x <= 100;
    ensures \result == (x / 3) + (x / 9) + (x / 99);
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    uint32_t original_x = x;
    uint32_t div_3 = 0;
    uint32_t temp_x = x;
    uint32_t div_9 = 0;
    uint32_t div_99 = 0;
    uint32_t result = 0;
    
    //@ assert (1 <= (original_x) && (original_x) <= 100);
    
    /*@
        loop invariant 1 <= original_x && original_x <= 100;
        loop invariant 0 <= temp_x;
        loop invariant div_3 <= original_x / 3;
        loop invariant original_x == temp_x + 3 * div_3;
        loop assigns temp_x, div_3;
        loop variant temp_x;
    */
    while (temp_x >= 3)
    {
        //@ assert temp_x >= 3;
        temp_x -= 3;
        div_3 += 1;
    }
    
    //@ assert div_3 == original_x / 3;
    
    temp_x = original_x;
    
    /*@
        loop invariant 1 <= original_x && original_x <= 100;
        loop invariant 0 <= temp_x;
        loop invariant div_9 <= original_x / 9;
        loop invariant original_x == temp_x + 9 * div_9;
        loop assigns temp_x, div_9;
        loop variant temp_x;
    */
    while (temp_x >= 9)
    {
        //@ assert temp_x >= 9;
        temp_x -= 9;
        div_9 += 1;
    }
    
    //@ assert div_9 == original_x / 9;
    
    temp_x = original_x;
    
    /*@
        loop invariant 1 <= original_x && original_x <= 100;
        loop invariant 0 <= temp_x;
        loop invariant div_99 <= original_x / 99;
        loop invariant original_x == temp_x + 99 * div_99;
        loop assigns temp_x, div_99;
        loop variant temp_x;
    */
    while (temp_x >= 99)
    {
        //@ assert temp_x >= 99;
        temp_x -= 99;
        div_99 += 1;
    }
    
    //@ assert div_99 == original_x / 99;
    
    result = div_3 + div_9 + div_99;
    //@ assert result == (original_x / 3) + (original_x / 9) + (original_x / 99);
    
    return result;
}

/*@
    assigns \nothing;
*/
int main()
{
    return 0;
}
