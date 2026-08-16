#include <stdint.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a && a <= 100 && 1 <= b && b <= 100;
    
    logic integer multiply(integer a, integer b) = a * b;
    
    lemma multiplication_bound: 
        \forall integer a, b; valid_range(a, b) ==> a * b <= 10000;
*/

/*@
    requires valid_range(a, b);
    ensures \result == multiply(a, b);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b) {
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert a * b <= 10000;
    
    uint32_t ans;
    ans = a * b;
    return ans;
}
