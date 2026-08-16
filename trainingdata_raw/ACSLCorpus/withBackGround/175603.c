#include <stdint.h>

/*@
    predicate valid_range(integer a, integer b) =
        0 < a && a <= 100 && 0 < b && b <= 100;
    
    logic integer multiply(integer a, integer b) = a * b;
    
    lemma multiplication_bound: 
        \forall integer a, b; 
        valid_range(a, b) ==> multiply(a, b) <= 10000;
*/

/*@
    requires valid_range(a, b);
    ensures \result == multiply(a, b);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b) {
    uint32_t res;
    
    //@ assert 0 < a && a <= 100;
    //@ assert 0 < b && b <= 100;
    //@ assert multiply(a, b) <= 10000;
    
    res = a * b;
    return res;
}

int main() {
    return 0;
}
