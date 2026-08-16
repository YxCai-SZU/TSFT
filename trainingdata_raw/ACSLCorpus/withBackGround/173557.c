#include <stdint.h>

/*@
    predicate input_in_range(integer x) = 1 <= x <= 10;
    
    logic integer compute_result(integer x) = x * (1 + x * (1 + x));
    
    lemma intermediate_bound1:
        \forall integer x; input_in_range(x) ==> 1 + x * (1 + x) >= 1;
    
    lemma intermediate_bound2:
        \forall integer x; input_in_range(x) ==> 1 + x * (1 + x) <= 1000;
    
    lemma result_bound:
        \forall integer x; input_in_range(x) ==> compute_result(x) <= 10000;
*/

/*@
    requires input_in_range(input);
    ensures \result == compute_result(input);
    assigns \nothing;
*/
uint32_t func(uint32_t input)
{
    // Declare all variables at the top
    uint32_t result;
    
    //@ assert input >= 1 && input <= 10;
    //@ assert 1 + input * (1 + input) >= 1;
    //@ assert 1 + input * (1 + input) <= 1000;
    //@ assert input * (1 + input * (1 + input)) <= 10000;
    
    result = input * (1 + input * (1 + input));
    
    //@ assert result == compute_result(input);
    return result;
}
