#include <stdint.h>

/*@
    predicate a_le_100(integer a) = a <= 100;
    predicate b_le_100(integer b) = b <= 100;
    predicate c_le_100(integer c) = c <= 100;
    predicate result_le_b_plus_c(integer result, integer b, integer c) = result <= b + c;
*/

/*@
    logic integer min(integer a, integer b) = (a < b) ? a : b;
*/

/*@
    requires a_le_100(a) && b_le_100(b) && c_le_100(c);
    ensures result_le_b_plus_c(\result, b, c);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t min_a_b;
    uint32_t result;
    
    //@ assert a <= 100 && b <= 100 && c <= 100;
    
    if (a < b) {
        min_a_b = a;
    } else {
        min_a_b = b;
    }
    
    //@ assert min_a_b == min(a, b);
    
    result = b + c - min_a_b;
    
    //@ assert result <= b + c;
    
    return result;
}
