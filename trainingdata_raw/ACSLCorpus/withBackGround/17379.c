#include <stdint.h>

/*@
    predicate is_valid_input(integer x) = 0 <= x && x <= 1;
    
    logic integer complement(integer x) = 1 - x;
    
    lemma complement_range: \forall integer x; is_valid_input(x) ==> complement(x) == 0 || complement(x) == 1;
*/

/*@
    requires is_valid_input(x);
    ensures \result == complement(x);
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    // Variable declarations at scope top
    uint32_t result;
    
    //@ assert x == 0 || x == 1;
    
    result = 1 - x;
    
    //@ assert result == complement(x);
    
    return result;
}
