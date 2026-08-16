#include <stdint.h>

/*@
    predicate valid_hour(integer h) = 0 <= h < 24;
    
    lemma sum_bounds:
        \forall integer a, b; 
        valid_hour(a) && valid_hour(b) ==> 0 <= a + b < 48;
*/

/*@
    requires valid_hour(a) && valid_hour(b);
    ensures valid_hour(\result);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b) {
    uint32_t sum;
    uint32_t result;
    
    //@ assert valid_hour(a);
    //@ assert valid_hour(b);
    
    sum = a + b;
    //@ assert 0 <= sum < 48;
    
    result = sum % 24;
    //@ assert valid_hour(result);
    
    return result;
}

int main() {
    return 0;
}
