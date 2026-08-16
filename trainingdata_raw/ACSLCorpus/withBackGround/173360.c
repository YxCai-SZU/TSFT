#include <stdint.h>

/*@
    predicate input_in_range(integer i) = 1 <= i && i <= 100;
    
    logic integer compute_result(integer i) = 3 * i * i;
    
    lemma multiplication_bounds:
        \forall integer i; input_in_range(i) ==> 3 * i <= 300;
    
    lemma result_bounds:
        \forall integer i; input_in_range(i) ==> 3 * i * i <= 300 * 100;
*/

/*@
    requires input_in_range(input);
    requires input == (int64_t)input;
    ensures \result == compute_result(input);
    assigns \nothing;
*/
int64_t func(int64_t input)
{
    // Variable declarations at top of scope
    int64_t result;
    
    //@ assert input_in_range(input);
    
    //@ assert 3 * input <= 300;
    
    //@ assert 3 * input * input <= 300 * 100;
    
    result = 3 * input * input;
    
    //@ assert result == compute_result(input);
    
    return result;
}
