#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;
    
    logic integer product(integer x, integer y) = x * y;
    
    lemma product_bound: \forall integer x, y; 
        valid_range(x) && valid_range(y) ==> product(x, y) <= 20000;
*/

/*@
    requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    ensures \result <= 20000;
    assigns \nothing;
*/
uint32_t non_linear_arith_example(uint32_t x, uint32_t y)
{
    // Variable declarations at scope top
    uint32_t result;
    
    //@ assert 1 <= x && x <= 100;
    //@ assert 1 <= y && y <= 100;
    //@ assert x * y <= 20000;
    
    result = x * y;
    
    //@ assert result <= 20000;
    return result;
}
