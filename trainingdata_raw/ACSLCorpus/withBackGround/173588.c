#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;
    
    logic integer product(integer a, integer b) = a * b;
    
    lemma product_bounded:
        \forall integer a, b;
            valid_range(a) && valid_range(b) ==> product(a, b) <= 10000;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == product(a, b);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at scope top
    uint32_t result;
    
    // Precondition assertions
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    
    // Overflow safety proof
    //@ assert product(a, b) <= 10000;
    
    result = a * b;
    
    // Postcondition verification
    //@ assert result == product(a, b);
    
    return result;
}
