#include <stdint.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 100;
    predicate b_in_range(integer b) = 1 <= b <= 100;
    predicate both_in_range(integer a, integer b) = 
        a_in_range(a) && b_in_range(b);
    
    logic integer compute_result(integer a, integer b) = 
        (a - (b * 2) > 0) ? (a - (b * 2)) : 0;
    
    lemma result_nonnegative:
        \forall integer a, b;
        both_in_range(a, b) ==> compute_result(a, b) >= 0;
*/

/*@
    requires a_in_range(a);
    requires b_in_range(b);
    ensures \result >= 0;
    ensures \result == compute_result(a, b);
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t result;
    
    //@ assert both_in_range(a, b);
    //@ assert a - (b * 2) >= 0 || 0 >= 0;
    
    if (a - (b * 2) > 0) {
        result = a - (b * 2);
    } else {
        result = 0;
    }
    
    //@ assert result == compute_result(a, b);
    //@ assert result >= 0;
    
    return result;
}
