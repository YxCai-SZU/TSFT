#include <stdint.h>

/*@
    predicate is_valid_input(integer x) = x <= 0x49;
    logic integer division_result(integer x, integer div) = x - 5 * div;
    logic integer final_result(integer div, integer mod) = div * 2 + mod;
*/

/*@
    requires is_valid_input(x);
    ensures \result == (x / 5) * 2 + (x % 5);
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    uint32_t result;
    uint32_t temp_x;
    uint32_t division_result;
    uint32_t modulus_result;
    
    result = 0;
    temp_x = x;
    division_result = 0;
    
    /*@
        loop invariant temp_x <= x;
        loop invariant division_result <= x / 5;
        loop invariant x <= 0x49;
        loop invariant temp_x == x - 5 * division_result;
        loop assigns temp_x, division_result;
        loop variant temp_x;
    */
    while (temp_x >= 5)
    {
        temp_x = temp_x - 5;
        division_result = division_result + 1;
    }
    
    modulus_result = temp_x;
    result = division_result * 2 + modulus_result;
    
    //@ assert result == (x / 5) * 2 + (x % 5);
    return result;
}
