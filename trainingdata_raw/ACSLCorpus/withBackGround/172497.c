#include <stdint.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 12 && 1 <= b <= 31;
    
    logic integer min_value(integer a, integer b) =
        a < b ? a : b;
    
    lemma min_property:
        \forall integer a, b;
        valid_range(a, b) ==> min_value(a, b) <= b;
    
    lemma min_equals_a_or_b:
        \forall integer a, b;
        valid_range(a, b) ==> 
            min_value(a, b) == a || min_value(a, b) == b;
*/

/*@
    requires valid_range(a, b);
    ensures \result <= b;
    ensures \result == a || \result == b;
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b) {
    uint64_t result;
    
    //@ assert valid_range(a, b);
    
    if (a < b) {
        result = a;
        //@ assert result == a;
    } else {
        result = b;
        //@ assert result == b;
    }
    
    //@ assert result <= b;
    //@ assert result == a || result == b;
    
    return result;
}
