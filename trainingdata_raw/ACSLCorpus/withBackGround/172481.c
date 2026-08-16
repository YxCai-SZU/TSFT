#include <stdint.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 12 && 1 <= b <= 31;
    
    logic integer min_val(integer a, integer b) =
        a <= b ? a : b;
    
    lemma min_le_a: \forall integer a, b; valid_range(a, b) ==> min_val(a, b) <= a;
*/

/*@
    requires valid_range(a, b);
    ensures \result <= a;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b) {
    uint32_t answer;
    
    //@ assert valid_range(a, b);
    
    if (a <= b) {
        answer = a;
        //@ assert answer == a;
    } else {
        answer = b;
        //@ assert answer == b;
    }
    
    //@ assert answer == min_val(a, b);
    //@ assert answer <= a;
    
    return answer;
}
