#include <stdint.h>

/*@
    predicate bounds(integer x) = 0 <= x && x <= 8;
    logic integer mul_bounded(integer x, integer y) = x * y;
*/

/*@
    requires bounds(x) && bounds(y) && bounds(z);
    ensures \result == mul_bounded(x, y) + z;
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y, uint32_t z) {
    uint32_t result;
    
    //@ assert bounds(x) && bounds(y) && bounds(z);
    //@ assert mul_bounded(x, y) <= 64;
    
    result = x * y + z;
    return result;
}
