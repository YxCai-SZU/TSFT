#include <stdint.h>

/*@
    predicate is_positive(integer v) = v > 0;
    predicate no_overflow(integer x, integer y) = x * y <= 4294967295;
*/

/*@
    logic integer multiply(integer x, integer y) = x * y;
*/

/*@
    lemma multiplication_bounds:
        \forall integer x, y;
            is_positive(x) && is_positive(y) && no_overflow(x, y) ==>
                multiply(x, y) <= 4294967295;
*/

/*@
    requires is_positive(x) && is_positive(y) && no_overflow(x, y);
    ensures \result == multiply(x, y);
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y)
{
    // Variable declarations at scope top
    uint32_t result;
    
    //@ assert is_positive(x);
    //@ assert is_positive(y);
    //@ assert no_overflow(x, y);
    
    result = x * y;
    
    //@ assert result == multiply(x, y);
    
    return result;
}
