#include <stdint.h>

/*@
    predicate a_in_range(integer a) = 0 <= a && a <= 0xFFFF;
    predicate b_in_range(integer b) = 0 <= b && b <= 0xFFFF;
    predicate product_in_range(integer a, integer b) = 
        a_in_range(a) && b_in_range(b) ==> a * b <= 0xFFFF * 0xFFFF;
*/

/*@
    requires a_in_range(a) && b_in_range(b);
    ensures \result == (a * b) / 10000;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b) {
    // Variable declarations at top of scope
    uint32_t result;
    
    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    //@ assert product_in_range(a, b);
    
    result = (a * b) / 10000;
    return result;
}
