#include <stdint.h>

/*@
    predicate is_valid_input(integer x) = 1 <= x && x <= 1000;
    predicate result_bounds(integer r) = 0 <= r && r <= 1000;
    predicate result_constraint(integer r, integer input) = 
        r * 3 <= input && input < (r + 1) * 3;
*/

/*@
    requires is_valid_input(input);
    ensures result_bounds(\result);
    ensures result_constraint(\result, input);
*/
uint32_t func(uint32_t input)
{
    uint32_t result;
    uint32_t temp_input;
    uint32_t count;
    
    result = 0;
    temp_input = input;
    count = 0;
    
    /*@
        loop invariant 0 <= temp_input <= input;
        loop invariant result == 0;
        loop invariant 0 <= count <= input / 3;
        loop invariant input == temp_input + 3 * count;
        loop assigns temp_input, count;
    */
    while (temp_input >= 3)
    {
        //@ assert temp_input >= 3;
        temp_input = temp_input - 3;
        //@ assert temp_input >= 0;
        count = count + 1;
        //@ assert count >= 1;
    }
    
    result = count;
    //@ assert result_bounds(result);
    //@ assert result_constraint(result, input);
    return result;
}
