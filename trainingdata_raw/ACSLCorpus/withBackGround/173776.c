#include <stdint.h>

/*@
    predicate is_safe_range(integer x) =
        x >= -46340 && x <= 46340;
    
    predicate no_overflow(integer x) =
        x * x >= 0 && x * x <= 9223372036854775807;
    
    lemma safety_implies_no_overflow:
        \forall integer x; is_safe_range(x) ==> no_overflow(x);
*/

/*@
    requires is_safe_range(x);
    requires no_overflow(x);
    ensures \result == x * x;
    assigns \nothing;
*/
int64_t func(int64_t x) {
    // Declare all variables at the top
    int64_t result;
    
    //@ assert is_safe_range(x);
    //@ assert no_overflow(x);
    
    result = x * x;
    
    //@ assert result == x * x;
    return result;
}
