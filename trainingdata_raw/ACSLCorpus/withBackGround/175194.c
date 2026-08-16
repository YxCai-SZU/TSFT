#include <stdint.h>

/*@
    predicate a_in_range(integer a) = 1 <= a && a <= 3;
    predicate b_in_range(integer b) = 1 <= b && b <= 3;
    predicate a_not_b(integer a, integer b) = a != b;
    predicate valid_inputs(integer a, integer b) = 
        a_in_range(a) && b_in_range(b) && a_not_b(a, b);
    
    logic integer compute_result(integer a, integer b) = 
        (1 <= 6 - a - b && 6 - a - b <= 3 && 6 - a - b != a && 6 - a - b != b) ? 
            (6 - a - b) : 
            (6 - ((a < b) ? a : b) * 2);
    
    lemma result_properties:
        \forall integer a, integer b;
        valid_inputs(a, b) ==> 
            compute_result(a, b) + a + b == 6 &&
            1 <= compute_result(a, b) && compute_result(a, b) <= 6;
*/

/*@
    requires valid_inputs(a, b);
    ensures \result + a + b == 6;
    ensures 1 <= \result && \result <= 6;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b) {
    int64_t c;
    int64_t result;
    
    //@ assert valid_inputs(a, b);
    
    c = 6 - a - b;
    
    if (c >= 1 && c <= 3 && c != a && c != b) {
        //@ assert 1 <= c && c <= 3 && c != a && c != b;
        result = c;
    } else {
        //@ assert 1 <= a && a <= 3 && 1 <= b && b <= 3 && a != b;
        c = (a < b) ? a : b;
        result = 6 - c * 2;
    }
    
    //@ assert result + a + b == 6;
    //@ assert 1 <= result && result <= 6;
    return result;
}
