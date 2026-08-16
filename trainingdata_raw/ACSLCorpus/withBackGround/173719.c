#include <stdint.h>

/*@
    predicate x_in_range(integer x) = 0 <= x <= 0xFFFF;
    
    logic integer compute_result(integer x) = (x + (x / 2)) / 2;
    
    lemma sum_bounds: \forall integer x; x_in_range(x) ==> x + (x / 2) <= 0xFFFFFFFF;
    lemma result_bounds: \forall integer x; x_in_range(x) ==> compute_result(x) <= 0xFFFFFFFF;
    lemma result_correct: \forall integer x; x_in_range(x) ==> compute_result(x) == (x + (x / 2)) / 2;
*/

/*@
    requires x <= 0xFFFF;
    ensures \result == (x + (x / 2)) / 2;
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    //@ assert x <= 0xFFFF;
    
    //@ assert x + (x / 2) <= 0xFFFFFFFF;
    
    //@ assert (x + (x / 2)) / 2 <= 0xFFFFFFFF;
    
    uint32_t result = (x + (x / 2)) / 2;
    
    //@ assert result == (x + (x / 2)) / 2;
    
    return result;
}
