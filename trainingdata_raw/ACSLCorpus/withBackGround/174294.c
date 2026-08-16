#include <stdint.h>

/*@
    predicate input_in_range(integer i) = 1 <= i <= 100;
    predicate square_in_range(integer i) = i * i <= 10000;
    predicate result_in_range(integer i) = i * i * 3 <= 30000;
    logic integer compute_result(integer i) = i * i * 3;
*/

/*@
    requires input_in_range(input);
    ensures \result == compute_result(input);
    assigns \nothing;
*/
int32_t func(int32_t input)
{
    // Variable declarations at scope top
    int32_t result;
    
    //@ assert input_in_range(input);
    //@ assert square_in_range(input);
    //@ assert result_in_range(input);
    
    result = input * input * 3;
    
    //@ assert result == compute_result(input);
    return result;
}
